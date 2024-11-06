#include "constants.h"

const char *chromatic_scale[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
const int chromatic_scale_size = sizeof(chromatic_scale) / sizeof(chromatic_scale[0]);

// Scales
const int major_scale_pattern[] = {2, 2, 1, 2, 2, 2, 1, 2};
const int major_scale_pattern_size = sizeof(major_scale_pattern) / sizeof(major_scale_pattern[0]);
const int minor_scale_pattern[] = {2, 1, 2, 2, 1, 2, 2, 1};
const int minor_scale_pattern_size = sizeof(minor_scale_pattern) / sizeof(minor_scale_pattern[0]);

// Chords
const int major_chords_pattern[] = {4, 3, 3};
const int major_chrods_pattern_size = sizeof(major_chords_pattern) / sizeof(major_chords_pattern[0]);
const int minor_chords_pattern[] = {3, 4, 5}; // TODO:
const int minor_chrods_pattern_size = sizeof(minor_chords_pattern) / sizeof(minor_chords_pattern[0]);

// Harmonic Circle
const int hcircle_pattern[] = {'M', 'm', 'm', 'M', 'M', 'm', 'd', 'M'};
// TODO:
const int hcircle_pattern_size = sizeof(hcircle_pattern) / sizeof(hcircle_pattern[0]);

const ScaleType scale_type = {"MAJOR_SCALE", "MINOR_SCALE", "MAJOR_CHORDS", "MINOR_CHORDS", "HARMONIC_CIRCLE"};
const ScalePatternsType scale_patterns = {
    {major_scale_pattern, major_scale_pattern_size},
    {minor_scale_pattern, minor_scale_pattern_size},
    {major_chords_pattern, major_chrods_pattern_size},
    {minor_chords_pattern, minor_chrods_pattern_size},
    {hcircle_pattern, hcircle_pattern_size},

};
