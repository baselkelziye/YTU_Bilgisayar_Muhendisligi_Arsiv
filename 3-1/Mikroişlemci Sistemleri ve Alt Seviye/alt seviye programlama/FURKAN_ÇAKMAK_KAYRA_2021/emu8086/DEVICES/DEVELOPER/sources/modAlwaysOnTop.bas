Attribute VB_Name = "modAlwaysOnTop"
' this module is reponsible for keeping devices on top of other windows

' virtual devices
' emu8086 project

' Form_Load code:
'
' If allow_on_top() Then set_on_top Me
'

' note: this module is disabled by default, because it causes incompatibily with modSINGLE_INSTANCE;
'       when minimized device is reactivated under Windows XP -
'       windows of other applications are activated instead.
'       to enable on-top feature for testing/debugging put this line inside emu8086.ini: devices_on_top=true
'       to successfully access emu8086.ini compiled device must be in c:\emu8086\devices\ or upper subdirectory.


Option Explicit

Dim bIS_ON_TOP As Boolean

Declare Function SetWindowPos Lib "user32" (ByVal hWnd As Long, ByVal hWndInsertAfter As Long, ByVal X As Long, ByVal Y As Long, ByVal cx As Long, ByVal cy As Long, ByVal wFlags As Long) As Long


Function allow_on_top() As Boolean
    
    On Error GoTo err1
    
    Dim iFileNum As Integer
    Dim sTemp As String
    Dim sName As String
    
    iFileNum = FreeFile
    
    ' get the location of emu8086.ini, it should be one dir above devices
    sName = App.Path
    Dim l As Long
    l = InStr(1, sName, "devices", vbTextCompare)
    If l > 0 Then
        sName = Mid(sName, 1, l - 1)
    Else
       allow_on_top = False ' do not allow by default
       Exit Function
    End If
    sName = sName & "emu8086.ini"
    
    
    
    Open sName For Input As iFileNum
    
    sTemp = Input(LOF(iFileNum), #iFileNum)
    
    If InStr(1, sTemp, "devices_on_top=true", vbTextCompare) > 0 Then
        allow_on_top = True
    Else
        allow_on_top = False
    End If
    
    Close iFileNum
    
    sTemp = ""
    
    Exit Function
err1:
    allow_on_top = False ' do not allow by default...
    Debug.Print "allow_on_top: " & Err.Description
    sTemp = ""
End Function



Public Sub set_on_top(frm As Form)
On Error GoTo err1
    Dim lHWND As Long
    lHWND = frm.hWnd
    SetWindowPos lHWND, -1, 0, 0, 0, 0, 83
    bIS_ON_TOP = True
    Exit Sub
err1:
    Debug.Print "err set_on_top: " & Err.Description
End Sub


' example:
' If shall_activate(Me) Then Me.Show
Function shall_activate(frm As Form) As Boolean
    If Not bIS_ON_TOP Or frm.WindowState = vbMinimized Then
        shall_activate = True
    Else
        shall_activate = False
    End If
End Function
