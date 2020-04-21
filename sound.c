#include <stdio.h>
#include "sound.h"
#include <math.h>
#include "screen.h"

// function definitions

WAVheader readwavhdr(FILE *fp) {
	WAVheader myh;
	fread(&myh, sizeof(myh), 1, fp);
	return myh;
}

void displaywavhdr(WAVheader h) {
	for (int i=0; i<4; i++)
		printf("%c", h.chunkID[i]);
	printf("\n");
	printf("Chunk size: %d\n", h.chunkSize);
	printf("Number of channels: %d\n", h.numChannels);
	printf("Sample rate: %d\n", h.sampleRate);
	printf("Bits per sample: %d\n", h.bitsPerSample);	
// -- to be continued
	double duration;
	duration =(double) h.subchunk2Size/h.byteRate;
	printf("Duration: %lf seconds\n", duration);
}

void wavdata(WAVheader h, FILE *fp){
	short samples[SIZE];
	int peaks = 0;
	int flags = 0;
	for(int i=0; i<BARS; i++){
		fread(samples, sizeof(samples), 1, fp);
		double sum = 0;
		for(int k=0; k<SIZE; k++){
			sum = sum + samples[k]*samples[k];
		} 
		//double dB = sqrt(sum/2000);
		double dB = 20*log10(sqrt(sum/SIZE));
#ifdef SDEBUG
		printf("dB[%d] = %f\n", i, dB);
#else
		if(dB>65) 
		{
			setfgcolor(RED);
			if (flags == 0) 
			{
				peaks ++; flags = 1;
			}
		}
		else 
		{
			setfgcolor(WHITE);
			if (flags == 1) flags = 0;
		} 
		drawbar(i+1, (int)dB/3);
		gotoXY(1,1);
		setfgcolor(CYAN);
		printf("Sample rate:%d\n", SAMPLERATE);
		gotoXY(1, 75);
		setfgcolor(MAGENTA);
		printf("Duration: %.1fs\n",(double)h.subchunk2Size/h.byteRate);
		gotoXY(1, 150);
		setfgcolor(YELLOW);
		printf("Peaks: %d\n", peaks);
#endif
	}
}
