import java.io.IOException;

public class TransactionWorker implements Runnable {
    private Product product;
    private int amount;
    private FileHelper fileHelper;
    private Warehouse warehouse;

    public TransactionWorker(Warehouse w, Product p, int amt, FileHelper h) {
        this.product = p;
        this.amount = amt;
        this.fileHelper = h;
        this.warehouse = w;
    }
    @Override
    public void run() {
        try {
            warehouse.updateAndLog(product, amount, fileHelper);
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}