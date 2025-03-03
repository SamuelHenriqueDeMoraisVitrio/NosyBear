
//silver_chain_scope_start
//mannaged by silver chain
#include "../../imports/imports.dec.h"
//silver_chain_scope_end

LuaCEmbedTable *private_error_response(LuaCEmbed *args, Errors *errors){
  LuaCEmbedTable *response_in_error = lua_n.tables.new_anonymous_table(args);
  lua_n.tables.set_bool_prop(response_in_error, "exist", errors->exist);
  lua_n.tables.set_string_prop(response_in_error, "message", errors->msg);
  return response_in_error;
}

void set_headers(LuaCEmbed *args, LuaCEmbedTable *response_table, BearHttpsResponse *response){
  LuaCEmbedTable *headers = lua_n.tables.new_anonymous_table(args);
  for(int i=0; i < bear.response.get_headders_size(response); i++){
    LuaCEmbedTable *header = lua_n.tables.new_anonymous_table(args);
    lua_n.tables.set_string_prop(header, "key", bear.response.get_headder_key_by_index(response, i));
    lua_n.tables.set_string_prop(header, "value", bear.response.get_headder_value_by_index(response, i));
    lua_n.tables.append_table(headers, header);
  }

  lua_n.tables.set_sub_table_prop(response_table, "headers", headers);
}

void set_body(LuaCEmbed *args, LuaCEmbedTable *response_table, BearHttpsResponse *response){
  LuaCEmbedTable *body_table = lua_n.tables.new_anonymous_table(args);

  lua_n.tables.set_string_prop(body_table, "content", (const char *)bear.response.read_body(response));
  lua_n.tables.set_long_prop(body_table, "size", bear.response.get_body_size(response));

  lua_n.tables.set_sub_table_prop(response_table, "body", body_table);
}

LuaCEmbedResponse *new_response_to_lua(LuaCEmbed *args, BearHttpsResponse *response, Errors *errors){
  
  LuaCEmbedTable *response_table = lua_n.tables.new_anonymous_table(args);

  lua_n.tables.set_long_prop(response_table, "status_code", bear.response.get_status_code(response));

  set_headers(args, response_table, response);

  set_body(args, response_table, response);

  lua_n.tables.set_sub_table_prop(response_table, "error", private_error_response(args, errors));

  if(bear.response.error(response)){
    errors->exist = true;
    errors->msg = bear.response.get_error_msg(response);
    return lua_n.response.send_table(private_error_response(args, errors));
  }

  return lua_n.response.send_table(response_table);
}

LuaCEmbedResponse *requesition(LuaCEmbed *args){

  Argument_handling *arguments_of_peek = private_arguments_requisition(args);
  if(arguments_of_peek->errors->exist){
    return lua_n.response.send_table(private_error_response(args, arguments_of_peek->errors));
  }

  BearHttpsRequest *request = bear.request.newBearHttpsRequest(arguments_of_peek->URL);
  bear.request.set_method(request, arguments_of_peek->METHOD);
  request->max_redirections = arguments_of_peek->MAX_ALLOW_REDIRECTS;

  for(int i=0; i < arguments_of_peek->Keys_params->HEADERS->size_params; i++){
    const char *key = arguments_of_peek->Keys_params->HEADERS->params_values[i]->KEY;
    const char *value = arguments_of_peek->Keys_params->HEADERS->params_values[i]->VALUE;
    bear.request.add_headder(request, (char*)key, (char*)value);
  }

  if(arguments_of_peek->UPLOAD){
    if(arguments_of_peek->UPLOAD_PATH){
      bear.request.send_file_auto_detect_content_type(request, arguments_of_peek->UPLOAD_PATH);
    }else{
      if(arguments_of_peek->any_type == 0){
        bear.request.send_body_str(request, (char *)arguments_of_peek->UPLOAD_ANY);
      }
      if(arguments_of_peek->any_type == 1){
        bear.request.send_any(request, (unsigned char *)arguments_of_peek->UPLOAD_ANY, arguments_of_peek->SIZE_UPLOAD);
      }
    }
  }

  BearHttpsResponse *response = bear.request.fetch(request);
  response->max_body_size = arguments_of_peek->MAX_DOWNLOAD_SIZE;

  LuaCEmbedResponse *out = new_response_to_lua(args, response, arguments_of_peek->errors);

  bear.request.free(request);
  bear.response.free(response);
  free_Argument_handling(arguments_of_peek);

  return out;
}



