package muhammetkayrabulut;

import java.util.HashMap;

public class Customer {
	private String name;
	private String telephone;
	private String address;
	private Home[] hm;
	private int homeCounter;
	private double payment;
	public Customer(String name, String telephone,String address) {
		this.address=address;
		this.telephone=telephone;
		this.name=name;
		hm= new Home[7];
		homeCounter=0;
		payment=0;
	}
	public void listHome() {
		for(Home home : hm) {
			if(home!=null)
				System.out.println(home);
		}
			
	}
	public void buyHome(Home home) {
		if(homeCounter<7) {
			if(homeCounter>=2)
				payment+=home.discountedPrice();
			else
				payment+=home.getPrice();
			hm[homeCounter]=home;
			homeCounter++;
		}
		
	}
	public String getInfo() {
		return "Merhaba ben " + name +". " +homeCounter+ " tane ev aldim. " + "Toplam " + payment + " odeme yaptim";
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
	public void listLocations() {
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		for(int i=0;i<7;i++) {
			if(hm[i]!=null) {
				map.putIfAbsent(hm[i].getLocation(), 0);
				map.put(hm[i].getLocation(), map.get(hm[i].getLocation())+1);}
		}
			for(String myMap : map.keySet()) {
				System.out.println("At city " + myMap +" ------>" + map.get(myMap) + " home(s)");
			}
			
		
	}
	
}
