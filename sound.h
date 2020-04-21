// this header file contains constant definition and function declaration
// for processing sound, specifically .wav files.
//#define SDEBUG
#define SAMPLERATE 16000
#define BARS 160
#define SIZE 500

typedef struct {
	char chunkID[4];		// should be always "RIFF"
	int chunkSize;			// indicates how big sound data is
	char format[4];			// should be always "WAVE"
	char subchunk1ID[4];	// should be always "fmt "
	int subchunk1Size;		// Should be 16 for PCM data
	short audioFormat;		// should be 1 for Linear samples
	short numChannels;		// 1 for mono and 2 for stereo
	int sampleRate;			// could be 44100, 16000, 8000,...
	int byteRate;			// can be calculated
	short blockAlign;		//  how many bytes in one block
	short bitsPerSample;	// how many bits in one sample
	char subchunk2TD[4];	// should be always "data"
	int subchunk2Size;		// how many bytes exactly for data part
}WAVheader;

// function declarations
WAVheader readwavhdr(FILE *);
void displaywavhdr(WAVheader);
void wavdata(WAVheader, FILE *);
