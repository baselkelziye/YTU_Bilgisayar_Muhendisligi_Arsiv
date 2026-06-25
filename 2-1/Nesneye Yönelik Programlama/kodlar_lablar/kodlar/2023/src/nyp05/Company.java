package nyp05;

public class Company {

	public static void main(String[] args) {
		Employee[] staff = new Employee[3];
		Manager boss = new Manager( "Cemalnur Sargut", 8000 );
		boss.setBonus( 2500 );
		staff[0] = boss;
		staff[1] = new Employee( "Yaþar Nuri Öztürk", 7500 );
		staff[2] = new Employee( "Fatih Çýtlak", 7000 );
		for( Employee author : staff )
			//System.out.println(author);
			System.out.println( author.getName() + " "  + author.getSalary( ) );
	}

}
