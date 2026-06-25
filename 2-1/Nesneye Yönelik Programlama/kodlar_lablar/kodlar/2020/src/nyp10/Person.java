package nyp10;

public class Person {
	private String name;
	private int age;

	public Person( String name )  { 
		setName(name);
	}
	public String getName( ) { return name; }
	public int getAge( ) { return age; }
	public String toString() {
		return getName() + " " + getAge( );
	}
	public void setName( String isim )  {
		this.name = isim;
	}
	public void setAge( int age ) throws ImpossibleInfo {
		if( age < 0 || age > 150 )
			throw new ImpossibleInfo( "Impossible age: " + 
				age );
		this.age = age;
	}
	
}
