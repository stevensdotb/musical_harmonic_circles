#include <stdio.h>
#include <stdlib.h>

/* Remove allocated pointers in memory */
void free_malloc(char **array, int size)
{
    for (int index = 0; index < size; index++)
    {
        free(array[index]);
    }
    free(array);
}
