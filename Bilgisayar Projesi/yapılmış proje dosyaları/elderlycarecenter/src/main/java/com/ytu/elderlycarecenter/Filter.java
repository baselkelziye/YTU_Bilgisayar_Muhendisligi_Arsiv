/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.ytu.elderlycarecenter;

/**
 *
 * @author omerhamidkamisli
 */
public class Filter {
    String Name;
    String Surname;
    int count;

    public Filter(String Name, String Surname, int count) {
        this.Name = Name;
        this.Surname = Surname;
        this.count = count;
    }

    public String getName() {
        return Name;
    }

    public void setName(String Name) {
        this.Name = Name;
    }

    public String getSurname() {
        return Surname;
    }

    public void setSurname(String Surname) {
        this.Surname = Surname;
    }

    public int getCount() {
        return count;
    }

    public void setCount(int count) {
        this.count = count;
    }
    
    
}
