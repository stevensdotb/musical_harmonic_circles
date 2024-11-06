#ifndef CONSTANTS_H
#define CONSTATNS_H

extern const char *chromatic_scale[];
extern const int chromatic_scale_size;

// Scales
extern const int major_scale_pattern[];
extern const int major_scale_pattern_size;
extern const int minor_scale_pattern[];
extern const int minor_scale_pattern_size;

// Chords
extern const int major_chords_pattern[];
extern const int major_chrods_pattern_size;
extern const int minor_chords_pattern[];
extern const int minor_chrods_pattern_size;

// Harmonic Circle
extern const int hcircle_pattern[];
// TODO:
extern const int hcircle_pattern_size;

typedef struct ScalePatternStruct {
    const int *value;
    const int size;
} ScalePatternType;

typedef struct ScalePatterns {
    ScalePatternType MAJOR_SCALE;
    ScalePatternType MINOR_SCALE;
    ScalePatternType MAJOR_CHORDS;
    ScalePatternType MINOR_CHORDS;
    ScalePatternType HARMONIC_CIRCLE;
} ScalePatternsType;

typedef struct ScaleType {
    char *MAJOR_SCALE;
    char *MINOR_SCALE;
    char *MAJOR_CHORDS;
    char *MINOR_CHORDS;
    char *HARMONIC_CIRCLE;
} ScaleType;

extern const struct ScaleType scale_type;

extern const ScalePatternsType scale_patterns;

#endif