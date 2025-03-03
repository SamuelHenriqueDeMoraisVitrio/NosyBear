
#include "imports/imports.def.h"



int main(){

  bear = newBearHttpsNamespace();
  lua_n = newLuaCEmbedNamespace();
  LuaCEmbed * l  = lua_n.newLuaEvaluation();

  Add_callbacks(l);
  
  lua_n.evaluate(l, "r = peek({URL='https://serjaoberranteiroserver.com.br', HEADERS={key1='value'}})");
  bool response = lua_n.get_evaluation_bool(l,"r.error.exist");
  //printf("result: %s\n",response);
  printf("\n\tresonse: %d\n", response);

  if(lua_n.has_errors(l)){
    printf("error: %s\n",lua_n.get_error_message(l));
  }
  lua_n.free(l);

  return 0;
}


