package com.mapreduce.util;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;

import javax.swing.JComboBox;

@SuppressWarnings("all")
public class SelectionManager implements ActionListener {
	JComboBox combo = null;
	public List<Object> selectedItems = new ArrayList<Object>();  // j2se 1.5+
	// List selectedItems = new ArrayList();			   // j2se 1.4-
	List<Object> nonSelectables = new ArrayList<Object>();
  
	public void actionPerformed(ActionEvent e) {
		if(combo == null) {
			combo = (JComboBox)e.getSource();
		}
		Object item = combo.getSelectedItem();
		// Toggle the selection state for item.
		if(selectedItems.contains(item)) {
			selectedItems.remove(item);
		} else if(!nonSelectables.contains(item)) {
			selectedItems.add(item);
		}
	}
  
	/**
	 * The varargs feature (Object... args) is new in j2se 1.5
	 * You can replace the argument with an array.
	 */
	public void setNonSelectables(Object... args) {
		for(int j = 0; j < args.length; j++) {
			nonSelectables.add(args[j]);
		}
	}
  
	public boolean isSelected(Object item) {
		return selectedItems.contains(item);
	}
}
