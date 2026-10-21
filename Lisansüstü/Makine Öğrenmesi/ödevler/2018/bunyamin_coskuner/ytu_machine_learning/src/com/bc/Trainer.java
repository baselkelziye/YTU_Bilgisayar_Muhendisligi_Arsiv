package com.bc;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.stream.Collectors;

public class Trainer {

    public static final int NUMBER_OF_CLASSES = 20;
    public static int NUMBER_OF_WORDS;
    private double[] probOfClass = new double[NUMBER_OF_CLASSES];
    private double[][] probOfEachWordGivenClass;
    private int[] correctGuesses = new int[NUMBER_OF_CLASSES];
    private int[] wrongGuesses = new int[NUMBER_OF_CLASSES];

    public void train(List<Data> data, List<Integer> labels) {
        calculateProbsOfEachClass(labels);
        probOfEachWordGivenClass = new double[NUMBER_OF_WORDS][NUMBER_OF_CLASSES];
        int[] eachClassWordCount = new int[NUMBER_OF_CLASSES];
        data.forEach(row -> {
            int docId = labels.get(row.getDocId() - 1) - 1;
            int wordId = row.getWordId();
            eachClassWordCount[docId] += row.getCount();
            probOfEachWordGivenClass[wordId][docId] += row.getCount();
        });

        // for avoiding 0's
        double alpha = 0.001;

        for (int i = 0; i < probOfEachWordGivenClass.length; i++) {
            for (int j = 0; j < NUMBER_OF_CLASSES; j++) {
                probOfEachWordGivenClass[i][j] =
                        (probOfEachWordGivenClass[i][j] + alpha) /
                        (eachClassWordCount[j] + NUMBER_OF_WORDS);
            }
        }
    }

    public double[] test(List<Data> testData, List<Integer> testLabels) {
        final AtomicInteger currentId = new AtomicInteger(testData.get(0).getDocId());
        final List<Data> dataGroups = new ArrayList<>();
        testData.forEach(row -> {
            if (row.getDocId() == currentId.intValue()) {
                dataGroups.add(row);
            } else {
                // it's time to classify
                int guess = classify(dataGroups);

                // since, arrays start at 0, and our classes start at 1, we need to decrement by 1
                int truth = testLabels.get(currentId.intValue()) - 1;
                boolean result = guess ==  truth;
                if (result) {
                    correctGuesses[truth]++;
                } else {
                    wrongGuesses[truth]++;
                }
                dataGroups.clear();
                currentId.set(row.getDocId());
            }
        });

        double[] results = new double[NUMBER_OF_CLASSES];

        for (int i = 0; i < NUMBER_OF_CLASSES; i++) {
            results[i] = correctGuesses[i] * 1.0 / (correctGuesses[i] + wrongGuesses[i]);
        }

        return results;
    }

    private int classify(List<Data> dataGroups) {
        double[] probabilities = new double[NUMBER_OF_CLASSES];
        for (int i = 0; i < NUMBER_OF_CLASSES; i++) {
            probabilities[i] = Math.log(probOfClass[i]);

            double sum = 0;
            for (Data data: dataGroups) {
                int frequency = data.getCount();
                double probability = probOfEachWordGivenClass[data.getWordId()][i];

                // in order to work with better numbers,
                // let's take log of the calculation
                sum += frequency * Math.log(probability);
            }
            probabilities[i] += sum;
        }

        // find the index of class with greatest probability
        int index = 0;
        double max = probabilities[index];
        for (int i = 1; i < NUMBER_OF_CLASSES; i++) {
            if (probabilities[i] > max) {
                max = probabilities[i];
                index = i;
            }
        }

        return index;
    }

    private void calculateProbsOfEachClass(List<Integer> labels) {
        labels.forEach(label -> probOfClass[label - 1]++);
        probOfClass = Arrays.stream(probOfClass)
                        .map(probOfClass -> probOfClass / labels.size())
                        .toArray();
    }
}
