
public class ClubCard {
	
	private static int counter = 220001;
	private final int ID;
	private double credit;
	Sports sp[] = new Sports[7];  //en fazla 7 farkli spora kayit olunabilir.
	
	public ClubCard(double credit) {
		this.credit = credit;
		ID = counter;
		counter++;
		
	}
	
	
	public void registerCourse(Sports sport){
		
		for(int i=0; i<sp.length; i++){
			if(sp[i] == null){
				sp[i] = sport;
				break;
			}
		}
		System.out.println("Registered to course: " + sport.getName());
		
	}
	

	
	public void listCourses() {
		for(int i=0; i<sp.length; i++){
			if(sp[i]!=null)
				System.out.println(sp[i].getName());
			
		}
		
	}
	
	


	public static int getCounter() {
		return counter;
	}


	public static void setCounter(int counter) {
		ClubCard.counter = counter;
	}


	public double getCredit() {
		return credit;
	}


	public void setCredit(double credit) {
		this.credit = credit;
	}


	public int getID() {
		return ID;
	}
	
	
	
	
	


	
	
	

}
