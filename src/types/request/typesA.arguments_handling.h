
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.types.h"
//silver_chain_scope_end





struct Argument_handling{
  
  const char *URL;
  Keys_params *HEADERS;
  Keys_params *COOKIES;
  Keys_params *PARAMS;
  long MAX_ALLOW_REDIRECTS;
  char *METHOD;
  long MAX_DOWNLOAD_SIZE;
  char *UPLOAD_PATH;
  char *UPLOAD_ANY;
};

