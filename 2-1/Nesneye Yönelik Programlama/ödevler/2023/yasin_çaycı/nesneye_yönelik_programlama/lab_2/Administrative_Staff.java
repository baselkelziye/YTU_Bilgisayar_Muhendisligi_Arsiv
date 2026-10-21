package selahattinyasincayci;

public class Administrative_Staff extends Staff{

	public Administrative_Staff(int staff_id, String name, String web) {
		super(staff_id, name, web);
	}
	
	public void add_academic_staff(Department department, Academic_Staff academic_staff) {
		department.getAcademic_staffs().add(academic_staff);
	}
	
	public void add_commission(Department department, Commission commission) {
		department.getCommissions().add(commission);
	}
	
	public void add_staff_to_commission(Department department, int id, String name ) {
		Commission commission = department.get_commission(name);
		Academic_Staff academic_staff = department.get_academic_staff(id);
		academic_staff.setCom_id(commission.getCommission_id());
	} //personelin com_id si ile academic personeli commisyona ekle o id yi set et 
	
	public Academic_Staff get_academic_staff(Department department, int id) {
		return department.get_academic_staff(id);
	}
	
	public void get_academic_staffs(Department department) {
		for (Academic_Staff academic_staff : department.get_academic_staffs()) {
			academic_staff.print_staff_information();
		}
	}
	
	public Commission get_commission(Department department, String name) {
		return department.get_commission(name);
	}
	
	public String department_History(Department department) {
		return department.getHistory();
	}
	
	public String get_department_mission_and_vision(Department department) {
		return department.getMission_and_vission();
	}
	
	public String get_department_name(Department department) {
		return department.getName();
	}
	
	public void set_department_history(Department department, String history) {
		department.setHistory(history);
	}
	
	public void set_department_mission_and_vision(Department department, String mission_and_vision) {
		department.setMission_and_vission(mission_and_vision);
	}
	
	public void set_department_name(Department department, String name) {
		department.setName(name);
	}
	
	public void print_commission_information(Department department) {
		department.print_commission_information();
	}
	
	public void print_staff_information() {
		System.out.println("	Name: "+super.getName()+", web: "+super.getWeb());
	}
	
	
	
}
