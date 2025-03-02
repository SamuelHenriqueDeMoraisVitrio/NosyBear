
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end

Argument_handling *private_arguments_requisition(LuaCEmbed *args){
  long size = lua_n.args.size(args);
  if(size == 0){
    printf("\n\tno argument providided in requisition\n");
    return NULL;
  }

  int arg_type = lua_n.args.get_type(args, 0);

  if(arg_type != lua_n.types.TABLE){
    printf("\n\tArgument provieded not aceppt\n");
    return NULL;
  }

  LuaCEmbedTable *args_in_table = lua_n.args.get_table(args, 0);
  int size_table = lua_n.tables.get_size(args_in_table);
  if(size_table < 1){
    printf("Argument provieded not accept");
    return NULL;
  }

  Argument_handling *self = new_Argument_handling(args, args_in_table);
  if(!self){
    printf("Internor error in Arguments requisition");
    exit(1);
  }

  return self;
}

LuaCEmbedResponse  *requesition(LuaCEmbed *args){

  Argument_handling *arguments_of_peek = private_arguments_requisition(args);
  if(!arguments_of_peek){
    printf("\n\tArguments_of_peek in error\n");
    exit(1);
  }

  BearHttpsRequest *request = bear.request.newBearHttpsRequest(arguments_of_peek->URL);
  bear.request.set_method(request, arguments_of_peek->METHOD);
  request->max_redirections = arguments_of_peek->MAX_ALLOW_REDIRECTS;

  for(int i=0; i < arguments_of_peek->Keys_params->HEADERS->size_params; i++){
    const char *key = arguments_of_peek->Keys_params->HEADERS->params_values[i]->KEY;
    const char *value = arguments_of_peek->Keys_params->HEADERS->params_values[i]->VALUE;
    bear.request.add_headder(request, (char*)key, (char*)value);
  }

  BearHttpsResponse *response = bear.request.fetch(request);
  response->max_body_size = arguments_of_peek->MAX_DOWNLOAD_SIZE;

  unsigned char *body = bear.response.read_body(response);
  long long size_body = bear.response.get_body_size(response);

  if(body){
    //printf("\n\tbody: \n%s\n\n", body);
  }

  if(bear.response.error(response)){
    printf("Error: %s", bear.response.get_error_msg(response));
    exit(1);
  }

  bear.request.free(request);
  bear.response.free(response);
  free_Argument_handling(arguments_of_peek);

  return lua_n.response.send_raw_string((const char *)body, size_body);
}



