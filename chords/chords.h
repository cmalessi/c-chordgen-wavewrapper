#ifndef CHORDS_H
#define CHORDS_H

#include <stdint.h>

#define SAMPLEFREQ 44100

typedef enum {
	C,
	Cs,
	D,
	Ds,
	E,
	F,
	Fs,
	G,
	Gs,
	A,
	As,
	B,
	NOTE_COUNT
} notes;

#define Db Cs
#define Eb Ds
#define Gb Fs
#define Ab Gs
#define Bb As

extern double notefreqs[NOTE_COUNT];

void init_notefreqs(void);
void note(int16_t** buffer, int32_t* samples, double freq, double length, int octv);
void maj(int16_t** buffer, int32_t* samples, double freq, double length, int octv);
void majinv1(int16_t** buffer, int32_t* samples, double freq, double length, int octv);
void majinv2(int16_t** buffer, int32_t* samples, double freq, double length, int octv);
void min(int16_t** buffer, int32_t* samples, double freq, double length, int octv);
void mininv1(int16_t** buffer, int32_t* samples, double freq, double length, int octv);
void mininv2(int16_t** buffer, int32_t* samples, double freq, double length, int octv);
void aug(int16_t** buffer, int32_t* samples, double freq, double length, int octv);
void auginv1(int16_t** buffer, int32_t* samples, double freq, double length, int octv);
void auginv2(int16_t** buffer, int32_t* samples, double freq, double length, int octv);
void dim(int16_t** buffer, int32_t* samples, double freq, double length, int octv);
void diminv1(int16_t** buffer, int32_t* samples, double freq, double length, int octv);
void diminv2(int16_t** buffer, int32_t* samples, double freq, double length, int octv);
void maj7(int16_t** buffer, int32_t* samples, double freq, double length, int octv);
void maj7inv1(int16_t** buffer, int32_t* samples, double freq, double length, int octv);
void maj7inv2(int16_t** buffer, int32_t* samples, double freq, double length, int octv);
void maj7inv3(int16_t** buffer, int32_t* samples, double freq, double length, int octv);
void min7(int16_t** buffer, int32_t* samples, double freq, double length, int octv);
void min7inv1(int16_t** buffer, int32_t* samples, double freq, double length, int octv);
void min7inv2(int16_t** buffer, int32_t* samples, double freq, double length, int octv);
void min7inv3(int16_t** buffer, int32_t* samples, double freq, double length, int octv);
void dom7(int16_t** buffer, int32_t* samples, double freq, double length, int octv);
void dom7inv1(int16_t** buffer, int32_t* samples, double freq, double length, int octv);
void dom7inv2(int16_t** buffer, int32_t* samples, double freq, double length, int octv);
void dom7inv3(int16_t** buffer, int32_t* samples, double freq, double length, int octv);

#endif
