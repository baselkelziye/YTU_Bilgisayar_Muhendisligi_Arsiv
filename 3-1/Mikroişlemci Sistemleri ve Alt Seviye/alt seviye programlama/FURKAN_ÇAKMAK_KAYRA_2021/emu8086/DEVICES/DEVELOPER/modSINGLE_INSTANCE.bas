Attribute VB_Name = "modSINGLE_INSTANCE"
' Visual Basic 6.0 and 5.0 developers!
' Several running instances of the same device on the same port can cause device conflict.
' You can use this code to prevent your device running several instances.

' add this code to Form_Load() or Sub Main()
'    ' do not allow more than one copy of this program to run simuateniously
'    If App.PrevInstance Then
'
'        ShowPrevInstance
'
'        End   ' terminate this instance!
'
'    End If


Option Explicit

Declare Function FindWindow Lib "user32" Alias "FindWindowA" (ByVal lpClassName As String, ByVal lpWindowName As String) As Long
Declare Function GetWindow Lib "user32" (ByVal hwnd As Long, ByVal wCmd As Long) As Long
Declare Function OpenIcon Lib "user32" (ByVal hwnd As Long) As Long
Declare Function SetForegroundWindow Lib "user32" (ByVal hwnd As Long) As Long
        
Public Const GW_HWNDPREV = 3



Function ShowPrevInstance() As Boolean ' returns True on sucess.
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

