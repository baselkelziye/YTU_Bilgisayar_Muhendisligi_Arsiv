package yazilim;

import java.awt.Color;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.Connection;
import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.HashMap;
import java.util.Map;
import org.jfree.chart.ChartFactory;
import org.jfree.chart.ChartPanel;
import org.jfree.chart.JFreeChart;
import org.jfree.data.general.DefaultPieDataset;
import java.math.BigDecimal;
import java.math.RoundingMode;
import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.SwingConstants;
import javax.swing.border.TitledBorder;
import javax.swing.table.TableColumn;
import org.jfree.chart.plot.PiePlot;
import org.jfree.chart.labels.StandardPieSectionLabelGenerator;
import java.text.DecimalFormat;
import yazilim.classes.SaleRecord;
import yazilim.classes.Vehicle;
import yazilim.classes.Dealer;

public class ReportPage {
    private JFrame frame;
    private static Connection conn;
    private Dealer dealer;
    private ChartPanel countChartPanel;
    private ChartPanel priceChartPanel;
    private JScrollPane saleHistoryScrollPane;
    private JPanel forecastsPanel;
    private JLabel totalLabel;
    private int reportAgainstOthersVehicleId = -1;
    private int saleHistoryVehicleId = -1;
    private int saleGuessVehicleId = -1;

    /**
     * Launch the application.
     */
    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            public void run() {
                try {
                    conn = java.sql.DriverManager.getConnection("jdbc:postgresql://localhost:5432/YazilimMuhProje", "postgres", "12345");
                    ReportPage window = new ReportPage(new Dealer(), conn);
                    window.frame.setVisible(true);
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        });
    }

    public ReportPage() throws SQLException {
        conn = java.sql.DriverManager.getConnection("jdbc:postgresql://localhost:5432/YazilimMuhProje", "postgres", "12345");
        dealer = new Dealer();
        initialize();
    }

    public ReportPage(Dealer dlr, Connection parent_conn) {
        dealer = dlr;
        conn = parent_conn;
        initialize();
    }

    private void initialize() {
        frame = new JFrame();
        frame.setTitle("Rapor Sayfası");
        frame.setBounds(100, 100, 1200, 600);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.getContentPane().setLayout(null);
        
        ArrayList<Vehicle> vehicleList = getAllVehicles();
        Map<Integer, Integer> indexToVehicleIdMap = new HashMap<>();
        JComboBox<String> vehicleSelector = new JComboBox<>();
        vehicleSelector.setBounds(450, 30, 300, 30);
        vehicleSelector.setFont(new Font("Tahoma", Font.PLAIN, 14));
        int index = 0;
        vehicleSelector.addItem("Tüm Araçlar");
        indexToVehicleIdMap.put(index, 0);
        index++;
        for (Vehicle v : vehicleList) {
            String displayText = String.format("%s / %s / %d / %s", v.getBrand(), v.getModel(), v.getYear(), v.getPckg());
            vehicleSelector.addItem(displayText);
            indexToVehicleIdMap.put(index, v.getVehicleId());
            index++;
        }
        frame.getContentPane().add(vehicleSelector);

        JButton reportAgainstOthersButton = new JButton("Diğer Araçlar İle Karşılaştır");
        reportAgainstOthersButton.setBounds(250, 80, 200, 30);
        frame.getContentPane().add(reportAgainstOthersButton);
        reportAgainstOthersButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            	clear("report-against-others");
            	int selectedIndex = vehicleSelector.getSelectedIndex();
                if (selectedIndex != -1) {
                    int vehicleId = indexToVehicleIdMap.get(selectedIndex);
                    if(vehicleId == 0) {  // Tüm araçlar işlemi
                    	clearReportAgainstOthersCharts();
                    	reportAgainstOthersVehicleId = 0;
                    	JOptionPane.showMessageDialog(null, "Bu özelliği kullanmak için belli bir araç seçiniz.");
                    }
                    else if(reportAgainstOthersVehicleId != vehicleId) {
                    	clearReportAgainstOthersCharts();
                        reportAgainstOthersVehicleId = vehicleId;
                        try {
                            // Seçilen aracın satış adedi
                            PreparedStatement selectedCountStmt = conn.prepareStatement(
                                "SELECT COUNT(*) FROM sales WHERE vehicle_id = ?"
                            );
                            selectedCountStmt.setInt(1, vehicleId);
                            ResultSet selectedCountRs = selectedCountStmt.executeQuery();
                            int selectedCount = selectedCountRs.next() ? selectedCountRs.getInt(1) : 0;

                            // Diğer araçların satış adedi
                            PreparedStatement otherCountStmt = conn.prepareStatement(
                                "SELECT COUNT(*) FROM sales WHERE vehicle_id != ?"
                            );
                            otherCountStmt.setInt(1, vehicleId);
                            ResultSet otherCountRs = otherCountStmt.executeQuery();
                            int otherCount = otherCountRs.next() ? otherCountRs.getInt(1) : 0;

                            // Seçilen aracın satış fiyat toplamı
                            PreparedStatement selectedPriceStmt = conn.prepareStatement(
                                "SELECT SUM(sale_price) FROM sales WHERE vehicle_id = ?"
                            );
                            selectedPriceStmt.setInt(1, vehicleId);
                            ResultSet selectedPriceRs = selectedPriceStmt.executeQuery();
                            double selectedTotalPrice = selectedPriceRs.next() ? selectedPriceRs.getDouble(1) : 0;

                            // Diğer araçların satış fiyat toplamı
                            PreparedStatement otherPriceStmt = conn.prepareStatement(
                                "SELECT SUM(sale_price) FROM sales WHERE vehicle_id != ?"
                            );
                            otherPriceStmt.setInt(1, vehicleId);
                            ResultSet otherPriceRs = otherPriceStmt.executeQuery();
                            double otherTotalPrice = otherPriceRs.next() ? otherPriceRs.getDouble(1) : 0;

                            // İlk pie chart: adet bazlı satış dağılımı
                            DefaultPieDataset countDataset = new DefaultPieDataset();
                            countDataset.setValue("Seçilen Araç", selectedCount);
                            countDataset.setValue("Diğer Araçlar", otherCount);
                            JFreeChart countChart = ChartFactory.createPieChart("Satış Adedi Dağılımı", countDataset, true, true, false);
                            // Yüzde dilimlerini göster
                            PiePlot countPlot = (PiePlot) countChart.getPlot();
                            countPlot.setLabelGenerator(new StandardPieSectionLabelGenerator(
                                "{0}: {1} adet ({2})", new DecimalFormat("0"), new DecimalFormat("0.0%")));
                            countChartPanel = new ChartPanel(countChart);
                            countChartPanel.setBounds(150, 150, 400, 300);
                            frame.getContentPane().add(countChartPanel);

                            // İkinci pie chart: fiyat bazlı satış dağılımı
                            DefaultPieDataset priceDataset = new DefaultPieDataset();
                            priceDataset.setValue("Seçilen Araç", selectedTotalPrice);
                            priceDataset.setValue("Diğer Araçlar", otherTotalPrice);
                            JFreeChart priceChart = ChartFactory.createPieChart("Satış Fiyatı Dağılımı", priceDataset, true, true, false);
                            // Yüzde dilimlerini göster
                            PiePlot pricePlot = (PiePlot) priceChart.getPlot();
                            pricePlot.setLabelGenerator(new StandardPieSectionLabelGenerator(
                                "{0}: {1}₺ ({2})", new DecimalFormat("#,##0.00"), new DecimalFormat("0.0%")));
                            priceChartPanel = new ChartPanel(priceChart);
                            priceChartPanel.setBounds(650, 150, 400, 300);
                            frame.getContentPane().add(priceChartPanel);
                        } catch (SQLException ex) {
                            ex.printStackTrace();
                        }
                    }
                    
                } else {
                    JOptionPane.showMessageDialog(frame, "Lütfen bir araç seçin.");
                }
            }
        });
        
        JButton saleHistortyButton = new JButton("Satış Geçmişi");
        saleHistortyButton.setBounds(500, 80, 200, 30);
        frame.getContentPane().add(saleHistortyButton);
        saleHistortyButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            	clear("sale-history");
            	int selectedIndex = vehicleSelector.getSelectedIndex();
                if (selectedIndex != -1) {
                    int vehicleId = indexToVehicleIdMap.get(selectedIndex);
                    if(vehicleId == 0) {  // Tüm araçlar işlemi
                    	clearSaleHistoryScrollPane();
                    	saleHistoryVehicleId = 0;
						try {
							PreparedStatement stmt = conn.prepareStatement("SELECT user_id, vehicle_id, sale_date, sale_price FROM sales ORDER BY sale_date DESC;");
							ResultSet rs = stmt.executeQuery();
							showSaleHistoryData(rs);
						} catch (SQLException e1) {
							// TODO Auto-generated catch block
							e1.printStackTrace();
						}
                    }
                    else if(saleHistoryVehicleId != vehicleId) {
                    	clearSaleHistoryScrollPane();
                    	saleHistoryVehicleId = vehicleId;

                    	try {
                    		PreparedStatement stmt = conn.prepareStatement("SELECT user_id, vehicle_id, sale_date, sale_price FROM sales WHERE vehicle_id = ? ORDER BY sale_date DESC;");
                    	    stmt.setInt(1, vehicleId);
                    	    ResultSet rs = stmt.executeQuery();
                    	    showSaleHistoryData(rs);
                    	} catch (SQLException ex) {
                    	    ex.printStackTrace();
                    	}
                    }
                } else {
                    JOptionPane.showMessageDialog(frame, "Lütfen bir araç seçin.");
                }
            }
        });

        JButton forecastButton = new JButton("Satış Tahmini (3 yıl)");
        forecastButton.setBounds(750, 80, 200, 30);
        frame.getContentPane().add(forecastButton);
        forecastButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
            	clear("sale-guess");
            	ArrayList<SaleRecord> saleRecords = new ArrayList<>();
            	int selectedIndex = vehicleSelector.getSelectedIndex();
                if (selectedIndex != -1) {
                    int vehicleId = indexToVehicleIdMap.get(selectedIndex);
                    if(vehicleId == 0) {  // Tüm araçlar işlemi
                    	clearSaleGuess();
                    	saleGuessVehicleId = 0;
                    	try {
                    		Date currentPeriodEnd = getCurrentPeriodEndDate();
							Date fifthBeforePeriodStartDate = getFifthBeforePeriodStartDate(currentPeriodEnd);
							
							PreparedStatement stmt = conn.prepareStatement("SELECT vehicle_id, sale_price FROM sales WHERE sale_date >= ? AND sale_date <= ? ORDER BY sale_date DESC;");
							stmt.setDate(1, fifthBeforePeriodStartDate);
							stmt.setDate(2, currentPeriodEnd);
							ResultSet rs = stmt.executeQuery();
							while (rs.next()) {
						        int vhcId = rs.getInt("vehicle_id");
						        BigDecimal salePrice = rs.getBigDecimal("sale_price");
						        SaleRecord record = new SaleRecord(vhcId, salePrice);
						        saleRecords.add(record);
						    }
							
							int saleCountForecast = getSaleCountForecast(saleRecords);
							BigDecimal saleReturnForecast = getSaleReturnForecast(saleRecords);
							populateForecastPanel(saleCountForecast, saleReturnForecast, saleRecords.size());
						} catch (SQLException e1) {
							// TODO Auto-generated catch block
							e1.printStackTrace();
						}
                    }
                    else if(saleGuessVehicleId != vehicleId) {
                    	clearSaleGuess();
                    	saleGuessVehicleId = 0;
                    	
                    	try {
                    		Date currentPeriodStart = getCurrentPeriodEndDate();
							Date fifthBeforePeriodStartDate = getFifthBeforePeriodStartDate(currentPeriodStart);
							
							PreparedStatement stmt = conn.prepareStatement("SELECT sale_price FROM sales WHERE vehicle_id = ? AND sale_date >= ? AND sale_date < ? ORDER BY sale_date DESC;");
							stmt.setInt(1, vehicleId);
							stmt.setDate(2, fifthBeforePeriodStartDate);
							stmt.setDate(3, currentPeriodStart);
							ResultSet rs = stmt.executeQuery();
							while (rs.next()) {
						        int vhcId = vehicleId;
						        BigDecimal salePrice = rs.getBigDecimal("sale_price");
						        SaleRecord record = new SaleRecord(vhcId, salePrice);
						        saleRecords.add(record);
						    }
							
							int saleCountForecast = getSaleCountForecast(saleRecords);
							BigDecimal saleReturnForecast = getSaleReturnForecast(saleRecords);
							populateForecastPanel(saleCountForecast, saleReturnForecast, saleRecords.size());
						} catch (SQLException e1) {
							// TODO Auto-generated catch block
							e1.printStackTrace();
						}
                    }
                } else {
                    JOptionPane.showMessageDialog(frame, "Lütfen bir araç seçin.");
                }
            }
        });
        
        frame.setVisible(true);
    }
    
    private int getSaleCountForecast(ArrayList<SaleRecord> saleRecords) {
    	if(saleRecords.size() % 5 >= 3) {
    		return saleRecords.size() / 5 + 1;
    	}
    	
    	return saleRecords.size() / 5;
    }
    
    private BigDecimal getSaleReturnForecast(ArrayList<SaleRecord> saleRecords) {
    	BigDecimal total = new BigDecimal("0.00");
    	for (SaleRecord saleRecord : saleRecords) {
    	    total = total.add(saleRecord.getSalePrice());
    	}
    	
    	BigDecimal divisor = new BigDecimal("5");
    	return total.divide(divisor, 2, RoundingMode.HALF_UP);
    }
    
    private void clear(String caller) {
    	if(caller.equals("report-against-others")) {
    		clearSaleHistoryScrollPane();
    		saleHistoryVehicleId = -1;
    		clearSaleGuess();
    		saleGuessVehicleId = -1;
    	}
    	else if(caller.equals("sale-history")) {
    		clearReportAgainstOthersCharts();
    		reportAgainstOthersVehicleId = -1;
    		clearSaleGuess();
    		saleGuessVehicleId = -1;
    	}
    	else if(caller.equals("sale-guess")) {
    		clearReportAgainstOthersCharts();
    		reportAgainstOthersVehicleId = -1;
    		clearSaleHistoryScrollPane();
    		saleHistoryVehicleId = -1;
    	}

    	frame.revalidate();
        frame.repaint();
    }
    
    private void clearReportAgainstOthersCharts() {
    	if (countChartPanel != null) {
            frame.getContentPane().remove(countChartPanel);
            countChartPanel = null;
        }
        if (priceChartPanel != null) {
            frame.getContentPane().remove(priceChartPanel);
            priceChartPanel = null;
        }
    }
    
    private void clearSaleHistoryScrollPane() {
    	if (saleHistoryScrollPane != null) {
            frame.getContentPane().remove(saleHistoryScrollPane);
            saleHistoryScrollPane = null;
        }
    	if (totalLabel != null) {
            frame.getContentPane().remove(totalLabel);
            totalLabel = null;
        }
    }
    
    private void clearSaleGuess() {
    	if (forecastsPanel != null) {
            frame.getContentPane().remove(forecastsPanel);
            forecastsPanel = null;
        }
    }
    
    private ArrayList<Vehicle> getAllVehicles() {
        ArrayList<Vehicle> vehicleList = new ArrayList<>();
        try {
            PreparedStatement stmt = conn.prepareStatement("SELECT * FROM vehicle");
            ResultSet rs = stmt.executeQuery();
            while (rs.next()) {
                vehicleList.add(new Vehicle(
                    rs.getInt("vehicle_id"),
                    rs.getString("brand"),
                    rs.getString("model"),
                    rs.getInt("year"),
                    rs.getString("package"),
                    rs.getBigDecimal("price")
                ));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return vehicleList;
    }
    
    private void showSaleHistoryData(ResultSet rs) {
    	String[] columnNames = {"#", "Müşteri", "Araç", "Satış Tarihi", "Satış Fiyatı", "Dönem"};
	    ArrayList<Object[]> rowData = new ArrayList<>();
	    int counter = 1;
	    double totalSalePrice = 0.00;
	    try {
			while (rs.next()) {
			    int userId = rs.getInt("user_id");
			    int vehicleId = rs.getInt("vehicle_id");
			    Date saleDate = rs.getDate("sale_date");
			    double salePrice = rs.getDouble("sale_price");
			    totalSalePrice += salePrice;

			    Calendar cal = Calendar.getInstance();
			    cal.setTime(saleDate);
			    int year = cal.get(Calendar.YEAR);
			    int month = cal.get(Calendar.MONTH) + 1;
			    int period = (month - 1) / 3 + 1;
			    String periodText = String.format("%d - %d. Dönem", year, period);
			    String fullName = getCustomerFullName(userId);
			    String carInfo = getCarInfo(vehicleId);
			    
			    rowData.add(new Object[]{counter, fullName, carInfo, saleDate.toString(), String.format("%.2f₺", salePrice), periodText});
			    counter++;
			}
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	    Object[][] data = rowData.toArray(new Object[0][]);

	    JTable table = new JTable(data, columnNames);
	    TableColumn countColumn = table.getColumnModel().getColumn(0);
	    countColumn.setMinWidth(20);
	    countColumn.setMaxWidth(20);
	    countColumn.setPreferredWidth(20);
	    
	    totalLabel = new JLabel(String.format("Toplam Satış: %.2f₺", totalSalePrice));
	    totalLabel.setFont(new Font("Arial", Font.BOLD, 14));
	    totalLabel.setBounds(500, 120, 300, 25);
	    
	    saleHistoryScrollPane = new JScrollPane(table);
	    saleHistoryScrollPane.setBounds(150, 150, 900, 300);

	    frame.getContentPane().add(totalLabel);
	    frame.getContentPane().add(saleHistoryScrollPane);
    }
    
    private void populateForecastPanel(int saleCountForecast, BigDecimal saleReturnForecast, int dataCount){
    	forecastsPanel = new JPanel();
		forecastsPanel.setLayout(new GridLayout(3, 1, 5, 5));
		forecastsPanel.setBounds(350, 150, 500, 200);
		forecastsPanel.setBorder(BorderFactory.createTitledBorder(
	        BorderFactory.createLineBorder(Color.BLACK),
	        "Gelecek Dönem İçin Satış Tahmini Sonuçları",
	        TitledBorder.CENTER,
	        TitledBorder.TOP,
	        new Font("Tahoma", Font.BOLD, 14)
	    ));

		JLabel forecastCountLabel = new JLabel("Satış Adedi: " + saleCountForecast);
		forecastCountLabel.setFont(new Font("Tahoma", Font.PLAIN, 14));
		forecastCountLabel.setHorizontalAlignment(SwingConstants.CENTER);

	    JLabel forecastReturnLabel = new JLabel("Satış Getirisi: " + saleReturnForecast + "₺");
	    forecastReturnLabel.setFont(new Font("Tahoma", Font.PLAIN, 14));
	    forecastReturnLabel.setHorizontalAlignment(SwingConstants.CENTER);
	    
	    JLabel forecastDateCountLabel = new JLabel("Tahmin İçin Kulanılan Veri Sayısı: " + dataCount);
	    forecastDateCountLabel.setFont(new Font("Tahoma", Font.PLAIN, 14));
	    forecastDateCountLabel.setHorizontalAlignment(SwingConstants.CENTER);

	    forecastsPanel.add(forecastCountLabel);
	    forecastsPanel.add(forecastReturnLabel);
	    forecastsPanel.add(forecastDateCountLabel);
	    frame.getContentPane().add(forecastsPanel);
	    frame.revalidate();
	    frame.repaint();
    }
    
    private String getCustomerFullName(int customerId) {
        try {
            PreparedStatement stmt = conn.prepareStatement("SELECT first_name, last_name FROM customer WHERE customer_id = ?");
            stmt.setInt(1, customerId);
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                return rs.getString("first_name") + " " + rs.getString("last_name");
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return "Bilinmeyen Kullanıcı";
    }
    
    private String getCarInfo(int vehicleId) {
        try {
            PreparedStatement stmt = conn.prepareStatement("SELECT brand, model, year, package FROM vehicle WHERE vehicle_id = ?");
            stmt.setInt(1, vehicleId);
            ResultSet rs = stmt.executeQuery();
            if (rs.next()) {
                return rs.getString("brand") + " / " + rs.getString("model") + " / " + rs.getInt("year") + " / " + rs.getString("package");
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return "Bilinmeyen Kullanıcı";
    }
    
    public static Date getCurrentPeriodEndDate() {
        Calendar cal = Calendar.getInstance();

        int currentMonth = cal.get(Calendar.MONTH);
        int startMonth = (currentMonth / 3) * 3;

        int nextPeriodMonth = startMonth + 3;

        cal.set(Calendar.MONTH, nextPeriodMonth);
        cal.set(Calendar.DAY_OF_MONTH, 1);

        cal.add(Calendar.DAY_OF_MONTH, -1);
        cal.set(Calendar.HOUR_OF_DAY, 23);
        cal.set(Calendar.MINUTE, 59);
        cal.set(Calendar.SECOND, 59);
        cal.set(Calendar.MILLISECOND, 999);

        return new Date(cal.getTimeInMillis());
    }

    
    public static Date getFifthBeforePeriodStartDate(Date currentPeriodEnd) {
        Calendar cal = Calendar.getInstance();
        cal.setTime(currentPeriodEnd);
        cal.add(Calendar.MONTH, -15);
        
        int month = cal.get(Calendar.MONTH);
        int startMonth = (month / 3) * 3;
        cal.set(Calendar.MONTH, startMonth);
        cal.set(Calendar.DAY_OF_MONTH, 1);

        cal.set(Calendar.HOUR_OF_DAY, 0);
        cal.set(Calendar.MINUTE, 0);
        cal.set(Calendar.SECOND, 0);
        cal.set(Calendar.MILLISECOND, 0);

        return new Date(cal.getTimeInMillis());
    }


    public void showFrame() {
        frame.setVisible(true);
    }
}
