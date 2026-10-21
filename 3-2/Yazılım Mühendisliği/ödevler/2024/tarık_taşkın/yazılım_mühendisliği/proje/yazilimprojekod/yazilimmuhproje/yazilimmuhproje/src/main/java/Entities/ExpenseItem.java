package Entities;

public class ExpenseItem {
    private int id;
    private String name;
    private double budget;
    private double thresholdPercent;
    private double maxLimit;
    private double usedBudget;
    private int department_id;
    public ExpenseItem() {}

    public ExpenseItem(int id, String name, double budget, double thresholdPercent, double maxLimit, double usedBudget, int department_id) {
        this.id = id;
        this.name = name;
        this.budget = budget;
        this.thresholdPercent = thresholdPercent;
        this.maxLimit = maxLimit;
        this.usedBudget = usedBudget;
        this.department_id = department_id;
    }

    // Getters & Setters
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public double getBudget() {
        return budget;
    }

    public void setBudget(double budget) {
        this.budget = budget;
    }

    public double getThresholdPercent() {
        return thresholdPercent;
    }

    public void setThresholdPercent(double thresholdPercent) {
        this.thresholdPercent = thresholdPercent;
    }
    public double getMaxLimit() {
        return maxLimit;
    }

    public void setMaxLimit(double maxLimit) {
        this.maxLimit = maxLimit;
    }
    public double getUsedBudget() {
        return usedBudget;
    }

    public void setUsedBudget(double usedBudget) {
        this.usedBudget = usedBudget;
    }
    
    public int getDepartment_id() {
        return department_id;
    }

    public void setDepartment_id(int department_id) {
        this.department_id = department_id;
    }
}

