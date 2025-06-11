package yazilim;

import java.awt.EventQueue;
import java.awt.Font;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JSpinner;
import javax.swing.SpinnerNumberModel;
import yazilim.classes.Vehicle;
import yazilim.classes.VehicleStock;
import yazilim.classes.Warehouse;
import java.awt.event.ActionListener;
import java.math.BigDecimal;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.awt.event.ActionEvent;

public class UpdateStockPage {
	private JFrame frame;
	private static Connection conn;
	private Warehouse warehouse;
	private JComboBox<String> vehicleSelector;
	private ArrayList<VehicleStock> vehicleStockList = new ArrayList<>();
	private ArrayList<Vehicle> vehicles = new ArrayList<>();
	private ArrayList<Integer> vehicleIdMap = new ArrayList<>();
	
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/YazilimMuhProje", "postgres", "12345");
					UpdateStockPage window = new UpdateStockPage(new Warehouse(), conn);
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
	
	public UpdateStockPage() throws SQLException {
		conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/YazilimMuhProje", "postgres", "12345");
		warehouse = new Warehouse();
		initialize();
	}

	/**
	 * Create the application.
	 */
	public UpdateStockPage(Warehouse wrhs, Connection parent_conn) {
		warehouse = wrhs;
		conn = parent_conn;
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
	    frame = new JFrame();
	    frame.setTitle("Stok Güncelleme Sayfası");
	    frame.setBounds(100, 100, 475, 230);
	    frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
	    frame.getContentPane().setLayout(null);

	    vehicleStockList = getVehicleStock();
	    vehicles = getVehicles();

	    vehicleSelector = new JComboBox<>();
	    vehicleSelector.setBounds(50, 30, 380, 30);
	    frame.getContentPane().add(vehicleSelector);

	    // Araçları listeye doldur
	    vehicleIdMap = new ArrayList<>();
	    for (VehicleStock vs : vehicleStockList) {
	        for (Vehicle v : vehicles) {
	            if (v.getVehicleId() == vs.getVehicleId()) {
	                String item = String.format("%s / %s / %d / %s / %.2f TL / Stok: %d",
	                    v.getBrand(),
	                    v.getModel(),
	                    v.getYear(),
	                    v.getPckg(),
	                    v.getPrice(),
	                    vs.getStock());
	                vehicleSelector.addItem(item);
	                vehicleIdMap.add(v.getVehicleId()); // index -> vehicle_id eşlemesi
	                break;
	            }
	        }
	    }
	    
	    JLabel quantityLabel = new JLabel("Adet:");
	    quantityLabel.setFont(new Font("Tahoma", Font.BOLD, 14));
	    quantityLabel.setBounds(20, 80, 50, 30);
	    frame.getContentPane().add(quantityLabel);

	    JSpinner quantitySpinner = new JSpinner(new SpinnerNumberModel(1, 1, 100, 1));
	    quantitySpinner.setBounds(70, 80, 60, 30);
	    frame.getContentPane().add(quantitySpinner);


	    JButton addToStockButton = new JButton("Stoğa Ekle");
	    addToStockButton.setFont(new Font("Tahoma", Font.BOLD, 16));
	    addToStockButton.setBounds(135, 80, 150, 30);
	    frame.getContentPane().add(addToStockButton);
	    addToStockButton.setFocusable(false);

	    addToStockButton.addActionListener(new ActionListener() {
	        public void actionPerformed(ActionEvent e) {
	            int selectedIndex = vehicleSelector.getSelectedIndex();
	            if (selectedIndex != -1) {
	            	int quantity = (int) quantitySpinner.getValue();
	                int vehicleId = vehicleIdMap.get(selectedIndex);
	                PreparedStatement updateWarehouseStmt;
					try {
						updateWarehouseStmt = conn.prepareStatement("UPDATE stock SET quantity = quantity + ? WHERE vehicle_id = ? AND location_type = 'warehouse'");
						updateWarehouseStmt.setInt(1, quantity);
                        updateWarehouseStmt.setInt(2, vehicleId);
                        updateWarehouseStmt.executeUpdate();
                        reloadVehicleData();
					} catch (SQLException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}  
	            }
	        }
	    });
	    
	    JButton removeFromStockButton = new JButton("Stoktan Çıkar");
	    removeFromStockButton.setFont(new Font("Tahoma", Font.BOLD, 16));
	    removeFromStockButton.setBounds(290, 80, 150, 30);
	    frame.getContentPane().add(removeFromStockButton);
	    removeFromStockButton.setFocusable(false);

	    removeFromStockButton.addActionListener(new ActionListener() {
	        public void actionPerformed(ActionEvent e) {
	            int selectedIndex = vehicleSelector.getSelectedIndex();
	            if (selectedIndex != -1) {
	            	int quantity = (int) quantitySpinner.getValue();
	                int vehicleId = vehicleIdMap.get(selectedIndex);
	                int availableStock = 0;
	                for (VehicleStock vs : vehicleStockList) {
	                    if (vs.getVehicleId() == vehicleId) {
	                        availableStock = vs.getStock();
	                        break;
	                    }
	                }

	                if (quantity > availableStock) {
	                	JOptionPane.showMessageDialog(null, "Stok yetersiz.");
	                }
	                else {
	                	PreparedStatement updateWarehouseStmt;
						try {
							updateWarehouseStmt = conn.prepareStatement("UPDATE stock SET quantity = quantity - ? WHERE vehicle_id = ? AND location_type = 'warehouse'");
							updateWarehouseStmt.setInt(1, quantity);
	                        updateWarehouseStmt.setInt(2, vehicleId);
	                        updateWarehouseStmt.executeUpdate();
	                        reloadVehicleData();
						} catch (SQLException e1) {
							// TODO Auto-generated catch block
							e1.printStackTrace();
						}  
	                }
	            }
	        }
	    });



	    JButton returnButton = new JButton("Geri");
	    returnButton.addActionListener(new ActionListener() {
	        public void actionPerformed(ActionEvent e) {
	            frame.setVisible(false);
	        }
	    });
	    returnButton.setFont(new Font("Tahoma", Font.BOLD, 18));
	    returnButton.setBounds(170, 140, 100, 30);
	    frame.getContentPane().add(returnButton);
	    returnButton.setFocusable(false);
	    
	    frame.setVisible(true);
	}
	
	public int pullVehicleToDealerFromWarehouse(int vehicleId, int quantity) {
		 int availableStock = 0;
         for (VehicleStock vs : vehicleStockList) {
             if (vs.getVehicleId() == vehicleId) {
                 availableStock = vs.getStock();
                 break;
             }
         }

         if (quantity > availableStock) {
             return -1;
         }
		
		
        try {
            PreparedStatement updateWarehouseStmt = conn.prepareStatement(
                "UPDATE stock SET quantity = quantity - ? WHERE vehicle_id = ? AND location_type = 'warehouse'"
            );
            updateWarehouseStmt.setInt(1, quantity);
            updateWarehouseStmt.setInt(2, vehicleId);
            int rowsAffected = updateWarehouseStmt.executeUpdate();

            if (rowsAffected > 0) {
                PreparedStatement checkWarehouseStmt = conn.prepareStatement(
                    "SELECT quantity FROM stock WHERE vehicle_id = ? AND location_type = 'warehouse'"
                );
                checkWarehouseStmt.setInt(1, vehicleId);
                ResultSet rsWarehouse = checkWarehouseStmt.executeQuery();

                if (rsWarehouse.next()) {
                    int warehouseQuantity = rsWarehouse.getInt("quantity");
                    if (warehouseQuantity == 0) {
                        PreparedStatement deleteWarehouseStmt = conn.prepareStatement(
                            "DELETE FROM stock WHERE vehicle_id = ? AND location_type = 'warehouse'"
                        );
                        deleteWarehouseStmt.setInt(1, vehicleId);
                        deleteWarehouseStmt.executeUpdate();
                    }
                }

                PreparedStatement checkStmt = conn.prepareStatement(
                    "SELECT * FROM stock WHERE vehicle_id = ? AND location_type = 'dealer'"
                );
                checkStmt.setInt(1, vehicleId);
                ResultSet rs = checkStmt.executeQuery();

                if (rs.next()) {
                    PreparedStatement updateDealerStmt = conn.prepareStatement(
                        "UPDATE stock SET quantity = quantity + ? WHERE vehicle_id = ? AND location_type = 'dealer'"
                    );
                    updateDealerStmt.setInt(1, quantity);
                    updateDealerStmt.setInt(2, vehicleId);
                    updateDealerStmt.executeUpdate();
                    return 1;
                } 
                else {
                    PreparedStatement insertDealerStmt = conn.prepareStatement(
                        "INSERT INTO stock (vehicle_id, location_type, quantity) VALUES (?, 'dealer', ?)"
                    );
                    insertDealerStmt.setInt(1, vehicleId);
                    insertDealerStmt.setInt(2, quantity);
                    insertDealerStmt.executeUpdate();
                    return 1;
                }
            } else {
            	return 0;
            }
        } catch (SQLException ex) {
        	return 0;
        }
	}

	private void reloadVehicleData() {
		vehicleStockList = getVehicleStock();
	    vehicles = getVehicles();
	    vehicleSelector.removeAllItems();
	    vehicleIdMap.removeAll(vehicleIdMap);
	    for (VehicleStock vs : vehicleStockList) {
	        for (Vehicle v : vehicles) {
	            if (v.getVehicleId() == vs.getVehicleId()) {
	                String item = String.format("%s / %s / %d / %s / %.2f TL / Stok: %d",
	                    v.getBrand(),
	                    v.getModel(),
	                    v.getYear(),
	                    v.getPckg(),
	                    v.getPrice(),
	                    vs.getStock());
	                vehicleIdMap.add(v.getVehicleId()); // index -> vehicle_id eşlemesi
	                vehicleSelector.addItem(item);
	                break;
	            }
	        }
	    }
	}
	
	public ArrayList<VehicleStock> getVehicleStock() {
	    ArrayList<VehicleStock> vehicleStockList = new ArrayList<>();

	    String query = "SELECT vehicle_id, quantity FROM stock WHERE location_type = 'warehouse'";

	    try {
	        PreparedStatement ps = conn.prepareStatement(query);
	        ResultSet rs = ps.executeQuery();

	        while (rs.next()) {
	            int vehicleId = rs.getInt("vehicle_id");
	            int quantity = rs.getInt("quantity");

	            vehicleStockList.add(new VehicleStock(vehicleId, quantity));
	        }

	        rs.close();
	        ps.close();
	    } catch (SQLException e) {
	        e.printStackTrace();
	    }

	    return vehicleStockList;
	}

	
	public ArrayList<Vehicle> getVehicles() {
		ArrayList<Vehicle> vehicles = new ArrayList<>();

	    String query = "SELECT v.vehicle_id, v.brand, v.model, v.year, v.package, v.price " +
	                   "FROM vehicle v " +
	                   "JOIN stock s ON v.vehicle_id = s.vehicle_id " +
	                   "WHERE s.location_type = 'warehouse'";

	    try {
	        PreparedStatement ps = conn.prepareStatement(query);
	        ResultSet rs = ps.executeQuery();

	        while (rs.next()) {
	            int vehicleId = rs.getInt("vehicle_id");
	            String brand = rs.getString("brand");
	            String model = rs.getString("model");
	            int year = rs.getInt("year");
	            String pckg = rs.getString("package");
	            BigDecimal price = rs.getBigDecimal("price");

	            Vehicle vehicle = new Vehicle(vehicleId, brand, model, year, pckg, price);
	            vehicles.add(vehicle);
	        }

	        rs.close();
	        ps.close();
	    } catch (SQLException e) {
	        e.printStackTrace();
	    }

	    return vehicles;
	}

	public void showFrame() {
		frame.setVisible(true);
	}
}