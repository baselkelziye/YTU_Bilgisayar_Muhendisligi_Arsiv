import java.io.IOException;
import java.time.LocalDateTime;
import java.util.HashMap;
import java.util.Map;

public class Warehouse {
    private String name;
    private Map<Integer, Product> inventory;
    private int maxCapacity;

    public Warehouse(String name, int maxCapacity) {
        this.name = name;
        this.maxCapacity = maxCapacity;
        this.inventory = new HashMap<>();
    }

    public void addProduct(Product p) {
        this.inventory.put(p.getId(), p);
    }

    public boolean isFull(int amount) {
        int count = inventory.size();
        return (count + amount) > maxCapacity;
    }

    public synchronized void updateAndLog(Product p, int amount, FileHelper helper) throws IOException {
        String data = "Time: " + LocalDateTime.now();
        data +="\nSuanda islem yapan thread:" + Thread.currentThread().getName();
        System.out.println("Suanda islem yapan thread:" + Thread.currentThread().getName());
        if (isFull(amount)) {
            System.out.println("Hata: Depo kapasitesi asildi! Islem yapilamiyor: " + p.getName());
            data += "\nHata: Depo kapasitesi asildi! Islem yapilamiyor: " + p.getName();
        }
        else if (inventory.size() + amount < 0) {
            System.out.println("Hata: Depoda yeterli stok yok! Urun: " + p.getName());
            data += "\nHata: Depoda yeterli stok yok! Urun: " + p.getName();
        }
        else  {
            if (amount > 0) {
                for (int i = 0; i < amount; i++) {
                    inventory.put(p.getId(), p);
                }
                System.out.println("TEDARIK (+) Urun: " + p.getName() + " Miktar: " + amount + " Guncel Stok: " + this.inventory.size());
                data += "\nTEDARIK (+) Urun: " + p.getName() + " Miktar: " + amount  + " Guncel Stok: " + this.inventory.size();
            }
            else {
                for (int i = 0; i < -amount; i++) {
                    inventory.remove(p.getId());
                }
                System.out.println("SATIS (-) Urun: " + p.getName() + " Miktar: " + (-amount) + " Guncel Stok: " + this.inventory.size());
                data += "\nSATIS (-) Urun: " + p.getName() + " Miktar: " + (-amount) + " Guncel Stok: " + this.inventory.size();
            }
        }

        helper.logAction("logdata.txt",data);
    }

    public Map<Integer, Product> getInventory() {
        return inventory;
    }

    @Override
    public String toString() {
        String s = "";
        s += "\n\n---Depo Durumu---\n";
        for (Map.Entry<Integer, Product> entry : inventory.entrySet()) {
            s += "Urun: " + entry.getValue().getName() + " | Stok: " + entry.getValue().getStock() + "\n";
        }
        return s;
    }
}
