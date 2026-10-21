package GUI;

import ahmetsefacetin.*;
import static ahmetsefacetin.Main.distributor;
import javax.swing.JFrame;
import javax.swing.JOptionPane;

public class StartPanel extends javax.swing.JFrame {

    public StartPanel() {
        initComponents();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        btnAddIndividualSubscriber = new javax.swing.JButton();
        btnAddCorporaitonSubscriber = new javax.swing.JButton();
        btnListSubscribers = new javax.swing.JButton();
        btnAddJournal = new javax.swing.JButton();
        btnListJournals = new javax.swing.JButton();
        btnAddSubscribtion = new javax.swing.JButton();
        btnListSubscriptionsByJournal = new javax.swing.JButton();
        btnListSubscriptionsBySubscriber = new javax.swing.JButton();
        tfSubscriberId = new javax.swing.JTextField();
        tfJournalIssn = new javax.swing.JTextField();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();
        tfIssn = new javax.swing.JTextField();
        btnListSendingOrders = new javax.swing.JButton();
        tfYear1 = new javax.swing.JTextField();
        tfMonth1 = new javax.swing.JTextField();
        tfYear2 = new javax.swing.JTextField();
        tfMonth2 = new javax.swing.JTextField();
        jLabel7 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        btnAllListSendingOrders = new javax.swing.JButton();
        jSeparator1 = new javax.swing.JSeparator();
        jSeparator2 = new javax.swing.JSeparator();
        jSeparator4 = new javax.swing.JSeparator();
        btnListIncompletePayments = new javax.swing.JButton();
        jSeparator5 = new javax.swing.JSeparator();
        btnReportPanel = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        btnAddIndividualSubscriber.setFont(new java.awt.Font("Segoe UI", 0, 18)); // NOI18N
        btnAddIndividualSubscriber.setText("Add New Individual Subscriber");
        btnAddIndividualSubscriber.setCursor(new java.awt.Cursor(java.awt.Cursor.DEFAULT_CURSOR));
        btnAddIndividualSubscriber.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnAddIndividualSubscriberActionPerformed(evt);
            }
        });

        btnAddCorporaitonSubscriber.setFont(new java.awt.Font("Segoe UI", 0, 18)); // NOI18N
        btnAddCorporaitonSubscriber.setText("Add New Corporation Subscriber");
        btnAddCorporaitonSubscriber.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnAddCorporaitonSubscriberActionPerformed(evt);
            }
        });

        btnListSubscribers.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        btnListSubscribers.setText("List Subscribers");
        btnListSubscribers.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnListSubscribersActionPerformed(evt);
            }
        });

        btnAddJournal.setFont(new java.awt.Font("Segoe UI", 0, 18)); // NOI18N
        btnAddJournal.setText("Add New Journal");
        btnAddJournal.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnAddJournalActionPerformed(evt);
            }
        });

        btnListJournals.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        btnListJournals.setText("List Journals");
        btnListJournals.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnListJournalsActionPerformed(evt);
            }
        });

        btnAddSubscribtion.setFont(new java.awt.Font("Segoe UI", 0, 18)); // NOI18N
        btnAddSubscribtion.setText("Add New Subscription");
        btnAddSubscribtion.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnAddSubscribtionActionPerformed(evt);
            }
        });

        btnListSubscriptionsByJournal.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        btnListSubscriptionsByJournal.setText("List Subscriptions for a Journal");
        btnListSubscriptionsByJournal.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnListSubscriptionsByJournalActionPerformed(evt);
            }
        });

        btnListSubscriptionsBySubscriber.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        btnListSubscriptionsBySubscriber.setText("List Subscriptions for a Subscriber");
        btnListSubscriptionsBySubscriber.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnListSubscriptionsBySubscriberActionPerformed(evt);
            }
        });

        tfSubscriberId.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        tfSubscriberId.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                tfSubscriberIdActionPerformed(evt);
            }
        });

        tfJournalIssn.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N

        jLabel1.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        jLabel1.setText("Subscriber ID");

        jLabel2.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        jLabel2.setText("Journal ISSN");

        jLabel4.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        jLabel4.setText("ISSN");

        jLabel5.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        jLabel5.setText("Month");

        jLabel6.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        jLabel6.setText("Year");

        tfIssn.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        tfIssn.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                tfIssnActionPerformed(evt);
            }
        });

        btnListSendingOrders.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        btnListSendingOrders.setText("List Sending Orders");
        btnListSendingOrders.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnListSendingOrdersActionPerformed(evt);
            }
        });

        tfYear1.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        tfYear1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                tfYear1ActionPerformed(evt);
            }
        });

        tfMonth1.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        tfMonth1.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                tfMonth1ActionPerformed(evt);
            }
        });

        tfYear2.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        tfYear2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                tfYear2ActionPerformed(evt);
            }
        });

        tfMonth2.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        tfMonth2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                tfMonth2ActionPerformed(evt);
            }
        });

        jLabel7.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        jLabel7.setText("Month");

        jLabel8.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        jLabel8.setText("Year");

        btnAllListSendingOrders.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        btnAllListSendingOrders.setText("List All Sending Orders");
        btnAllListSendingOrders.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnAllListSendingOrdersActionPerformed(evt);
            }
        });

        jSeparator4.setOrientation(javax.swing.SwingConstants.VERTICAL);

        btnListIncompletePayments.setFont(new java.awt.Font("Segoe UI", 0, 14)); // NOI18N
        btnListIncompletePayments.setText("List Incomplete Payments");
        btnListIncompletePayments.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnListIncompletePaymentsActionPerformed(evt);
            }
        });

        jSeparator5.setOrientation(javax.swing.SwingConstants.VERTICAL);

        btnReportPanel.setFont(new java.awt.Font("Segoe UI", 0, 18)); // NOI18N
        btnReportPanel.setText("Report Panel");
        btnReportPanel.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                btnReportPanelActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jSeparator1)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                    .addComponent(btnListSubscribers, javax.swing.GroupLayout.PREFERRED_SIZE, 130, Short.MAX_VALUE)
                                    .addComponent(btnListJournals, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                                .addGap(64, 64, 64))
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                    .addComponent(jLabel4)
                                    .addComponent(jLabel5)
                                    .addComponent(jLabel6)
                                    .addComponent(btnListSendingOrders, javax.swing.GroupLayout.DEFAULT_SIZE, 169, Short.MAX_VALUE)
                                    .addComponent(tfYear1)
                                    .addComponent(tfMonth1)
                                    .addComponent(tfIssn))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addComponent(jSeparator5, javax.swing.GroupLayout.PREFERRED_SIZE, 11, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(18, 18, 18)))
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jLabel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                    .addComponent(btnListSubscriptionsBySubscriber, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                    .addComponent(tfSubscriberId))
                                .addGap(18, 18, 18)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                                    .addComponent(tfJournalIssn)
                                    .addComponent(btnListSubscriptionsByJournal, javax.swing.GroupLayout.DEFAULT_SIZE, 247, Short.MAX_VALUE)
                                    .addComponent(jLabel2, javax.swing.GroupLayout.Alignment.LEADING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                                .addGap(20, 20, 20))
                            .addGroup(layout.createSequentialGroup()
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                    .addComponent(jLabel7)
                                    .addComponent(jLabel8)
                                    .addComponent(tfMonth2)
                                    .addComponent(tfYear2)
                                    .addComponent(btnAllListSendingOrders))
                                .addGap(18, 18, 18)
                                .addComponent(jSeparator4, javax.swing.GroupLayout.PREFERRED_SIZE, 11, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                    .addComponent(btnListIncompletePayments, javax.swing.GroupLayout.DEFAULT_SIZE, 244, Short.MAX_VALUE)
                                    .addComponent(btnReportPanel, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                                .addGap(37, 37, 37))))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addGap(0, 22, Short.MAX_VALUE)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(btnAddIndividualSubscriber, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(btnAddCorporaitonSubscriber, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addGap(99, 99, 99)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(btnAddJournal, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(btnAddSubscribtion, javax.swing.GroupLayout.DEFAULT_SIZE, 310, Short.MAX_VALUE))))
                .addGap(63, 63, 63))
            .addComponent(jSeparator2)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(btnAddIndividualSubscriber, javax.swing.GroupLayout.PREFERRED_SIZE, 53, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnAddJournal, javax.swing.GroupLayout.PREFERRED_SIZE, 53, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(btnAddCorporaitonSubscriber, javax.swing.GroupLayout.PREFERRED_SIZE, 53, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(btnAddSubscribtion, javax.swing.GroupLayout.PREFERRED_SIZE, 53, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addComponent(jSeparator2, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(2, 2, 2)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(22, 22, 22)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                                .addComponent(tfJournalIssn, javax.swing.GroupLayout.PREFERRED_SIZE, 38, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addComponent(tfSubscriberId, javax.swing.GroupLayout.PREFERRED_SIZE, 38, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addComponent(btnListJournals, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, 38, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(btnListSubscriptionsBySubscriber, javax.swing.GroupLayout.PREFERRED_SIZE, 38, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(btnListSubscriptionsByJournal, javax.swing.GroupLayout.PREFERRED_SIZE, 38, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(btnListSubscribers, javax.swing.GroupLayout.PREFERRED_SIZE, 38, javax.swing.GroupLayout.PREFERRED_SIZE)))
                    .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                        .addComponent(jLabel1)
                        .addComponent(jLabel2)))
                .addGap(13, 13, 13)
                .addComponent(jSeparator1, javax.swing.GroupLayout.PREFERRED_SIZE, 10, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(32, 32, 32)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel4)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(tfIssn, javax.swing.GroupLayout.PREFERRED_SIZE, 34, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(12, 12, 12)
                                .addComponent(jLabel5)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(tfMonth1, javax.swing.GroupLayout.PREFERRED_SIZE, 34, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(jLabel6)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(tfYear1, javax.swing.GroupLayout.PREFERRED_SIZE, 34, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(12, 12, 12)
                                .addComponent(btnListSendingOrders, javax.swing.GroupLayout.PREFERRED_SIZE, 36, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(layout.createSequentialGroup()
                                .addComponent(jLabel7)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(tfMonth2, javax.swing.GroupLayout.PREFERRED_SIZE, 34, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                                .addComponent(jLabel8)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(tfYear2, javax.swing.GroupLayout.PREFERRED_SIZE, 34, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addGap(12, 12, 12)
                                .addComponent(btnAllListSendingOrders, javax.swing.GroupLayout.PREFERRED_SIZE, 36, javax.swing.GroupLayout.PREFERRED_SIZE)))
                        .addGap(0, 22, Short.MAX_VALUE))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                            .addComponent(jSeparator5)
                            .addComponent(jSeparator4))
                        .addContainerGap())
                    .addGroup(layout.createSequentialGroup()
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addComponent(btnListIncompletePayments, javax.swing.GroupLayout.PREFERRED_SIZE, 37, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(67, 67, 67)
                        .addComponent(btnReportPanel, javax.swing.GroupLayout.PREFERRED_SIZE, 60, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void btnAddIndividualSubscriberActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnAddIndividualSubscriberActionPerformed
        AddIndividualSubscriberPanel addSubscriberPanel = new AddIndividualSubscriberPanel();
        addSubscriberPanel.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        addSubscriberPanel.setVisible(true);
        addSubscriberPanel.pack();
        addSubscriberPanel.setLocationRelativeTo(null);

    }//GEN-LAST:event_btnAddIndividualSubscriberActionPerformed

    private void btnAddCorporaitonSubscriberActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnAddCorporaitonSubscriberActionPerformed
        AddCorporationSubscriberPanel addCorporationSubscriber = new AddCorporationSubscriberPanel();
        addCorporationSubscriber.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        addCorporationSubscriber.setVisible(true);
        addCorporationSubscriber.pack();
        addCorporationSubscriber.setLocationRelativeTo(null);

    }//GEN-LAST:event_btnAddCorporaitonSubscriberActionPerformed

    private void btnListSubscribersActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnListSubscribersActionPerformed
        distributor.listSubscribers();
    }//GEN-LAST:event_btnListSubscribersActionPerformed

    private void btnAddJournalActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnAddJournalActionPerformed
        AddJournalPanel addJournal = new AddJournalPanel();
        addJournal.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        addJournal.setVisible(true);
        addJournal.pack();
        addJournal.setLocationRelativeTo(null);
    }//GEN-LAST:event_btnAddJournalActionPerformed

    private void btnListJournalsActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnListJournalsActionPerformed
        distributor.listJournals();
    }//GEN-LAST:event_btnListJournalsActionPerformed

    private void btnAddSubscribtionActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnAddSubscribtionActionPerformed
        AddSubscriptionPanel subscriptionPanel = new AddSubscriptionPanel();
        subscriptionPanel.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        subscriptionPanel.setVisible(true);
        subscriptionPanel.pack();
        subscriptionPanel.setLocationRelativeTo(null);
    }//GEN-LAST:event_btnAddSubscribtionActionPerformed

    private void btnListSubscriptionsBySubscriberActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnListSubscriptionsBySubscriberActionPerformed
        String subscriberIdString = tfSubscriberId.getText();

        if (subscriberIdString.isEmpty()) {
            JOptionPane.showMessageDialog(null, "Please enter Subscriber ID!", "Try again", JOptionPane.ERROR_MESSAGE);
            return;
        }

        Integer subscriberId = Integer.parseInt(subscriberIdString);

        distributor.listSubcriptionsBySubscriber(subscriberId);
    }//GEN-LAST:event_btnListSubscriptionsBySubscriberActionPerformed

    private void btnListSubscriptionsByJournalActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnListSubscriptionsByJournalActionPerformed
        String issn = tfJournalIssn.getText();

        if (issn.isEmpty()) {
            JOptionPane.showMessageDialog(null, "Please enter Subscriber ID!", "Try again", JOptionPane.ERROR_MESSAGE);
            return;
        }

        distributor.listSubcriptionsByJournal(issn);
    }//GEN-LAST:event_btnListSubscriptionsByJournalActionPerformed

    private void tfSubscriberIdActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_tfSubscriberIdActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_tfSubscriberIdActionPerformed

    private void btnListSendingOrdersActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnListSendingOrdersActionPerformed
        String issn = tfIssn.getText();
        String monthString = tfMonth1.getText();
        String yearString = tfYear1.getText();

        if (issn.isEmpty() || monthString.isEmpty() || yearString.isEmpty()) {
            JOptionPane.showMessageDialog(null, "Please enter all fields!", "Try again", JOptionPane.ERROR_MESSAGE);
            return;
        }

        Integer month = Integer.parseInt(monthString);
        Integer year = Integer.parseInt(yearString);

        if (month > 12 && month < 1) {
            JOptionPane.showMessageDialog(null, "Month must be between 1 and 12!", "Try again", JOptionPane.ERROR_MESSAGE);
            return;
        }

        JOptionPane.showMessageDialog(null, distributor.listSendingOrders(issn, month, year), "Sending Orders for Journal with ISSN: " + issn, JOptionPane.INFORMATION_MESSAGE);
    }//GEN-LAST:event_btnListSendingOrdersActionPerformed

    private void tfIssnActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_tfIssnActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_tfIssnActionPerformed

    private void tfYear1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_tfYear1ActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_tfYear1ActionPerformed

    private void tfMonth1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_tfMonth1ActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_tfMonth1ActionPerformed

    private void tfYear2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_tfYear2ActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_tfYear2ActionPerformed

    private void tfMonth2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_tfMonth2ActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_tfMonth2ActionPerformed

    private void btnAllListSendingOrdersActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnAllListSendingOrdersActionPerformed
        String monthString = tfMonth2.getText();
        String yearString = tfYear2.getText();

        if (monthString.isEmpty() || yearString.isEmpty()) {
            JOptionPane.showMessageDialog(null, "Please enter all fields!", "Try again", JOptionPane.ERROR_MESSAGE);
            return;
        }

        Integer month = Integer.parseInt(monthString);
        Integer year = Integer.parseInt(yearString);

        if (month > 12 && month < 1) {
            JOptionPane.showMessageDialog(null, "Month must be between 1 and 12!", "Try again", JOptionPane.ERROR_MESSAGE);
            return;
        }

        distributor.listAllSendingOrders(month, year);
    }//GEN-LAST:event_btnAllListSendingOrdersActionPerformed

    private void btnListIncompletePaymentsActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnListIncompletePaymentsActionPerformed
        distributor.listIncompletePayments();
    }//GEN-LAST:event_btnListIncompletePaymentsActionPerformed

    private void btnReportPanelActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_btnReportPanelActionPerformed
        Thread reportThread = new Thread(new Distributor());
        reportThread.start();
    }//GEN-LAST:event_btnReportPanelActionPerformed


    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton btnAddCorporaitonSubscriber;
    private javax.swing.JButton btnAddIndividualSubscriber;
    private javax.swing.JButton btnAddJournal;
    private javax.swing.JButton btnAddSubscribtion;
    private javax.swing.JButton btnAllListSendingOrders;
    private javax.swing.JButton btnListIncompletePayments;
    private javax.swing.JButton btnListJournals;
    private javax.swing.JButton btnListSendingOrders;
    private javax.swing.JButton btnListSubscribers;
    private javax.swing.JButton btnListSubscriptionsByJournal;
    private javax.swing.JButton btnListSubscriptionsBySubscriber;
    private javax.swing.JButton btnReportPanel;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JSeparator jSeparator1;
    private javax.swing.JSeparator jSeparator2;
    private javax.swing.JSeparator jSeparator4;
    private javax.swing.JSeparator jSeparator5;
    private javax.swing.JTextField tfIssn;
    private javax.swing.JTextField tfJournalIssn;
    private javax.swing.JTextField tfMonth1;
    private javax.swing.JTextField tfMonth2;
    private javax.swing.JTextField tfSubscriberId;
    private javax.swing.JTextField tfYear1;
    private javax.swing.JTextField tfYear2;
    // End of variables declaration//GEN-END:variables
}
