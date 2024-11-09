#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fileutil.h"

// Load the text file from the given filename.
// Return a pointer to the array of strings.
// Sets the value of size to be the number of valid
// entries in the array (not the total array length).
char ** loadFileAA(char *filename, int *size)
{
	// Open the given file for reading.
	FILE *in = fopen(filename, "r");

	// If the file has not been created, inform the user that it cannot be 
	// opened and exit the program.
	if (!in)
	{
	    perror("Can't open file");
	    exit(1);
	}
	
	// Set the capacity of the array to 25.
	int capacity = 25;

	// Allocate memory for an array of strings.
	char ** arr = malloc(capacity * sizeof(char *));

	// Set the number of entries in the array to 0.
	*size = 0;

	char line[255];
	
	while (fgets(line, 255, in) != NULL)
    {
		// If the number of entries exceeds the capacity of the array, increase the 
		// capacity by 5, and expand the array to its new capacity.
		if (*size >= capacity)
		{
			capacity += 5;
			char ** temp = realloc(arr, capacity * sizeof(char *));
			arr = temp;
		}

        // Trim the newline character from the end of the current line if it has one.
        char *nl = strchr(line, '\n');
        if (nl)
        {
            *nl = '\0';
        }

		// Allocate memory for the string.
		arr[*size] = malloc(strlen(line) + 1);

		// Copy the string to the array.
		strcpy(arr[*size], line);

		// Increase the number of entries by 1.
		(*size)++;
	}

	// Close the file.
	fclose(in);

	// Return the pointer to the array of strings.
	return arr;
}

// Search the array for the target string.
char * substringSearchAA(char *target, char **lines, int size)
{
	// Loops through every entry in the array.
	for (int i = 0; i < size; i++) 
	{
		// If the target string is in the current entry, return that entry.
        if (strstr(lines[i], target) != NULL) {
            return lines[i];
		}
    }
	// If the target string was not found, return NULL.
	return NULL;
}

// Free the memory used by the array.
void freeAA(char ** arr, int size)
{
	// Loops through and frees up every entry in the array.
	for (int i = 0; i < size; i++) 
	{
        free(arr[i]);
    }
}