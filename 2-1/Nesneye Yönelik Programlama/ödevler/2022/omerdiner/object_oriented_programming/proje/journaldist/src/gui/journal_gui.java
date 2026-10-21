package gui;
import javax.swing.*;
import java.awt.*;
public class journal_gui extends JFrame{
    public journal_gui(){
        super("Journal Menu");
        setLayout(new BoxLayout(getContentPane(), BoxLayout.Y_AXIS));
        setSize(300, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);

        JButton journal_ekle = new JButton("Journal Ekle");
        JButton search_btn = new JButton("Journal Ara");
        JButton ana_menu_btn = new JButton("Ana Menu");


        add(journal_ekle);
        add(search_btn);
        add(ana_menu_btn);

        journal_ekle.addActionListener(e -> {
            dispose();
            new journal_ekleme_gui().setVisible(true);
        });



        search_btn.addActionListener(e -> {
            dispose();
            new search_journal_gui().setVisible(true);
        });
        ana_menu_btn.addActionListener(e -> {
            dispose();
            new main_gui().setVisible(true);
        });
    }
}
