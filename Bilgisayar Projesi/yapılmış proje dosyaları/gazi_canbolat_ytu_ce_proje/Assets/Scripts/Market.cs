using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Market : MonoBehaviour
{
    public GameObject canvas;

    public void openMarket()
    {
        if (canvas != null)
        {
            canvas.SetActive(true);
        }
    }

    public void closeMarket()
    {
        if (canvas != null)
        {
            canvas.SetActive(false);
        }
    }
}
