
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.dec.h"
//silver_chain_scope_end



void Add_callbacks(LuaCEmbed *l){

  lua_n.add_callback(l,"peek", requesition);

}


