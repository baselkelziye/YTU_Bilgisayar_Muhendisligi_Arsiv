
public class Lab1 {

	public static void main(String[] args) {
		EstateAgent es = new EstateAgent();
		es.setName("ABC Real Estate Agent");
		
		Home h1 = new Apartment(700.00, "Istanbul", 1000) ;
		Home h2 = new Apartment(550.00, "Ankara", 750);
		Home h3 = new Villa(350.00, "Ankara");
		Home h4 = new Villa(400.00, "Ankara");
		es.hasHome(h1);
		es.hasHome(h2);
		es.hasHome(h3);
		es.hasHome(h4);
		
		Customer cs1 = new Customer("Ali Deniz", "585-234-33-42", "Istanbul");
		
		es.listHome(); 
		es.sellHome(h1, cs1);
		es.sellHome(h3, cs1);
		es.sellHome(h4, cs1);
		System.out.println("-----------After Sales---------------------------------------");
		es.listHome();
		
		System.out.println("-------------------------------------------------------------");
		System.out.println(cs1.getInfo());
		cs1.listHome();
		cs1.listLocations();
		
		
		
		

	}

	

}
