package Repository;

import DTO.ExpenseReportDto;
import Entities.Expense;
import Entities.ExpenseItem;

import java.util.List;

public interface IExpenseRepository {
    void addExpense(Expense expense);
    void approveExpense(int expenseId);
    void submitExpenseDocument(int expenseId, String documentPath);
    void correctExpenseItem(int expenseId, int newExpenseItemId);
    Expense getExpenseById(int expenseId);
    ExpenseItem getExpenseItemById(int expenseItemId);
    void payPartialExpense(int expenseId);
    void rejectExpense(int expenseId);
    void sendNotificationToAllUsers(String message);
    List<ExpenseReportDto> getGroupedExpenseReports();
    List<Expense> getPendingExpensesByDepartmentID(int department_id);
    List<Expense> getApprovedExpensesByDepartmentID(int department_id);


}
