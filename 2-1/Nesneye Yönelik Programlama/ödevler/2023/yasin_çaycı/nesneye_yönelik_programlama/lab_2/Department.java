package selahattinyasincayci;

import java.util.ArrayList;

public class Department {

	private ArrayList<Academic_Staff> academic_staffs;
	private ArrayList<Commission> commissions;
	private String history;
	private String mission_and_vission;
	private String name;
	
	public Department(String history, String mission_and_vission, String name) {
		this.history = history;
		this.mission_and_vission = mission_and_vission;
		this.name = name;
		commissions = new ArrayList<>();
		academic_staffs = new ArrayList<>();
	}
	
	public Academic_Staff get_academic_staff(int staff_id) {
		if(!academic_staffs.isEmpty()) {
			for (Academic_Staff academic_Staff : academic_staffs) {
				if(academic_Staff.getStaff_id() == staff_id) {
					return academic_Staff;
				}
			}
		}
		return null;
	}
	
	public ArrayList<Academic_Staff> get_academic_staffs() {
		return academic_staffs;
	}
	
	public ArrayList<Commission> getCommissions() {
		return commissions;
	}
	
	public Commission get_commission(String name) {
		if(!commissions.isEmpty()) {
			for (Commission commission : commissions) {
				if(commission.getName().equalsIgnoreCase(name)) {
					return commission;
				}
			}
		}
		return null;
	}
	
	public void print_academic_staffs_information() {
		for (Academic_Staff academic_Staff : academic_staffs) {
			System.out.println("\n");
			academic_Staff.print_staff_information();
		}
	}
	
	public void print_commission_information() {
		int i;
		for (Commission commission : commissions) {
			i = 1;
			System.out.println("\t"+commission.getCommission_id()+". Commission: "+commission.getName());
			for (Academic_Staff academic_Staff : academic_staffs) {
				if(academic_Staff.getCom_id() == commission.getCommission_id()) {
					System.out.println("\t\t"+i+". Academic Personal: "+academic_Staff.getName());
					i++;
				}
			}
			if(i == 1) {
				System.out.println("\t\tThere is no one on this commission.");
			}
		}
	}
	
	public String getHistory() {
		return history;
	}
	public void setHistory(String history) {
		this.history = history;
	}
	
	public String getMission_and_vission() {
		return mission_and_vission;
	}
	public void setMission_and_vission(String mission_and_vission) {
		this.mission_and_vission = mission_and_vission;
	}
	
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	
	public ArrayList<Academic_Staff> getAcademic_staffs() {
		return academic_staffs;
	}
	
	
	
	
	
}
