package selahattinyasincayci;

import java.io.IOException;

public class ApartmentException extends IOException{
	private static final long serialVersionUID = 1L;

	public ApartmentException(String message) throws IOException{
		throw new IOException(message);
	}
	
}
