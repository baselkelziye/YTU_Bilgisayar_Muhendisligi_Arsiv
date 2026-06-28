package nyp09;
import java.io.IOException;
/* Check the needed additions
 * if we had extended this exception  
 * from java.lang.RuntimeException
 */
@SuppressWarnings("serial")
public class ImpossibleInfo extends IOException {
	public ImpossibleInfo( String errorMessage ) { 
		super(errorMessage); 
	}
}
