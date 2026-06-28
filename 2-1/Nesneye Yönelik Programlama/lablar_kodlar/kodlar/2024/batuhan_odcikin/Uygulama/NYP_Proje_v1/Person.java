package nyp_project;

import java.io.Serializable;

public class Person implements Serializable{
 /**
	 * 
	 */
	private static final long serialVersionUID = 1L;
private final long national_id;
 private String name;
 
 public Person (String name, long national_id) {
	 this.name = name;
	this.national_id = national_id;
 }

@Override
public String toString() {
	return "Person [name=" + name + ", national_id=" + national_id + "]";
}

public long getNational_id() {
	return national_id;
}

public String getName() {
	return name;
}
 
 
}
