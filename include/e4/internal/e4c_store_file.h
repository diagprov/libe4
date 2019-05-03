//  e4c_store.h
//  2018-07-06  Markku-Juhani O. Saarinen <markku@teserakt.io>

//  (c) 2018 Copyright Teserakt AG

//  Persistent key storage.

#ifndef _E4C_STORE_H_
#define _E4C_STORE_H_

#include <stdint.h>
#include <stddef.h>


#define E4_TOPICS_MAX 100

const char E4V1_MAGIC[4] = "E41P";

// In memory structures that represent the file. This may need to become 

typedef struct {
    uint8_t topic[E4_TOPICHASH_LEN];
    uint8_t key[E4_KEY_LEN];
} topic_key;


struct _e4storage {
    uint8_t id[E4_ID_LEN];
    uint8_t key[E4_KEY_LEN];
    /* this field is never syned to disk. */
    uint8_t ctrltopic[E4_TOPICHASH_LEN];
    uint16_t topiccount;
    topic_key topics[E4_TOPICS_MAX]; 
    char* filepath;
};


/** \brief Initialize e4storage memory.
   \param store structure representing storage.
   \return 0 on success. Non-zero return values indicate errors.
 */
int e4c_init(e4storage* store);
/** \brief Load e4storage from persistence file.
   \param store structure representing storage.
   \param path a string locating the file to be opened.
   \return 0 on success. Non-zero return values indicate errors.
 */
int e4c_load(e4storage* store, const char *path);
/** \brief Sync e4storage with persistence file
   \param store structure representing storage.
   \return 0 on success. Non-zero return values indicate errors.
 */
int e4c_sync(e4storage* store);
/** \brief Set the Identity of the device. An identifier can be generated 
    from an alias using the utility function e4c_derive_clientid.
   \param store structure representing storage.
   \param id buffer representing the bytes for the identifier.
   \return 0 on success. Non-zero return values indicate errors.
 */
int e4c_set_id(e4storage* store, const uint8_t *id);
int e4c_set_idkey(e4storage* store, const uint8_t *key);
int e4c_is_device_ctrltopic(e4storage* store, const char *topic);
int e4c_getindex(e4storage* store, const char *topic);
int e4c_gettopickey(uint8_t *key, e4storage* store, const int index);
int e4c_set_topic_key(e4storage* store, const uint8_t *topic_hash, const uint8_t *key);
int e4c_remove_topic(e4storage* store, const uint8_t *topic_hash);
int e4c_reset_topics(e4storage* store);

#ifdef DEBUG
void e4c_debug_dumpkeys(e4storage* store);
#endif

#endif
