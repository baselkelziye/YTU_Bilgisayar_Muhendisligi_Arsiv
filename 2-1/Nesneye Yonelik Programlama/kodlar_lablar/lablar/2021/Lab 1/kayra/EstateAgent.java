package muhammetkayrabulut;

public class EstateAgent {
	private String name;
	private Home[] h;
	public void hasHome(Home home) {
		for(int i=0;i<7;i++) {
			if(h[i]==null) {
				h[i]=home;
				break;
			}
		}
	}
	public EstateAgent() {
		h=new Home[7];
	}
	public void sellHome(Home hm, Customer cm) {
		for(int i=0;i<7;i++) {
			if(h[i]==hm) {
				cm.buyHome(hm);
				h[i]=null;
				break;
			}
		}

		
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public void listHome() {
		System.out.println("Evler burada:");
		for(int i=0;i<7;i++) {
			if(h[i]!=null)
				System.out.println(h[i]);
		}
		
	}
	

}
