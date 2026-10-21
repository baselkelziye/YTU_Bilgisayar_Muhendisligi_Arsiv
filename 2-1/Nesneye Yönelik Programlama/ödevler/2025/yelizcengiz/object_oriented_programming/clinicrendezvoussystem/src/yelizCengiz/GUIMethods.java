package yelizCengiz;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.lang.reflect.Method;
import java.util.Properties;

import javax.swing.JButton;
import javax.swing.JCheckBox;
import javax.swing.JComboBox;
import javax.swing.JLabel;
import javax.swing.JRadioButton;
import javax.swing.JTable;
import javax.swing.JTextField;

public class GUIMethods {
	
	public static void addDatePicker(int locX, int locY, int sizeX, int sizeY,String name) {
		Properties properties =new Properties();
	}
	
	public static JComboBox<String> addComboBox(int locX, int locY, int sizeX, int sizeY,String name, String[] options){
		JComboBox< String> comboBox=new JComboBox<String>(options);
		comboBox.setBounds(locX, locY, sizeX, sizeY);
		comboBox.setName(name);
		Main.components.add(comboBox);
		comboBox.setVisible(false);
		Main.frame.add(comboBox);
		return comboBox;
	}
	
	public static JRadioButton addRatioButton(String text,int locX, int locY, int sizeX, int sizeY,String name) {
		JRadioButton radioButton=new JRadioButton(text);
		radioButton.setBounds(locX, locY, sizeX, sizeY);
		radioButton.setName(name);
		Main.components.add(radioButton);
		radioButton.setVisible(false);
		Main.frame.add(radioButton);
		return radioButton;
	}
	
	public static void addCheckBox(String text,int locX, int locY, int sizeX, int sizeY,String name) {
		JCheckBox checkBox=new JCheckBox(text);   //isSelected ile
		checkBox.setBounds(locX, locY, sizeX, sizeY);
		checkBox.setName(name);
		checkBox.setEnabled(true);
		Main.components.add(checkBox);
		checkBox.setVisible(false);
		Main.frame.add(checkBox);
	}
	
	public static void addTextField(String text,int locX, int locY, int sizeX, int sizeY,String name) {
		JTextField textField=new JTextField(text);//gettext ile
		textField.setBounds(locX, locY, sizeX, sizeY);
		textField.setName(name);
		Main.components.add(textField);
		textField.setVisible(false);
		Main.frame.add(textField);
	}
	
	
	public static void addLabel(String text, int locX, int locY, int sizeX, int sizeY,String name) {
		JLabel label=new JLabel(text);
		label.setBounds(locX, locY, sizeX, sizeY);
		label.setName(name);
		Main.components.add(label);
		label.setVisible(false);
		Main.frame.add(label);
	}
	
	public static void addTable(int locX, int locY, int sizeX, int sizeY,String name,String[][] data,String[] titles) {
		JTable table=new JTable(data,titles);
		table.setBounds(locX, locY, sizeX, sizeY);
		table.setName(name);
		Main.components.add(table);
		table.setVisible(false);
		Main.frame.add(table);
	}
	
	public static void addButton(String text, int locX, int locY, int sizeX, int sizeY,String name , String methodName) {
		JButton button =new JButton(text);
		button.setBounds(locX, locY, sizeX, sizeY);
		button.setName(name);
		Main.components.add(button);
		button.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				Method method;
				try {
					method=Main.class.getMethod(methodName, null);
					method.invoke(this);
					
				} catch (Exception e1) {
					e1.printStackTrace();
				}			
			}
		});
		button.setVisible(false);
		Main.frame.add(button);
	}
	
}
