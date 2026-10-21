package Proje;

import java.awt.EventQueue;
import java.awt.Font;
import java.io.IOException;
import java.util.ArrayList;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.SwingConstants;
import javax.swing.border.EmptyBorder;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JTextArea;

public class childInfo extends JFrame {

    private JPanel contentPane;
    private JTextArea textArea;
    /**
     * Launch the application.
     */

    /**
     * Create the frame.
     */
    
    public childInfo(User parent, String name, String surname, String A, String B, String N) {
    	textArea = new JTextArea();
    	textArea.setFont(new Font("Calibri", Font.BOLD, 20));
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setBounds(100, 100, 703, 503);
        contentPane = new JPanel();
        contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));

        setContentPane(contentPane);
        contentPane.setLayout(null);

        JPanel panel = new JPanel();
        panel.setBounds(326, 10, 10, 10);
        contentPane.add(panel);
        // ÇOCUĞUN İSİM SOYİSMİNİ EKRANA YAZDIRIYORUM
        JLabel lblChild = new JLabel(name + " " + surname);
        lblChild.setHorizontalAlignment(SwingConstants.CENTER);
        lblChild.setFont(new Font("Calibri", Font.BOLD, 55));
        lblChild.setBounds(0, 0, 687, 84);
        contentPane.add(lblChild);
        fileOperations fileOps = new fileOperations();
      //  ArrayList<Results> childResults = fileOps.getResultsFromFile(name, surname);
        
        JButton btnGeriDn = new JButton("Geri Dön");
        btnGeriDn.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		EventQueue.invokeLater(new Runnable() {
        			public void run() {
        				try {
        					chooseTest frame = new chooseTest(parent,name,surname,0);
        					frame.setVisible(true);
        				} catch (Exception e) {
        					e.printStackTrace();
        				}
        			}
        		});
        		dispose();
        	}
        });
        
        btnGeriDn.setFont(new Font("Calibri", Font.BOLD, 16));
        btnGeriDn.setBounds(525, 404, 162, 49);
        contentPane.add(btnGeriDn);
        

        ArrayList<Results> resultList;
        int i = 102;
        try {
            resultList = fileOps.getResultsFromFile(name, surname);
            if (resultList.isEmpty()) {
            	// KULLANICI HENÜZ OYUN OYNAMADIYSA EKRANA BUNU YAZDIRIYORUM
                JLabel lblNewLabel = new JLabel("Bu Kullanıcı Henüz Oyun Oynamadı");
                lblNewLabel.setBounds(29, 102, 627, 29);
                contentPane.add(lblNewLabel);
            } else {
            	
                JPanel panel_1 = new JPanel();
                panel_1.setLayout(null);

                int j = 1;
                JScrollPane scrollPane = new JScrollPane(panel_1);
                scrollPane.setBounds(29, 102, 627, 286);
                contentPane.add(scrollPane);
                // KULLANICININ OYNADIĞI OYUNLARI EKRANA YAZDIRIYORUM
                scrollPane.setViewportView(textArea);
                int paramA = Integer.parseInt(A);
                int paramB = Integer.parseInt(B);
                int paramN = Integer.parseInt(N);
                int k = 0;
                for (Results results : resultList) {
                	if((results.getParameters()[0] == paramA) && (results.getParameters()[1] == paramB) && (results.getParameters()[2] == paramN)) {
                		k++;
                		textArea.append(" "+j+".Oyun\n-----------------\n"+results.printQuestionInfo(results.getResults())+" | Başlama Saati "+results.getStartDate()+ "\n");
    					for(int t = 0 ; t<(results.getQuests().size()) ; t++) {
    						textArea.append(" "+results.printAllQuests(results.getQuests(), results.getAnswers(), t, results.getTime()));
    					}
    					textArea.append("\n");
    					j++;
    				}
                }
                if(k == 0) {
                	textArea.append("   "+name+" "+surname+" Henüz Bu Alıştırmayı Oynamadı");
                }
                	
                textArea.setEditable(false);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
