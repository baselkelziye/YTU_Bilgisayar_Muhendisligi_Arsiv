VERSION 5.00
Begin VB.Form frmTrafficLights 
   BackColor       =   &H00000000&
   BorderStyle     =   1  'Fixed Single
   Caption         =   "Traffic Lights"
   ClientHeight    =   3840
   ClientLeft      =   90
   ClientTop       =   375
   ClientWidth     =   3375
   FillStyle       =   0  'Solid
   BeginProperty Font 
      Name            =   "Fixedsys"
      Size            =   9
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   FontTransparent =   0   'False
   Icon            =   "frmTrafficLights.frx":0000
   KeyPreview      =   -1  'True
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   256
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   225
   Begin VB.PictureBox picStatus 
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      BackColor       =   &H00FFFFFF&
      BorderStyle     =   0  'None
      FontTransparent =   0   'False
      ForeColor       =   &H80000008&
      Height          =   585
      Left            =   307
      ScaleHeight     =   585
      ScaleWidth      =   2760
      TabIndex        =   1
      Top             =   2985
      Width           =   2760
   End
   Begin VB.PictureBox picTL 
      AutoSize        =   -1  'True
      BackColor       =   &H00000000&
      BorderStyle     =   0  'None
      FillColor       =   &H00808080&
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H0000FFFF&
      Height          =   2910
      Left            =   52
      Picture         =   "frmTrafficLights.frx":038A
      ScaleHeight     =   194
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   218
      TabIndex        =   0
      Top             =   60
      Width           =   3270
      Begin VB.PictureBox picCarPic_T_B 
         Appearance      =   0  'Flat
         AutoRedraw      =   -1  'True
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   495
         Left            =   1290
         Picture         =   "frmTrafficLights.frx":1325
         ScaleHeight     =   33
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   22
         TabIndex        =   5
         Top             =   210
         Width           =   330
      End
      Begin VB.PictureBox picCarPic_L_R 
         Appearance      =   0  'Flat
         AutoRedraw      =   -1  'True
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   330
         Left            =   510
         Picture         =   "frmTrafficLights.frx":1C2B
         ScaleHeight     =   22
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   33
         TabIndex        =   4
         Top             =   1380
         Width           =   495
      End
      Begin VB.PictureBox picCarPic_B_T 
         Appearance      =   0  'Flat
         AutoRedraw      =   -1  'True
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   495
         Left            =   1710
         Picture         =   "frmTrafficLights.frx":2505
         ScaleHeight     =   33
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   22
         TabIndex        =   3
         Top             =   1965
         Width           =   330
      End
      Begin VB.PictureBox picCarPic_R_L 
         Appearance      =   0  'Flat
         AutoRedraw      =   -1  'True
         AutoSize        =   -1  'True
         BackColor       =   &H80000005&
         BorderStyle     =   0  'None
         ForeColor       =   &H80000008&
         Height          =   330
         Left            =   2475
         Picture         =   "frmTrafficLights.frx":2E0B
         ScaleHeight     =   22
         ScaleMode       =   3  'Pixel
         ScaleWidth      =   33
         TabIndex        =   2
         Top             =   990
         Width           =   495
      End
      Begin VB.Timer timerCars 
         Interval        =   50
         Left            =   2775
         Top             =   60
      End
      Begin VB.Timer timerUpdate 
         Interval        =   111
         Left            =   1740
         Top             =   105
      End
   End
   Begin VB.Label lblPort4 
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   " port 4 (word - 16 bits)"
      BeginProperty Font 
         Name            =   "Verdana"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FFFFFF&
      Height          =   195
      Left            =   135
      TabIndex        =   6
      Top             =   3585
      Width           =   3075
   End
End
Attribute VB_Name = "frmTrafficLights"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
' virual device for emu8086 it can be controlled by microprocessor emulator

' Traffic_Lights.exe

' TRAFFIC LIGHTS
' ports 4-5  (2 bytes)

' #1144

Option Explicit


' from previous port read:
Dim uSTATUS_REGISTER_L_PREV As Byte
Dim uSTATUS_REGISTER_H_PREV As Byte

' current port read:
Dim uSTATUS_REGISTER_L As Byte
Dim uSTATUS_REGISTER_H As Byte


' car to semaphore reaction
Dim bSTOP_B_T As Boolean
Dim bSTOP_R_L As Boolean
Dim bSTOP_T_B As Boolean
Dim bSTOP_L_R As Boolean

Private Sub Form_Load()

    ' do not allow more than one copy of this program to run simuateniously
    If App.PrevInstance Then

        ShowPrevInstance

        End   ' terminate this instance!

    End If

    GetWindowPos Me
 
    update_DEVICE
    
    If allow_on_top() Then set_on_top Me
    
End Sub



Private Sub Form_Unload(Cancel As Integer)
    SaveWindowState Me
End Sub


Public Sub update_DEVICE()

    picTL_Paint
    update_picStatus
    
End Sub


Private Sub picTL_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
   ' Debug.Print X, Y
End Sub

Private Sub timerCars_Timer()
On Error GoTo err1


        If bSTOP_B_T And picCarPic_B_T.Top >= 134 And picCarPic_B_T.Top <= 140 Then
            ' car stopped...
        Else
            picCarPic_B_T.Top = picCarPic_B_T.Top - 5
            If picCarPic_B_T.Top + picCarPic_B_T.Height < 0 Then picCarPic_B_T.Top = picTL.ScaleHeight + picCarPic_B_T.Height + 10
        End If
        
        


        If bSTOP_R_L And picCarPic_R_L.Left >= 159 And picCarPic_R_L.Left <= 165 Then
            ' car stopped...
        Else
            picCarPic_R_L.Left = picCarPic_R_L.Left - 5
            If picCarPic_R_L.Left + picCarPic_R_L.Width < 0 Then picCarPic_R_L.Left = picTL.ScaleWidth + picCarPic_R_L.Width + 10
        End If
        
        
        If bSTOP_T_B And (picCarPic_T_B.Top + picCarPic_T_B.Height) <= 43 And (picCarPic_T_B.Top + picCarPic_T_B.Height) >= 37 Then
            ' car stopped...
        Else
            picCarPic_T_B.Top = picCarPic_T_B.Top + 5
            If picCarPic_T_B.Top + 10 > picTL.ScaleHeight Then picCarPic_T_B.Top = 0 - picCarPic_T_B.Height - 10
        End If
        
        
        
        If bSTOP_L_R And (picCarPic_L_R.Width + picCarPic_L_R.Left) >= 58 And (picCarPic_L_R.Width + picCarPic_L_R.Left) <= 64 Then
            ' car stopped...
        Else
            picCarPic_L_R.Left = picCarPic_L_R.Left + 5
            If picCarPic_L_R.Left > picTL.ScaleWidth Then picCarPic_L_R.Left = 0 - picCarPic_L_R.Width - 10
        End If
        
        
        
    Exit Sub
err1:
    Debug.Print "timerCars: " & Err.Description
End Sub

'Private Sub picTL_Click()
'    SavePicture picTL, "c:\1.bmp"
'End Sub

Private Sub timerUpdate_Timer()

    uSTATUS_REGISTER_L = io.READ_IO_BYTE(4)
    uSTATUS_REGISTER_H = io.READ_IO_BYTE(5)

    If uSTATUS_REGISTER_L = uSTATUS_REGISTER_L_PREV And uSTATUS_REGISTER_H = uSTATUS_REGISTER_H_PREV Then
        ' no changes!
    Else
        ' keep previous state:
        uSTATUS_REGISTER_L_PREV = uSTATUS_REGISTER_L
        uSTATUS_REGISTER_H_PREV = uSTATUS_REGISTER_H
        
        If shall_activate(Me) Then Me.Show
        update_DEVICE
    End If
    
End Sub



' Private Sub picStatus_Paint()
' I set it to be AutoRedraw=True, so no need to update on
' paint, also this prevents flickering:
Private Sub update_picStatus()
    On Error GoTo err_fp

    Dim sBWORD As String
    Dim s As String
    Dim i As Long
    Dim uBIT_POS As Byte
    Dim f1 As Single
    
    Const sCaptionBits = "FEDCBA9876543210"
    
    sBWORD = toBIN_WORD(to16bit_SIGNED(uSTATUS_REGISTER_L, uSTATUS_REGISTER_H))
    
    
    picStatus.CurrentX = picStatus.ScaleWidth / 2 - picStatus.TextWidth(sCaptionBits) / 2
    picStatus.CurrentY = 50 'picStatus.TextHeight(sCaptionBits)
    
    picStatus.ForeColor = RGB(100, 100, 100)
    picStatus.Print sCaptionBits
    
    picStatus.CurrentX = picStatus.ScaleWidth / 2 - picStatus.TextWidth(sBWORD) / 2
    picStatus.CurrentY = 50 + picStatus.TextHeight(sCaptionBits)
    
    
    
    For i = 1 To 16
        s = Mid(sBWORD, i, 1)
        If i < 5 Then ' draw grey bits that aren't used
            picStatus.ForeColor = RGB(170, 170, 170)
        Else
            If s = "0" Then
                picStatus.ForeColor = vbBlue
            Else
                picStatus.ForeColor = vbRed
            End If
        End If
        picStatus.Print s;
    Next i
    
    Exit Sub
    
err_fp:
    Debug.Print "trafic:picStatus_Paint: " & Err.Description
    
End Sub




' set lights:
Private Sub picTL_Paint()

    On Error GoTo err_ptlp

    Dim sBWORD As String
    Dim s As String
    Dim i As Long
    Dim uBIT_POS As Byte
    
    sBWORD = toBIN_WORD(to16bit_SIGNED(uSTATUS_REGISTER_L, uSTATUS_REGISTER_H))
    
    ' make LSB be at index 1:
    sBWORD = StrReverse(sBWORD)
    
    For i = 1 To 16
    
        s = Mid(sBWORD, i, 1)
        
        uBIT_POS = i - 1
        
        Select Case uBIT_POS

        
        ' traffic lights 9,A,B:
        Case 11
            draw_DOT s, vbGreen, 40, 120
            bSTOP_L_R = IIf(s = "1", False, True)
        Case 10
            draw_DOT s, vbYellow, 52, 120
        Case 9
            draw_DOT s, vbRed, 64, 120
        
        ' traffic lights 6,7,8:
        Case 8
            draw_DOT s, vbGreen, 78, 20
            bSTOP_T_B = IIf(s = "1", False, True)
        Case 7
            draw_DOT s, vbYellow, 78, 32
        Case 6
            draw_DOT s, vbRed, 78, 43
            
            
            
        ' traffic lights 3,4,5:
        Case 5
            draw_DOT s, vbGreen, 182, 58
            bSTOP_R_L = IIf(s = "1", False, True)
        Case 4
            draw_DOT s, vbYellow, 170, 58
        Case 3
            draw_DOT s, vbRed, 159, 58
            
        ' traffic lights 0,1,2:
        Case 2
            draw_DOT s, vbGreen, 145, 158
            bSTOP_B_T = IIf(s = "1", False, True)
        Case 1
            draw_DOT s, vbYellow, 145, 146
        Case 0
            draw_DOT s, vbRed, 145, 134
            
        End Select
    
    Next i
    
    Exit Sub
err_ptlp:
    Debug.Print "picTL_Paint: " & Err.Description
End Sub

Private Sub draw_DOT(sSTATUS As String, lCOLOR As Long, fPosX As Single, fPosY As Single)
    Dim l As Long
    
    If sSTATUS = "1" Then
        l = lCOLOR
    Else
        l = RGB(127, 127, 127)
    End If
    
    
    ' 1.26#322 picTL.PSet (fPosX, fPosY), l
    picTL.DrawWidth = 1
    picTL.FillColor = l
    picTL.FillStyle = vbFSSolid
    
    ' 1.27 - without it first circle is
    ' drawn with current fore color (seems
    ' to be VB bug or something),
    ' DoEvents also helps.
    picTL.ForeColor = l
    
    
    picTL.Circle (fPosX, fPosY), 4, l
End Sub


Function to16bit_SIGNED(ByRef byteL As Byte, ByRef byteH As Byte) As Integer
    Dim temp As Long
    
    ' lower byte - on lower address!
    ' byte1 - lower byte!
    
    temp = byteH
    temp = temp * 256 ' shift left by 16.
    temp = temp + byteL
    
    
    to16bit_SIGNED = to_signed_int(temp)
End Function

' makes a long to be a SIGNED integer:
 Function to_signed_int(l As Long) As Integer
    If l >= -32768 And l < 65536 Then
        If l <= 32767 Then
            to_signed_int = l
        Else
            to_signed_int = l - 65536
        End If
    Else
        to_signed_int = 0
        Debug.Print "Wrong param calling to_signed_int(): " & l
    End If
End Function


' returns BINARY presentation of a number,
' return value has 16 bits (zeros & ones)
Function toBIN_WORD(ByRef iNum As Integer) As String

    Dim sHEX As String
    Dim sResult As String
    Dim i As Integer
    Dim Size As Integer
    
    sHEX = Hex(iNum)
    Size = Len(sHEX)
    
    sResult = ""
    
    For i = Size To 1 Step -1
        sResult = HEX_2_BIN(Mid(sHEX, i, 1)) & sResult
    Next i
    
    toBIN_WORD = make_min_len(sResult, 16, "0")
    
End Function


' converts single HEX digit to BINARY:
Function HEX_2_BIN(ByRef sHEX_DIGIT As String) As String
    Select Case UCase(sHEX_DIGIT)
    
    Case "0"
        HEX_2_BIN = "0000"

    Case "1"
        HEX_2_BIN = "0001"
 
    Case "2"
        HEX_2_BIN = "0010"

    Case "3"
        HEX_2_BIN = "0011"

    Case "4"
        HEX_2_BIN = "0100"

    Case "5"
        HEX_2_BIN = "0101"

    Case "6"
        HEX_2_BIN = "0110"

    Case "7"
        HEX_2_BIN = "0111"

    Case "8"
        HEX_2_BIN = "1000"

    Case "9"
        HEX_2_BIN = "1001"

    Case "A"
        HEX_2_BIN = "1010"

    Case "B"
        HEX_2_BIN = "1011"

    Case "C"
        HEX_2_BIN = "1100"

    Case "D"
        HEX_2_BIN = "1101"

    Case "E"
        HEX_2_BIN = "1110"

    Case "F"
        HEX_2_BIN = "1111"
        
    Case "h", "H"   ' ignore (suffix).
        HEX_2_BIN = ""
        
    Case Else
        Debug.Print "wrong argument in HEX_2_BIN(" & sHEX_DIGIT & ")"
    End Select
End Function


 Function make_min_len(s As String, minLen As Integer, sAddWhat As String) As String
    Dim i As Integer
    Dim sRes As String
    
    i = 0
    sRes = s
    
    While Len(sRes) < minLen
        sRes = sAddWhat & sRes
    Wend
    
    make_min_len = sRes
    
End Function


