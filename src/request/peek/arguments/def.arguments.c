
//silver_chain_scope_start
//mannaged by silver chain
#include "../../../imports/imports.dec.h"
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
