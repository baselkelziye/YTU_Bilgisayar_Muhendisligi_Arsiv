package a;

import java.awt.Container;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.ArrayList;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JScrollPane;

import java.awt.Color;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

public class ResultsPage extends JFrame implements ActionListener{

	private static final long serialVersionUID = 1L;
	
	private Container container = getContentPane();
	private JButton deleteButton = new JButton("Kayıtları Sil");
	private JButton backButton = new JButton("");
	private Image img = new ImageIcon(this.getClass().getResource("images/backButton.png")).getImage();
	private JTable table;
	private String[] titles = {"Username", "Start Time", "Finish Time","Point"};
	private JScrollPane sp;
	
    ResultsPage() {
        setLayoutManager();
        setLocationAndSize();
        addComponentsToContainer();
        addActionEvent();
    }
 
    public void setLayoutManager() {
        container.setLayout(null);
    }
 
    public void setLocationAndSize() {
        deleteButton.setBackground(new Color(0, 128, 255));
        deleteButton.setBounds(375, 392, 269, 52);
        deleteButton.setOpaque(true);
        backButton.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		AdminPage frame = new AdminPage();
                jumpToAdmin(frame);
        	}
        });
        backButton.setIcon(new ImageIcon(img));
        backButton.setBounds(473, 10, 34, 30);
        backButton.setContentAreaFilled(false);
        backButton.setBorderPainted(false);
    }
 
    public void addComponentsToContainer() {
        container.add(deleteButton);
        container.add(backButton);
        
        table = new JTable();
        table.setBounds(20, 60, 875, 299);
        getContentPane().add(table);
        //sp = new JScrollPane(table);
        //container.add(sp);
        loadData();
    }
 
    public void addActionEvent() {
    	deleteButton.addActionListener(this);
    }
 
    @Override
    public void actionPerformed(ActionEvent e) {

        if(e.getSource() == deleteButton) {
        	deleteRecords();
        }
    }
    
    private void loadData() {
        try {
            // Verileri okumak için ObjectInputStream kullanacağız
            FileInputStream fis = new FileInputStream("results.dat");
            ObjectInputStream ois = new ObjectInputStream(fis);
            User user = (User) ois.readObject(); 
            ArrayList<Exercise> exercises = user.getExercises();
            DefaultTableModel model = new DefaultTableModel();

            // Sütun başlıklarını modelin sütunlarına ekle
            for (String title : titles) {
                model.addColumn(title);
            }

            // Her bir egzersiz için verileri tabloya ekle
            for (Exercise exercise : exercises) {
            	String username = user.getUsername();
                String startTime = String.valueOf(exercise.getStartTime());
                String finishTime = String.valueOf(exercise.getEndTime());
                double point = exercise.getPoint();
                // Verileri modelin bir satırına ekle
                model.addRow(new Object[]{username, startTime, finishTime, point});
                
            }

            table.setModel(model);
            
            ois.close();
            fis.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }

    
    private void deleteRecords() {
    	String resultsFilePath = "results.dat";
         //results.dat dosyasını sil
        File resultsFile = new File(resultsFilePath);
        if (resultsFile.exists()) {
        	resultsFile.delete();
            System.out.println("results.dat dosyası silindi.");
        } else {
            System.out.println("results.dat dosyası bulunamadı.");
        }      
    }
    
    private void jumpToAdmin(AdminPage frame) {
    	this.setVisible(false);
        frame.setVisible(true);
        frame.setBounds(10, 10, 400, 500);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(false);
    }
}
