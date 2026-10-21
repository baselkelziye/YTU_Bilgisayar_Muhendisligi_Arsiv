package com.airline.util;

import java.io.*;
import java.util.*;

public class FileUtil {

    private static void ensureFileExists(String filePath) {
        try {
            File file = new File(filePath);
            File parent = file.getParentFile();

            if (parent != null && !parent.exists()) {
                parent.mkdirs();
            }

            if (!file.exists()) {
                file.createNewFile();
            }
        } catch (IOException e) {
            System.out.println("File creation failed: " + filePath);
        }
    }

    public static List<String> readAllLines(String filePath) {
        ensureFileExists(filePath);

        List<String> lines = new ArrayList<>();
        File file = new File(filePath);

        if (!file.exists()) return null;

        try (BufferedReader br = new BufferedReader(new FileReader(file))) {
            String line;
            while((line = br.readLine()) != null){
                lines.add(line);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return lines;
    }

    public static void writeAllLines(String filePath, List<String> lines) {
        ensureFileExists(filePath);

        File file = new File(filePath);
        file.getParentFile().mkdirs();

        try (BufferedWriter bw = new BufferedWriter(new FileWriter(file))) {
            for(String line : lines){
                bw.write(line);
                bw.newLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}