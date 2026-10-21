package com.bc;

import java.util.List;

public class Main {

    public static void main(String[] args) {
	    FileParser fileParser = new FileParser();
	    Trainer trainer = new Trainer();
        List<Data> trainData = fileParser.readTrainData();
        List<Data> testData = fileParser.readTestData();
        List<Integer> trainLabels = fileParser.readTrainLabel();
        List<Integer> testLabels = fileParser.readTestLabel();

        trainer.train(trainData, trainLabels);
        double[] results = trainer.test(testData, testLabels);

        for (int i = 0; i < results.length; i++) {
            System.out.println("Probability of class " + (i + 1) + " : " + results[i]);
        }
    }
}
