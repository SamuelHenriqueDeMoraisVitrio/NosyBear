
//silver_chain_scope_start
//mannaged by silver chain
#include "imports/imports.global.h"
//silver_chain_scope_end


int luaopen_NosyBear_start_point(lua_State *state){

  lua_n = newLuaCEmbedNamespace();

  LuaCEmbed * l  = lua_n.newLuaLib(state);
  //lua_n.add_callback(l,"add",add_cfunc);
  //lua_n.add_callback(l,"sub",sub_cfunc);

  lua_n.perform(l);

}
