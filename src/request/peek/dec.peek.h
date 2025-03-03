
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.global.h"
//silver_chain_scope_end


LuaCEmbedTable *private_error_response(LuaCEmbed *args, Errors *errors);

void set_headers(LuaCEmbed *args, LuaCEmbedTable *response_table, BearHttpsResponse *response);

void set_body(LuaCEmbed *args, LuaCEmbedTable *response_table, BearHttpsResponse *response);

LuaCEmbedResponse *new_response_to_lua(LuaCEmbed *args, BearHttpsResponse *response, Errors *errors);

LuaCEmbedResponse  *requesition(LuaCEmbed *args);



