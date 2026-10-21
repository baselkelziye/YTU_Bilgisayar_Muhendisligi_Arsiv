package DTO;

public class ExpenseReportDto {
    private int userId;
    private int departmentId;
    private int expenseItemId;
    private String monthYear; // örnek: "2024-03"
    private double totalAmount;

    public ExpenseReportDto(int userId, int departmentId, int expenseItemId, String monthYear, double totalAmount) {
        this.userId = userId;
        this.departmentId = departmentId;
        this.expenseItemId = expenseItemId;
        this.monthYear = monthYear;
        this.totalAmount = totalAmount;
    }
    public ExpenseReportDto() {

    }

    public int getUserId() {
        return userId;
    }

    public void setUserId(int userId) {
        this.userId = userId;
    }

    public int getDepartmentId() {
        return departmentId;
    }

    public void setDepartmentId(int departmentId) {
        this.departmentId = departmentId;
    }

    public int getExpenseItemId() {
        return expenseItemId;
    }

    public void setExpenseItemId(int expenseItemId) {
        this.expenseItemId = expenseItemId;
    }

    public String getMonthYear() {
        return monthYear;
    }

    public void setMonthYear(String monthYear) {
        this.monthYear = monthYear;
    }

    public double getTotalAmount() {
        return totalAmount;
    }

    public void setTotalAmount(double totalAmount) {
        this.totalAmount = totalAmount;
    }
    // Constructor, getters, setters
}

