/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.ytu.elderlycarecenter;

/**
 *
 * @author ohkam
 */
public class Visitor {
    int id;
    String first_name;
    String last_name;
    int visit_count;

    public Visitor(int id, String first_name, String last_name, int visit_count) {
        this.id = id;
        this.first_name = first_name;
        this.last_name = last_name;
        this.visit_count = visit_count;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getFirst_name() {
        return first_name;
    }

    public void setFirst_name(String first_name) {
        this.first_name = first_name;
    }

    public String getLast_name() {
        return last_name;
    }

    public void setLast_name(String last_name) {
        this.last_name = last_name;
    }

    public int getVisit_count() {
        return visit_count;
    }

    public void setVisit_count(int visit_count) {
        this.visit_count = visit_count;
    }
}
