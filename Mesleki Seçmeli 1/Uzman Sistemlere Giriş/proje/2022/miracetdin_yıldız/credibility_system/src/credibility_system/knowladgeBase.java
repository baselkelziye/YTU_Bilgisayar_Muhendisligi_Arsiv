/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package credibility_system;

/**
 *
 * @author Miracetdin
 */
public class knowladgeBase {
    // Rules
    
    // calculating age score
    static int calAgeScore(int age){
        int score = 0;
        if(age < 20){
            score = 2;
        }
        else if(age < 30){
            score = 3;
        }
        else if(age < 40){
            score = 4;
        }
        else if(age < 50){
            score = 5;
        }
        else if(age < 60){
            score = 5;
        }
        else if(age < 70){
            score = 3;
        }
        else{
            score = 1;
        }
        return score;
    }
    
    // calculating education score
    static  int calEduScore(String education){
        int score = 0;
        if(education.equals("Uneducated")){
            score = 1;
        }
        else if(education.equals("High School")){
            score = 2;
        }
        else if(education.equals("Graduate")){
            score = 3;
        }
        else if(education.equals("Post-Graduate")){
            score = 4;
        }
        else if(education.equals("Doctarate")){
            score = 5;
        }
        return score;
    }
    
    // calculating income score
    static int calIncScore(int income){
        int score = 0;
        if(income < 40000){
            score = 1;
        }
        else if(income < 60000){
            score = 2;
        }
        else if(income < 80000){
            score = 3;
        }
        else if(income < 100000){
            score = 4;
        }
        else if(income < 120000){
            score = 5;
        }
        return score;
    }
    
    // calculating home (own/rent/mortgage) score
    static int calHomScore(String home){
        int score = 0;
        if(home.equals("Mortgage")){
            score = 1;
        }
        else if(home.equals("Rent")){
            score = 2;
        }
        else if(home.equals("Own")){
            score = 3;
        }
        return score;
    }
    
    // calculating debt score
    static int calDebScore(int debt){
        int score = 0;
        if(debt < 5000){
            score = 6;
        }
        else if(debt < 10000){
            score = 5;
        }
        else if(debt < 15000){
            score = 4;
        }
        else if(debt < 20000){
            score = 3;
        }
        else if(debt < 25000){
            score = 2;
        }
        else if(debt < 30000){
            score = 1;
        }
        else{
            score = 0;
        }
        return score;
    }
    
    // calculating credi amount score
    static int calAmoScore(int amount){
        int score = 0;
        if(amount < 5000){
            score = 6;
        }
        else if(amount < 10000){
            score = 5;
        }
        else if(amount < 15000){
            score = 4;
        }
        else if(amount < 20000){
            score = 3;
        }
        else if(amount < 25000){
            score = 2;
        }
        else if(amount < 30000){
            score = 1;
        }
        else{
            score = 0;
        }
        return score;
    }
    
}
