package yelizCengiz;

import java.util.Date;

import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.SwingUtilities;

public class RendezvousThread implements Runnable{
	private final CRS crs;
    private final long natId;
    private final Hospital hospital;
    private final Section section;
    private final Doctor doctor;
    private final Date desired;
    private final JFrame frame;

    public RendezvousThread(CRS crs, long natId, Hospital hospital, Section section,Doctor doctor, Date desired, JFrame frame) {
        this.crs = crs;
        this.natId = natId;
        this.hospital = hospital;
        this.section = section;
        this.doctor = doctor;
        this.desired = desired;
        this.frame = frame;
    }

    @Override
    public synchronized void run() {
        if(crs.makeRendezvous(natId,hospital.getId(),section.getId(),doctor.getDiplomaId(), desired)) {
            SwingUtilities.invokeLater(() -> {
                JOptionPane.showMessageDialog(frame,"Rendezvous has been scheduled.");
            });
        } else {
            SwingUtilities.invokeLater(() -> {
                JOptionPane.showMessageDialog(frame,"Rendezvous has not been scheduled because the max number of patients for the day has been reached!!");
            });
        }
    }
}
