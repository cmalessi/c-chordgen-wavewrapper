#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "chords.h"
#include "parser.h"

void wav_wrapper(FILE* f, uint32_t datasize, int16_t* audiodata);

int main(int argc, char* argv[]) {
	
	FILE* fptr = fopen("output.wav", "wb");
	int16_t* databuffer = (int16_t*) malloc(2*(int)pow(10, 8));
	int16_t* databuffer_start = databuffer;

	uint32_t samples = 0;

	init_notefreqs();

	int i;
	for (i = 1; i < argc; i++) {
		chord_spec c;

		if (!parse_chord(argv[i], &c)) {
			fprintf(stderr, "invalid chord: %s\n", argv[i]);
			continue;
		}

		c.fn(
		    &databuffer,
		    &samples,
		    notefreqs[c.root],
		    c.duration,
		    c.octave
		);
	}
	
	wav_wrapper(fptr, samples * sizeof(uint16_t), databuffer_start);

	free(databuffer_start);
	fclose (fptr);
	return 0;
}

void wav_wrapper(FILE* f, uint32_t datasize, int16_t* audiodata) {

	fwrite("RIFF", 1, 4, f);
	
	uint32_t RIFF_cksize = datasize + 36;
	fwrite(&RIFF_cksize, 4, 1, f);

	fwrite("WAVE", 1, 4, f);

	fwrite("fmt ", 1, 4, f);

	uint32_t fmt_cksize = 16;
	fwrite(&fmt_cksize, 4, 1, f);

	uint16_t wFormatTag = 1;
	fwrite(&wFormatTag, 2, 1, f);

	uint16_t nChannels = 1;
	fwrite(&nChannels, 2, 1, f);

	uint32_t nSamplesPerSec = 44100;
	fwrite(&nSamplesPerSec, 4, 1, f);

	uint32_t nAvgBytesPerSec = 88200;
	fwrite(&nAvgBytesPerSec, 4, 1, f);

	uint16_t nBlockAlign = 2;
	fwrite(&nBlockAlign, 2, 1, f);

	uint16_t wBitsPerSample = 16;
	fwrite(&wBitsPerSample, 2, 1, f);

	fwrite("data", 1, 4, f); 

	fwrite(&datasize, 4, 1, f);

	fwrite(audiodata, 1, datasize, f);

	return;
}
