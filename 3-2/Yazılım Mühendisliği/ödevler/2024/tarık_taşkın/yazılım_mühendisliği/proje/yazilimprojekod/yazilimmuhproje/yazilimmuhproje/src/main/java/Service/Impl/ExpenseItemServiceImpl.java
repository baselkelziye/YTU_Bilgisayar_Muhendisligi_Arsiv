package Service.Impl;

import Entities.ExpenseItem;
import Repository.IExpenseItemRepository;
import Service.IExpenseItemService;
import java.util.List;

public class ExpenseItemServiceImpl implements IExpenseItemService {

    private final IExpenseItemRepository expenseItemRepository;

    public ExpenseItemServiceImpl(IExpenseItemRepository expenseItemRepository) {
        this.expenseItemRepository = expenseItemRepository;
    }
    @Override
    public void updateExpenseItemBudget(int expenseItemId, double newBudget) {
        expenseItemRepository.updateExpenseItemBudget(expenseItemId, newBudget);
    }
    
    @Override
    public List<ExpenseItem> getExpenseItems() {
        return expenseItemRepository.getExpenseItems();
    }
}
