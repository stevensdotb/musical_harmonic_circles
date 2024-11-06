#ifndef NOTES_BUILDER_H
#define NOTES_BUILDER_H

#include "constants.h"

/* Find note index in MUSICAL_NOTES */
static int find_index(const char *note);

/* Prints the specified scale pattern*/
static void print_scale_pattern(ScalePatternType scale_pattern);

/* Parses sharp notes to flat E.g: F# -> Eb*/
static char *parse_sharp_to_flat(const char *note);

/* Gets the scale pattern by type */
ScalePatternType get_scale_pattern(char *scale_type);

/* Create the harmonic circle */
static char **create_harmonic_circle(ScalePatternType scale_pattern, char **note_scale);

// Write a flag (^) at the end of the note to highlight the relative note
static char *set_relative_note_flag(int index, const char *note);

/* Get given scale from a single note */
char **build_note_scale(const char *note, ScalePatternType scale_pattern);

/* Get all major scales */
char ***build_scales(char *scale_t);

#endif // NOTES_BUILDER_H