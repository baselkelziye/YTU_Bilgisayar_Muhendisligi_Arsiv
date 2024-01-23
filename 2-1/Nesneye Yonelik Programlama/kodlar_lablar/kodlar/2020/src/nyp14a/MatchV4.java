package nyp14a;

public class MatchV4 {
	public static void main(String[] args) {
		Thread aThread, bThread, cThread, dThread;
		aThread = new Thread( new SoccerFan("G.S.", "Rulez!") );
		aThread.start( );
		bThread = new Thread( new SoccerFan("G.S.", "is the champ!") );
		bThread.start( );
		cThread = new Thread( new SoccerFan("F.B.", "is no.1!") );
		cThread.start( );
		dThread = new Thread( new SoccerFan("F.B.", "is the best!") );
		dThread.start( );
	}
}
