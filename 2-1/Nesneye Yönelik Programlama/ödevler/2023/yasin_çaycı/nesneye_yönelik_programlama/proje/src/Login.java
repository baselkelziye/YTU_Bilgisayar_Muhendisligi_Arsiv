package a;

import javax.swing.JFrame;

public class Login {
    public static void main(String[] a) {
    	LoginPage frame = new LoginPage();
        frame.setTitle("Login Page");
        frame.setVisible(true);
        frame.setBounds(10, 10, 400, 500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(false);
    }
}