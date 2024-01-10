package nyp14a;
import java.util.concurrent.*;
public class MatchWithPoolVerbose {
	public static void main(String[] args) {
		System.out.println("1");
		long begin = System.currentTimeMillis();
		System.out.println("2");
		ExecutorService pool = Executors.newCachedThreadPool();
		System.out.println("3");
		pool.execute( new SoccerFan("G.S.", "Rulez!") );
		System.out.println("4");
		pool.execute( new SoccerFan("G.S.", "is the champ!") );
		System.out.println("5");
		pool.execute( new SoccerFan("F.B.", "is no.1!") );
		System.out.println("6");
		pool.execute( new SoccerFan("F.B.", "is the best!") );
		System.out.println("7");
		//pool.execute( new Refree("Play nicely!"));
		System.out.println("8");
		pool.shutdown( );
		System.out.println("9");
		System.out.println("Shutdown initiated");
		System.out.println("10");
		while(!pool.isTerminated());
		System.out.println("11");
		long end = System.currentTimeMillis();
		System.out.println("12");
		System.out.println(end-begin);
	}
}
