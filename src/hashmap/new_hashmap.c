/*
** EPITECH PROJECT, 2023
** secured
** File description:
** new_hashmap
*/

#include <stdlib.h>
#include <string.h>

#include "hashmap.h"

hashmap_t *new_hashmap(
    uint64_t (*hash_function)(const char *, uint32_t), uint32_t num_buckets
)
{
    hashmap_t *map =
        malloc(sizeof(hashmap_t) + sizeof(bucket_t) * num_buckets);

    if (!map)
        return NULL;
    map->hash_function = hash_function;
    map->num_buckets = num_buckets;
    memset(map->buckets, 0, num_buckets);
    return map;
}
