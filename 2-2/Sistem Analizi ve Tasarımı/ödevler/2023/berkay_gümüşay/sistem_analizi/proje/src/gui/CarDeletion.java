package GUI;

import Database.CarOperations;
import Database.CustomerOperations;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class CarDeletion {

    private JPanel carDeletionPanel;
    private JTextField plateTextField;
    private JButton submitButton;

    public CarDeletion() {
        JFrame frame = new JFrame("Customer Deletion");
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setSize(500,100);
        frame.setContentPane(carDeletionPanel);
        // frame.pack();
        frame.setVisible(true);

        submitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String plate = plateTextField.getText();
                CarOperations del = new CarOperations();
                int rowsDeleted = del.deleteCar(plate);
                if(rowsDeleted > 0) {
                    JOptionPane.showMessageDialog(frame,"Araba Başarıyla Silindi.");
                }
                else
                    JOptionPane.showMessageDialog(frame,"Araba bulunamadı.");
            }
        });
    }
}
