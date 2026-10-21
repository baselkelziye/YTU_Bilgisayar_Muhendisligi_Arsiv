package ahmetsefacetin;

import GUI.StartPanel;

public class Main {

    public static Distributor distributor = new Distributor();

    public static void main(String args[]) {
        distributor.loadState("distributorData.ser");

        StartPanel startPanel = new StartPanel();
        startPanel.setVisible(true);
        startPanel.pack();
        startPanel.setLocationRelativeTo(null);
    }

}
