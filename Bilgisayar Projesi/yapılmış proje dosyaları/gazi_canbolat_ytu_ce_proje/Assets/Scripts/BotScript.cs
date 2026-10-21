using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Tilemaps;
using TMPro;

public class BotScript : MonoBehaviour
{
    public GameObject player;
    public Tilemap floor, mountains, hills;
    public int maxMovementPoint = 3, range = 7, botAttackPoint = 100, botDefensePoint = 140;
    public float apGainRatio = 0.04f, dpGainRatio = 0.04f;
    Vector3Int playerCell, botCell;
    int cellDistanceX, cellDistanceY, movementPoint, totalDistance;
    float cellDiagonal = 5.12f;
    bool isOnHill = false;
    public TMP_Text botAP, botDP;
    void Start()
    {
        if(hills.HasTile(hills.WorldToCell(player.transform.position)))
            isOnHill = true;
        updateBotInfo();
    }
    public void move()
    {
        //tur başı alacağı güçlendirmeler
        botAttackPoint += (int)(botAttackPoint * apGainRatio);
        botDefensePoint += (int)(botDefensePoint * dpGainRatio);
        botAP.text = botAttackPoint.ToString();
        botDP.text = botDefensePoint.ToString();
        //hamle yap
        movementPoint = maxMovementPoint;
        playerCell = hills.WorldToCell(player.transform.position);
        botCell = hills.WorldToCell(transform.position);
        cellDistanceX = playerCell.x - botCell.x;
        cellDistanceY = playerCell.y - botCell.y;
        totalDistance = Mathf.Abs(cellDistanceX) + Mathf.Abs(cellDistanceY);
        if(totalDistance<range)
        {
            //yaklaş
            while (movementPoint > 0 )
            {
                step(selectDirection(playerCell.x - botCell.x, playerCell.y - botCell.y));
                movementPoint--;
                playerCell = hills.WorldToCell(player.transform.position);
                botCell = hills.WorldToCell(transform.position);
                if (playerCell==botCell)
                {
                    movementPoint = 0;
                }
            }
        }
        else
        {
            //random bir yönde uygun bir kare varsa ilerle
            while (movementPoint > 0)
            {
                step(Random.Range(0, 4));
                movementPoint--;
            }
        }

    }

    public void step(int direction)
    {
        switch (direction)
        {
            case 0:
                if(floor.HasTile(floor.WorldToCell(transform.position + new Vector3(cellDiagonal / 2, cellDiagonal / 4, 0))))
                {
                    if (isOnHill)
                    {
                        transform.position += new Vector3(cellDiagonal / 2, (cellDiagonal / 4)-1, 0);
                        isOnHill = false;
                    }
                    else
                    {
                        transform.position += new Vector3(cellDiagonal / 2, cellDiagonal / 4, 0);
                    }
                }else if(hills.HasTile(floor.WorldToCell(transform.position + new Vector3(cellDiagonal / 2, cellDiagonal / 4, 0))))
                {
                    if (isOnHill)
                    {
                        transform.position += new Vector3(cellDiagonal / 2, cellDiagonal / 4, 0);
                        
                    }
                    else
                    {
                        transform.position += new Vector3(cellDiagonal / 2, (cellDiagonal / 4) + 1, 0);
                        isOnHill = true;
                    }
                }
                else
                {
                    step(Random.Range(0, 4));
                }
                break;
            case 1:
                if (floor.HasTile(floor.WorldToCell(transform.position + new Vector3(-cellDiagonal / 2, -cellDiagonal / 4, 0))))
                {
                    if (isOnHill)
                    {
                        transform.position += new Vector3(-cellDiagonal / 2, (-cellDiagonal / 4) - 1, 0);
                        isOnHill = false;
                    }
                    else
                    {
                        transform.position += new Vector3(-cellDiagonal / 2, -cellDiagonal / 4, 0);
                    }
                }
                else if (hills.HasTile(floor.WorldToCell(transform.position + new Vector3(-cellDiagonal / 2, -cellDiagonal / 4, 0))))
                {
                    if (isOnHill)
                    {
                        transform.position += new Vector3(-cellDiagonal / 2, -cellDiagonal / 4, 0);

                    }
                    else
                    {
                        transform.position += new Vector3(-cellDiagonal / 2, (-cellDiagonal / 4) + 1, 0);
                        isOnHill = true;
                    }
                }
                else
                {
                    step(Random.Range(0, 4));
                }
                break;
            case 2:
                if (floor.HasTile(floor.WorldToCell(transform.position + new Vector3(-cellDiagonal / 2, cellDiagonal / 4, 0))))
                {
                    if (isOnHill)
                    {
                        transform.position += new Vector3(-cellDiagonal / 2, (cellDiagonal / 4) - 1, 0);
                        isOnHill = false;
                    }
                    else
                    {
                        transform.position += new Vector3(-cellDiagonal / 2, cellDiagonal / 4, 0);
                    }
                }
                else if (hills.HasTile(floor.WorldToCell(transform.position + new Vector3(-cellDiagonal / 2, cellDiagonal / 4, 0))))
                {
                    if (isOnHill)
                    {
                        transform.position += new Vector3(-cellDiagonal / 2, cellDiagonal / 4, 0);

                    }
                    else
                    {
                        transform.position += new Vector3(-cellDiagonal / 2, (cellDiagonal / 4) + 1, 0);
                        isOnHill = true;
                    }
                }
                else
                {
                    step(Random.Range(0, 4));
                }
                break;
            case 3:
                if (floor.HasTile(floor.WorldToCell(transform.position + new Vector3(cellDiagonal / 2, -cellDiagonal / 4, 0))))
                {
                    if (isOnHill)
                    {
                        transform.position += new Vector3(cellDiagonal / 2, (-cellDiagonal / 4) - 1, 0);
                        isOnHill = false;
                    }
                    else
                    {
                        transform.position += new Vector3(cellDiagonal / 2, -cellDiagonal / 4, 0);
                    }
                }
                else if (hills.HasTile(floor.WorldToCell(transform.position + new Vector3(cellDiagonal / 2, -cellDiagonal / 4, 0))))
                {
                    if (isOnHill)
                    {
                        transform.position += new Vector3(cellDiagonal / 2, -cellDiagonal / 4, 0);

                    }
                    else
                    {
                        transform.position += new Vector3(cellDiagonal / 2, (-cellDiagonal / 4) + 1, 0);
                        isOnHill = true;
                    }
                }
                else
                {
                    step(Random.Range(0, 4));
                }
                break;
            default:
                Debug.Log("Hatalı yön seçimi");
                break;
        }
        
    }
    //sağ üst:0; sol alt:1; sol üst:2; sağ alt:3
    public int selectDirection(int disX, int disY)
    {
        if (Mathf.Abs(disX) > Mathf.Abs(disY))
        {
            if (disX > 0)
            {
                return 0;
            }
            return 1;
        }
        else if(disY>0)
        {
            return 2;
        }
        return 3;
    }

    public void updateBotInfo()
    {
        botAP.text = botAttackPoint.ToString();
        botDP.text = botDefensePoint.ToString();
    }
    
}
