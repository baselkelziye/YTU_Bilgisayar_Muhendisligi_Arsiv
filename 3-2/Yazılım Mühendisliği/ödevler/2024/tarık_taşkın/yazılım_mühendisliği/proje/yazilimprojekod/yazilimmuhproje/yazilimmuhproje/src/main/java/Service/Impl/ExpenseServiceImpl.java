package Service.Impl;

import DTO.ExpenseReportDto;
import Entities.Expense;
import Entities.ExpenseItem;
import Repository.IExpenseItemRepository;
import Repository.IExpenseRepository;
import Service.IBudgetEstimatorService;
import Service.IExpenseService;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ExpenseServiceImpl implements IExpenseService {
    private final IExpenseRepository expenseRepository;
    private final IExpenseItemRepository expenseItemRepository;

    public ExpenseServiceImpl(IExpenseRepository expenseRepository, IExpenseItemRepository expenseItemRepository) {
        this.expenseRepository = expenseRepository;
        this.expenseItemRepository = expenseItemRepository;
    }

    public Map<Integer, Double> getDepartmentBudgetEstimates(int period) {
        List<ExpenseReportDto> allReports = expenseRepository.getGroupedExpenseReports();
        BudgetEstimatorServiceImpl estimator = new BudgetEstimatorServiceImpl();

        Map<Integer, List<Double>> departmentExpenseMap = new HashMap<>();
        Map<Integer, Double> departmentEstimates = new HashMap<>();

        for (ExpenseReportDto dto : allReports) {
            /*System.out.println("DEBUG: userId=" + dto.getUserId() +
                    ", dept=" + dto.getDepartmentId() +
                    ", amount=" + dto.getTotalAmount() +
                    ", date=" + dto.getMonthYear());*/

            int departmentId = dto.getDepartmentId();
            departmentExpenseMap.putIfAbsent(departmentId, new ArrayList<>());
            departmentExpenseMap.get(departmentId).add(dto.getTotalAmount());
        }

        for (Map.Entry<Integer, List<Double>> entry : departmentExpenseMap.entrySet()) {
            int departmentId = entry.getKey();
            List<Double> expenses = entry.getValue();

            if (!expenses.isEmpty()) {
                int effectivePeriod = Math.min(expenses.size(), period);
                double estimate = estimator.calculateMovingAverage(expenses, effectivePeriod);
                departmentEstimates.put(departmentId, estimate);
            }
            else {
                System.out.println("INFO: Departman " + departmentId + " için yeterli veri yok, veri adedi=" + expenses.size());
            }
        }

        return departmentEstimates;
    }


    @Override
    public double getTotalBudgetEstimate(int period) {
        Map<Integer, Double> departmentEstimates = getDepartmentBudgetEstimates(period);
        double total = 0.0;
        for (double estimate : departmentEstimates.values()) {
            total += estimate;
        }
        return total;
    }

    @Override
    public List<ExpenseReportDto> getGroupedExpenseReports() {
        return expenseRepository.getGroupedExpenseReports();
    }
    
    @Override
    public List<Expense> getPendingExpensesByDepartmentID(int department_id) {
        return expenseRepository.getPendingExpensesByDepartmentID(department_id);
    }
    
    @Override
    public List<Expense> getApprovedExpensesByDepartmentID(int department_id) {
        return expenseRepository.getApprovedExpensesByDepartmentID(department_id);
    }         
    
    @Override
    public String processExpensePayment(int expenseId) {
        Expense expense = expenseRepository.getExpenseById(expenseId);
        if (expense == null) {
            System.out.println("Harcama bulunamadı ❌");
            return "Harcama bulunamadı!";
        }
        if (!"APPROVED".equalsIgnoreCase(expense.getStatus())) {
            System.out.println("Harcama henüz onaylanmamış, ödeme yapılamaz ❌");
            return "Harcama henüz onaylanmamış!";
        }

        ExpenseItem item = expenseRepository.getExpenseItemById(expense.getExpenseItemId());
        if (item == null) {
            System.out.println("Harcama kalemi bulunamadı ❌");
            return "Harcama kalemi bulunamadı!";
        }

        double amount = expense.getAmount();
        double budget = item.getBudget();
        double maxLimit = item.getMaxLimit();
        double used = item.getUsedBudget();
        System.out.println("Amount " + amount + " TL");
        System.out.println("Budget " + budget + " TL");
        System.out.println("MaxLimit " + maxLimit + " TL");
        System.out.println("used " + used + " TL");
        double newUsed = used + amount;

        System.out.println("NewUsed " + newUsed + " TL");
        if (newUsed <= budget) {
            // 🔵 TAM ÖDEME
            expenseRepository.payPartialExpense(expenseId);
            expenseItemRepository.updateUsedBudget(item.getId(), amount);
            System.out.println("Tam ödeme yapıldı ✅ (amount = " + amount + " TL)");
            return "Tam ödeme yapıldı!";
        }
        else if (newUsed <= maxLimit && newUsed > budget) {
            // 🟡 KISMİ ÖDEME (budget - used kadar ödeme yapılacak)
            double payable = budget - newUsed;
                if(payable>=0)
                {
                    // Ödenecek miktar varsa kısmi ödeme yapılır
                    expenseRepository.payPartialExpense(expenseId);
                    expenseItemRepository.updateUsedBudget(item.getId(), amount);
                    expenseRepository.sendNotificationToAllUsers(
                            "⚠️ Uyarı: '" + item.getName() + "' kaleminde bütçe sınırı aşıldı. Sadece " + payable + " TL ödenebildi."
                    );
                    System.out.println("Kısmi ödeme yapıldı ✅ (payable = " + payable + " TL)");
                    return "Kısmi ödeme yapıldı! (%.2f TL)".formatted(payable);
                }else{
                    expenseRepository.payPartialExpense(expenseId);
                    expenseItemRepository.updateUsedBudget(item.getId(), amount);
                    expenseRepository.sendNotificationToAllUsers(
                            "⚠️ Uyarı: '" + item.getName() + "' kaleminde bütçe sınırı aşıldı. Sadece 0.0 TL ödenebildi."
                    );
                    System.out.println("Kısmi ödeme yapıldı ✅ (payable = 0.0 TL)");
                    return "Bütçe sınırı aşıldı, ödeme yapılamadı!";
                }


        }
        else if(newUsed > maxLimit){
            // 🔴 RED
            expenseRepository.rejectExpense(expenseId);
            expenseRepository.sendNotificationToAllUsers(
                    "❌ '" + item.getName() + "' harcama kalemi limit aşıldı! Harcama reddedildi."
            );
            System.out.println("Üst limit aşıldı, ödeme reddedildi ❌");
            return "Üst limit aşıldı, ödeme reddedildi!";
        }
        return "";
    }




    @Override
    public void correctExpenseItem(int expenseId, int newExpenseItemId) {
        expenseRepository.correctExpenseItem(expenseId, newExpenseItemId);
    }

    @Override
    public void submitExpenseDocument(int expenseId, String documentPath) {
        expenseRepository.submitExpenseDocument(expenseId, documentPath);
    }

    @Override
    public void addExpense(Expense expense) {
        expenseRepository.addExpense(expense);
    }
    @Override
    public void approveExpense(int expenseId) {
        expenseRepository.approveExpense(expenseId);
    }

}
