package artificial.intelligence.assignment.one.model;

import java.util.Collection;

public interface Result {
	Collection<SearchObject> getPath();

	void getPath(Collection<SearchObject> path);

	double getDistance();

	void setDistance(double distance);

	Time getElapsedTime();

	void getElapsedTime(Time elapsedTime);

	long getIterationAmount();

	void setIterationAmount(long iterationAmount);

	int getTopStackSize();

	void setTopStackSize(int topStackSize);
}
