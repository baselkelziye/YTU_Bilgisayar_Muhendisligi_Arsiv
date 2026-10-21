package com.bc;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class FileParser {

    private static final String DATA_PREFIX = "data/";
    private static final String TRAIN_DATA_PATH = "train.data";
    private static final String TRAIN_LABEL_PATH = "train.label";
    private static final String TEST_DATA_PATH = "test.data";
    private static final String TEST_LABEL_PATH = "test.label";

    private static final String LABELS_PATH = "labels.txt";

    private static final String VOCABS = "vocabs.txt";

    public List<Data> readTrainData() {
        return readData(TRAIN_DATA_PATH);
    }

    public List<Data> readTestData() {
        return readData(TEST_DATA_PATH);
    }

    public List<Integer> readTrainLabel() {
        return readLabel(TRAIN_LABEL_PATH);
    }

    public List<Integer> readTestLabel() {
        return readLabel(TEST_LABEL_PATH);
    }

    private List<Data> readData(String path) {
        final List<Data> retVal = new ArrayList<>();
        AtomicInteger dictionarySize = new AtomicInteger();
        readFile(path, line -> {
            Data newData = new Data(readDataLine(line));
            retVal.add(newData);
            if (newData.getWordId() > dictionarySize.intValue()) {
                dictionarySize.set(newData.getWordId());
            }
            return line;
        });
        Trainer.NUMBER_OF_WORDS = dictionarySize.intValue();
        return retVal;
    }

    private List<Integer> readLabel(String path) {
        final List<Integer> retVal = new ArrayList<>();
        readFile(path, line -> {
            retVal.add(Integer.parseInt(line));
            return line;
        });
        return retVal;
    }

    private List<Integer> readDataLine(String line) {
        return Arrays.stream(line.split(" "))
                    .map(part -> Integer.parseInt(part))
                    .collect(Collectors.toList());
    }

    private void readFile(String fileName, Function<String, String> function) {
        try (Stream<String> stream = Files.lines(Paths.get(DATA_PREFIX + fileName))) {
            stream.forEach(line -> {
                function.apply(line);
            });
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
