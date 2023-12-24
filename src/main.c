/*
** EPITECH PROJECT, 2023
** secured
** File description:
** main
*/

#include <stdio.h>

#include "hashing_functions.h"
#include "hashmap/hashmap.h"
#include "utility.h"

#ifdef UNIT_TESTS
#define MAIN not_main
#else
#define MAIN main
#endif

int MAIN(void)
{
    hashmap_t *h = new_hashmap(sdbm, 10);

    hm_insert(h, "bruh", "hurb");
    hm_insert(h, "yes", "no");
    hm_insert(h, "yeah", "nop");
    hm_dump(h);
    printf("Searching for yes: %s\n", hm_search(h, "yes"));
    printf("Searching for no: %s\n", hm_search(h, "no"));
    delete_hashmap(h);
    return 0;
}
