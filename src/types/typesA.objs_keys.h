
//silver_chain_scope_start
//mannaged by silver chain
#include "../imports/imports.types.h"
//silver_chain_scope_end

struct List_keys_params{
  Params_list *HEADERS;
  Params_list *COOKIES;
  Params_list *PARAMS;
};

struct Params_list{
  long size_params;
  Keys_params **params_values;
};

struct Keys_params{
  const char *KEY;
  const char *VALUE;
};


