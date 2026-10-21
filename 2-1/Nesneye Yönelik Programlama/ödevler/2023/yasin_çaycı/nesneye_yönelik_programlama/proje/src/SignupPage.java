package a;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
 
public class SignupPage extends JFrame implements ActionListener, ItemListener {

	private static final long serialVersionUID = 1L;
	
	private Container container = getContentPane();
	private JLabel userLabel = new JLabel("USERNAME");
	private JLabel passwordLabel = new JLabel("PASSWORD");
	private JTextField userTextField = new JTextField();
	private JPasswordField passwordField = new JPasswordField();
	private JCheckBox checkboxAdmin = new JCheckBox("Admin");
	private JCheckBox checkboxUser = new JCheckBox("User");
	private JButton endButton = new JButton("Tamamla");
	private static ArrayList<Admin> adminList;
	private static ArrayList<User> userList;
	
    public SignupPage() {
        setLayoutManager();
        setLocationAndSize();
        addComponentsToContainer();
        addActionEvent();
        adminList = new ArrayList<>();
        userList = new ArrayList<>();
    }
 
    public void setLayoutManager() {
        container.setLayout(null);
    }
 
    public void setLocationAndSize() {
        userLabel.setBounds(35, 175, 100, 30);
        passwordLabel.setBounds(35, 235, 100, 30);
        userTextField.setBounds(138, 176, 150, 30);
        passwordField.setBounds(138, 236, 150, 30);
        checkboxAdmin.setBounds(138, 126, 60, 30);
    }
 
    public void addComponentsToContainer() {
        container.add(userLabel);
        container.add(passwordLabel);
        container.add(userTextField);
        container.add(passwordField);
        container.add(checkboxAdmin);
        
        checkboxUser.setBounds(238, 126, 60, 30);
        getContentPane().add(checkboxUser);
        
        checkboxAdmin.addItemListener(this);
        checkboxUser.addItemListener(this);
      
        
        endButton.setBackground(new Color(0, 128, 255));
        endButton.setBounds(150, 288, 126, 42);
        getContentPane().add(endButton);
    }
 
    public void addActionEvent() {
    	checkboxAdmin.addActionListener(this);
    	checkboxUser.addActionListener(this);
    	endButton.addActionListener(this);
    }
    
    public void itemStateChanged(ItemEvent e) {
        if (e.getSource() == checkboxAdmin && checkboxAdmin.isSelected()) {
        	checkboxUser.setSelected(false);
        } else if (e.getSource() == checkboxUser && checkboxUser.isSelected()) {
        	checkboxAdmin.setSelected(false);
        }
    }
    
    public boolean isExistingUser(User person, ArrayList<User> userList) {
        for (User element : userList) {
            if (element.getUsername().equalsIgnoreCase(person.getUsername())) {
                return true;
            }
        }
        return false;
    }

    public boolean isExistingAdmin(Admin person, ArrayList<Admin> adminList) {
        for (Admin element : adminList) {
            if (element.getUsername().equalsIgnoreCase(person.getUsername())) {
                return true;
            }
        }
        return false;
    }
    
    public void loadData(File file, ArrayList<Admin> adminList, ArrayList<User> userList) {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(file))) {
            Object obj = ois.readObject();
            if (obj instanceof ArrayList) {
                ArrayList<?> dataList = (ArrayList<?>) obj;
                for (Object data : dataList) {
                    if (data instanceof Admin) {
                        adminList.add((Admin) data);
                    } else if (data instanceof User) {
                        userList.add((User) data);
                    }
                }
                System.out.println(file.getName() + " dosyasından veriler yüklendi.");
            }
        } catch (IOException | ClassNotFoundException e) {
            e.printStackTrace();
        }
    }
    

   	@SuppressWarnings("deprecation")
   	@Override
   	public void actionPerformed(ActionEvent e) { 
   	    String directoryPath = "data";
   	    File directory = new File(directoryPath);
   	  
   	    if (!directory.exists()) {
   	        directory.mkdirs(); // Klasörü oluştur
   	        System.out.println("data klasörü oluşturuldu.");
   	    }

   	    if (e.getSource() == endButton) {
   	        if (checkboxAdmin.isSelected()) {
   	        	String fileName = "admins.dat";
   	            File file = new File(directory, fileName);
   	   	    	loadData(file, adminList, userList);
   	            Admin admin = new Admin(userTextField.getText(), passwordField.getText());
   	           
   	            if (isExistingAdmin(admin, adminList)) {
   	                JOptionPane.showMessageDialog(this, "Farklı bir kullanıcı adı seçin");
   	            } else {
   	                adminList.add(admin);
   	                saveData(file, adminList, fileName);
   	                LoginPage frame = new LoginPage();
   	                jumpToLogin(frame);
   	            }
   	        } else if (checkboxUser.isSelected()) {
   	        	String fileName = "users.dat";
	            File file = new File(directory, fileName);
	            loadData(file, adminList, userList);
   	            User user = new User(userTextField.getText(), passwordField.getText(), null);
   	            if (isExistingUser(user, userList)) {
   	                JOptionPane.showMessageDialog(this, "Farklı bir kullanıcı adı seçin");
   	            } else {
   	                userList.add(user);
   	                saveData(file, userList, fileName);
   	                LoginPage frame = new LoginPage();
   	                jumpToLogin(frame);
   	            }
   	        } else {
   	            JOptionPane.showMessageDialog(this, "Hangi rolde kayıt olacağınızı seçin");
   	        }
   	    }
   	}
   	
   	public <E> void saveData(File file, ArrayList<E> userList, String fileName) {
   		if (!file.exists()) {
		     try {
		         file.createNewFile();
		         System.out.println(".dat dosyası oluşturuldu.");
		     } catch (IOException err) {
		         err.printStackTrace();
		     }
		 }

	      try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(fileName))) {
	          oos.writeObject(userList);
	          System.out.println("İnsanlar dosyaya kaydedildi.");
	      } catch (IOException err) {
           err.printStackTrace();
	      }
   	}
   	
   	public void jumpToLogin(LoginPage frame) {    
   	    frame.setVisible(true);
   	    this.setVisible(false);
   	    frame.setBounds(10, 10, 400, 500);
   	    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
   	    frame.setResizable(false);
   	    
   	    // Seçili rolü kontrol edip aktarmak için;
   	    if (checkboxAdmin.isSelected()) {
   	        frame.setSelectedRole("admin");
   	    } else if (checkboxUser.isSelected()) {
   	        frame.setSelectedRole("user");
   	    }
   	}


}
 