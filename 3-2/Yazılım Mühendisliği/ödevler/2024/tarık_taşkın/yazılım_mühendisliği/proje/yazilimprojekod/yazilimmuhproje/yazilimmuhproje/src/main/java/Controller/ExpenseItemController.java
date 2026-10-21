package Controller;

import Entities.ExpenseItem;
import Service.IExpenseItemService;
import Service.IExpenseService;
import java.util.List;

public class ExpenseItemController {
    private final IExpenseItemService expenseItemService;

    public ExpenseItemController(IExpenseItemService expenseItemService) {
        this.expenseItemService = expenseItemService;
    }
    
    public void updateExpenseItemBudget(int expenseItemId, double newBudget) {
        expenseItemService.updateExpenseItemBudget(expenseItemId, newBudget);
    }
    
    public List<ExpenseItem> getExpenseItems() {
        return expenseItemService.getExpenseItems();
    }
    
}
