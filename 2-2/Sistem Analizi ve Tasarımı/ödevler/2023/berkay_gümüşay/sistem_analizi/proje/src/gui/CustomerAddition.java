package GUI;

import Database.CustomerOperations;
import Entities.Customer;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CustomerAddition {

    private JPanel customerAdditionPanel;
    private JTextField nameTextField;
    private JTextField surnameTextField;
    private JTextField TCTextField;
    private JTextField birthDateTextField;
    private JButton saveButton;



    public CustomerAddition() {
        JFrame frame = new JFrame("Customer Addition");
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setSize(700,200);
        frame.setContentPane(customerAdditionPanel);
        frame.pack();
        frame.setVisible(true);

        saveButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String name = nameTextField.getText();
                String surname = surnameTextField.getText();
                String tc = TCTextField.getText();
                String birthDate = birthDateTextField.getText();
                Entities.Customer tempCustomer = new Customer(name,surname,tc,birthDate);
                CustomerOperations add = new CustomerOperations();
                add.addCustomer(tempCustomer);
                JOptionPane.showMessageDialog(frame, "Müşteri başarıyla eklendi.");
            }
        });
    }





}
