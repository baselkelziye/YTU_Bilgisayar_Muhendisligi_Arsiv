
public class Member {
	
	private String name;
	private double credit;
	ClubCard card;
	
	
	public Member(String name, double credit) {
		this.name = name;
		this.credit = credit;
		card = new ClubCard(credit);
	}


	
	public void registerCourse(Sports sport){
		card.registerCourse(sport);
	}
	
	

	public void listCourses() {
		card.listCourses();
		
	}



	public void getInfo() {
		System.out.println(getName() + " "+ card.getID());
		
	}
	
	

	@Override
	public String toString() {
		return "Member [name=" + name + ", credit=" + credit + "]";
	}



	public String getName() {
		return name;
	}



	public void setName(String name) {
		this.name = name;
	}



	public double getCredit() {
		return credit;
	}



	public void setCredit(double credit) {
		this.credit = credit;
	}
	
	
	

}
