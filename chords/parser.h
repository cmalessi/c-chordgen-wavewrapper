#ifndef PARSER_H
#define PARSER_H

#include <stdint.h>
#include "chords.h"

typedef void (*chord_fn)(
	int16_t** buffer,
	int32_t* samples,
	double freq,
	double length,
	int octv
);

typedef struct {
	notes root;
	chord_fn fn;
	int octave;
	double duration;
} chord_spec;

int parse_chord(const char* arg, chord_spec* out);

#endif
