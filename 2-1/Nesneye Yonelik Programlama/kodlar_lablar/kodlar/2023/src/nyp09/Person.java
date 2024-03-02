package nyp09;

public class Person {
	private String name;
	private int age;

	public Person( String name ) throws ImpossibleInfo  { 
		setName(name);
	}
	public String getName( ) { return name; }
	public int getAge( ) { return age; }
	public String toString() {
		return getName() + " " + getAge( );
	}
	public void setName( String isim ) throws ImpossibleInfo  { //Ör. "Su Ak"
		if( isim.length() < 5 )
			throw new ImpossibleInfo("Name is too short: " + isim );
		this.name = isim;
	}
	public void setAge( int age ) throws ImpossibleInfo {
		if( age < 0 || age > 150 )
			throw new ImpossibleInfo( "Impossible age: " +  age );
		this.age = age;
	}
	
}
