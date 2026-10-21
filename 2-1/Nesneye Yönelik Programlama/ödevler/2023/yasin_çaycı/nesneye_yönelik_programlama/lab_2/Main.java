package selahattinyasincayci;

public class Main {
	
	public static void main(String[] args) {
	String department_name = "Computer Engineering";
	String department_history = "Lorem İpsum";
	String mission_and_vision = "Lorem İpsum";
	
	Department d = new Department(department_name, department_history, mission_and_vision);
	Administrative_Staff administrative_staff = new Administrative_Staff(1,"Sırma YAVUZ","www.sirmayavuz.com");
	
	System.out.println("Information of Administrative Staff");
	administrative_staff.print_staff_information();
	
	Commission com1 = new Commission(1, "Assignment Commission");
	Commission com2 = new Commission(2, "Commission of Adaptation");
	Commission com3 = new Commission(3, "Internship Commission");
	
	administrative_staff.add_commission(d, com1);
	administrative_staff.add_commission(d, com2);
	administrative_staff.add_commission(d, com3);
	
	Academic_Staff staff1 = new Academic_Staff(1, "İdris DEMİR", "www.idrisdemir.com", "idrisd@yildiz.edu.tr", "D-025");
	staff1.add_research("Deep Learning");
	staff1.add_research("Speech Processing");
	staff1.add_research("NLP");
	
	Academic_Staff staff2 = new Academic_Staff(2, "Birol GEZGİN", "www.birolgezgin.com");
	staff2.add_research("NLP");
	staff2.add_research("Computer Engineering");
	staff2.add_research("Deep learning");
	staff2.add_research("Machine Learning");
	
	Academic_Staff staff3 = new Academic_Staff(3, "Seren Cımbız", "www.serencimbiz.com");
	staff3.add_research("Deep Learning");
	staff3.add_research("Image Processing");
	
	administrative_staff.add_academic_staff(d, staff1);
	administrative_staff.add_academic_staff(d, staff2);
	administrative_staff.add_academic_staff(d, staff3);
	
	administrative_staff.add_staff_to_commission(d, 1, "Assignment Commission");
	administrative_staff.add_staff_to_commission(d, 2, "Internship Commission");
	administrative_staff.add_staff_to_commission(d, 3, "Assignment Commission");
	
	System.out.println("\nCommission:");
	administrative_staff.print_commission_information(d);
	System.out.println("\nInformation of Academic Staffs");
	administrative_staff.get_academic_staffs(d);
	
	staff1.delete_research(1);
	staff2.delete_research("NLP");
	System.out.println("After staff delete research area\n");
	administrative_staff.get_academic_staffs(d);
	}
}
