package unitTestingByFowler;
import junit.framework.*;
public class TestCustomer extends TestCase {
	private Customer yunus;
	private Movie matrix, monster, surrogate, terminator;
	protected void setUp() {
		yunus = new Customer("Yunus Emre Selçuk");
		matrix = new Movie("The Matrix",Movie.REGULAR);
		monster = new Movie("Monsters, Inc.",Movie.CHILDRENS);
		surrogate = new Movie("Surrogates", Movie.NEW_RELEASE);
		terminator = new Movie("Terminator Salvation",Movie.NEW_RELEASE);
	}
	public void testGetName( ) {
		String sonuc = yunus.getName( );
		assertEquals("Yunus Emre Selçuk",sonuc);
	}
	public void testStatementWhenEmpty( ) {
		String sonuc = yunus.statement();
		String beklenen = "Rental Record for Yunus Emre Selçuk\n";
		beklenen += "Amount owed is 0.0\n";
		beklenen += "You earned 0 frequent renter points";
		assertEquals(beklenen, sonuc);
	}
	public void testStatementWithMoviesLongRent( ) {
		yunus.addRental( new Rental(matrix, 3) );
		yunus.addRental( new Rental(monster, 4) );
		yunus.addRental( new Rental(surrogate, 2) );
		String sonuc = yunus.statement();
		String beklenen = "Rental Record for Yunus Emre Selçuk\n";
		beklenen += "\tThe Matrix\t3.5\n";
		beklenen += "\tMonsters, Inc.\t3.0\n";
		beklenen += "\tSurrogates\t6.0\n";
		beklenen += "Amount owed is 12.5\n";
		beklenen += "You earned 4 frequent renter points";
		assertEquals(beklenen, sonuc);
	}
	public void testStatementWithMoviesShortRent( ) {
		yunus.addRental( new Rental(matrix, 2) );
		yunus.addRental( new Rental(monster, 3) );
		yunus.addRental( new Rental(surrogate, 1) );
		String sonuc = yunus.statement();
		String beklenen = "Rental Record for Yunus Emre Selçuk\n";
		beklenen += "\tThe Matrix\t2.0\n";
		beklenen += "\tMonsters, Inc.\t1.5\n";
		beklenen += "\tSurrogates\t3.0\n";
		beklenen += "Amount owed is 6.5\n";
		beklenen += "You earned 3 frequent renter points";
		assertEquals(beklenen, sonuc);
	}
	public void testNewReleaseRentalBonus( ) {
		yunus.addRental( new Rental(surrogate, 2) );
		yunus.addRental( new Rental(terminator, 1) );
		String sonuc = yunus.statement();
		String beklenen = "Rental Record for Yunus Emre Selçuk\n";
		beklenen += "\tSurrogates\t6.0\n";
		beklenen += "\tTerminator Salvation\t3.0\n";
		beklenen += "Amount owed is 9.0\n";
		beklenen += "You earned 3 frequent renter points";
		assertEquals(beklenen, sonuc);
	}

}
