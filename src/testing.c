
#include "imports/imports.def.h"



int main(){

  lua_n = newLuaCEmbedNamespace();
  LuaCEmbed * l  = lua_n.newLuaEvaluation();

  lua_n.add_callback(l,"teste", requesition);
  //lua_n.add_callback(l,"sub",sub_cfunc);
  
  lua_n.evaluate(l, "teste({'ssss', samu='22', eu='44', samuel='samuel'})");

  if(lua_n.has_errors(l)){
    printf("error: %s\n",lua_n.get_error_message(l));
  }
  lua_n.free(l);

  return 0;
}


