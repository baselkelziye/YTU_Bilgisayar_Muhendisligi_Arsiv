package Entities;

import java.time.LocalDateTime;

public class Expense {
    private int id;
    private int userId;
    private int expenseItemId;
    private double amount;
    private String status;
    private LocalDateTime createdAt;
    private String documentPath;

    public Expense() {}

    public Expense(int userId, int expenseItemId, double amount) {
        this.userId = userId;
        this.expenseItemId = expenseItemId;
        this.amount = amount;
        this.status = "PENDING";             // OTOMATİK
        this.createdAt = LocalDateTime.now(); // OTOMATİK3
    }
    
    public Expense(int userId, int expenseItemId, double amount, String documentPath) {
        this.userId = userId;
        this.expenseItemId = expenseItemId;
        this.amount = amount;
        this.status = "PENDING";             // OTOMATİK
        this.createdAt = LocalDateTime.now(); // OTOMATİK3
        this.documentPath = documentPath;
    }

    public Expense(int id, int userId, int expenseItemId, double amount, String status, LocalDateTime createdAt, String documentPath) {
        this.id = id;
        this.userId = userId;
        this.expenseItemId = expenseItemId;
        this.amount = amount;
        this.status = status;
        this.createdAt = createdAt;
        this.documentPath = documentPath;
    }

    // Getters & Setters
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getUserId() {
        return userId;
    }

    public void setUserId(int userId) {
        this.userId = userId;
    }

    public int getExpenseItemId() {
        return expenseItemId;
    }

    public void setExpenseItemId(int expenseItemId) {
        this.expenseItemId = expenseItemId;
    }

    public double getAmount() {
        return amount;
    }

    public void setAmount(double amount) {
        this.amount = amount;
    }

    public String getStatus() {
        return status;
    }

    public void setStatus(String status) {
        this.status = status;
    }

    public LocalDateTime getCreatedAt() {
        return createdAt;
    }

    public void setCreatedAt(LocalDateTime createdAt) {
        this.createdAt = createdAt;
    }

    public String getDocumentPath() {
        return documentPath;
    }

    public void setDocumentPath(String documentPath) {
        this.documentPath = documentPath;
    }
}

