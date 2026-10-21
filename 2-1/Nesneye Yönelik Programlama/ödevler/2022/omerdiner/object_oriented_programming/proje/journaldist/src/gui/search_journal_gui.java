package gui;

import backend.Distributor;

import javax.swing.*;
import java.awt.*;

public class search_journal_gui extends JFrame {

   private Distributor distributor ;

    public search_journal_gui() {
        super("Journal Ara");
        setLayout(new BoxLayout(getContentPane(), BoxLayout.Y_AXIS));
        setSize(300, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);


        getContentPane().setBackground(Color.LIGHT_GRAY);

        JPanel panel = new JPanel(new FlowLayout());
        panel.setBackground(Color.LIGHT_GRAY);

        JLabel issnLabel = new JLabel("ISSN:");
        JTextField issnTextField = new JTextField(15);

        JButton ara_btn = new JButton("Ara");
        JButton ana_menu_btn = new JButton("Ana Menu");

        panel.add(issnLabel);
        panel.add(issnTextField);
        panel.add(ara_btn);
        panel.add(ana_menu_btn);

        add(panel);


        ara_btn.setBackground(Color.BLUE);
        ana_menu_btn.setBackground(Color.GREEN);


        ara_btn.setForeground(Color.WHITE);
        ana_menu_btn.setForeground(Color.WHITE);

        Font font = new Font("Arial", Font.PLAIN, 14);
        issnLabel.setFont(font);
        issnTextField.setFont(font);

        ara_btn.addActionListener(e -> {
            dispose();
            distributor = new Distributor();
            distributor.loadState("db.bin");
            if(distributor.searchJournal(issnTextField.getText()) != null){
                JOptionPane.showMessageDialog(null, distributor.searchJournal(issnTextField.getText()).toString());
            }
            else{
                JOptionPane.showMessageDialog(null, "Verilen issn'e sahip journal bulunamadı:  " + issnTextField.getText());
            }

            new main_gui().setVisible(true);
        });

        ana_menu_btn.addActionListener(e -> {
            dispose();
            new main_gui().setVisible(true);
        });
    }
}
