package application;

import gui.report_gui;
public class report_gui_thread implements Runnable
    {
    @Override
    public void run() {
        new report_gui().setVisible(true);
    }

    }