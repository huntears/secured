/*
** EPITECH PROJECT, 2023
** secured
** File description:
** hm_search
*/

#include <stddef.h>
#include <string.h>

#include "hashmap.h"

char *hm_search(const hashmap_t *hm, const char *key)
{
    uint64_t hashed_key = hm->hash_function(key, (uint32_t) strlen(key));
    uint64_t bucket_index = hashed_key % hm->num_buckets;

    for (bucket_node_t *n = hm->buckets[bucket_index].nodes; n; n = n->next)
        if (n->hashed_key == hashed_key && !strcmp(n->key, key))
            return n->data;
    return NULL;
}
