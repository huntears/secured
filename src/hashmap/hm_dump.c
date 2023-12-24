/*
** EPITECH PROJECT, 2023
** secured
** File description:
** hm_dump
*/

#include <stdio.h>

#include "hashmap.h"

static void bucket_dump(const bucket_t *bck)
{
    for (const bucket_node_t *n = bck->nodes; n; n = n->next)
        printf("> %lu - %s\n", n->hashed_key, n->data);
}

void hm_dump(const hashmap_t *hm)
{
    for (uint32_t i = 0; i < hm->num_buckets; i++) {
        printf("[%u]:\n", i);
        bucket_dump(&hm->buckets[i]);
    }
}
