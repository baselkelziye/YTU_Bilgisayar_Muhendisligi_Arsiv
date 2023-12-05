VERSION 5.00
Begin VB.Form frmStepperMotor 
   BackColor       =   &H00FFFFFF&
   BorderStyle     =   1  'Fixed Single
   Caption         =   "stepper-motor on port 7"
   ClientHeight    =   2850
   ClientLeft      =   90
   ClientTop       =   375
   ClientWidth     =   3465
   BeginProperty Font 
      Name            =   "Fixedsys"
      Size            =   9
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   Icon            =   "frmStepperMotor.frx":0000
   KeyPreview      =   -1  'True
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   ScaleHeight     =   190
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   231
   Begin VB.Timer timerUpdater 
      Interval        =   107
      Left            =   2820
      Top             =   975
   End
   Begin VB.PictureBox picROTOR 
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   1320
      Index           =   3
      Left            =   6030
      Picture         =   "frmStepperMotor.frx":038A
      ScaleHeight     =   1320
      ScaleWidth      =   1320
      TabIndex        =   5
      Top             =   120
      Visible         =   0   'False
      Width           =   1320
   End
   Begin VB.PictureBox picROTOR 
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   1320
      Index           =   2
      Left            =   4065
      Picture         =   "frmStepperMotor.frx":096E
      ScaleHeight     =   1320
      ScaleWidth      =   1320
      TabIndex        =   4
      Top             =   3210
      Visible         =   0   'False
      Width           =   1320
   End
   Begin VB.PictureBox picROTOR 
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   1320
      Index           =   1
      Left            =   4050
      Picture         =   "frmStepperMotor.frx":0F33
      ScaleHeight     =   1320
      ScaleWidth      =   1320
      TabIndex        =   3
      Top             =   1620
      Visible         =   0   'False
      Width           =   1320
   End
   Begin VB.PictureBox picROTOR 
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   1320
      Index           =   0
      Left            =   4050
      Picture         =   "frmStepperMotor.frx":14C8
      ScaleHeight     =   1320
      ScaleWidth      =   1320
      TabIndex        =   2
      Top             =   105
      Visible         =   0   'False
      Width           =   1320
   End
   Begin VB.PictureBox picTL 
      AutoRedraw      =   -1  'True
      BackColor       =   &H00FFFFFF&
      BorderStyle     =   0  'None
      Height          =   1920
      Left            =   1072
      ScaleHeight     =   128
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   88
      TabIndex        =   1
      Top             =   165
      Width           =   1320
   End
   Begin VB.PictureBox picStatus 
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      BackColor       =   &H00FFFFFF&
      BorderStyle     =   0  'None
      FontTransparent =   0   'False
      ForeColor       =   &H80000008&
      Height          =   585
      Left            =   352
      ScaleHeight     =   585
      ScaleWidth      =   2760
      TabIndex        =   0
      Top             =   2160
      Width           =   2760
   End
   Begin VB.Label Label7 
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "7"
      ForeColor       =   &H80000008&
      Height          =   225
      Left            =   360
      TabIndex        =   7
      Top             =   1725
      Width           =   120
   End
   Begin VB.Label lblStatus 
      Alignment       =   2  'Center
      Appearance      =   0  'Flat
      BackColor       =   &H80000005&
      BackStyle       =   0  'Transparent
      Caption         =   "busy"
      BeginProperty Font 
         Name            =   "Verdana"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00000000&
      Height          =   195
      Left            =   75
      TabIndex        =   6
      Top             =   1500
      Width           =   750
   End
End
Attribute VB_Name = "frmStepperMotor"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
' designed for emu8086 microprocessor

' STEPPER MOTOR ON PORT 7

' Stepper_motor.exe




Option Explicit

Dim uSTATUS_REGISTER_PREV As Byte
Dim uSTATUS_REGISTER As Byte ' port 7

Dim uCURRENT_ROTOR_POSITON As Integer

Dim uCURRENT_DOT_POS As Integer



Private Sub Form_Load()

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

    ' it is assumed that high bit is cleared by the microprocessor
    ' when it writes new data, thus motor becomes busy.

    update_picTL
    
    
    ' update complete,
    ' update top bit of port 7 to let microprocessor know that motor has sucessfully moved.
    uSTATUS_REGISTER = uSTATUS_REGISTER Or 128 ' set top bit.
    io.WRITE_IO_BYTE 7, uSTATUS_REGISTER
    
    lblStatus.Caption = "ready"
    lblStatus.ForeColor = vbRed
    
    
    update_picStatus
    
    
    
End Sub


Private Sub timerUpdater_Timer()
   
   uSTATUS_REGISTER = io.READ_IO_BYTE(7)
   
   If uSTATUS_REGISTER_PREV <> uSTATUS_REGISTER Then ' is there change is port input?
        
        ' set "busy", update_DEVICE should set "ready"
        lblStatus.Caption = "busy"
        lblStatus.ForeColor = vbBlue
        update_picStatus ' its better to show what is inputed. it will set busy even if processor writes "1" to top most bit, therefore it is assumed that processor writes zero there.
        DoEvents
        
        update_DEVICE
        
        If shall_activate(Me) Then Me.Show
        
        uSTATUS_REGISTER_PREV = uSTATUS_REGISTER
        
   End If
   
End Sub



Private Sub update_picStatus()
    On Error GoTo err_fp

    Dim sBBYTE As String
    Dim s As String
    Dim i As Long
    Dim uBIT_POS As Byte
    Dim f1 As Single
    
    Const sCaptionBits = "76543210"
    
    sBBYTE = toBIN_BYTE(uSTATUS_REGISTER)
    
    
    picStatus.CurrentX = picStatus.ScaleWidth / 2 - picStatus.TextWidth(sCaptionBits) / 2
    picStatus.CurrentY = 50 ' picStatus.TextHeight(sCaptionBits)
    
    picStatus.ForeColor = RGB(100, 100, 100)
    picStatus.Print sCaptionBits
    
    picStatus.CurrentX = picStatus.ScaleWidth / 2 - picStatus.TextWidth(sBBYTE) / 2
    picStatus.CurrentY = 50 + picStatus.TextHeight(sCaptionBits)
    
    
    
    For i = 1 To 8
        s = Mid(sBBYTE, i, 1)
        If s = "0" Then
            picStatus.ForeColor = vbBlue
        Else
            picStatus.ForeColor = vbRed
        End If
        picStatus.Print s;
    Next i
    
    Exit Sub
    
err_fp:
    Debug.Print "picStatus_Paint: " & Err.Description
    
End Sub


Private Sub update_picTL()
On Error GoTo err_tl_err
    
    Dim r1 As Long
    Dim r2 As Long
    
    Dim fCENTER As Single
    Dim lCOLOR As Long
    
    Const MAGNET_WIDTH = 10
    Const MAGNET_HEIGHT = 10
    Const DIST_BETWEEN_MAGNETS = 25
    Const START_Y = 100
    Const START_Y_edge = 93   ' for magnets ont he edge.
    Const LEFT_CORRECTION = 2 ' the correction (because image isn't symentrical...)
    
    update_ROTOR
    
    fCENTER = picTL.ScaleWidth / 2 - MAGNET_WIDTH / 2 - LEFT_CORRECTION
    
    picTL.DrawWidth = 1
    
    ' firt bit:
    lCOLOR = IIf(uSTATUS_REGISTER And 1, vbRed, vbBlue)
    picTL.Line (fCENTER + DIST_BETWEEN_MAGNETS, START_Y_edge)-(fCENTER + DIST_BETWEEN_MAGNETS + MAGNET_WIDTH, START_Y_edge + MAGNET_HEIGHT), lCOLOR, BF

    ' draw destription below bit:
    r1 = picTL.CurrentX - MAGNET_WIDTH / 2 - picTL.TextWidth("0") / 2
    r2 = picTL.CurrentY + 2
    picTL.CurrentX = r1
    picTL.CurrentY = r2
    picTL.Print "0"
    
    ' second bit:
    lCOLOR = IIf(uSTATUS_REGISTER And 2, vbRed, vbBlue)
    picTL.Line (fCENTER, START_Y)-(fCENTER + MAGNET_WIDTH, START_Y + MAGNET_HEIGHT), lCOLOR, BF


    ' draw destription below bit:
    r1 = picTL.CurrentX - MAGNET_WIDTH / 2 - picTL.TextWidth("1") / 2
    r2 = picTL.CurrentY + 2
    picTL.CurrentX = r1
    picTL.CurrentY = r2
    picTL.Print "1"
    
        
    ' third bit:
    lCOLOR = IIf(uSTATUS_REGISTER And 4, vbRed, vbBlue)
    picTL.Line (fCENTER - DIST_BETWEEN_MAGNETS, START_Y_edge)-(fCENTER - DIST_BETWEEN_MAGNETS + MAGNET_WIDTH, START_Y_edge + MAGNET_HEIGHT), lCOLOR, BF

    
    ' draw destription below bit:
    r1 = picTL.CurrentX - MAGNET_WIDTH / 2 - picTL.TextWidth("2") / 2
    r2 = picTL.CurrentY + 2
    picTL.CurrentX = r1
    picTL.CurrentY = r2
    picTL.Print "2"
        
        
Exit Sub
err_tl_err:
    Debug.Print "stepper_motor: picTL_Paint: " & Err.Description
End Sub

Private Sub update_ROTOR()

    Dim iCUR As Integer
    Dim iNEW As Integer
    Dim uTEMP As Byte
    
    
    Dim iMOVES As Integer
    Const dLEFT = 1
    Const dRIGHT = -1
    Const dLEFT_FS = 2 ' full step.
    Const dRIGHT_FS = -2 ' full step.
    
    
    iCUR = uCURRENT_ROTOR_POSITON ' just for convenience.
    
    iNEW = uCURRENT_ROTOR_POSITON ' by default.
     
    ' only low 3 bits are used:
    
    uTEMP = uSTATUS_REGISTER And 7  ' leave only 3 bits.
    
    Select Case uTEMP
    
    Case 0   ' 000
            ' never moves.
        
    Case 1   ' 001
            Select Case iCUR
            Case 0
                iNEW = 1
                iMOVES = dLEFT_FS
            Case 1
                ' stays.
            Case 2
                iNEW = 1
                iMOVES = dLEFT
            Case 3
                iNEW = 1
                iMOVES = dRIGHT
            End Select
        
    Case 2   ' 010
            Select Case iCUR
            Case 0
                ' stays.
                
            Case 1
                ' stays (may jump to random position in real physics).
                
            Case 2
                iNEW = 0
                iMOVES = dRIGHT
                
            Case 3
                iNEW = 0
                iMOVES = dLEFT
                
            End Select
        
    Case 3   ' 011
            Select Case iCUR
            Case 0
                iNEW = 3
                iMOVES = dRIGHT
                
            Case 1
                iNEW = 3
                iMOVES = dLEFT
                
            Case 2
                iNEW = 3
                iMOVES = dRIGHT_FS
                
            Case 3
                ' stays.
                
            End Select
        
    Case 4   ' 100
            Select Case iCUR
            Case 0
                iNEW = 1
                iMOVES = dRIGHT_FS
                
            Case 1
                ' stays.
                
            Case 2
                iNEW = 1
                iMOVES = dLEFT
            
            Case 3
                iNEW = 1
                iMOVES = dRIGHT
            
            End Select
        
    Case 5   ' 101
            Select Case iCUR
            Case 0
                ' stays (may jump to 1).
                
            Case 1
                ' stays.
            
            Case 2
                iNEW = 1
                iMOVES = dLEFT
            
            Case 3
                iNEW = 1
                iMOVES = dRIGHT
                
            End Select
    
    Case 6   ' 110
            Select Case iCUR
            Case 0
                iNEW = 2
                iMOVES = dLEFT
                
            Case 1
                iNEW = 2
                iMOVES = dRIGHT
            
            Case 2
                ' stays.
                
            Case 3
                iNEW = 2
                iMOVES = dLEFT_FS ' not sure! sure?
            
            End Select
    
    
    Case 7   ' 111
            Select Case iCUR
            
            Case 0
                ' stays.
                
            Case 1
                ' stays.
                
            Case 2
                iNEW = 0
                iMOVES = dRIGHT
                
            Case 3
                iNEW = 0
                iMOVES = dLEFT
            
            End Select
        
    End Select
    

    uCURRENT_ROTOR_POSITON = iNEW
    picTL.Picture = picROTOR(iNEW).Picture
 
    picTL.CurrentX = 0
    picTL.CurrentY = 0
    If iMOVES > 0 Then
        picTL.Print "->"
    ElseIf iMOVES < 0 Then
        picTL.Print "<-"
    Else
        picTL.Print "-"
    End If
 
    move_DOT iMOVES
 
End Sub


Private Sub move_DOT(iStep As Integer)

' no need because when picture reloads it
' clears everything:
'' draw_DOT uCURRENT_DOT_POS, vbWhite ' hide old dot.

If (uCURRENT_DOT_POS = 0) And (iStep < 0) Then
    uCURRENT_DOT_POS = 32
End If

uCURRENT_DOT_POS = uCURRENT_DOT_POS + iStep

If uCURRENT_DOT_POS = -1 Then uCURRENT_DOT_POS = 31

If uCURRENT_DOT_POS = 32 Then uCURRENT_DOT_POS = 0
If uCURRENT_DOT_POS = 33 Then uCURRENT_DOT_POS = 1

draw_DOT uCURRENT_DOT_POS, vbGreen ' draw new dot.

End Sub

Private Sub draw_DOT(iPos As Integer, lCOLOR As Long)

Dim iX As Integer
Dim iY As Integer
    
    
    Select Case uCURRENT_DOT_POS
    Case 0
        iX = 43
        iY = 86
    Case 1
        iX = 34
        iY = 85
    Case 2
        iX = 26
        iY = 83
    Case 3
        iX = 20
        iY = 78
    Case 4
        iX = 14
        iY = 74
    Case 5
        iX = 8
        iY = 67
    Case 6
        iX = 4
        iY = 59
    Case 7
        iX = 2
        iY = 52
    Case 8
        iX = 1
        iY = 44
    Case 9
        iX = 2
        iY = 36
    Case 10
        iX = 3
        iY = 27
    Case 11
        iX = 7
        iY = 20
    Case 12
        iX = 13
        iY = 14
    Case 13
        iX = 19
        iY = 9
    Case 14
        iX = 26
        iY = 5
    Case 15
        iX = 34
        iY = 2
    Case 16
        iX = 42
        iY = 2
    Case 17
        iX = 50
        iY = 2
    Case 18
        iX = 58
        iY = 5
    Case 19
        iX = 65
        iY = 9
    Case 20
        iX = 71
        iY = 14
    Case 21
        iX = 77
        iY = 20
    Case 22
        iX = 81
        iY = 27
    Case 23
        iX = 84
        iY = 35
    Case 24
        iX = 85
        iY = 43
    Case 25
        iX = 84
        iY = 51
    Case 26
        iX = 81
        iY = 60
    Case 27
        iX = 77
        iY = 67
    Case 28
        iX = 73
        iY = 73
    Case 29
        iX = 66
        iY = 78
    Case 30
        iX = 58
        iY = 82
    Case 31
        iX = 51
        iY = 85
        
    Case Else
        ' something wrong.
        Debug.Print "draw_DOT: uCURRENT_DOT_POS: " & uCURRENT_DOT_POS
        uCURRENT_DOT_POS = 0
        Exit Sub
        
    End Select
    
    picTL.DrawWidth = 2

    picTL.Line (iX, iY)-(43, 43), lCOLOR
    
End Sub




' returns BINARY presentation of a number,
' return value has 8 bits (zeros & ones)
Function toBIN_BYTE(ByRef bNum As Byte) As String

    Dim sHEX As String
    Dim sResult As String
    Dim i As Integer
    Dim Size As Integer
    
    sHEX = Hex(bNum)
    Size = Len(sHEX)
    
    sResult = ""
    
    For i = Size To 1 Step -1
        sResult = HEX_2_BIN(Mid(sHEX, i, 1)) & sResult
    Next i
    
    toBIN_BYTE = make_min_len(sResult, 8, "0")
    
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

