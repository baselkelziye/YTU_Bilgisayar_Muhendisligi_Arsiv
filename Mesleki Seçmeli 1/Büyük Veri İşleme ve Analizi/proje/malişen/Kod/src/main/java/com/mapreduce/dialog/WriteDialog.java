package com.mapreduce.dialog;

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.IOException;
import java.util.Arrays;

import javax.swing.DefaultComboBoxModel;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JDialog;
import javax.swing.JFileChooser;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;

import com.mapreduce.ReadWrite;

public class WriteDialog extends JDialog {

	private final JPanel contentPanel = new JPanel();
	private JLabel lblNewLabel;
	private JLabel lblNewLabel_1;
	private JButton btnNewButton;
	private JFileChooser fileChooser = new JFileChooser();
	private JComboBox<String> comboBox;
	private String[] outputs;

	/**
	 * Create the dialog.
	 */
	public WriteDialog() {
		setTitle("Write");
		setBounds(100, 100, 555, 156);
		getContentPane().setLayout(new BorderLayout());
		contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		getContentPane().add(contentPanel, BorderLayout.CENTER);
		GridBagLayout gbl_contentPanel = new GridBagLayout();
		gbl_contentPanel.columnWidths = new int[]{17, 449, 0};
		gbl_contentPanel.rowHeights = new int[]{39, 39, 0};
		gbl_contentPanel.columnWeights = new double[]{0.0, 0.0, Double.MIN_VALUE};
		gbl_contentPanel.rowWeights = new double[]{0.0, 0.0, Double.MIN_VALUE};
		contentPanel.setLayout(gbl_contentPanel);
		{
			lblNewLabel_1 = new JLabel("Input: ");
			GridBagConstraints gbc_lblNewLabel_1 = new GridBagConstraints();
			gbc_lblNewLabel_1.anchor = GridBagConstraints.WEST;
			gbc_lblNewLabel_1.fill = GridBagConstraints.VERTICAL;
			gbc_lblNewLabel_1.insets = new Insets(0, 0, 5, 5);
			gbc_lblNewLabel_1.gridx = 0;
			gbc_lblNewLabel_1.gridy = 0;
			contentPanel.add(lblNewLabel_1, gbc_lblNewLabel_1);
			lblNewLabel_1.setFont(new Font("Tahoma", Font.PLAIN, 18));
		}
		{
			fileChooser.setCurrentDirectory(new File("."));
			btnNewButton = new JButton("Choose");
			btnNewButton.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					switch (fileChooser.showOpenDialog(WriteDialog.this)) {
						case JFileChooser.APPROVE_OPTION:
							btnNewButton.setText(fileChooser.getSelectedFile().getPath());
							String[] arr = Arrays.copyOf(outputs, outputs.length);
							for (int i = 0; i < outputs.length; i++) {
								arr[i] = outputs[i] + fileChooser.getSelectedFile().getName();
							}
							comboBox.setModel(new DefaultComboBoxModel<String>(arr));
							break;
						case JFileChooser.CANCEL_OPTION:
							break;					 
						case JFileChooser.ERROR_OPTION:
							btnNewButton.setText("Error");
							break;
					}				}
			});
			btnNewButton.setFont(new Font("Tahoma", Font.PLAIN, 18));
			GridBagConstraints gbc_btnNewButton = new GridBagConstraints();
			gbc_btnNewButton.fill = GridBagConstraints.BOTH;
			gbc_btnNewButton.insets = new Insets(0, 0, 5, 0);
			gbc_btnNewButton.gridx = 1;
			gbc_btnNewButton.gridy = 0;
			contentPanel.add(btnNewButton, gbc_btnNewButton);
		}
		{
			lblNewLabel = new JLabel("Output: ");
			GridBagConstraints gbc_lblNewLabel = new GridBagConstraints();
			gbc_lblNewLabel.anchor = GridBagConstraints.WEST;
			gbc_lblNewLabel.fill = GridBagConstraints.VERTICAL;
			gbc_lblNewLabel.insets = new Insets(0, 0, 0, 5);
			gbc_lblNewLabel.gridx = 0;
			gbc_lblNewLabel.gridy = 1;
			contentPanel.add(lblNewLabel, gbc_lblNewLabel);
			lblNewLabel.setFont(new Font("Tahoma", Font.PLAIN, 18));
		}
		{
			comboBox = new JComboBox<String>();
			comboBox.setFont(new Font("Tahoma", Font.PLAIN, 18));
			try {
				outputs = ReadWrite.getDirectories("/", true);
			} catch (IllegalArgumentException | IOException e) {
				e.printStackTrace();
			}
			comboBox.setModel(new DefaultComboBoxModel<String>(outputs));
			
			GridBagConstraints gbc_textField = new GridBagConstraints();
			gbc_textField.fill = GridBagConstraints.HORIZONTAL;
			gbc_textField.gridx = 1;
			gbc_textField.gridy = 1;
			contentPanel.add(comboBox, gbc_textField);
		}
		{
			JPanel buttonPane = new JPanel();
			buttonPane.setLayout(new FlowLayout(FlowLayout.RIGHT));
			getContentPane().add(buttonPane, BorderLayout.SOUTH);
			{
				final JButton okButton = new JButton("OK");
				okButton.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {
						try {
							String input = btnNewButton.getText();
							if (input == null || input.equals("Choose")) return;
							String output = (String) comboBox.getSelectedItem();
							if (output == null || output.trim().isEmpty()) return;
							ReadWrite.writeFile(output, input);
							// JOptionPane.showMessageDialog(okButton.getParent(), "Success", "Success", JOptionPane.INFORMATION_MESSAGE);
						} catch (IOException err) {
							err.printStackTrace();
							// JOptionPane.showMessageDialog(okButton.getParent(), err.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
						}
						dispose();
					}
				});
				okButton.setActionCommand("OK");
				buttonPane.add(okButton);
				getRootPane().setDefaultButton(okButton);
			}
			{
				JButton cancelButton = new JButton("Cancel");
				cancelButton.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {
						dispose();
					}
				});
				cancelButton.setActionCommand("Cancel");
				buttonPane.add(cancelButton);
			}
		}
		setDefaultCloseOperation(JDialog.DISPOSE_ON_CLOSE);
		setVisible(true);
	}

}
