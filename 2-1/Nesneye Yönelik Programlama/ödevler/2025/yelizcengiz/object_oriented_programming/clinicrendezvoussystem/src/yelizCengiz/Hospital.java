package yelizCengiz;

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
		sections=new LinkedList<Section>();
	}

	public Section getSection(int id) {
		for(Section s: sections) {
			if(s.getId()==id) {
				return s;
			}
		}
		return null;
	}

	public Section getSection(String name) {
		for(Section s: sections) {
			if(s.getName()==name) {
				return s;
			}
		}
		return null;
	}
	
	public int getId() {
		return id;
	}

	public String getName() {
		return name;
	}

	public boolean addSection(Section section) throws DuplicateInfoException {
		
		if(getSection(section.getId())!=null) {
			throw new DuplicateInfoException("ayni idye sahip section eklenmeye calisildi");		
		}
		else if(getSection(section.getName())!=null) {
			//throw new DuplicateInfoException("ayni ada sahip section eklenmeye calisildi");//farkli hospitallerin aynı sectionu olabilir
		}	
		
		if(getSection(section.getId())!=null||getSection(section.getName())!=null) {
			return false;
		}
		sections.add(section);
		return true;
		
	}
	
	
	public LinkedList<Section> getSections() {
		return sections;
	}

	public String toString() {
		return this.name;
	}
	
}
