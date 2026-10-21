package gui;

import javax.swing.*;

public class report_gui extends JFrame  {

    public report_gui(){

        super("Rapor");
        setLayout(new BoxLayout(getContentPane(), BoxLayout.Y_AXIS));
        setSize(300, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);


        JButton bitecek_abonelik_btn = new JButton("Bitecek Abonelikler");
        JButton odemeleri_goster_btn = new JButton("Odemeleri Goster");


        add(bitecek_abonelik_btn);
        add(odemeleri_goster_btn);

        bitecek_abonelik_btn.addActionListener(e -> {
            dispose();
            new bitecek_abonelik_gui().setVisible(true);
        });

        odemeleri_goster_btn.addActionListener(e -> {
            dispose();
            new odemeleri_goster_gui().setVisible(true);
        });




    }


}
