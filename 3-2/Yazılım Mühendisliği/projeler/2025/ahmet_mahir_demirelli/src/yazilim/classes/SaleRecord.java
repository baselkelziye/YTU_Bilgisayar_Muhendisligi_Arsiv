package yazilim.classes;

import java.math.BigDecimal;

public class SaleRecord {
    private int vehicleId;
    private BigDecimal salePrice;

    public SaleRecord(int vehicleId, BigDecimal salePrice) {
        this.vehicleId = vehicleId;
        this.salePrice = salePrice;
    }

    public int getVehicleId() {
        return vehicleId;
    }

    public BigDecimal getSalePrice() {
        return salePrice;
    }
    
    public void setVehicleId(int vehicleId) {
        this.vehicleId = vehicleId;
    }

    public void setSalePrice(BigDecimal salePrice) {
    	this.salePrice = salePrice;
    }
    
    @Override
	public String toString() {
	    return "Sale Record{" +
	            "vehicleId=" + vehicleId +
	            ", salePrice='" + salePrice +
	            '}';
	}
}