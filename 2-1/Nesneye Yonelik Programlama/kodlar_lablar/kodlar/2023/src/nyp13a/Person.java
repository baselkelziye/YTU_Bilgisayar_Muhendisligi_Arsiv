package nyp13a;
public class Person {
	private String name;
	public Person( String name ) { this.name = name; }
	@SuppressWarnings("unused")
	private class Employee { //begin inner class
		private int salary;
		public Employee( int salary ) { this.salary = salary; }
		public int getSalary() { return salary; }
		public void setSalary(int salary) { this.salary = salary; }
		public String toString( ) { return name + " " + salary; }
	} //end inner class
	public static void main( String[] args ) {
		Employee[] staff = new Employee[3];
		Person kisi;
		kisi = new Person("Osman Pamukoğlu");
		staff[0] = kisi.new Employee( 10000 );
		kisi = new Person("Nihat Genç");
		staff[1] = kisi.new Employee( 7500 );
		kisi = new Person("Barış Müstecaplıoğlu");
		staff[2] = kisi.new Employee( 6000 );
		for( Employee eleman: staff ) 
			System.out.println( eleman.toString() );
	}
}
