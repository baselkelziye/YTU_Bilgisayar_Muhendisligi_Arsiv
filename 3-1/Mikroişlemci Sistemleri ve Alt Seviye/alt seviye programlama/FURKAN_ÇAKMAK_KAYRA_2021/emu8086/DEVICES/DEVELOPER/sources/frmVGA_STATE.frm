VERSION 5.00
Begin VB.Form frmVGA_STATE 
   BorderStyle     =   5  'Sizable ToolWindow
   Caption         =   "VGA STATE"
   ClientHeight    =   195
   ClientLeft      =   60
   ClientTop       =   300
   ClientWidth     =   1605
   Icon            =   "frmVGA_STATE.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   MinButton       =   0   'False
   ScaleHeight     =   195
   ScaleWidth      =   1605
   ShowInTaskbar   =   0   'False
   Begin VB.Timer Timer1 
      Interval        =   1000
      Left            =   1110
      Top             =   30
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "EMULATION"
      BeginProperty Font 
         Name            =   "Small Fonts"
         Size            =   6.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   165
      Left            =   60
      TabIndex        =   0
      Top             =   0
      Width           =   825
   End
End
Attribute VB_Name = "frmVGA_STATE"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
' #400b10-VGA#

' pass through...
' play:   mov     dx,03dah
' lb1:    in      al,dx
'        test    al,8
'        jnz     lb1
' lb2:    in      al,dx
'        test    al,8
'        jz      lb2

Option Explicit

Dim bFLAG As Boolean

Private Sub Timer1_Timer()
On Error GoTo ERR1

    If bFLAG Then
        io.WRITE_IO_BYTE 986, 255 ' 03dah = 986
    Else
        io.WRITE_IO_BYTE 986, 0 ' 03dah = 986
    End If
    
    bFLAG = Not bFLAG

    Exit Sub
ERR1:
    Debug.Print "Timer1_Timer: " & Err.Description
End Sub
