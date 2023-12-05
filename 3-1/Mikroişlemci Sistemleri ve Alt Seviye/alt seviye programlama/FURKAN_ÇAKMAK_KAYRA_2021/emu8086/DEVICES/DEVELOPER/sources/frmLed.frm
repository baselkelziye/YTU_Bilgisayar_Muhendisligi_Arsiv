VERSION 5.00
Begin VB.Form frmLed 
   AutoRedraw      =   -1  'True
   BackColor       =   &H00000000&
   BorderStyle     =   1  'Fixed Single
   Caption         =   "LED display"
   ClientHeight    =   1080
   ClientLeft      =   90
   ClientTop       =   375
   ClientWidth     =   2475
   Icon            =   "frmLed.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   1080
   ScaleWidth      =   2475
   Begin VB.Timer Timer1 
      Interval        =   300
      Left            =   570
      Top             =   1590
   End
   Begin VB.Label Label1 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      BackStyle       =   0  'Transparent
      Caption         =   "port 199 (2 bytes)"
      BeginProperty Font 
         Name            =   "Verdana"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00C0C0C0&
      Height          =   195
      Left            =   540
      TabIndex        =   0
      Top             =   615
      Width           =   1560
   End
   Begin VB.Image imgMINUS 
      Height          =   255
      Left            =   315
      Picture         =   "frmLed.frx":0D4A
      Top             =   120
      Visible         =   0   'False
      Width           =   180
   End
   Begin VB.Image d 
      Height          =   255
      Index           =   4
      Left            =   585
      Picture         =   "frmLed.frx":0D88
      Top             =   120
      Width           =   180
   End
   Begin VB.Image d 
      Height          =   255
      Index           =   3
      Left            =   945
      Picture         =   "frmLed.frx":1296
      Top             =   120
      Width           =   180
   End
   Begin VB.Image d 
      Height          =   255
      Index           =   2
      Left            =   1290
      Picture         =   "frmLed.frx":17A4
      Top             =   120
      Width           =   180
   End
   Begin VB.Image d 
      Height          =   255
      Index           =   1
      Left            =   1650
      Picture         =   "frmLed.frx":1CB2
      Top             =   120
      Width           =   180
   End
   Begin VB.Image d 
      Height          =   255
      Index           =   0
      Left            =   2010
      Picture         =   "frmLed.frx":21C0
      Top             =   120
      Width           =   180
   End
   Begin VB.Image dig 
      Height          =   255
      Index           =   9
      Left            =   3390
      Picture         =   "frmLed.frx":26CE
      Top             =   1140
      Visible         =   0   'False
      Width           =   180
   End
   Begin VB.Image dig 
      Height          =   255
      Index           =   8
      Left            =   3060
      Picture         =   "frmLed.frx":2BDC
      Top             =   1140
      Visible         =   0   'False
      Width           =   180
   End
   Begin VB.Image dig 
      Height          =   255
      Index           =   7
      Left            =   2715
      Picture         =   "frmLed.frx":30EA
      Top             =   1140
      Visible         =   0   'False
      Width           =   180
   End
   Begin VB.Image dig 
      Height          =   255
      Index           =   6
      Left            =   2340
      Picture         =   "frmLed.frx":35F8
      Top             =   1140
      Visible         =   0   'False
      Width           =   180
   End
   Begin VB.Image dig 
      Height          =   255
      Index           =   5
      Left            =   2010
      Picture         =   "frmLed.frx":3B06
      Top             =   1140
      Visible         =   0   'False
      Width           =   180
   End
   Begin VB.Image dig 
      Height          =   255
      Index           =   4
      Left            =   1710
      Picture         =   "frmLed.frx":4014
      Top             =   1140
      Visible         =   0   'False
      Width           =   180
   End
   Begin VB.Image dig 
      Height          =   255
      Index           =   3
      Left            =   1335
      Picture         =   "frmLed.frx":4522
      Top             =   1125
      Visible         =   0   'False
      Width           =   180
   End
   Begin VB.Image dig 
      Height          =   255
      Index           =   2
      Left            =   945
      Picture         =   "frmLed.frx":4A30
      Top             =   1125
      Visible         =   0   'False
      Width           =   180
   End
   Begin VB.Image dig 
      Height          =   255
      Index           =   1
      Left            =   570
      Picture         =   "frmLed.frx":4F3E
      Top             =   1110
      Visible         =   0   'False
      Width           =   180
   End
   Begin VB.Image dig 
      Height          =   255
      Index           =   0
      Left            =   270
      Picture         =   "frmLed.frx":544C
      Top             =   1110
      Visible         =   0   'False
      Width           =   180
   End
End
Attribute VB_Name = "frmLed"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
Option Explicit

Dim lPrevResult As Long ' #1122d


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

On Error GoTo err1

    ' Intenger values:
    '    -32,768 to 32,767
    Dim lResult As Long
    
    
    
    
    ' Read SIGNED WORD from port 199:
    lResult = READ_IO_WORD(199)
        
    If lPrevResult <> lResult Then ' #1122d
        If shall_activate(Me) Then Me.Show
        lPrevResult = lResult
    End If
    
    ' Show minus if required:
    If lResult < 0 Then
        imgMINUS.Visible = True
        lResult = Abs(lResult)
    Else
        imgMINUS.Visible = False
    End If
    
    ' Display 5 digits:
    Dim i As Integer
    Dim v As Byte
    
    For i = 0 To 4
    
        v = lResult Mod 10
    
        d(i).Picture = dig(v).Picture
        
        lResult = Int(lResult / 10)
        
    Next i

    Exit Sub
err1:
    Debug.Print "err1"
    Resume Next
End Sub
