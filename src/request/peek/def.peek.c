
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.dec.h"
#include <stdbool.h>
#include <string.h>
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


  bool exist_url = false;
  const char* url = NULL;
  long max_allow_redirects;
  char *method;
  long max_download_size;
  char *upload_path;
  int type_any = -1;
  void *upload_any;
  long size_headers = 0;
  long size_params = 0;
  long size_cookies = 0;

  LuaCEmbedTable *args_in_table = lua_n.args.get_table(args, 0);
  int size_table = lua_n.tables.get_size(args_in_table);
  if(size_table < 0){
    printf("Argument provieded not accept");
    return NULL;
  }



  for(int i=1; i < size_table; i++){
    char *key_all = lua_n.tables.get_key_by_index(args_in_table, i);

    if(strcmp(key_all, "URL") == 0){
      url = lua_n.tables.get_string_by_index(args_in_table, i);
      continue;
    }
    if(strcmp(key_all, "MAX_ALLOW_REDIRECTS") == 0){
      max_allow_redirects = lua_n.tables.get_long_by_index(args_in_table, i);
      continue;
    }
    if(strcmp(key_all, "METHOD") == 0){
      method = lua_n.tables.get_string_by_index(args_in_table, i);
      continue;
    }
    if(strcmp(key_all, "MAX_DOWNLOAD_SIZE") == 0){
      max_download_size = lua_n.tables.get_long_by_index(args_in_table, i);
      continue;
    }
    if(strcmp(key_all, "UPLOAD_PATH") == 0){
      upload_path = lua_n.tables.get_string_by_index(args_in_table, i);
      continue;
    }
    if(strcmp(key_all, "UPLOAD_ANY") == 0){
      int type = lua_n.tables.get_type_by_index(args_in_table, i);
      if(type == lua_n.types.STRING){
        type_any = 1;
        upload_any = lua_n.tables.get_raw_string_by_index(args_in_table, i, 0);
        continue;
      }
      if(type == lua_n.types.TABLE){
        type_any = 2;
        upload_any = lua_n.tables.get_sub_table_by_index(args_in_table, i);
        continue;
      }
      type_any = -1;
    }
    if(strcmp(key_all, "HEADERS") == 0){
      LuaCEmbedTable *headers_table = lua_n.tables.get_sub_table_by_index(args_in_table, i);
      size_headers = lua_n.tables.get_size(headers_table);
      for(int i=0; i < size_headers; i++){
        const char *key_header = lua_n.tables.get_key_by_index(headers_table, i);
        const char *value = lua_n.tables.get_string_by_index(headers_table, i);
        printf("\n\tHEADER://key_all: %s, value: %s", key_header, value);
      }
    }
    printf("\n\tALL://key_all: %s", key_all);

  }
  if(!url){
    printf("\n\tURL not provieded\n");
    return NULL;
  }

  return NULL;
}

LuaCEmbedResponse  *requesition(LuaCEmbed *args){

  private_arguments_requisition(args);

  return NULL;
}



