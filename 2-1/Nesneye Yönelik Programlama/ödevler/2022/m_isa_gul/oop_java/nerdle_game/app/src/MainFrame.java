import java.awt.Color;
import java.awt.EventQueue;
import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.Timer;

import java.awt.Font;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.SwingConstants;

public class MainFrame extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	private JPanel contentPane;
	public JLabel lblTimer = new JLabel("0");
	public int panel_num, row, col;
	public int i,j;
	public JButton activeBtn, keyboardBtn;
	public int activeRow =0;
	public String expression="";
	public String equation;
	
	Timer timer;
	int sec;
	
	public char operator;
	public String oper;
	
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					MainFrame frame = new MainFrame();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	
	
	
	public MainFrame() {

		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 819, 721);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JPanel panel_end = new JPanel();
		panel_end.setBounds(0, 0, 803, 399);
		contentPane.add(panel_end);
		panel_end.setLayout(null);
		
		JLabel lblNewLabel = new JLabel("Game Over!");
		lblNewLabel.setFont(new Font("Tahoma", Font.PLAIN, 40));
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setBounds(226, 27, 299, 85);
		panel_end.add(lblNewLabel);
		
		JLabel lblNewLabel_1 = new JLabel("Time:");
		lblNewLabel_1.setFont(new Font("Tahoma", Font.PLAIN, 20));
		lblNewLabel_1.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel_1.setBounds(271, 245, 81, 50);
		panel_end.add(lblNewLabel_1);
		
		JLabel lblTime = new JLabel("0");
		lblTime.setFont(new Font("Tahoma", Font.PLAIN, 20));
		lblTime.setHorizontalAlignment(SwingConstants.CENTER);
		lblTime.setBounds(390, 245, 61, 50);
		panel_end.add(lblTime);
		
		JLabel lblNewLabel_1_1 = new JLabel("Try:");
		lblNewLabel_1_1.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel_1_1.setFont(new Font("Tahoma", Font.PLAIN, 20));
		lblNewLabel_1_1.setBounds(271, 325, 81, 50);
		panel_end.add(lblNewLabel_1_1);
		
		JLabel lblTry = new JLabel("0");
		lblTry.setHorizontalAlignment(SwingConstants.CENTER);
		lblTry.setFont(new Font("Tahoma", Font.PLAIN, 20));
		lblTry.setBounds(390, 325, 61, 50);
		panel_end.add(lblTry);
		
		JLabel lblWinLose = new JLabel("You Lose");
		lblWinLose.setHorizontalAlignment(SwingConstants.CENTER);
		lblWinLose.setFont(new Font("Tahoma", Font.PLAIN, 30));
		lblWinLose.setBounds(257, 100, 230, 61);
		panel_end.add(lblWinLose);
		
		JLabel lblEquation = new JLabel("");
		lblEquation.setHorizontalAlignment(SwingConstants.CENTER);
		lblEquation.setFont(new Font("Tahoma", Font.PLAIN, 20));
		lblEquation.setBounds(189, 172, 369, 48);
		panel_end.add(lblEquation);
		panel_end.setVisible(false);
		
		JPanel panel_key = new JPanel();
		panel_key.setBounds(0, 399, 803, 283);
		contentPane.add(panel_key);
		panel_key.setLayout(null);
		panel_key.setVisible(false);
		
		JButton btn0 = new JButton("0");
		
		btn0.setBounds(206, 183, 60, 43);
		panel_key.add(btn0);
		
		JButton btn1 = new JButton("1");
		btn1.setBounds(206, 129, 60, 43);
		panel_key.add(btn1);
		
		JButton btn2 = new JButton("2");
		btn2.setBounds(276, 129, 60, 43);
		panel_key.add(btn2);
		
		JButton btn3 = new JButton("3");
		btn3.setBounds(346, 129, 60, 43);
		panel_key.add(btn3);
		
		JButton btn4 = new JButton("4");
		btn4.setBounds(206, 75, 60, 43);
		panel_key.add(btn4);
		
		JButton btn5 = new JButton("5");
		btn5.setBounds(276, 75, 60, 43);
		panel_key.add(btn5);
		
		JButton btn6 = new JButton("6");
		btn6.setBounds(346, 75, 60, 43);
		panel_key.add(btn6);
		
		JButton btn7 = new JButton("7");
		btn7.setBounds(206, 21, 60, 43);
		panel_key.add(btn7);
		
		JButton btn8 = new JButton("8");
		btn8.setBounds(276, 21, 60, 43);
		panel_key.add(btn8);
		
		JButton btn9 = new JButton("9");
		btn9.setBounds(346, 21, 60, 43);
		panel_key.add(btn9);
		
		JButton btnSum = new JButton("+");
		btnSum.setBounds(454, 21, 60, 43);
		panel_key.add(btnSum);
		
		JButton btnSub = new JButton("-");
		btnSub.setBounds(524, 21, 60, 43);
		panel_key.add(btnSub);
		
		JButton btnMul = new JButton("*");
		btnMul.setBounds(454, 75, 60, 43);
		panel_key.add(btnMul);
		
		JButton btnDiv = new JButton("/");
		btnDiv.setBounds(524, 75, 60, 43);
		panel_key.add(btnDiv);
		
		JButton btnEqual = new JButton("=");
		btnEqual.setBounds(486, 129, 60, 43);
		panel_key.add(btnEqual);
		
		JButton btnControl = new JButton("Control");
		
		btnControl.setBounds(276, 183, 130, 43);
		panel_key.add(btnControl);
		
//		JLabel lblTimer = new JLabel("0");
		lblTimer.setFont(new Font("Tahoma", Font.PLAIN, 20));
		lblTimer.setHorizontalAlignment(SwingConstants.CENTER);
		lblTimer.setBounds(51, 96, 105, 50);
		panel_key.add(lblTimer);
		
		JLabel lblTimeText = new JLabel("Time");
		lblTimeText.setHorizontalAlignment(SwingConstants.CENTER);
		lblTimeText.setFont(new Font("Tahoma", Font.PLAIN, 20));
		lblTimeText.setBounds(62, 48, 81, 50);
		panel_key.add(lblTimeText);
		
		
		
		
		JPanel panel_7 = new JPanel();
		panel_7.setBounds(0, 0, 803, 399);
		contentPane.add(panel_7);
		panel_7.setVisible(false);
		panel_7.setLayout(null);
		
		JButton btn7_1 = new JButton("");
		

		btn7_1.setBounds(190, 38, 50, 50);
		panel_7.add(btn7_1);
		
		JButton btn7_2 = new JButton("");
		
		btn7_2.setBounds(250, 38, 50, 50);
		panel_7.add(btn7_2);
		
		JButton btn7_3 = new JButton("");
		
		btn7_3.setBounds(310, 38, 50, 50);
		panel_7.add(btn7_3);
		
		JButton btn7_4 = new JButton("");
		
		btn7_4.setBounds(370, 38, 50, 50);
		panel_7.add(btn7_4);
		
		JButton btn7_5 = new JButton("");
		
		btn7_5.setBounds(430, 38, 50, 50);
		panel_7.add(btn7_5);
		
		JButton btn7_6 = new JButton("");
		
		btn7_6.setBounds(490, 38, 50, 50);
		panel_7.add(btn7_6);
		
		JButton btn7_7 = new JButton("");
		
		btn7_7.setBounds(550, 38, 50, 50);
		panel_7.add(btn7_7);
		
		JButton btn7_1_1 = new JButton("");
		btn7_1_1.setEnabled(false);
		btn7_1_1.setBounds(190, 99, 50, 50);
		panel_7.add(btn7_1_1);
		
		JButton btn7_2_1 = new JButton("");
		btn7_2_1.setEnabled(false);
		btn7_2_1.setBounds(250, 99, 50, 50);
		panel_7.add(btn7_2_1);
		
		JButton btn7_3_1 = new JButton("");
		btn7_3_1.setEnabled(false);
		btn7_3_1.setBounds(310, 99, 50, 50);
		panel_7.add(btn7_3_1);
		
		JButton btn7_4_1 = new JButton("");
		btn7_4_1.setEnabled(false);
		btn7_4_1.setBounds(370, 99, 50, 50);
		panel_7.add(btn7_4_1);
		
		JButton btn7_5_1 = new JButton("");
		btn7_5_1.setEnabled(false);
		btn7_5_1.setBounds(430, 99, 50, 50);
		panel_7.add(btn7_5_1);
		
		JButton btn7_6_1 = new JButton("");
		btn7_6_1.setEnabled(false);
		btn7_6_1.setBounds(490, 99, 50, 50);
		panel_7.add(btn7_6_1);
		
		JButton btn7_7_1 = new JButton("");
		btn7_7_1.setEnabled(false);
		btn7_7_1.setBounds(550, 99, 50, 50);
		panel_7.add(btn7_7_1);
		
		JButton btn7_1_2 = new JButton("");
		btn7_1_2.setEnabled(false);
		btn7_1_2.setBounds(190, 160, 50, 50);
		panel_7.add(btn7_1_2);
		
		JButton btn7_2_2 = new JButton("");
		btn7_2_2.setEnabled(false);
		btn7_2_2.setBounds(250, 160, 50, 50);
		panel_7.add(btn7_2_2);
		
		JButton btn7_3_2 = new JButton("");
		btn7_3_2.setEnabled(false);
		btn7_3_2.setBounds(310, 160, 50, 50);
		panel_7.add(btn7_3_2);
		
		JButton btn7_4_2 = new JButton("");
		btn7_4_2.setEnabled(false);
		btn7_4_2.setBounds(370, 160, 50, 50);
		panel_7.add(btn7_4_2);
		
		JButton btn7_5_2 = new JButton("");
		btn7_5_2.setEnabled(false);
		btn7_5_2.setBounds(430, 160, 50, 50);
		panel_7.add(btn7_5_2);
		
		JButton btn7_6_2 = new JButton("");
		btn7_6_2.setEnabled(false);
		btn7_6_2.setBounds(490, 160, 50, 50);
		panel_7.add(btn7_6_2);
		
		JButton btn7_7_2 = new JButton("");
		btn7_7_2.setEnabled(false);
		btn7_7_2.setBounds(550, 160, 50, 50);
		panel_7.add(btn7_7_2);
		
		JButton btn7_1_3 = new JButton("");
		btn7_1_3.setEnabled(false);
		btn7_1_3.setBounds(190, 221, 50, 50);
		panel_7.add(btn7_1_3);
		
		JButton btn7_2_3 = new JButton("");
		btn7_2_3.setEnabled(false);
		btn7_2_3.setBounds(250, 221, 50, 50);
		panel_7.add(btn7_2_3);
		
		JButton btn7_3_3 = new JButton("");
		btn7_3_3.setEnabled(false);
		btn7_3_3.setBounds(310, 221, 50, 50);
		panel_7.add(btn7_3_3);
		
		JButton btn7_4_3 = new JButton("");
		btn7_4_3.setEnabled(false);
		btn7_4_3.setBounds(370, 221, 50, 50);
		panel_7.add(btn7_4_3);
		
		JButton btn7_5_3 = new JButton("");
		btn7_5_3.setEnabled(false);
		btn7_5_3.setBounds(430, 221, 50, 50);
		panel_7.add(btn7_5_3);
		
		JButton btn7_6_3 = new JButton("");
		btn7_6_3.setEnabled(false);
		btn7_6_3.setBounds(490, 221, 50, 50);
		panel_7.add(btn7_6_3);
		
		JButton btn7_7_3 = new JButton("");
		btn7_7_3.setEnabled(false);
		btn7_7_3.setBounds(550, 221, 50, 50);
		panel_7.add(btn7_7_3);
		
		JButton btn7_1_4 = new JButton("");
		btn7_1_4.setEnabled(false);
		btn7_1_4.setBounds(190, 282, 50, 50);
		panel_7.add(btn7_1_4);
		
		JButton btn7_2_4 = new JButton("");
		btn7_2_4.setEnabled(false);
		btn7_2_4.setBounds(250, 282, 50, 50);
		panel_7.add(btn7_2_4);
		
		JButton btn7_3_4 = new JButton("");
		btn7_3_4.setEnabled(false);
		btn7_3_4.setBounds(310, 282, 50, 50);
		panel_7.add(btn7_3_4);
		
		JButton btn7_4_4 = new JButton("");
		btn7_4_4.setEnabled(false);
		btn7_4_4.setBounds(370, 282, 50, 50);
		panel_7.add(btn7_4_4);
		
		JButton btn7_5_4 = new JButton("");
		btn7_5_4.setEnabled(false);
		btn7_5_4.setBounds(430, 282, 50, 50);
		panel_7.add(btn7_5_4);
		
		JButton btn7_6_4 = new JButton("");
		btn7_6_4.setEnabled(false);
		btn7_6_4.setBounds(490, 282, 50, 50);
		panel_7.add(btn7_6_4);
		
		JButton btn7_7_4 = new JButton("");
		btn7_7_4.setEnabled(false);
		btn7_7_4.setBounds(550, 282, 50, 50);
		panel_7.add(btn7_7_4);
		
		JButton btn7_1_5 = new JButton("");
		btn7_1_5.setEnabled(false);
		btn7_1_5.setBounds(190, 343, 50, 50);
		panel_7.add(btn7_1_5);
		
		JButton btn7_2_5 = new JButton("");
		btn7_2_5.setEnabled(false);
		btn7_2_5.setBounds(250, 343, 50, 50);
		panel_7.add(btn7_2_5);
		
		JButton btn7_3_5 = new JButton("");
		btn7_3_5.setEnabled(false);
		btn7_3_5.setBounds(310, 343, 50, 50);
		panel_7.add(btn7_3_5);
		
		JButton btn7_4_5 = new JButton("");
		btn7_4_5.setEnabled(false);
		btn7_4_5.setBounds(370, 343, 50, 50);
		panel_7.add(btn7_4_5);
		
		JButton btn7_5_5 = new JButton("");
		btn7_5_5.setEnabled(false);
		btn7_5_5.setBounds(430, 343, 50, 50);
		panel_7.add(btn7_5_5);
		
		JButton btn7_6_5 = new JButton("");
		btn7_6_5.setEnabled(false);
		btn7_6_5.setBounds(490, 343, 50, 50);
		panel_7.add(btn7_6_5);
		
		JButton btn7_7_5 = new JButton("");
		btn7_7_5.setEnabled(false);
		btn7_7_5.setBounds(550, 343, 50, 50);
		panel_7.add(btn7_7_5);
		
		JPanel panel_8 = new JPanel();
		panel_8.setBounds(0, 0, 803, 399);
		contentPane.add(panel_8);
		panel_8.setVisible(false);
		panel_8.setLayout(null);
		
		JButton btn8_1 = new JButton("");
		btn8_1.setBounds(163, 39, 50, 50);
		panel_8.add(btn8_1);
		
		JButton btn8_2 = new JButton("");
		btn8_2.setBounds(223, 39, 50, 50);
		panel_8.add(btn8_2);
		
		JButton btn8_3 = new JButton("");
		btn8_3.setBounds(283, 39, 50, 50);
		panel_8.add(btn8_3);
		
		JButton btn8_4 = new JButton("");
		btn8_4.setBounds(343, 39, 50, 50);
		panel_8.add(btn8_4);
		
		JButton btn8_5 = new JButton("");
		btn8_5.setBounds(403, 39, 50, 50);
		panel_8.add(btn8_5);
		
		JButton btn8_6 = new JButton("");
		btn8_6.setBounds(463, 39, 50, 50);
		panel_8.add(btn8_6);
		
		JButton btn8_7 = new JButton("");
		btn8_7.setBounds(523, 39, 50, 50);
		panel_8.add(btn8_7);
		
		JButton btn8_8 = new JButton("");
		btn8_8.setBounds(583, 39, 50, 50);
		panel_8.add(btn8_8);
		
		JButton btn8_1_1 = new JButton("");
		btn8_1_1.setEnabled(false);
		btn8_1_1.setBounds(163, 100, 50, 50);
		panel_8.add(btn8_1_1);
		
		JButton btn8_2_1 = new JButton("");
		btn8_2_1.setEnabled(false);
		btn8_2_1.setBounds(223, 100, 50, 50);
		panel_8.add(btn8_2_1);
		
		JButton btn8_3_1 = new JButton("");
		btn8_3_1.setEnabled(false);
		btn8_3_1.setBounds(283, 100, 50, 50);
		panel_8.add(btn8_3_1);
		
		JButton btn8_4_1 = new JButton("");
		btn8_4_1.setEnabled(false);
		btn8_4_1.setBounds(343, 100, 50, 50);
		panel_8.add(btn8_4_1);
		
		JButton btn8_5_1 = new JButton("");
		btn8_5_1.setEnabled(false);
		btn8_5_1.setBounds(403, 100, 50, 50);
		panel_8.add(btn8_5_1);
		
		JButton btn8_6_1 = new JButton("");
		btn8_6_1.setEnabled(false);
		btn8_6_1.setBounds(463, 100, 50, 50);
		panel_8.add(btn8_6_1);
		
		JButton btn8_7_1 = new JButton("");
		btn8_7_1.setEnabled(false);
		btn8_7_1.setBounds(523, 100, 50, 50);
		panel_8.add(btn8_7_1);
		
		JButton btn8_8_1 = new JButton("");
		btn8_8_1.setEnabled(false);
		btn8_8_1.setBounds(583, 100, 50, 50);
		panel_8.add(btn8_8_1);
		
		JButton btn8_1_2 = new JButton("");
		btn8_1_2.setEnabled(false);
		btn8_1_2.setBounds(163, 161, 50, 50);
		panel_8.add(btn8_1_2);
		
		JButton btn8_2_2 = new JButton("");
		btn8_2_2.setEnabled(false);
		btn8_2_2.setBounds(223, 161, 50, 50);
		panel_8.add(btn8_2_2);
		
		JButton btn8_3_2 = new JButton("");
		btn8_3_2.setEnabled(false);
		btn8_3_2.setBounds(283, 161, 50, 50);
		panel_8.add(btn8_3_2);
		
		JButton btn8_4_2 = new JButton("");
		btn8_4_2.setEnabled(false);
		btn8_4_2.setBounds(343, 161, 50, 50);
		panel_8.add(btn8_4_2);
		
		JButton btn8_5_2 = new JButton("");
		btn8_5_2.setEnabled(false);
		btn8_5_2.setBounds(403, 161, 50, 50);
		panel_8.add(btn8_5_2);
		
		JButton btn8_6_2 = new JButton("");
		btn8_6_2.setEnabled(false);
		btn8_6_2.setBounds(463, 161, 50, 50);
		panel_8.add(btn8_6_2);
		
		JButton btn8_7_2 = new JButton("");
		btn8_7_2.setEnabled(false);
		btn8_7_2.setBounds(523, 161, 50, 50);
		panel_8.add(btn8_7_2);
		
		JButton btn8_8_2 = new JButton("");
		btn8_8_2.setEnabled(false);
		btn8_8_2.setBounds(583, 161, 50, 50);
		panel_8.add(btn8_8_2);
		
		JButton btn8_1_3 = new JButton("");
		btn8_1_3.setEnabled(false);
		btn8_1_3.setBounds(163, 222, 50, 50);
		panel_8.add(btn8_1_3);
		
		JButton btn8_2_3 = new JButton("");
		btn8_2_3.setEnabled(false);
		btn8_2_3.setBounds(223, 222, 50, 50);
		panel_8.add(btn8_2_3);
		
		JButton btn8_3_3 = new JButton("");
		btn8_3_3.setEnabled(false);
		btn8_3_3.setBounds(283, 222, 50, 50);
		panel_8.add(btn8_3_3);
		
		JButton btn8_4_3 = new JButton("");
		btn8_4_3.setEnabled(false);
		btn8_4_3.setBounds(343, 222, 50, 50);
		panel_8.add(btn8_4_3);
		
		JButton btn8_5_3 = new JButton("");
		btn8_5_3.setEnabled(false);
		btn8_5_3.setBounds(403, 222, 50, 50);
		panel_8.add(btn8_5_3);
		
		JButton btn8_6_3 = new JButton("");
		btn8_6_3.setEnabled(false);
		btn8_6_3.setBounds(463, 222, 50, 50);
		panel_8.add(btn8_6_3);
		
		JButton btn8_7_3 = new JButton("");
		btn8_7_3.setEnabled(false);
		btn8_7_3.setBounds(523, 222, 50, 50);
		panel_8.add(btn8_7_3);
		
		JButton btn8_8_3 = new JButton("");
		btn8_8_3.setEnabled(false);
		btn8_8_3.setBounds(583, 222, 50, 50);
		panel_8.add(btn8_8_3);
		
		JButton btn8_1_4 = new JButton("");
		btn8_1_4.setEnabled(false);
		btn8_1_4.setBounds(163, 283, 50, 50);
		panel_8.add(btn8_1_4);
		
		JButton btn8_2_4 = new JButton("");
		btn8_2_4.setEnabled(false);
		btn8_2_4.setBounds(223, 283, 50, 50);
		panel_8.add(btn8_2_4);
		
		JButton btn8_3_4 = new JButton("");
		btn8_3_4.setEnabled(false);
		btn8_3_4.setBounds(283, 283, 50, 50);
		panel_8.add(btn8_3_4);
		
		JButton btn8_4_4 = new JButton("");
		btn8_4_4.setEnabled(false);
		btn8_4_4.setBounds(343, 283, 50, 50);
		panel_8.add(btn8_4_4);
		
		JButton btn8_5_4 = new JButton("");
		btn8_5_4.setEnabled(false);
		btn8_5_4.setBounds(403, 283, 50, 50);
		panel_8.add(btn8_5_4);
		
		JButton btn8_6_4 = new JButton("");
		btn8_6_4.setEnabled(false);
		btn8_6_4.setBounds(463, 283, 50, 50);
		panel_8.add(btn8_6_4);
		
		JButton btn8_7_4 = new JButton("");
		btn8_7_4.setEnabled(false);
		btn8_7_4.setBounds(523, 283, 50, 50);
		panel_8.add(btn8_7_4);
		
		JButton btn8_8_4 = new JButton("");
		btn8_8_4.setEnabled(false);
		btn8_8_4.setBounds(583, 283, 50, 50);
		panel_8.add(btn8_8_4);
		
		JButton btn8_1_5 = new JButton("");
		btn8_1_5.setEnabled(false);
		btn8_1_5.setBounds(163, 344, 50, 50);
		panel_8.add(btn8_1_5);
		
		JButton btn8_2_5 = new JButton("");
		btn8_2_5.setEnabled(false);
		btn8_2_5.setBounds(223, 344, 50, 50);
		panel_8.add(btn8_2_5);
		
		JButton btn8_3_5 = new JButton("");
		btn8_3_5.setEnabled(false);
		btn8_3_5.setBounds(283, 344, 50, 50);
		panel_8.add(btn8_3_5);
		
		JButton btn8_4_5 = new JButton("");
		btn8_4_5.setEnabled(false);
		btn8_4_5.setBounds(343, 344, 50, 50);
		panel_8.add(btn8_4_5);
		
		JButton btn8_5_5 = new JButton("");
		btn8_5_5.setEnabled(false);
		btn8_5_5.setBounds(403, 344, 50, 50);
		panel_8.add(btn8_5_5);
		
		JButton btn8_6_5 = new JButton("");
		btn8_6_5.setEnabled(false);
		btn8_6_5.setBounds(463, 344, 50, 50);
		panel_8.add(btn8_6_5);
		
		JButton btn8_7_5 = new JButton("");
		btn8_7_5.setEnabled(false);
		btn8_7_5.setBounds(523, 344, 50, 50);
		panel_8.add(btn8_7_5);
		
		JButton btn8_8_5 = new JButton("");
		btn8_8_5.setEnabled(false);
		btn8_8_5.setBounds(583, 344, 50, 50);
		panel_8.add(btn8_8_5);
		
		JPanel panel_9 = new JPanel();
		panel_9.setBounds(0, 0, 803, 399);
		contentPane.add(panel_9);
		panel_9.setVisible(false);
		panel_9.setLayout(null);
		
		JButton btn9_1 = new JButton("");
		btn9_1.setBounds(116, 35, 50, 50);
		panel_9.add(btn9_1);
		
		JButton btn9_2 = new JButton("");
		btn9_2.setBounds(176, 35, 50, 50);
		panel_9.add(btn9_2);
		
		JButton btn9_3 = new JButton("");
		btn9_3.setBounds(236, 35, 50, 50);
		panel_9.add(btn9_3);
		
		JButton btn9_4 = new JButton("");
		btn9_4.setBounds(296, 35, 50, 50);
		panel_9.add(btn9_4);
		
		JButton btn9_5 = new JButton("");
		btn9_5.setBounds(356, 35, 50, 50);
		panel_9.add(btn9_5);
		
		JButton btn9_6 = new JButton("");
		btn9_6.setBounds(416, 35, 50, 50);
		panel_9.add(btn9_6);
		
		JButton btn9_7 = new JButton("");
		btn9_7.setBounds(476, 35, 50, 50);
		panel_9.add(btn9_7);
		
		JButton btn9_8 = new JButton("");
		btn9_8.setBounds(536, 35, 50, 50);
		panel_9.add(btn9_8);
		
		JButton btn9_9 = new JButton("");
		btn9_9.setBounds(596, 35, 50, 50);
		panel_9.add(btn9_9);
		
		JButton btn9_1_1 = new JButton("");
		btn9_1_1.setEnabled(false);
		btn9_1_1.setBounds(116, 96, 50, 50);
		panel_9.add(btn9_1_1);
		
		JButton btn9_2_1 = new JButton("");
		btn9_2_1.setEnabled(false);
		btn9_2_1.setBounds(176, 96, 50, 50);
		panel_9.add(btn9_2_1);
		
		JButton btn9_3_1 = new JButton("");
		btn9_3_1.setEnabled(false);
		btn9_3_1.setBounds(236, 96, 50, 50);
		panel_9.add(btn9_3_1);
		
		JButton btn9_4_1 = new JButton("");
		btn9_4_1.setEnabled(false);
		btn9_4_1.setBounds(296, 96, 50, 50);
		panel_9.add(btn9_4_1);
		
		JButton btn9_5_1 = new JButton("");
		btn9_5_1.setEnabled(false);
		btn9_5_1.setBounds(356, 96, 50, 50);
		panel_9.add(btn9_5_1);
		
		JButton btn9_6_1 = new JButton("");
		btn9_6_1.setEnabled(false);
		btn9_6_1.setBounds(416, 96, 50, 50);
		panel_9.add(btn9_6_1);
		
		JButton btn9_7_1 = new JButton("");
		btn9_7_1.setEnabled(false);
		btn9_7_1.setBounds(476, 96, 50, 50);
		panel_9.add(btn9_7_1);
		
		JButton btn9_8_1 = new JButton("");
		btn9_8_1.setEnabled(false);
		btn9_8_1.setBounds(536, 96, 50, 50);
		panel_9.add(btn9_8_1);
		
		JButton btn9_9_1 = new JButton("");
		btn9_9_1.setEnabled(false);
		btn9_9_1.setBounds(596, 96, 50, 50);
		panel_9.add(btn9_9_1);
		
		JButton btn9_1_2 = new JButton("");
		btn9_1_2.setEnabled(false);
		btn9_1_2.setBounds(116, 157, 50, 50);
		panel_9.add(btn9_1_2);
		
		JButton btn9_2_2 = new JButton("");
		btn9_2_2.setEnabled(false);
		btn9_2_2.setBounds(176, 157, 50, 50);
		panel_9.add(btn9_2_2);
		
		JButton btn9_3_2 = new JButton("");
		btn9_3_2.setEnabled(false);
		btn9_3_2.setBounds(236, 157, 50, 50);
		panel_9.add(btn9_3_2);
		
		JButton btn9_4_2 = new JButton("");
		btn9_4_2.setEnabled(false);
		btn9_4_2.setBounds(296, 157, 50, 50);
		panel_9.add(btn9_4_2);
		
		JButton btn9_5_2 = new JButton("");
		btn9_5_2.setEnabled(false);
		btn9_5_2.setBounds(356, 157, 50, 50);
		panel_9.add(btn9_5_2);
		
		JButton btn9_6_2 = new JButton("");
		btn9_6_2.setEnabled(false);
		btn9_6_2.setBounds(416, 157, 50, 50);
		panel_9.add(btn9_6_2);
		
		JButton btn9_7_2 = new JButton("");
		btn9_7_2.setEnabled(false);
		btn9_7_2.setBounds(476, 157, 50, 50);
		panel_9.add(btn9_7_2);
		
		JButton btn9_8_2 = new JButton("");
		btn9_8_2.setEnabled(false);
		btn9_8_2.setBounds(536, 157, 50, 50);
		panel_9.add(btn9_8_2);
		
		JButton btn9_9_2 = new JButton("");
		btn9_9_2.setEnabled(false);
		btn9_9_2.setBounds(596, 157, 50, 50);
		panel_9.add(btn9_9_2);
		
		JButton btn9_1_3 = new JButton("");
		btn9_1_3.setEnabled(false);
		btn9_1_3.setBounds(116, 218, 50, 50);
		panel_9.add(btn9_1_3);
		
		JButton btn9_2_3 = new JButton("");
		btn9_2_3.setEnabled(false);
		btn9_2_3.setBounds(176, 218, 50, 50);
		panel_9.add(btn9_2_3);
		
		JButton btn9_3_3 = new JButton("");
		btn9_3_3.setEnabled(false);
		btn9_3_3.setBounds(236, 218, 50, 50);
		panel_9.add(btn9_3_3);
		
		JButton btn9_4_3 = new JButton("");
		btn9_4_3.setEnabled(false);
		btn9_4_3.setBounds(296, 218, 50, 50);
		panel_9.add(btn9_4_3);
		
		JButton btn9_5_3 = new JButton("");
		btn9_5_3.setEnabled(false);
		btn9_5_3.setBounds(356, 218, 50, 50);
		panel_9.add(btn9_5_3);
		
		JButton btn9_6_3 = new JButton("");
		btn9_6_3.setEnabled(false);
		btn9_6_3.setBounds(416, 218, 50, 50);
		panel_9.add(btn9_6_3);
		
		JButton btn9_7_3 = new JButton("");
		btn9_7_3.setEnabled(false);
		btn9_7_3.setBounds(476, 218, 50, 50);
		panel_9.add(btn9_7_3);
		
		JButton btn9_8_3 = new JButton("");
		btn9_8_3.setEnabled(false);
		btn9_8_3.setBounds(536, 218, 50, 50);
		panel_9.add(btn9_8_3);
		
		JButton btn9_9_3 = new JButton("");
		btn9_9_3.setEnabled(false);
		btn9_9_3.setBounds(596, 218, 50, 50);
		panel_9.add(btn9_9_3);
		
		JButton btn9_1_4 = new JButton("");
		btn9_1_4.setEnabled(false);
		btn9_1_4.setBounds(116, 279, 50, 50);
		panel_9.add(btn9_1_4);
		
		JButton btn9_2_4 = new JButton("");
		btn9_2_4.setEnabled(false);
		btn9_2_4.setBounds(176, 279, 50, 50);
		panel_9.add(btn9_2_4);
		
		JButton btn9_3_4 = new JButton("");
		btn9_3_4.setEnabled(false);
		btn9_3_4.setBounds(236, 279, 50, 50);
		panel_9.add(btn9_3_4);
		
		JButton btn9_4_4 = new JButton("");
		btn9_4_4.setEnabled(false);
		btn9_4_4.setBounds(296, 279, 50, 50);
		panel_9.add(btn9_4_4);
		
		JButton btn9_5_4 = new JButton("");
		btn9_5_4.setEnabled(false);
		btn9_5_4.setBounds(356, 279, 50, 50);
		panel_9.add(btn9_5_4);
		
		JButton btn9_6_4 = new JButton("");
		btn9_6_4.setEnabled(false);
		btn9_6_4.setBounds(416, 279, 50, 50);
		panel_9.add(btn9_6_4);
		
		JButton btn9_7_4 = new JButton("");
		btn9_7_4.setEnabled(false);
		btn9_7_4.setBounds(476, 279, 50, 50);
		panel_9.add(btn9_7_4);
		
		JButton btn9_8_4 = new JButton("");
		btn9_8_4.setEnabled(false);
		btn9_8_4.setBounds(536, 279, 50, 50);
		panel_9.add(btn9_8_4);
		
		JButton btn9_9_4 = new JButton("");
		btn9_9_4.setEnabled(false);
		btn9_9_4.setBounds(596, 279, 50, 50);
		panel_9.add(btn9_9_4);
		
		JButton btn9_1_5 = new JButton("");
		btn9_1_5.setEnabled(false);
		btn9_1_5.setBounds(116, 340, 50, 50);
		panel_9.add(btn9_1_5);
		
		JButton btn9_2_5 = new JButton("");
		btn9_2_5.setEnabled(false);
		btn9_2_5.setBounds(176, 340, 50, 50);
		panel_9.add(btn9_2_5);
		
		JButton btn9_3_5 = new JButton("");
		btn9_3_5.setEnabled(false);
		btn9_3_5.setBounds(236, 340, 50, 50);
		panel_9.add(btn9_3_5);
		
		JButton btn9_4_5 = new JButton("");
		btn9_4_5.setEnabled(false);
		btn9_4_5.setBounds(296, 340, 50, 50);
		panel_9.add(btn9_4_5);
		
		JButton btn9_5_5 = new JButton("");
		btn9_5_5.setEnabled(false);
		btn9_5_5.setBounds(356, 340, 50, 50);
		panel_9.add(btn9_5_5);
		
		JButton btn9_6_5 = new JButton("");
		btn9_6_5.setEnabled(false);
		btn9_6_5.setBounds(416, 340, 50, 50);
		panel_9.add(btn9_6_5);
		
		JButton btn9_7_5 = new JButton("");
		btn9_7_5.setEnabled(false);
		btn9_7_5.setBounds(476, 340, 50, 50);
		panel_9.add(btn9_7_5);
		
		JButton btn9_8_5 = new JButton("");
		btn9_8_5.setEnabled(false);
		btn9_8_5.setBounds(536, 340, 50, 50);
		panel_9.add(btn9_8_5);
		
		JButton btn9_9_5 = new JButton("");
		btn9_9_5.setEnabled(false);
		btn9_9_5.setBounds(596, 340, 50, 50);
		panel_9.add(btn9_9_5);
		
		JPanel panel_main = new JPanel();
		panel_main.setBounds(0, 0, 803, 682);
		contentPane.add(panel_main);
		panel_main.setLayout(null);
		
		JButton btnNewGame = new JButton("New Game");
		btnNewGame.setBounds(299, 54, 100, 80);
		panel_main.add(btnNewGame);
		
		JLabel lblTest = new JLabel("");
		lblTest.setHorizontalAlignment(SwingConstants.CENTER);
		lblTest.setFont(new Font("Tahoma", Font.PLAIN, 40));
		lblTest.setBounds(217, 250, 278, 80);
		panel_main.add(lblTest);
		
		JLabel lblTestLen = new JLabel("");
		lblTestLen.setHorizontalAlignment(SwingConstants.CENTER);
		lblTestLen.setFont(new Font("Tahoma", Font.PLAIN, 40));
		lblTestLen.setBounds(217, 339, 278, 80);
		panel_main.add(lblTestLen);
		
		JButton btnTest = new JButton("Test");
		btnTest.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				equation = mainPrg.GenerateEquation();
				lblTest.setText(equation);
				lblTestLen.setText("Length: "+String.valueOf(equation.length()));
			}
		});
		btnTest.setBounds(299, 145, 100, 80);
		panel_main.add(btnTest);
		
		
		
		btnNewGame.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				sec=0;
				gameTimer();
				timer.start();
				
				
				
				btnNewGame.setVisible(false);
				panel_key.setVisible(true);
				btnTest.setVisible(false);
				lblTest.setVisible(false);
				lblTestLen.setVisible(false);
				equation = mainPrg.GenerateEquation();				
				System.out.println(equation+" : "+String.valueOf(equation.length()));

				panel_num = equation.length();
				switch(equation.length()) {
				case 7:
					panel_7.setVisible(true);
					panel_8.setVisible(false);
					panel_9.setVisible(false);
					break;
				case 8:
					panel_8.setVisible(true);
					panel_7.setVisible(false);
					panel_9.setVisible(false);
					break;
				case 9:
					panel_7.setVisible(false);
					panel_8.setVisible(false);
					panel_9.setVisible(true);
					break;
			}
			}
		});
		
		JButton[][] buttons7 = {
				{btn7_1,btn7_2,btn7_3,btn7_4,btn7_5,btn7_6,btn7_7},
				{btn7_1_1,btn7_2_1,btn7_3_1,btn7_4_1,btn7_5_1,btn7_6_1,btn7_7_1},
				{btn7_1_2,btn7_2_2,btn7_3_2,btn7_4_2,btn7_5_2,btn7_6_2,btn7_7_2},
				{btn7_1_3,btn7_2_3,btn7_3_3,btn7_4_3,btn7_5_3,btn7_6_3,btn7_7_3},
				{btn7_1_4,btn7_2_4,btn7_3_4,btn7_4_4,btn7_5_4,btn7_6_4,btn7_7_4},
				{btn7_1_5,btn7_2_5,btn7_3_5,btn7_4_5,btn7_5_5,btn7_6_5,btn7_7_5}
		};
		JButton[][] buttons8 = {
				{btn8_1,btn8_2,btn8_3,btn8_4,btn8_5,btn8_6,btn8_7,btn8_8},
				{btn8_1_1,btn8_2_1,btn8_3_1,btn8_4_1,btn8_5_1,btn8_6_1,btn8_7_1,btn8_8_1},
				{btn8_1_2,btn8_2_2,btn8_3_2,btn8_4_2,btn8_5_2,btn8_6_2,btn8_7_2,btn8_8_2},
				{btn8_1_3,btn8_2_3,btn8_3_3,btn8_4_3,btn8_5_3,btn8_6_3,btn8_7_3,btn8_8_3},
				{btn8_1_4,btn8_2_4,btn8_3_4,btn8_4_4,btn8_5_4,btn8_6_4,btn8_7_4,btn8_8_4},
				{btn8_1_5,btn8_2_5,btn8_3_5,btn8_4_5,btn8_5_5,btn8_6_5,btn8_7_5,btn8_8_5}
		};
		JButton[][] buttons9 = {
				{btn9_1,btn9_2,btn9_3,btn9_4,btn9_5,btn9_6,btn9_7,btn9_8,btn9_9},
				{btn9_1_1,btn9_2_1,btn9_3_1,btn9_4_1,btn9_5_1,btn9_6_1,btn9_7_1,btn9_8_1,btn9_9_1},
				{btn9_1_2,btn9_2_2,btn9_3_2,btn9_4_2,btn9_5_2,btn9_6_2,btn9_7_2,btn9_8_2,btn9_9_2},
				{btn9_1_3,btn9_2_3,btn9_3_3,btn9_4_3,btn9_5_3,btn9_6_3,btn9_7_3,btn9_8_3,btn9_9_3},
				{btn9_1_4,btn9_2_4,btn9_3_4,btn9_4_4,btn9_5_4,btn9_6_4,btn9_7_4,btn9_8_4,btn9_9_4},
				{btn9_1_5,btn9_2_5,btn9_3_5,btn9_4_5,btn9_5_5,btn9_6_5,btn9_7_5,btn9_8_5,btn9_9_5}
		};
		
		JButton[] keyboard = {btn0,btn1,btn2,btn3,btn4,btn5,btn6,btn7,btn8,btn9,btnSum,btnSub,btnMul,btnDiv,btnEqual};
		
		ActionListener activeButton = new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				activeBtn = (JButton) e.getSource();
			}
		};
		for(i=0;i<6;i++) {
			for(j=0;j<7;j++){
				buttons7[i][j].addActionListener(activeButton);
			}
		}
		for(i=0;i<6;i++) {
			for(j=0;j<8;j++){
				buttons8[i][j].addActionListener(activeButton);
			}
		}
		for(i=0;i<6;i++) {
			for(j=0;j<9;j++){
				buttons9[i][j].addActionListener(activeButton);
			}
		}
		ActionListener keyListener = new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				keyboardBtn = (JButton) e.getSource();
				activeBtn.setText(keyboardBtn.getText());
			}
		};
		for(JButton btn: keyboard) {
			btn.addActionListener(keyListener);
		}
		JButton[][][] panel_buttons= {buttons7,buttons8,buttons9};
		
		btnControl.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e)  {				
				try{
					expression="";
					for(i=0;i<panel_num;i++) {
						expression = expression+panel_buttons[panel_num-7][activeRow][i].getText();
						
					}
				    
					char[] equationArr = equation.toCharArray();
					char[] expressionArr = expression.toCharArray();
					char[] operators = "+-*/".toCharArray();
					
					if(equation.equals(expression)) {
						panel_end.setVisible(true);
						lblTry.setText(String.valueOf(activeRow+1)+"/6");
						lblTime.setText(String.valueOf(sec));
						lblWinLose.setText("You Win!");
						timer.stop();
						lblTimer.setVisible(false);
						lblTimeText.setVisible(false);

						switch(panel_num) {
						case 7:
							panel_7.setVisible(false);
							break;
						case 8:
							panel_8.setVisible(false);
							break;
						case 9:
							panel_9.setVisible(false);
							break;
						}
						
					}
					else {
						String result = expression.split("=")[1];
						String exp = expression.split("=")[0];
						int res = Integer.parseInt(result);
					
						for(char op: operators) {
							for(char c: exp.toCharArray()) {
								if (op == c) {
									operator = op;
									
								}
							}
						}
						
						oper = '\\'+String.valueOf(operator);
						
						
						int num1 = Integer.parseInt(exp.split(oper)[0]);
						int num2 = Integer.parseInt(exp.split(oper)[1]);
						int realRes=0;
						if(oper.charAt(1) == "+".toCharArray()[0]) {
							realRes= num1+num2;
						}else if(oper.charAt(1) == "-".toCharArray()[0]) {
							realRes=num1-num2;
						}else if(oper.charAt(1) == "*".toCharArray()[0]) {
							realRes=num1*num2;
						}else if(oper.charAt(1) == "/".toCharArray()[0]) {
							realRes=num1/num2;
						}
						
						if(res==realRes) {
							for(i=0;i<panel_num;i++) {
								if(expressionArr[i] == equationArr[i]) {
									panel_buttons[panel_num-7][activeRow][i].setBackground(Color.GREEN);
								}else {
									panel_buttons[panel_num-7][activeRow][i].setBackground(Color.RED);
									for(char c:equationArr) {
										if(expressionArr[i] == c) {
											panel_buttons[panel_num-7][activeRow][i].setBackground(Color.YELLOW);
										}
									}
								}
							}
							if(activeRow < 5) {
								for(i=0;i<panel_num;i++) {
									panel_buttons[panel_num-7][activeRow][i].setEnabled(false);
									panel_buttons[panel_num-7][activeRow+1][i].setEnabled(true);
									activeBtn = null;
								}
								activeRow++;
							}else {
								panel_end.setVisible(true);
								lblTry.setText(String.valueOf(activeRow+1)+"/6");
								lblTime.setText(String.valueOf(sec));
								timer.stop();
								lblTimer.setVisible(false);
								lblTimeText.setVisible(false);
								lblWinLose.setText("You Lose!");
								lblEquation.setText("Equation: "+equation);
								switch(panel_num) {
									case 7:
										panel_7.setVisible(false);
										break;
									case 8:
										panel_8.setVisible(false);
										break;
									case 9:
										panel_9.setVisible(false);
										break;
								}
							}
						}
						else {
							JOptionPane.showMessageDialog(null,
					                "Check your expression!",
					                "Error",
					                JOptionPane.ERROR_MESSAGE);
							
						}
						
					}
				}catch(Exception e1) {
					JOptionPane.showMessageDialog(null,
			                e1.getMessage(),
			                "Error",
			                JOptionPane.ERROR_MESSAGE);
				}
			}
		});
		
	}
	public void gameTimer() {
		timer = new Timer(1000,new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				sec++;
				lblTimer.setText(String.valueOf(sec));
			}
		});
	}
}
