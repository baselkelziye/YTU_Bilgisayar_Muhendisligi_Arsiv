VERSION 5.00
Begin VB.Form frmSimple 
   BorderStyle     =   1  'Fixed Single
   Caption         =   "simple io test"
   ClientHeight    =   2475
   ClientLeft      =   90
   ClientTop       =   375
   ClientWidth     =   4050
   Icon            =   "frmSimple.frx":0000
   LinkTopic       =   "Form1"
   LockControls    =   -1  'True
   MaxButton       =   0   'False
   ScaleHeight     =   2475
   ScaleWidth      =   4050
   Begin VB.TextBox txtIN_W117 
      Enabled         =   0   'False
      BeginProperty Font 
         Name            =   "Fixedsys"
         Size            =   9
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   330
      Left            =   2640
      TabIndex        =   3
      Top             =   2070
      Width           =   1320
   End
   Begin VB.TextBox txtOUT_B110 
      BackColor       =   &H00FFFFFF&
      BeginProperty Font 
         Name            =   "Fixedsys"
         Size            =   9
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000000&
      Height          =   330
      Left            =   2895
      TabIndex        =   0
      Top             =   330
      Width           =   1065
   End
   Begin VB.TextBox txtOUT_W112 
      BackColor       =   &H00FFFFFF&
      BeginProperty Font 
         Name            =   "Fixedsys"
         Size            =   9
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000000&
      Height          =   330
      Left            =   2895
      TabIndex        =   1
      Top             =   810
      Width           =   1065
   End
   Begin VB.TextBox txtIN_B115 
      Enabled         =   0   'False
      BeginProperty Font 
         Name            =   "Fixedsys"
         Size            =   9
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   330
      Left            =   2640
      TabIndex        =   2
      Top             =   1650
      Width           =   1320
   End
   Begin VB.Timer Timer1 
      Interval        =   100
      Left            =   3525
      Top             =   1185
   End
   Begin VB.Label Label7 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      Caption         =   "for hexadecimal digits add h suffix"
      BeginProperty Font 
         Name            =   "Verdana"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   -1  'True
         Strikethrough   =   0   'False
      EndProperty
      Height          =   195
      Left            =   390
      TabIndex        =   9
      Top             =   30
      Width           =   2970
   End
   Begin VB.Label Label5 
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      BorderStyle     =   1  'Fixed Single
      Caption         =   " updating input ports every 100 milliseconds "
      ForeColor       =   &H80000008&
      Height          =   225
      Left            =   165
      TabIndex        =   8
      Top             =   1275
      Width           =   3150
   End
   Begin VB.Label Label4 
      AutoSize        =   -1  'True
      Caption         =   "read word from port 112:"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   195
      Left            =   165
      TabIndex        =   7
      Top             =   2138
      Width           =   2100
   End
   Begin VB.Label Label3 
      AutoSize        =   -1  'True
      Caption         =   "write byte to port 110: "
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   195
      Left            =   165
      TabIndex        =   6
      Top             =   398
      Width           =   1950
   End
   Begin VB.Label Label2 
      AutoSize        =   -1  'True
      Caption         =   "write word to port 112: "
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   195
      Left            =   165
      TabIndex        =   5
      Top             =   878
      Width           =   1995
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "read byte from port 110:"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   195
      Left            =   165
      TabIndex        =   4
      Top             =   1718
      Width           =   2055
   End
End
Attribute VB_Name = "frmSimple"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Private Sub Form_Load()
    ' do not allow more than one copy of this program to run simuateniously
    If App.PrevInstance Then

        ShowPrevInstance

        End   ' terminate this instance!

    End If
    
    GetWindowPos Me
    
    If allow_on_top() Then set_on_top Me
    
End Sub

Private Sub Form_Unload(Cancel As Integer)
    SaveWindowState Me
End Sub

Private Sub Timer1_Timer()

    ' Read UNSIGNED BYTE from port 110:
    txtIN_B115.Text = Hex(READ_IO_BYTE(110)) & "h"
    
    ' Read SIGNED WORD from port 112:
    txtIN_W117.Text = Hex(READ_IO_WORD(112)) & "h"
    
End Sub



Private Sub txtOUT_B110_Change()
On Error GoTo err1:
   Dim tb As Byte
   Dim s As String
   
   If Val(txtOUT_B110.Text) > 255 Then
        txtOUT_B110.ForeColor = vbRed
   Else
        txtOUT_B110.ForeColor = vbBlack
   End If
   
   s = txtOUT_B110.Text
   
   If UCase(Right(s, 1)) = "H" Then
        s = "&H" & s
   End If
   
   If UCase(Left(s, 2)) = "0X" Then
      s = Mid(s, 3)
      s = "&H" & s
   End If
   
   tb = Val("&h" & Right((Hex(Val(s))), 2))

   WRITE_IO_BYTE 110, tb
   
   Exit Sub
err1:
   MsgBox Err.Description & ": " & txtOUT_B110.Text
   txtOUT_B110.Text = ""
End Sub

Private Sub txtOUT_B110_KeyPress(KeyAscii As Integer)
    If KeyAscii = 13 Then
        KeyAscii = 0
        txtOUT_B110_Change
    End If
End Sub

Private Sub txtOUT_W112_Change()
On Error GoTo err1:
   Dim ti As Integer
   
   
   If Val(txtOUT_W112.Text) > 65535 Then
        txtOUT_W112.ForeColor = vbRed
   Else
        txtOUT_W112.ForeColor = vbBlack
   End If
   
   Dim s As String
   
   s = txtOUT_W112.Text
   
   If UCase(Right(s, 1)) = "H" Then
        s = "&H" & s
   End If
   
   If UCase(Left(s, 2)) = "0X" Then
      s = Mid(s, 3)
      s = "&H" & s
   End If
      
   
   ti = Val("&h" & Right(Hex(Val(s)), 4))

   WRITE_IO_WORD 112, ti
   
   Exit Sub
err1:
   MsgBox Err.Description & ": " & txtOUT_W112.Text
   txtOUT_W112.Text = ""
End Sub


Private Sub txtOUT_W112_KeyPress(KeyAscii As Integer)
    If KeyAscii = 13 Then
        KeyAscii = 0
        txtOUT_W112_Change
    End If
End Sub

' activate window when there is new data in port
Private Sub txtIN_B115_Change()
On Error Resume Next
    If shall_activate(Me) Then Me.Show
End Sub

' activate window when there is new data in port
Private Sub txtIN_W117_Change()
On Error Resume Next
    If shall_activate(Me) Then Me.Show
End Sub

