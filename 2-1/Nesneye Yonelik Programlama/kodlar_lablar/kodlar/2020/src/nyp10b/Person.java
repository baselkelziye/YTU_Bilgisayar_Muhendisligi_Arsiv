package nyp10b;

public class Person {
	private String name;
	private int age;

	public Person( String name ) throws ImpossibleInfo, UnallowedInfo {
		setName(name);
	}
	public String getName( ) { return name; }
	public int getAge( ) { return age; }
	public String toString() {
		return getName() + " " + getAge( );
	}
	public void setName( String isim ) throws ImpossibleInfo, 
												UnallowedInfo  {
		if( isim.length() <6 )
			throw new ImpossibleInfo( "Impossible name: " + 
					isim + " is too short!" );
		if( (isim.split(" ")).length > 5 )
			throw new UnallowedInfo( "Unallowed name: " + 
					isim + " has too many spaces!" );
		this.name = isim;
	}
	public void setAge( int age ) throws ImpossibleInfo {
		if( age < 0 || age > 150 )
			throw new ImpossibleInfo( "Impossible age: " + 
				age );
		this.age = age;
	}
	
}
