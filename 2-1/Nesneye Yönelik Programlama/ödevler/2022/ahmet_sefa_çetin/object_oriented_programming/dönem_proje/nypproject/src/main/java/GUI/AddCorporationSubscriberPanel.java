package GUI;

import ahmetsefacetin.*;
import static ahmetsefacetin.Main.distributor;
import javax.swing.JOptionPane;

public class AddCorporationSubscriberPanel extends javax.swing.JFrame {

    public AddCorporationSubscriberPanel() {
        initComponents();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        btnAddSubscriber = new javax.swing.JButton();
        tfName = new javax.swing.JTextField();
        tfAdress = new javax.swing.JTextField();
        tfBankCode = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        tfBankName = new javax.swing.JTextField();
        tfIssueDay = new javax.swing.JTextField();
        jLabel3 = new javax.swing.JLabel();
        tfIssudeMonth = new javax.swing.JTextField();
        jLabel4 = new javax.swing.JLabel();
        tfIssueYear = new javax.swing.JTextField();
        jLabel9 = new javax.swing.JLabel();
        tfAccountNumber = new javax.swing.JTextField();
        jLabel10 = new javax.swing.JLabel();
        tfBalance = new javax.swing.JTextField();
        jLabel11 = new javax.swing.JLabel();
        jLabel12 = new javax.swing.JLabel();
        tfId = new javax.swing.JTextField();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabel5.setFont(new java.awt.Font("Segoe UI", 0, 24)); // NOI18N
        jLabel5.setText("Bank Code");

        jLabel6.setFont(new java.awt.Font("Segoe UI", 0, 24)); // NOI18N
        jLabel6.setText("Bank Name");

        jLabel7.setFont(new java.awt.Font("Segoe UI", 0, 24)); // NOI18N
        jLabel7.setText("Issue Day");

        jLabel8.setFont(new java.awt.Font("Segoe UI", 0, 24)); // NOI18N
        jLabel8.setText("Issue Year");

        btnAddSubscriber.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        btnAddSubscriber.setText("Add Subscriber");
        btnAddSubscriber.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnAddSubscriberActionPerformed(evt);
            }
        });

        tfName.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                tfNameActionPerformed(evt);
            }
        });

        jLabel2.setFont(new java.awt.Font("Segoe UI", 0, 36)); // NOI18N
        jLabel2.setText("New Corporation Subscriber Panel");

        tfBankName.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                tfBankNameActionPerformed(evt);
            }
        });

        tfIssueDay.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                tfIssueDayActionPerformed(evt);
            }
        });

        jLabel3.setFont(new java.awt.Font("Segoe UI", 0, 24)); // NOI18N
        jLabel3.setText("Name");

        jLabel4.setFont(new java.awt.Font("Segoe UI", 0, 24)); // NOI18N
        jLabel4.setText("Adress");

        jLabel9.setFont(new java.awt.Font("Segoe UI", 0, 24)); // NOI18N
        jLabel9.setText("Issue Month");

        jLabel10.setFont(new java.awt.Font("Segoe UI", 0, 24)); // NOI18N
        jLabel10.setText("Account Number");

        jLabel11.setFont(new java.awt.Font("Segoe UI", 0, 24)); // NOI18N
        jLabel11.setText("Id");

        jLabel12.setFont(new java.awt.Font("Segoe UI", 0, 24)); // NOI18N
        jLabel12.setText("Balance");

        tfId.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                tfIdActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel2)
                    .addComponent(jLabel11, javax.swing.GroupLayout.PREFERRED_SIZE, 182, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel3)
                            .addComponent(jLabel4)
                            .addComponent(jLabel5)
                            .addComponent(jLabel6)
                            .addComponent(jLabel7)
                            .addComponent(jLabel9)
                            .addComponent(jLabel8)
                            .addComponent(jLabel10)
                            .addComponent(jLabel12, javax.swing.GroupLayout.PREFERRED_SIZE, 182, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGap(80, 80, 80)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(tfBalance, javax.swing.GroupLayout.PREFERRED_SIZE, 394, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(btnAddSubscriber, javax.swing.GroupLayout.PREFERRED_SIZE, 130, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                                .addComponent(tfId, javax.swing.GroupLayout.PREFERRED_SIZE, 394, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                    .addComponent(tfAdress)
                                    .addComponent(tfName)
                                    .addComponent(tfBankCode)
                                    .addComponent(tfBankName)
                                    .addComponent(tfIssueDay)
                                    .addComponent(tfIssudeMonth)
                                    .addComponent(tfIssueYear)
                                    .addComponent(tfAccountNumber, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 394, javax.swing.GroupLayout.PREFERRED_SIZE))))))
                .addContainerGap(34, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel2)
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel11)
                    .addComponent(tfId, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3)
                    .addComponent(tfName, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel4)
                    .addComponent(tfAdress, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel12)
                    .addComponent(tfBalance, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel5)
                    .addComponent(tfBankCode, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel6)
                    .addComponent(tfBankName, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel7)
                    .addComponent(tfIssueDay, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(tfIssudeMonth, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel9))
                .addGap(17, 17, 17)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(tfIssueYear, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel8))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel10)
                    .addComponent(tfAccountNumber, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(39, 39, 39)
                .addComponent(btnAddSubscriber, javax.swing.GroupLayout.PREFERRED_SIZE, 36, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(18, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btnAddSubscriberActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnAddSubscriberActionPerformed
        String idString = tfId.getText();
        String name = tfName.getText();
        String adress = tfAdress.getText();
        String balanceString = tfBalance.getText();
        String bankCodeString = tfBankCode.getText();
        String bankName = tfBankName.getText();
        String issueDayString = tfIssueDay.getText();
        String issueMonthString = tfIssudeMonth.getText();
        String issueYearString = tfIssueYear.getText();
        String accountNumberString = tfAccountNumber.getText();

        if (idString.isEmpty() || name.isEmpty() || adress.isEmpty() || balanceString.isEmpty() || bankCodeString.isEmpty() || bankName.isEmpty() || issueDayString.isEmpty() || issueMonthString.isEmpty() || issueYearString.isEmpty() || accountNumberString.isEmpty()) {
            JOptionPane.showMessageDialog(null, "Please enter all fields!", "Try again", JOptionPane.ERROR_MESSAGE);
            return;
        }

        Integer id = Integer.parseInt(idString);
        Double balance = Double.parseDouble(balanceString);
        Integer bankCode = Integer.parseInt(bankCodeString);
        Integer issueDay = Integer.parseInt(issueDayString);
        Integer issueMonth = Integer.parseInt(issueMonthString);
        Integer issueYear = Integer.parseInt(issueYearString);
        Integer accountNumber = Integer.parseInt(accountNumberString);

        Subscriber subscriber = new Corporation(id, name, adress, balance, bankCode, bankName, issueDay, issueMonth, issueYear, accountNumber);

        if (!distributor.addSubscriber(subscriber)) {
            JOptionPane.showMessageDialog(null, "There is a subscriber with the same ID!", "Try again", JOptionPane.ERROR_MESSAGE);
            Subscriber.setCounter(Subscriber.getCounter() - 1);
            return;
        }

        System.out.println("Subscriber is added successfully");
        System.out.println(subscriber + "\n");

        JOptionPane.showMessageDialog(null, subscriber, "Subscriber is added successfully", JOptionPane.INFORMATION_MESSAGE);
        distributor.saveState("distributorData.ser");
    }//GEN-LAST:event_btnAddSubscriberActionPerformed

    private void tfNameActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_tfNameActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_tfNameActionPerformed

    private void tfBankNameActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_tfBankNameActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_tfBankNameActionPerformed

    private void tfIssueDayActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_tfIssueDayActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_tfIssueDayActionPerformed

    private void tfIdActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_tfIdActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_tfIdActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnAddSubscriber;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel11;
    private javax.swing.JLabel jLabel12;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JTextField tfAccountNumber;
    private javax.swing.JTextField tfAdress;
    private javax.swing.JTextField tfBalance;
    private javax.swing.JTextField tfBankCode;
    private javax.swing.JTextField tfBankName;
    private javax.swing.JTextField tfId;
    private javax.swing.JTextField tfIssudeMonth;
    private javax.swing.JTextField tfIssueDay;
    private javax.swing.JTextField tfIssueYear;
    private javax.swing.JTextField tfName;
    // End of variables declaration//GEN-END:variables
}
