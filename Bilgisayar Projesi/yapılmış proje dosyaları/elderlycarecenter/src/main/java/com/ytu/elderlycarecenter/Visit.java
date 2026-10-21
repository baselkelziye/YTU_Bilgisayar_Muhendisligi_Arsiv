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
import java.sql.Date;

public class Visit {
    int visit_id;
    int elder_id;
    String elder_first_name;
    String elder_last_name;
    Date visit_time;
    int first_visitor_id;
    String first_visitor_first_name;
    String first_visitor_last_name;
    int second_visitor_id;
    String second_visitor_first_name;
    String second_visitor_last_name;

    public int getVisit_id() {
        return visit_id;
    }

    public void setVisit_id(int visit_id) {
        this.visit_id = visit_id;
    }

    public int getElder_id() {
        return elder_id;
    }

    public void setElder_id(int elder_id) {
        this.elder_id = elder_id;
    }

    public String getElder_first_name() {
        return elder_first_name;
    }

    public void setElder_first_name(String elder_first_name) {
        this.elder_first_name = elder_first_name;
    }

    public String getElder_last_name() {
        return elder_last_name;
    }

    public void setElder_last_name(String elder_last_name) {
        this.elder_last_name = elder_last_name;
    }

    public Date getVisit_time() {
        return visit_time;
    }

    public void setVisit_time(Date visit_time) {
        this.visit_time = visit_time;
    }

    public int getFirst_visitor_id() {
        return first_visitor_id;
    }

    public void setFirst_visitor_id(int first_visitor_id) {
        this.first_visitor_id = first_visitor_id;
    }

    public String getFirst_visitor_first_name() {
        return first_visitor_first_name;
    }

    public void setFirst_visitor_first_name(String first_visitor_first_name) {
        this.first_visitor_first_name = first_visitor_first_name;
    }

    public String getFirst_visitor_last_name() {
        return first_visitor_last_name;
    }

    public void setFirst_visitor_last_name(String first_visitor_last_name) {
        this.first_visitor_last_name = first_visitor_last_name;
    }

    public int getSecond_visitor_id() {
        return second_visitor_id;
    }

    public void setSecond_visitor_id(int second_visitor_id) {
        this.second_visitor_id = second_visitor_id;
    }

    public String getSecond_visitor_first_name() {
        return second_visitor_first_name;
    }

    public void setSecond_visitor_first_name(String second_visitor_first_name) {
        this.second_visitor_first_name = second_visitor_first_name;
    }

    public String getSecond_visitor_last_name() {
        return second_visitor_last_name;
    }

    public void setSecond_visitor_last_name(String second_visitor_last_name) {
        this.second_visitor_last_name = second_visitor_last_name;
    }

    public Visit(int visit_id, int elder_id, String elder_first_name, String elder_last_name, Date visit_time, int first_visitor_id, String first_visitor_first_name, String first_visitor_last_name, int second_visitor_id, String second_visitor_first_name, String second_visitor_last_name) {
        this.visit_id = visit_id;
        this.elder_id = elder_id;
        this.elder_first_name = elder_first_name;
        this.elder_last_name = elder_last_name;
        this.visit_time = visit_time;
        this.first_visitor_id = first_visitor_id;
        this.first_visitor_first_name = first_visitor_first_name;
        this.first_visitor_last_name = first_visitor_last_name;
        this.second_visitor_id = second_visitor_id;
        this.second_visitor_first_name = second_visitor_first_name;
        this.second_visitor_last_name = second_visitor_last_name;
    }
}

