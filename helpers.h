#ifndef HELPERS_H
#define HELPER_H

/* Remove allocated pointers in memory */
void free_malloc(char **array, int size);

/* Validate array memory allocation */
void validate_malloc(char *array);

/* Validate 2d array memory allocation */
void validate_malloc_2d(char **array);

void delay(int microseconds);

#endif