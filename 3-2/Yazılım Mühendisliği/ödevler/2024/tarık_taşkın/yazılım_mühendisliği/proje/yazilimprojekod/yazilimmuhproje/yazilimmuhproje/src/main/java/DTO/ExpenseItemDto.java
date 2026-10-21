package DTO;
public class ExpenseItemDto {
    private int id;
    private String name;
    private double budget;
    private double thresholdPercent;

    public ExpenseItemDto() {}

    public ExpenseItemDto(int id, String name, double budget, double thresholdPercent) {
        this.id = id;
        this.name = name;
        this.budget = budget;
        this.thresholdPercent = thresholdPercent;
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
}

