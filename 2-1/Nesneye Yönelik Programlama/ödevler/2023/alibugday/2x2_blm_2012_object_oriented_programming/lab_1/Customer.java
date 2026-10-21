package lab1_19011076;

public class Customer {
	private String name;
	private String telephone;
	private String address;
	private Home[] hm = new Home[50];
	private int homeCounter;
	private double payment;
	
	public Customer(String name, String telephone, String address) {
		this.name = name;
		this.telephone = telephone;
		this.address = address;
	}
	
	public void buyHome(Home aHome) {
		for(int i=0;i<hm.length;i++) {
			if(hm[i] == null) {
				
				if(homeCounter >= 2) {
					setPayment(getPayment() + aHome.discountedPrice());
				}
				else {
					setPayment(getPayment() + aHome.getPrice());
				}
				hm[i] = aHome;
				homeCounter++;
				break;
	
			}
		}
	}
	
	public void listHome() {
		for(int i=0;i<hm.length;i++) {
			if(hm[i]!=null) {
				System.out.println(hm[i].toString());
			}
		}
	}
	
	public String getInfo() {
		/*int toplamEv = 0;
		double toplamOdeme = 0;
		for(int i=0;i<hm.length;i++) {
			if(hm[i]!=null) {
				toplamEv++;
				toplamOdeme+=hm[i].getPrice();
			}
		}*/
		
		return "Musterinin ismi " + getName() + "toplam ev sayisi:" + homeCounter + "toplam yaptigi odeme:" + getPayment();
		
	}
	
	public void listLocations() {
		for(int i=0;i<hm.length;i++) {
			if(hm[i]!=null) {
				System.out.println(hm[i].getLocation());
			}
		}
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getTelephone() {
		return telephone;
	}

	public void setTelephone(String telephone) {
		this.telephone = telephone;
	}

	public String getAddress() {
		return address;
	}

	public void setAddress(String address) {
		this.address = address;
	}

	public int getHomeCounter() {
		return homeCounter;
	}

	public void setHomeCounter(int homeCounter) {
		this.homeCounter = homeCounter;
	}

	public double getPayment() {
		return payment;
	}

	public void setPayment(double payment) {
		this.payment = payment;
	}
	
	
	
}
