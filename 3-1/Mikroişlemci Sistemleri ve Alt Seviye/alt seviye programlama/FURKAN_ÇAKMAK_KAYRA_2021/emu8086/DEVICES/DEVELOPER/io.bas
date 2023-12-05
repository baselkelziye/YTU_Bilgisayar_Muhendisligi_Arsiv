Attribute VB_Name = "io"
' this module can be used to implement your own external devices
' for emu8086 - 8086 microprocessor emulator.
' device can be written in visual basic
' for c/c++/ms visual c++ use io.h for c# use io.cs

' supported input / output addresses:
'                  0 to 65535 (&H0 - &HFFFF)

' most recent version of emu8086 is required,
' check this url for the latest version:
'            http://www.emu8086.com

' you don't need to understand the code of this
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
' where:
'  lPORT_NUM - is a number in range: from 0 to 65535.
'  uValue    - unsigned byte value to be written to a port.
'  iValue    - signed word value to be written to a port.






Option Explicit

Const sIO_FILE = "C:\emu8086.io"

Function READ_IO_BYTE(lPORT_NUM As Long) As Byte
On Error GoTo err_rib

Dim sFileName As String
Dim tb As Byte
Dim fNum As Integer

sFileName = sIO_FILE

fNum = FreeFile

Open sFileName For Random Shared As fNum Len = 1

' File's first byte has Index 1 in VB
' compatibility for Port 0:
Get fNum, lPORT_NUM + 1, tb

Close fNum


READ_IO_BYTE = tb


Exit Function
err_rib:
Debug.Print "READ_IO_BYTE: " & Err.Description
Close fNum

End Function

Sub WRITE_IO_BYTE(lPORT_NUM As Long, uValue As Byte)
On Error GoTo err_wib

Dim sFileName As String
Dim fNum As Integer

sFileName = sIO_FILE

fNum = FreeFile


Open sFileName For Random Shared As fNum Len = 1

' File's first byte has Index 1 in VB
' compatibility for Port 0:
Put fNum, lPORT_NUM + 1, uValue

Close fNum

Exit Sub
err_wib:
Debug.Print "WRITE_IO_BYTE: " & Err.Description
Close fNum
End Sub


Function READ_IO_WORD(lPORT_NUM As Long) As Integer
Dim tb1 As Byte
Dim tb2 As Byte

    ' Read lower byte:
    tb1 = READ_IO_BYTE(lPORT_NUM)
    ' Write higher byte:
    tb2 = READ_IO_BYTE(lPORT_NUM + 1)

    READ_IO_WORD = make16bit_SIGNED_WORD(tb1, tb2)
End Function


Sub WRITE_IO_WORD(lPORT_NUM As Long, iValue As Integer)
Dim tb1 As Byte
Dim tb2 As Byte

   ' Write lower byte:
   WRITE_IO_BYTE lPORT_NUM, iValue And 255 ' 00FF
   ' Write higher byte:
   WRITE_IO_BYTE lPORT_NUM + 1, (iValue And 65280) / 256 ' FF00 >> 8
End Sub

' This function corrects the file path by adding "\"
' in the end if required:
Function AddTrailingSlash(sPath As String) As String
  
    If (sPath <> "") Then
        If (Mid(sPath, Len(sPath), 1) <> "\") Then
          AddTrailingSlash = sPath & "\"
          Exit Function
        End If
    End If
  
    AddTrailingSlash = sPath
  
End Function

Function make16bit_SIGNED_WORD(ByRef byteL As Byte, ByRef byteH As Byte) As Integer
    Dim temp As Long
    
    ' lower byte - on lower address!
    ' byte1 - lower byte!
    
    temp = byteH
    temp = temp * 256 ' shift left by 8 bit.
    temp = temp + byteL
    
    
    make16bit_SIGNED_WORD = make_signed_int(temp)
End Function

' Makes a Long to be a SIGNED Integer:
 Function make_signed_int(l As Long) As Integer
    If l >= -32768 And l < 65536 Then
        If l <= 32767 Then
            make_signed_int = l
        Else
            make_signed_int = l - 65536
        End If
    Else
        make_signed_int = 0
        Debug.Print "wrong param calling make_signed_int(): " & l
    End If
End Function
