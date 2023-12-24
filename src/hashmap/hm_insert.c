/*
** EPITECH PROJECT, 2023
** secured
** File description:
** hm_insert
*/

#include <stdlib.h>
#include <string.h>

#include "hashmap.h"

// hashed_key has already been computed, no need to recompute
static int insert_new_node(
    bucket_t *bck, const char *key, const char *value, uint64_t hashed_key
)
{
    bucket_node_t *new_node = malloc(sizeof(bucket_node_t));

    if (!new_node)
        return 1;
    new_node->hashed_key = hashed_key;
    new_node->key = strdup(key);
    if (!new_node->key) {
        free(new_node);
        return 1;
    }
    new_node->data = strdup(value);
    if (!new_node->data) {
        free(new_node->key);
        free(new_node);
        return 1;
    }
    new_node->next = bck->nodes;
    bck->num_nodes++;
    bck->nodes = new_node;
    return 0;
}

static int update_node(bucket_node_t *node, const char *value)
{
    free(node->data);
    node->data = strdup(value);
    return !node->data;
}

int hm_insert(hashmap_t *hm, const char *key, const char *value)
{
    uint64_t hashed_key = hm->hash_function(key, (uint32_t) strlen(key));
    uint64_t bucket_index = hashed_key % hm->num_buckets;

    for (bucket_node_t *n = hm->buckets[bucket_index].nodes; n; n = n->next)
        if (n->hashed_key == hashed_key && !strcmp(n->key, key))
            return update_node(n, value);
    return insert_new_node(&hm->buckets[bucket_index], key, value, hashed_key);
}
