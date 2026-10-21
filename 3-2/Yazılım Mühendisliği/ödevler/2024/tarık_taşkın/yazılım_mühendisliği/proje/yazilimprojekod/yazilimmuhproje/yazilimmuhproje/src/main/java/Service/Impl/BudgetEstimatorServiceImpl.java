package Service.Impl;

import Service.IBudgetEstimatorService;
import java.util.List;

public class BudgetEstimatorServiceImpl implements IBudgetEstimatorService {

    @Override
    public double calculateMovingAverage(List<Double> amounts, int period) {
        if (amounts == null || amounts.isEmpty()) {
            throw new IllegalArgumentException("Geçmiş veriler boş olamaz.");
        }
        if (period <= 0) {
            throw new IllegalArgumentException("Periyot pozitif olmalı.");
        }
        if (amounts.size() < period) {
            throw new IllegalArgumentException("Yeterli veri yok. İstenen periyottan daha az veri var.");
        }

        double sum = 0.0;
        int startIndex = amounts.size() - period;

        for (int i = startIndex; i < amounts.size(); i++) {
            sum += amounts.get(i);
        }

        return sum / period;
    }
}

