Attribute VB_Name = "mWinState"
' this file belongs to emu8086 project...


Option Explicit

Const DEFAULT_min_width = 1500
Const DEFAULT_min_height = 1500

Global Const sTitleA = "emu8086"

Sub SaveWindowState(frm As Form)
On Error GoTo err_sws

    Dim sName As String
    
    sName = frm.Name
    
    If (frm.WindowState <> vbMinimized) And (frm.WindowState <> vbMaximized) Then
    
        SaveSetting sTitleA, "WinStates", sName & "_LEFT", frm.Left
        SaveSetting sTitleA, "WinStates", sName & "_TOP", frm.Top
        SaveSetting sTitleA, "WinStates", sName & "_WIDTH", frm.Width
        SaveSetting sTitleA, "WinStates", sName & "_HEIGHT", frm.Height

    End If

    Exit Sub
err_sws:
    Debug.Print "SaveWindowState: " & Err.Description

End Sub

' we use 2 separate subs instead of a single sub, because
' some forms have a fixed size!

' I added this to make window be centered
' by default instead of default settings:
Sub GetWindowPos_CENTER_BY_DEFAULT(frm As Form)
On Error GoTo err_gws

    Dim sName As String
    Dim t As Single
    
    sName = frm.Name

    t = GetSetting(sTitleA, "WinStates", sName & "_LEFT", Screen.Width / 2 - frm.Width / 2)
    If t < 0 Then
        frm.Left = 0
    ElseIf t > (Screen.Width - DEFAULT_min_width) Then
        frm.Left = Screen.Width - DEFAULT_min_width
    Else
        frm.Left = t
    End If
    
    t = GetSetting(sTitleA, "WinStates", sName & "_TOP", Screen.Height / 2 - frm.Height / 2)
    If t < 0 Then
        frm.Top = 0
    ElseIf t > (Screen.Height - DEFAULT_min_height) Then
        frm.Top = Screen.Height - DEFAULT_min_height
    Else
        frm.Top = t
    End If


    Exit Sub
err_gws:
    Debug.Print "GetWindowState: " & Err.Description

End Sub


Sub GetWindowPos(frm As Form)
On Error GoTo err_gws

    Dim sName As String
    Dim t As Single
    
    sName = frm.Name

    t = GetSetting(sTitleA, "WinStates", sName & "_LEFT", frm.Left)
    If t < 0 Then
        frm.Left = 0
    ElseIf t > (Screen.Width - DEFAULT_min_width) Then
        frm.Left = Screen.Width - DEFAULT_min_width
    Else
        frm.Left = t
    End If
    
    t = GetSetting(sTitleA, "WinStates", sName & "_TOP", frm.Top)
    If t < 0 Then
        frm.Top = 0
    ElseIf t > (Screen.Height - DEFAULT_min_height) Then
        frm.Top = Screen.Height - DEFAULT_min_height
    Else
        frm.Top = t
    End If


    Exit Sub
err_gws:
    Debug.Print "GetWindowState: " & Err.Description

End Sub

Sub GetWindowSize(frm As Form, Optional sinMIN_WIDTH As Single, Optional sinMIN_HEIGHT As Single)   ' #1105
On Error GoTo err_gws

    ' #1105 allow passing the allowed minimum to this sub.
    If sinMIN_WIDTH < DEFAULT_min_width Then sinMIN_WIDTH = DEFAULT_min_width
    If sinMIN_HEIGHT < DEFAULT_min_height Then sinMIN_HEIGHT = DEFAULT_min_height


    Dim sName As String
    Dim t As Single
    
    sName = frm.Name

    t = GetSetting(sTitleA, "WinStates", sName & "_WIDTH", frm.Width)
    If t < sinMIN_WIDTH Then
        frm.Width = sinMIN_WIDTH
    ElseIf t > Screen.Width - 100 Then
        frm.Width = Screen.Width - 100
    Else
        frm.Width = t
    End If
    
    t = GetSetting(sTitleA, "WinStates", sName & "_HEIGHT", frm.Height)
    If t < sinMIN_HEIGHT Then
        frm.Height = sinMIN_HEIGHT
    ElseIf t > Screen.Height - 500 Then
        frm.Height = Screen.Height - 500
    Else
        frm.Height = t
    End If
    
        
    Exit Sub
err_gws:
    Debug.Print "GetWindowState: " & Err.Description

End Sub

