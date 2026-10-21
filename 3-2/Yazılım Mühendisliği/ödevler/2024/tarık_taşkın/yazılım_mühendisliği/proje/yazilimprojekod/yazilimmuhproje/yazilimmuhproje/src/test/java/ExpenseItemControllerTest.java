
import Controller.ExpenseItemController;

import Entities.ExpenseItem;
import Service.IExpenseItemService;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.mockito.Mockito;

import java.util.*;

import static org.junit.jupiter.api.Assertions.*;
import static org.mockito.Mockito.*;

public class ExpenseItemControllerTest {
    private IExpenseItemService expenseItemService;
    private ExpenseItemController expenseItemController;

    @BeforeEach
    public void setUp() {
        expenseItemService = mock(IExpenseItemService.class);
        expenseItemController = new ExpenseItemController(expenseItemService);
    }

    // ExpenseItemControllerTest.java
    @Test
    public void testUpdateExpenseItemBudget_CallsServiceCorrectly() {
        expenseItemController.updateExpenseItemBudget(10, 5000.0);
        verify(expenseItemService).updateExpenseItemBudget(10, 5000.0);
    }

    @Test
    public void testGetExpenseItems_ReturnsList() {
        List<ExpenseItem> items = new ArrayList<>();
        when(expenseItemService.getExpenseItems()).thenReturn(items);

        List<ExpenseItem> result = expenseItemController.getExpenseItems();

        assertNotNull(result);
        assertEquals(0, result.size());
    }



}
