// Usually in a header file, following information are included
// 1. function declarations
// 2. constant definitions
// 3. conditional compilation

//constant definitions
#define ESC 0x1B
#define UNICODE 	// for conditional compilation
#define BAR "\u2590"

#define DEBUG		// for conditional compilation
typedef struct {		// this struct will define a compound data, which 
	int row;			// consists of the number of rows and the number of columns of our screen
	int col;
} Position;

//#define BLACK 30, instead of using #define, it's better to use enumeration
enum FG{BLACK=30, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};
#define bg(c) (c+10) // macro definition

// function declarations
void clearscreen(void);
void setfgcolor(int);
void setbgcolor(int);
void setcolors(int, int);
void resetcolors(void);
void gotoXY(int, int);
void drawbar(int, int);
void drawrect(int, int, int, int);
Position getscreensize(void);
