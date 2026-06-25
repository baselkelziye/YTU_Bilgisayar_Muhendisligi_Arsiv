package nyp_project;

public class Doctor extends Person{
	private int diploma_id;
	private Schedule schedule;
	
	public Doctor(String name, long national_id, int diploma_id,int max_PatientPerDay) {
		super(name, national_id);
		this.diploma_id = diploma_id;
		schedule = new Schedule(max_PatientPerDay);
	}

	public int getDiploma_id() {
		return diploma_id;
	}

	public Schedule getSchedule() {
		return schedule;
	}

	
	
}
