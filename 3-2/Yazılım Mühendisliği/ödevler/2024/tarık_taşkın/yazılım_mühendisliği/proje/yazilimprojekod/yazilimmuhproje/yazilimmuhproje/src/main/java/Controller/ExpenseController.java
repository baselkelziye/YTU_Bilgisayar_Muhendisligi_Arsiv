package Controller;

import DTO.ExpenseReportDto;
import Entities.Expense;
import Service.IExpenseService;
import Service.IUserService;

import java.util.List;
import java.util.Map;

public class ExpenseController {
    private final IExpenseService expenseService;

    public ExpenseController(IExpenseService expenseService) {
        this.expenseService = expenseService;
    }

    public Map<Integer, Double> showDepartmentWiseBudgetEstimates(int period) {
        Map<Integer, Double> estimates = expenseService.getDepartmentBudgetEstimates(period);

        for (Map.Entry<Integer, Double> entry : estimates.entrySet()) {
            System.out.println("Departman " + entry.getKey() + " için tahmini bütçe: " + entry.getValue() + " TL");
        }

        double totalEstimate = expenseService.getTotalBudgetEstimate(period);
        System.out.println("\n🔵 Tüm departmanların toplam tahmini bütçesi: " + totalEstimate + " TL");
        
        return estimates;
    }

    public List<ExpenseReportDto> showExpenseReports() {
        List<ExpenseReportDto> reports = expenseService.getGroupedExpenseReports();
        for (ExpenseReportDto r : reports) {
            System.out.println(
                    "Kullanıcı: " + r.getUserId() +
                            " | Departman: " + r.getDepartmentId() +
                            " | Kalem: " + r.getExpenseItemId() +
                            " | Dönem: " + r.getMonthYear() +
                            " | Tutar: " + r.getTotalAmount()
            );
        }
        
        return reports;
    }
    
    public List<Expense> getPendingExpensesByDepartmentID(int department_id) {
        return expenseService.getPendingExpensesByDepartmentID(department_id);
    }
    
    public List<Expense> getApprovedExpensesByDepartmentID(int department_id) {
        return expenseService.getApprovedExpensesByDepartmentID(department_id);
    }

    public String processExpensePayment(int expenseId) {
        return expenseService.processExpensePayment(expenseId);
    }

    public void correctExpenseItem(int expenseId, int newExpenseItemId) {
        expenseService.correctExpenseItem(expenseId, newExpenseItemId);
    }
    
    //Gerek yok, silinecek
    public void submitExpenseDocument(int expenseId, String documentPath) {
        expenseService.submitExpenseDocument(expenseId, documentPath);
    }

    public void addExpense(int userId, int expenseItemId, double amount, String documentPath ) {
        Expense expense = new Expense(userId, expenseItemId, amount, documentPath);
        expenseService.addExpense(expense);
    }
    public void approveExpense(int expenseId) {
        expenseService.approveExpense(expenseId);
    }

}
