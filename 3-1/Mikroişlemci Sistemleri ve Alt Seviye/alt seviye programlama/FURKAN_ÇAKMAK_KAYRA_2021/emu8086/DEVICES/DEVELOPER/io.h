/*
 this header file can be used to implement your own external devices for
 emu8086 - 8086 microprocessor emulator.
 devices can be written in borland turbo c, visual c++
 (for visual basic use io.bas instead).

 supported input / output addresses:
                  0 to 65535 (0x0 - 0xFFFF)

 most recent version of emu8086 is required,
 check this url for the latest version:
 http://www.emu8086.com

 you don't need to understand the code of this
 module, just include this file (io.h) into your
 project, and use these functions:

    unsigned char READ_IO_BYTE(long lPORT_NUM)
    short int READ_IO_WORD(long lPORT_NUM)

    void WRITE_IO_BYTE(long lPORT_NUM, unsigned char uValue)
    void WRITE_IO_WORD(long lPORT_NUM, short int iValue)

 where:
  lPORT_NUM - is a number in range: from 0 to 65535.
  uValue    - unsigned byte value to be written to a port.
  iValue    - signed word value to be written to a port.
*/

const char sIO_FILE[] = "C:\emu8086.io";

unsigned char READ_IO_BYTE(long lPORT_NUM)
{
	unsigned char tb;

	char buf[500];
	unsigned int ch;

	strcpy(buf, sIO_FILE);

	FILE *fp;

	fp = fopen(buf,"r+");

	// Read byte from port:
	fseek(fp, lPORT_NUM, SEEK_SET);
    ch = fgetc(fp);

	fclose(fp);

	tb = ch;

	return tb;
}

short int READ_IO_WORD(long lPORT_NUM)
{
	short int ti;
	unsigned char tb1;
	unsigned char tb2;

	tb1 = READ_IO_BYTE(lPORT_NUM);
	tb2 = READ_IO_BYTE(lPORT_NUM + 1);

	// Convert 2 bytes to a 16 bit word:
	ti = tb2;
    ti = ti << 8;
	ti = ti + tb1;

	return ti;
}

void WRITE_IO_BYTE(long lPORT_NUM, unsigned char uValue)
{
	char buf[500];
	unsigned int ch;

	strcpy(buf, sIO_FILE);

	FILE *fp;

	fp = fopen(buf,"r+");

    ch = uValue;

	// Write byte to port:
	fseek(fp, lPORT_NUM, SEEK_SET);
	fputc(ch, fp);

	fclose(fp);
}

void WRITE_IO_WORD(long lPORT_NUM, short int iValue)
{
	WRITE_IO_BYTE (lPORT_NUM, iValue & 0x00FF);
	WRITE_IO_BYTE (lPORT_NUM + 1, (iValue & 0xFF00) >> 8);
}
