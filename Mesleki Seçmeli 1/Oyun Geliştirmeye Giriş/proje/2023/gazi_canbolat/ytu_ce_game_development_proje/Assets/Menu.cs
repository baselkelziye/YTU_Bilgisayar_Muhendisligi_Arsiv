using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
public class Menu : MonoBehaviour
{
   
    public void restartGame(){
        SceneManager.LoadScene(0);
    }
    public void quitGame(){
        Application.Quit();
    }
}
