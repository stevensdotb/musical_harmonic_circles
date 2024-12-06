#include <stdio.h>
#include <stdlib.h>

/* Remove allocated pointers in memory */
void free_malloc(char **array, int size) {
    for (int index = 0; index < size; index++) {
        free(array[index]);
    }
    free(array);
}

void test_print_array(char **array) {
    int size = sizeof(array) * sizeof(array[0]);
    for (int index; index < size; index++) {
        printf("%s ", array[index]);
    }
}
