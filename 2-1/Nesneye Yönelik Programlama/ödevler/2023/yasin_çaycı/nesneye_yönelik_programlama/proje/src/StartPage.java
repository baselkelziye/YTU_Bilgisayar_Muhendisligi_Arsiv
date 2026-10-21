package a;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
 
public class StartPage extends JFrame implements ActionListener {
 
	private static final long serialVersionUID = 1L;
	
	private Container container = getContentPane();
	private JButton startButton = new JButton("Yeni Alıştırma");
	private JButton backButton = new JButton("");
	private Image img = new ImageIcon(this.getClass().getResource("images/backButton.png")).getImage();
    StartPage() {
        setLayoutManager();
        setLocationAndSize();
        addComponentsToContainer();
        addActionEvent();
    }
 
    public void setLayoutManager() {
        container.setLayout(null);
    }
 
    public void setLocationAndSize() {
    	startButton.setBackground(new Color(0, 128, 255));
    	startButton.setBounds(113, 230, 174, 32);
    	startButton.setOpaque(true);
    	backButton.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
                LoginPage frame = new LoginPage();
                jumpToLogin(frame);
        	}
        });
        backButton.setIcon(new ImageIcon(img));
        backButton.setBounds(174, 10, 34, 30);
        backButton.setContentAreaFilled(false);
        backButton.setBorderPainted(false);
    }
 
    public void addComponentsToContainer() {
        container.add(startButton);
        container.add(backButton);
    }
 
    public void addActionEvent() {
    	startButton.addActionListener(this);
    }
 
    @Override
    public void actionPerformed(ActionEvent e) {
        //login button
        if (e.getSource() == startButton) {
        	GamePage frame = new GamePage();
            frame.setVisible(true);
            this.setVisible(false);
            frame.setBounds(10, 10, 400, 500);
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setResizable(false);
        }
    }
    
    private void jumpToLogin(LoginPage frame) {
	     frame.setVisible(true);
	     this.setVisible(false);
	     frame.setBounds(10, 10, 400, 500);
	     frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	     frame.setResizable(false);
	 }
 
}
 