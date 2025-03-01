
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.global.h"
//silver_chain_scope_end


Keys_params *private_new_Keys_params(const char *key, const char *value);

List_keys_params *private_new_List_keys_arguments();

Params_list *private_new_params_list();

void add_param_in_list(Params_list *self, Keys_params *value_argument);

void *private_get_result_or_default(LuaCEmbedTable *table, const char *prop, void *default_arg, void*(*get_by_props)(LuaCEmbedTable*, const char*));

void private_update_params(LuaCEmbedTable *table, Params_list *params, const char *prop);

Argument_handling *new_Argument_handling(LuaCEmbed *args, LuaCEmbedTable *args_peek);


void free_Argument_handling(Argument_handling *self);

void private_free_List_keys_params(List_keys_params *self);

void private_free_params_list(Params_list *self);

void private_free_keys_params(Keys_params *self);
