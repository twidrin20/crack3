#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

const int PASS_LEN=50;        // Maximum any password will be


// Stucture to hold both a plaintext password and a hash.
struct entry 
{
    // TODO: FILL THIS IN
};



// TODO
// Read in the dictionary file and return an array of entry structs.
// Each entry should contain both the hash and the dictionary
// word.
struct entry *read_dictionary(char *filename, int *size)
{
    *size = 0;
    return NULL;
}


int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        printf("Usage: %s hash_file dict_file\n", argv[0]);
        exit(1);
    }

    // TODO: Read the dictionary file into an array of entry structures
    struct entry *dict = read_dictionary(NULL, NULL);
    
    // TODO: Sort the hashed dictionary using qsort.
    // You will need to provide a comparison function that
    // sorts the array by hash value.
    qsort(dict, 0, 0, NULL);
    
    // Partial example of using bsearch, for testing. Delete this line
    // once you get the remainder of the program working.
    // This is the hash for "rockyou".
    struct entry *found = bsearch("f806fc5a2a0d5ba2471600758452799c", dict, 0, 0, NULL);

    // TODO
    // Open the hash file for reading.

    // TODO
    // For each hash, search for it in the dictionary using
    // binary search.
    // If you find it, get the corresponding plaintext dictionary word.
    // Print out both the hash and word.
    // Need only one loop. (Yay!)
}
