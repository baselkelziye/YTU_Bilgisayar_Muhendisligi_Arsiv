using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Tilemaps;
using UnityEngine.UI;
using TMPro;
public class CharacterMovement : MonoBehaviour
{
    public List<GameObject> enemies = new List<GameObject>();
    public Tilemap floor, hills, mountains;
    public Camera cam;
    Vector3Int touchCell, characterCell;
    float cellDiagonal = 5.12f;
    bool isSelected, onHill=false;
    public int maxMovementPoint = 3;
    int turnNumber, cellDistanceX, cellDistanceY, movementPoint, attackPoint=0, defensePoint=0, gold, lost, numOfSwordsman=0, numOfArcher=0, numOfSpearman=0, numOfCavalry=0, armySize=0;
    public Sprite normal, highlighted;
    public GameObject morAdam, warPanel, swordsmanPanel, spearmanPanel, archerPanel, cavalryPanel, eventObject, losePanel, endGameCanvas;
    public TMP_Text playerAP, playerDP, botAP, botDP, collectedGold, lostUnit, currentGold, turn, movementPointText;
    BotScript botScript;
    EventScript eventScript;
    Recruitment swordsmanScript, spearmanScript, archerScript, cavalryScript;
    void Start()
    {
        if(hills.HasTile(hills.WorldToCell(transform.position)))
            onHill = true;
        movementPoint = maxMovementPoint;
        swordsmanScript = swordsmanPanel.GetComponent<Recruitment>();
        spearmanScript = spearmanPanel.GetComponent<Recruitment>();
        archerScript = archerPanel.GetComponent<Recruitment>();
        cavalryScript = cavalryPanel.GetComponent<Recruitment>();
        eventScript = eventObject.GetComponent<EventScript>();
        showMovementPoint();
    }
    void Update()
    {
        showMovementPoint();
        int random;
        Vector3 worldPos = Camera.main.ScreenToWorldPoint(Input.mousePosition);
        worldPos.z = 0;
        touchCell = hills.WorldToCell(worldPos);
        characterCell = hills.WorldToCell(transform.position);
        if(hills.WorldToCell(eventObject.transform.position) == characterCell){
            eventScript.randomEvent();
            eventScript.destroyEventPoint();
        }
        foreach(GameObject enemy in enemies)
        {
            if (hills.WorldToCell(enemy.transform.position) == characterCell)
            {
                gold = int.Parse(currentGold.text);
                botScript = enemy.GetComponent<BotScript>();
                warPanel.SetActive(true);
                playerAP.text = attackPoint.ToString();
                playerDP.text = defensePoint.ToString();
                botAP.text = botScript.botAttackPoint.ToString();
                botDP.text = botScript.botDefensePoint.ToString();
                collectedGold.text = (attackPoint - botScript.botDefensePoint).ToString();
                if (int.Parse(collectedGold.text) > 0)
                    gold += int.Parse(collectedGold.text);
                else
                    collectedGold.text = "0";
                currentGold.text = gold.ToString();
                lostUnit.text = ((botScript.botAttackPoint-defensePoint)/25).ToString();
                lost = int.Parse(lostUnit.text);
                if (lost < 0)
                {
                    lost = 0;
                    lostUnit.text = "0";
                }
                else if (lost < armySize)
                {
                    while (lost > 0)
                    {
                        random = Random.Range(0, 4);
                        switch (random)
                        {
                            case 0:
                                if (numOfSwordsman > 0)
                                {
                                    disbandSwordsman();
                                    lost--;
                                    swordsmanScript.disband();
                                    currentGold.text = gold.ToString();
                                    break;
                                }
                                goto case 1;
                            case 1:
                                if (numOfSpearman > 0)
                                {
                                    disbandSpearman();
                                    lost--;
                                    spearmanScript.disband();
                                    currentGold.text = gold.ToString();
                                    break;
                                }
                                goto case 2;
                            case 2:
                                if (numOfArcher > 0)
                                {
                                    disbandArcher();
                                    lost--;
                                    archerScript.disband();
                                    currentGold.text = gold.ToString();
                                    break;
                                }
                                goto case 3;
                            case 3:
                                if (numOfCavalry > 0)
                                {
                                    disbandCavalry();
                                    lost--;
                                    cavalryScript.disband();
                                    currentGold.text = gold.ToString();
                                }
                                break;
                        }
                    }
                }
                else
                {
                    lostUnit.text = armySize.ToString();
                    losePanel.SetActive(true);
                    endGameCanvas.SetActive(true);

                }
                
                turnNumber = int.Parse(turn.text);
                botScript.botAttackPoint = (botScript.botAttackPoint / 3)+40*turnNumber;
                botScript.botDefensePoint = (botScript.botDefensePoint / 3)+40 * turnNumber;
                botScript.updateBotInfo();
                for (int i = 0; i<20; i++)
                    botScript.step(Random.Range(0, 4));
            }

        }
        if (Input.GetMouseButtonDown(0) && touchCell == characterCell)
        {
            if (isSelected)
            {
                morAdam.GetComponent<SpriteRenderer>().sprite = normal;
                isSelected = false;
            }
            else
            {
                isSelected = true;
                morAdam.GetComponent<SpriteRenderer>().sprite = highlighted;
            }
        }
        else if (Input.GetMouseButtonDown(0) && isSelected)
        {
            cellDistanceX = touchCell.x - characterCell.x;
            cellDistanceY = touchCell.y - characterCell.y;
            if (hills.HasTile(touchCell))
            {
                if (movementPoint > Mathf.Abs(cellDistanceX) + Mathf.Abs(cellDistanceY))
                {
                    if (cellDistanceX != 0 || cellDistanceY != 0)
                    {
                        transform.position += new Vector3(cellDiagonal * (cellDistanceX - cellDistanceY) / 2, (cellDiagonal * (cellDistanceX + cellDistanceY) / 4), 0);
                        movementPoint -= Mathf.Abs(cellDistanceX) + Mathf.Abs(cellDistanceY) + 1;
                        if (!onHill)
                            transform.position += new Vector3(0, 1, 0);
                        onHill = true;
                    }

                    morAdam.GetComponent<SpriteRenderer>().sprite = normal;
                    isSelected = false;
                }
            }
            else if(floor.HasTile(touchCell) && !mountains.HasTile(touchCell))
            {
                if (movementPoint >= Mathf.Abs(cellDistanceX) + Mathf.Abs(cellDistanceY))
                {
                    if (cellDistanceX != 0 || cellDistanceY != 0)
                    {
                        transform.position += new Vector3(cellDiagonal * (cellDistanceX - cellDistanceY) / 2, cellDiagonal * (cellDistanceX + cellDistanceY) / 4, 0);
                        movementPoint -= Mathf.Abs(cellDistanceX) + Mathf.Abs(cellDistanceY);
                        if (onHill)
                        {
                            onHill = false;
                            transform.position += new Vector3(0, -1, 0);
                        }
                    }

                    morAdam.GetComponent<SpriteRenderer>().sprite = normal;
                    isSelected = false;
                }
            }
            
                 
        }

    }
    public void showMovementPoint()
    {
        movementPointText.text = movementPoint.ToString();
    }
    public void resetMovementPoint()
    {
        movementPoint = maxMovementPoint;
    }
    public void recruitSwordsman()
    {
        gold = int.Parse(currentGold.text);
        if (gold >= 75)
        {
            attackPoint += 50;
            defensePoint += 30;
            numOfSwordsman++;
            armySize++;
        }
    }
    public void disbandSwordsman()
    {
        if (numOfSwordsman > 0)
        {

            attackPoint -= 50;
            defensePoint -= 30;
            numOfSwordsman--;
            armySize--;
        }
    }
    public void recruitSpearman()
    {
        gold = int.Parse(currentGold.text);
        if (gold >= 125)
        {
            attackPoint += 20;
            defensePoint += 90;
            numOfSpearman++;
            armySize++;
        }

    }
    public void disbandSpearman()
    {
        if (numOfSpearman > 0)
        {
            attackPoint -= 20;
            defensePoint -= 90;
            numOfSpearman--;
            armySize--;
        }
    }
    public void recruitArcher()
    {
        gold = int.Parse(currentGold.text);
        if (gold >= 135)
        {
            attackPoint += 80;
            defensePoint += 5;
            numOfArcher++;
            armySize++;
        }
    }
    public void disbandArcher()
    {
        if (numOfArcher > 0)
        {
            attackPoint -= 80;
            defensePoint -= 5;
            numOfArcher--;
            armySize--;
        }
    }
    public void recruitCavalry()
    {
        gold = int.Parse(currentGold.text);
        if (gold >= 175)
        {
            attackPoint += 115;
            defensePoint += 40;
            numOfCavalry++;
            armySize++;
        }
    }
    public void disbandCavalry()
    {
        if (numOfCavalry > 0)
        {
            attackPoint -= 115;
            defensePoint -= 40;
            numOfCavalry--;
            armySize--;
        }
    }
    public void gainMovementPoint(int val)
    {
        movementPoint += val;
    }
}
