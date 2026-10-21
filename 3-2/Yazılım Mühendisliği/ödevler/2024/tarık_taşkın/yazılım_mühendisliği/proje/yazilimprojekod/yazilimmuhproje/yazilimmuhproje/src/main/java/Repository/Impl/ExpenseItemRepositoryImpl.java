package Repository.Impl;

import Entities.ExpenseItem;
import Repository.IExpenseItemRepository;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class ExpenseItemRepositoryImpl implements IExpenseItemRepository {

    private final Connection connection;
    public ExpenseItemRepositoryImpl(Connection connection) {
        this.connection = connection;
    }
    
    @Override
    public List<ExpenseItem> getExpenseItems() {
        List<ExpenseItem> expenseItems = new ArrayList<>();

        String sql = "SELECT id, name, budget, threshold_percent, max_limit, used_budget, department_id FROM expense_items ORDER BY id";

        try (PreparedStatement stmt = connection.prepareStatement(sql)) {
            ResultSet rs = stmt.executeQuery();

            while (rs.next()) {
                int id = rs.getInt("id");
                String name = rs.getString("name");
                double budget = rs.getDouble("budget");
                double thresholdPercent = rs.getDouble("threshold_percent");
                double maxLimit = rs.getDouble("max_limit");
                double usedBudget = rs.getDouble("used_budget");
                int deptId = rs.getInt("department_id");

                ExpenseItem item = new ExpenseItem(id, name, budget, thresholdPercent, maxLimit, usedBudget, deptId);
                expenseItems.add(item);
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }

        return expenseItems;
    }

    @Override
    public void updateUsedBudget(int expenseItemId, double amountToAdd) {
        String sql = "UPDATE expense_items SET used_budget = used_budget + ? WHERE id = ?";
        try (PreparedStatement statement = connection.prepareStatement(sql)) {
            statement.setDouble(1, amountToAdd);
            statement.setInt(2, expenseItemId);
            statement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    @Override
    public void updateExpenseItemBudget(int expenseItemId, double newBudget) {
        String sql2 = "SELECT max_limit, budget FROM expense_items WHERE id = ?";
        double max_limit = 0, budget = 0;
        
        try (PreparedStatement statement = connection.prepareStatement(sql2)) {
            statement.setInt(1, expenseItemId);
            try (ResultSet resultSet = statement.executeQuery()) {
                if (resultSet.next()) {
                    max_limit = resultSet.getDouble("max_limit");
                    budget = resultSet.getDouble("budget");
                }
            }
            
            
            
        } catch (SQLException e) {
            e.printStackTrace();
        }
        
        double newMaxLimit = (max_limit - budget) + newBudget;
        
        String sql = "UPDATE expense_items SET budget = ?, max_limit = ? WHERE id = ?";
        
        try (PreparedStatement statement = connection.prepareStatement(sql)) {
            statement.setDouble(1, newBudget);
            statement.setDouble(2, newMaxLimit);
            statement.setInt(3, expenseItemId);
            statement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

}
