package GUI;

import Database.CarOperations;
import Database.CustomerOperations;
import Entities.Car;
import Entities.Customer;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import javax.xml.crypto.Data;
import java.awt.*;

public class CarRental {
    private JPanel mainRentalPanel;
    private JPanel customerListPanel;
    private JPanel carListPanel;
    private JPanel submissionPanel;
    private JTextField customerTextField;
    private JTextField carTextField;
    private JButton submitButton;
    private JTable customerList;
    private JTable carList;
    private JTextField totalDayTextField;

    public CarRental() {
        JFrame frame = new JFrame("Car Addition");
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
         frame.setSize(900,700);
        frame.setContentPane(mainRentalPanel);
     //   frame.pack();

        createCarList();
        createCustomerList();
        rentOperation();



        frame.setVisible(true);



    }
    public void createCustomerList() {
        String customerColumns[] = {"AD","SOYAD","TC","DOĞUM TARİHİ"};
        DefaultTableModel customerModel = new DefaultTableModel(customerColumns,0);

        customerList = new JTable(customerModel);
        JScrollPane customerScrollPane = new JScrollPane(customerList);
        customerListPanel.setLayout(new BorderLayout());
        customerListPanel.add(customerScrollPane,BorderLayout.CENTER);

        for(Entities.Customer list : Customer.setList()) {
            customerModel.addRow(list.getRentalObjects());
        }
    }
    public void createCarList() {
        String carColumns[] = {"PLAKA","MODEL","YIL","ÜCRET(İNDRMSZ)"};
        DefaultTableModel carModel = new DefaultTableModel(carColumns,0);

        carList = new JTable(carModel);
        JScrollPane carScrollPane = new JScrollPane(carList);
        carListPanel.setLayout(new BorderLayout());
        carListPanel.add(carScrollPane, BorderLayout.CENTER);

        for(Entities.Car list : Car.setList()) {
            Object[] temp = list.getRentalObjects();
            if(temp!=null) carModel.addRow(temp);
        }

    }

    public void rentOperation() {
        carTextField.setEditable(false);
        customerTextField.setEditable(false);

        submitButton.addActionListener(e -> {
            int selectedCarRow = carList.getSelectedRow();
            int selectedCustomerRow = customerList.getSelectedRow();

            if (selectedCarRow != -1 && selectedCustomerRow != -1) {
                String selectedCarPlate = (String) carList.getValueAt(selectedCarRow, 0);
                String selectedCustomerTC = (String) customerList.getValueAt(selectedCustomerRow, 2);
                Integer totalDay = Integer.parseInt(totalDayTextField.getText());
                Double price = (Double) carList.getValueAt(selectedCarRow,3);
                Double totalPrice = totalDay*price; // calculator !!!

                carTextField.setText(selectedCarPlate);
                customerTextField.setText(selectedCustomerTC);

                Database.CarOperations carOp = new CarOperations();
                carOp.renting(selectedCustomerTC,selectedCarPlate,totalDay);

                Database.CustomerOperations customerOp = new CustomerOperations();
                customerOp.renting(selectedCustomerTC,selectedCarPlate,totalPrice);

                JOptionPane.showMessageDialog(mainRentalPanel, "Kiralanan Araba : " + selectedCarPlate + "\nKiralayan Müşteri TC: " + selectedCustomerTC);
            } else {
                JOptionPane.showMessageDialog(mainRentalPanel, "Please select a car and a customer.");
            }
        });
    }

}
