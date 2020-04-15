#define ESC 0x1B
enum FG{BLACK=30,RED,GREEN,YELLOW,BLUE,MAGENTA,CYAN,WHITE};
#define bg(c) (c+10)	//this is called macro definition 
#define UNICODE 
#define BAR "\u2590"
#define RECT "\u2584"
//#define DEBUG // for conditional compilation 
typedef struct{
	int row; //this struct will define a compound data, which consists of
	int col; //the number of rows and the number of columns of our screen
}Position;

void clearscreen(void);
void setfgcolor(int);
void setbgcolor(int);
void setcolors (int, int);
void resetcolors(void);
void gotoXY(int, int);
void drawbar(int, int);
void drawrect(int, int, int, int);
Position getscreensize(void);
