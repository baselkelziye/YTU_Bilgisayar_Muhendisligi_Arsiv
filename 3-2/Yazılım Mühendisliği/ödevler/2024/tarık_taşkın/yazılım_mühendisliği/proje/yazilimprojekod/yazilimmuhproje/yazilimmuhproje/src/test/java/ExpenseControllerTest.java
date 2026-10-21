

import Controller.ExpenseController;
import DTO.ExpenseReportDto;
import Repository.IExpenseRepository;
import Repository.Impl.ExpenseRepositoryImpl;
import Service.IExpenseService;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import static org.mockito.Mockito.*;
import org.mockito.ArgumentCaptor;
import Entities.Expense;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.*;

import static org.junit.jupiter.api.Assertions.*;
import static org.mockito.Mockito.*;

public class ExpenseControllerTest {


    private IExpenseService expenseService;
    private ExpenseController expenseController;
    private IExpenseRepository expenseRepository;
    private Connection mockConnection;
    private PreparedStatement mockStatement;
    @BeforeEach
    public void setUp() throws SQLException {
        expenseService = mock(IExpenseService.class);
        expenseController = new ExpenseController(expenseService);
        mockConnection = mock(Connection.class);
        mockStatement = mock(PreparedStatement.class);

        // SQL prepare işlemi yapılınca sahte statement dönsün
        when(mockConnection.prepareStatement(anyString())).thenReturn(mockStatement);

        // expenseRepository içinde mockConnection kullanılacak şekilde sahte instance oluştur
         expenseRepository = new ExpenseRepositoryImpl(mockConnection); // constructor buna göre olmalı


    }

    // ExpenseControllerTest.java
    @Test
    public void testShowExpenseReport_ReturnsList() {
        List<ExpenseReportDto> mockList = new ArrayList<>();
        when(expenseService.getGroupedExpenseReports()).thenReturn(mockList);

        List<ExpenseReportDto> result = expenseController.showExpenseReports();

        assertNotNull(result);
        assertEquals(0, result.size());
    }

    // ExpenseControllerTest.java

    @Test
    public void testGetPendingExpensesByDepartmentID_ReturnsList() {
        List<Expense> mockList = new ArrayList<>();
        when(expenseService.getPendingExpensesByDepartmentID(5)).thenReturn(mockList);

        List<Expense> result = expenseController.getPendingExpensesByDepartmentID(5);

        assertNotNull(result);
        assertEquals(0, result.size());
        verify(expenseService).getPendingExpensesByDepartmentID(5);
    }

    @Test
    public void testGetApprovedExpensesByDepartmentID_ReturnsList() {
        List<Expense> mockList = new ArrayList<>();
        when(expenseService.getApprovedExpensesByDepartmentID(3)).thenReturn(mockList);

        List<Expense> result = expenseController.getApprovedExpensesByDepartmentID(3);

        assertNotNull(result);
        assertEquals(0, result.size());
        verify(expenseService).getApprovedExpensesByDepartmentID(3);
    }

    @Test
    public void testProcessExpensePayment_ReturnsString() {
        String expected = "Success";
        when(expenseService.processExpensePayment(7)).thenReturn(expected);

        String result = expenseController.processExpensePayment(7);

        assertEquals(expected, result);
        verify(expenseService).processExpensePayment(7);
    }

    @Test
    public void testCorrectExpenseItem_CallsServiceCorrectly() {
        expenseController.correctExpenseItem(10, 99);
        verify(expenseService).correctExpenseItem(10, 99);
    }

    // ExpenseControllerTest.java
    @Test
    public void testAddExpense_CreatesAndPassesCorrectExpense() {
        int userId = 1;
        int expenseItemId = 2;
        double amount = 100.0;
        String documentPath = "test.pdf";

        expenseController.addExpense(userId, expenseItemId, amount, documentPath);

        // ArgumentCaptor ile Expense objesinin içeriğini kontrol ediyoruz
        ArgumentCaptor<Expense> expenseCaptor = ArgumentCaptor.forClass(Expense.class);
        verify(expenseService).addExpense(expenseCaptor.capture());

        Expense capturedExpense = expenseCaptor.getValue();
        assertEquals(userId, capturedExpense.getUserId());
        assertEquals(expenseItemId, capturedExpense.getExpenseItemId());
        assertEquals(amount, capturedExpense.getAmount());
        assertEquals(documentPath, capturedExpense.getDocumentPath());
    }

    @Test
    void testRejectExpense_UpdatesStatusToRejected() throws SQLException {
        int testExpenseId = 123;

        // Metodu çağır
        expenseRepository.rejectExpense(testExpenseId);

        // Doğru SQL sorgusu ile hazırlama yapılmış mı?
        verify(mockConnection).prepareStatement("UPDATE expenses SET status = 'REJECTED' WHERE id = ?");

        // Doğru parametre atanmış mı?
        verify(mockStatement).setInt(1, testExpenseId);

        // executeUpdate çağrılmış mı?
        verify(mockStatement).executeUpdate();
    }

}
