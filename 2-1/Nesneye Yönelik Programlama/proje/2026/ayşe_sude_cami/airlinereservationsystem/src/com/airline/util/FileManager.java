package com.airline.util;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

/**
 * Dosya okuma/yazma işlemlerini yöneten yardımcı sınıf.
 * Tüm veriler dosyalarda saklanır (veritabanı kullanılmaz).
 */
public class FileManager {

    private static final String DATA_DIR = "data/";

    static {
        // Data klasörünü oluştur
        File dir = new File(DATA_DIR);
        if (!dir.exists()) {
            dir.mkdirs();
        }
    }

    /**
     * Bir nesneyi dosyaya kaydeder.
     * @param obj Kaydedilecek nesne
     * @param filename Dosya adı
     */
    public static void saveObject(Object obj, String filename) {
        try (ObjectOutputStream oos = new ObjectOutputStream(
                new FileOutputStream(DATA_DIR + filename))) {
            oos.writeObject(obj);
        } catch (IOException e) {
            System.err.println("Dosya kaydetme hatası: " + e.getMessage());
            e.printStackTrace();
        }
    }

    /**
     * Dosyadan bir nesne yükler.
     * @param filename Dosya adı
     * @return Yüklenen nesne veya null
     */
    public static Object loadObject(String filename) {
        File file = new File(DATA_DIR + filename);
        if (!file.exists()) {
            return null;
        }

        try (ObjectInputStream ois = new ObjectInputStream(
                new FileInputStream(file))) {
            return ois.readObject();
        } catch (IOException | ClassNotFoundException e) {
            System.err.println("Dosya yükleme hatası: " + e.getMessage());
            e.printStackTrace();
            return null;
        }
    }

    /**
     * Bir listeyi dosyaya kaydeder.
     * @param list Kaydedilecek liste
     * @param filename Dosya adı
     */
    public static <T> void saveList(List<T> list, String filename) {
        saveObject(new ArrayList<>(list), filename);
    }

    /**
     * Dosyadan bir liste yükler.
     * @param filename Dosya adı
     * @return Yüklenen liste veya boş liste
     */
    @SuppressWarnings("unchecked")
    public static <T> List<T> loadList(String filename) {
        Object obj = loadObject(filename);
        if (obj instanceof List) {
            return (List<T>) obj;
        }
        return new ArrayList<>();
    }

    /**
     * Dosyanın var olup olmadığını kontrol eder.
     * @param filename Dosya adı
     * @return Dosya varsa true
     */
    public static boolean fileExists(String filename) {
        return new File(DATA_DIR + filename).exists();
    }

    /**
     * Dosyayı siler.
     * @param filename Dosya adı
     * @return Silme başarılı ise true
     */
    public static boolean deleteFile(String filename) {
        return new File(DATA_DIR + filename).delete();
    }

    /**
     * Metin içeriğini dosyaya yazar.
     * @param content Yazılacak içerik
     * @param filename Dosya adı
     */
    public static void writeText(String content, String filename) {
        try (PrintWriter writer = new PrintWriter(
                new FileWriter(DATA_DIR + filename))) {
            writer.print(content);
        } catch (IOException e) {
            System.err.println("Metin yazma hatası: " + e.getMessage());
            e.printStackTrace();
        }
    }

    /**
     * Dosyadan metin okur.
     * @param filename Dosya adı
     * @return Okunan metin veya null
     */
    public static String readText(String filename) {
        File file = new File(DATA_DIR + filename);
        if (!file.exists()) {
            return null;
        }

        StringBuilder content = new StringBuilder();
        try (BufferedReader reader = new BufferedReader(
                new FileReader(file))) {
            String line;
            while ((line = reader.readLine()) != null) {
                content.append(line).append("\n");
            }
        } catch (IOException e) {
            System.err.println("Metin okuma hatası: " + e.getMessage());
            e.printStackTrace();
            return null;
        }
        return content.toString();
    }

    /**
     * Data klasöründeki tüm dosyaları listeler.
     * @return Dosya adları listesi
     */
    public static List<String> listFiles() {
        List<String> files = new ArrayList<>();
        File dir = new File(DATA_DIR);
        File[] fileList = dir.listFiles();
        if (fileList != null) {
            int i = 0;
            while (i < fileList.length) {
                File file = fileList[i];
                if (file.isFile()) {
                    files.add(file.getName());
                }
                i++;
            }
        }
        return files;
    }

    /**
     * Data klasörünü temizler (tüm dosyaları siler).
     */
    public static void clearAllData() {
        File dir = new File(DATA_DIR);
        File[] files = dir.listFiles();
        if (files != null) {
            int i = 0;
            while (i < files.length) {
                File file = files[i];
                file.delete();
                i++;
            }
        }
    }

    /**
     * Data klasörünün yolunu döndürür.
     */
    public static String getDataDirectory() {
        return DATA_DIR;
    }
}
