package GUI;

import ahmetsefacetin.*;
import static ahmetsefacetin.Main.distributor;
import javax.swing.JOptionPane;

public class AddSubscriptionPanel extends javax.swing.JFrame {

    public AddSubscriptionPanel() {
        initComponents();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        btnAddSubscription = new javax.swing.JButton();
        tfSubscriptionId = new javax.swing.JTextField();
        tfJournalIssn = new javax.swing.JTextField();
        tfDiscountRatio = new javax.swing.JTextField();
        jLabel7 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        jLabel2.setFont(new java.awt.Font("Segoe UI", 0, 36)); // NOI18N
        jLabel2.setText("Add Subscription");

        jLabel3.setFont(new java.awt.Font("Segoe UI", 0, 24)); // NOI18N
        jLabel3.setText("Subscriber Id");

        jLabel4.setFont(new java.awt.Font("Segoe UI", 0, 24)); // NOI18N
        jLabel4.setText("Journal Issn");

        btnAddSubscription.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        btnAddSubscription.setText("Add Subscription");
        btnAddSubscription.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnAddSubscriptionActionPerformed(evt);
            }
        });

        tfSubscriptionId.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                tfSubscriptionIdActionPerformed(evt);
            }
        });

        tfDiscountRatio.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                tfDiscountRatioActionPerformed(evt);
            }
        });

        jLabel7.setFont(new java.awt.Font("Segoe UI", 0, 24)); // NOI18N
        jLabel7.setText("Discount Ratio");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addGroup(javax.swing.GroupLayout.Alignment.LEADING, layout.createSequentialGroup()
                        .addComponent(jLabel2)
                        .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel3)
                            .addComponent(jLabel4)
                            .addComponent(jLabel7))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 74, Short.MAX_VALUE)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(btnAddSubscription)
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                .addComponent(tfJournalIssn, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 394, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(tfSubscriptionId, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 394, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(tfDiscountRatio, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 394, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addGap(59, 59, 59))))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabel2)
                .addGap(19, 19, 19)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3)
                    .addComponent(tfSubscriptionId, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel4)
                    .addComponent(tfJournalIssn, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel7)
                    .addComponent(tfDiscountRatio, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 40, Short.MAX_VALUE)
                .addComponent(btnAddSubscription, javax.swing.GroupLayout.PREFERRED_SIZE, 36, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(32, 32, 32))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btnAddSubscriptionActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnAddSubscriptionActionPerformed
        String idString = tfSubscriptionId.getText();
        String issn = tfJournalIssn.getText();
        String discountRatioString = tfDiscountRatio.getText();

        if (idString.isEmpty() || issn.isEmpty() || discountRatioString.isEmpty()) {
            JOptionPane.showMessageDialog(null, "Please enter all fields!", "Try again", JOptionPane.ERROR_MESSAGE);
            return;
        }

        Integer id = Integer.parseInt(idString);
        Double discountRatio = Double.parseDouble(discountRatioString);

        PaymentInfo payment = new PaymentInfo(discountRatio);

        if (!distributor.addSubscription(issn, id, payment)) {
            JOptionPane.showMessageDialog(null, "Subscriber or Journal doesn't exist!", "Try again", JOptionPane.ERROR_MESSAGE);
        }
        distributor.saveState("distributorData.ser");
    }//GEN-LAST:event_btnAddSubscriptionActionPerformed

    private void tfSubscriptionIdActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_tfSubscriptionIdActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_tfSubscriptionIdActionPerformed

    private void tfDiscountRatioActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_tfDiscountRatioActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_tfDiscountRatioActionPerformed

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnAddSubscription;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JTextField tfDiscountRatio;
    private javax.swing.JTextField tfJournalIssn;
    private javax.swing.JTextField tfSubscriptionId;
    // End of variables declaration//GEN-END:variables
}
