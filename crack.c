#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "md5.h"

#if __has_include("fileutil.h")
#include "fileutil.h"
#endif

#define PASS_LEN 50     // Maximum length any password will be.
#define HASH_LEN 33     // Length of hash plus one for null.

// Create a function protoype for the alphabetic function.
int alphabetic(const void *a, const void *b);

int main(int argc, char *argv[])
{
    // If there are less than 3 arguments, display an error message and exit the program.
    if (argc < 3) 
    {
        printf("Usage: %s hash_file dictionary_file\n", argv[0]);
        exit(1);
    }

    // Declare an integer variable for the size of the hashes array.
    int size;

    // Load the hashes file into the array.
    char **hashes = loadFileAA(argv[1], &size);
    
    // Sort the hashes using the qsort function.
    qsort(hashes, size, sizeof(char *), alphabetic);
    
    // Open the password file for reading.
    FILE *in = fopen(argv[2], "r");

    // Declare an integer variable for the number of matches found and set it to 0.
    int counter = 0;

    // Read through every password in the password file.
    char password[PASS_LEN];
    while (fgets(password, PASS_LEN, in) != NULL)
    {
        // Trim the newline character from the end of the current password if it has one.
        char *nl = strchr(password, '\n');
        if (nl)
        {
            *nl = '\0';
        }

        // Hash the current password.
        char *hash = md5(password, strlen(password));

        // Attempt to match the hash with all the hashes in the hash file.
        char *found = substringSearchAA(hash, hashes, size);

        // If there is a match, display both the password and hash and increase the counter by 1.
        if (found != NULL)
        {
            printf("Match Found\nPassword: %sHash: %s\n", password, hash);
            counter++;
        }
    }
    
    // Close the file, display the number of hashes found, and free up memory.
    fclose(in);
    printf("\nNumber of hashes found: %d\n", counter);
    freeAA(hashes, size);
}

// Create a comparison function that allows the qsort function to sort alphabetically.
int alphabetic(const void *a, const void *b)
{
    char **aa = (char **)a;
    char **bb = (char **)b;

    return strcmp(*aa, *bb);
}