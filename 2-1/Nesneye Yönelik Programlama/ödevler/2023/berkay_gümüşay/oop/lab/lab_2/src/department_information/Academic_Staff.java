package department_information;

import java.util.ArrayList;

public class Academic_Staff extends Staff {
	
	private static int com_id;
	private String office;
	private ArrayList<String> research_areas;
	
	
	
	public Academic_Staff(int i, String string, String string2, String string3, String string4) {
		super(i,string,string2,string3);
        this.office = string4;
        research_areas = new ArrayList<String>();
        com_id++;
	}
	public Academic_Staff(int i, String string, String string2) {
		super(i,string,string2);
		research_areas = new ArrayList<String>();
		com_id++;
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
	public boolean delete_research (int research_ID) {
		if(research_areas.get(research_ID) != null) {
			research_areas.remove(research_ID);
			return true;
		}
		return false;
		
	}
	public boolean delete_research (String research_name) {
		int i=0;
		for(String element : research_areas) {
			if(element.contains(research_name)) {
				research_areas.remove(i);
				return true;
			}
			i++;
		}
		return false;	
	}
	public void add_research(String research_name) {
		research_areas.add(research_name);
	}
	public void print_staff_information() {
		System.out.println(toString());
	}
	@Override
	public String toString() {
		return "Academic_Staff [office=" + office + ", research_areas=" + research_areas + "]";
	}
	
}
