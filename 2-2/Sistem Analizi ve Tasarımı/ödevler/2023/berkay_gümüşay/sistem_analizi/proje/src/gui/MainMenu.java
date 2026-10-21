package GUI;

import javax.swing.*;

public class MainMenu {


    private JPanel mainPanel;
    private JButton addCar;
    private JButton listCar;
    private JButton deleteCustomer;
    private JButton addCustomer;
    private JButton financeButton;
    private JButton rentACarButton;
    private JButton deleteCar;
    private JButton listCustomer;

    public MainMenu() {
        JFrame frame = new JFrame("Main Menu");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(750, 750);
        frame.setContentPane(mainPanel);
        frame.pack();
        frame.setVisible(true);
        addCustomer.addActionListener(e-> new CustomerAddition());
        deleteCustomer.addActionListener(e-> new CustomerDeletion());
        addCar.addActionListener(e-> new CarAddition());
        deleteCar.addActionListener(e-> new CarDeletion());
        listCar.addActionListener(e-> new CarList());
        listCustomer.addActionListener(e-> new CustomerList());
        rentACarButton.addActionListener(e-> new CarRental());
        financeButton.addActionListener(e-> new FinanceList());



    }

}
