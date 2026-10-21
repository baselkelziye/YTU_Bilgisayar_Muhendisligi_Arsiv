#ifndef _GRAPH_H_
#define _GRAPH_H_

#define __STR(str) #str

#define __CLRRIGHT		__STR(\33[0K) 	//clears the line from cursor to end
#define __CLRLEFT		__STR(\33[1K) 	//clears the line from cursor to head
#define __CLRLINE		__STR(\33[2K\r) //clears whole line , cursor returned to head
#define __CURUP			__STR(\033[A)	//moves up the cursor 1 line
#define __CURDOWN		__STR(\033[B)	//moves down the cursor 1 line

#define __RESET 		__STR(\33[0m)	// resets attributes
#define __BRIGHT 		__STR(\33[1m)	// brightens up the text
#define __DIM 			__STR(\33[2m)	// dims up the text
#define __UNDERSCORE	__STR(\33[4m)	// underscores the text
#define __BLINK 		__STR(\33[5m)	// turns on blinks
#define __REVERSE 		__STR(\33[7m)	// reverses color
#define __INVISCUR 		__STR(\33[?25l)	// makes cursor invisible
#define __VISCUR 		__STR(\33[?25h)	// makes cursor visible 	


//-------COLOR CODES---------//
#define _C_BLACK 		__STR(\33[30m)	
#define _C_RED 			__STR(\33[31m) 	
#define _C_GREEN 		__STR(\33[32m)
#define _C_YELLOW 		__STR(\33[33m)
#define _C_BLUE 		__STR(\33[34m) 
#define _C_MAGENTA 		__STR(\33[35m)
#define _C_CYAN 		__STR(\33[36m) 
#define _C_WHITE 		__STR(\33[37m) 
#define _C_DEFAULT 		__STR(\33[39m) 

#define _B_BLACK	__STR(\33[40m)
#define _B_RED		__STR(\33[41m)
#define _B_GREEN	__STR(\33[42m)
#define _B_YELLOW	__STR(\33[43m)
#define _B_BLUE		__STR(\33[44m)
#define _B_MAGENTA	__STR(\33[45m)
#define _B_CYAN		__STR(\33[46m)
#define _B_WHITE	__STR(\33[47m)
#define _B_DEFAULT	__STR(\33[49m)

#endif

