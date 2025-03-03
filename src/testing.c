
#include "imports/imports.def.h"



int main(){

  bear = newBearHttpsNamespace();
  lua_n = newLuaCEmbedNamespace();
  LuaCEmbed * l  = lua_n.newLuaEvaluation();

  Add_callbacks(l);
  
  lua_n.evaluate(l, "r = peek({URL='https://serjaoberranteiroserver.com.br', HEADERS={key1='value'})");
  const char *response = lua_n.get_string_evaluation(l,"r");
  //printf("result: %s\n",response);
  printf("resonse");

  if(lua_n.has_errors(l)){
    printf("error: %s\n",lua_n.get_error_message(l));
  }
  lua_n.free(l);

  return 0;
}


