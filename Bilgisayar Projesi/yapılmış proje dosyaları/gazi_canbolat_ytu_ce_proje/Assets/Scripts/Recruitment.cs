using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;
public class Recruitment : MonoBehaviour
{
    public int buyPrice, sellPrice, attackPoint, defensePoint, dailyFood, salary;
    public TMP_Text goldText, amount, totalDailyFoodUI, totalSalaryUI, totalAttackPointUI, totalDefensePointUI;
    public GameObject goldNeededPanel;
    int currentGold, numberOfSoldier, totalDailyFood, totalSalary, totalAttackPoint, totalDefensePoint;
   
    public void recruit()
    {
        currentGold = int.Parse(goldText.text);
        numberOfSoldier = int.Parse(amount.text);
        totalDailyFood = int.Parse(totalDailyFoodUI.text);
        totalSalary = int.Parse(totalSalaryUI.text);
        totalAttackPoint = int.Parse(totalAttackPointUI.text);
        totalDefensePoint = int.Parse(totalDefensePointUI.text);
        if (currentGold >= buyPrice)
        {
            currentGold -= buyPrice;
            totalDailyFood -= dailyFood;
            totalSalary -= salary;
            totalAttackPoint += attackPoint;
            totalDefensePoint += defensePoint;
            numberOfSoldier++;
        }
        else
        {
            goldNeededPanel.SetActive(true);
        }
        goldText.text = currentGold.ToString();
        amount.text = numberOfSoldier.ToString();
        totalDailyFoodUI.text = totalDailyFood.ToString();
        totalSalaryUI.text = totalSalary.ToString();
        totalAttackPointUI.text = totalAttackPoint.ToString();
        totalDefensePointUI.text = totalDefensePoint.ToString();
    }
    public void disband()
    {
        currentGold = int.Parse(goldText.text);
        numberOfSoldier = int.Parse(amount.text);
        totalDailyFood = int.Parse(totalDailyFoodUI.text);
        totalSalary = int.Parse(totalSalaryUI.text);
        totalAttackPoint = int.Parse(totalAttackPointUI.text);
        totalDefensePoint = int.Parse(totalDefensePointUI.text);
        if (numberOfSoldier > 0)
        {
            currentGold += sellPrice;
            totalDailyFood += dailyFood;
            totalSalary += salary;
            totalAttackPoint -= attackPoint;
            totalDefensePoint -= defensePoint;
            numberOfSoldier--;
        }
        goldText.text = currentGold.ToString();
        amount.text = numberOfSoldier.ToString();
        totalDailyFoodUI.text = totalDailyFood.ToString();
        totalSalaryUI.text = totalSalary.ToString();
        totalAttackPointUI.text = totalAttackPoint.ToString();
        totalDefensePointUI.text = totalDefensePoint.ToString();
    } 
}
