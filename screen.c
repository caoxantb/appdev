// This file contains function to manipulate screens, such as foreground
// color, background color, clearscreen, restore default settings, etc.
// To enable screen manipulations, we need to use VT100 escape sequences
// see the link: http://www.termsys.demon.co.uk/vtansi.htm
// move between files: alt + . (forward), alt + , (backward)

#include <stdio.h> // for printf() function
#include "screen.h" // contains constants used in this program
#include <string.h>

// function definitions
// a function name is an identifier in C, an identifier  should start
// with a letter or an underscore, and follow by letters, digits, underscores
void setfgcolor (int fg){
	printf("%c[1;%dm", ESC, fg); 
}

void setbgcolor(int bg){
	printf("%c[1;%dm", ESC, bg);
}

void setcolors (int fg, int bg){
	setfgcolor(fg);
	setbgcolor(bg);
}

void clearscreen(void){
	printf("%c[2J", ESC);
}

void resetcolors(void){
	printf("%c[0m", ESC);
}

void gotoXY(int row, int col){
	printf("%c[%d;%dH", ESC, row, col);
}

void drawbar (int col, int height){
	int i;
	for(i = 1 ; i < height; i++){
		gotoXY(i, col);
#ifdef UNICODE
		printf("%s", BAR);
#else
		printf("%c", '#');
#endif
	}
}

void drawrect(int row, int col, int height, int width){
	int i, j; 
	for (i=row; i<row+height; i++) {
		for (j=col; j<col+width; j++) {
			gotoXY(i, j);
#ifdef UNICODE
			printf("%s", BAR);
#else
			printf("%c", '#');
#endif
		}
		printf("\n");
	}
}


Position getscreensize(void){
	// in this function we use terminal query function to 
	// query cursor position, the terminal should return a 
	// string back to the program if a query string
	// "ESC[6n" is issued to the terminal
	Position p; 
	int r, c;	//for decoding the report string 
	char ret[100] =  "\0";	//an empty string to get report
	gotoXY(999, 999);	//force the cursor to the bottom
						//right corner
	printf("%c[6n", ESC);
	scanf("%s", ret);	//we get report from the terminal
#ifdef DEBUG
	printf("%s\n", ret);
#endif
	// we will decode the return string
	if(strlen(ret)>0){
		char dum;
		sscanf(ret, "%c%c%d%c%d%c",&dum, &dum, &r, &dum, &c, &dum);
		p.row = r;
		p.col = c;
	} 
	else {
		p.row = 0;
		p.col = 0;
	}
	return p;
}
