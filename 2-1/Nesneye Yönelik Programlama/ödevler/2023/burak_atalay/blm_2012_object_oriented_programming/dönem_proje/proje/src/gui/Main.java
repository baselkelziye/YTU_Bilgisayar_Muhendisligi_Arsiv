package GUI;
import distributor.Distributor;

public class Main {
    public static void main(String[] args) {
        DistributorUI distributorUI = new DistributorUI();
        Distributor distributor = new Distributor();
        distributorUI.setDistributor(distributor);
        distributorUI.setVisible(true);
        distributorUI.pack();
        distributorUI.setLocationRelativeTo(null);
    }
}
