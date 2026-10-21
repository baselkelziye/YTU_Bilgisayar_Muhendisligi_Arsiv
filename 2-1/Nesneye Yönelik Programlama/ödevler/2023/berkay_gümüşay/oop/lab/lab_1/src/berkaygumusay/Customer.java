package BerkayGumusay;

public class Customer {
	
	private String name;
	private int identityID;
	Rezervation[] rezervations = new Rezervation[10];
	
	
	private static int i = 0; // temp degisken
	
	public Customer(String name, int identityID) {
		this.name = name;
		this.identityID = identityID;
		
	}
	public void makeRezervation(Hotel hotel,String roomType,int day ) {
		
		for(Room oda : hotel.getRooms()) {
			if((oda.getRoomType().equals(roomType)) && (oda.isAvailable()) ) {
				oda.setAvailable(false);
				rezervations[i] = new Rezervation(hotel, oda.getRoomNumber(), day);
				i++;
				System.out.println("!! Oda Alma Islemi Basarili !!");
				return;
			}
		}
		System.out.println("!! Sectiginiz Oda Musait Degil !!");
		return;
	}
	public void getInvoice(int rezervationID){
		for(Rezervation temp : rezervations) {
			if(temp.getRezervationID() == rezervationID) {
				temp.calculatePayment();
				return;
			}
		}
	}
	public void listCustomerRezervations() {
		for(Rezervation temp : rezervations) {
			if(temp == null) {
				return;
			}
			System.out.println("-" + temp.getRezervationID() +" " + temp.getHotel().getHotelName() + " | " + temp.getRoomNumber() + " " + temp.getDay());
		}
	}
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getIdentityID() {
		return identityID;
	}

	public void setIdentityID(int identityID) {
		this.identityID = identityID;
	}

	public Rezervation[] getRezervations() {
		return rezervations;
	}

	public void setRezervations(Rezervation[] rezervations) {
		this.rezervations = rezervations;
	}
	
	
	
	
}
