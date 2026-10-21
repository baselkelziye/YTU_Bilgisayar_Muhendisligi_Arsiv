package artificial.intelligence.assignment.one.exception;

import artificial.intelligence.assignment.one.model.Result;

public class SearchException extends Exception{

	/**
	 * Auto-generated serial id
	 */
	private static final long serialVersionUID = 5508868582540942366L;

	private Result result;

	public SearchException() {
		super();
	}

	public SearchException(String message, Throwable cause, boolean enableSuppression, boolean writableStackTrace) {
		super(message, cause, enableSuppression, writableStackTrace);
	}

	public SearchException(String message, Throwable cause) {
		super(message, cause);
	}

	public SearchException(String message) {
		super(message);
	}

	public SearchException(Throwable cause) {
		super(cause);
	}

	public SearchException(Result result) {
		super();
		this.result = result;
	}

	public Result getResult() {
		return result;
	}
}
