#include <stdlib.h>

#include "hashmap.h"

static void delete_bucket(bucket_t *bck)
{
    //
}

void delete_hashmap(hashmap_t *hm)
{
    if (!hm)
        return;
    for (uint32_t i = 0; i < hm->num_buckets; i++)
        delete_bucket(&hm->buckets[i]);
    free(hm);
}
