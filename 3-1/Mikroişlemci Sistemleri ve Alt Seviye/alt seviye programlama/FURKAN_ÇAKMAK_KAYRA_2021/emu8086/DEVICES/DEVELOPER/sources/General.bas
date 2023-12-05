Attribute VB_Name = "General"
Option Explicit

' Declarations to avoid duplicate instances of printer running:
Declare Function FindWindow Lib "user32" Alias "FindWindowA" (ByVal lpClassName As String, ByVal lpWindowName As String) As Long
Declare Function GetWindow Lib "user32" (ByVal hWnd As Long, ByVal wCmd As Long) As Long
Declare Function OpenIcon Lib "user32" (ByVal hWnd As Long) As Long
Declare Function SetForegroundWindow Lib "user32" (ByVal hWnd As Long) As Long
Public Const GW_HWNDPREV = 3

' bells and whistles
Public Declare Function Beep Lib "kernel32" (ByVal dwFreq As Long, ByVal dwDuration As Long) As Long

