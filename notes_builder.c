#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// local headers
#include "helpers.h"
#include "notes_builder.h"

/* Find note index in MUSICAL_NOTES */
static int find_index(const char *note) {
    for (int i = 0; i < chromatic_scale_size; i++) {
        if (strcmp(chromatic_scale[i], note) == 0) {
            return i;
        }
    }
    return -1; // Note not found
}

/* Prints the Tone, semi-tone pattern*/
static void print_scale_pattern(ScalePatternType scale_pattern) {
    // TODO: Print the scale pattern based on the scale type
}

/* TODO: Parses sharp notes to flat E.g: D# -> Eb*/
static char *parse_sharp_to_flat(const char *note) {
    char *copy_note = (char *)malloc(strlen(note));
    if (copy_note != NULL) {
        strcpy(copy_note, note);
    }

    if (strstr(note, "#") == NULL) {
        return copy_note;
    }

    char *flat_note = (char *)malloc(4);
    if (flat_note == NULL) {
        return copy_note;
    }

    // Modify the sharp note
    strcpy(flat_note, chromatic_scale[find_index(note) + 1]);
    strcat(flat_note, "b");

    return flat_note;
}


/* Gets the scale pattern by type */
ScalePatternType get_scale_pattern(char *scale_t) {
    if (strcmp(scale_t, scale_type.MAJOR_SCALE) == 0) {
        return scale_patterns.MAJOR_SCALE;
    }

    if (strcmp(scale_t, scale_type.MINOR_SCALE) == 0) {
        return scale_patterns.MINOR_SCALE;
    }

    if (strcmp(scale_t, scale_type.MAJOR_CHORDS) == 0) {
        return scale_patterns.MAJOR_CHORDS;
    }
    if (strcmp(scale_t, scale_type.MINOR_CHORDS) == 0) {
        return scale_patterns.MINOR_CHORDS;
    }

    return scale_patterns.HARMONIC_CIRCLE;
}

/* Create harmonic circle relative notes scale */
char **create_relative_harmonic_circle(char **harmonic_circle) {
    const int main_scale_size = get_scale_pattern(scale_type.MAJOR_SCALE).size;
    char **relative = (char **)malloc(main_scale_size * sizeof(char *));

    if (relative == NULL) {
        return NULL;
    }

    // Start from the sixth note (5th index)
    int note_index = 5;
    int index = 0;

    while (index <= main_scale_size) {
        relative[index] = harmonic_circle[note_index];

        note_index++;

        if (note_index == (main_scale_size - 1)) {
            note_index = 0;
        }

        // Finish the loop with the last note of the circle
        if (relative[index] == NULL && index == 6) {
            break;
        }

        index++;
    }

    return relative;
}

/* Create the harmonic circle */
static char **create_harmonic_circle(ScalePatternType scale_pattern, char **note_scale) {
    const int main_scale_size = get_scale_pattern(scale_type.MAJOR_SCALE).size;
    char **harmonic_circle = (char **)malloc(main_scale_size * sizeof(char *));

    if (harmonic_circle == NULL || note_scale == NULL) {
        return NULL;
    }

    for (int index = 0; index < main_scale_size; index++) {
        char *copy_note = (char *)malloc(strlen(note_scale[index]) + 4);

        if (copy_note == NULL) {
            // free_malloc(harmonic_circle, main_scale_size);
            return NULL;
        }

        strcpy(copy_note, note_scale[index]);

        // Add minor letter
        if (scale_pattern.value[index] == 'm') {
            strcat(copy_note, "m");
        }
        // Add dim at the end
        else if (scale_pattern.value[index] == 'd') {
            strcat(copy_note, "dim");
        }
        
        harmonic_circle[index] = copy_note;
    }
    return harmonic_circle;
}

/* Get the musical scale from a single note */
char **build_note_scale(const char *note, ScalePatternType scale_pattern) {
    char **note_scale = (char **)malloc(get_scale_pattern(scale_type.MAJOR_SCALE).size * sizeof(char *));

    if (note_scale == NULL) {
        return NULL;
    }

    int note_index = find_index(note); // get the index of the note
    int scale_index = 0;               // Index to add the note to the scale
    int sp_index = 0;                  // to iterate the scale pattern

    while (scale_index < chromatic_scale_size && sp_index < scale_pattern.size) {
        char *_note = (char *)chromatic_scale[note_index];

        // TODO: Parse sharp notes to flat using parse_sharp_to_flat() function
        note_scale[sp_index] = _note;

        note_index = (note_index + scale_pattern.value[sp_index]) % chromatic_scale_size;

        sp_index++;
        scale_index++;
    }

    return note_scale;
}

/* Get all major scales */
char ***build_scales(char *scale_t) {
    ScalePatternType scale_pattern = get_scale_pattern(scale_t);
    const int main_scale_size = get_scale_pattern(scale_type.MAJOR_SCALE).size;
    char ***note_scales = (char ***)malloc(main_scale_size * sizeof(char **));

    if (note_scales == NULL) {
        return NULL;
    }

    for (int index = 0; index < chromatic_scale_size; index++) {
        note_scales[index] = (char **)malloc(scale_pattern.size * sizeof(char *));

        if (note_scales[index] == NULL) {
            free_malloc(note_scales[index], scale_pattern.size);
            return NULL;
        }

        if (strcmp(scale_t, scale_type.HARMONIC_CIRCLE) == 0) {
            note_scales[index] = create_harmonic_circle(
                scale_pattern,
                build_note_scale(chromatic_scale[index], get_scale_pattern(scale_type.MAJOR_SCALE))
            );
        } else {
            note_scales[index] = build_note_scale(chromatic_scale[index], scale_pattern);
        }
    }
    return note_scales;
}
