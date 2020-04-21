#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "comm.h"
#include "sound.h"

int main(void) {
	Position p = getscreensize();
	if(p.col<BARS){
		printf("Your screen size is not wide enough\n");
		return 1;
	}
	FILE *fp = fopen("test.wav", "r");
	WAVheader h = readwavhdr(fp);
	displaywavhdr(h);
	getchar();
	clearscreen();
	wavdata(h, fp);
	fclose(fp);
	getchar();
}
