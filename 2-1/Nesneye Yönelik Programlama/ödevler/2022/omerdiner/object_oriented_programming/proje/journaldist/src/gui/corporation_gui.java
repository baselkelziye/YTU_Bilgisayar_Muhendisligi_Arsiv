package gui;
import backend.Corporation;
import backend.Distributor;


import javax.swing.*;
import java.awt.*;
public class corporation_gui extends JFrame{


   private Distributor distributor = new Distributor();
    public corporation_gui() {
        super("Sirket Ekle");
        setLayout(new BoxLayout(getContentPane(), BoxLayout.Y_AXIS));
        setSize(300, 300);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);

        distributor.loadState("db.bin");


        JPanel panel = new JPanel(new GridLayout(0, 2, 5, 5));

        JLabel nameLabel = new JLabel("Name:");
        JTextField name = new JTextField(10);
        JLabel addressLabel = new JLabel("Address:");
        JTextField address = new JTextField(10);
        JLabel bankCodeLabel = new JLabel("Bank Code:");
        JTextField bankCode = new JTextField(10);
        JLabel bankNameLabel = new JLabel("Bank Name:");
        JTextField bankName = new JTextField(10);
        JLabel issueDayLabel = new JLabel("Issue Day:");
        JTextField issueDay = new JTextField(10);
        JLabel issueMonthLabel = new JLabel("Issue Month:");
        JTextField issueMonth = new JTextField(10);
        JLabel issueYearLabel = new JLabel("Issue Year:");
        JTextField issueYear = new JTextField(10);
        JLabel accountNumberLabel = new JLabel("Account Number:");
        JTextField accountNumber = new JTextField(10);
        JButton olustur_btn = new JButton("Yeni sirket olustur");
        JButton ana_menu_btn = new JButton("Ana Menu");


       addLabelAndInput(panel, nameLabel, name);
        addLabelAndInput(panel, addressLabel, address);
        addLabelAndInput(panel, bankCodeLabel, bankCode);
        addLabelAndInput(panel, bankNameLabel, bankName);
        addLabelAndInput(panel, issueDayLabel, issueDay);
        addLabelAndInput(panel, issueMonthLabel, issueMonth);
        addLabelAndInput(panel, issueYearLabel, issueYear);
        addLabelAndInput(panel, accountNumberLabel, accountNumber);


        panel.add(olustur_btn);
        panel.add(ana_menu_btn);

        add(panel);



        olustur_btn.addActionListener(e -> {
            dispose();
            Corporation corporation = new Corporation(name.getText(), address.getText(), Integer.parseInt(bankCode.getText()), bankName.getText(), Integer.parseInt(issueDay.getText()), Integer.parseInt(issueMonth.getText()), Integer.parseInt(issueYear.getText()), Integer.parseInt(accountNumber.getText()));
            distributor.addSubscriber(corporation);
            distributor.saveState("db.bin");
            JOptionPane.showMessageDialog(null, "Sirket ekleme basarili.");

            new main_gui().setVisible(true);
        });

        ana_menu_btn.addActionListener(e -> {
            dispose();
            new main_gui().setVisible(true);
        });
    }


    public void addLabelAndInput(JPanel panel, JLabel label, JTextField input){
        panel.add(label);
        panel.add(input);
    }


}
