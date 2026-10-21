package selahattinyasincayci;


public class Main {
	
	public static void main(String[] args) {
		
		Hotel h1 = new Hotel("London Hotel", "London, UK", "0044201491866");
		Hotel h2 = new Hotel("Istanbul Hotel", "Istanbul, Turkey", "009212432121");
		
		Customer c1 = new Customer("Jane Austen", 1112334455);
		
		c1.makeRezervation(h1, "suit", 3);
		c1.makeRezervation(h2, "family", 5);
		c1.makeRezervation(h1, "suit", 4);
		
		c1.listCustomerRezervations();  
		
		System.out.println("************************************************");
		c1.getInvoice(20230002);     //verilen rezervasyon numarasina ait odeme bilgileri listelenir.
		
		System.out.println("************************************************");
		Customer c2 = new Customer("Agatha Christie", 1133557799);
		c2.makeRezervation(h2, "family", 4);
	
		
		
	}

}

