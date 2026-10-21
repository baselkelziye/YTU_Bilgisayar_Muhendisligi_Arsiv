package deneme;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

// User class to store logged-in user details
class User {
    private int id;
    private String username;
    private String fname;
    private String lname;
    private String address;

    public User(int id, String username, String fname, String lname, String address) {
        this.id = id;
        this.username = username;
        this.fname = fname;
        this.lname = lname;
        this.address = address;
    }

    public int getId() {
        return id;
    }

    public String getFname() {
        return fname;
    }

    public String getLname() {
        return lname;
    }

    public String getAddress() {
        return address;
    }

    public String getUsername() {
        return username;
    }
}

public class SwingLoginApp {
    // Database connection details
    static final String DB_URL = "jdbc:postgresql://localhost/vetcare";
    static final String DB_USER = "postgres";
    static final String DB_PASSWORD = "1234";

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> new LoginFrame());
    }
}

// Login Frame
class LoginFrame extends JFrame {
    private JTextField usernameField;
    private JPasswordField passwordField;
    private JLabel messageLabel;

    public LoginFrame() {
        setTitle("Login System");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(400, 250);
        setLocationRelativeTo(null);

        JPanel panel = new JPanel();
        panel.setLayout(new GridLayout(4, 2, 10, 10));

        JLabel usernameLabel = new JLabel("Username:");
        usernameField = new JTextField();

        JLabel passwordLabel = new JLabel("Password:");
        passwordField = new JPasswordField();

        JButton loginButton = new JButton("Login");
        loginButton.addActionListener(e -> handleLogin());

        messageLabel = new JLabel("", SwingConstants.CENTER);

        panel.add(usernameLabel);
        panel.add(usernameField);
        panel.add(passwordLabel);
        panel.add(passwordField);
        panel.add(new JLabel()); // Empty placeholder
        panel.add(loginButton);

        add(panel, BorderLayout.CENTER);
        add(messageLabel, BorderLayout.SOUTH);

        setVisible(true);
    }

    private void handleLogin() {
        String username = usernameField.getText();
        String password = new String(passwordField.getPassword());

        try (Connection conn = DriverManager.getConnection(SwingLoginApp.DB_URL, SwingLoginApp.DB_USER, SwingLoginApp.DB_PASSWORD)) {
            User user = validateCredentials(conn, username, password);

            if (user != null) {
                messageLabel.setText("Login successful!");
                new HomepageFrame(user).setVisible(true);;
                dispose();
            } else {
                messageLabel.setText("Invalid username or password.");
            }
        } catch (SQLException ex) {
            ex.printStackTrace();
            messageLabel.setText("Database error.");
        }
    }

    private User validateCredentials(Connection conn, String username, String password) throws SQLException {
        String query = "SELECT * FROM person WHERE username = ? AND password = ?";
        try (PreparedStatement stmt = conn.prepareStatement(query)) {
            stmt.setString(1, username);
            stmt.setString(2, password);

            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                return new User(
                        rs.getInt("id"),
                        rs.getString("username"),
                        rs.getString("fname"),
                        rs.getString("lname"),
                        rs.getString("address")
                );
            }
        }
        return null;
    }
}

// Homepage Frame
class HomepageFrame extends JFrame {
    private User user;

        public HomepageFrame(User user) {
            this.user = user;

            setTitle("Personal Homepage");
            setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            setSize(500, 400);
            setLocationRelativeTo(null);

            JPanel buttonPanel = new JPanel();
            buttonPanel.setLayout(new GridLayout(5, 1, 10, 10));

            JButton accountInfoButton = new JButton("View Account Information");
            JButton viewPetsButton = new JButton("View My Pets");
            JButton vetReservationButton = new JButton("Make a Veterinary Appointment");
            JButton petStoreButton = new JButton("Go to Pet Store");
            JButton logoutButton = new JButton("Logout");

            accountInfoButton.addActionListener(e -> viewAccountInfo());
            viewPetsButton.addActionListener(e -> {
                dispose(); // Close the HomepageFrame
                new PetsFrame(user).setVisible(true);
            });
            vetReservationButton.addActionListener(e -> {
                dispose(); // Close the HomepageFrame
                new AppointmentFrame(user).setVisible(true);
            });
            petStoreButton.addActionListener(e -> {
                dispose(); // Close the HomepageFrame
                new PetStoreFrame(user).setVisible(true);
            });
            logoutButton.addActionListener(e -> logout());

            buttonPanel.add(accountInfoButton);
            buttonPanel.add(viewPetsButton);
            buttonPanel.add(vetReservationButton);
            buttonPanel.add(petStoreButton);
            buttonPanel.add(logoutButton);

            add(buttonPanel, BorderLayout.CENTER);


        }


        private void logout() {
            int confirmation = JOptionPane.showConfirmDialog(this, "Are you sure you want to logout?", "Logout Confirmation", JOptionPane.YES_NO_OPTION);
            if (confirmation == JOptionPane.YES_OPTION) {
                dispose(); // Close the HomepageFrame
                new LoginFrame().setVisible(true); // Redirect to login screen
            }
        }
    


    private void viewAccountInfo() {
        JOptionPane.showMessageDialog(this,
                "Full Name: " + user.getFname() + " " + user.getLname() +
                        "\nAddress: " + user.getAddress() +
                        "\nUsername: " + user.getUsername(),
                "Account Information", JOptionPane.INFORMATION_MESSAGE);
    }


}


//PetStoreFrame class with JList for product display
class PetStoreFrame extends JFrame {
 private User user;
 private JList<String> productList;
 private DefaultListModel<String> productListModel;
 private JTextField quantityField;
 private ArrayList<CartItem> cart;

 public PetStoreFrame(User user) {
     this.user = user;
     this.cart = new ArrayList<>();
     setTitle("Pet Store");
     setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
     setSize(600, 400);
     setLocationRelativeTo(null);

     JPanel mainPanel = new JPanel(new BorderLayout());
     JPanel controlPanel = new JPanel(new FlowLayout());

     JLabel quantityLabel = new JLabel("Quantity:");
     quantityField = new JTextField(5);
     JButton addToCartButton = new JButton("Add to Cart");
     JButton viewCartButton = new JButton("View Cart");
     JButton backButton = new JButton("Back");

     addToCartButton.addActionListener(e -> addToCart());
     viewCartButton.addActionListener(e -> {
         dispose();
         new CartFrame(user, cart, this).setVisible(true);
     });
     backButton.addActionListener(e -> {
         dispose();
         new HomepageFrame(user).setVisible(true);
     });

     controlPanel.add(quantityLabel);
     controlPanel.add(quantityField);
     controlPanel.add(addToCartButton);
     controlPanel.add(viewCartButton);
     controlPanel.add(backButton);

     productListModel = new DefaultListModel<>();
     productList = new JList<>(productListModel);
     productList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
     JScrollPane scrollPane = new JScrollPane(productList);

     loadProducts();

     mainPanel.add(scrollPane, BorderLayout.CENTER);
     mainPanel.add(controlPanel, BorderLayout.SOUTH);

     add(mainPanel);
     setVisible(true);
 }

 private void loadProducts() {
	    try (Connection conn = DriverManager.getConnection(SwingLoginApp.DB_URL, SwingLoginApp.DB_USER, SwingLoginApp.DB_PASSWORD)) {
	        String query = "SELECT product_id, name, price, quantity FROM display_stocks";
	        try (PreparedStatement stmt = conn.prepareStatement(query);
	             ResultSet rs = stmt.executeQuery()) {

	            while (rs.next()) {
	                int productId = rs.getInt("product_id");
	                String name = rs.getString("name");
	                double price = rs.getDouble("price");
	                int stock = rs.getInt("quantity");
	                productListModel.addElement(String.format("ID: %d | %s | $%.2f | Stock: %d", productId, name, price, stock));
	            }
	        }
	    } catch (SQLException ex) {
	        ex.printStackTrace();
	        JOptionPane.showMessageDialog(this, "Failed to load products.", "Error", JOptionPane.ERROR_MESSAGE);
	    }
	}


 private void addToCart() {
     int selectedIndex = productList.getSelectedIndex();
     if (selectedIndex == -1) {
         JOptionPane.showMessageDialog(this, "Please select a product.", "Error", JOptionPane.ERROR_MESSAGE);
         return;
     }

     try {
         String selectedProduct = productListModel.getElementAt(selectedIndex);
         String[] parts = selectedProduct.split("\\|");
         int productId = Integer.parseInt(parts[0].split(":")[1].trim());
         String name = parts[1].trim();
         double price = Double.parseDouble(parts[2].split("\\$")[1].trim());
         int stock = Integer.parseInt(parts[3].split(":")[1].trim());
         int quantity = Integer.parseInt(quantityField.getText());

         if (quantity > stock) {
             JOptionPane.showMessageDialog(this, "Not enough stock available.", "Error", JOptionPane.ERROR_MESSAGE);
             return;
         }

         cart.add(new CartItem(productId, name, price, quantity));
         JOptionPane.showMessageDialog(this, "Item added to cart.", "Success", JOptionPane.INFORMATION_MESSAGE);
     } catch (NumberFormatException e) {
         JOptionPane.showMessageDialog(this, "Invalid quantity.", "Error", JOptionPane.ERROR_MESSAGE);
     }
 }
}

class CartFrame extends JFrame {
    private User user;
    private ArrayList<CartItem> cart;
    private PetStoreFrame petStoreFrame;
    private JList<String> cartList;
    private DefaultListModel<String> cartListModel;

    public CartFrame(User user, ArrayList<CartItem> cart, PetStoreFrame petStoreFrame) {
        this.user = user;
        this.cart = cart;
        this.petStoreFrame = petStoreFrame;

        setTitle("Cart");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(600, 400);
        setLocationRelativeTo(null);

        JPanel mainPanel = new JPanel(new BorderLayout());
        JPanel controlPanel = new JPanel(new FlowLayout());

        JButton removeButton = new JButton("Remove Selected");
        JButton checkoutButton = new JButton("Checkout");
        JButton backButton = new JButton("Back to Store");
        JButton loadOrderDetailsButton = new JButton("Load Order Details");

        removeButton.addActionListener(e -> removeSelectedItem());
        checkoutButton.addActionListener(e -> checkout());
        backButton.addActionListener(e -> {
            dispose();
            petStoreFrame.setVisible(true);
        });
        loadOrderDetailsButton.addActionListener(e -> loadOrderDetails(user.getId()));

        controlPanel.add(removeButton);
        controlPanel.add(checkoutButton);
        controlPanel.add(backButton);
        controlPanel.add(loadOrderDetailsButton); // Add the new button here

        cartListModel = new DefaultListModel<>();
        cartList = new JList<>(cartListModel);
        cartList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        JScrollPane scrollPane = new JScrollPane(cartList);

        loadCart();

        mainPanel.add(scrollPane, BorderLayout.CENTER);
        mainPanel.add(controlPanel, BorderLayout.SOUTH);

        add(mainPanel);
        setVisible(true);
    }

    private void loadCart() {
        cartListModel.clear();
        for (CartItem item : cart) {
            cartListModel.addElement(String.format("ID: %d | %s | $%.2f | Quantity: %d",
                    item.getProductId(), item.getName(), item.getPrice(), item.getQuantity()));
        }
    }

    private void removeSelectedItem() {
        int selectedIndex = cartList.getSelectedIndex();
        if (selectedIndex == -1) {
            JOptionPane.showMessageDialog(this, "Please select an item to remove.", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }

        cart.remove(selectedIndex);
        loadCart();
        JOptionPane.showMessageDialog(this, "Item removed from cart.", "Success", JOptionPane.INFORMATION_MESSAGE);
    }

    private void checkout() {
        try (Connection conn = DriverManager.getConnection(SwingLoginApp.DB_URL, SwingLoginApp.DB_USER, SwingLoginApp.DB_PASSWORD)) {
            conn.setAutoCommit(false);

            String insertBuyQuery = "INSERT INTO buy (order_id, person_id) VALUES (nextval('buy_seq'), ?) RETURNING order_id";
            int orderId;
            try (PreparedStatement buyStmt = conn.prepareStatement(insertBuyQuery)) {
                buyStmt.setInt(1, user.getId());
                ResultSet rs = buyStmt.executeQuery();
                if (rs.next()) {
                    orderId = rs.getInt("order_id");
                } else {
                    throw new SQLException("Failed to generate buy ID.");
                }
            }

            String insertBuyDetailsQuery = "INSERT INTO buy_details (order_id, product_id, product_name, quantity) VALUES (?, ?, ?, ?)";
            try (PreparedStatement detailsStmt = conn.prepareStatement(insertBuyDetailsQuery)) {
                for (CartItem item : cart) {
                    detailsStmt.setInt(1, orderId);
                    detailsStmt.setInt(2, item.getProductId());
                    detailsStmt.setString(3, item.getName());
                    detailsStmt.setInt(4, item.getQuantity());
                    detailsStmt.addBatch();
                }
                detailsStmt.executeBatch();
            }

            conn.commit();
            cart.clear();
            loadCart();

            // Fetch total cost using buy_details_of_person function
            double totalCost = computeTotalCost(orderId);
            JOptionPane.showMessageDialog(this, "Purchase successful! Total cost: $" + totalCost, "Success", JOptionPane.INFORMATION_MESSAGE);
        } catch (SQLException ex) {
            ex.printStackTrace();
            JOptionPane.showMessageDialog(this, "Failed to complete purchase: " + ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    private double computeTotalCost(int orderId) throws SQLException {
        double totalCost = 0;
        String query = "SELECT compute_total_cost(?) AS total_cost";

        try (Connection conn = DriverManager.getConnection(SwingLoginApp.DB_URL, SwingLoginApp.DB_USER, SwingLoginApp.DB_PASSWORD);
             PreparedStatement stmt = conn.prepareStatement(query)) {
            stmt.setInt(1, orderId);

            try (ResultSet rs = stmt.executeQuery()) {
                if (rs.next()) {
                    totalCost = rs.getDouble("total_cost");
                }
            }
        }
        return totalCost;
    }

    // Updated loadOrderDetails method to open a new screen (frame)
    private void loadOrderDetails(int userId) {
        String query = "SELECT * FROM buy_details_of_person(?)";

        try (Connection conn = DriverManager.getConnection(SwingLoginApp.DB_URL, SwingLoginApp.DB_USER, SwingLoginApp.DB_PASSWORD);
             PreparedStatement stmt = conn.prepareStatement(query)) {
            stmt.setInt(1, userId);

            try (ResultSet rs = stmt.executeQuery()) {
                // Create a new frame to display the order details
                JFrame orderDetailsFrame = new JFrame("Order Details");
                orderDetailsFrame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
                orderDetailsFrame.setSize(600, 400);
                orderDetailsFrame.setLocationRelativeTo(this);

                DefaultListModel<String> orderDetailsModel = new DefaultListModel<>();
                JList<String> orderDetailsList = new JList<>(orderDetailsModel);
                orderDetailsList.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
                JScrollPane scrollPane = new JScrollPane(orderDetailsList);

                while (rs.next()) {
                    String productName = rs.getString("product_name");
                    int quantity = rs.getInt("quantity");
                    orderDetailsModel.addElement(String.format("Product: %s | Quantity: %d", productName, quantity));
                }

                orderDetailsFrame.add(scrollPane);
                orderDetailsFrame.setVisible(true);
            }
        } catch (SQLException ex) {
            ex.printStackTrace();
            JOptionPane.showMessageDialog(this, "Failed to load order details: " + ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
        }
    }
}




//CartItem Class
class CartItem {
 private int productId;
 private String name;
 private double price;
 private int quantity;

 public CartItem(int productId, String name, double price, int quantity) {
     this.productId = productId;
     this.name = name;
     this.price = price;
     this.quantity = quantity;
 }

 public int getProductId() {
     return productId;
 }

 public String getName() {
     return name;
 }

 public double getPrice() {
     return price;
 }

 public int getQuantity() {
     return quantity;
 }
}




//Updated PetsFrame with "Go Back" button and ReservationsFrame
class PetsFrame extends JFrame {
 private User user;

 public PetsFrame(User user) {
     this.user = user;

     setTitle("My Pets");
     setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
     setSize(500, 400);
     setLocationRelativeTo(null);

     JPanel buttonPanel = new JPanel();
     buttonPanel.setLayout(new GridLayout(4, 1, 10, 10));

     JButton viewPetsButton = new JButton("View Pets");
     JButton addPetButton = new JButton("Add New Pet");
     JButton viewPetDetailsButton = new JButton("View Pet Details");
     JButton goBackButton = new JButton("Go Back");

     viewPetsButton.addActionListener(e -> viewPets());
     addPetButton.addActionListener(e -> addPet());
     viewPetDetailsButton.addActionListener(e -> viewPetDetails());
     goBackButton.addActionListener(e -> goBack());

     buttonPanel.add(viewPetsButton);
     buttonPanel.add(addPetButton);
     buttonPanel.add(viewPetDetailsButton);
     buttonPanel.add(goBackButton);

     add(buttonPanel, BorderLayout.CENTER);

 }

 private void viewPets() {
     // View pets implementation
     try (Connection conn = DriverManager.getConnection(SwingLoginApp.DB_URL, SwingLoginApp.DB_USER, SwingLoginApp.DB_PASSWORD)) {
         String query = "SELECT * FROM pet WHERE owner_id = ?";
         try (PreparedStatement stmt = conn.prepareStatement(query)) {
             stmt.setInt(1, user.getId());
             ResultSet rs = stmt.executeQuery();

             StringBuilder petsInfo = new StringBuilder("Your Pets:\n");
             while (rs.next()) {
                 petsInfo.append("-- ID: ").append(rs.getInt("id")).append(", ");
                 petsInfo.append("Name: ").append(rs.getString("name")).append(", ");
                 petsInfo.append("Species: ").append(rs.getString("species")).append(", ");
                 petsInfo.append("Breed: ").append(rs.getString("breed")).append(", ");
                 petsInfo.append("Age: ").append(rs.getInt("age")).append(", ");
                 petsInfo.append("Sex: ").append(rs.getString("sex")).append("\n");
             }

             if (petsInfo.length() == 10) {
                 petsInfo.append("You have no pets.");
             }

             JOptionPane.showMessageDialog(this, petsInfo.toString(), "My Pets", JOptionPane.INFORMATION_MESSAGE);
         }
     } catch (SQLException ex) {
         ex.printStackTrace();
         JOptionPane.showMessageDialog(this, "Error fetching pets.", "Error", JOptionPane.ERROR_MESSAGE);
     }
 }

 private void addPet() {
     // Add pet implementation
     int id = Integer.parseInt(JOptionPane.showInputDialog(this, "Enter pet id:"));
     String name = JOptionPane.showInputDialog(this, "Enter pet name:");
     String species = JOptionPane.showInputDialog(this, "Enter pet species:");
     String breed = JOptionPane.showInputDialog(this, "Enter pet breed:");
     int age = Integer.parseInt(JOptionPane.showInputDialog(this, "Enter pet age:"));
     String sex = JOptionPane.showInputDialog(this, "Enter pet sex (M or F):");

     try (Connection conn = DriverManager.getConnection(SwingLoginApp.DB_URL, SwingLoginApp.DB_USER, SwingLoginApp.DB_PASSWORD)) {
         String query = "INSERT INTO pet (id, name, owner_id, species, breed, age, sex) VALUES (?, ?, ?, ?, ?, ?, ?)";
         try (PreparedStatement stmt = conn.prepareStatement(query)) {
             stmt.setInt(1, id);
             stmt.setString(2, name);
             stmt.setInt(3, user.getId());
             stmt.setString(4, species);
             stmt.setString(5, breed);
             stmt.setInt(6, age);
             stmt.setString(7, sex);
             stmt.executeUpdate();

             JOptionPane.showMessageDialog(this, "Pet added successfully!", "Success",
                     JOptionPane.INFORMATION_MESSAGE);
         }
     } catch (SQLException ex) {
         ex.printStackTrace();
         JOptionPane.showMessageDialog(this, "Error adding pet.", "Error", JOptionPane.ERROR_MESSAGE);
     }
 }

 private void viewPetDetails() {
	    try (Connection conn = DriverManager.getConnection(SwingLoginApp.DB_URL, SwingLoginApp.DB_USER, SwingLoginApp.DB_PASSWORD)) {
	        // Query to select pets that have appointments using the view
	        String query = "SELECT distinct name FROM display_pets_with_appointments ";
	        try (PreparedStatement stmt = conn.prepareStatement(query)) {
	           

	            ResultSet rs = stmt.executeQuery();

	            StringBuilder petDetails = new StringBuilder("Pets with Appointments:\n");
	            while (rs.next()) {
	                petDetails.append("Pet Name: ").append(rs.getString("name")).append("\n");
	            }

	            if (petDetails.length() == 26) {  // "Pets with Appointments:\n" length = 26
	                petDetails.append("You have no pets with appointments.");
	            }

	            JOptionPane.showMessageDialog(this, petDetails.toString(), "Pet Details", JOptionPane.INFORMATION_MESSAGE);
	        }
	    } catch (SQLException ex) {
	        ex.printStackTrace();
	        JOptionPane.showMessageDialog(this, "Error fetching pet details.", "Error", JOptionPane.ERROR_MESSAGE);
	    }
}



 


 private void goBack() {
     // Go back to homepage
     new HomepageFrame(user).setVisible(true);;
     dispose();
 }
}

//ReservationsFrame Class


// AppointmentFrame class to handle pet appointments
class AppointmentFrame extends JFrame {
    private User user;
    private JComboBox<String> petComboBox;
    private JComboBox<String> appointmentTypeComboBox;
    private JSpinner dateSpinner;
    private DefaultListModel<String> appointmentListModel;

    public AppointmentFrame(User user) {
        this.user = user;

        setTitle("Make an Appointment");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(500, 400);
        setLocationRelativeTo(null);

        JPanel formPanel = new JPanel(new GridLayout(4, 2, 10, 10));

        // Fetch pets and appointment types from the database
        petComboBox = new JComboBox<>(fetchPetsFromDatabase());
        appointmentTypeComboBox = new JComboBox<>(fetchAppointmentTypesFromDatabase());

        JLabel petLabel = new JLabel("Select Pet:");
        JLabel appointmentTypeLabel = new JLabel("Select Appointment Type:");
        JLabel dateLabel = new JLabel("Select Date:");

        dateSpinner = new JSpinner(new SpinnerDateModel());
        JSpinner.DateEditor dateEditor = new JSpinner.DateEditor(dateSpinner, "yyyy-MM-dd");
        dateSpinner.setEditor(dateEditor);

        JButton makeAppointmentButton = new JButton("Make Appointment");
        makeAppointmentButton.addActionListener(e -> makeAppointment());

        JButton viewAppointmentsButton = new JButton("View Appointments");
        viewAppointmentsButton.addActionListener(e -> viewAppointments());

        JButton backButton = new JButton("Back to Homepage");
        backButton.addActionListener(e -> {
            dispose();
            new HomepageFrame(user).setVisible(true);
        });

        formPanel.add(petLabel);
        formPanel.add(petComboBox);
        formPanel.add(appointmentTypeLabel);
        formPanel.add(appointmentTypeComboBox);
        formPanel.add(dateLabel);
        formPanel.add(dateSpinner);
        formPanel.add(makeAppointmentButton);
        formPanel.add(viewAppointmentsButton);

        add(formPanel, BorderLayout.CENTER);
        add(backButton, BorderLayout.SOUTH);
    }

    private String[] fetchPetsFromDatabase() {
        ArrayList<String> pets = new ArrayList<>();
        try (Connection conn = DriverManager.getConnection(SwingLoginApp.DB_URL, SwingLoginApp.DB_USER, SwingLoginApp.DB_PASSWORD)) {
            String query = "SELECT id FROM pet WHERE owner_id = ?";
            try (PreparedStatement stmt = conn.prepareStatement(query)) {
                stmt.setInt(1, user.getId());
                ResultSet rs = stmt.executeQuery();
                while (rs.next()) {
                    pets.add(rs.getString("id"));
                }
            }
        } catch (SQLException ex) {
            ex.printStackTrace();
            JOptionPane.showMessageDialog(this, "Failed to fetch pets from database.", "Error", JOptionPane.ERROR_MESSAGE);
        }
        return pets.toArray(new String[0]);
    }

    private String[] fetchAppointmentTypesFromDatabase() {
        ArrayList<String> appointmentTypes = new ArrayList<>();
        appointmentTypes.add("Vaccination");
        appointmentTypes.add("Check-up");

        return appointmentTypes.toArray(new String[0]);
    }

    private void makeAppointment() {
        String selectedPet = (String) petComboBox.getSelectedItem();
        String selectedAppointmentType = (String) appointmentTypeComboBox.getSelectedItem();
        java.util.Date selectedDate = (java.util.Date) dateSpinner.getValue();
        java.sql.Date sqlDate = new java.sql.Date(selectedDate.getTime());

        try (Connection conn = DriverManager.getConnection(SwingLoginApp.DB_URL, SwingLoginApp.DB_USER, SwingLoginApp.DB_PASSWORD)) {
            // Query to insert the appointment with sequence-generated appointment_id
            String query = "INSERT INTO appointment (appointment_id, owner_id, pet_id, type, op_date) VALUES (nextval('appointment_seq'), ?, ?, ?, ?)";
            try (PreparedStatement stmt = conn.prepareStatement(query)) {
                stmt.setInt(1, user.getId()); // owner_id
                stmt.setInt(2, Integer.parseInt(selectedPet)); // pet_id

                stmt.setString(3, selectedAppointmentType); // type
                stmt.setDate(4, sqlDate); // op_date
                stmt.executeUpdate();
                JOptionPane.showMessageDialog(this, "Appointment made successfully!", "Success", JOptionPane.INFORMATION_MESSAGE);
            }
        } catch (SQLException ex) {
            ex.printStackTrace();
            JOptionPane.showMessageDialog(this, "Failed to make appointment.", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }


    private void viewAppointments() {
        JFrame viewFrame = new JFrame("Your Appointments");
        viewFrame.setSize(500, 300);
        viewFrame.setLocationRelativeTo(null);

        appointmentListModel = new DefaultListModel<>();
        JList<String> appointmentList = new JList<>(appointmentListModel);
        fetchAppointmentsFromDatabase();

        JButton closeButton = new JButton("Close");
        closeButton.addActionListener(e -> viewFrame.dispose());

        viewFrame.add(new JScrollPane(appointmentList), BorderLayout.CENTER);
        viewFrame.add(closeButton, BorderLayout.SOUTH);
        viewFrame.setVisible(true);
    }

    private void fetchAppointmentsFromDatabase() {
        appointmentListModel.clear();
        try (Connection conn = DriverManager.getConnection(SwingLoginApp.DB_URL, SwingLoginApp.DB_USER, SwingLoginApp.DB_PASSWORD)) {
            String query = "SELECT pet_id, type, op_date FROM appointment WHERE owner_id = ?";
            try (PreparedStatement stmt = conn.prepareStatement(query)) {
                stmt.setInt(1, user.getId());
                ResultSet rs = stmt.executeQuery();
                while (rs.next()) {
                	int petId = rs.getInt("pet_id");
                    String appointmentType = rs.getString("type");
                    String appointmentDate = rs.getDate("op_date").toString();
                    appointmentListModel.addElement(" --Id: " + petId +  " --Type: " + appointmentType + " --Date: " + appointmentDate);
                }
            }
        } catch (SQLException ex) {
            ex.printStackTrace();
            JOptionPane.showMessageDialog(this, "Failed to fetch appointments from database.", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }
}
