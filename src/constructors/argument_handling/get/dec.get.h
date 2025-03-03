
//silver_chain_scope_start
//mannaged by silver chain
#include "../../../imports/imports.global.h"
//silver_chain_scope_end


void *private_get_result_or_default(LuaCEmbedTable *table, const char *prop, void *default_arg, void*(*get_by_props)(LuaCEmbedTable*, const char*));

void private_update_params(LuaCEmbedTable *table, Params_list *params, const char *prop);

void private_update_any(Argument_handling *args, LuaCEmbedTable *table);

Argument_handling *new_Argument_handling(LuaCEmbed *args, LuaCEmbedTable *args_peek);


