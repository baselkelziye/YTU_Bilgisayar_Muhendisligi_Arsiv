package yazilim.requests;

import java.sql.Connection;
import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.time.LocalDate;

public class PriceOfferRequest extends CustomerRequest{
	private Connection conn;

	

	public PriceOfferRequest(int userId, int vehicleId, LocalDate requestDate, Connection conn) {
		super(userId, vehicleId, requestDate);
		// TODO Auto-generated constructor stub
		this.conn = conn;
	}
	
	

	@Override
	public boolean processRequest(int userId, int vehicleId, LocalDate requestDate) {
		String query = "INSERT INTO requests (user_id, vehicle_id, request_type, request_date, status) VALUES (?, ?, ?, ?, ?)";
	    try {
	        PreparedStatement stmt = conn.prepareStatement(query);
	        stmt.setInt(1, userId); 
	        stmt.setInt(2, vehicleId); 
	        stmt.setString(3, "price_offer"); 
	        stmt.setDate(4, Date.valueOf(requestDate)); 
	        stmt.setString(5, "pending"); 
	        
	        stmt.executeUpdate(); 
	        return true; 
	    } catch (SQLException e) {
	        e.printStackTrace(); 
	        return false; 
	    }
	}


}
