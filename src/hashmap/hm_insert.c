#include <stdlib.h>
#include <string.h>

#include "hashmap.h"

void hm_insert(hashmap_t *hm, const char *key, const char *value)
{
    uint64_t hashed_key = hm->hash_function(key, (uint32_t) strlen(key));
    bucket_node_t *new_node = malloc(sizeof(bucket_node_t));
    uint64_t bucket_index = hashed_key % hm->num_buckets;

    if (!new_node)
        return;
    new_node->hashed_key = hashed_key;
    new_node->key = strdup(key);
    new_node->data = strdup(value);
    new_node->next = hm->buckets[bucket_index].nodes;
    hm->buckets[bucket_index].num_nodes++;
    hm->buckets[bucket_index].nodes = new_node;
}
