package department_information;

public class Administrative_Staff extends Staff {

	public Administrative_Staff(int i, String string, String string2) {
        super(i,string,string2);
    }
	
	public void add_academic_staff(Department d, Academic_Staff staff1) {
        d.getAcademic_staffs().add(staff1);

    }
	public void add_academic_staff(Department d, Commission c) {
		d.getCommissions().add(c);
	}
	public Academic_Staff get_academic_staff(Department d, int index) {
		return d.getAcademic_staffs().get(index);
	}
	public void get_academic_staffs(Department d) {
		d.print_academic_staffs_information();
	}
	public String get_department_history(Department d) {
		return d.getHistory();
	}
	public String get_mission_and_vision(Department d) {
		return d.getHistory();
	}
	public String get_department_name(Department d) {
		return d.getName();
	}
	public void print_commission_information(Department a) {
		int i,n;
        n=a.getCommissions().size();
        for(i=0;i<n;i++) {
            System.out.println(a.getCommissions().toString());
        }
	}
	public void print_staff_information() {
		
	}
	public void add_staff_to_commission(Department d, int a, String b) {
		d.get_academic_staff(a).getResearch_areas().add(b);
	}
	public void set_department_history(Department d, String a) {
		d.setHistory(a);
	}
	public void set_department_mission_and_vision(Department d, String a) {
		d.setMission_and_vision(a);
	}
	public void set_department_name(Department d, String a) {
		d.setName(a);
	}
	public void add_commission(Department d , Commission a) {
		d.getCommissions().add(a);
	}

}
