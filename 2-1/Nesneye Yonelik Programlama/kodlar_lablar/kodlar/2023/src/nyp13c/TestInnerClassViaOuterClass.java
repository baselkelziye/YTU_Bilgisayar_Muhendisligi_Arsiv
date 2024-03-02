package nyp13c;
public class TestInnerClassViaOuterClass {
	public static void main(String[] args) {
		Person[] staff = new Person[3];
		staff[0] = new Person( "Polat Alemdar" );
		staff[0].enlist( 10000 );
		staff[1] = new Person( "Memati Baş" );
		//staff[1].enlist( 7000 );
		staff[2] = new Person( "Abdülhey Çoban" );
		staff[2].enlist( 5000 );
		for( Person insan: staff )
			System.out.println( insan );
	}
}
