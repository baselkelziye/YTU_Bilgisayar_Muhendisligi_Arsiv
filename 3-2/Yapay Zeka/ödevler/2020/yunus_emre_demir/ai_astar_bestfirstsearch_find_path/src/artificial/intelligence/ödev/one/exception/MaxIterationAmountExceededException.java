package artificial.intelligence.assignment.one.exception;

import artificial.intelligence.assignment.one.model.Result;
import artificial.intelligence.assignment.one.model.SearchResult;

public class MaxIterationAmountExceededException extends SearchException {

	/**
	 * Auto-generated serial id
	 */
	private static final long serialVersionUID = 3471673666853305467L;

	public MaxIterationAmountExceededException() {
		super();
	}

	public MaxIterationAmountExceededException(String message, Throwable cause) {
		super(message, cause);
	}

	public MaxIterationAmountExceededException(String message) {
		super(message);
	}

	public MaxIterationAmountExceededException(Throwable cause) {
		super(cause);
	}


	public MaxIterationAmountExceededException(Result result) {
		super(result);
	}

	public MaxIterationAmountExceededException(String message, Throwable cause, boolean enableSuppression,
			boolean writableStackTrace) {
		super(message, cause, enableSuppression, writableStackTrace);
	}
	
	public MaxIterationAmountExceededException(SearchResult searchResult) {
		super(searchResult);
	}

}
