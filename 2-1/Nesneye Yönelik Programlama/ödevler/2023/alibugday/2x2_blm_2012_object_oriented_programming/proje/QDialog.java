package NYO_proje_19011076;

import java.awt.event.*;
import java.awt.*;
import javax.swing.*;

public class QDialog extends JFrame implements ActionListener{
	static JFrame f = new JFrame();
	private JPanel textPanel = new JPanel();
	private JPanel butonPanel = new JPanel();
	private JButton btn;
	private JLabel l;
	public QDialog(String msg, String msg2) {
		f.setLayout(new GridLayout(2,1));
		//JDialog d = new JDialog(f, "alert");
		//d.setLocation(200, 200); 
		
        // create a label
        l = new JLabel(msg);
        l.setHorizontalAlignment(JLabel.CENTER);
        btn = new JButton(msg2);
        btn.addActionListener(this);
        
        btn.setFont(new Font("Ink Free",Font.BOLD,25));
        btn.setHorizontalAlignment(JButton.CENTER);
        btn.setBounds(0, 0, 50, 50);
        //d.add(l);
        
        //d.add(btn);
        
        textPanel.setLayout(new BorderLayout());
        butonPanel.setLayout(new BorderLayout());
        //butonPanel.setBounds(0, 0, 50, 50);
        // setsize of dialog
        
        textPanel.add(l);
        butonPanel.add(btn);
        f.add(textPanel);
        f.add(butonPanel);
        f.setSize(200, 200);
        f.addWindowListener((WindowListener) new WindowAdapter() {
	         public void windowClosing(WindowEvent windowEvent){
	            f.dispose();
	         }        
	    }); 
        // set visibility of dialog
        f.setVisible(true);
	}
	
	public QDialog(String msg) {
		f.setLayout(new GridLayout(1,1));
		//JDialog d = new JDialog(f, "alert");
		///d.setLocation(200, 200); 
		f.setLocation(200, 200);
        // create a label
        l = new JLabel(msg);
        l.setHorizontalAlignment(JLabel.CENTER);
        //JButton btn = new JButton(msg2);
        //btn.addActionListener(this);
        
        //btn.setFont(new Font("Ink Free",Font.BOLD,25));
        //btn.setHorizontalAlignment(JButton.CENTER);
        //btn.setBounds(0, 0, 50, 50);
        //d.add(l);
        
        //d.add(btn);
        
        textPanel.setLayout(new BorderLayout());
        //butonPanel.setLayout(new BorderLayout());
        //butonPanel.setBounds(0, 0, 50, 50);
        // setsize of dialog
        
        textPanel.add(l);
        //butonPanel.add(btn);
        f.add(textPanel);
        //f.add(butonPanel);
        f.setSize(200, 200);
        f.addWindowListener((WindowListener) new WindowAdapter() {
	         public void windowClosing(WindowEvent windowEvent){
	            f.dispose();
	         }        
	    });  
        // set visibility of dialog
        f.setVisible(true);
	}
	

	@Override
	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == btn) {
			
			int j=GenerateEquation.randomGenerator.nextInt(2)+1;
	        String equation = GenerateEquation.createEquation(j);
	        l.setText(equation);
		}
		
	}
	
	public static void main(String[] args) {
		QDialog dialog = new QDialog("bu bir dialog", "tekrar uret");
		
	}

}
