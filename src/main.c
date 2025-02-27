
//silver_chain_scope_start
//mannaged by silver chain
#include "imports/imports.dep.h"
//silver_chain_scope_end


int main(){
    BearHttpsRequest *request = newBearHttpsRequest("https://example.com");
    BearHttpsResponse *response =BearHttpsRequest_fetch(request);
    const int MAX_CONTENT = 2000;
    unsigned char *body = BearHttpsResponse_read_body(response,MAX_CONTENT);
    if(body){
        printf("body: %s\n",body);
    }

    if(BearHttpsResponse_error(response)){
        printf("error: %s\n",BearHttpsResponse_get_error_msg(response));
    }

    BearHttpsRequest_free(request);
    BearHttpsResponse_free(response);

}
