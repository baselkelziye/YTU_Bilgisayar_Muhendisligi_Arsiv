package GUI;

import Database.CustomerOperations;
import Entities.Customer;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CustomerDeletion {
    private JPanel customerDeletionPanel;
    private JTextField TCTextField;
    private JButton submitButton;

    public CustomerDeletion() {
        JFrame frame = new JFrame("Customer Deletion");
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setSize(500,100);
        frame.setContentPane(customerDeletionPanel);
        // frame.pack();
        frame.setVisible(true);

        submitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String tc = TCTextField.getText();
                CustomerOperations del = new CustomerOperations();
                int rowsDeleted = del.deleteCustomer(tc);
                if(rowsDeleted > 0) {
                    JOptionPane.showMessageDialog(frame,"Müşteri Başarıyla Silindi.");
                }
                else
                    JOptionPane.showMessageDialog(frame,"Müşteri bulunamadı.");
            }
        });
    }
}
