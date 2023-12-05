{ this header file can be used to implement your own external devices for
 emu8086 - 8086 microprocessor emulator.
 
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
}


unit io;

interface
uses
  Classes,SysUtils;

  const sIO_FILE='C:\emu8086.io';
  function READ_IO_BYTE(lPORT_NUM:Word):Byte;
  function READ_IO_WORD(lPORT_NUM:Word):Word;
  procedure WRITE_IO_BYTE(lPORT_NUM:Word;bValue:Byte);
  procedure WRITE_IO_WORD(lPORT_NUM:Word;iValue:Word);


implementation

function READ_IO_BYTE(lPORT_NUM:Word):Byte;
var
  fp: Integer;
  ch:Byte;
begin
  fp:=FileOpen(sIO_FILE,fmOpenReadWrite);
  FileSeek(fp, lPORT_NUM, 0);
  FileRead(fp,ch,1);
  FileClose(fp);
  Result:=ch;
end;

function READ_IO_WORD(lPORT_NUM:Word):Word;
var
  tb1,tb2:Byte;
  ti:Word;
begin
  tb1 := READ_IO_BYTE(lPORT_NUM);
	tb2 := READ_IO_BYTE(lPORT_NUM + 1);
  ti := tb2;
  ti := ti shl 8;
  ti := ti + tb1;
  Result := ti;
end;

  procedure WRITE_IO_BYTE(lPORT_NUM:Word;bValue:Byte);
var
  fp: Integer;
  ch:Byte;
begin
  ch:= bValue;
  fp:=FileOpen(sIO_FILE,fmOpenReadWrite);
  FileSeek(fp, lPORT_NUM, 0);
  FileWrite(fp,ch,1);
  FileClose(fp);
end;

procedure WRITE_IO_WORD(lPORT_NUM:Word;iValue:Word);  
begin
	WRITE_IO_BYTE (lPORT_NUM, iValue AND $00FF);
	WRITE_IO_BYTE (lPORT_NUM + 1, (iValue and $FF00) shr 8);
end;

end.
