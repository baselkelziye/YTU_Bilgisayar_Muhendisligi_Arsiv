package nypproject;

public class DuplicateInfoException extends RuntimeException {
	private static final long serialVersionUID = 1L;
	
	public DuplicateInfoException(String error) {
		super(error);
	}

}
