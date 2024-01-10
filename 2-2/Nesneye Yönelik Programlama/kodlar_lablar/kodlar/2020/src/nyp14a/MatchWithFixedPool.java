package nyp14a;
import java.util.concurrent.*;
public class MatchWithFixedPool {
	public static void main(String[] args) {
		long begin = System.currentTimeMillis();
		ExecutorService pool = Executors.newFixedThreadPool(4);
		pool.execute( new SoccerFan("G.S.", "Rulez!") );
		pool.execute( new SoccerFan("G.S.", "is the champ!") );
		pool.execute( new SoccerFan("F.B.", "is no.1!") );
		pool.execute( new SoccerFan("F.B.", "is the best!") );
		pool.shutdown( );
		while(!pool.isTerminated());
		long end = System.currentTimeMillis();
		System.out.println(end-begin);
	}
}
