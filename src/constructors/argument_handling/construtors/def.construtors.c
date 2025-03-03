
//silver_chain_scope_start
//mannaged by silver chain
#include "../../../imports/imports.dec.h"
//silver_chain_scope_end


Keys_params *private_new_Keys_params(const char *key, const char *value){
  Keys_params *self = malloc(sizeof(Keys_params) + 1);
  if(!self){
    printf("Internal error in struct Keys_params");
    exit(1);
  }
  self->KEY = key;
  self->VALUE = value;
  return self;
}

List_keys_params *private_new_List_keys_arguments(){
  List_keys_params *self = malloc(sizeof(List_keys_params) + 1);
  if(!self){
    printf("Internal error in struct List_keys_arguments");
    exit(1);
  }

  self->HEADERS = private_new_params_list();
  self->PARAMS = private_new_params_list();
  self->COOKIES = private_new_params_list();

  return self;
}

Params_list *private_new_params_list(){
  Params_list *self = malloc(sizeof(Params_list) + 1);
  if(!self){
    printf("Internal error in struct Params_list");
    exit(1);
  }

  self->size_params = 0;

  self->params_values = malloc(sizeof(Keys_params*) + 1);
  if(!self->params_values){
    printf("Internal error in struct Params_list");
    exit(1);
  }

  return self;
}

void add_param_in_list(Params_list *self, Keys_params *value_argument){
  if(value_argument){
    self->size_params++;
    self->params_values = realloc(self->params_values, sizeof(Keys_params *) * (self->size_params + 1));
    if(!self->params_values){
      printf("Internal error in struct HEADERS");
      exit(1);
    }
    self->params_values[self->size_params - 1] = value_argument;
  }
}
