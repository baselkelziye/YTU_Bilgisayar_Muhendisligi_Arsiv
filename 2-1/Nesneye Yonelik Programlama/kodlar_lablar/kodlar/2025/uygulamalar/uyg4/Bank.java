package Uyg4;

import java.io.*;
import java.util.*;

public class Bank {

    private String name;
    private Map<Integer, Account> accounts = new HashMap<>();

    public Bank(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void addAccount(Account acc) {
        accounts.put(acc.getId(), acc);
    }

    public Account getAccount(int id) {
        return accounts.get(id);
    }

    private class FileHelper {

        void writeFile(String file) throws IOException {
            ArrayList<Integer> list = new ArrayList<>();

            for (int i = 0; i < 100; i++) list.add(1);
            for (int i = 0; i < 90; i++)  list.add(-1);

            Collections.shuffle(list);

            BufferedWriter w = new BufferedWriter(new FileWriter(file));
            for (int v : list)
                w.write(v + "\n");
            w.close();
        }

        Object[] readFile(String file) throws IOException {
            ArrayList<Object> list = new ArrayList<>();
            BufferedReader r = new BufferedReader(new FileReader(file));
            String line;

            while ((line = r.readLine()) != null)
                list.add(Integer.parseInt(line));

            r.close();
            return list.toArray();
        }
    }

    public void createDataFile(String file) throws IOException {
        new FileHelper().writeFile(file);
    }

    public Object[] loadData(String file) throws IOException {
        return new FileHelper().readFile(file);
    }
}
