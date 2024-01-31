package com.mapreduce.dialog;

import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridBagConstraints;
import java.awt.GridBagLayout;
import java.awt.Insets;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;

import javax.swing.DefaultComboBoxModel;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JDialog;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;

import com.mapreduce.ReadWrite;

public class CreateDirectoryDialog extends JDialog {

	private final JPanel contentPanel = new JPanel();
	private JTextField textField_1;
	private JLabel lblNewLabel_1;
	private JComboBox<String> comboBox;

	/**
	 * Create the dialog.
	 */
	public CreateDirectoryDialog() {
		setTitle("Create Directory");
		setBounds(100, 100, 555, 152);
		getContentPane().setLayout(new BorderLayout());
		contentPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		getContentPane().add(contentPanel, BorderLayout.CENTER);
		GridBagLayout gbl_contentPanel = new GridBagLayout();
		gbl_contentPanel.columnWidths = new int[]{-10, 465, 0};
		gbl_contentPanel.rowHeights = new int[]{0, 39, 0};
		gbl_contentPanel.columnWeights = new double[]{0.0, 1.0, Double.MIN_VALUE};
		gbl_contentPanel.rowWeights = new double[]{0.0, 0.0, Double.MIN_VALUE};
		contentPanel.setLayout(gbl_contentPanel);
		{
			JLabel lblNewLabel_1_1 = new JLabel("Path: ");
			lblNewLabel_1_1.setFont(new Font("Tahoma", Font.PLAIN, 18));
			GridBagConstraints gbc_lblNewLabel_1_1 = new GridBagConstraints();
			gbc_lblNewLabel_1_1.anchor = GridBagConstraints.EAST;
			gbc_lblNewLabel_1_1.insets = new Insets(0, 0, 5, 5);
			gbc_lblNewLabel_1_1.gridx = 0;
			gbc_lblNewLabel_1_1.gridy = 0;
			contentPanel.add(lblNewLabel_1_1, gbc_lblNewLabel_1_1);
		}
		{
			comboBox = new JComboBox<String>();
			comboBox.setFont(new Font("Tahoma", Font.PLAIN, 18));
			try {
				comboBox.setModel(new DefaultComboBoxModel<String>(ReadWrite.getDirectories("/", true)));
			} catch (IllegalArgumentException | IOException e) {
				e.printStackTrace();
			}
			GridBagConstraints gbc_textField = new GridBagConstraints();
			gbc_textField.insets = new Insets(0, 0, 5, 0);
			gbc_textField.fill = GridBagConstraints.HORIZONTAL;
			gbc_textField.gridx = 1;
			gbc_textField.gridy = 0;
			contentPanel.add(comboBox, gbc_textField);
		}
		{
			lblNewLabel_1 = new JLabel("Name: ");
			GridBagConstraints gbc_lblNewLabel_1 = new GridBagConstraints();
			gbc_lblNewLabel_1.fill = GridBagConstraints.BOTH;
			gbc_lblNewLabel_1.insets = new Insets(0, 0, 0, 5);
			gbc_lblNewLabel_1.gridx = 0;
			gbc_lblNewLabel_1.gridy = 1;
			contentPanel.add(lblNewLabel_1, gbc_lblNewLabel_1);
			lblNewLabel_1.setFont(new Font("Tahoma", Font.PLAIN, 18));
		}
		{
			textField_1 = new JTextField();
			lblNewLabel_1.setLabelFor(textField_1);
			GridBagConstraints gbc_textField_1 = new GridBagConstraints();
			gbc_textField_1.fill = GridBagConstraints.HORIZONTAL;
			gbc_textField_1.gridx = 1;
			gbc_textField_1.gridy = 1;
			contentPanel.add(textField_1, gbc_textField_1);
			textField_1.setFont(new Font("Tahoma", Font.PLAIN, 18));
			textField_1.setColumns(10);
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
							String path = (String) comboBox.getSelectedItem();
							if (path == null || path.trim().isEmpty()) return;
							String name = textField_1.getText();
							if (name == null || name.trim().isEmpty()) return;
							ReadWrite.createDirectory(path + name);
							System.out.println("\n\n");
							System.out.println("Created");
						} catch (IOException err) {
							err.printStackTrace();
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
