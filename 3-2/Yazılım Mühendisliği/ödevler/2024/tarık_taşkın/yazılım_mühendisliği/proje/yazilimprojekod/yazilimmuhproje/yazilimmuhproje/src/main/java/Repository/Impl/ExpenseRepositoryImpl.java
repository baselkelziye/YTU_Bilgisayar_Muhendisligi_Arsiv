package Repository.Impl;

import DTO.ExpenseReportDto;
import Entities.Expense;
import Entities.ExpenseItem;
import Repository.IExpenseRepository;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Timestamp;
import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.List;

public class ExpenseRepositoryImpl implements IExpenseRepository {
    private final Connection connection;

    public ExpenseRepositoryImpl(Connection connection) {
        this.connection = connection;
    }

    @Override
    public List<ExpenseReportDto> getGroupedExpenseReports() {
        List<ExpenseReportDto> reports = new ArrayList<>();

        String sql = """
                        SELECT 
                            e.user_id,
                            u.department_id,
                            e.expense_item_id,
                            TO_CHAR(e.created_at, 'YYYY-MM') AS month_year,
                            SUM(e.amount) AS total_amount
                        FROM expenses e
                        JOIN users u ON e.user_id = u.id
                        WHERE e.status = 'PAID'
                        GROUP BY e.user_id, u.department_id, e.expense_item_id, month_year
                        ORDER BY month_year ASC
                    """;


        try (PreparedStatement stmt = connection.prepareStatement(sql);
             ResultSet rs = stmt.executeQuery()) {

            while (rs.next()) {
                ExpenseReportDto dto = new ExpenseReportDto();
                dto.setUserId(rs.getInt("user_id"));
                dto.setDepartmentId(rs.getInt("department_id"));
                dto.setExpenseItemId(rs.getInt("expense_item_id"));
                dto.setMonthYear(rs.getString("month_year"));
                dto.setTotalAmount(rs.getDouble("total_amount"));

                reports.add(dto);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        return reports;
    }
    
    @Override
    public List<Expense> getPendingExpensesByDepartmentID(int department_id) {
        List<Expense> expenses = new ArrayList<>();
        
        String sql = """
                        SELECT 
                            e.id,
                            e.user_id,
                            e.expense_item_id,
                            e.amount,
                            e.status,
                            e.created_at,
                            e.document_path
                        FROM expenses e
                        JOIN users u ON e.user_id = u.id
                        WHERE e.status = 'PENDING' and u.department_id = ?
                        ORDER BY created_at ASC
                    """;
        
            try (PreparedStatement stmt = connection.prepareStatement(sql)) {

            stmt.setInt(1, department_id);
            ResultSet rs = stmt.executeQuery();

            while (rs.next()) {
                int id = rs.getInt("id");
                int userId = rs.getInt("user_id");
                int expenseItemId = rs.getInt("expense_item_id");
                double amount = rs.getDouble("amount");
                String status = rs.getString("status");
                Timestamp createdAtTs = rs.getTimestamp("created_at");
                LocalDateTime createdAt = createdAtTs.toLocalDateTime();
                String documentPath = rs.getString("document_path");

                Expense expense = new Expense(id, userId, expenseItemId, amount, status, createdAt, documentPath);
                expenses.add(expense);
            }

        } catch (SQLException e) {
            e.printStackTrace(); // veya logger ile loglayabilirsin
        }

        return expenses;
    }
    
    @Override
    public List<Expense> getApprovedExpensesByDepartmentID(int department_id) {
        List<Expense> expenses = new ArrayList<>();
        
        String sql = """
                        SELECT 
                            e.id,
                            e.user_id,
                            e.expense_item_id,
                            e.amount,
                            e.status,
                            e.created_at,
                            e.document_path
                        FROM expenses e
                        JOIN users u ON e.user_id = u.id
                        WHERE e.status = 'APPROVED' and u.department_id = ?
                        ORDER BY created_at ASC
                    """;
        
            try (PreparedStatement stmt = connection.prepareStatement(sql)) {

            stmt.setInt(1, department_id);
            ResultSet rs = stmt.executeQuery();

            while (rs.next()) {
                int id = rs.getInt("id");
                int userId = rs.getInt("user_id");
                int expenseItemId = rs.getInt("expense_item_id");
                double amount = rs.getDouble("amount");
                String status = rs.getString("status");
                Timestamp createdAtTs = rs.getTimestamp("created_at");
                LocalDateTime createdAt = createdAtTs.toLocalDateTime();
                String documentPath = rs.getString("document_path");

                Expense expense = new Expense(id, userId, expenseItemId, amount, status, createdAt, documentPath);
                expenses.add(expense);
            }

        } catch (SQLException e) {
            e.printStackTrace(); // veya logger ile loglayabilirsin
        }

        return expenses;
    }

    @Override
    public void sendNotificationToAllUsers(String message) {
        System.out.println("🔔 BİLDİRİM: " + message);
    }

    @Override
    public void rejectExpense(int expenseId) {
        String sql = "UPDATE expenses SET status = 'REJECTED' WHERE id = ?";
        try (PreparedStatement statement = connection.prepareStatement(sql)) {
            statement.setInt(1, expenseId);
            statement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void payPartialExpense(int expenseId) {
        // amount alanı DEĞİŞTİRİLMEMELİ!
        String sql = "UPDATE expenses SET status = 'PAID' WHERE id = ?";
        try (PreparedStatement statement = connection.prepareStatement(sql)) {
            statement.setInt(1, expenseId);
            statement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    @Override
    public ExpenseItem getExpenseItemById(int expenseItemId) {
        String sql = "SELECT * FROM expense_items WHERE id = ?";
        try (PreparedStatement statement = connection.prepareStatement(sql)) {
            statement.setInt(1, expenseItemId);
            var resultSet = statement.executeQuery();
            if (resultSet.next()) {
                ExpenseItem item = new ExpenseItem();
                item.setId(resultSet.getInt("id"));
                item.setName(resultSet.getString("name"));
                item.setBudget(resultSet.getDouble("budget"));
                item.setThresholdPercent(resultSet.getDouble("threshold_percent"));
                item.setMaxLimit(resultSet.getDouble("max_limit"));
                item.setUsedBudget(resultSet.getDouble("used_budget")); // 📢 eksik olan burası!
                return item;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }


    @Override
    public Expense getExpenseById(int expenseId) {
        String sql = "SELECT * FROM expenses WHERE id = ?";
        try (PreparedStatement statement = connection.prepareStatement(sql)) {
            statement.setInt(1, expenseId);
            var resultSet = statement.executeQuery();
            if (resultSet.next()) {
                Expense expense = new Expense();
                expense.setId(resultSet.getInt("id"));
                expense.setUserId(resultSet.getInt("user_id"));
                expense.setExpenseItemId(resultSet.getInt("expense_item_id"));
                expense.setAmount(resultSet.getDouble("amount"));
                expense.setStatus(resultSet.getString("status"));
                expense.setCreatedAt(resultSet.getTimestamp("created_at").toLocalDateTime());
                return expense;
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    @Override
    public void correctExpenseItem(int expenseId, int newExpenseItemId) {
        String sql = "UPDATE expenses SET expense_item_id = ? WHERE id = ?";
        try (PreparedStatement statement = connection.prepareStatement(sql)) {
            statement.setInt(1, newExpenseItemId);
            statement.setInt(2, expenseId);
            statement.executeUpdate();
            System.out.println("Harcama kalemi düzeltildi ✅");
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void submitExpenseDocument(int expenseId, String documentPath) {
        String checkStatusSql = "SELECT status FROM expenses WHERE id = ?";
        String updateDocumentSql = "UPDATE expenses SET document_path = ? WHERE id = ?";

        try (PreparedStatement checkStmt = connection.prepareStatement(checkStatusSql)) {
            checkStmt.setInt(1, expenseId);
            var resultSet = checkStmt.executeQuery();

            if (resultSet.next()) {
                String status = resultSet.getString("status");
                if (!"APPROVED".equalsIgnoreCase(status)) {
                    System.out.println("Harcama henüz onaylanmamış. Belge eklenemez ❌");
                    return;
                }
            } else {
                System.out.println("Harcama bulunamadı ❌");
                return;
            }

            try (PreparedStatement updateStmt = connection.prepareStatement(updateDocumentSql)) {
                updateStmt.setString(1, documentPath);
                updateStmt.setInt(2, expenseId);
                updateStmt.executeUpdate();
                System.out.println("Belge başarıyla yüklendi ✅");
            }

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    @Override
    public void addExpense(Expense expense) {
        String sql = "INSERT INTO expenses (user_id, expense_item_id, amount, status, created_at, document_path) VALUES (?, ?, ?, ?, ?, ?)";
        try (PreparedStatement statement = connection.prepareStatement(sql)) {
            statement.setInt(1, expense.getUserId());
            statement.setInt(2, expense.getExpenseItemId());
            statement.setDouble(3, expense.getAmount());
            statement.setString(4, expense.getStatus());
            statement.setObject(5, expense.getCreatedAt());
            statement.setString(6, expense.getDocumentPath());
            statement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
    @Override
    public void approveExpense(int expenseId) {
        String sql = "UPDATE expenses SET status = 'APPROVED' WHERE id = ?";
        try (PreparedStatement statement = connection.prepareStatement(sql)) {
            statement.setInt(1, expenseId);
            statement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

}
