/*
** EPITECH PROJECT, 2023
** secured
** File description:
** hashmap
*/

#ifndef BE5162AD_085E_47B8_B89B_522E2E979393
#define BE5162AD_085E_47B8_B89B_522E2E979393

#include <stdint.h>

typedef struct bucket_node {
    uint64_t hashed_key;
    char *key;
    char *data;
    struct bucket_node *next;
} bucket_node_t;

typedef struct bucket {
    uint64_t num_nodes;
    bucket_node_t *nodes;
} bucket_t;

typedef struct hashmap {
    uint64_t (*hash_function)(const char *, uint32_t);
    uint32_t num_buckets;
    bucket_t buckets[];
} hashmap_t;

hashmap_t *new_hashmap(
    uint64_t (*hash_function)(const char *, uint32_t), uint32_t num_buckets
);
void delete_hashmap(hashmap_t *hm);
void hm_insert(hashmap_t *hm, const char *key, const char *value);
void hm_dump(const hashmap_t *hm);

#endif /* BE5162AD_085E_47B8_B89B_522E2E979393 */
