package nypproject;

import java.io.Serializable;
import java.util.LinkedList;

public class Hospital implements Serializable {
	private static final long serialVersionUID = 1L;
	
	private final int id;
	private String name;
	private LinkedList<Section> sections;
	
	public Hospital(int id, String name)
	{
		this.id = id;
		this.name = name;
		sections = new LinkedList<Section>();
	}
	
	public Hospital(int id, String name, LinkedList<Section> sections)
	{
		this.id = id;
		this.name = name;
		this.sections = sections;
	}
	
	@SuppressWarnings("unused")
	private Section getSection(String name) 
	{
		for(Section section : sections) 
		{
			if(section.getName().equals(name)) 
			{
				return section;
			}
		}
		System.out.println("Section with name " + name + " couldn't be found!");
		return null;
	}
	
	public Section getSection(int id) 
	{
		for(Section section : sections) 
		{
			if(section.getID() == id) 
			{
				return section;
			}
		}
		System.out.println("Section with id " + id + " couldn't be found!");
		return null;
	}
	
	public LinkedList<Section> getSections(){
		return sections;
	}
	
	public String getName() {
		return name;
	}
	
	public void addSection(Section section) 
	{
		if(getSection(section.getID()) != null) {
			if(CRS.GUIMode)
				return;
			throw new DuplicateInfoException("Section with this id already exists!");
			
		}
		else 
		{
			sections.add(section);
		}
	}
	
	public Section removeSection(int sectionID) {
		Section section = getSection(sectionID);
		if(sections.remove(section));
		return section;
	}
		
	public void clearSectionList() {
		sections.clear();
	}
	
	public int getID() {
		return id;
	}
	
	public String toString() {
		return name+"-"+id;
	}

}
