#include "parser.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    const char* name;
    notes note;
} note_entry;

static note_entry note_table[] = {
	{"C", C}, {"C#", Cs}, {"Db", Db},
	{"D", D}, {"D#", Ds}, {"Eb", Eb},
	{"E", E},
	{"F", F}, {"F#", Fs}, {"Gb", Gb},
	{"G", G}, {"G#", Gs}, {"Ab", Ab},
	{"A", A}, {"A#", As}, {"Bb", Bb},
	{"B", B},
};

static int parse_note(const char* s, notes* out) {
	for (size_t i = 0; i < sizeof(note_table)/sizeof(*note_table); i++) {
		if (strcmp(s, note_table[i].name) == 0) {
			*out = note_table[i].note;
			return 1;
		}
	}
	return 0;
}

typedef struct {
	const char* name;
	chord_fn fn;
} chord_entry;

static chord_entry chord_table[] = {
	{"maj", maj},
	{"majinv1", majinv1},
	{"majinv2", majinv2},
	{"min", min},
	{"mininv1", mininv1},
	{"mininv2", mininv2},
	{"aug", aug},
	{"auginv1", auginv1},
	{"auginv2", auginv2},
	{"dim", dim},
	{"diminv1", diminv1},
	{"diminv2", diminv2},

	{"maj7", maj7},
	{"maj7inv1", maj7inv1},
	{"maj7inv2", maj7inv2},
	{"maj7inv3", maj7inv3},

	{"min7", min7},
	{"min7inv1", min7inv1},
	{"min7inv2", min7inv2},
	{"min7inv3", min7inv3},

	{"dom7", dom7},
	{"dom7inv1", dom7inv1},
	{"dom7inv2", dom7inv2},
	{"dom7inv3", dom7inv3},
};

static chord_fn get_chord_fn(const char* name) {
	for (size_t i = 0; i < sizeof(chord_table)/sizeof(*chord_table); i++) {
		if (strcmp(name, chord_table[i].name) == 0)
			return chord_table[i]. fn;
	}
	return NULL;
}

int parse_chord(const char*arg, chord_spec* out) {
	char buf[64];
	strncpy(buf, arg, sizeof(buf));
	buf[sizeof(buf) - 1] = '\0';

	char* note_str = strtok(buf, ":");
	char* qual_str = strtok(NULL, ":");
	char* oct_str = strtok(NULL, ":");
	char* dur_str = strtok(NULL, ":");

	if (!note_str || !qual_str || !oct_str || !dur_str)
		return 0;

	if (!parse_note(note_str, &out->root))
		return 0;

	out->fn = get_chord_fn(qual_str);
	if (!out->fn)
		return 0;

	out->octave = atoi(oct_str);
	out->duration = atof(dur_str);

	if (out-> octave < 0 || out-> duration <= 0.0)
		return 0;

	return 1;
}
