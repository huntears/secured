/*
** EPITECH PROJECT, 2023
** secured
** File description:
** hm_delete
*/

#include <stdlib.h>
#include <string.h>

#include "hashmap.h"

static int
delete_from_bucket(bucket_t *bck, const char *key, uint64_t hashed_key)
{
    bucket_node_t *prev = NULL;

    if (!bck->num_nodes)
        return 1;
    for (bucket_node_t *n = bck->nodes; n; n = n->next) {
        if (n->hashed_key == hashed_key && !strcmp(n->key, key)) {
            free(n->data);
            free(n->key);
            if (prev)
                prev->next = n->next;
            else
                bck->nodes = n->next;
            free(n);
            return 0;
        }
    }
    return 1;
}

int hm_delete(hashmap_t *hm, const char *key)
{
    uint64_t hashed_key = hm->hash_function(key, (uint32_t) strlen(key));
    uint64_t bucket_index = hashed_key % hm->num_buckets;

    return delete_from_bucket(&hm->buckets[bucket_index], key, hashed_key);
}
