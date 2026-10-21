package department_information;

import java.util.ArrayList;

public class Department {
	
	private ArrayList<Academic_Staff> academic_staffs;
	private ArrayList<Commission> commissions;
	private String history;
	private String mission_and_vision;
	private String name;
	
	public Department(String history, String mission_and_vision, String name) {
		super();
		this.history = history;
		this.mission_and_vision = mission_and_vision;
		this.name = name;
		academic_staffs = new ArrayList<Academic_Staff>();
		commissions = new ArrayList<Commission>();
	}

	public ArrayList<Academic_Staff> getAcademic_staffs() {
		return academic_staffs;
	}

	public ArrayList<Commission> getCommissions() {
		return commissions;
	}

	public String getHistory() {
		return history;
	}
	
	public void setHistory(String history) {
		this.history = history;
	}

	public String getMission_and_vision() {
		return mission_and_vision;
	}

	public void setMission_and_vision(String mission_and_vision) {
		this.mission_and_vision = mission_and_vision;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}
	
	public Academic_Staff get_academic_staff(int index) {
		return academic_staffs.get(index);
	}
	public Commission getCommission(String name) {
        for (Commission commission : commissions) {
            if (commission.getName().equals(name)) {
                return commission;
            }
        }
        return null;
    }
	
	public void print_academic_staffs_information() {
		for(Academic_Staff element : academic_staffs) {
			element.print_staff_information();
		}
	}
	
	public void print_commission_information() {
		for(Commission element : commissions) {
			System.out.println(element.toString());
		}
	}
	
	
}
