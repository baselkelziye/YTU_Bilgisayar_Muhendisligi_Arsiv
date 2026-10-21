package com.airline.gui;

import javax.swing.*;
import java.awt.*;
import java.util.Random;
import java.util.concurrent.*;
import java.util.concurrent.atomic.AtomicInteger;

public class SeatSimulationPanel extends JPanel {

    private static final int ROWS = 30;
    private static final int COLS = 6;
    private static final int PASSENGERS = 90;

    private final JButton[][] seatButtons = new JButton[ROWS][COLS];
    private final boolean[][] seats = new boolean[ROWS][COLS];

    private final Object seatLock = new Object();

    private JCheckBox syncCheckBox;
    private JButton startButton;
    private JLabel resultLabel;

    private AtomicInteger occupiedCount = new AtomicInteger(0);

    public SeatSimulationPanel() {
        setLayout(new BorderLayout());
        initUI();
    }

    private void initUI() {
        JPanel topPanel = new JPanel();
        syncCheckBox = new JCheckBox("Synchronize Threads", true);
        startButton = new JButton("Start Simulation");
        startButton.addActionListener(e -> startSimulation());

        topPanel.add(syncCheckBox);
        topPanel.add(startButton);
        add(topPanel, BorderLayout.NORTH);

        JPanel gridPanel = new JPanel(new GridLayout(ROWS, COLS, 2, 2));
        initSeats(gridPanel);
        add(gridPanel, BorderLayout.CENTER);

        resultLabel = new JLabel("Occupied seats: 0", SwingConstants.CENTER);
        add(resultLabel, BorderLayout.SOUTH);

        JPanel legend = new JPanel();
        JLabel l1 = new JLabel("Green: Available ");
        l1.setForeground(new Color(0, 128, 0));
        JLabel l2 = new JLabel("Red: Occupied ");
        l2.setForeground(Color.RED);
        JLabel l3 = new JLabel("Orange: ERROR (Double Booked!)");
        l3.setForeground(Color.ORANGE.darker());
        legend.add(l1);
        legend.add(l2);
        legend.add(l3);
        add(legend, BorderLayout.SOUTH);

        JPanel bottomWrapper = new JPanel(new BorderLayout());
        bottomWrapper.add(resultLabel, BorderLayout.NORTH);
        bottomWrapper.add(legend, BorderLayout.SOUTH);
        add(bottomWrapper, BorderLayout.SOUTH);
    }

    private void initSeats(JPanel panel) {
        panel.removeAll();
        occupiedCount.set(0);

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                seats[i][j] = false;
                JButton btn = new JButton((i + 1) + "" + (char) ('A' + j));
                btn.setEnabled(false);
                btn.setBackground(Color.GREEN);
                seatButtons[i][j] = btn;
                panel.add(btn);
            }
        }
        panel.revalidate();
        panel.repaint();
    }

    private void startSimulation() {
        initSeats((JPanel) getComponent(1));
        startButton.setEnabled(false);

        boolean synchronizedMode = syncCheckBox.isSelected();
        ExecutorService executor = Executors.newFixedThreadPool(PASSENGERS);

        for (int i = 0; i < PASSENGERS; i++) {
            executor.execute(new PassengerTask(synchronizedMode));
        }

        executor.shutdown();

        new Thread(() -> {
            try {
                executor.awaitTermination(20, TimeUnit.SECONDS); // Increased wait just in case
            } catch (InterruptedException ignored) {
            }

            int uniqueSeats = 0;
            for (int r = 0; r < ROWS; r++) {
                for (int c = 0; c < COLS; c++) {
                    if (seats[r][c])
                        uniqueSeats++;
                }
            }

            final int finalUnique = uniqueSeats;
            final int ops = occupiedCount.get();

            SwingUtilities.invokeLater(() -> {
                resultLabel.setText(String.format("Target: %d | Processed: %d | Actual Reserved: %d", PASSENGERS, ops,
                        finalUnique));

                if (finalUnique != PASSENGERS) {
                    resultLabel.setForeground(Color.RED);
                    resultLabel.setText(resultLabel.getText() + " (SYNC ERROR!)");
                } else {
                    resultLabel.setForeground(new Color(0, 100, 0));
                    resultLabel.setText(resultLabel.getText() + " (Success)");
                }
                startButton.setEnabled(true);
            });
        }).start();
    }

    private class PassengerTask implements Runnable {

        private final boolean sync;
        private final Random random = new Random();

        PassengerTask(boolean sync) {
            this.sync = sync;
        }

        @Override
        public void run() {
            boolean seatReserved = false;
            while (!seatReserved) {
                int r = random.nextInt(ROWS);
                int c = random.nextInt(COLS);

                if (sync) {
                    synchronized (seatLock) {
                        if (!seats[r][c]) {
                            reserveSeat(r, c);
                            seatReserved = true;
                        }
                    }
                } else {
                    if (!seats[r][c]) {
                        try {
                            Thread.sleep(10);
                        } catch (InterruptedException e) {
                        }
                        reserveSeat(r, c);
                        seatReserved = true;
                    }
                }
            }
        }

        private void reserveSeat(int r, int c) {
            boolean isCollision = false;
            if (seats[r][c]) {
                isCollision = true;
            }

            seats[r][c] = true;
            occupiedCount.incrementAndGet();

            boolean finalIsCollision = isCollision;
            SwingUtilities.invokeLater(() -> {
                if (finalIsCollision) {
                    seatButtons[r][c].setBackground(Color.ORANGE);
                    seatButtons[r][c].setText("!!");
                } else {
                    seatButtons[r][c].setBackground(Color.RED);
                }
            });
        }
    }
}