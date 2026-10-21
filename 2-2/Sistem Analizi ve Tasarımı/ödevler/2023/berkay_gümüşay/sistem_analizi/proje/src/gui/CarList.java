package GUI;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.util.ArrayList;
import java.util.List;

public class CarList {
    private JTable listedCars;
    private JPanel carListPanel;


    public CarList() {
        JFrame frame = new JFrame("Car List");
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setSize(700,200);
    //     frame.setContentPane(carListPanel);
      //  frame.pack();


        String arr[] = {"PLAKA","MODEL","YIL","FIYAT","VERGI","ARABA SAHİBİ (TC)"};
        DefaultTableModel model = new DefaultTableModel(arr,0);

        listedCars = new JTable(model) {
            @Override
            public boolean isCellEditable(int row, int column) {
                return false;
            }
        };

        JScrollPane scrollPane = new JScrollPane(listedCars);
        frame.getContentPane().add(scrollPane, BorderLayout.CENTER);


        for(Entities.Car list : Entities.Car.setList()) {
            model.addRow(list.getObjects());
        }

        frame.setVisible(true);

    }

}
