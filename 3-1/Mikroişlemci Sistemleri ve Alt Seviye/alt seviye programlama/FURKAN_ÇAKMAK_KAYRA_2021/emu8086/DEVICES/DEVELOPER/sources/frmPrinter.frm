VERSION 5.00
Begin VB.Form frmPrinter 
   Caption         =   "printer emulation"
   ClientHeight    =   5100
   ClientLeft      =   105
   ClientTop       =   390
   ClientWidth     =   4005
   BeginProperty Font 
      Name            =   "Courier"
      Size            =   9.75
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   Icon            =   "frmPrinter.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   5100
   ScaleWidth      =   4005
   Begin VB.Timer Timer1 
      Interval        =   200
      Left            =   3105
      Top             =   555
   End
   Begin VB.CommandButton cmdNewPage 
      Caption         =   "new page"
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   9.75
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   375
      Left            =   60
      TabIndex        =   2
      TabStop         =   0   'False
      Top             =   75
      Width           =   1215
   End
   Begin VB.PictureBox picPaper 
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      BackColor       =   &H80000005&
      FillStyle       =   0  'Solid
      FontTransparent =   0   'False
      ForeColor       =   &H80000008&
      Height          =   4335
      Left            =   30
      ScaleHeight     =   287
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   223
      TabIndex        =   0
      Top             =   585
      Width           =   3375
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      Caption         =   "printer data port: 130d"
      BeginProperty Font 
         Name            =   "Verdana"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   195
      Index           =   0
      Left            =   1485
      TabIndex        =   1
      Top             =   180
      Width           =   2235
   End
End
Attribute VB_Name = "frmPrinter"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
' the original idea by Andrew Nelis

Option Explicit

Private Sub Form_Load()

    If App.PrevInstance Then
        ShowPrevInstance
        End  ' terminate this instance!
    End If
 
    GetWindowPos Me
    GetWindowSize Me, 4125, 5510
    
    If allow_on_top() Then set_on_top Me
     
End Sub

Private Sub Form_Resize()
    On Error GoTo err1
    
        picPaper.Left = 0
        picPaper.Width = Me.ScaleWidth
        picPaper.Height = Me.ScaleHeight - picPaper.Top
        
    Exit Sub
err1:
    Debug.Print "Form_Resize: " & Err.Description
End Sub

Private Sub Form_Unload(Cancel As Integer)
    SaveWindowState Me
End Sub

Private Sub cmdNewPage_Click()
    new_page
End Sub

Private Sub Timer1_Timer()
On Error GoTo err1
    
    Dim port_num As Long
    port_num = 130
    Dim byteChar As Byte
    
    byteChar = READ_IO_BYTE(port_num)
    If byteChar <> 0 Then
        ' Debug.Print char
        printer_print byteChar
        WRITE_IO_BYTE port_num, 0
        If shall_activate(Me) Then Me.Show
    End If
    
    byteChar = 0
    
    Exit Sub
err1:
    picPaper.Print "i/o error:" & LCase(Err.Description)
    
End Sub


Sub printer_print(byteChar As Byte)
On Error GoTo err1:


  ' check automatic line feed
  If picPaper.CurrentX >= picPaper.ScaleWidth Then
        head_print 10
        picPaper.CurrentX = 0
  End If
  


   Select Case byteChar
        Case 7
             ' bell  (not all printers support it, only the old telegraphs do)
             Beep 300, 20
             
        Case 9
             ' horizontal tab = 4 new lines
             Dim i As Integer
             For i = 1 To 4
                 head_print 10
             Next i
            
        Case 12
             ' form feed, new page
             new_page
            
        Case 13
             ' line feed
             picPaper.CurrentX = 0
    
             
        Case Else
             ' it's a printable character, print it out:
             head_print (byteChar)
                     
    End Select


    Exit Sub
err1:
    Debug.Print "printer error: " & Err.Description
End Sub

Sub head_print(byteChar As Byte)
    picPaper.Print Chr(byteChar);
End Sub

Sub new_page()
    picPaper.Cls
End Sub
















' protection code to avoid running two printers simultaneously on the same port
Private Function ShowPrevInstance() As Boolean ' returns True on sucess.
On Error GoTo err1:

    Dim sOldTitle As String
    Dim lWindowHandle As Long

    'saving the current title in OldTitle variable
    'and changing the application title

    sOldTitle = App.Title
    App.Title = "NNNNNN - I WILL CLOSE MYSELF"

    'finding the previous instance, if you are using VB 5.0, change "ThunderRT6Main" to "ThunderRT5Main"
    lWindowHandle = FindWindow("ThunderRT6Main", sOldTitle)

    'if there is no old instances of your application - exit.
    If lWindowHandle = 0 Then
    ShowPrevInstance = False
    Exit Function
    End If

    'Find the window we need to restore
    lWindowHandle = GetWindow(lWindowHandle, GW_HWNDPREV)

    'Now restore it
    Call OpenIcon(lWindowHandle)

    'And Bring it to the foreground
    Call SetForegroundWindow(lWindowHandle)
      
    ShowPrevInstance = True
    Exit Function
err1:
    Debug.Print "ShowPrevInstance: " & Err.Description
    Resume Next
End Function
