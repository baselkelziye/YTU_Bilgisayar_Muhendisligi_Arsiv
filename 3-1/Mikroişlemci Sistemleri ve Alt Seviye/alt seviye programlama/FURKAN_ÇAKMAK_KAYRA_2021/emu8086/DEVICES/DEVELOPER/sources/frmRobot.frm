VERSION 5.00
Begin VB.Form frmRobot 
   BackColor       =   &H00FFFFFF&
   BorderStyle     =   1  'Fixed Single
   Caption         =   "robot on port 9         (3 bytes)"
   ClientHeight    =   4005
   ClientLeft      =   90
   ClientTop       =   375
   ClientWidth     =   4470
   BeginProperty Font 
      Name            =   "Fixedsys"
      Size            =   9
      Charset         =   0
      Weight          =   400
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   Icon            =   "frmRobot.frx":0000
   KeyPreview      =   -1  'True
   LinkTopic       =   "Form1"
   LockControls    =   -1  'True
   MaxButton       =   0   'False
   ScaleHeight     =   267
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   298
   Begin VB.PictureBox picLAMP_OFF 
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   480
      Left            =   5430
      Picture         =   "frmRobot.frx":038A
      ScaleHeight     =   32
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   32
      TabIndex        =   15
      Tag             =   "LAMP_OFF"
      ToolTipText     =   "Lamp"
      Top             =   2250
      Visible         =   0   'False
      Width           =   480
   End
   Begin VB.PictureBox picTools 
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   480
      Index           =   2
      Left            =   1080
      Picture         =   "frmRobot.frx":0434
      ScaleHeight     =   32
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   32
      TabIndex        =   14
      Tag             =   "LAMP"
      ToolTipText     =   "Lamp"
      Top             =   3450
      Width           =   480
   End
   Begin VB.PictureBox picTools 
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   480
      Index           =   1
      Left            =   570
      Picture         =   "frmRobot.frx":04DE
      ScaleHeight     =   32
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   32
      TabIndex        =   13
      Tag             =   "WALL"
      ToolTipText     =   "Wall"
      Top             =   3450
      Width           =   480
   End
   Begin VB.PictureBox picTools 
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      BorderStyle     =   0  'None
      FillColor       =   &H000000FF&
      ForeColor       =   &H000000FF&
      Height          =   480
      Index           =   0
      Left            =   45
      Picture         =   "frmRobot.frx":0599
      ScaleHeight     =   32
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   32
      TabIndex        =   12
      Tag             =   "ROBOT"
      ToolTipText     =   "Robot"
      Top             =   3450
      Width           =   480
   End
   Begin VB.Timer timer_Do_ROBOT_MOVE 
      Enabled         =   0   'False
      Interval        =   1
      Left            =   285
      Top             =   2325
   End
   Begin VB.PictureBox pics 
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   480
      Index           =   8
      Left            =   5445
      Picture         =   "frmRobot.frx":0664
      ScaleHeight     =   32
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   32
      TabIndex        =   10
      Tag             =   "500"
      Top             =   1320
      Visible         =   0   'False
      Width           =   480
   End
   Begin VB.PictureBox pics 
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   480
      Index           =   7
      Left            =   5490
      Picture         =   "frmRobot.frx":06AF
      ScaleHeight     =   32
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   32
      TabIndex        =   9
      Tag             =   "315"
      Top             =   690
      Visible         =   0   'False
      Width           =   480
   End
   Begin VB.PictureBox pics 
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   480
      Index           =   6
      Left            =   5445
      Picture         =   "frmRobot.frx":0BC2
      ScaleHeight     =   32
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   32
      TabIndex        =   8
      Tag             =   "270"
      Top             =   150
      Visible         =   0   'False
      Width           =   480
   End
   Begin VB.PictureBox pics 
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   480
      Index           =   5
      Left            =   4755
      Picture         =   "frmRobot.frx":0C8D
      ScaleHeight     =   32
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   32
      TabIndex        =   7
      Tag             =   "225"
      Top             =   3285
      Visible         =   0   'False
      Width           =   480
   End
   Begin VB.PictureBox pics 
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   480
      Index           =   4
      Left            =   4710
      Picture         =   "frmRobot.frx":11BF
      ScaleHeight     =   32
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   32
      TabIndex        =   6
      Tag             =   "180"
      Top             =   2685
      Visible         =   0   'False
      Width           =   480
   End
   Begin VB.PictureBox pics 
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   480
      Index           =   3
      Left            =   4695
      Picture         =   "frmRobot.frx":128A
      ScaleHeight     =   32
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   32
      TabIndex        =   5
      Tag             =   "135"
      Top             =   2010
      Visible         =   0   'False
      Width           =   480
   End
   Begin VB.PictureBox pics 
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   480
      Index           =   2
      Left            =   4695
      Picture         =   "frmRobot.frx":179A
      ScaleHeight     =   32
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   32
      TabIndex        =   4
      Tag             =   "90"
      Top             =   1290
      Visible         =   0   'False
      Width           =   480
   End
   Begin VB.PictureBox pics 
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   480
      Index           =   1
      Left            =   4650
      Picture         =   "frmRobot.frx":1865
      ScaleHeight     =   32
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   32
      TabIndex        =   3
      Tag             =   "45"
      Top             =   615
      Visible         =   0   'False
      Width           =   480
   End
   Begin VB.PictureBox pics 
      Appearance      =   0  'Flat
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      BorderStyle     =   0  'None
      ForeColor       =   &H80000008&
      Height          =   480
      Index           =   0
      Left            =   4650
      Picture         =   "frmRobot.frx":1D94
      ScaleHeight     =   32
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   32
      TabIndex        =   2
      Tag             =   "0"
      Top             =   120
      Visible         =   0   'False
      Width           =   480
   End
   Begin VB.Timer timer_COMPLETE_LEFT 
      Enabled         =   0   'False
      Interval        =   250
      Left            =   1080
      Top             =   1905
   End
   Begin VB.Timer timer_COMPLETE_RIGHT 
      Enabled         =   0   'False
      Interval        =   250
      Left            =   1080
      Top             =   2475
   End
   Begin VB.PictureBox picStatus 
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      BackColor       =   &H00FFFFFF&
      BorderStyle     =   0  'None
      FontTransparent =   0   'False
      ForeColor       =   &H80000008&
      Height          =   975
      Left            =   1650
      ScaleHeight     =   975
      ScaleWidth      =   2760
      TabIndex        =   1
      Top             =   2985
      Width           =   2760
   End
   Begin VB.PictureBox picTL 
      Appearance      =   0  'Flat
      AutoRedraw      =   -1  'True
      BackColor       =   &H00FFFFFF&
      BeginProperty Font 
         Name            =   "MS Sans Serif"
         Size            =   8.25
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H80000008&
      Height          =   2910
      Left            =   60
      ScaleHeight     =   192
      ScaleMode       =   3  'Pixel
      ScaleWidth      =   288
      TabIndex        =   0
      Top             =   45
      Width           =   4350
      Begin VB.Timer timerPortReader 
         Interval        =   117
         Left            =   195
         Top             =   60
      End
      Begin VB.Timer timerHide_Positioner 
         Enabled         =   0   'False
         Interval        =   1000
         Left            =   2370
         Top             =   2295
      End
      Begin VB.Shape shapePOSITIONER 
         BorderStyle     =   3  'Dot
         DrawMode        =   6  'Mask Pen Not
         Height          =   480
         Left            =   1755
         Top             =   1275
         Visible         =   0   'False
         Width           =   480
      End
   End
   Begin VB.Label lblMessage 
      BackStyle       =   0  'Transparent
      ForeColor       =   &H000000FF&
      Height          =   225
      Left            =   60
      TabIndex        =   11
      Top             =   3000
      Width           =   1470
   End
   Begin VB.Menu popMapUpMenu 
      Caption         =   "popMapUpMenu"
      Visible         =   0   'False
      Begin VB.Menu mnuSwitchOffAllLamps 
         Caption         =   "Switch Off All Lamps"
      End
      Begin VB.Menu mnuSwitchOnAllLamps 
         Caption         =   "Switch On All Lamps"
      End
   End
End
Attribute VB_Name = "frmRobot"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
' virtual device for emu8086 microprocessor

' ROBOT


Option Explicit

Option Base 0


Dim uCOMMAND_REGISTER As Byte  ' port 9  - accepts commands.
Dim uDATA_REGISTER As Byte     ' port 10 - output.
Dim uSTATUS_REGISTER As Byte   ' port 11 - output.

' ========= BIT VALUES ===================

'''''' uCOMMAND_REGISTER '''''''''''''''
' see do_ROBOT_COMMAND()
''''''''''''''''''''''''''''''''''''''''

'''''' uSTATUS_REGISTER ''''''''''''''''
' bit#
'  0   - not zero when has new data in uDATA_REGISTER (not set yet).
'  1   - not zero when robot is busy doing some task.
'  2   - not zero when cannot move, zero on successful move.
''''''''''''''''''''''''''''''''''''''''

'===========================================


Public b_SHOWN_FIRST_TIME As Boolean

Const pic_WIDTH = 32
Const pic_HEIGHT = 32
Const map_RIGHT_BORDER = 8
Const map_BOTTOM_BORDER = 5

Const PIC_EMPTY = 500

Dim iROBOT_X As Integer
Dim iROBOT_Y As Integer
Dim iROBOT_DIRECTION As Integer ' direction in degrees (0..360).

' should be set by setBUSY_ON() / setBUSY_OFF() only:
Dim bROBOT_BUSY As Boolean

' for smooth moving of the robot:
Dim fSTART_MOVE_X As Single
Dim fSTART_MOVE_Y As Single
Dim fEND_MOVE_X As Single
Dim fEND_MOVE_Y As Single


Dim theMAP(0 To map_RIGHT_BORDER, 0 To map_BOTTOM_BORDER) As Byte

Dim uCurrentTool As Byte

Const ID_ROBOT_0 = 1
Const ID_ROBOT_90 = 2
Const ID_ROBOT_180 = 3
Const ID_ROBOT_270 = 4

Const ID_WALL = 7

Const ID_LAMP_ON = 10
Const ID_LAMP_OFF = 11

Const ID_EMPTY = 0

Const TOOL_NOT_SELECTED = 255


Private Sub Form_Load()
    
    
'    ' do not allow more than one copy of this program to run simuateniously
    If App.PrevInstance Then

        ShowPrevInstance

        End   ' terminate this instance!

    End If

    
    Dim iX As Integer
    Dim iY As Integer
    
    
    GetWindowPos Me
        
    reset_DEVICE
    
   
    ' load existing map (if any), or set default map:
    load_MAP
    
    ' tool not defined yet!
    uCurrentTool = TOOL_NOT_SELECTED
    
    
    If allow_on_top() Then set_on_top Me
    
End Sub

Public Sub reset_DEVICE()

    timer_Do_ROBOT_MOVE.Enabled = False
    timer_COMPLETE_LEFT.Enabled = False
    timer_COMPLETE_RIGHT.Enabled = False

    setBUSY_OFF

    uCOMMAND_REGISTER = 0
    uDATA_REGISTER = 0
    uSTATUS_REGISTER = 0
    
   
    redraw_MAP
    
    
    update_DEVICE
    
End Sub

Public Sub update_DEVICE()
    
    update_picStatus
    
End Sub











Private Sub update_picStatus()
    On Error GoTo err_fp

    Dim sBBYTE As String
    Dim uBIT_POS As Byte
    Dim f1 As Single
    
    Const sCaptionBits = "76543210"
    
    Const sCOMMAND = "command: "  ' the longest (from other captions).
    Const sData = "data: "
    Const sSTATUS = "status:"
    
    
    picStatus.CurrentX = picStatus.TextWidth(sCOMMAND)
    picStatus.CurrentY = 50
    
    picStatus.ForeColor = RGB(100, 100, 100)
    picStatus.Print sCaptionBits;
    
    picStatus.ForeColor = vbBlack
    picStatus.Print " port"
    
    ''''''''''''' command ''''''''''''''''''''''''''''''''''''''''''
    sBBYTE = toBIN_BYTE(uCOMMAND_REGISTER)
    
    picStatus.CurrentX = 0
    picStatus.CurrentY = 50 + picStatus.TextHeight(sCaptionBits)
    picStatus.ForeColor = RGB(100, 100, 100)
    picStatus.Print sCOMMAND
    
    picStatus.CurrentX = picStatus.TextWidth(sCOMMAND) ' the longest caption.
    picStatus.CurrentY = 50 + picStatus.TextHeight(sCaptionBits)
                
    print_bits sBBYTE
    
    picStatus.ForeColor = vbBlack
    picStatus.Print "   9";
    ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    
    ''''''''''''' data ''''''''''''''''''''''''''''''''''''''''''
    sBBYTE = toBIN_BYTE(uDATA_REGISTER)
    
    picStatus.CurrentX = 0
    picStatus.CurrentY = 50 + picStatus.TextHeight(sCaptionBits) * 2
    picStatus.ForeColor = RGB(100, 100, 100)
    picStatus.Print sData
    
    picStatus.CurrentX = picStatus.TextWidth(sCOMMAND) ' the longest caption.
    picStatus.CurrentY = 50 + picStatus.TextHeight(sCaptionBits) * 2
                
    print_bits sBBYTE
    
    picStatus.ForeColor = vbBlack
    picStatus.Print "  10";
    ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    
    ''''''''''''' status ''''''''''''''''''''''''''''''''''''''''''
    sBBYTE = toBIN_BYTE(uSTATUS_REGISTER)
    
    picStatus.CurrentX = 0
    picStatus.CurrentY = 50 + picStatus.TextHeight(sCaptionBits) * 3
    picStatus.ForeColor = RGB(100, 100, 100)
    picStatus.Print sSTATUS
    
    picStatus.CurrentX = picStatus.TextWidth(sCOMMAND) ' the longest caption.
    picStatus.CurrentY = 50 + picStatus.TextHeight(sCaptionBits) * 3
                
    print_bits sBBYTE
    
    picStatus.ForeColor = vbBlack
    picStatus.Print "  11";
    ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
    
    
    io.WRITE_IO_BYTE 11, uSTATUS_REGISTER
    
    
    Exit Sub
    
err_fp:
    Debug.Print "picStatus_Paint: " & Err.Description
    
End Sub


Private Sub print_bits(sBBYTE As String)
    
    Dim s As String
    Dim i As Long
    
    For i = 1 To 8
        s = Mid(sBBYTE, i, 1)
        If s = "0" Then
            picStatus.ForeColor = vbBlue
        Else
            picStatus.ForeColor = vbRed
        End If
        picStatus.Print s;
    Next i
    
End Sub



Private Sub do_ROBOT_COMMAND()

    If bROBOT_BUSY Then Exit Sub ' cannot be (because check is done before call).

    
    setBUSY_ON
    
    set_STATUS_CMD_SUCCESS  ' if required set to error.
    
    DoEvents ' allow redraw the status.

    Select Case uCOMMAND_REGISTER
    
    Case 0  ' nothing.

    Case 1  ' move.
        move_ROBOT
        Exit Sub  ' required to keep bROBOT_BUSY = True
         
    Case 2  ' turn left.
    
    
        ' bug fix 2004-09-23
        Select Case iROBOT_DIRECTION + 90
        Case 0:
        theMAP(iROBOT_X, iROBOT_Y) = ID_ROBOT_0
        Case 90:
        theMAP(iROBOT_X, iROBOT_Y) = ID_ROBOT_90
        Case 180:
        theMAP(iROBOT_X, iROBOT_Y) = ID_ROBOT_180
        Case 270:
        theMAP(iROBOT_X, iROBOT_Y) = ID_ROBOT_270
        End Select
    
    
        iROBOT_DIRECTION = iROBOT_DIRECTION + 45
        iROBOT_DIRECTION = make_Valid_Angle(iROBOT_DIRECTION) ' 1.26#330
        redraw_ROBOT
        timer_COMPLETE_LEFT.Enabled = True
                
        Exit Sub  ' required to keep bROBOT_BUSY = True
        
    Case 3  ' turn right.
    
    
        ' bug fix 2004-09-23
        Select Case iROBOT_DIRECTION - 90
        Case 0:
        theMAP(iROBOT_X, iROBOT_Y) = ID_ROBOT_0
        Case 90:
        theMAP(iROBOT_X, iROBOT_Y) = ID_ROBOT_90
        Case 180:
        theMAP(iROBOT_X, iROBOT_Y) = ID_ROBOT_180
        Case 270:
        theMAP(iROBOT_X, iROBOT_Y) = ID_ROBOT_270
        End Select
            
        iROBOT_DIRECTION = iROBOT_DIRECTION - 45
        iROBOT_DIRECTION = make_Valid_Angle(iROBOT_DIRECTION) ' 1.26#330
        redraw_ROBOT
        timer_COMPLETE_RIGHT.Enabled = True
        
        Exit Sub  ' required to keep bROBOT_BUSY = True
        
    Case 4  ' examine!
        robot_EXAMINE ' assumed that examine is fast enough.
    
    
    Case 5 ' switch on a lamp.
        robot_SWITCH_LAMP True ' takes no time.
    
    Case 6 ' switch off a lamp.
        robot_SWITCH_LAMP False ' takes no time.
        
    
    Case Else
        set_STATUS_CMD_ERROR
        Debug.Print "wrong command for robot: " & uCOMMAND_REGISTER
    
    End Select
   
    setBUSY_OFF
    
End Sub



Private Sub Form_Unload(Cancel As Integer)
    
    SaveWindowState Me
    
    save_MAP
    
End Sub

Private Sub timer_COMPLETE_LEFT_Timer()
    iROBOT_DIRECTION = iROBOT_DIRECTION + 45
    
    iROBOT_DIRECTION = make_Valid_Angle(iROBOT_DIRECTION)
    
    redraw_ROBOT
    timer_COMPLETE_LEFT.Enabled = False
    
    setBUSY_OFF
End Sub

Private Sub timer_COMPLETE_RIGHT_Timer()
    iROBOT_DIRECTION = iROBOT_DIRECTION - 45
    
    iROBOT_DIRECTION = make_Valid_Angle(iROBOT_DIRECTION)
    
    redraw_ROBOT
    timer_COMPLETE_RIGHT.Enabled = False
    
    setBUSY_OFF
End Sub


Private Sub move_ROBOT()
On Error GoTo err_mr

    Dim tX As Integer
    Dim tY As Integer
    
    tX = iROBOT_X
    tY = iROBOT_Y
    
    Select Case iROBOT_DIRECTION
    
    Case 0, 360
        tX = tX + 1
        
    Case 90
        tY = tY - 1
        
    Case 180
        tX = tX - 1
        
    Case 270
        tY = tY + 1
        
    End Select
    
    
    If tX > map_RIGHT_BORDER Then
        set_STATUS_CMD_ERROR
        setBUSY_OFF
        Exit Sub
    End If
    
    If tY < 0 Then
        set_STATUS_CMD_ERROR
        setBUSY_OFF
        Exit Sub
    End If
    
    If tX < 0 Then
        set_STATUS_CMD_ERROR
        setBUSY_OFF
        Exit Sub
    End If
        
    If tY > map_BOTTOM_BORDER Then
        set_STATUS_CMD_ERROR
        setBUSY_OFF
        Exit Sub
    End If
        
        
    ' check for an obstacle!
    If theMAP(tX, tY) <> 0 Then
        set_STATUS_CMD_ERROR
        setBUSY_OFF
        Exit Sub
    End If

    
    smooth_ROBOT_MOVE tX, tY
    
    Exit Sub
err_mr:
    Debug.Print "move_ROBOT: " & Err.Description
    
End Sub

' receves logical coordinates:
Private Sub smooth_ROBOT_MOVE(i_to_X As Integer, i_to_Y As Integer)

fSTART_MOVE_X = iROBOT_X * pic_WIDTH
fSTART_MOVE_Y = iROBOT_Y * pic_HEIGHT

fEND_MOVE_X = i_to_X * pic_WIDTH
fEND_MOVE_Y = i_to_Y * pic_HEIGHT

' updated before actual move completes:
move_ROBOT_to i_to_X, i_to_Y, False, degrees_to_ROBOT_ID(iROBOT_DIRECTION)

timer_Do_ROBOT_MOVE.Enabled = True

End Sub


Private Sub timer_Do_ROBOT_MOVE_Timer()

' if start coordinates equal
' to end, then the move ends:
If fSTART_MOVE_X = fEND_MOVE_X Then
    If fSTART_MOVE_Y = fEND_MOVE_Y Then
        timer_Do_ROBOT_MOVE.Enabled = False
        setBUSY_OFF
        Exit Sub
    End If
End If

draw_PIC PIC_EMPTY, fSTART_MOVE_X, fSTART_MOVE_Y

If fSTART_MOVE_X < fEND_MOVE_X Then fSTART_MOVE_X = fSTART_MOVE_X + 1

If fSTART_MOVE_X > fEND_MOVE_X Then fSTART_MOVE_X = fSTART_MOVE_X - 1

If fSTART_MOVE_Y < fEND_MOVE_Y Then fSTART_MOVE_Y = fSTART_MOVE_Y + 1

If fSTART_MOVE_Y > fEND_MOVE_Y Then fSTART_MOVE_Y = fSTART_MOVE_Y - 1

draw_PIC iROBOT_DIRECTION, fSTART_MOVE_X, fSTART_MOVE_Y


End Sub


Private Sub redraw_ROBOT()
    draw_PIC_at_logical_coord iROBOT_DIRECTION, iROBOT_X, iROBOT_Y
End Sub

Private Sub hide_ROBOT()
    draw_PIC_at_logical_coord PIC_EMPTY, iROBOT_X, iROBOT_Y
End Sub

' draws picture at logical coordinates:
Private Sub draw_PIC_at_logical_coord(iPIC_ID As Integer, at_X As Integer, at_Y As Integer)
    Dim fX As Single
    Dim fY As Single
    
    
    fX = at_X * pic_WIDTH
    fY = at_Y * pic_HEIGHT
    
    draw_PIC iPIC_ID, fX, fY
        
End Sub

' draws picture at physical coordinates:
Private Sub draw_PIC(iPIC_ID As Integer, fX As Single, fY As Single)
    Dim i As Integer
    
    For i = pics.LBound To pics.UBound
        If Val(pics(i).Tag) = iPIC_ID Then
            picTL.PaintPicture pics(i).Picture, fX, fY
            Exit Sub
        End If
    Next i
End Sub


Private Sub setBUSY_ON()
    bROBOT_BUSY = True
    
    uSTATUS_REGISTER = uSTATUS_REGISTER Or 2 ' set bit 000000010.
    update_picStatus
End Sub

Private Sub setBUSY_OFF()
    bROBOT_BUSY = False
    
    uSTATUS_REGISTER = uSTATUS_REGISTER And 253 ' clear bit 000000010.
    update_picStatus
End Sub


Private Sub set_STATUS_CMD_SUCCESS()
    uSTATUS_REGISTER = uSTATUS_REGISTER And 251 ' clear bit 000000100.
    update_picStatus
End Sub

Private Sub set_STATUS_CMD_ERROR()
    uSTATUS_REGISTER = uSTATUS_REGISTER Or 4 ' set bit 000000100.
    update_picStatus
End Sub


Private Sub set_STATUS_DATA_READY()
    uSTATUS_REGISTER = uSTATUS_REGISTER Or 1 ' set bit 000000001.
    update_picStatus
End Sub

'Private Sub set_STATUS_DATA_OLD()
'    uSTATUS_REGISTER = uSTATUS_REGISTER And 254 ' clear bit 000000001.
'    update_picStatus
'End Sub




Private Sub picTL_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)
On Error GoTo err_tlmm

    Dim fX As Single
    Dim fY As Single

    fX = X - (X Mod pic_WIDTH)
    fY = Y - (Y Mod pic_HEIGHT)
    
    shapePOSITIONER.Move fX, fY

    If Not shapePOSITIONER.Visible Then shapePOSITIONER.Visible = True

    timerHide_Positioner.Enabled = True

    Exit Sub
err_tlmm:
    Debug.Print "picTL_MouseMove: " & Err.Description
End Sub

Private Sub Form_MouseMove(Button As Integer, Shift As Integer, X As Single, Y As Single)

    If shapePOSITIONER.Visible Then shapePOSITIONER.Visible = False

End Sub

Private Sub timerHide_Positioner_Timer()

    If shapePOSITIONER.Visible Then shapePOSITIONER.Visible = False

    timerHide_Positioner.Enabled = False
End Sub


' 1.27#348
Private Sub picTL_MouseDown(Button As Integer, Shift As Integer, X As Single, Y As Single)
    
On Error GoTo err_pmd


    If Button = vbRightButton Then
        PopupMenu popMapUpMenu
        Exit Sub
    End If


    ' 1.27#351
    If uCurrentTool = TOOL_NOT_SELECTED Then
        ' tool not defined yet!
        Exit Sub
    End If


    ' just to make it better:
    If Not bROBOT_BUSY Then
        lblMessage.Caption = ""
    Else
        lblMessage.Caption = "MOVING!"
        Exit Sub
    End If

    Dim fX As Single
    Dim fY As Single
    
    Dim logicX As Integer
    Dim logicY As Integer
    
    Dim uTool As Byte
    
    

    
    fX = X - (X Mod pic_WIDTH)
    fY = Y - (Y Mod pic_HEIGHT)
    
    
    logicX = fX / pic_WIDTH
    logicY = fY / pic_HEIGHT
    
    
    ' if the same object is placed over, then the delete it,
    ' or if it's robot just change the direction,
    ' if it's a lamp just turn it on off, and only then delete:
    If equal_to_ID(theMAP(logicX, logicY), uCurrentTool) Then
    
        If equal_to_ID(uCurrentTool, ID_ROBOT_0) Then
        
            ' rotate the robot:
            Select Case theMAP(logicX, logicY)
            Case ID_ROBOT_0
                uTool = ID_ROBOT_90
            Case ID_ROBOT_90
                uTool = ID_ROBOT_180
            Case ID_ROBOT_180
                uTool = ID_ROBOT_270
            Case ID_ROBOT_270
                uTool = ID_ROBOT_0
            End Select
        
        ElseIf equal_to_ID(uCurrentTool, ID_LAMP_ON) Then
        
            Select Case theMAP(logicX, logicY)
            Case ID_LAMP_ON
                uTool = ID_LAMP_OFF
            Case ID_LAMP_OFF
                uTool = ID_EMPTY   ' delete.
            End Select
        
        Else
            uTool = ID_EMPTY
        End If
    Else
        uTool = uCurrentTool
    End If


    theMAP(logicX, logicY) = uTool


    Select Case uTool
    
    Case ID_ROBOT_0
        move_ROBOT_to fX / pic_WIDTH, fY / pic_HEIGHT, True, uTool
        iROBOT_DIRECTION = 0
        draw_PIC iROBOT_DIRECTION, fX, fY
        
    Case ID_ROBOT_90
        move_ROBOT_to fX / pic_WIDTH, fY / pic_HEIGHT, True, uTool
        iROBOT_DIRECTION = 90
        draw_PIC iROBOT_DIRECTION, fX, fY
        
    Case ID_ROBOT_180
        move_ROBOT_to fX / pic_WIDTH, fY / pic_HEIGHT, True, uTool
        iROBOT_DIRECTION = 180
        draw_PIC iROBOT_DIRECTION, fX, fY
        
    Case ID_ROBOT_270
        move_ROBOT_to fX / pic_WIDTH, fY / pic_HEIGHT, True, uTool
        iROBOT_DIRECTION = 270
        draw_PIC iROBOT_DIRECTION, fX, fY
        
    Case ID_WALL
        picTL.PaintPicture picTools(1).Picture, fX, fY
        
    Case ID_LAMP_ON
        picTL.PaintPicture picTools(2).Picture, fX, fY
    
    Case ID_LAMP_OFF
        picTL.PaintPicture picLAMP_OFF.Picture, fX, fY
        
    Case ID_EMPTY
        draw_PIC PIC_EMPTY, fX, fY
    
    Case Else
        Exit Sub ' tool not selected
    
    End Select



        
    Exit Sub
err_pmd:
    Debug.Print "Robot: picTL_MouseDown: " & Err.Description
End Sub


Private Sub selectTOOL(Index As Integer)
On Error GoTo err_st

    Dim i As Integer
    
    For i = picTools.LBound To picTools.UBound
        If Index = i Then
            picTools(i).BorderStyle = vbFixedSingle
        Else
            picTools(i).BorderStyle = 0
        End If
    Next i
    
    Exit Sub
err_st:
End Sub

Private Sub picTools_Click(Index As Integer)
On Error GoTo err_tc

    
    selectTOOL Index
    

    Select Case picTools(Index).Tag
    
    Case "ROBOT"
        If uCurrentTool = ID_ROBOT_0 Then
            select_ERASER
        Else
            uCurrentTool = ID_ROBOT_0
        End If
    
    Case "WALL"
        If uCurrentTool = ID_WALL Then
            select_ERASER
        Else
            uCurrentTool = ID_WALL
        End If
    
    Case "LAMP"
        If uCurrentTool = ID_LAMP_ON Then
            select_ERASER
        Else
            uCurrentTool = ID_LAMP_ON
        End If
        
    End Select
    
    
    Exit Sub
    
err_tc:
    Debug.Print "picTools_Click: " & Err.Description
End Sub

Private Sub select_ERASER()
    uCurrentTool = ID_EMPTY
    selectTOOL -1
End Sub

Private Sub Form_Click()
    select_ERASER
End Sub

Private Sub lblMessage_Click()
    Form_Click
End Sub


Private Sub redraw_MAP()
On Error GoTo err_rm

' doesn't help!
' even if autoredraw is set to true...
'''    ' 2.04#531
'''    Dim l As Long
'''    l = frmMain.picForRobotBGCOLOR.Point(0, 0)
'''    picTL.BackColor = l
'''    Debug.Print "bgcolor: " & l


    picTL.Cls

    Dim iX As Integer
    Dim iY As Integer
    
    Dim uID As Byte
    
    
    For iY = 0 To map_BOTTOM_BORDER
        For iX = 0 To map_RIGHT_BORDER
            
            uID = theMAP(iX, iY)
            
            Select Case uID
            
            Case ID_ROBOT_0
                move_ROBOT_to iX, iY, False, uID
                iROBOT_DIRECTION = 0
                draw_PIC iROBOT_DIRECTION, iX * pic_WIDTH, iY * pic_HEIGHT
                
            
            Case ID_ROBOT_90
                move_ROBOT_to iX, iY, False, uID
                iROBOT_DIRECTION = 90
                draw_PIC iROBOT_DIRECTION, iX * pic_WIDTH, iY * pic_HEIGHT
                                
            Case ID_ROBOT_180
                move_ROBOT_to iX, iY, False, uID
                iROBOT_DIRECTION = 180
                draw_PIC iROBOT_DIRECTION, iX * pic_WIDTH, iY * pic_HEIGHT
                                                        
            Case ID_ROBOT_270
                move_ROBOT_to iX, iY, False, uID
                iROBOT_DIRECTION = 270
                draw_PIC iROBOT_DIRECTION, iX * pic_WIDTH, iY * pic_HEIGHT
                                                                                  
                                
            Case ID_WALL
                picTL.PaintPicture picTools(1).Picture, iX * pic_WIDTH, iY * pic_HEIGHT
                
            Case ID_LAMP_ON
                picTL.PaintPicture picTools(2).Picture, iX * pic_WIDTH, iY * pic_HEIGHT
                
            Case ID_LAMP_OFF
                picTL.PaintPicture picLAMP_OFF.Picture, iX * pic_WIDTH, iY * pic_HEIGHT
                
                
            End Select
            
        Next iX
    Next iY
    

    Exit Sub
err_rm:
    Debug.Print "frmDEVICE_Robot: redraw_MAP: " & Err.Description
End Sub



Private Sub if_ROBOT_EXISTS_REMOVE(bDRAW_EMPTY As Boolean)
On Error GoTo err_rm

    Dim iX As Integer
    Dim iY As Integer
    
    For iY = 0 To map_BOTTOM_BORDER
        For iX = 0 To map_RIGHT_BORDER
            
            If equal_to_ID(theMAP(iX, iY), ID_ROBOT_0) Then
                theMAP(iX, iY) = 0
                If bDRAW_EMPTY Then
                    draw_PIC_at_logical_coord PIC_EMPTY, iX, iY
                End If
            End If
            
        Next iX
    Next iY
    

    Exit Sub
err_rm:
    Debug.Print "if_ROBOT_EXISTS_REMOVE: " & Err.Description
End Sub


Private Sub move_ROBOT_to(iX As Integer, iY As Integer, bClearPrevPos As Boolean, uROBOT_ID As Byte)
On Error GoTo err_mrt

    if_ROBOT_EXISTS_REMOVE bClearPrevPos
    
    iROBOT_X = iX
    iROBOT_Y = iY
    
    theMAP(iX, iY) = uROBOT_ID
    
    Exit Sub
err_mrt:
    Debug.Print "move_robot_to: " & Err.Description
End Sub


Private Function equal_to_ID(iTool As Byte, iID As Byte) As Boolean
    
On Error GoTo err_eti

    ' wall and some unic case of robot/lamp group:
    If iTool = iID Then
            equal_to_ID = True
            Exit Function
    End If
    
    
    ' robot group:
    If (iTool >= ID_ROBOT_0) And (iTool <= ID_ROBOT_270) Then
        If (iID >= ID_ROBOT_0) And (iID <= ID_ROBOT_270) Then
            equal_to_ID = True
            Exit Function
        Else
            equal_to_ID = False
            Exit Function
        End If
    End If
    
    ' lamp group:
    If (iTool >= ID_LAMP_ON) And (iTool <= ID_LAMP_OFF) Then
        If (iID >= ID_LAMP_ON) And (iID <= ID_LAMP_OFF) Then
            equal_to_ID = True
            Exit Function
        Else
            equal_to_ID = False
            Exit Function
        End If
    End If
    
    Exit Function
err_eti:
    Debug.Print "equal_to_ID: " & Err.Description
    equal_to_ID = False
End Function


Private Function degrees_to_ROBOT_ID(iDegrees As Integer) As Byte
    
    Select Case iDegrees
    
    Case 0
        degrees_to_ROBOT_ID = ID_ROBOT_0
        
    Case 90
        degrees_to_ROBOT_ID = ID_ROBOT_90
        
    Case 180
        degrees_to_ROBOT_ID = ID_ROBOT_180
        
    Case 270
        degrees_to_ROBOT_ID = ID_ROBOT_270
        
    Case Else
        degrees_to_ROBOT_ID = ID_ROBOT_0
        Debug.Print "degrees_to_ROBOT_ID: " & iDegrees
        
    End Select

End Function


Private Sub robot_EXAMINE()

On Error GoTo err_re

Dim uID As Byte

uID = getObject_in_Front_of_Robot

Select Case uID

Case ID_WALL
    uDATA_REGISTER = 255
    
Case ID_LAMP_ON
    uDATA_REGISTER = 7

Case ID_LAMP_OFF
    uDATA_REGISTER = 8

Case ID_EMPTY
    uDATA_REGISTER = 0

Case Else
    Debug.Print "robot_EXAMINE: unknown uID?"
    uDATA_REGISTER = 0
End Select

    io.WRITE_IO_BYTE 10, uDATA_REGISTER

    set_STATUS_DATA_READY

Exit Sub
err_re:
    Debug.Print "robot_EXAMINE: " & Err.Description
End Sub


Private Sub robot_SWITCH_LAMP(bSWITCH_ON As Boolean)

On Error GoTo err_swl

Dim uID As Byte

uID = getObject_in_Front_of_Robot

If bSWITCH_ON Then

    Select Case uID
    Case ID_LAMP_ON
        set_STATUS_CMD_ERROR ' already on!
            
    Case ID_LAMP_OFF
        setObject_in_Front_of_Robot ID_LAMP_ON
    
    Case Else
        set_STATUS_CMD_ERROR ' not a lamp!
    End Select
    
Else

    Select Case uID
    Case ID_LAMP_ON
        setObject_in_Front_of_Robot ID_LAMP_OFF
    
    Case ID_LAMP_OFF
        set_STATUS_CMD_ERROR ' already off!
    
    Case Else
        set_STATUS_CMD_ERROR ' not a lamp!
    End Select

End If

redraw_MAP

Exit Sub
err_swl:
    Debug.Print "robot_SWITCH_LAMP: " & Err.Description
End Sub


Private Function getObject_in_Front_of_Robot() As Byte
Dim iX As Integer
Dim iY As Integer


iX = iROBOT_X
iY = iROBOT_Y

Select Case iROBOT_DIRECTION

Case 0
    iX = iX + 1
    
Case 90
    iY = iY - 1
    
Case 180
    iX = iX - 1
    
Case 270
    iY = iY + 1
    
End Select


If (iX < 0) Or (iY < 0) Or _
   (iX > map_RIGHT_BORDER) Or (iY > map_BOTTOM_BORDER) Then
   
    getObject_in_Front_of_Robot = ID_WALL
    
Else

    getObject_in_Front_of_Robot = theMAP(iX, iY)
    
End If

End Function


Private Sub setObject_in_Front_of_Robot(uOBJ_ID As Byte)
Dim iX As Integer
Dim iY As Integer


iX = iROBOT_X
iY = iROBOT_Y

Select Case iROBOT_DIRECTION

Case 0
    iX = iX + 1
    
Case 90
    iY = iY - 1
    
Case 180
    iX = iX - 1
    
Case 270
    iY = iY + 1
    
End Select


If (iX < 0) Or (iY < 0) Or _
   (iX > map_RIGHT_BORDER) Or (iY > map_BOTTOM_BORDER) Then
   
    Debug.Print "setObject_in_Front_of_Robot: out of the map?"
    
Else

    theMAP(iX, iY) = uOBJ_ID
    
End If

End Sub


Private Sub load_MAP()
On Error GoTo err_lm

    Dim iX As Integer
    Dim iY As Integer

    Dim sFileName As String
    Dim gFileNumber As Integer
    
    Dim tb As Byte
    
    sFileName = Add_BackSlash(App.Path) & "robot_map.dat"


    If Not FileExists(sFileName) Then
       make_Default_MAP
       Exit Sub ' nothing to load.
    End If


    gFileNumber = FreeFile

    Open sFileName For Random As gFileNumber Len = 1
    
    For iY = 0 To map_BOTTOM_BORDER
        For iX = 0 To map_RIGHT_BORDER
            Get gFileNumber, , tb
            theMAP(iX, iY) = tb
        Next iX
    Next iY
    
    Close gFileNumber
    
    
    redraw_MAP
    
    
    'Debug.Print "robot map loaded!"
    

    Exit Sub
err_lm:
    Debug.Print "load_MAP: " & Err.Description
End Sub

Public Sub save_MAP()
On Error GoTo err_sm

    Dim iX As Integer
    Dim iY As Integer

    Dim sFileName As String
    Dim gFileNumber As Integer

    sFileName = Add_BackSlash(App.Path) & "robot_map.dat"
        
        
    ' delete the old file (if exists):
    If FileExists(sFileName) Then
        Kill sFileName
    End If


    gFileNumber = FreeFile

    Open sFileName For Random As gFileNumber Len = 1
    
    For iY = 0 To map_BOTTOM_BORDER
        For iX = 0 To map_RIGHT_BORDER
            Put gFileNumber, , theMAP(iX, iY)
        Next iX
    Next iY
    
    Close gFileNumber
    
    'Debug.Print "robot map saved!"
    
    
    Exit Sub
err_sm:
    Debug.Print "save_MAP: " & Err.Description
    Close gFileNumber
End Sub

Private Sub make_Default_MAP()
On Error GoTo err_mdm

    Dim iX As Integer
    Dim iY As Integer
    
    ' clear the map:
    For iY = 0 To map_BOTTOM_BORDER
        For iX = 0 To map_RIGHT_BORDER
            theMAP(iX, iY) = 0
        Next iX
    Next iY
    
    
    theMAP(3, 3) = ID_ROBOT_90
    
    theMAP(7, 0) = ID_LAMP_OFF
    theMAP(1, 1) = ID_LAMP_OFF
    theMAP(7, 0) = ID_LAMP_OFF
    theMAP(0, 2) = ID_LAMP_OFF
    theMAP(7, 4) = ID_LAMP_OFF
    
    theMAP(4, 1) = ID_WALL
    theMAP(8, 1) = ID_WALL
    theMAP(2, 4) = ID_WALL
    
    redraw_MAP
    
    
    Exit Sub
err_mdm:
    Debug.Print "make_Default_MAP: " & Err.Description
    
End Sub




Private Sub mnuSwitchOffAllLamps_Click()

    Dim iX As Integer
    Dim iY As Integer
    
    For iY = 0 To map_BOTTOM_BORDER
        For iX = 0 To map_RIGHT_BORDER
            If theMAP(iX, iY) = ID_LAMP_ON Then
                theMAP(iX, iY) = ID_LAMP_OFF
            End If
        Next iX
    Next iY
    
    redraw_MAP
     
End Sub

Private Sub mnuSwitchOnAllLamps_Click()
    Dim iX As Integer
    Dim iY As Integer
    
    For iY = 0 To map_BOTTOM_BORDER
        For iX = 0 To map_RIGHT_BORDER
            If theMAP(iX, iY) = ID_LAMP_OFF Then
                theMAP(iX, iY) = ID_LAMP_ON
            End If
        Next iX
    Next iY
    
    redraw_MAP
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



Function Add_BackSlash(sPath As String) As String
  
    If (sPath <> "") Then
        If (Mid(sPath, Len(sPath), 1) <> "\") Then
          Add_BackSlash = sPath & "\"
          Exit Function
        End If
    End If
 
 
    Add_BackSlash = sPath
  
End Function


Function FileExists(ByVal sFileName As String) As Boolean

    Dim i As Integer
    
    On Error GoTo NotFound
    
    i = GetAttr(sFileName)
        
    FileExists = True
    
    Exit Function
    
NotFound:

    FileExists = False
    
End Function


' receives any angle -32768...32767, and returns 0...359
Function make_Valid_Angle(iAnyAngle As Integer) As Integer
On Error GoTo err_make_va

Dim i As Integer

If (iAnyAngle >= 0) And (iAnyAngle < 360) Then
    
    make_Valid_Angle = iAnyAngle ' no need to correct.

Else

    If iAnyAngle > 0 Then
    
        i = iAnyAngle Mod 360
    
        make_Valid_Angle = i
    
    Else
    
        i = Abs(iAnyAngle) Mod 360
    
        make_Valid_Angle = 360 - i
        
    End If

End If

Exit Function

err_make_va:
    Debug.Print "make_Valid_Angle: " & iAnyAngle & ": " & Err.Description
    make_Valid_Angle = 0
    
End Function



Private Sub timerPortReader_Timer()

    Dim byteT As Byte
    
    byteT = io.READ_IO_BYTE(9)
    If uCOMMAND_REGISTER <> byteT Then
        setCOMMAND byteT
        If shall_activate(Me) Then Me.Show
    End If
    
End Sub




' port 9
Private Sub setCOMMAND(uBYTE As Byte)

    
    If bROBOT_BUSY Then
        lblMessage.Caption = "BUSY!"
        set_STATUS_CMD_ERROR ' set error.
        ' Debug.Print "Cannot do command - I'm busy!"
    Else
        lblMessage.Caption = ""
        uCOMMAND_REGISTER = uBYTE
        do_ROBOT_COMMAND
    End If
    
    update_DEVICE
    
End Sub

