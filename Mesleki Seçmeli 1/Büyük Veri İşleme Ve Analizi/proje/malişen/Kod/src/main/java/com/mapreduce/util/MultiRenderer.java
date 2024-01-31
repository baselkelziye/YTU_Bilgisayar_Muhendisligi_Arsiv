package com.mapreduce.util;

import java.awt.Component;

import javax.swing.Icon;
import javax.swing.JList;
import javax.swing.plaf.basic.BasicComboBoxRenderer;

@SuppressWarnings("all")
public class MultiRenderer extends BasicComboBoxRenderer {
	SelectionManager selectionManager;
  
	public MultiRenderer(SelectionManager sm) {
		selectionManager = sm;
	}
  
	public Component getListCellRendererComponent(JList list,
												  Object value,
												  int index,
												  boolean isSelected,
												  boolean cellHasFocus) {
		if (selectionManager.isSelected(value)) {
			setBackground(list.getSelectionBackground());
			setForeground(list.getSelectionForeground());
		} else {
			setBackground(list.getBackground());
			setForeground(list.getForeground());
		}
  
		setFont(list.getFont());
  
		if (value instanceof Icon) {
			setIcon((Icon)value);
		} else {
			setText((value == null) ? "" : value.toString());
		}
		return this;
	}
}
