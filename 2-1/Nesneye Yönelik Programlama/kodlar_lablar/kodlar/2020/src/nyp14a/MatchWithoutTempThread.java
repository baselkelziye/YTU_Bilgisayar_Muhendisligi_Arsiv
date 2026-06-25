package nyp14a;

public class MatchWithoutTempThread {
	public static void main(String[] args) {
		(new Thread( new SoccerFan("G.S.", "Rulez!"))).start();
		(new Thread( new SoccerFan("G.S.", "is the champ!"))).start();
		(new Thread( new SoccerFan("F.B.", "Rulez!"))).start();
		(new Thread( new SoccerFan("F.B.", "is the champ!"))).start();

	}

}
