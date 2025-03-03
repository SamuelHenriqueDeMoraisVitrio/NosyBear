
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.types.h"
//silver_chain_scope_end

struct Argument_handling{
  
  const char *URL;
  List_keys_params *Keys_params;
  long MAX_ALLOW_REDIRECTS;
  const char *METHOD;
  long MAX_DOWNLOAD_SIZE;
  bool UPLOAD;
  const char *UPLOAD_PATH;
  const unsigned char *UPLOAD_ANY;
  short any_type;
  long long SIZE_UPLOAD;
  Errors *errors;
};

