
//silver_chain_scope_start
//mannaged by silver chain
#include "../../../imports/imports.dec.h"
//silver_chain_scope_end



void free_Argument_handling(Argument_handling *self){
  
  if(self){
    if(self->Keys_params){
      private_free_List_keys_params(self->Keys_params);
    }
    free(self);
  }
}

void private_free_List_keys_params(List_keys_params *self){

  if(self){
    if(self->HEADERS){
      private_free_params_list(self->HEADERS);
    }
    if(self->PARAMS){
      private_free_params_list(self->PARAMS);
    }
    if(self->COOKIES){
      private_free_params_list(self->COOKIES);
    }
    free(self);
  }
}

void private_free_params_list(Params_list *self){

  if(self){
    if(self->params_values){
      for(int i = 0; i < self->size_params; i++){
        private_free_keys_params(self->params_values[i]);
      }
      free(self->params_values);
    }
    free(self);
  }
}

void private_free_keys_params(Keys_params *self){
  if(self){
    free(self);
  }
}

