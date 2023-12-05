VERSION 5.00
Begin VB.Form frmThermometer 
   AutoRedraw      =   -1  'True
   BackColor       =   &H00FFFFFF&
   BorderStyle     =   1  'Fixed Single
   Caption         =   "thermometer & heater - io device"
   ClientHeight    =   7995
   ClientLeft      =   90
   ClientTop       =   375
   ClientWidth     =   4935
   BeginProperty Font 
      Name            =   "Tahoma"
      Size            =   9.75
      Charset         =   0
      Weight          =   700
      Underline       =   0   'False
      Italic          =   0   'False
      Strikethrough   =   0   'False
   EndProperty
   Icon            =   "frmThermometer.frx":0000
   LinkTopic       =   "Form1"
   MaxButton       =   0   'False
   Picture         =   "frmThermometer.frx":0442
   ScaleHeight     =   533
   ScaleMode       =   3  'Pixel
   ScaleWidth      =   329
   Begin VB.Timer TimerPort127Check 
      Interval        =   20
      Left            =   4380
      Top             =   6585
   End
   Begin VB.Timer TimerAnimation 
      Interval        =   500
      Left            =   2865
      Top             =   4755
   End
   Begin VB.TextBox txtAirTemperature 
      Alignment       =   2  'Center
      BeginProperty Font 
         Name            =   "Fixedsys"
         Size            =   9
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   360
      Left            =   2805
      MaxLength       =   4
      TabIndex        =   5
      Text            =   "0"
      Top             =   4065
      Width           =   1290
   End
   Begin VB.CommandButton cmdOnOff 
      Caption         =   "On"
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      Height          =   300
      Left            =   3540
      TabIndex        =   3
      Top             =   6600
      Width           =   555
   End
   Begin VB.Timer TimerTime 
      Interval        =   200
      Left            =   3780
      Top             =   4740
   End
   Begin VB.Label lblURL 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      Caption         =   "emu8086"
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   195
      Left            =   4080
      MouseIcon       =   "frmThermometer.frx":14C0
      MousePointer    =   99  'Custom
      TabIndex        =   7
      Top             =   7755
      Width           =   825
   End
   Begin VB.Label Label2 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      Caption         =   "designed for"
      BeginProperty Font 
         Name            =   "Tahoma"
         Size            =   8.25
         Charset         =   0
         Weight          =   700
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00404040&
      Height          =   195
      Left            =   2970
      TabIndex        =   6
      Top             =   7755
      Width           =   1065
   End
   Begin VB.Label Label1 
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      Caption         =   "air temperature:"
      ForeColor       =   &H00000000&
      Height          =   240
      Left            =   2595
      TabIndex        =   4
      Top             =   3720
      Width           =   1635
   End
   Begin VB.Label lblTemperature 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      Caption         =   "20 °"
      ForeColor       =   &H000000FF&
      Height          =   240
      Left            =   2220
      TabIndex        =   2
      Top             =   1185
      Width           =   420
   End
   Begin VB.Shape Column 
      BackColor       =   &H000000FF&
      BackStyle       =   1  'Opaque
      BorderColor     =   &H000000FF&
      FillColor       =   &H000000FF&
      Height          =   4725
      Left            =   645
      Top             =   1215
      Width           =   105
   End
   Begin VB.Shape FlameCover 
      BackStyle       =   1  'Opaque
      BorderColor     =   &H00FFFFFF&
      Height          =   795
      Left            =   315
      Top             =   6495
      Width           =   840
   End
   Begin VB.Label lblPort127 
      Alignment       =   2  'Center
      BackColor       =   &H00FFFFFF&
      Caption         =   "00000000"
      BeginProperty Font 
         Name            =   "Fixedsys"
         Size            =   9
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   225
      Left            =   3330
      TabIndex        =   1
      Top             =   5835
      Width           =   975
   End
   Begin VB.Label lblPort125 
      Alignment       =   2  'Center
      AutoSize        =   -1  'True
      BackColor       =   &H00FFFFFF&
      Caption         =   "00000000"
      BeginProperty Font 
         Name            =   "Fixedsys"
         Size            =   9
         Charset         =   0
         Weight          =   400
         Underline       =   0   'False
         Italic          =   0   'False
         Strikethrough   =   0   'False
      EndProperty
      ForeColor       =   &H00FF0000&
      Height          =   225
      Left            =   3360
      TabIndex        =   0
      Top             =   1170
      Width           =   975
   End
   Begin VB.Image imgFire 
      Height          =   795
      Left            =   315
      Picture         =   "frmThermometer.frx":17CA
      Top             =   6495
      Width           =   795
   End
End
Attribute VB_Name = "frmThermometer"
Attribute VB_GlobalNameSpace = False
Attribute VB_Creatable = False
Attribute VB_PredeclaredId = True
Attribute VB_Exposed = False
' thermometer and heater device for emu8086.

' feel free to e-mail if you have any questions:  info@emu8086.com

' copyright (c) emu8086.com

Option Explicit

Dim iTemperature As Integer                      ' Thermometer temperature.
Dim isFlame As Boolean                           ' "True" when fire is burning.

Dim bOLD_VALUE As Byte ' #1122d

Private Sub Form_Load()


    ' do not allow more than one copy of this program to run simuateniously
    If App.PrevInstance Then

        ShowPrevInstance

        End   ' terminate this instance!

    End If



    SetFlame True

    Set_Temperature Val(txtAirTemperature.Text)
        
        
    GetWindowPos Me
    
    If allow_on_top() Then set_on_top Me
    
    
End Sub

Private Sub SetFlame(b As Boolean)

    FlameCover.Visible = Not b
    isFlame = b
    
    If b Then
        cmdOnOff.Caption = "Off"
        TimerTime.Interval = 200
    Else
        cmdOnOff.Caption = "On"
        TimerTime.Interval = 1000
    End If
    
End Sub


Private Sub Form_Unload(Cancel As Integer)
    SaveWindowState Me
End Sub

Private Sub TimerTime_Timer()
    
     If isFlame Then
            Set_Temperature iTemperature + 1
     Else
        If iTemperature > Val(txtAirTemperature.Text) Then
            Set_Temperature iTemperature - 1
        End If
        
        If iTemperature < Val(txtAirTemperature.Text) Then
            Set_Temperature iTemperature + 1
        End If
     End If

End Sub

' makes an integer to be a BYTE (unsigned):
Function to_unsigned_byte(i As Integer) As Byte
    
    If i >= -128 And i <= 255 Then
        If i >= 0 Then
            to_unsigned_byte = i
        Else
            to_unsigned_byte = 256 + i
        End If
    Else
        to_unsigned_byte = 0
        Debug.Print "Wrong param calling to_unsigned_byte(): " & i
    End If
End Function

Sub Set_Temperature(iVal As Integer)

    ' Our termometer works in -65 to 120 °C range only!
    If iVal > 120 Or iVal < -65 Then Exit Sub

    iTemperature = iVal
    
    lblPort125.Caption = toBIN_BYTE(to_unsigned_byte(iTemperature))
    
    lblTemperature.Caption = iTemperature & " °"

    Dim iColumnValue As Integer
    iColumnValue = TemperatureToColumn(iTemperature)
    Column.Top = 81 + (315 - iColumnValue)
    Column.Height = iColumnValue
    
    ' Write to Emu8086 port #125:
    WRITE_IO_BYTE 125, to_unsigned_byte(iTemperature)
    
' HELPED US TO DRAW VALUES ON TERMOMETER
'    If iTemperature Mod 20 = 0 Then
'        PSet (130, Column.Top)
'    End If
    
End Sub

Function Make_Min_Len(s As String, minLen As Integer, sAddWhat As String) As String
    Dim i As Integer
    Dim sRes As String
    
    i = 0
    sRes = s
    
    While Len(sRes) < minLen
        sRes = sAddWhat & sRes
    Wend
    
    Make_Min_Len = sRes
    
End Function


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
    
    toBIN_BYTE = Make_Min_Len(sResult, 8, "0")
    
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

Function TemperatureToColumn(iTemp As Integer) As Integer

    Dim i As Integer
    
    Dim a As Variant
    a = Array(-65, -64.413, -63.826, -63.239, -62.652, -62.06499, -61.47799, -60.89099, -60.30399, -59.71699, -59.12999, -58.54298, -57.95598, -57.36898, -56.78198, -56.19498, -55.60798, -55.02097, -54.43397, -53.84697, -53.25997, -52.67297, -52.08596, -51.49896, -50.91196, -50.32496, -49.73796, -49.15096, -48.56395, -47.97695, -47.38995, -46.80295, -46.21595, -45.62894, -45.04194, -44.45494, -43.86794, -43.28094, -42.69394, -42.10693, -41.51993, -40.93293, -40.34593, -39.75893, -39.17192, -38.58492, -37.99792, -37.41092, -36.82392, -36.23692, -35.64991, -35.06291, -34.47591, -33.88891, -33.30191, -32.7149, -32.1279, -31.5409, -30.9539, -30.3669, -29.7799, -29.1929, -28.6059, -28.0189, -27.4319, -26.8449, -26.2579, -25.6709, -25.0839, -24.4969, -23.9099, -23.3229, -22.7359, -22.1489, -21.5619, -20.97491, -20.38791, -19.80091, -19.21391, -18.62691, -18.03991, -17.45291, -16.86591, -16.27891, -15.69191, -15.10491, -14.51791, -13.93091, -13.34391, -12.75691, _
                -12.16991, -11.58291, -10.99591, -10.40891, -9.821907, -9.234907, _
                -8.647907, -8.060907, -7.473907, -6.886908, -6.299908, -5.712908, -5.125908, -4.538908, -3.951908, -3.364908, -2.777908, -2.190908, _
                 -1.603908, -1.016908, -0.4299084, 0.1570916, 0.7440916, 1.331092, 1.918092, 2.505092, 3.092092, 3.679091, 4.266091, 4.853091, 5.440091, 6.027091, _
                6.614091, 7.201091, 7.788091, 8.375091, 8.96209, 9.54909, 10.13609, 10.72309, 11.31009, 11.89709, 12.48409, 13.07109, 13.65809, 14.24509, 14.83209, 15.41909, 16.00609, 16.59309, 17.18009, 17.76709, 18.35409, 18.94109, 19.52809, 20.11509, 20.70209, 21.28909, 21.87609, 22.46309, 23.05009, 23.63709, 24.22409, 24.81109, 25.39809, 25.98509, 26.57209, 27.15909, 27.74609, 28.33309, 28.92009, 29.50709, 30.09409, 30.68109, 31.26809, 31.85509, 32.44209, 33.02909, 33.61609, 34.20309, 34.7901, 35.3771, 35.9641, 36.5511, 37.1381, 37.72511, 38.31211, 38.89911, 39.48611, 40.07311, 40.66011, 41.24712, 41.83412, 42.42112, 43.00812, 43.59512, 44.18213, 44.76913, 45.35613, 45.94313, 46.53013, 47.11713, 47.70414, 48.29114, 48.87814, 49.46514, 50.05214, _
                50.63914, 51.22615, 51.81315, 52.40015, 52.98715, 53.57415, 54.16116, 54.74816, _
                 55.33516, 55.92216, 56.50916, 57.09616, 57.68317, 58.27017, 58.85717, 59.44417, 60.03117, 60.61818, 61.20518, 61.79218, 62.37918, 62.96618, 63.55318, 64.14018, 64.72718, 65.31418, 65.90118, 66.48817, 67.07517, 67.66217, 68.24917, 68.83617, 69.42316, 70.01016, 70.59716, 71.18416, 71.77116, 72.35815, 72.94515, 73.53215, 74.11915, 74.70615, 75.29314, 75.88014, 76.46714, 77.05414, 77.64114, 78.22813, 78.81513, 79.40213, 79.98913, 80.57613, 81.16312, 81.75012, 82.33712, 82.92412, 83.51112, 84.09811, 84.68511, 85.27211, 85.85911, 86.44611, 87.0331, 87.6201, 88.2071, 88.7941, 89.3811, 89.96809, 90.55509, 91.14209, 91.72909, 92.31609, 92.90308, 93.49008, 94.07708, 94.66408, 95.25108, 95.83807, 96.42507, 97.01207, 97.59907, 98.18607, 98.77306, 99.36006, 99.94706, 100.5341, 101.1211, 101.7081, 102.2951, 102.882, 103.469, 104.056, 104.643, 105.23, 105.817, 106.404, 106.991, 107.578, 108.165, 108.752, 109.339, 109.926, 110.513, 111.1, _
                111.687, 112.274, 112.861, 113.448, 114.035, 114.622, 115.209, 115.796, 116.383, _
                 116.97, 117.557, 118.144, 118.731, 119.318, 119.905, 120)

    For i = LBound(a) To UBound(a)
        If a(i) >= iTemp Then
            TemperatureToColumn = i
            Exit Function
        End If
    Next i
''
'    ' HELPED US TO CREATE TEMPARATURE TABLE -65 TO 120
'    ' VISIBLE VALUES (-40 to 120)
'    ' (120 + Abs(-65)) / 315 = 0.587
'    '  315 - maximum value for the column.
'    Dim k As Single
'    k = -65
'    For i = 0 To 315
'        Debug.Print k & ", ";
'        k = k + 0.587
'    Next i
'   End

End Function


Private Sub cmdOnOff_Click()
    
    ' Write to Emu8086 port #127:
    
    If isFlame Then
        WRITE_IO_BYTE 127, 0
    Else
        WRITE_IO_BYTE 127, 1
    End If
    
End Sub

Private Sub TimerAnimation_Timer()
    If isFlame Then
        imgFire.Visible = Not imgFire.Visible
    Else
        imgFire.Visible = False
    End If
End Sub

Private Sub TimerPort127Check_Timer()
On Error GoTo err1

    Dim m As Byte
    
    m = READ_IO_BYTE(127)
    
    If bOLD_VALUE <> m Then ' #1122d
        If shall_activate(Me) Then Me.Show
        bOLD_VALUE = m
    End If
    
    ' Checking lower bit:
    If (m And 1) Then
        SetFlame True
        lblPort127.ForeColor = vbRed
    Else
        SetFlame False
        lblPort127.ForeColor = vbBlue
    End If
    
    lblPort127.Caption = toBIN_BYTE(m)
    
    Exit Sub
err1:
    Debug.Print "err1"
    Resume Next
End Sub


Private Sub lblURL_Click()
On Error GoTo err1:
    Clipboard.Clear
    Clipboard.SetText "http://www.emu8086.com"
    Shell "Explorer http://www.emu8086.com", vbMaximizedFocus
    Exit Sub
err1:
    MsgBox "Copied to clipboard: http://www.emu8086.com"
End Sub

