
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end



LuaCEmbedResponse  *requesition(LuaCEmbed *args){

  Argument_handling *arguments_of_peek = private_arguments_requisition(args);
  if(!arguments_of_peek){
    printf("\n\tArguments_of_peek in error\n");
    exit(1);
  }

  BearHttpsRequest *request = bear.request.newBearHttpsRequest(arguments_of_peek->URL);
  bear.request.set_method(request, arguments_of_peek->METHOD);
  request->max_redirections = arguments_of_peek->MAX_ALLOW_REDIRECTS;


  bear.request.add_headder(request, "Content-Type", (char *)arguments_of_peek->UPLOAD_CONTENT_TYPE);
  for(int i=0; i < arguments_of_peek->Keys_params->HEADERS->size_params; i++){
    const char *key = arguments_of_peek->Keys_params->HEADERS->params_values[i]->KEY;
    const char *value = arguments_of_peek->Keys_params->HEADERS->params_values[i]->VALUE;
    bear.request.add_headder(request, (char*)key, (char*)value);
  }

  bear.request.represent(request);
  BearHttpsResponse *response = bear.request.fetch(request);
  response->max_body_size = arguments_of_peek->MAX_DOWNLOAD_SIZE;

  unsigned char *body = bear.response.read_body(response);
  long long size_body = bear.response.get_body_size(response);

  if(bear.response.error(response)){
    printf("Error: %s", bear.response.get_error_msg(response));
    exit(1);
  }

  bear.request.free(request);
  bear.response.free(response);
  free_Argument_handling(arguments_of_peek);

  return lua_n.response.send_raw_string((const char *)body, size_body);
}



