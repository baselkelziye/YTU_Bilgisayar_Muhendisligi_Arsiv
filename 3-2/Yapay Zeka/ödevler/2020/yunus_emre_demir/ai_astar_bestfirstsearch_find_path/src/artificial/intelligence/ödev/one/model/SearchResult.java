package artificial.intelligence.assignment.one.model;

import java.util.Collection;

public class SearchResult implements Result {
	private Collection<SearchObject> path;
	private double distance;
	private Time elapsedTime;
	private long iterationAmount;
	private int topStackSize;

	public SearchResult() {
		super();
	}

	public SearchResult(Collection<SearchObject> path, double distance, Time elapsedTime, long iterationAmount,
			int topStackSize) {
		super();
		this.path = path;
		this.distance = distance;
		this.elapsedTime = elapsedTime;
		this.iterationAmount = iterationAmount;
		this.topStackSize = topStackSize;
	}

	@Override
	public Collection<SearchObject> getPath() {
		return this.path;
	}

	@Override
	public void getPath(Collection<SearchObject> path) {
		this.path = path;
	}

	@Override
	public double getDistance() {
		return this.distance;
	}

	@Override
	public void setDistance(double distance) {
		this.distance = distance;
	}

	@Override
	public Time getElapsedTime() {
		return elapsedTime;
	}

	@Override
	public void getElapsedTime(Time elapsedTime) {
		this.elapsedTime = elapsedTime;
	}

	@Override
	public long getIterationAmount() {
		return iterationAmount;
	}

	@Override
	public void setIterationAmount(long iterationAmount) {
		this.iterationAmount = iterationAmount;
	}

	@Override
	public int getTopStackSize() {
		return topStackSize;
	}

	@Override
	public void setTopStackSize(int topStackSize) {
		this.topStackSize = topStackSize;
	}

	@Override
	public String toString() {
		return "[Total Iteration: " + this.iterationAmount + " Total Distance: " + this.distance + " Top Stack Size: "
				+ this.topStackSize + " Elapsed Time: " + elapsedTime + "]";
	}

}
