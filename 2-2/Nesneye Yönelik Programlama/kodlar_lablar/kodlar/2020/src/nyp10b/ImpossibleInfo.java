package nyp10b;
import java.io.IOException;
/* @home: Check the needed additions
 * if we had extended this exception  
 * from java.lang.RuntimeException
 */
@SuppressWarnings("serial")
public class ImpossibleInfo extends IOException {
	public ImpossibleInfo( String errorMessage ) { 
		super(errorMessage); 
	}
}
