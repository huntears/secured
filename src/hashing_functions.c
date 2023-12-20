/*
** EPITECH PROJECT, 2023
** secured
** File description:
** hashing_functions
*/

#include <stdint.h>

#include "hashing_functions.h"

uint64_t sdbm(const char *str, uint32_t len)
{
    uint64_t hash = 0;

    for (uint32_t i = 0; i < len; i++)
        hash = (uint64_t) str[i] + (hash << 6) + (hash << 16) - hash;
    return hash;
}
