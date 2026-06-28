package nyp14a;

public class MatchV2 {
	public static void main(String[] args) {
		Thread aThread;
		aThread = new Thread( new SoccerFan("G.S.", "Rulez!") );
		aThread.run();
		aThread = new Thread( new SoccerFan("G.S.", "is the champ!") );
		aThread.run( );
		aThread = new Thread( new SoccerFan("F.B.", "is no.1!") );
		aThread.run( );
		aThread = new Thread( new SoccerFan("F.B.", "is the best!") );
		aThread.run( );
/*		aThread = new Thread( new Refree("calm down") );
		aThread.start();*/

	}

}
