Option Strict Off
Option Explicit On
Module io
	' this module can be used to implement
	' your own external devices for emu8086 -
	' 8086 microprocessor emulator.
    ' devices can be written in 
    ' visual basic 6.0 (use io.bas)
    ' visual basic .net (use io.vb)
    ' c/c++/ms visual c++ (use io.h)

	' supported input / output addresses:
	'                  0 to 65535 (&H0 - &HFFFF)
	
	' most recent version of emu8086 is required,
	' check this url for an update:
	' http://www.emu8086.com
	
	' You don't need to understand the code of this
	' module, just add this file ("io.bas") into your
	' project, and use these functions:
	'
	'    READ_IO_BYTE(lPORT_NUM As Long) As Byte
	'    READ_IO_WORD(lPORT_NUM As Long) As Integer
	'
	' and subs:
	'
	'    WRITE_IO_BYTE(lPORT_NUM As Long, uValue As Byte)
	'    WRITE_IO_WORD(lPORT_NUM As Long, iValue As Integer)
	'
	' Where:
	'  lPORT_NUM - is a number in range: from 0 to 65535.
	'  uValue    - unsigned byte value to be written to a port.
	'  iValue    - signed word value to be written to a port.
	
	
	
	
	Const sIO_FILE As String = "C:\emu8086.io"
	
	Function READ_IO_BYTE(ByRef lPORT_NUM As Integer) As Byte
        'On Error GoTo err_rib
		
		Dim sFileName As String
        Dim tb() As Byte = {0}
		Dim fNum As Short
		
		sFileName = sIO_FILE
		
		fNum = FreeFile
        FileOpen(fNum, sFileName, OpenMode.Random, OpenAccess.ReadWrite, OpenShare.Shared, 1)

		' File's first byte has Index 1 in VB
		' compatibility for Port 0:
        FileGet(fNum, tb, lPORT_NUM + 1)

		FileClose(fNum)
		
		
        READ_IO_BYTE = tb(0)
		
		
		Exit Function
err_rib: 
		System.Diagnostics.Debug.WriteLine("READ_IO_BYTE: " & Err.Description)
		FileClose(fNum)
		
	End Function
	
	Sub WRITE_IO_BYTE(ByRef lPORT_NUM As Integer, ByRef uValue As Byte)
        'On Error GoTo err_wib
		
		Dim sFileName As String
        Dim fNum As Short
        Dim tb() As Byte = {0}
		
		sFileName = sIO_FILE
		
		fNum = FreeFile
		
		
        FileOpen(fNum, sFileName, OpenMode.Random, OpenAccess.ReadWrite, OpenShare.Shared, 1)
		
		' File's first byte has Index 1 in VB
		' compatibility for Port 0:
        tb(0) = uValue
        FilePut(fNum, tb, lPORT_NUM + 1)
		
		FileClose(fNum)
		
		Exit Sub
err_wib: 
		System.Diagnostics.Debug.WriteLine("WRITE_IO_BYTE: " & Err.Description)
		FileClose(fNum)
	End Sub
	
	
	Function READ_IO_WORD(ByRef lPORT_NUM As Integer) As Short
		Dim tb1 As Byte
		Dim tb2 As Byte
		
		' Read lower byte:
		tb1 = READ_IO_BYTE(lPORT_NUM)
		' Write higher byte:
		tb2 = READ_IO_BYTE(lPORT_NUM + 1)
		
		READ_IO_WORD = make16bit_SIGNED_WORD(tb1, tb2)
	End Function
	
	
	Sub WRITE_IO_WORD(ByRef lPORT_NUM As Integer, ByRef iValue As Short)
		Dim tb1 As Byte
		Dim tb2 As Byte
		
		' Write lower byte:
		WRITE_IO_BYTE(lPORT_NUM, iValue And 255) ' 00FF
		' Write higher byte:
		WRITE_IO_BYTE(lPORT_NUM + 1, CShort(iValue And 65280) / 256) ' FF00 >> 8
	End Sub
	
	' This function corrects the file path by adding "\"
	' in the end if required:
	Function AddTrailingSlash(ByRef sPath As String) As String
		
		If (sPath <> "") Then
			If (Mid(sPath, Len(sPath), 1) <> "\") Then
				AddTrailingSlash = sPath & "\"
				Exit Function
			End If
		End If
		
		AddTrailingSlash = sPath
		
	End Function
	
	Function make16bit_SIGNED_WORD(ByRef byteL As Byte, ByRef byteH As Byte) As Short
		Dim temp As Integer
		
		' lower byte - on lower address!
		' byte1 - lower byte!
		
		temp = byteH
		temp = temp * 256 ' shift left by 8 bit.
		temp = temp + byteL
		
		
		make16bit_SIGNED_WORD = make_signed_int(temp)
	End Function
	
	' Makes a Long to be a SIGNED Integer:
	Function make_signed_int(ByRef l As Integer) As Short
		If l >= -32768 And l < 65536 Then
			If l <= 32767 Then
				make_signed_int = l
			Else
				make_signed_int = l - 65536
			End If
		Else
			make_signed_int = 0
			MsgBox("Wrong param calling make_signed_int(): " & l)
		End If
	End Function
End Module