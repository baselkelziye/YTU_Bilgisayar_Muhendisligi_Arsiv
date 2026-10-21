using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;
public class NextTurn : MonoBehaviour
{
    public TextMeshProUGUI turnNum;
    public TMP_Text goldText, foodText, totalDailyFoodUI, totalSalaryUI;
    int prevTurn, currentGold, currentFood, totalDailyFood, totalSalary;
    public GameObject eventObject, winPanel, loseHungerPanel, loseBankruptcyPanel, endGameCanvas, player;
    EventScript eventScript;
    CharacterMovement playerScript;
    void Start()
    {
        eventScript = eventObject.GetComponent<EventScript>();
        playerScript = player.GetComponent<CharacterMovement>();
    }
    public void turnButton()
    {
        prevTurn = int.Parse(turnNum.text);
        currentGold = int.Parse(goldText.text);
        totalDailyFood = int.Parse(totalDailyFoodUI.text);
        totalSalary = int.Parse(totalSalaryUI.text);
        currentGold = int.Parse(goldText.text);
        currentFood = int.Parse(foodText.text);
        if(currentGold + totalSalary >= 0)
        {
            currentGold += totalSalary;
        }
        else
        {
            loseBankruptcyPanel.SetActive(true);
            endGameCanvas.SetActive(true);
        }
        if(currentFood + totalDailyFood >= 0)
        {
            currentFood += totalDailyFood;
        }
        else
        {
            loseHungerPanel.SetActive(true);
            endGameCanvas.SetActive(true);
        }
        if (--eventScript.repeatTurnValue == 0)
        {
            eventScript.repeatTurnValue = eventScript.defaultRepeatTurnValue;
            eventScript.createEventPoint();
        }
        prevTurn++;
        if (prevTurn == 20)
        {
            winPanel.SetActive(true);
            endGameCanvas.SetActive(true);
        }
        playerScript.showMovementPoint();
        turnNum.text = prevTurn.ToString();
        totalDailyFoodUI.text = totalDailyFood.ToString();
        totalSalaryUI.text = totalSalary.ToString();
        goldText.text = currentGold.ToString();
        foodText.text = currentFood.ToString();
    }
}
