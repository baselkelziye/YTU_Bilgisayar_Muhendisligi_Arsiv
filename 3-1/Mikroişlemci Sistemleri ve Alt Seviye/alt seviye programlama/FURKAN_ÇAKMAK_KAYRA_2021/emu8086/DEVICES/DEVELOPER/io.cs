#region Introduction
/*
 this class can be used to implement your own external devices for
 emu8086 - 8086 microprocessor emulator. device can be written in visual c#

 supported input / output addresses:
                  0 to 65535 (0x0 - 0xFFFF)

 most recent version of emu8086 is required,
 check this url for the latest version:
 http://www.emu8086.com

 you don't need to understand the code of this
 module, just include this file ("io.cs") into your
 project, and use these functions:

	public static System.Byte READ_IO_BYTE(long lPORT_NUM) 
	public static int READ_IO_WORD(long lPORT_NUM) 

	public static void WRITE_IO_BYTE(long lPORT_NUM, System.Byte uValue) 
	public static void WRITE_IO_WORD(long lPORT_NUM, System.Int16 iValue) 

 where:
  lPORT_NUM - is a number in range: from 0 to 65535.
  uValue    - unsigned byte value to be written to a port.
  iValue    - signed word value to be written to a port.

 This class is written by deTrox Yang. If you have any suggestion 
 please send email to detrox@gmail.com.
 
 Thanks
*/
#endregion
using System;
using System.Text;
using System.IO;
using System.Runtime.InteropServices;

namespace Emu8086
{
	/// <summary>
	/// I/O Device class for Emu8086 
	/// </summary>
	public class IO
	{
		private const string sIO_FILE = "C:\emu8086.io";
		
		private IO()
		{
		}
		
		public static System.Byte READ_IO_BYTE(long lPORT_NUM) 
		{
			StringBuilder sTempDir = new StringBuilder(500);
			string sFilename = null;		
			sFilename = sIO_FILE;
			FileStream rdr = new FileStream(sFilename, FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
			rdr.Seek(lPORT_NUM, SeekOrigin.Begin);
			int ch = rdr.ReadByte();
			rdr.Close();
			return (System.Byte)ch;
		}

		public static int READ_IO_WORD(long lPORT_NUM) 
		{
			Int16 ti;
			System.Byte tb1;
			System.Byte tb2;

			tb1 = READ_IO_BYTE(lPORT_NUM);
			tb2 = READ_IO_BYTE(lPORT_NUM + 1);
			// Convert 2 bytes to a 16 bit word:
			ti = (Int16)(tb2 * 256 + tb1);
			
			return ti;
		}

		public static void WRITE_IO_BYTE(long lPORT_NUM, System.Byte uValue) 
		{
			StringBuilder sTempDir = new StringBuilder(500);
			string sFilename = null;
			sFilename = sIO_FILE;
			FileStream rdr = new FileStream(sFilename, FileMode.Open, FileAccess.Write, FileShare.ReadWrite);
			rdr.Seek(lPORT_NUM, SeekOrigin.Begin);
			rdr.WriteByte(uValue);
			rdr.Close();
		}
		
		public static void WRITE_IO_WORD(long lPORT_NUM, System.Int16 iValue) 
		{
			WRITE_IO_BYTE (lPORT_NUM, (Byte)(iValue & 0x00FF));
			WRITE_IO_BYTE (lPORT_NUM + 1, (Byte) ((iValue & 0xFF00) / 256));
		}

	}
}