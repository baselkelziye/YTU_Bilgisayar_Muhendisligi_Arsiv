package application;

import gui.main_gui;
public class main_gui_thread implements Runnable
    {
    @Override
    public void run() {
        new main_gui().setVisible(true);
    }

    }

