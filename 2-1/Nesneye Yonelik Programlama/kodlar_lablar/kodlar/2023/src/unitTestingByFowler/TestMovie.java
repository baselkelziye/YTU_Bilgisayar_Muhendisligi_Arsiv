package unitTestingByFowler;

import static org.junit.Assert.assertNotEquals;

import junit.framework.TestCase;

public class TestMovie extends TestCase {
	private Movie matrix, monster, surrogate, terminator;
	protected void setUp() {
		matrix = new Movie("The Matrix",Movie.REGULAR);
		monster = new Movie("Monsters, Inc.",Movie.CHILDRENS);
		surrogate = new Movie("Surrogates", Movie.NEW_RELEASE);
		terminator = new Movie("Terminator Salvation",Movie.NEW_RELEASE);
	}
	public void testMovieTypes() {
		assertEquals(surrogate.getPriceCode(),terminator.getPriceCode());
		assertNotEquals(monster.getPriceCode(), matrix.getPriceCode());
		assertTrue(matrix.getPriceCode()!=surrogate.getPriceCode());
		assertFalse(monster.getPriceCode()==terminator.getPriceCode());
		
	}

}
