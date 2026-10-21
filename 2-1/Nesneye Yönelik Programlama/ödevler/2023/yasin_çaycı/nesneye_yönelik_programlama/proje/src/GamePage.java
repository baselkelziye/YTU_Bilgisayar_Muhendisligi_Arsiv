package a;

import java.awt.Container;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.io.OutputStream;
import java.text.SimpleDateFormat;
import java.time.Duration;
import java.util.ArrayList;
import java.util.Date;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTextField;
import javax.swing.Timer;
import java.awt.Color;
import javax.swing.JLayeredPane;
import java.awt.Font;
import java.awt.Image;

public class GamePage extends JFrame implements ActionListener{

	private static final long serialVersionUID = 1L;
	
	private Container container = getContentPane();
	private JLabel lblNewLabel = new JLabel("Soru:");
	private JLabel lblNewLabel_1 = new JLabel("1");
	private JLabel lblNewLabel_1_1 = new JLabel(Integer.toString(AdminPage.numberN));
	private JLabel lblNewLabel_1_2 = new JLabel("\\");
	private JLabel labelN = new JLabel(Integer.toString(AdminPage.numberA));
    private JLabel lblX = new JLabel("x");
    private JLabel labelN_2 = new JLabel(Integer.toString(AdminPage.numberB));
    private JLabel labelN_3 = new JLabel("=       ?");
    private JTextField TextFieldN = new JTextField();
    private JButton answerButton = new JButton("Cevapla");
    private JButton homeButton = new JButton("");
    private JLabel timerLabel = new JLabel("0");
    private Image img = new ImageIcon(this.getClass().getResource("images/homeicon.png")).getImage();
    private int counter = 1;
    private Timer timer;
    private long startTime;
    private static double puan;
    private double[] elapsedSeconds;
    private Question question;
    private Exercise exercise;
    private ArrayList<Question> questions;
    
    GamePage() {
    	getContentPane().setFont(new Font("Tahoma", Font.PLAIN, 13));
        setLayoutManager();
        setLocationAndSize();
        addComponentsToContainer();
        addActionEvent();
        startTimer();
        puan = 100;
        elapsedSeconds = new double[AdminPage.numberN];
        questions = new ArrayList<>();
    }
 
    public void setLayoutManager() {
        container.setLayout(null);
    }
 
    public void setLocationAndSize() {
        labelN.setFont(new Font("Tahoma", Font.PLAIN, 16));
        labelN.setBounds(101, 160, 34, 30);
        TextFieldN.setBounds(82, 215, 232, 37);
        answerButton.setBackground(new Color(0, 128, 255));
        answerButton.setBounds(82, 280, 232, 52);
        answerButton.setOpaque(true);
        homeButton.setIcon(new ImageIcon(img));
        homeButton.setBounds(174, 10, 34, 30);
        homeButton.setContentAreaFilled(false);
        homeButton.setBorderPainted(false);
        homeButton.addActionListener(new ActionListener() {
        	public void actionPerformed(ActionEvent e) {
        		StartPage frame = new StartPage();
        		jumpToStart(frame);
        	}
        });
    }
 
    public void addComponentsToContainer() {
    	container.add(homeButton);
    	container.add(labelN);
        
        JLayeredPane layeredPane = new JLayeredPane();
        layeredPane.setBounds(0, 0, 1, 1);
        getContentPane().add(layeredPane);
        container.add(TextFieldN);
        container.add(answerButton);
        
        lblX.setBounds(141, 160, 26, 30);
        getContentPane().add(lblX);
        labelN_2.setFont(new Font("Tahoma", Font.PLAIN, 16));
        
        labelN_2.setBounds(177, 160, 34, 30);
        getContentPane().add(labelN_2);
        
        labelN_3.setFont(new Font("Tahoma", Font.PLAIN, 16));
        labelN_3.setBounds(219, 160, 95, 30);
        getContentPane().add(labelN_3);
              
        lblNewLabel.setFont(new Font("Tahoma", Font.PLAIN, 16));
        lblNewLabel.setBounds(115, 84, 45, 13);
        getContentPane().add(lblNewLabel);
        
        lblNewLabel_1.setFont(new Font("Tahoma", Font.PLAIN, 16));
        lblNewLabel_1.setBounds(174, 84, 20, 13);
        getContentPane().add(lblNewLabel_1);
        
        lblNewLabel_1_1.setFont(new Font("Tahoma", Font.PLAIN, 16));
        lblNewLabel_1_1.setBounds(232, 84, 20, 13);
        getContentPane().add(lblNewLabel_1_1);
        
        lblNewLabel_1_2.setFont(new Font("Tahoma", Font.PLAIN, 16));
        lblNewLabel_1_2.setBounds(204, 84, 20, 13);
        getContentPane().add(lblNewLabel_1_2);
        
        timerLabel.setBounds(174, 362, 45, 13);
        getContentPane().add(timerLabel);
    }
 
    public void addActionEvent() {
    	answerButton.addActionListener(this);
    }
    
    private void startTimer() {
        startTime = System.nanoTime();
        ActionListener taskPerformer = new ActionListener() {
            public void actionPerformed(ActionEvent evt) {
                long endTime = System.nanoTime();
                long finalTime = endTime - startTime;

                // Süreyi Duration sınıfı ile hesaplamak için
                Duration duration = Duration.ofNanos(finalTime);

                // Süreyi istediğim formatta biçimlendirmek için
                long hours = duration.toHours();
                long minutes = duration.toMinutesPart();
                long seconds = duration.toSecondsPart();
                String formattedTime = String.format("%02d:%02d:%02d", hours, minutes, seconds);

                timerLabel.setText(formattedTime);
            }
        };

        timer = new Timer(1, taskPerformer);
        timer.start();
    }

    @Override
    public void actionPerformed(ActionEvent e) {
    	String directoryPath = "data";
   	    File directory = new File(directoryPath);
	    if (!directory.exists()) {
	        directory.mkdirs(); // Klasörü oluştur
	        System.out.println("data klasörü oluşturuldu.");
	    }
	    
    	int control = AdminPage.numberA * AdminPage.numberB;
    	exercise = new Exercise(null,null,null);
        if (counter < AdminPage.numberN) {
        	long endTime = System.nanoTime();
            long finalTime = endTime - startTime;
        	timer.stop();
            timerLabel.setText("0");
            if (e.getSource() == answerButton) {
            	double elapsedSecond = finalTime / 1_000_000_000.0;
            	elapsedSeconds[counter-1] = elapsedSecond;
                System.out.println(elapsedSeconds[counter-1]);
                if (Integer.parseInt(TextFieldN.getText()) == control) {  
                    System.out.println("Doğru cevap");
                    question = new Question(elapsedSecond, AdminPage.numberA, AdminPage.numberB, true);
                } else {
                	question = new Question(elapsedSecond, AdminPage.numberA, AdminPage.numberB, false);
                	puan -= (float) (100/(float)AdminPage.numberN);
                }
                questions.add(question);
                if(counter == 1) {
                	Date date = new Date();
                	SimpleDateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
                    String formattedDate = dateFormat.format(date);
                	exercise.setStartTime(formattedDate);
                }
                if(counter == AdminPage.numberN - 1) {// son soru soruldu
                	Date date = new Date();
                	SimpleDateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
                    String formattedDate = dateFormat.format(date);
                	exercise.setEndTime(formattedDate);
                }
                if(control != 0) { //eğer admin tarafından bir sayı girilmemişse varsayılan modu sağlamak için;
	                AdminPage.numberA = (int) (Math.random() * 9 + 1);
	                AdminPage.numberB = (int) (Math.random() * 9 + 1);
                }

                labelN.setText(Integer.toString(AdminPage.numberA));
                labelN_2.setText(Integer.toString(AdminPage.numberB));
                TextFieldN.setText("");
                startTimer();
                timerLabel.setText("0"); 
                counter++; // counter'ın artırılma işlemi burada yapılıyor
                lblNewLabel_1.setText(Integer.toString(counter));
            }
        }
        else { //artık son soru ve sonrası için;
        	exercise.setQuestions(questions);
        	long endTime = System.nanoTime();
            long finalTime = endTime - startTime;
            elapsedSeconds[AdminPage.numberN-1] = finalTime / 1_000_000_000.0;
            System.out.println(elapsedSeconds[counter-1]);
        	timer.stop();
        	//son soru için;
        	if (Integer.parseInt(TextFieldN.getText()) == control) { 
                System.out.println("Doğru cevap");
            } else {
                puan -= (float) (100/(float)AdminPage.numberN);
            }
        	TextFieldN.setText("");
            timer.stop();
            timerLabel.setText("00:00:00");
            Double point = (puan - findTotal(elapsedSeconds) / 5);
            JOptionPane.showMessageDialog(this, "Puan: " + point);
            exercise.setPoint(point);
        }
        if(LoginPage.trueUser.getExercises() == null) { //hiç alıştırma yapılmamışsa
        	ArrayList<Exercise> exercises = new ArrayList<>();
        	exercises.add(exercise);
        	LoginPage.trueUser.setExercises(exercises);
        	}
        else {
        	LoginPage.trueUser.getExercises().add(exercise);
        }
        String fileName = "results.dat";
        File file = new File(directory, fileName);
        saveResult(file, LoginPage.trueUser);
    }
    
    private void saveResult(File file, User user) {
        String fileName = "results.dat";
        if (!file.exists()) {
		     try {
		         file.createNewFile();
		         System.out.println(".dat dosyası oluşturuldu.");
		     } catch (IOException err) {
		         err.printStackTrace();
		     }
		 }
        try {
            // Dosyayı açma modu "append" olarak ayarlanır
            FileOutputStream fos = new FileOutputStream(fileName, true);
            ObjectOutputStream oos;

            // Dosyaya yeni bir kullanıcı eklemek için ObjectOutputStream oluşturulur
            if (file.length() == 0) {
                // Dosya boşsa yeni ObjectOutputStream oluşturulur
                oos = new ObjectOutputStream(fos);
            } else {
                // Dosya boş değilse mevcut FileOutputStream'a ObjectOutputStream bağlanır
                oos = new AppendableObjectOutputStream(fos);
            }

            // Kullanıcıyı dosyaya yaz
            oos.writeObject(user);
            System.out.println("User result dosyasına kaydedildi.");
            oos.close();
            fos.close();
        } catch (IOException err) {
            err.printStackTrace();
        }
    }
   
    private double findTotal(double[] arr) {
        double total = arr[0];
        for(int i = 1; i < arr.length; i++) {
        	System.out.println(total);
            total += arr[i];
        }
        System.out.println(total);
        return total;
    }
	
	private void jumpToStart(StartPage frame) {
	     frame.setVisible(true);
	     this.setVisible(false);
	     frame.setBounds(10, 10, 400, 500);
	     frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	     frame.setResizable(false);
	 }
 
}

 class AppendableObjectOutputStream extends ObjectOutputStream {
    public AppendableObjectOutputStream(OutputStream out) throws IOException {
        super(out);
    }

    @Override
    protected void writeStreamHeader() throws IOException {
        // Geçersiz kılınarak dosya başlığının yazılmasını engeller
        // Böylece mevcut dosyanın sonuna eklemeyi sağlar
        reset();
    }
}
