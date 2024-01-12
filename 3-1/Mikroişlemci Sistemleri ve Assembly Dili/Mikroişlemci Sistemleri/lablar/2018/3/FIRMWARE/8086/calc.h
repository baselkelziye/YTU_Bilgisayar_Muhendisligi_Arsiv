/******************************************************************************
************                 LABCENTER ELECTRONICS                  ************                              
************		     Proteus VSM Sample Design Code             ************		 	
************	       Integer Calculator ( 2K Code Limit)	        ************
********************************************************************************/

typedef void VOID;
typedef int  INT;
typedef unsigned short WORD;
typedef char CHAR;
typedef unsigned char BYTE;
typedef float FLOAT;
typedef double DOUBLE;
typedef long LONG;

// Define the maximum number of ASCII characters that can fit
// on the display.
#define MAX_DISPLAY_CHAR 9

//Error handling status.
enum ERROR { OK = 0, SLEEP = 1, ERROR = 2};

/************************************************************************
***** FUNCTION PROTOTYPES *****
******************************/

VOID calc_evaluate();

//Operator indirect function.
VOID calc_opfunctions (CHAR token);

//Utility functions.
CHAR  calc_testkey  (CHAR ch);
LONG  calc_asciidec (CHAR *buffer);
CHAR *calc_decascii (LONG num);
INT   calc_chkerror (LONG num);
VOID  calc_output   (INT status);

// I/O functions.
CHAR calc_getkey (VOID);
VOID calc_display (CHAR buf[MAX_DISPLAY_CHAR]);

//Assembly Function prototypes.
void initialise();
char input ();
char output(char ch);
void clearscreen(); 







