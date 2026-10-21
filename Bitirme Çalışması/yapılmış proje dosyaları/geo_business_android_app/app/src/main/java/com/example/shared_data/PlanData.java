package com.example.shared_data;

import com.example.models.Plan;

public class PlanData {

    private static PlanData instance;
    private Plan planData;

    private PlanData() {}

    public static PlanData getInstance() {
        if (instance == null) {
            instance = new PlanData();
        }
        return instance;
    }

    public Plan getSharedData() {
        return planData;
    }

    public void setSharedData(Plan planData) {
        this.planData = planData;
    }

}
