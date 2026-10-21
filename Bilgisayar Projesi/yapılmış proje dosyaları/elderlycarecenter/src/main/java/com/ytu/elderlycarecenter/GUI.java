/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.ytu.elderlycarecenter;

import static java.lang.String.valueOf;
import java.sql.Date;
import java.sql.SQLException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.TableModel;

/**
 *
 * @author ohkam
 */
public class GUI extends javax.swing.JFrame {
    dbOP db;
    int selectedRoomId = -1;
    int selectedElderID = -1;
    int selectedVisitor1ID = -1;
    int selectedVisitor2ID = -1;
    int empty = 0;
    int visit_count = 0;
    int elder_age = 50;
    /**
     * Creates new form GUI
     * @throws java.sql.SQLException
     */
    public GUI() throws SQLException {
        this.db = new dbOP();
        initComponents();
        
        visitorsToTable(visit_count);
        roomsToTable(0);
        eldersToTable(elder_age);
        visitsToTable();
        eldersToTable2(0);
        visitorsToTable2();
        filterToTable(0);
    }
    
    public void roomsToTable(int empty) throws SQLException{
        DefaultTableModel model = (DefaultTableModel) table_rooms.getModel();
        model.setRowCount(0);
        Object rowData[] = new Object[3];
        ArrayList<Room> rooms = db.get_rooms(empty);

        for (int i = 0; i < rooms.size(); i++) {
            rowData[0] = rooms.get(i).getId();
            rowData[1] = rooms.get(i).getRoom_number();
            model.addRow(rowData);
        }
    }
    
    public void filterToTable(int count) throws SQLException{
        DefaultTableModel model = (DefaultTableModel) table_filter_visit.getModel();
        model.setRowCount(0);
        Object rowData[] = new Object[4];
        ArrayList<Filter> visits = db.filter_visit(count);

        for (int i = 0; i < visits.size(); i++) {
            rowData[0] = visits.get(i).getName();
            rowData[1] = visits.get(i).getSurname();
            rowData[2] = visits.get(i).getCount();
            model.addRow(rowData);
        }
    }
    
    public void eldersToTable(int value) throws SQLException{
        DefaultTableModel model = (DefaultTableModel) table_elders.getModel();
        model.setRowCount(0);
        Object rowData[] = new Object[7];
        ArrayList<Elder> elders = db.get_elders(value);

        for (int i = 0; i < elders.size(); i++) {
            rowData[0] = elders.get(i).getId();
            rowData[1] = elders.get(i).getFirst_name();
            rowData[2] = elders.get(i).getLast_name();
            rowData[3] = elders.get(i).getDate_of_birth();
            rowData[4] = elders.get(i).getGender();
            rowData[5] = elders.get(i).getVisit_count();
            rowData[6] = elders.get(i).getRoom().getRoom_number();
            
            model.addRow(rowData);
        }
    }
    
     public void eldersToTable2(int value) throws SQLException{
        DefaultTableModel model = (DefaultTableModel) table_visitElders.getModel();
        model.setRowCount(0);
        Object rowData[] = new Object[4];
        ArrayList<Elder> elders = db.get_elders(value);

        for (int i = 0; i < elders.size(); i++) {
            rowData[0] = elders.get(i).getId();
            rowData[1] = elders.get(i).getFirst_name();
            rowData[2] = elders.get(i).getLast_name();
            rowData[3] = elders.get(i).getVisit_count();
            
            model.addRow(rowData);
        }
    }
     
      public void visitorsToTable2() throws SQLException{
        DefaultTableModel model = (DefaultTableModel) table_visitVisitor1.getModel();
        model.setRowCount(0);
        Object rowData[] = new Object[4];
        
        DefaultTableModel model1 = (DefaultTableModel) table_visitVisitor2.getModel();
        model1.setRowCount(0);
        Object rowData1[] = new Object[4];
        
        ArrayList<Visitor> visitors = db.get_visitors(0);

        for (int i = 0; i < visitors.size(); i++) {
            rowData[0] = visitors.get(i).getId();
            rowData[1] = visitors.get(i).getFirst_name();
            rowData[2] = visitors.get(i).getLast_name();
            rowData[3] = visitors.get(i).getVisit_count();
            rowData1[0] = visitors.get(i).getId();
            rowData1[1] = visitors.get(i).getFirst_name();
            rowData1[2] = visitors.get(i).getLast_name();
            rowData1[3] = visitors.get(i).getVisit_count();
            model.addRow(rowData);
            model1.addRow(rowData1);
        }
    }
    
    public void visitsToTable() throws SQLException{
        DefaultTableModel model = (DefaultTableModel) table_visits.getModel();
        model.setRowCount(0);
        Object rowData[] = new Object[8];
        ArrayList<Visit> visits = db.get_visits();

        for (int i = 0; i < visits.size(); i++) {
            rowData[0] = visits.get(i).getVisit_id();
            rowData[1] = visits.get(i).getElder_first_name();
            rowData[2] = visits.get(i).getElder_last_name();
            rowData[3] = visits.get(i).getFirst_visitor_first_name();
            rowData[4] = visits.get(i).getFirst_visitor_last_name();
            if(visits.get(i).getSecond_visitor_first_name().equals("NULL")){
                rowData[5] = "";
                rowData[6] = "";
            } else {
                rowData[5] = visits.get(i).getSecond_visitor_first_name();
                rowData[6] = visits.get(i).getSecond_visitor_last_name();
            }
            rowData[7] = visits.get(i).getVisit_time();
            model.addRow(rowData);
        }
    }
    
    public void visitorsToTable(int value) throws SQLException{
        DefaultTableModel model = (DefaultTableModel) table_visitors.getModel();
        model.setRowCount(0);
        Object rowData[] = new Object[4];
        ArrayList<Visitor> visitors = db.get_visitors(value);
        int count = 0;
        for (int i = 0; i < visitors.size(); i++) {
            rowData[0] = visitors.get(i).getId();
            rowData[1] = visitors.get(i).getFirst_name();
            rowData[2] = visitors.get(i).getLast_name();
            rowData[3] = visitors.get(i).getVisit_count();
            
            model.addRow(rowData);
            count++;
        }
    }
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        tabbedPane = new javax.swing.JTabbedPane();
        jPanel1 = new javax.swing.JPanel();
        jScrollPane1 = new javax.swing.JScrollPane();
        table_rooms = new javax.swing.JTable();
        btn_addRoom = new javax.swing.JButton();
        btn_deleteRoom = new javax.swing.JButton();
        btn_emptyRooms = new javax.swing.JButton();
        jPanel2 = new javax.swing.JPanel();
        jScrollPane2 = new javax.swing.JScrollPane();
        table_elders = new javax.swing.JTable();
        txt_name = new javax.swing.JTextField();
        jLabel1 = new javax.swing.JLabel();
        txt_birthday = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        txt_surname = new javax.swing.JTextField();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        cb_gender = new javax.swing.JComboBox<>();
        btn_addElder = new javax.swing.JButton();
        btn_deleteElder = new javax.swing.JButton();
        btn_updateElder = new javax.swing.JButton();
        label_elder_age = new javax.swing.JLabel();
        slider_elder_age = new javax.swing.JSlider();
        jPanel3 = new javax.swing.JPanel();
        jScrollPane4 = new javax.swing.JScrollPane();
        table_visitors = new javax.swing.JTable();
        jLabel5 = new javax.swing.JLabel();
        txt_nameVisitor = new javax.swing.JTextField();
        txt_surnameVisitor = new javax.swing.JTextField();
        jLabel6 = new javax.swing.JLabel();
        btn_addVisitor = new javax.swing.JButton();
        btn_deleteVisitor = new javax.swing.JButton();
        btn_updateVisitor = new javax.swing.JButton();
        slider_visit_count = new javax.swing.JSlider();
        label_visitor_visit_count = new javax.swing.JLabel();
        jPanel4 = new javax.swing.JPanel();
        jScrollPane3 = new javax.swing.JScrollPane();
        table_visits = new javax.swing.JTable();
        jLabel7 = new javax.swing.JLabel();
        txt_searchElder = new javax.swing.JTextField();
        jPanel5 = new javax.swing.JPanel();
        jScrollPane5 = new javax.swing.JScrollPane();
        table_visitElders = new javax.swing.JTable();
        jLabel8 = new javax.swing.JLabel();
        jLabel9 = new javax.swing.JLabel();
        jScrollPane6 = new javax.swing.JScrollPane();
        table_visitVisitor1 = new javax.swing.JTable();
        jLabel10 = new javax.swing.JLabel();
        jScrollPane7 = new javax.swing.JScrollPane();
        table_visitVisitor2 = new javax.swing.JTable();
        jLabel11 = new javax.swing.JLabel();
        selected_elder_label = new javax.swing.JLabel();
        jLabel12 = new javax.swing.JLabel();
        selected_visitor_label2 = new javax.swing.JLabel();
        jLabel13 = new javax.swing.JLabel();
        selected_visitor_label1 = new javax.swing.JLabel();
        btn_newVisit = new javax.swing.JButton();
        jLabel14 = new javax.swing.JLabel();
        jPanel6 = new javax.swing.JPanel();
        jScrollPane8 = new javax.swing.JScrollPane();
        table_filter_visit = new javax.swing.JTable();
        jLabel15 = new javax.swing.JLabel();
        txt_visit_count = new javax.swing.JTextField();
        jButton1 = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setPreferredSize(new java.awt.Dimension(1000, 700));

        table_rooms.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null},
                {null, null},
                {null, null},
                {null, null}
            },
            new String [] {
                "Id", "Room Name"
            }
        ) {
            boolean[] canEdit = new boolean [] {
                false, false
            };

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        table_rooms.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                table_roomsMouseClicked(evt);
            }
        });
        jScrollPane1.setViewportView(table_rooms);
        if (table_rooms.getColumnModel().getColumnCount() > 0) {
            table_rooms.getColumnModel().getColumn(0).setResizable(false);
            table_rooms.getColumnModel().getColumn(1).setResizable(false);
        }

        btn_addRoom.setText("Add Room");
        btn_addRoom.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn_addRoomActionPerformed(evt);
            }
        });

        btn_deleteRoom.setText("Delete room");
        btn_deleteRoom.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn_deleteRoomActionPerformed(evt);
            }
        });

        btn_emptyRooms.setText("Boş Odaları Getir / Hepsini Göster");
        btn_emptyRooms.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn_emptyRoomsActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 906, Short.MAX_VALUE)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addComponent(btn_addRoom)
                        .addGap(199, 199, 199)
                        .addComponent(btn_emptyRooms)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(btn_deleteRoom)))
                .addContainerGap())
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 363, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(btn_addRoom)
                    .addComponent(btn_deleteRoom)
                    .addComponent(btn_emptyRooms))
                .addContainerGap(8, Short.MAX_VALUE))
        );

        tabbedPane.addTab("Rooms", jPanel1);

        table_elders.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null, null, null, null, null},
                {null, null, null, null, null, null, null},
                {null, null, null, null, null, null, null},
                {null, null, null, null, null, null, null}
            },
            new String [] {
                "id", "Name", "Surname", "Birthday", "Gender", "Visit Count", "Room Number"
            }
        ));
        table_elders.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                table_eldersMouseClicked(evt);
            }
        });
        jScrollPane2.setViewportView(table_elders);
        if (table_elders.getColumnModel().getColumnCount() > 0) {
            table_elders.getColumnModel().getColumn(0).setMaxWidth(20);
            table_elders.getColumnModel().getColumn(3).setHeaderValue("Birthday");
            table_elders.getColumnModel().getColumn(4).setHeaderValue("Gender");
            table_elders.getColumnModel().getColumn(6).setHeaderValue("Room Number");
        }

        jLabel1.setText("Name");

        jLabel2.setText("Birthday ( Format: YYYY-MM-DD)");

        jLabel3.setText("Surname");

        jLabel4.setText("Gender");

        cb_gender.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Male", "Female" }));

        btn_addElder.setText("Add");
        btn_addElder.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn_addElderActionPerformed(evt);
            }
        });

        btn_deleteElder.setText("Delete");
        btn_deleteElder.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn_deleteElderActionPerformed(evt);
            }
        });

        btn_updateElder.setText("Update");
        btn_updateElder.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn_updateElderActionPerformed(evt);
            }
        });

        label_elder_age.setForeground(new java.awt.Color(255, 0, 0));
        label_elder_age.setText("50");

        slider_elder_age.setPaintLabels(true);
        slider_elder_age.setPaintTicks(true);
        slider_elder_age.addChangeListener(new javax.swing.event.ChangeListener() {
            public void stateChanged(javax.swing.event.ChangeEvent evt) {
                slider_elder_ageStateChanged(evt);
            }
        });

        javax.swing.GroupLayout jPanel2Layout = new javax.swing.GroupLayout(jPanel2);
        jPanel2.setLayout(jPanel2Layout);
        jPanel2Layout.setHorizontalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane2, javax.swing.GroupLayout.DEFAULT_SIZE, 906, Short.MAX_VALUE)
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addComponent(jLabel1)
                                .addComponent(txt_name, javax.swing.GroupLayout.PREFERRED_SIZE, 192, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addComponent(jLabel2)
                            .addComponent(txt_birthday, javax.swing.GroupLayout.PREFERRED_SIZE, 192, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(92, 92, 92)
                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(jLabel4)
                            .addComponent(jLabel3)
                            .addComponent(txt_surname, javax.swing.GroupLayout.DEFAULT_SIZE, 192, Short.MAX_VALUE)
                            .addComponent(cb_gender, 0, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(slider_elder_age, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGroup(jPanel2Layout.createSequentialGroup()
                                .addGap(15, 15, 15)
                                .addComponent(label_elder_age)))
                        .addGap(55, 55, 55)
                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(btn_deleteElder, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(btn_updateElder, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, 123, Short.MAX_VALUE)
                            .addComponent(btn_addElder, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))))
                .addContainerGap())
        );
        jPanel2Layout.setVerticalGroup(
            jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel2Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 269, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel3)
                            .addComponent(btn_addElder))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btn_deleteElder)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btn_updateElder))
                    .addGroup(jPanel2Layout.createSequentialGroup()
                        .addComponent(jLabel1)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanel2Layout.createSequentialGroup()
                                .addGap(22, 22, 22)
                                .addComponent(slider_elder_age, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addComponent(label_elder_age)
                            .addGroup(jPanel2Layout.createSequentialGroup()
                                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                    .addComponent(txt_name, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(txt_surname, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(jPanel2Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(jPanel2Layout.createSequentialGroup()
                                        .addComponent(jLabel2)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                        .addComponent(txt_birthday, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                                    .addGroup(jPanel2Layout.createSequentialGroup()
                                        .addComponent(jLabel4)
                                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                        .addComponent(cb_gender, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))))))
                .addContainerGap(28, Short.MAX_VALUE))
        );

        tabbedPane.addTab("Elders", jPanel2);

        table_visitors.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null}
            },
            new String [] {
                "id", "First Name", "Surname", "Visit Count"
            }
        ));
        table_visitors.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                table_visitorsMouseClicked(evt);
            }
        });
        jScrollPane4.setViewportView(table_visitors);

        jLabel5.setText("Name");

        jLabel6.setText("Surname");

        btn_addVisitor.setText("Add");
        btn_addVisitor.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn_addVisitorActionPerformed(evt);
            }
        });

        btn_deleteVisitor.setText("Delete");
        btn_deleteVisitor.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn_deleteVisitorActionPerformed(evt);
            }
        });

        btn_updateVisitor.setText("Update");
        btn_updateVisitor.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn_updateVisitorActionPerformed(evt);
            }
        });

        slider_visit_count.setPaintLabels(true);
        slider_visit_count.setPaintTicks(true);
        slider_visit_count.setValue(0);
        slider_visit_count.addChangeListener(new javax.swing.event.ChangeListener() {
            public void stateChanged(javax.swing.event.ChangeEvent evt) {
                slider_visit_countStateChanged(evt);
            }
        });

        label_visitor_visit_count.setForeground(new java.awt.Color(255, 0, 0));
        label_visitor_visit_count.setText("0");

        javax.swing.GroupLayout jPanel3Layout = new javax.swing.GroupLayout(jPanel3);
        jPanel3.setLayout(jPanel3Layout);
        jPanel3Layout.setHorizontalGroup(
            jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel3Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane4)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel3Layout.createSequentialGroup()
                        .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel5)
                            .addComponent(txt_nameVisitor, javax.swing.GroupLayout.PREFERRED_SIZE, 192, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(92, 92, 92)
                        .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(jLabel6)
                            .addComponent(txt_surnameVisitor, javax.swing.GroupLayout.PREFERRED_SIZE, 192, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanel3Layout.createSequentialGroup()
                                .addGap(33, 33, 33)
                                .addComponent(slider_visit_count, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(jPanel3Layout.createSequentialGroup()
                                .addGap(48, 48, 48)
                                .addComponent(label_visitor_visit_count)))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 84, Short.MAX_VALUE)
                        .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(btn_deleteVisitor, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(btn_updateVisitor, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(btn_addVisitor, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 123, javax.swing.GroupLayout.PREFERRED_SIZE))))
                .addContainerGap())
        );
        jPanel3Layout.setVerticalGroup(
            jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel3Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jScrollPane4, javax.swing.GroupLayout.PREFERRED_SIZE, 318, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel3Layout.createSequentialGroup()
                        .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel6)
                            .addComponent(btn_addVisitor))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btn_deleteVisitor)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(btn_updateVisitor))
                    .addGroup(jPanel3Layout.createSequentialGroup()
                        .addComponent(jLabel5)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(slider_visit_count, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGroup(jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                .addComponent(txt_nameVisitor, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(txt_surnameVisitor, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))))
                    .addComponent(label_visitor_visit_count))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        tabbedPane.addTab("Visitors", jPanel3);

        table_visits.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null, null, null, null, null, null},
                {null, null, null, null, null, null, null, null},
                {null, null, null, null, null, null, null, null},
                {null, null, null, null, null, null, null, null}
            },
            new String [] {
                "Visit id", "Elder Name", "Elder Surname", "Visitior Name", "Visitor Surname", "Visitor Name", "Visitor Surname", "Visit Time"
            }
        ));
        jScrollPane3.setViewportView(table_visits);

        jLabel7.setText("Search Visit from elder or visitor");

        txt_searchElder.addInputMethodListener(new java.awt.event.InputMethodListener() {
            public void caretPositionChanged(java.awt.event.InputMethodEvent evt) {
            }
            public void inputMethodTextChanged(java.awt.event.InputMethodEvent evt) {
                txt_searchElderİnputMethodTextChanged(evt);
            }
        });
        txt_searchElder.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                txt_searchElderActionPerformed(evt);
            }
        });
        txt_searchElder.addKeyListener(new java.awt.event.KeyAdapter() {
            public void keyPressed(java.awt.event.KeyEvent evt) {
                txt_searchElderKeyPressed(evt);
            }
            public void keyReleased(java.awt.event.KeyEvent evt) {
                txt_searchElderKeyReleased(evt);
            }
        });

        javax.swing.GroupLayout jPanel4Layout = new javax.swing.GroupLayout(jPanel4);
        jPanel4.setLayout(jPanel4Layout);
        jPanel4Layout.setHorizontalGroup(
            jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel4Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane3, javax.swing.GroupLayout.DEFAULT_SIZE, 906, Short.MAX_VALUE)
                    .addGroup(jPanel4Layout.createSequentialGroup()
                        .addComponent(jLabel7)
                        .addGap(84, 84, 84)
                        .addComponent(txt_searchElder, javax.swing.GroupLayout.PREFERRED_SIZE, 199, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(0, 0, Short.MAX_VALUE)))
                .addContainerGap())
        );
        jPanel4Layout.setVerticalGroup(
            jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel4Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel4Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel7)
                    .addComponent(txt_searchElder, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(14, 14, 14)
                .addComponent(jScrollPane3, javax.swing.GroupLayout.PREFERRED_SIZE, 312, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(66, Short.MAX_VALUE))
        );

        tabbedPane.addTab("Visits", jPanel4);

        table_visitElders.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null}
            },
            new String [] {
                "id", "Name", "Surname", "Visit Count"
            }
        ));
        table_visitElders.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                table_visitEldersMouseClicked(evt);
            }
        });
        jScrollPane5.setViewportView(table_visitElders);
        if (table_visitElders.getColumnModel().getColumnCount() > 0) {
            table_visitElders.getColumnModel().getColumn(0).setMaxWidth(20);
        }

        jLabel8.setText("Elders");

        jLabel9.setText("Visitor 1");

        table_visitVisitor1.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null}
            },
            new String [] {
                "id", "Name", "Surname", "Visit Count"
            }
        ));
        table_visitVisitor1.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                table_visitVisitor1MouseClicked(evt);
            }
        });
        jScrollPane6.setViewportView(table_visitVisitor1);
        if (table_visitVisitor1.getColumnModel().getColumnCount() > 0) {
            table_visitVisitor1.getColumnModel().getColumn(0).setMaxWidth(20);
        }

        jLabel10.setText("Visitor 2");

        table_visitVisitor2.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null}
            },
            new String [] {
                "id", "Name", "Surname", "Visit Count"
            }
        ));
        table_visitVisitor2.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                table_visitVisitor2MouseClicked(evt);
            }
        });
        jScrollPane7.setViewportView(table_visitVisitor2);
        if (table_visitVisitor2.getColumnModel().getColumnCount() > 0) {
            table_visitVisitor2.getColumnModel().getColumn(0).setMaxWidth(20);
        }

        jLabel11.setText("Selected Elder:");

        selected_elder_label.setForeground(new java.awt.Color(204, 0, 0));
        selected_elder_label.setText("Not Selected");

        jLabel12.setText("Selected Visitor:");

        selected_visitor_label2.setForeground(new java.awt.Color(204, 0, 0));
        selected_visitor_label2.setText("Not Selected");

        jLabel13.setText("Selected Visitor:");

        selected_visitor_label1.setForeground(new java.awt.Color(204, 0, 0));
        selected_visitor_label1.setText("Not Selected");

        btn_newVisit.setText("Submit");
        btn_newVisit.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btn_newVisitActionPerformed(evt);
            }
        });

        jLabel14.setForeground(new java.awt.Color(255, 0, 0));
        jLabel14.setText("Visitor 1 must be selected.");

        javax.swing.GroupLayout jPanel5Layout = new javax.swing.GroupLayout(jPanel5);
        jPanel5.setLayout(jPanel5Layout);
        jPanel5Layout.setHorizontalGroup(
            jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel5Layout.createSequentialGroup()
                .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel5Layout.createSequentialGroup()
                        .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanel5Layout.createSequentialGroup()
                                .addContainerGap()
                                .addComponent(jScrollPane5, javax.swing.GroupLayout.PREFERRED_SIZE, 333, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(jPanel5Layout.createSequentialGroup()
                                .addGap(153, 153, 153)
                                .addComponent(jLabel8)))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jScrollPane6, javax.swing.GroupLayout.PREFERRED_SIZE, 333, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGroup(jPanel5Layout.createSequentialGroup()
                                .addGap(143, 143, 143)
                                .addComponent(jLabel9))))
                    .addGroup(jPanel5Layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(jLabel11)
                        .addGap(18, 18, 18)
                        .addComponent(selected_elder_label)
                        .addGap(95, 95, 95)
                        .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanel5Layout.createSequentialGroup()
                                .addGap(143, 143, 143)
                                .addComponent(jLabel10))
                            .addComponent(jScrollPane7, javax.swing.GroupLayout.PREFERRED_SIZE, 333, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGroup(jPanel5Layout.createSequentialGroup()
                                .addComponent(jLabel12)
                                .addGap(18, 18, 18)
                                .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addGroup(jPanel5Layout.createSequentialGroup()
                                        .addGap(10, 10, 10)
                                        .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                            .addGroup(jPanel5Layout.createSequentialGroup()
                                                .addGap(23, 23, 23)
                                                .addComponent(btn_newVisit))
                                            .addComponent(jLabel14)))
                                    .addComponent(selected_visitor_label2))))
                        .addGap(27, 27, 27)
                        .addComponent(jLabel13)
                        .addGap(18, 18, 18)
                        .addComponent(selected_visitor_label1)
                        .addGap(0, 65, Short.MAX_VALUE)))
                .addContainerGap())
        );
        jPanel5Layout.setVerticalGroup(
            jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel5Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel5Layout.createSequentialGroup()
                        .addComponent(jLabel8)
                        .addGap(3, 3, 3)
                        .addComponent(jScrollPane5, javax.swing.GroupLayout.PREFERRED_SIZE, 134, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel5Layout.createSequentialGroup()
                        .addComponent(jLabel9)
                        .addGap(3, 3, 3)
                        .addComponent(jScrollPane6, javax.swing.GroupLayout.PREFERRED_SIZE, 134, javax.swing.GroupLayout.PREFERRED_SIZE)))
                .addGap(18, 18, 18)
                .addComponent(jLabel10)
                .addGap(3, 3, 3)
                .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane7, javax.swing.GroupLayout.PREFERRED_SIZE, 134, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(jLabel11)
                        .addComponent(selected_elder_label))
                    .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(jLabel13)
                        .addComponent(selected_visitor_label1)))
                .addGap(18, 18, 18)
                .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel12)
                    .addComponent(selected_visitor_label2))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(btn_newVisit)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jLabel14)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        tabbedPane.addTab("New Visit", jPanel5);

        table_filter_visit.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null},
                {null, null, null},
                {null, null, null},
                {null, null, null}
            },
            new String [] {
                "Name", "Surname", "Count"
            }
        ));
        jScrollPane8.setViewportView(table_filter_visit);

        jLabel15.setText("Visit Count");

        txt_visit_count.setText("0");

        jButton1.setText("Search");
        jButton1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel6Layout = new javax.swing.GroupLayout(jPanel6);
        jPanel6.setLayout(jPanel6Layout);
        jPanel6Layout.setHorizontalGroup(
            jPanel6Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel6Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jScrollPane8, javax.swing.GroupLayout.PREFERRED_SIZE, 797, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(18, 18, 18)
                .addGroup(jPanel6Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(txt_visit_count)
                    .addGroup(jPanel6Layout.createSequentialGroup()
                        .addGroup(jPanel6Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel15)
                            .addComponent(jButton1))
                        .addGap(0, 6, Short.MAX_VALUE)))
                .addContainerGap())
        );
        jPanel6Layout.setVerticalGroup(
            jPanel6Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel6Layout.createSequentialGroup()
                .addGroup(jPanel6Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel6Layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(jScrollPane8, javax.swing.GroupLayout.PREFERRED_SIZE, 381, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(jPanel6Layout.createSequentialGroup()
                        .addGap(25, 25, 25)
                        .addComponent(jLabel15)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(txt_visit_count, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(18, 18, 18)
                        .addComponent(jButton1)))
                .addContainerGap(37, Short.MAX_VALUE))
        );

        tabbedPane.addTab("Filter by Visits", jPanel6);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(tabbedPane)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(tabbedPane, javax.swing.GroupLayout.PREFERRED_SIZE, 470, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 0, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btn_addRoomActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn_addRoomActionPerformed
        try {
            db.insert_room();
            JOptionPane.showMessageDialog(null, "Room Added.");
        } catch (SQLException ex) {
            Logger.getLogger(GUI.class.getName()).log(Level.SEVERE, null, ex);
        }
        try {
            roomsToTable(empty);
        } catch (SQLException ex) {
            Logger.getLogger(GUI.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_btn_addRoomActionPerformed

    private void table_roomsMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_table_roomsMouseClicked
        
    }//GEN-LAST:event_table_roomsMouseClicked

    private void btn_deleteRoomActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn_deleteRoomActionPerformed
        int index = table_rooms.getSelectedRow();
        TableModel model = table_rooms.getModel();
        int id = Integer.parseInt(model.getValueAt(index,0).toString());
        System.out.println(model.getValueAt(index,0).toString());
        try {
            db.delete_room(id);
            JOptionPane.showMessageDialog(null, "Room Deleted.");
        } catch (SQLException ex) {
            Logger.getLogger(GUI.class.getName()).log(Level.SEVERE, null, ex);
        }
        try {
            roomsToTable(empty);
        } catch (SQLException ex) {
            Logger.getLogger(GUI.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_btn_deleteRoomActionPerformed
    private void clearTexts(){
        txt_name.setText("");
        txt_surname.setText("");
        txt_nameVisitor.setText("");
        txt_surnameVisitor.setText("");
        txt_birthday.setText("");
        cb_gender.setSelectedIndex(0);
    }
    
    private void btn_addElderActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn_addElderActionPerformed
        String first_name = txt_name.getText();
        String last_name = txt_surname.getText();
        String date_of_birthdayS = txt_birthday.getText();
        Date date_of_birthday=Date.valueOf(date_of_birthdayS);
        
        String gender = String.valueOf(cb_gender.getSelectedItem());
        try {
            db.insert_elder(first_name, last_name, date_of_birthday, gender);
            eldersToTable(elder_age);
            clearTexts();
            JOptionPane.showMessageDialog(null, "Elder Added.");
            JOptionPane.showMessageDialog(null, "Trigger Activated! Automaticly assigned a room");
        } catch (SQLException ex) {
            Logger.getLogger(GUI.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_btn_addElderActionPerformed

    private void btn_deleteElderActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn_deleteElderActionPerformed
        int index = table_elders.getSelectedRow();
        TableModel model = table_elders.getModel();
        int id = Integer.parseInt(model.getValueAt(index,0).toString());
        try {
            db.delete_elder(id);
            JOptionPane.showMessageDialog(null, "Elder deleted.");
            JOptionPane.showMessageDialog(null, "Trigger Activated! The room is marked as empty ");
        } catch (SQLException ex) {
            Logger.getLogger(GUI.class.getName()).log(Level.SEVERE, null, ex);
        }
        try {
            eldersToTable(elder_age);
        } catch (SQLException ex) {
            Logger.getLogger(GUI.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_btn_deleteElderActionPerformed

    private void btn_updateElderActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn_updateElderActionPerformed
        int index = table_elders.getSelectedRow();
        TableModel model = table_elders.getModel();
        int id = Integer.parseInt(model.getValueAt(index,0).toString());
           
        String first_name = txt_name.getText();
        String last_name = txt_surname.getText();
        String date_of_birthdayS = txt_birthday.getText();
        Date date_of_birthday=Date.valueOf(date_of_birthdayS);
        
        String gender = String.valueOf(cb_gender.getSelectedItem());
        try {
            db.update_elder(id,first_name, last_name, date_of_birthday, gender);
            eldersToTable(elder_age);
            clearTexts();
            JOptionPane.showMessageDialog(null, "Elder updated.");
        } catch (SQLException ex) {
            Logger.getLogger(GUI.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        try {
            eldersToTable(elder_age);
        } catch (SQLException ex) {
            Logger.getLogger(GUI.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_btn_updateElderActionPerformed

    private void table_eldersMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_table_eldersMouseClicked
         int index = table_elders.getSelectedRow();
        TableModel model = table_elders.getModel();
        int id = Integer.parseInt(model.getValueAt(index,0).toString());
        txt_name.setText(model.getValueAt(index, 1).toString());
        txt_surname.setText(model.getValueAt(index, 2).toString());
        txt_birthday.setText(model.getValueAt(index, 3).toString());
        if(model.getValueAt(index, 4).toString().equals("Male")){
            cb_gender.setSelectedIndex(0);
        } else {
            cb_gender.setSelectedIndex(1);
        }
    }//GEN-LAST:event_table_eldersMouseClicked

    private void btn_addVisitorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn_addVisitorActionPerformed
        String first_name = txt_nameVisitor.getText();
        String last_name = txt_surnameVisitor.getText();
        
        try {
            db.insert_visitor(first_name, last_name);
            eldersToTable(elder_age);
            clearTexts();
            JOptionPane.showMessageDialog(null, "Visitor Added");
        } catch (SQLException ex) {
            Logger.getLogger(GUI.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_btn_addVisitorActionPerformed

    private void btn_deleteVisitorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn_deleteVisitorActionPerformed
        int index = table_visitors.getSelectedRow();
        TableModel model = table_visitors.getModel();
        int id = Integer.parseInt(model.getValueAt(index,0).toString());
        try {
            db.delete_visitor(id);
            JOptionPane.showMessageDialog(null, "Visitor Deleted");
        } catch (SQLException ex) {
            Logger.getLogger(GUI.class.getName()).log(Level.SEVERE, null, ex);
        }
        try {
            visitorsToTable(visit_count);
        } catch (SQLException ex) {
            Logger.getLogger(GUI.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_btn_deleteVisitorActionPerformed

    private void btn_updateVisitorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn_updateVisitorActionPerformed
        int index = table_visitors.getSelectedRow();
        TableModel model = table_visitors.getModel();
        int id = Integer.parseInt(model.getValueAt(index,0).toString());
           
        String first_name = txt_nameVisitor.getText();
        String last_name = txt_surnameVisitor.getText();
       
        try {
            db.update_visitor(id,first_name, last_name);
            visitorsToTable(visit_count);
            clearTexts();
            JOptionPane.showMessageDialog(null, "Visitor Updated");
        } catch (SQLException ex) {
            Logger.getLogger(GUI.class.getName()).log(Level.SEVERE, null, ex);
        }
        
       
    }//GEN-LAST:event_btn_updateVisitorActionPerformed

    private void table_visitorsMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_table_visitorsMouseClicked
        int index = table_visitors.getSelectedRow();
        TableModel model = table_visitors.getModel();
        txt_nameVisitor.setText(model.getValueAt(index, 1).toString());
        txt_surnameVisitor.setText(model.getValueAt(index, 2).toString());
    }//GEN-LAST:event_table_visitorsMouseClicked

    private void txt_searchElderİnputMethodTextChanged(java.awt.event.InputMethodEvent evt) {//GEN-FIRST:event_txt_searchElderİnputMethodTextChanged
        
    }//GEN-LAST:event_txt_searchElderİnputMethodTextChanged

    private void txt_searchElderActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_txt_searchElderActionPerformed
        
    }//GEN-LAST:event_txt_searchElderActionPerformed

    private void txt_searchElderKeyPressed(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_txt_searchElderKeyPressed
        
    }//GEN-LAST:event_txt_searchElderKeyPressed
    
    public void visitsToTable(String searchQuery) throws SQLException{
        DefaultTableModel model = (DefaultTableModel) table_visits.getModel();
        model.setRowCount(0);
        Object rowData[] = new Object[8];
        ArrayList<Visit> visits = db.search_visits(searchQuery);

        for (int i = 0; i < visits.size(); i++) {
            rowData[0] = visits.get(i).getVisit_id();
            rowData[1] = visits.get(i).getElder_first_name();
            rowData[2] = visits.get(i).getElder_last_name();
            rowData[3] = visits.get(i).getFirst_visitor_first_name();
            rowData[4] = visits.get(i).getFirst_visitor_last_name();
            if(visits.get(i).getSecond_visitor_first_name().equals("NULL")){
                rowData[5] = "";
                rowData[6] = "";
            } else {
                rowData[5] = visits.get(i).getSecond_visitor_first_name();
                rowData[6] = visits.get(i).getSecond_visitor_last_name();
            }
            rowData[7] = visits.get(i).getVisit_time();
            model.addRow(rowData);
        }
    }
    private void txt_searchElderKeyReleased(java.awt.event.KeyEvent evt) {//GEN-FIRST:event_txt_searchElderKeyReleased
        System.out.println(txt_searchElder.getText());
        try {
            visitsToTable(txt_searchElder.getText());
        } catch (SQLException ex) {
            Logger.getLogger(GUI.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_txt_searchElderKeyReleased

    private void table_visitEldersMouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_table_visitEldersMouseClicked
        int index = table_visitElders.getSelectedRow();
        TableModel model = table_visitElders.getModel();
        selected_elder_label.setText(model.getValueAt(index, 1).toString() + " " +model.getValueAt(index, 2).toString() );
        selectedElderID = Integer.parseInt(model.getValueAt(index, 0).toString());
    }//GEN-LAST:event_table_visitEldersMouseClicked

    private void table_visitVisitor1MouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_table_visitVisitor1MouseClicked
        int index = table_visitVisitor1.getSelectedRow();
        TableModel model = table_visitVisitor1.getModel();
        selected_visitor_label1.setText(model.getValueAt(index, 1).toString() + " " +model.getValueAt(index, 2).toString() );
        selectedVisitor1ID = Integer.parseInt(model.getValueAt(index, 0).toString());
    }//GEN-LAST:event_table_visitVisitor1MouseClicked

    private void table_visitVisitor2MouseClicked(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_table_visitVisitor2MouseClicked
        int index = table_visitVisitor2.getSelectedRow();
        TableModel model = table_visitVisitor2.getModel();
        selected_visitor_label2.setText(model.getValueAt(index, 1).toString() + " " +model.getValueAt(index, 2).toString() );
        selectedVisitor2ID = Integer.parseInt(model.getValueAt(index, 0).toString());
    }//GEN-LAST:event_table_visitVisitor2MouseClicked

    private void btn_newVisitActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn_newVisitActionPerformed
        try {
            db.insert_visit(selectedElderID, selectedVisitor1ID, selectedVisitor2ID);
            eldersToTable2(0);
            visitorsToTable2();
            JOptionPane.showMessageDialog(null, "New Visit Created.");
            JOptionPane.showMessageDialog(null, "Trigger Activated. Visit counts updated!");
        } catch (SQLException ex) {
            Logger.getLogger(GUI.class.getName()).log(Level.SEVERE, null, ex);
            JOptionPane.showMessageDialog(null, ex);
        }
    }//GEN-LAST:event_btn_newVisitActionPerformed

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        int count = Integer.parseInt(txt_visit_count.getText());
        try {
            filterToTable(count);
        } catch (SQLException ex) {
            Logger.getLogger(GUI.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_jButton1ActionPerformed

    private void btn_emptyRoomsActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btn_emptyRoomsActionPerformed
        try {
            empty++;
            if(empty == 2){
                empty = 0;
            }
            roomsToTable(empty);
        } catch (SQLException ex) {
            Logger.getLogger(GUI.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_btn_emptyRoomsActionPerformed

    private void slider_visit_countStateChanged(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_slider_visit_countStateChanged
        visit_count = slider_visit_count.getValue();
        label_visitor_visit_count.setText(valueOf(visit_count));
        try {
            visitorsToTable(visit_count);
        } catch (SQLException ex) {
            Logger.getLogger(GUI.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_slider_visit_countStateChanged

    private void slider_elder_ageStateChanged(javax.swing.event.ChangeEvent evt) {//GEN-FIRST:event_slider_elder_ageStateChanged
        elder_age = slider_elder_age.getValue();
        label_elder_age.setText(valueOf(elder_age));
        try {
            eldersToTable(elder_age);
        } catch (SQLException ex) {
            Logger.getLogger(GUI.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_slider_elder_ageStateChanged

    
    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(GUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(GUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(GUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(GUI.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                try {
                    new GUI().setVisible(true);
                } catch (SQLException ex) {
                    Logger.getLogger(GUI.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btn_addElder;
    private javax.swing.JButton btn_addRoom;
    private javax.swing.JButton btn_addVisitor;
    private javax.swing.JButton btn_deleteElder;
    private javax.swing.JButton btn_deleteRoom;
    private javax.swing.JButton btn_deleteVisitor;
    private javax.swing.JButton btn_emptyRooms;
    private javax.swing.JButton btn_newVisit;
    private javax.swing.JButton btn_updateElder;
    private javax.swing.JButton btn_updateVisitor;
    private javax.swing.JComboBox<String> cb_gender;
    private javax.swing.JButton jButton1;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel11;
    private javax.swing.JLabel jLabel12;
    private javax.swing.JLabel jLabel13;
    private javax.swing.JLabel jLabel14;
    private javax.swing.JLabel jLabel15;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel2;
    private javax.swing.JPanel jPanel3;
    private javax.swing.JPanel jPanel4;
    private javax.swing.JPanel jPanel5;
    private javax.swing.JPanel jPanel6;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JScrollPane jScrollPane3;
    private javax.swing.JScrollPane jScrollPane4;
    private javax.swing.JScrollPane jScrollPane5;
    private javax.swing.JScrollPane jScrollPane6;
    private javax.swing.JScrollPane jScrollPane7;
    private javax.swing.JScrollPane jScrollPane8;
    private javax.swing.JLabel label_elder_age;
    private javax.swing.JLabel label_visitor_visit_count;
    private javax.swing.JLabel selected_elder_label;
    private javax.swing.JLabel selected_visitor_label1;
    private javax.swing.JLabel selected_visitor_label2;
    private javax.swing.JSlider slider_elder_age;
    private javax.swing.JSlider slider_visit_count;
    private javax.swing.JTabbedPane tabbedPane;
    private javax.swing.JTable table_elders;
    private javax.swing.JTable table_filter_visit;
    private javax.swing.JTable table_rooms;
    private javax.swing.JTable table_visitElders;
    private javax.swing.JTable table_visitVisitor1;
    private javax.swing.JTable table_visitVisitor2;
    private javax.swing.JTable table_visitors;
    private javax.swing.JTable table_visits;
    private javax.swing.JTextField txt_birthday;
    private javax.swing.JTextField txt_name;
    private javax.swing.JTextField txt_nameVisitor;
    private javax.swing.JTextField txt_searchElder;
    private javax.swing.JTextField txt_surname;
    private javax.swing.JTextField txt_surnameVisitor;
    private javax.swing.JTextField txt_visit_count;
    // End of variables declaration//GEN-END:variables
}
