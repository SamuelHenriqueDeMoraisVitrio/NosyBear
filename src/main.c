
//silver_chain_scope_start
//mannaged by silver chain
#include "imports/imports.def.h"
//silver_chain_scope_end


int luaopen_NosyBear_start_point(lua_State *state){

  bear = newBearHttpsNamespace();
  lua_n = newLuaCEmbedNamespace();

  LuaCEmbed * l  = lua_n.newLuaLib(state);
  //lua_n.add_callback(l,"add",add_cfunc);
  //lua_n.add_callback(l,"sub",sub_cfunc);

  return lua_n.perform(l);
}


