
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.types.h"
//silver_chain_scope_end



struct response_struct{
  const char *URL;
  Body *body;
  Params_list *headers;
  long status_code;
  Errors *errors;
};


