/*
** EPITECH PROJECT, 2023
** secured
** File description:
** delete_hashmap
*/

#include <stdlib.h>

#include "hashmap.h"

static void delete_bucket(bucket_t *bck)
{
    // TODO (huntears): Actually delete the buckets
}

void delete_hashmap(hashmap_t *hm)
{
    if (!hm)
        return;
    for (uint32_t i = 0; i < hm->num_buckets; i++)
        delete_bucket(&hm->buckets[i]);
    free(hm);
}
