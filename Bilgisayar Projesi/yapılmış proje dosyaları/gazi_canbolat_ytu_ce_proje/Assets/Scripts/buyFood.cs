using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;
public class buyFood : MonoBehaviour
{
    public TMP_Text goldText, foodText;
    public int foodPrice=40, foodAmount=200;
    int gold, food;
    public GameObject goldNeededPanel;
    public void buy()
    {
        gold = int.Parse(goldText.text);
        food = int.Parse(foodText.text);
        if (gold > foodPrice)
        {
            gold -= foodPrice;
            food += foodAmount;
            goldText.text = gold.ToString();
            foodText.text = food.ToString();
        }
        else
        {
            goldNeededPanel.SetActive(true);
        }
    }
}
