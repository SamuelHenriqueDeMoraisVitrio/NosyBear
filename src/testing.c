
#include "imports/imports.def.h"



int main(){

  lua_n = newLuaCEmbedNamespace();
  LuaCEmbed * l  = lua_n.newLuaEvaluation();

  lua_n.add_callback(l,"teste", requesition);
  //lua_n.add_callback(l,"sub",sub_cfunc);
  
  lua_n.evaluate(l, "teste('samuel henrique de morais vitrio')");

  return 0;
}


