using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Key : MonoBehaviour
{
    public float keyDropRate = 0.20f;
    public bool key = false;
    public GameObject keyImage;
    public void isKeyDropped(){
        if(Random.Range(0f, 1f)<keyDropRate){
            DropKey();
        }
    }
    public void DropKey(){
        key = true;
        keyImage.SetActive(true);
    }

}
