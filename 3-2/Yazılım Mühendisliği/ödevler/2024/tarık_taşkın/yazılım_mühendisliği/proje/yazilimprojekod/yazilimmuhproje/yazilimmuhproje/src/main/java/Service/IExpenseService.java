package Service;

import DTO.ExpenseReportDto;
import Entities.Expense;

import java.util.List;
import java.util.Map;

public interface IExpenseService {
    void addExpense(Expense expense);
    void approveExpense(int expenseId);
    void submitExpenseDocument(int expenseId, String documentPath);
    void correctExpenseItem(int expenseId, int newExpenseItemId);
    String processExpensePayment(int expenseId);
    List<ExpenseReportDto> getGroupedExpenseReports();
    List<Expense> getPendingExpensesByDepartmentID(int department_id);
    List<Expense> getApprovedExpensesByDepartmentID(int department_id);
    Map<Integer, Double> getDepartmentBudgetEstimates(int period);
    double getTotalBudgetEstimate(int period);
    
}
