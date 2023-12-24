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

int main(void)
{
    hashmap_t *h = new_hashmap(sdbm, 10);
    hm_insert(h, "bruh", "hurb");
    hm_insert(h, "yes", "no");
    hm_insert(h, "yeah", "nop");
    hm_dump(h);
    delete_hashmap(h);
    return 0;
}
