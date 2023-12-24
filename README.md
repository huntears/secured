# Secured

This repository contains a simple implementation of the 1st year secured
project.

## Differences from the subject

This implementation:
 - Does not use the given header file
 - Names the hashtable as a hashmap. Why? Because I prefer it that way :3
 - Does not compile a static library. Why? Because I couldn't be bothered
 - Uses libc function. Why? Because I couldn't be bothered to reimplement them
 - Can comment inside functions. Why? Because
 - Some functions prototypes contain const where there wasn't. Why? Because I
 like to respect const correctness

This should still be enough of a reference to the project either way.

## Hashing function

The chosen hashing function is sdbm as it has very few collisions and overall
good randomization, which is everything that could be asked for a hashmap's
hashing function.

Read more [here on this SO answer](https://softwareengineering.stackexchange.com/questions/49550/which-hashing-algorithm-is-best-for-uniqueness-and-speed/145633#145633)
