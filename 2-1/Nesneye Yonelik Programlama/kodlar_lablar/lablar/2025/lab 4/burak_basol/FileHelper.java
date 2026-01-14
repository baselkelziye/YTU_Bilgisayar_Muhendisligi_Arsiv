import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Map;

public class FileHelper {
    public void logAction(String fileName, String message) throws IOException {
        BufferedWriter bw = new BufferedWriter(new FileWriter(fileName)); // append modda nasıl açacağımı bilmiyorum
        try {
            bw.write(message);
        } catch (IOException e) {
            e.printStackTrace();
        }

        bw.close();
    }

    public void saveInventory(String fileName, Map<Integer, Product> inventory) throws IOException {
        BufferedWriter bw = new BufferedWriter(new FileWriter(fileName));
        String s = "";
        s += "---Depo Durumu---\n";
        for (Map.Entry<Integer, Product> entry : inventory.entrySet()) {
            s += "Urun: " + entry.getValue().getName() + " | Stok: " + entry.getValue().getStock() + "\n";
        }

        try {
            bw.write(s);
        }
        catch (IOException e) {
            e.printStackTrace();
        }
        bw.close();
    }
}

//private class FileHelper {

    //void writeFile(String file) throws IOException {
    //    ArrayList<Integer> list = new ArrayList<>();

    //    for (int i = 0; i < 100; i++) list.add(1);
    //   for (int i = 0; i < 90; i++)  list.add(-1);

     //   Collections.shuffle(list);

     //   BufferedWriter w = new BufferedWriter(new FileWriter(file));
     //   for (int v : list)
     //       w.write(v + "\n");
    //    w.close();
   // }

 //   Object[] readFile(String file) throws IOException {
 //       ArrayList<Object> list = new ArrayList<>();
//        BufferedReader r = new BufferedReader(new FileReader(file));
 //       String line;

   //     while ((line = r.readLine()) != null)
   //         list.add(Integer.parseInt(line));

   //     r.close();
   //     return list.toArray();
