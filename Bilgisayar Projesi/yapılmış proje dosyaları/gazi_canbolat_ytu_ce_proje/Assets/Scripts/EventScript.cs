using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.Tilemaps;
using TMPro;

public class EventScript : MonoBehaviour
{
    public Tilemap floor, hills;
    Vector3Int newPosition, tilePosition;
    bool repeat;
    public GameObject eventPoint, swordsmanPanel, spearmanPanel, archerPanel, cavalryPanel, player, gold50, gold100, gold150, food40, food80, food120, foundSwordsman, foundSpearman, foundArcher, foundCavalry, gainMovement2, gainMovement3, gainMovement4;
    public int repeatTurnValue = 4, defaultRepeatTurnValue = 5;
    int eventNumber, gold, food;
    public TMP_Text goldUI, foodUI;
    Recruitment swordsmanScript, spearmanScript, archerScript, cavalryScript;
    CharacterMovement playerScript;
    void Start()
    {
        swordsmanScript = swordsmanPanel.GetComponent<Recruitment>();
        spearmanScript = spearmanPanel.GetComponent<Recruitment>();
        archerScript = archerPanel.GetComponent<Recruitment>();
        cavalryScript = cavalryPanel.GetComponent<Recruitment>();
        playerScript = player.GetComponent<CharacterMovement>();
        destroyEventPoint();
    }
    public void randomEvent()
    {
        eventNumber = Random.Range(0, 13);
        gold = int.Parse(goldUI.text);
        food = int.Parse(foodUI.text);
        switch (eventNumber)
        {
            case 0:
                gold += 50;
                goldUI.text = gold.ToString();
                gold50.SetActive(true);
                break;
            case 1:
                gold += 100;
                goldUI.text = gold.ToString();
                gold100.SetActive(true);
                break;
            case 2:
                gold += 150;
                goldUI.text = gold.ToString();
                gold150.SetActive(true);
                break;
            case 3:
                food += 40;
                foodUI.text = food.ToString();
                food40.SetActive(true);
                break;
            case 4:
                food += 800;
                foodUI.text = food.ToString();
                food80.SetActive(true);
                break;
            case 5:
                food += 120;
                foodUI.text = food.ToString();
                food120.SetActive(true);
                break;
            case 6:
                playerScript.recruitSwordsman();
                swordsmanScript.recruit();
                gold += 75;
                goldUI.text = gold.ToString();
                foundSwordsman.SetActive(true);
                break;
            case 7:
                playerScript.recruitSpearman();
                spearmanScript.recruit();
                gold += 125;
                goldUI.text = gold.ToString();
                foundSpearman.SetActive(true);
                break;
            case 8:
                playerScript.recruitArcher();
                archerScript.recruit();
                gold += 135;
                goldUI.text = gold.ToString();
                foundArcher.SetActive(true);
                break;
            case 9:
                playerScript.recruitCavalry();
                cavalryScript.recruit();
                gold += 175;
                goldUI.text = gold.ToString();
                foundCavalry.SetActive(true);
                break;
            case 10:
                playerScript.gainMovementPoint(2);
                playerScript.showMovementPoint();
                gainMovement2.SetActive(true);
                break;
            case 11:
                playerScript.gainMovementPoint(3);
                playerScript.showMovementPoint();
                gainMovement3.SetActive(true);
                break;
            case 12:
                playerScript.gainMovementPoint(4);
                playerScript.showMovementPoint();
                gainMovement4.SetActive(true);
                break;
        }
    }
    public void createEventPoint()
    {
        repeat = true;
        while (repeat)
        {
            newPosition = new Vector3Int(Random.Range(-25, 25), Random.Range(-25, 25), 0);
            tilePosition = floor.WorldToCell(newPosition);
            if (floor.HasTile(tilePosition))
            {
                eventPoint.SetActive(true);
                transform.position = floor.CellToWorld(tilePosition);
                transform.position += new Vector3(0, 1.56f , 0);
                repeat = false;
            }
            else if (hills.HasTile(tilePosition))
            {
                eventPoint.SetActive(true);
                transform.position = floor.CellToWorld(tilePosition);
                transform.position += new Vector3(0, 2.28f , 0);
                repeat = false;
            }
        }
        
         
    }
    public void destroyEventPoint()
    {
        transform.position += new Vector3(100, 0, 0);
        eventPoint.SetActive(false);
        repeatTurnValue = defaultRepeatTurnValue;
    }
}
