/*
** EPITECH PROJECT, 2023
** secured
** File description:
** main
*/

#ifndef UNIT_TESTS

#include <stdio.h>

#include "hashing_functions.h"
#include "hashmap/hashmap.h"
#include "utility.h"

int main(void)
{
    hashmap_t *h = new_hashmap(sdbm, 10);

    hm_insert(h, "bruh", "hurb");
    hm_insert(h, "yes", "no");
    hm_insert(h, "yeah", "nop");
    hm_dump(h);
    printf("Searching for yes: %s\n", hm_search(h, "yes"));
    printf("Searching for no: %s\n", hm_search(h, "no"));
    hm_delete(h, "yes");
    printf("Deleting yes...\n");
    printf("Searching for yes after delete: %s\n", hm_search(h, "yes"));
    hm_insert(h, "bruh1", "hurb1");
    hm_insert(h, "bruh2", "hurb2");
    hm_insert(h, "bruh3", "hurb3");
    hm_insert(h, "bruh4", "hurb4");
    hm_insert(h, "bruh5", "hurb5");
    hm_insert(h, "bruh6", "hurb6");
    hm_insert(h, "bruh7", "hurb7");
    hm_dump(h);
    printf("Deleting bruh...\n");
    hm_delete(h, "bruh");
    hm_dump(h);
    delete_hashmap(h);
    return 0;
}

#endif
