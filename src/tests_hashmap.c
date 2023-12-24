/*
** EPITECH PROJECT, 2023
** secured
** File description:
** tests_hashmap
*/

#ifdef UNIT_TESTS

#include <criterion/criterion.h>
#include <stdio.h>

#include "hashing_functions.h"
#include "hashmap/hashmap.h"

// Just have a 1 second timeout on all tests just in case there's an infinite
// loop, which would instantly deadlock the whole thing
TestSuite(hm, .timeout = 1);

Test(hm, simple_insert_fetch)
{
    hashmap_t *h = new_hashmap(sdbm, 32);
    char *value = NULL;

    hm_insert(h, "bruv", "hurb");
    value = hm_search(h, "bruv");

    cr_assert_str_eq("hurb", value);

    delete_hashmap(h);
}

Test(hm, simple_null_fetch)
{
    hashmap_t *h = new_hashmap(sdbm, 32);
    char *value = NULL;

    value = hm_search(h, "bruv");

    cr_assert_null(value);

    delete_hashmap(h);
}

Test(hm, create_delete)
{
    hashmap_t *h = new_hashmap(sdbm, 32);

    delete_hashmap(h);
}

Test(hm, fetch_after_delete)
{
    hashmap_t *h = new_hashmap(sdbm, 32);
    char *value = NULL;

    hm_insert(h, "bruv", "hurb");
    value = hm_search(h, "bruv");
    cr_assert_str_eq("hurb", value);

    hm_delete(h, "bruv");
    value = hm_search(h, "bruv");
    cr_assert_null(value);

    delete_hashmap(h);
}

Test(hm, bad_delete)
{
    hashmap_t *h = new_hashmap(sdbm, 32);

    int ret_value = hm_delete(h, "bruv");

    cr_assert_neq(ret_value, 0);

    delete_hashmap(h);
}

Test(hm, insert_overwrite)
{
    hashmap_t *h = new_hashmap(sdbm, 32);
    char *value = NULL;

    hm_insert(h, "bruv", "hurb");
    value = hm_search(h, "bruv");
    cr_assert_str_eq("hurb", value);

    hm_insert(h, "bruv", "yip yip");
    value = hm_search(h, "bruv");
    cr_assert_str_eq("yip yip", value);

    delete_hashmap(h);
}

Test(hm, one_bucket_thousand_inserts)
{
    hashmap_t *h = new_hashmap(sdbm, 1);
    char *value = NULL;
    char key_buffer[16] = {0};
    char value_buffer[16] = {0};

    for (int i = 0; i < 1000; i++) {
        sprintf(key_buffer, "bruh%d", i);
        sprintf(value_buffer, "hurb%d", i);
        hm_insert(h, key_buffer, value_buffer);
    }

    for (int i = 0; i < 1000; i++) {
        sprintf(key_buffer, "bruh%d", i);
        sprintf(value_buffer, "hurb%d", i);
        value = hm_search(h, key_buffer);
        cr_assert_str_eq(value, value_buffer);
    }

    delete_hashmap(h);
}

Test(hm, thousand_bucket_thousand_inserts)
{
    hashmap_t *h = new_hashmap(sdbm, 1000);
    char *value = NULL;
    char key_buffer[16] = {0};
    char value_buffer[16] = {0};

    for (int i = 0; i < 1000; i++) {
        sprintf(key_buffer, "bruh%d", i);
        sprintf(value_buffer, "hurb%d", i);
        hm_insert(h, key_buffer, value_buffer);
    }

    for (int i = 0; i < 1000; i++) {
        sprintf(key_buffer, "bruh%d", i);
        sprintf(value_buffer, "hurb%d", i);
        value = hm_search(h, key_buffer);
        cr_assert_str_eq(value, value_buffer);
    }

    delete_hashmap(h);
}

Test(hm, one_bucket_ten_thousand_inserts)
{
    hashmap_t *h = new_hashmap(sdbm, 1);
    char *value = NULL;
    char key_buffer[16] = {0};
    char value_buffer[16] = {0};

    for (int i = 0; i < 10000; i++) {
        sprintf(key_buffer, "bruh%d", i);
        sprintf(value_buffer, "hurb%d", i);
        hm_insert(h, key_buffer, value_buffer);
    }

    for (int i = 0; i < 10000; i++) {
        sprintf(key_buffer, "bruh%d", i);
        sprintf(value_buffer, "hurb%d", i);
        value = hm_search(h, key_buffer);
        cr_assert_str_eq(value, value_buffer);
    }

    delete_hashmap(h);
}

Test(hm, thousand_bucket_ten_thousand_inserts)
{
    hashmap_t *h = new_hashmap(sdbm, 1000);
    char *value = NULL;
    char key_buffer[16] = {0};
    char value_buffer[16] = {0};

    for (int i = 0; i < 10000; i++) {
        sprintf(key_buffer, "bruh%d", i);
        sprintf(value_buffer, "hurb%d", i);
        hm_insert(h, key_buffer, value_buffer);
    }

    for (int i = 0; i < 10000; i++) {
        sprintf(key_buffer, "bruh%d", i);
        sprintf(value_buffer, "hurb%d", i);
        value = hm_search(h, key_buffer);
        cr_assert_str_eq(value, value_buffer);
    }

    delete_hashmap(h);
}

// 30 seconds is a lot, but it's just to be sure the CI goes through
// It only takes 2 seconds on my system :)
Test(hm, ten_thousand_bucket_million_inserts, .timeout = 30)
{
    hashmap_t *h = new_hashmap(sdbm, 10000);
    char *value = NULL;
    char key_buffer[16] = {0};
    char value_buffer[16] = {0};

    for (int i = 0; i < 1000000; i++) {
        sprintf(key_buffer, "bruh%d", i);
        sprintf(value_buffer, "hurb%d", i);
        hm_insert(h, key_buffer, value_buffer);
    }

    for (int i = 0; i < 1000000; i++) {
        sprintf(key_buffer, "bruh%d", i);
        sprintf(value_buffer, "hurb%d", i);
        value = hm_search(h, key_buffer);
        cr_assert_str_eq(value, value_buffer);
    }

    delete_hashmap(h);
}

Test(hm, thousand_bucket_ten_thousand_inserts_some_delete)
{
    hashmap_t *h = new_hashmap(sdbm, 1000);
    char *value = NULL;
    char key_buffer[16] = {0};
    char value_buffer[16] = {0};

    for (int i = 0; i < 10000; i++) {
        sprintf(key_buffer, "bruh%d", i);
        sprintf(value_buffer, "hurb%d", i);
        hm_insert(h, key_buffer, value_buffer);
    }

    for (int i = 0; i < 10000; i++) {
        sprintf(key_buffer, "bruh%d", i);
        sprintf(value_buffer, "hurb%d", i);
        value = hm_search(h, key_buffer);
        cr_assert_str_eq(value, value_buffer);
    }

    for (int i = 0; i < 10000; i++) {
        if (!(i % 3))
            continue;
        sprintf(key_buffer, "bruh%d", i);
        int ret_value = hm_delete(h, key_buffer);
        cr_assert_eq(ret_value, 0);
    }

    for (int i = 0; i < 10000; i++) {
        sprintf(key_buffer, "bruh%d", i);
        value = hm_search(h, key_buffer);

        if (!(i % 3)) {
            sprintf(value_buffer, "hurb%d", i);
            cr_assert_str_eq(value, value_buffer);
        } else
            cr_assert_null(value, "value not null with i == %d", i);
    }

    delete_hashmap(h);
}

Test(hm, thousand_bucket_ten_thousand_inserts_more_delete)
{
    hashmap_t *h = new_hashmap(sdbm, 1000);
    char *value = NULL;
    char key_buffer[16] = {0};
    char value_buffer[16] = {0};

    for (int i = 0; i < 10000; i++) {
        sprintf(key_buffer, "bruh%d", i);
        sprintf(value_buffer, "hurb%d", i);
        hm_insert(h, key_buffer, value_buffer);
    }

    for (int i = 0; i < 10000; i++) {
        sprintf(key_buffer, "bruh%d", i);
        sprintf(value_buffer, "hurb%d", i);
        value = hm_search(h, key_buffer);
        cr_assert_str_eq(value, value_buffer);
    }

    for (int i = 0; i < 10000; i++) {
        if (i % 6)
            continue;
        sprintf(key_buffer, "bruh%d", i);
        int ret_value = hm_delete(h, key_buffer);
        cr_assert_eq(ret_value, 0);
    }

    for (int i = 0; i < 10000; i++) {
        sprintf(key_buffer, "bruh%d", i);
        value = hm_search(h, key_buffer);

        if (i % 6) {
            sprintf(value_buffer, "hurb%d", i);
            cr_assert_str_eq(value, value_buffer);
        } else
            cr_assert_null(value, "value not null with i == %d", i);
    }

    delete_hashmap(h);
}

#endif
