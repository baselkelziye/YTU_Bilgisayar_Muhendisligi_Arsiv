package Repository;

import Entities.ExpenseItem;
import java.util.List;

public interface IExpenseItemRepository {
    List<ExpenseItem> getExpenseItems();
    void updateExpenseItemBudget(int expenseItemId, double newBudget);
    void updateUsedBudget(int expenseItemId, double amountToAdd);

}
