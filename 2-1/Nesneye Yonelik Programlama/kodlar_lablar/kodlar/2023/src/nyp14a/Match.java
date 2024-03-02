package nyp14a;

public class Match {
	public static void main(String[] args) {
		Thread aThread;
		aThread = new Thread( new SoccerFan("G.S.", "Rulez!") );
		aThread.start( );
		aThread = new Thread( new SoccerFan("G.S.", "is the champ!") );
		aThread.start( );
		aThread = new Thread( new SoccerFan("F.B.", "is no.1!") );
		aThread.start( );
		aThread = new Thread( new SoccerFan("F.B.", "is the best!") );
		aThread.start( );
	}

}
