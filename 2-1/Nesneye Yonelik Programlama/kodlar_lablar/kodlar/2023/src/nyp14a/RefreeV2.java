package nyp14a;
import java.util.Random;

public class RefreeV2 implements Runnable {
	public final static int STEPS = 10;
	public final static int DELAY = 1000;
	private String shoutPhrase;

	public RefreeV2( String shoutPhrase ) {
		this.shoutPhrase = shoutPhrase;
	}

	public void run() {
		Random generator = new Random();
		try {
		    for( int i = 0; i < STEPS; i++ ) {
		    	System.out.println( shoutPhrase );
		    	Thread.sleep( generator.nextInt(DELAY) );
		    }
		} 
		catch (InterruptedException e) {
		    e.printStackTrace();
		}
	}
}
