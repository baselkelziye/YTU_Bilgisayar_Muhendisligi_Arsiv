package lab1_19011076;

public class EstateAgent {
	private String name;
	private Home[] h;
	
	
	public EstateAgent() {
		h = new Home[20];
	}
	
	public void hasHome(Home aHome) {
		for(int i=0;i<h.length;i++) {
			if(h[i] == null) {
				h[i] = aHome;
				break;
			}
		}
	}
	
	public void listHome() {
		for(int i=0;i<h.length;i++) {
			if(h[i] != null) {
				System.out.println(h[i].toString());
			}
		}
	}
	
	public void sellHome(Home aHome, Customer aCustomer) {
		for(int i=0;i<h.length;i++) {
			if(h[i] == aHome) {
				h[i] = null;
				aCustomer.buyHome(aHome);
			}
		}
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}
	
	
}
