package yazilim.requests;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.time.LocalDate;

public class OrderRequest extends CustomerRequest{
	private Connection conn;
	private int offerId;
	
	public OrderRequest(int userId, int vehicleId, LocalDate requestDate, Connection conn, int offerId) {
		super(userId, vehicleId, requestDate);
		// TODO Auto-generated constructor stub
		this.conn = conn;
		this.offerId = offerId;
	}

	@Override
	public boolean processRequest(int userId, int vehicleId, LocalDate requestDate) {
	    String offerQuery = "SELECT offer_date FROM price_offers WHERE offer_id = ? AND user_id = ? AND vehicle_id = ?";

	    try {
	        PreparedStatement stmt = conn.prepareStatement(offerQuery);
	        stmt.setInt(1, offerId);
	        stmt.setInt(2, userId);
	        stmt.setInt(3, vehicleId);

	        ResultSet rs = stmt.executeQuery();

	        if (rs.next()) {
	            LocalDate offerDate = rs.getDate("offer_date").toLocalDate();
	            LocalDate currentDate = LocalDate.now();

	            if (offerDate.plusDays(30).isBefore(currentDate)) {
	                System.out.println("Teklif süresi dolmuş.");
	                return false;
	            }

	            String insertQuery = "INSERT INTO requests (user_id, vehicle_id, request_type, request_date, status) VALUES (?, ?, ?, ?, ?)";
	            stmt = conn.prepareStatement(insertQuery);
	            stmt.setInt(1, userId);
	            stmt.setInt(2, vehicleId);
	            stmt.setString(3, "order");
	            stmt.setDate(4, java.sql.Date.valueOf(requestDate));
	            stmt.setString(5, "pending");

	            stmt.executeUpdate();
	            return true;
	        } else {
	            System.out.println("Teklif bulunamadı.");
	            return false;
	        }
	    } catch (SQLException e) {
	        e.printStackTrace();
	        return false;
	    }
	}
}
