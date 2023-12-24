/*
** EPITECH PROJECT, 2023
** secured
** File description:
** delete_hashmap
*/

#include <stdlib.h>

#include "hashmap.h"
#include "utility.h"

static void delete_bucket_node(bucket_node_t *bck_node)
{
    free(bck_node->data);
    free(bck_node->key);
}

static void delete_bucket(bucket_t *bck)
{
    bucket_node_t *current_node = bck->nodes;
    bucket_node_t *next_node = NULL;

    while (current_node) {
        next_node = current_node->next;
        delete_bucket_node(current_node);
        free(current_node);
        current_node = next_node;
    }
}

void delete_hashmap(hashmap_t *hm)
{
    if (!hm)
        return;
    for (uint32_t i = 0; i < hm->num_buckets; i++)
        delete_bucket(&hm->buckets[i]);
    free(hm);
}
