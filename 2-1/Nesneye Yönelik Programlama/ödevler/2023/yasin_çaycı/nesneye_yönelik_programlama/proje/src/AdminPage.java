package a;

import java.awt.Container;
import java.awt.EventQueue;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JPasswordField;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;
import java.awt.Color;

public class AdminPage extends JFrame implements ActionListener{

	private static final long serialVersionUID = 1L;
	
	private Container container = getContentPane();
	private JLabel labelA = new JLabel("A");
	private JLabel labelB = new JLabel("B");
	private JLabel labelN = new JLabel("N");
	private JTextField TextFieldA = new JTextField();
	private JTextField TextFieldB = new JTextField();
	private JTextField TextFieldN = new JTextField();
	private JButton createButton = new JButton("Oluştur");
	private JButton resultButton = new JButton("Sonuçlar");
	private JButton homeButton = new JButton("");
	private Image img = new ImageIcon(this.getClass().getResource("images/homeicon.png")).getImage();
    
    public static int numberA = (int) (Math.random() * 9 + 1);
    public static int numberB = (int) (Math.random() * 9 + 1);
    public static int numberN = (int) (Math.random() * 9 + 1); 
    public static int control = 0;
 
    AdminPage() {
        setLayoutManager();
        setLocationAndSize();
        addComponentsToContainer();
        addActionEvent();
    }
 
    public void setLayoutManager() {
        container.setLayout(null);
    }
 
    public void setLocationAndSize() {
        labelA.setBounds(82, 91, 34, 30);
        labelB.setBounds(82, 159, 34, 30);
        labelN.setBounds(82, 225, 34, 30);
        TextFieldA.setBounds(126, 92, 150, 30);
        TextFieldB.setBounds(126, 160, 150, 30);
        TextFieldN.setBounds(126, 226, 150, 30);
        createButton.setBackground(new Color(0, 128, 255));
        createButton.setBounds(55, 317, 111, 52);
        createButton.setOpaque(true);
        homeButton.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		LoginPage frame = new LoginPage();
        		jumpToLogin(frame);
        	}
        });
        homeButton.setIcon(new ImageIcon(img));
        homeButton.setBounds(174, 10, 34, 30);
        homeButton.setContentAreaFilled(false);
        homeButton.setBorderPainted(false);
        
        resultButton.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        	}
        });
        resultButton.setOpaque(true);
        resultButton.setBackground(new Color(0, 128, 255));
        resultButton.setBounds(210, 317, 116, 52);
        resultButton.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		ResultsPage frame = new ResultsPage();
        		jumpToResults(frame);
        	}
        });
        getContentPane().add(resultButton);
    }
 
    public void addComponentsToContainer() {
        container.add(labelA);
        container.add(labelB);
        container.add(labelN);
        container.add(TextFieldA);
        container.add(TextFieldB);
        container.add(TextFieldN);
        container.add(createButton);
        container.add(homeButton); 
        container.add(resultButton);
    }
 
    public void addActionEvent() {
    	createButton.addActionListener(this);
    }
 
    @Override
    public void actionPerformed(ActionEvent e) {

        if(e.getSource() == createButton) {
            AdminPage.numberA = Integer.parseInt(TextFieldA.getText());
            AdminPage.numberB = Integer.parseInt(TextFieldB.getText());
            AdminPage.numberN = Integer.parseInt(TextFieldN.getText());
            control = 1;
            /*boolean error = false;
            
            if(numberA < 1 || numberA > 10) {
                JOptionPane.showMessageDialog(this, "A Sayisi Hatali Girildi");
                error = true;
            }
            
            if(numberB < 1 || numberB > 10) {
                JOptionPane.showMessageDialog(this, "B Sayisi Hatali Girildi");
                error = true;
            }
            
           if(numberN <= 0) {
                JOptionPane.showMessageDialog(this, "N Sayisi Hatali Girildi");
                error = true;
            }*/
            System.out.println(AdminPage.numberA +" "+  AdminPage.numberB +" "+ AdminPage.numberN);
        }
    }
    
    private void jumpToLogin(LoginPage frame) {
        frame.setVisible(true);
        this.setVisible(false);
        frame.setBounds(10, 10, 400, 500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(false);
    }
    
    private void jumpToResults(ResultsPage frame) {
        frame.setVisible(true);
        this.setVisible(false);
        frame.setBounds(10, 10, 940, 500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(false);
    }
}
