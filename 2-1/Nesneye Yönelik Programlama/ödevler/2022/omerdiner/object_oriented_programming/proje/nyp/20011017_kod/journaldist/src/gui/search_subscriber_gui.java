package gui;

import backend.Distributor;

import javax.swing.*;
import java.awt.*;

public class search_subscriber_gui extends JFrame {
   private Distributor distributor ;

    public search_subscriber_gui() {
        super("Subscriber Ara");
        setLayout(new BoxLayout(getContentPane(), BoxLayout.Y_AXIS));
        setSize(300, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);


        JPanel panel = new JPanel(new FlowLayout());

        JLabel nameLabel = new JLabel("Name:");
        JTextField nameTextField = new JTextField(15);
        JButton ara_btn = new JButton("Ara");
        JButton ana_menu_btn = new JButton("Ana Menu");

        panel.add(nameLabel);
        panel.add(nameTextField);
        panel.add(ara_btn);
        panel.add(ana_menu_btn);

        add(panel);

        ara_btn.addActionListener(e -> {
            dispose();
            distributor = new Distributor();
            distributor.loadState("db.bin");
            if(distributor.searchSubscriber(nameTextField.getText()) != null){
                JOptionPane.showMessageDialog(null, distributor.searchSubscriber(nameTextField.getText()).toString());
            }
            else{
                JOptionPane.showMessageDialog(null, "Bu isme sahip subscriber bulunamadi:  " + nameTextField.getText());
            }

            new main_gui().setVisible(true);
        });

        ana_menu_btn.addActionListener(e -> {
            dispose();
            new main_gui().setVisible(true);
        });
    }
}
