
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

  long size_arguments = lua_n.tables.get_size(sub_table);

  for(int i=0; i < size_arguments; i++){
    const char *key = lua_n.tables.get_key_by_index(sub_table, i);
    if(!key){continue;}
    const char *value = lua_n.tables.get_string_prop(sub_table, key);

    Keys_params *value_param = private_new_Keys_params(key, value);

    add_param_in_list(params, value_param);
  }
}

Argument_handling *new_Argument_handling(LuaCEmbed *args, LuaCEmbedTable *args_peek){

  Argument_handling *self = malloc(sizeof(Argument_handling) + 1);
  if(!self){
    printf("Internal error in struct Argument_handling");
    exit(1);
  }
  
  self->URL = lua_n.tables.get_string_prop(args_peek, "URL");
  if(lua_n.has_errors(args)){
    printf("Error: %s", lua_n.get_error_message(args));
    exit(1);
  }

  self->MAX_ALLOW_REDIRECTS = (long)private_get_result_or_default(args_peek, "MAX_ALLOW_REDIRECTS", (void*)1000, (void*)lua_n.tables.get_long_prop);

  self->METHOD = (const char *)private_get_result_or_default(args_peek, "METHOD", "GET", (void*)lua_n.tables.get_string_prop);

  self->MAX_DOWNLOAD_SIZE = (long)private_get_result_or_default(args_peek, "MAX_DOWNLOAD_SIZE", (void*)-1, (void*)lua_n.tables.get_long_prop);

  self->UPLOAD_PATH = (const char*)private_get_result_or_default(args_peek, "UPLOAD_PATH", NULL, (void*)lua_n.tables.get_string_prop);

  self->UPLOAD_CONTENT_TYPE = (const char *)private_get_result_or_default(args_peek, "UPLOAD_CONTENT_TYPE", "text/plain", (void *)lua_n.tables.get_string_prop);

  self->UPLOAD_ANY = NULL;//(const char *)private_get_result_or_default(args_peek, "UPLOAD_ANY", NULL, (void*)lua_n.tables.get_string_prop);

  self->Keys_params = private_new_List_keys_arguments();

  private_update_params(args_peek, self->Keys_params->HEADERS, "HEADERS");
  private_update_params(args_peek, self->Keys_params->COOKIES, "COOKIES");
  private_update_params(args_peek, self->Keys_params->PARAMS, "PARAMS");

  return self;

}
