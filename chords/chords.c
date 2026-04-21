#include "chords.h"
#include <math.h>

double notefreqs[NOTE_COUNT];

static inline double semitone(double n) {
	return pow(2.0, n / 12.0);
}

void init_notefreqs(void) {
	notefreqs[C] = 220 * semitone(3); 
	notefreqs[Cs] = notefreqs[C] * semitone(1);
	notefreqs[D] = notefreqs[C] * semitone(2);
	notefreqs[Ds] = notefreqs[C] * semitone(3);
	notefreqs[E] = notefreqs[C] * semitone(4);
	notefreqs[F] = notefreqs[C] * semitone(5);
	notefreqs[Fs] = notefreqs[C] * semitone(6);
	notefreqs[G] = notefreqs[C] * semitone(7);
	notefreqs[Gs] = notefreqs[C] * semitone(8);
	notefreqs[A] = notefreqs[C] * semitone(9);
	notefreqs[As] = notefreqs[C] * semitone(10);
	notefreqs[B] = notefreqs[C] * semitone(11);
}

void note(int16_t** buffer, int32_t* samples, double freq, double length, int octv) {

	double time;
	freq *= pow(2, octv - 4);

	for (time = 0; time < length; time += 1.0 / SAMPLEFREQ) {
		*(*buffer)++ = sin(2 * M_PI * freq * time) * 32767;
	}
	
	*samples += length * SAMPLEFREQ;
	return;
}

void maj(int16_t** buffer, int32_t* samples, double freq, double length, int octv) {
	
	double time;
	freq *= pow(2, octv - 4);

	double f3 = freq * semitone(4);
	double f5 = freq * semitone(7);

	for (time = 0; time < length; time += 1.0 / SAMPLEFREQ) {
		*(*buffer)++ = (sin(2 * M_PI * freq * time) +
			     sin(2 * M_PI * f3 * time) +
			     sin(2 * M_PI * f5 * time)) / 3.0 * 32767;
	}

	*samples += length * SAMPLEFREQ;
	return;
}

void majinv1(int16_t** buffer, int32_t* samples, double freq, double length, int octv) {
	
	double time;
	freq *= pow(2, octv - 4);

	double f3 = freq * semitone(4);
	double f5 = freq * semitone(7);
	double octave = freq * 2;

	for (time = 0; time < length; time += 1.0 / SAMPLEFREQ) {
		*(*buffer)++ = (sin(2 * M_PI * octave * time) +
			     sin(2 * M_PI * f3 * time) +
			     sin(2 * M_PI * f5 * time)) / 3.0 * 32767;
	}

	*samples += length * SAMPLEFREQ;
	return;
}

void majinv2(int16_t** buffer, int32_t* samples, double freq, double length, int octv) {
	
	double time;
	freq *= pow(2, octv - 4);

	double octavef3 = freq * semitone(4) * 2;
	double f5 = freq * semitone(7);
	double octave = freq * 2;

	for (time = 0; time < length; time += 1.0 / SAMPLEFREQ) {
		*(*buffer)++ = (sin(2 * M_PI * octave * time) +
			     sin(2 * M_PI * octavef3 * time) +
			     sin(2 * M_PI * f5 * time)) / 3.0 * 32767;
	}

	*samples += length * SAMPLEFREQ;
	return;
}

void min(int16_t** buffer, int32_t* samples, double freq, double length, int octv) {
	
	double time;
	freq *= pow(2, octv - 4);

	double f3 = freq * semitone(3);
	double f5 = freq * semitone(7);

	for (time = 0; time < length; time += 1.0 / SAMPLEFREQ) {
		*(*buffer)++ = (sin(2 * M_PI * freq * time) +
			     sin(2 * M_PI * f3 * time) +
			     sin(2 * M_PI * f5 * time)) / 3.0 * 32767;
	}

	*samples += length * SAMPLEFREQ;
	return;
}

void mininv1(int16_t** buffer, int32_t* samples, double freq, double length, int octv) {
	
	double time;
	freq *= pow(2, octv - 4);

	double f3 = freq * semitone(3);
	double f5 = freq * semitone(7);
	double octave = freq * 2;

	for (time = 0; time < length; time += 1.0 / SAMPLEFREQ) {
		*(*buffer)++ = (sin(2 * M_PI * octave * time) +
			     sin(2 * M_PI * f3 * time) +
			     sin(2 * M_PI * f5 * time)) / 3.0 * 32767;
	}

	*samples += length * SAMPLEFREQ;
	return;
}

void mininv2(int16_t** buffer, int32_t* samples, double freq, double length, int octv) {
	
	double time;
	freq *= pow(2, octv - 4);

	double octavef3 = freq * semitone(3) * 2;
	double f5 = freq * semitone(7);
	double octave = freq * 2;

	for (time = 0; time < length; time += 1.0 / SAMPLEFREQ) {
		*(*buffer)++ = (sin(2 * M_PI * octave * time) +
			     sin(2 * M_PI * octavef3 * time) +
			     sin(2 * M_PI * f5 * time)) / 3.0 * 32767;
	}

	*samples += length * SAMPLEFREQ;
	return;
}

void aug(int16_t** buffer, int32_t* samples, double freq, double length, int octv) {
	
	double time;
	freq *= pow(2, octv - 4);

	double f3 = freq * semitone(4);
	double f5 = freq * semitone(8);

	for (time = 0; time < length; time += 1.0 / SAMPLEFREQ) {
		*(*buffer)++ = (sin(2 * M_PI * freq * time) +
			     sin(2 * M_PI * f3 * time) +
			     sin(2 * M_PI * f5 * time)) / 3.0 * 32767;
	}

	*samples += length * SAMPLEFREQ;
	return;
}

void auginv1(int16_t** buffer, int32_t* samples, double freq, double length, int octv) {
	
	double time;
	freq *= pow(2, octv - 4);

	double f3 = freq * semitone(4);
	double f5 = freq * semitone(8);
	double octave = freq * 2;

	for (time = 0; time < length; time += 1.0 / SAMPLEFREQ) {
		*(*buffer)++ = (sin(2 * M_PI * octave * time) +
			     sin(2 * M_PI * f3 * time) +
			     sin(2 * M_PI * f5 * time)) / 3.0 * 32767;
	}

	*samples += length * SAMPLEFREQ;
	return;
}

void auginv2(int16_t** buffer, int32_t* samples, double freq, double length, int octv) {
	
	double time;
	freq *= pow(2, octv - 4);

	double octavef3 = freq * semitone(4) * 2;
	double f5 = freq * semitone(8);
	double octave = freq * 2;

	for (time = 0; time < length; time += 1.0 / SAMPLEFREQ) {
		*(*buffer)++ = (sin(2 * M_PI * octave * time) +
			     sin(2 * M_PI * octavef3 * time) +
			     sin(2 * M_PI * f5 * time)) / 3.0 * 32767;
	}

	*samples += length * SAMPLEFREQ;
	return;
}

void dim(int16_t** buffer, int32_t* samples, double freq, double length, int octv) {
	
	double time;
	freq *= pow(2, octv - 4);

	double f3 = freq * semitone(3);
	double f5 = freq * semitone(6);

	for (time = 0; time < length; time += 1.0 / SAMPLEFREQ) {
		*(*buffer)++ = (sin(2 * M_PI * freq * time) +
			     sin(2 * M_PI * f3 * time) +
			     sin(2 * M_PI * f5 * time)) / 3.0 * 32767;
	}

	*samples += length * SAMPLEFREQ;
	return;
}

void diminv1(int16_t** buffer, int32_t* samples, double freq, double length, int octv) {
	
	double time;
	freq *= pow(2, octv - 4);

	double f3 = freq * semitone(3);
	double f5 = freq * semitone(6);
	double octave = freq * 2;

	for (time = 0; time < length; time += 1.0 / SAMPLEFREQ) {
		*(*buffer)++ = (sin(2 * M_PI * octave * time) +
			     sin(2 * M_PI * f3 * time) +
			     sin(2 * M_PI * f5 * time)) / 3.0 * 32767;
	}

	*samples += length * SAMPLEFREQ;
	return;
}

void diminv2(int16_t** buffer, int32_t* samples, double freq, double length, int octv) {
	
	double time;
	freq *= pow(2, octv - 4);

	double octavef3 = freq * semitone(3) * 2;
	double f5 = freq * semitone(6);
	double octave = freq * 2;

	for (time = 0; time < length; time += 1.0 / SAMPLEFREQ) {
		*(*buffer)++ = (sin(2 * M_PI * octave * time) +
			     sin(2 * M_PI * octavef3 * time) +
			     sin(2 * M_PI * f5 * time)) / 3.0 * 32767;
	}

	*samples += length * SAMPLEFREQ;
	return;
}

void maj7(int16_t** buffer, int32_t* samples, double freq, double length, int octv) {

	double time;
	freq *= pow(2, octv - 4);

	double f3 = freq * semitone(4);
	double f5 = freq * semitone(7);
	double f7 = freq * semitone(11);

	for (time = 0; time < length; time += 1.0 / SAMPLEFREQ) {
		*(*buffer)++ = (sin(2 * M_PI * freq * time) +
			     sin(2 * M_PI * f3 * time) +
			     sin(2 * M_PI * f5 * time) +
			     sin(2 * M_PI * f7 * time)) / 4.0 * 32767;
	}

	*samples += length * SAMPLEFREQ;
	return;
}


void maj7inv1(int16_t** buffer, int32_t* samples, double freq, double length, int octv) {
	
	double time;
	freq *= pow(2, octv - 4);

	double f3 = freq * semitone(4);
	double f5 = freq * semitone(7);
	double f7 = freq * semitone(11);
	double octave = freq * 2;

	for (time = 0; time < length; time += 1.0 / SAMPLEFREQ) {
		*(*buffer)++ = (sin(2 * M_PI * f3 * time) +
			     sin(2 * M_PI * f5 * time) +
			     sin(2 * M_PI * f7 * time) +
			     sin(2 * M_PI * octave * time)) / 4.0 * 32767;
	}

	*samples += length * SAMPLEFREQ;
	return;
}

void maj7inv2(int16_t** buffer, int32_t* samples, double freq, double length, int octv) {
	
	double time;
	freq *= pow(2, octv - 4);

	double f5 = freq * semitone(7);
	double f7 = freq * semitone(11);
	double octave = freq * 2;
	double octavef3 = freq * semitone(4) * 2;

	for (time = 0; time < length; time += 1.0 / SAMPLEFREQ) {
		*(*buffer)++ = (sin(2 * M_PI * f5 * time) +
			     sin(2 * M_PI * f7 * time) +
			     sin(2 * M_PI * octave * time) +
			     sin(2 * M_PI * octavef3 * time)) / 4.0 * 32767;
	}

	*samples += length * SAMPLEFREQ;
	return;
}

void maj7inv3(int16_t** buffer, int32_t* samples, double freq, double length, int octv) {
	
	double time;
	freq *= pow(2, octv - 4);

	double f7 = freq * semitone(11);
	double octave = freq * 2;
	double octavef3 = freq * semitone(4) * 2;
	double octavef5 = freq * semitone(7) * 2;

	for (time = 0; time < length; time += 1.0 / SAMPLEFREQ) {
		*(*buffer)++ = (sin(2 * M_PI * f7 * time) +
			     sin(2 * M_PI * octave * time) +
			     sin(2 * M_PI * octavef3 * time) +
			     sin(2 * M_PI * octavef5 * time)) / 4.0 * 32767;
	}

	*samples += length * SAMPLEFREQ;
	return;
}

void min7(int16_t** buffer, int32_t* samples, double freq, double length, int octv) {

	double time;
	freq *= pow(2, octv - 4);

	double f3 = freq * semitone(3);
	double f5 = freq * semitone(7);
	double f7 = freq * semitone(10);

	for (time = 0; time < length; time += 1.0 / SAMPLEFREQ) {
		*(*buffer)++ = (sin(2 * M_PI * freq * time) +
			     sin(2 * M_PI * f3 * time) +
			     sin(2 * M_PI * f5 * time) +
			     sin(2 * M_PI * f7 * time)) / 4.0 * 32767;
	}

	*samples += length * SAMPLEFREQ;
	return;
}


void min7inv1(int16_t** buffer, int32_t* samples, double freq, double length, int octv) {
	
	double time;
	freq *= pow(2, octv - 4);

	double f3 = freq * semitone(3);
	double f5 = freq * semitone(7);
	double f7 = freq * semitone(10);
	double octave = freq * 2;

	for (time = 0; time < length; time += 1.0 / SAMPLEFREQ) {
		*(*buffer)++ = (sin(2 * M_PI * f3 * time) +
			     sin(2 * M_PI * f5 * time) +
			     sin(2 * M_PI * f7 * time) +
			     sin(2 * M_PI * octave * time)) / 4.0 * 32767;
	}

	*samples += length * SAMPLEFREQ;
	return;
}

void min7inv2(int16_t** buffer, int32_t* samples, double freq, double length, int octv) {
	
	double time;
	freq *= pow(2, octv - 4);

	double f5 = freq * semitone(7);
	double f7 = freq * semitone(10);
	double octave = freq * 2;
	double octavef3 = freq * semitone(3) * 2;

	for (time = 0; time < length; time += 1.0 / SAMPLEFREQ) {
		*(*buffer)++ = (sin(2 * M_PI * f5 * time) +
			     sin(2 * M_PI * f7 * time) +
			     sin(2 * M_PI * octave * time) +
			     sin(2 * M_PI * octavef3 * time)) / 4.0 * 32767;
	}

	*samples += length * SAMPLEFREQ;
	return;
}

void min7inv3(int16_t** buffer, int32_t* samples, double freq, double length, int octv) {
	
	double time;
	freq *= pow(2, octv - 4);

	double f7 = freq * semitone(10);
	double octave = freq * 2;
	double octavef3 = freq * semitone(3) * 2;
	double octavef5 = freq * semitone(7) * 2;

	for (time = 0; time < length; time += 1.0 / SAMPLEFREQ) {
		*(*buffer)++ = (sin(2 * M_PI * f7 * time) +
			     sin(2 * M_PI * octave * time) +
			     sin(2 * M_PI * octavef3 * time) +
			     sin(2 * M_PI * octavef5 * time)) / 4.0 * 32767;
	}

	*samples += length * SAMPLEFREQ;
	return;
}

void dom7(int16_t** buffer, int32_t* samples, double freq, double length, int octv) {

	double time;
	freq *= pow(2, octv - 4);

	double f3 = freq * semitone(4);
	double f5 = freq * semitone(7);
	double f7 = freq * semitone(10);

	for (time = 0; time < length; time += 1.0 / SAMPLEFREQ) {
		*(*buffer)++ = (sin(2 * M_PI * freq * time) +
			     sin(2 * M_PI * f3 * time) +
			     sin(2 * M_PI * f5 * time) +
			     sin(2 * M_PI * f7 * time)) / 4.0 * 32767;
	}

	*samples += length * SAMPLEFREQ;
	return;
}

void dom7inv1(int16_t** buffer, int32_t* samples, double freq, double length, int octv) {

	double time;
	freq *= pow(2, octv - 4);

	double f3 = freq * semitone(4);
	double f5 = freq * semitone(7);
	double f7 = freq * semitone(10);
	double octave = freq * 2;

	for (time = 0; time < length; time += 1.0 / SAMPLEFREQ) {
		*(*buffer)++ = (sin(2 * M_PI * octave * time) +
			     sin(2 * M_PI * f3 * time) +
			     sin(2 * M_PI * f5 * time) +
			     sin(2 * M_PI * f7 * time)) / 4.0 * 32767;
	}

	*samples += length * SAMPLEFREQ;
	return;
}

void dom7inv2(int16_t** buffer, int32_t* samples, double freq, double length, int octv) {

	double time;
	freq *= pow(2, octv - 4);

	double octavef3 = freq * semitone(4) * 2;
	double f5 = freq * semitone(7);
	double f7 = freq * semitone(10);
	double octave = freq * 2;

	for (time = 0; time < length; time += 1.0 / SAMPLEFREQ) {
		*(*buffer)++ = (sin(2 * M_PI * octave * time) +
			     sin(2 * M_PI * octavef3 * time) +
			     sin(2 * M_PI * f5 * time) +
			     sin(2 * M_PI * f7 * time)) / 4.0 * 32767;
	}

	*samples += length * SAMPLEFREQ;
	return;
}

void dom7inv3(int16_t** buffer, int32_t* samples, double freq, double length, int octv) {

	double time;
	freq *= pow(2, octv - 4);

	double octavef3 = freq * semitone(4) * 2;
	double octavef5 = freq * semitone(7) * 2;
	double f7 = freq * semitone(10);
	double octave = freq * 2;

	for (time = 0; time < length; time += 1.0 / SAMPLEFREQ) {
		*(*buffer)++ = (sin(2 * M_PI * octave * time) +
			     sin(2 * M_PI * octavef3 * time) +
			     sin(2 * M_PI * octavef5 * time) +
			     sin(2 * M_PI * f7 * time)) / 4.0 * 32767;
	}

	*samples += length * SAMPLEFREQ;
	return;
}
