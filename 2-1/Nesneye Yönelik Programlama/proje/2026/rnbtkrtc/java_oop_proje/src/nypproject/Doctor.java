package nypproject;

public class Doctor extends Person {
	private static final long serialVersionUID = 1L;
	
	private final int diploma_id;
	private Schedule schedule;
	private Section ownerSection;     // GUI'da hangi doctorun hangi sectiona ait olduğuna
	private int maxPatientPerDay = 3; // daha kolay bir şekilde erişmek için kullanılıyor
	
	
	public Doctor(String name,long national_id,int diploma_id) {
		super(name,national_id);
		this.diploma_id = diploma_id;
		schedule = new Schedule(maxPatientPerDay,this);
	}
	
	public void setSection(Section section) {
		ownerSection = section;
	}
	
	public Section getSection() {
		return ownerSection;
	}
	
	public Schedule getSchedule() 
	{
		return schedule;
	}
	
	public int getDiplomaID(){	
		return diploma_id;
	}
	
	public String toString() {
		return super.toString()+"-"+diploma_id;
	}
}
