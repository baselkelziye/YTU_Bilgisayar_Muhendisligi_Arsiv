package Service;

import Entities.ExpenseItem;
import java.util.List;

public interface IExpenseItemService {
    List<ExpenseItem> getExpenseItems();
    void updateExpenseItemBudget(int expenseItemId, double newBudget);

}
