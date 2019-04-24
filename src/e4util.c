
#include "e4.h"
#include "stdlib.h"
#include "string.h"

int e4c_derive_clientid(char* clientid, const size_t clientidlen, 
        const char* clientname, const size_t clientnamelen) {

    if ( clientidlen < E4_ID_LEN ) {
        return E4_ID_LEN;
    }

    sha3(clientname, clientnamelen, clientid, E4_ID_LEN);
    return 0;
}

int e4c_derive_control_topic(char* topic, const size_t topiclen, 
        const char* clientid) {
    
    const REQ_TOPICSZ = (2*E4_ID_LEN) + 3; // "e4/<hex of hash>".
    int i = 0;

    if ( topiclen < REQ_TOPICSZ+1 ) {
        return REQ_TOPICSZ + 1;
    }

    snprintf(topic, topiclen, "e4/", 3);
    for ( i = 0; i < E4_ID_LEN; i++ ) {
        const size_t adjust = 3 + 2*i;
        snprintf((char*)(topic + adjust), topiclen-adjust, "%02X", 
                (unsigned char*) clientid[i]);
    }

    return 0;
}

