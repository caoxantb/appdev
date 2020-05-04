#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "comm.h"
#include "sound.h"

int main(void) {
	Position cur = getscreensize(); // get screen size
	char postdata[100];
	sprintf(postdata, "row=%d&col=%d&id=e1900304", cur.row, cur.col);
	printf("\n%s\n", postdata);
	sendpost(URL, postdata);
	gotoXY(1, 1);
	printf("Screen size: row =%d, col =%d\n", cur.row, cur.col);

	printf("Today we will make some animations. Press any key to continue\n");
	getchar();	// wait for the user to press a key
	getchar();
	int ff, bb;
	float step = (float)cur.col/cur.row;
	for (int i=1; i<=cur.row; i++) {
		ff = (i+1)%8+BLACK;
		bb = (i+2)%8+BLACK;
		setcolors(ff, bg(bb));
		clearscreen();
		drawrect(10, 10, 5, 30);
		gotoXY(cur.row-i,(i-1)*step+1);
		setfgcolor(GREEN);
		printf("HELLO\n");
		usleep(500000);	//sleep(1);
	}
/*	for (int i=1; i<21; i++) {
		bb =(i+2)%8+BLACK;
		setfgcolor(RED);
		setbgcolor(bg(bb));
		clearscreen();
		drawrect(20-i,(i-1)*2+41, 2, 4);
		gotoXY(i+1,(i-1)*2+41);
		setfgcolor(GREEN);
		printf("HELLO\n");
		sleep(1);
	} */
	resetcolors();
	clearscreen();
	printf("color is set back to default\n");
	getchar();
	FILE *fp = fopen("test.wav", "r");
	WAVheader h =readwavhdr(fp);
	fclose(fp);
	displaywavhdr(h);
	/*
	setfgcolor(GREEN);
	gotoXY(14, 35);
	printf("Hello, world!\n");
	getchar();	// wait for user to press a key
	drawbar(30, 30);
	drawbar(50, 30);
	getchar();	// after drawing bars, wait for an input
	resetcolors();
	printf("This text is displayed in default color\n");
*/
}
