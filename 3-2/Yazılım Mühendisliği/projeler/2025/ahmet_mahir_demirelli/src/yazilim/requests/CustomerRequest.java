package yazilim.requests;

import java.time.LocalDate;

public abstract class CustomerRequest {
	private int requestId;
	private int userId;
	private int vehicleId;
	private LocalDate requestDate;
	private String status;
	
	
	
	public CustomerRequest(int userId, int vehicleId, LocalDate requestDate) {
		super();
		this.userId = userId;
		this.vehicleId = vehicleId;
		this.requestDate = requestDate;
	}
	
	public int getRequestId() {
		return requestId;
	}
	public int getUserId() {
		return userId;
	}
	public void setUserId(int userId) {
		this.userId = userId;
	}
	public int getVehicleId() {
		return vehicleId;
	}
	public void setVehicleId(int vehicleId) {
		this.vehicleId = vehicleId;
	}
	public LocalDate getRequestDate() {
		return requestDate;
	}
	public void setRequestDate(LocalDate requestDate) {
		this.requestDate = requestDate;
	}
	public String getStatus() {
		return status;
	}
	
	public abstract boolean processRequest(int userId, int vehicleId, LocalDate requestDate);


}
