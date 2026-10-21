using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraMovement : MonoBehaviour
{
    private float dragSpeed;
    public int refreshRate = 5;
    private Vector3 touchStart;
    private int counter = 0;
    
    void Start()
    {
        dragSpeed = Camera.main.orthographicSize * (-1.4f);
    }

    void Update()
    {
        if (Input.GetMouseButtonDown(0))
        {
            touchStart = Input.mousePosition;
            return;
        }

        if (!Input.GetMouseButton(0))
        {
            return;
        }

        if (counter == refreshRate)
        {
            touchStart = Input.mousePosition;
            counter = 0;
        }
        
        counter++;
        Vector3 pos = Camera.main.ScreenToViewportPoint(Input.mousePosition - touchStart);
        Vector3 move = new Vector3(pos.x * dragSpeed, pos.y * dragSpeed, 0);

        transform.Translate(move, Space.World);

    }
}
