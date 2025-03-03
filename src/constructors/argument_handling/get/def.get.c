
//silver_chain_scope_start
//mannaged by silver chain
#include "../../../imports/imports.dec.h"
//silver_chain_scope_end

void *private_get_result_or_default(LuaCEmbedTable *table, const char *prop, void *default_arg, void*(*get_by_props)(LuaCEmbedTable*, const char*)){

  if(lua_n.tables.get_type_prop(table, prop) == lua_n.types.NILL){
    return default_arg;
  }

  void *response = get_by_props(table, prop);

  return response;
}

void private_update_params(LuaCEmbedTable *table, Params_list *params, const char *prop){

  int type = lua_n.tables.get_type_prop(table, prop);

  if(type == lua_n.types.NILL){
    return;
  }

  if(type != lua_n.types.TABLE){
    printf("\n\tArguments in %s not accet\n", prop);
    exit(1);
  }

  LuaCEmbedTable *sub_table = lua_n.tables.get_sub_table_prop(table, prop);

  long size_by_keys = lua_n.tables.get_size(sub_table);
  long size_by_raw = lua_n.tables.get_listable_size(sub_table);

  for(int i=0; i < size_by_keys + size_by_raw; i++){
    const char *key = lua_n.tables.get_key_by_index(sub_table, i);
    if(!key){
      if(lua_n.tables.get_type_by_index(sub_table, i) == lua_n.types.TABLE){
        LuaCEmbedTable *header = lua_n.tables.get_sub_table_by_index(sub_table, i);
        const char *key_raw = lua_n.tables.get_string_prop(header, "key");
        const char *value_raw = lua_n.tables.get_string_prop(header, "value");

        Keys_params *value_header_raw = private_new_Keys_params(key_raw, value_raw);
        add_param_in_list(params, value_header_raw);
      }
      continue;
    }
    const char *value = lua_n.tables.get_string_prop(sub_table, key);

    Keys_params *value_param = private_new_Keys_params(key, value);

    add_param_in_list(params, value_param);
  }
}

void private_update_any(Argument_handling *args, LuaCEmbedTable *table){

  const char *prop = "UPLOAD_ANY";

  LuaCEmbedTable *upload_any = private_get_result_or_default(table, prop, NULL, (void *)lua_n.tables.get_sub_table_prop);

  if(!upload_any){
    args->UPLOAD = !args->UPLOAD_PATH?false:true;
    args->UPLOAD_ANY = NULL;
    args->SIZE_UPLOAD = 0;
    return;
  }

  args->SIZE_UPLOAD = (long long)private_get_result_or_default(upload_any, "size", 0, (void*)lua_n.tables.get_long_prop);

  if(lua_n.tables.get_type_prop(upload_any, "content") == lua_n.types.STRING){
    if(args->SIZE_UPLOAD <= 0){
      args->any_type = 0;//type == string
      args->UPLOAD_ANY = private_get_result_or_default(upload_any, "content", NULL, (void *)lua_n.tables.get_string_prop);
      args->UPLOAD = !args->UPLOAD_ANY?false:true;
      return;
    }

    args->any_type = 1;//type == raw_string
    args->UPLOAD_ANY = (const unsigned char *)lua_n.tables.get_raw_string_prop(upload_any, "content", &args->SIZE_UPLOAD);
    args->UPLOAD = true;
    return;
  }

}

Argument_handling *new_Argument_handling(LuaCEmbed *args, LuaCEmbedTable *args_peek){

  Errors *errors_request = malloc(sizeof(Errors) + 1);
  if(!errors_request){
    printf("Internal error: struct Errors in Argument_handling");
    exit(1);
  }

  Argument_handling *self = malloc(sizeof(Argument_handling) + 1);
  if(!self){
    printf("Internal error in struct Argument_handling");
    exit(1);
  }
  
  self->errors = errors_request;

  self->URL = lua_n.tables.get_string_prop(args_peek, "URL");
  if(lua_n.has_errors(args)){
    self->errors->exist = true;
    self->errors->msg = "Error: URL invalid;";
    return NULL;
  }

  self->errors->exist = false;

  self->MAX_ALLOW_REDIRECTS = (long)private_get_result_or_default(args_peek, "MAX_ALLOW_REDIRECTS", (void*)1000, (void*)lua_n.tables.get_long_prop);

  self->METHOD = (const char *)private_get_result_or_default(args_peek, "METHOD", "GET", (void*)lua_n.tables.get_string_prop);

  self->MAX_DOWNLOAD_SIZE = (long)private_get_result_or_default(args_peek, "MAX_DOWNLOAD_SIZE", (void*)-1, (void*)lua_n.tables.get_long_prop);

  self->UPLOAD_PATH = (const char*)private_get_result_or_default(args_peek, "UPLOAD_PATH", NULL, (void*)lua_n.tables.get_string_prop);

  private_update_any(self, args_peek);

  self->Keys_params = private_new_List_keys_arguments();

  private_update_params(args_peek, self->Keys_params->HEADERS, "HEADERS");
  private_update_params(args_peek, self->Keys_params->COOKIES, "COOKIES");
  private_update_params(args_peek, self->Keys_params->PARAMS, "PARAMS");

  return self;
}
