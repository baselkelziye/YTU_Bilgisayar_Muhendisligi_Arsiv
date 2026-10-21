package GUI;

import Database.CarOperations;
import Entities.Car;

import javax.swing.*;
import javax.swing.text.html.parser.Entity;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CarAddition {
    private JTextField plateTextField;
    private JTextField modelTextField;
    private JTextField yearTextField;
    private JTextField priceTextField;
    private JTextField totalTaxTextField;
    private JButton submitButton;
    private JPanel carAdditionPanel;

    public CarAddition() {
        JFrame frame = new JFrame("Car Addition");
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        // frame.setSize(700,200);
        frame.setContentPane(carAdditionPanel);
        frame.pack();
        frame.setVisible(true);
        submitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String plate = plateTextField.getText();
                String model = modelTextField.getText();
                Integer year = Integer.parseInt(yearTextField.getText());
                Double price =  Double.parseDouble(priceTextField.getText());
                Double totalTax = Double.parseDouble(totalTaxTextField.getText());
                Entities.Car tempCar = new Car(plate,model,year,price,totalTax);
                CarOperations carAddition = new CarOperations();
                carAddition.addCar(tempCar);
                JOptionPane.showMessageDialog(frame,"Araba Başarıyla Eklendi.");

            }
        });

    }
}
