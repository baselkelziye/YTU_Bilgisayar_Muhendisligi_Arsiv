package lab1;

public class Main {

	public static void main(String[] args) {
	
		Company company = new Company("Global Adventures", 8, 10, 10);  
		
		Tour tr1 = new Tour("Disneyland", "Paris", 150);
		Tour tr2 = new Tour("City Tour", "Paris", 50);
		Tour tr3 = new Tour("Diving", "Cairo", 50);
		Tour tr4 = new Tour("Pyramids", "Cairo", 65);
		Tour tr5 = new Tour("Diving", "Bali", 200 );
		Tour tr6 = new Tour("City Tour", "Tokio", 90);
		
		Ticket tk1 = new Ticket("Istanbul","Paris","MyJet", 150);
		Ticket tk2 = new Ticket("Istanbul","Cairo","AnAir", 120);
		Ticket tk3 = new Ticket("Istanbul","Bali","AnAir", 1000);
		Ticket tk4 = new Ticket("Istanbul","Bali","MyJet", 800);
		Ticket tk5 = new Ticket("Istanbul","Paris","AnAir", 120);
		Ticket tk6 = new Ticket("Istanbul","Bali","XYZJet", 900);
		
		
		Tour tours[] = {tr1, tr2, tr3, tr4, tr5, tr6};
		for(int i=0; i<tours.length; i++)
			company.addTour(tours[i]);
		
		
		Ticket tickets[] = {tk1, tk2, tk3, tk4, tk5, tk6};
		for(int i=0; i<tickets.length; i++)
			company.addTicket(tickets[i]);
		
		company.listTours();
		System.out.println();
		
		company.listTickets();
		System.out.println();
		
		company.searchTour("Paris");
		System.out.println();
		
		company.searchCheapestTicket("Bali");
		System.out.println();
		
		company.showCitiesWithToursAndFlights(); 
		System.out.println();
		

		Staff s1 = new Staff("Eric Smith", 35, 800);
		Staff s2 = new Staff("Sophia Taylor", 53, 900);
		Staff s3 = new Staff("James Harris", 29, 750);
		Staff s4 = new Staff("Olivia Miller", 24, 650);
		
		Staff staff[] = {s1, s2, s3, s4};
		for(int i=0; i<staff.length; i++)
			company.addStaff(staff[i]);
				
		System.out.println("Average salary in this company is: " + company.averageStaffSalary());
		System.out.println("Oldest staff in this company is "+ company.findOldestStaffAge() + " years old.");
		
				

	}

}
