package nypproject;

import java.io.Serializable;

public class Person implements Serializable {
	private static final long serialVersionUID = 1L;
	
	private String name;
	private final long national_id;
	
	public Person(String name,long national_id) 
	{
		this.name = name;
		this.national_id = national_id;
	}
	
	public long getNationalID() 
	{	
		return national_id;
	}
	
	public String getName() 
	{
		return name;
	}
	
	public String toString() 
	{
		return name+"-"+national_id;
	}

}
