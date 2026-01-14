package sevval_cabuk;

public class Main {
    public static void main(String[] args) throws Exception {
        Warehouse warehouse = new Warehouse("Akademik Depo",60);
        FileHelper helper = new FileHelper();

        Product p1 = new Product(101, "Islemci", 20);
        Product p2 = new Product(102, "Ekran Karti", 10);
        Product p3 = new Product(103, "Anakart", 20);

        warehouse.addProduct(p1);
        warehouse.addProduct(p2);
        warehouse.addProduct(p3);

        helper.saveInventory("baslangic_stok.txt", warehouse.getInventory());
        
        for (Product p : warehouse.getInventory().values()) {
            System.out.println(p.getId() + "," + p.getName() + "," + p.getStock());
        }
        System.out.print("\n");
        
        Thread t1 = new Thread(new TransactionWorker(warehouse, p1, -10, helper),"th1"); 
        Thread t2 = new Thread(new TransactionWorker(warehouse, p1, 20, helper),"th2");          
        Thread t3 = new Thread(new TransactionWorker(warehouse, p2, -5, helper),"th3");  
        Thread t4 = new Thread(new TransactionWorker(warehouse, p3, -15, helper),"th4");
        Thread t5 = new Thread(new TransactionWorker(warehouse, p2, -10, helper),"th5");
        Thread t6 = new Thread(new TransactionWorker(warehouse, p1, 30, helper),"th6");

        t1.start(); t2.start(); t3.start(); t4.start(); t5.start();t6.start();

        t1.join(); t2.join(); t3.join(); t4.join(); t5.join(); t6.join();

        helper.saveInventory("final_stok.txt", warehouse.getInventory());
        System.out.println(warehouse);
    }
}