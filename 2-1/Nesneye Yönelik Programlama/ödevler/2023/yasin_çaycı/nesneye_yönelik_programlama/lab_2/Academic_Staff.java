package selahattinyasincayci;

import java.util.ArrayList;

public class Academic_Staff extends Staff{
	private int com_id;
	private String office;
	private ArrayList<String> research_areas;
	
	
	public Academic_Staff(int com_id, String name, String web) {
		super(com_id,name,web);
		research_areas = new ArrayList<>();
	}
	
	public Academic_Staff(int com_id, String name, String web, String mail, String office) {
		super(com_id,name,web,mail);
		this.office = office;
		research_areas = new ArrayList<>();
	}
	
	public void add_research(String researchName) {
		research_areas.add(researchName);
	}
	
	public boolean delete_research(String researchName) {
		for (String area : research_areas) {
			if(area.equalsIgnoreCase(researchName)) {
				 research_areas.remove(researchName);
				 return true;
			}
		}
		return false;
	}
	
	public boolean delete_research(int index) {
		if(research_areas.isEmpty() == false) {
			research_areas.remove(index);
			return true;
		}
		return false;
	}

	public int getCom_id() {
		return com_id;
	}

	public void setCom_id(int com_id) {
		this.com_id = com_id;
	}

	public String getOffice() {
		return office;
	}

	public void setOffice(String office) {
		this.office = office;
	}

	public ArrayList<String> getResearch_areas() {
		return research_areas;
	}
	
	public void print_staff_information() {
		System.out.println("Name: "+super.getName()+", web: "+super.getWeb()+", office_no: "+office+
				"\n"+super.getName()+" Research Areas:");
		for (String area : research_areas) {
			System.out.println(area);
		}
		System.out.println("\n");
	}

	
}
