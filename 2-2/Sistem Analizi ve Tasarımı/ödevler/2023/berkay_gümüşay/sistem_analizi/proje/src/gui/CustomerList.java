package GUI;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;

public class CustomerList {
    private JPanel customerListPanel;
    private JTable listedCustomers;

    public CustomerList() {
        JFrame frame = new JFrame("Customer List");
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setSize(700,200);
        //     frame.setContentPane(carListPanel);
        //  frame.pack();


        String arr[] = {"AD","SOYAD","TC","DOĞUM TARİHİ","ARABA-LAR","TOPLAM ÖDEME"};
        DefaultTableModel model = new DefaultTableModel(arr,0);

        listedCustomers = new JTable(model) {
            @Override
            public boolean isCellEditable(int row, int column) {
                return false;
            }
        };

        JScrollPane scrollPane = new JScrollPane(listedCustomers);
        frame.getContentPane().add(scrollPane, BorderLayout.CENTER);


        for(Entities.Customer list : Entities.Customer.setList()) {
            model.addRow(list.getObjects());
        }

        frame.setVisible(true);

    }

}

