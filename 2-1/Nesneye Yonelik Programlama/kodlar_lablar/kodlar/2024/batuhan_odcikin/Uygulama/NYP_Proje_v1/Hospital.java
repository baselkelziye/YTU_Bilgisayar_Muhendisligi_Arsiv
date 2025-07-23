package nyp_project;

import java.io.Serializable;
import java.util.LinkedList;

public class Hospital implements Serializable{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private final int id;
	private String name;
	private LinkedList<Section> sections;
	
	public Hospital(int id, String name) {
		this.id = id;
		this.name = name;
		sections = new LinkedList<Section>();
	}
	
	public Section getSection(int id) {
		for(Section s:sections) {
			if(s.getId() == id)
				return s;
		}
		return null;
	}
	
	public Section getSection(String name) {
		for(Section s:sections) {
			if(s.getName() == name)
				return s;
		}
		return null;
	}
	
	public void listSections() {
		for(Section s:sections) {
			System.out.println(s.getId() + "- " + s.getName() );
		}
	}
	
	public void AddSection(Section section) throws DuplicateException{
		for(Section s:sections) {
			if(s.getId() == section.getId()) {
				throw new DuplicateException("Duplicate error! - Already a section added with same id.");
			}	
		}
		sections.add(section);
	}

	public String getName() {
		return name;
	}

	public LinkedList<Section> getSections() {
		return sections;
	}

	public int getId() {
		return id;
	}
	
	
}
