package nyp01b;

public class Car {
	   private String plate;
	   private String chassisNR;
	   public Car( String plateNr, String chassisNR ) {
	      plate = plateNr;
	      this.chassisNR = chassisNR;
	   }   
	   public String getPlate() {
	      return plate;
	   }
	   public void setPlate(String plate) {
	      this.plate = plate;
	   }
	   public String getChassisNR( ) {
	      return chassisNR;
	   }
	}
