package Service;

import java.util.List;

public interface IBudgetEstimatorService {
    double calculateMovingAverage(List<Double> amounts, int period);
}
