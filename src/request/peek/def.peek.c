
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end


Argument_handling *arguments_requisition(LuaCEmbed *args){

  /*
  const char *url = lua_n.args.get_str(args, 0);
  if(!url){
    return NULL;
  }
  */
  int arg_type = lua_n.args.get_type(args, 0);

  const char *converted_to_str = lua_n.convert_arg_code(arg_type);
  printf("type: %s\n",converted_to_str);

  return NULL;



}

LuaCEmbedResponse  *requesition(LuaCEmbed *args){

  arguments_requisition(args);

  return NULL;
}



