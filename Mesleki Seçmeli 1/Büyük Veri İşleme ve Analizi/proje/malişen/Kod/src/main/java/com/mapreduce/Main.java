package com.mapreduce;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

import javax.swing.BoxLayout;
import javax.swing.DefaultComboBoxModel;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextPane;
import javax.swing.SwingConstants;

import com.mapreduce.dialog.CreateDirectoryDialog;
import com.mapreduce.dialog.ReadDialog;
import com.mapreduce.dialog.RemoveDialog;
import com.mapreduce.dialog.RemoveDirectoryDialog;
import com.mapreduce.dialog.WriteDialog;
import com.mapreduce.dialog.jobs.DateAverageDialog;
import com.mapreduce.dialog.jobs.MinMaxReviewDialog;
import com.mapreduce.dialog.jobs.MovieAverageDialog;
import com.mapreduce.dialog.jobs.StandardDeviationDialog;
import com.mapreduce.dialog.jobs.TotalReviewsDialog;
import com.mapreduce.util.PrintStreamCapturer;
import com.mapreduce.util.ProcessHandler;
import com.mapreduce.util.ServiceStatus;

public class Main {

	private JFrame frame;

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					Main window = new Main();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public Main() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		frame = new JFrame();
		frame.setBounds(100, 100, 1280, 720);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		JPanel panel = new JPanel();
		panel.setBounds(7, 10, 1249, 62);
		panel.setLayout(new BoxLayout(panel, BoxLayout.X_AXIS));
		
		JPanel panel_1 = new JPanel();
		panel.add(panel_1);
		panel_1.setLayout(new GridLayout(2, 4, 0, 0));
		
		JLabel lblHadoop_2 = new JLabel("Hadoop: ");
		lblHadoop_2.setHorizontalAlignment(SwingConstants.RIGHT);
		panel_1.add(lblHadoop_2);
		lblHadoop_2.setFont(new Font("Tahoma", Font.PLAIN, 18));
		
		final JTextPane txtpnAsd_1 = new JTextPane();
		panel_1.add(txtpnAsd_1);
		txtpnAsd_1.setText(ServiceStatus.hadoop() ? "on" : "off");
		txtpnAsd_1.setFont(new Font("Tahoma", Font.PLAIN, 18));
		txtpnAsd_1.setEditable(false);
		
		JButton btnStart = new JButton("Start");
		btnStart.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panel_1.add(btnStart);
		
		JButton btnStop = new JButton("Stop");
		btnStop.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panel_1.add(btnStop);
		
		JLabel lblHadoop = new JLabel("Yarn: ");
		lblHadoop.setHorizontalAlignment(SwingConstants.RIGHT);
		panel_1.add(lblHadoop);
		lblHadoop.setFont(new Font("Tahoma", Font.PLAIN, 18));
		
		final JTextPane txtpnAsd = new JTextPane();
		panel_1.add(txtpnAsd);
		txtpnAsd.setEditable(false);
		txtpnAsd.setText(ServiceStatus.yarn() ? "on" : "off");
		txtpnAsd.setFont(new Font("Tahoma", Font.PLAIN, 18));
		
		JButton btnStart_1 = new JButton("Start");
		btnStart_1.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panel_1.add(btnStart_1);
		
		JButton btnStop_1 = new JButton("Stop");
		btnStop_1.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panel_1.add(btnStop_1);
		
		JPanel panel_2 = new JPanel();
		panel.add(panel_2);
		panel_2.setLayout(new GridLayout(0, 3, 0, 0));
		
		JButton btnRead = new JButton("Read");
		panel_2.add(btnRead);
		btnRead.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				new ReadDialog();
			}
		});
		btnRead.setFont(new Font("Tahoma", Font.PLAIN, 18));
		
		JButton btnNewButton = new JButton("Write");
		panel_2.add(btnNewButton);
		btnNewButton.setFont(new Font("Tahoma", Font.PLAIN, 18));
		
		JButton btnNewButton_2 = new JButton("List");
		btnNewButton_2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					ReadWrite.listFiles("/");
				} catch (IllegalArgumentException | IOException e1) {
					e1.printStackTrace();
				}
			}
		});
		
		JButton btnCreateDirectory_1 = new JButton("Create Directory");
		btnCreateDirectory_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				new CreateDirectoryDialog();
			}
		});
		btnCreateDirectory_1.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panel_2.add(btnCreateDirectory_1);
		btnNewButton_2.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panel_2.add(btnNewButton_2);
		
		JButton btnCreateDirectory = new JButton("Remove");
		btnCreateDirectory.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				new RemoveDialog();
			}
		});
		btnCreateDirectory.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panel_2.add(btnCreateDirectory);
		
		JButton btnRemoveDirectory = new JButton("Remove Directory");
		btnRemoveDirectory.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				new RemoveDirectoryDialog();
			}
		});
		btnRemoveDirectory.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panel_2.add(btnRemoveDirectory);
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				new WriteDialog();
			}
		});
		btnStop_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					ProcessHandler.run("stop-yarn.sh");
					txtpnAsd.setText("off");
				} catch (IOException err) {
					err.printStackTrace();
					txtpnAsd.setText("error");
				}
			}
		});
		btnStart_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					ProcessHandler.run("start-yarn.sh");
					txtpnAsd.setText("on");
				} catch (IOException err) {
					err.printStackTrace();
					txtpnAsd.setText("error");
				}
			}
		});
		btnStop.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					ProcessHandler.run("stop-dfs.sh");
					txtpnAsd_1.setText("off");
				} catch (IOException err) {
					err.printStackTrace();
					txtpnAsd_1.setText("error");
				}
			}
		});
		btnStart.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				try {
					ProcessHandler.run("start-dfs.sh");
					txtpnAsd_1.setText("on");
				} catch (IOException err) {
					err.printStackTrace();
					txtpnAsd_1.setText("error");
				}
			}
		});
		
		JPanel panel_3 = new JPanel();
		panel_3.setBounds(7, 82, 1249, 591);
		frame.getContentPane().setLayout(null);
		frame.getContentPane().add(panel);
		
		JPanel panel_4 = new JPanel();
		panel.add(panel_4);
		panel_4.setLayout(new BorderLayout(0, 0));
		
		final JComboBox<Job> comboBox = new JComboBox<Job>();
		panel_4.add(comboBox);
		comboBox.setFont(new Font("Tahoma", Font.PLAIN, 18));
		comboBox.setModel(new DefaultComboBoxModel<Job>(Job.values()));
		comboBox.setSelectedIndex(0);

		JButton btnNewButton_1 = new JButton("Run");
		btnNewButton_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Job job = (Job) comboBox.getSelectedItem();
				switch (job) {
					case TotalReviews:
						new TotalReviewsDialog();
						break;
					case MovieAverage:
						new MovieAverageDialog();
						break;
					case MinMaxReview:
						new MinMaxReviewDialog();
						break;
					case DateAverage:
						new DateAverageDialog();
						break;
					case StandardDeviation:
						new StandardDeviationDialog();
						break;
					default:
						break;
				}
			}
		});
		btnNewButton_1.setFont(new Font("Tahoma", Font.PLAIN, 18));
		panel_4.add(btnNewButton_1, BorderLayout.SOUTH);
		frame.getContentPane().add(panel_3);
		panel_3.setLayout(new GridLayout(1, 1, 0, 0));
		
		JTextArea textArea = new JTextArea();
		textArea.setEditable(false);
		textArea.setLineWrap(true);
		// panel_3.add(textArea);
		System.setOut(new PrintStreamCapturer(textArea, System.out));
		System.setErr(new PrintStreamCapturer(textArea, System.err, "[ERROR] "));
		
		JScrollPane scrollPane = new JScrollPane(textArea);
		panel_3.add(scrollPane);
	}

	public enum Job {
		TotalReviews,
		MovieAverage,
		MinMaxReview,
		DateAverage,
		StandardDeviation;
	}
}
