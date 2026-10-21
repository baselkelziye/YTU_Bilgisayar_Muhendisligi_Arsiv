package GUI;

import Entities.Finance;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.Date;

public class FinanceList {
    private JFrame frame;
    private JPanel mainFinanceListPanel;
    private JPanel filterPanel;
    private JPanel listPanel;
    private JTable listTable;
    private JButton filterButton;
    private JComboBox<String> monthComboBox;

    private String[] months = {"Filtre Yok",
            "Ocak", "Şubat", "Mart", "Nisan", "Mayıs", "Haziran",
            "Temmuz", "Ağustos", "Eylül", "Ekim", "Kasım", "Aralık"
    };

    public FinanceList() {
        frame = new JFrame("Finance List");
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setSize(900, 700);
        mainFinanceListPanel = new JPanel();
        frame.setContentPane(mainFinanceListPanel);
        doFilter();
        createList("Filtre Yok");
        frame.setVisible(true);



    }

    public void createList(String filtered) {

        String financeColumns[] = {"TARİH", "AÇIKLAMA", "DEĞER"};
        DefaultTableModel financeModel = new DefaultTableModel(financeColumns, 0);
        listTable = new JTable(financeModel) {
            @Override
            public boolean isCellEditable(int row, int column) {
                return false;
            }
        };
        JScrollPane financeScrollPane = new JScrollPane(listTable);


        listPanel = new JPanel();
        listPanel.setLayout(new BorderLayout());
        listPanel.add(financeScrollPane, BorderLayout.CENTER);

        for (Entities.Finance list : Finance.setList()) {

            if (filtered.equals("Filtre Yok")) {
                Object[] financeRow = {list.getReleaseDate(), list.getDefinition(), list.getCost()};
                financeModel.addRow(financeRow);
            }
            else {
                    Object[] temp = list.getObjects();
                    Date temp_date = list.getReleaseDate();
                    int currentMonth = temp_date.getMonth() + 1;
                    if(filtered == months[currentMonth])
                        financeModel.addRow(temp);
                }
            }

        mainFinanceListPanel.add(listPanel, BorderLayout.CENTER);
        mainFinanceListPanel.revalidate();
        mainFinanceListPanel.repaint();
    }

    public void doFilter() {
        filterPanel = new JPanel();
        monthComboBox = new JComboBox<>(months);
        filterButton = new JButton("Filtrele");
        filterPanel.add(monthComboBox);
        filterPanel.add(filterButton);
        mainFinanceListPanel.setLayout(new BorderLayout());
        mainFinanceListPanel.add(filterPanel, BorderLayout.NORTH);

        if(!filterButton.isEnabled()) createList("");

        filterButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String selectedMonth = (String) monthComboBox.getSelectedItem();
                mainFinanceListPanel.remove(listPanel);
                createList(selectedMonth);
            }
        });
    }
}
