package artificial.intelligence.assignment.one.search;

import artificial.intelligence.assignment.one.exception.MaxIterationAmountExceededException;
import artificial.intelligence.assignment.one.exception.NoImageLoadException;
import artificial.intelligence.assignment.one.model.Result;
import artificial.intelligence.assignment.one.model.SearchObject;

public interface HeuristiclySearchable {
	int heuristicFunction(SearchObject startPoint, SearchObject endPoint);

	Result search(SearchObject startPoint, SearchObject endPoint)
			throws MaxIterationAmountExceededException, NoImageLoadException;

}
