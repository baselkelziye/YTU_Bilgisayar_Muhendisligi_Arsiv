package artificial.intelligence.assignment.one.model;

public class PathNode {
	private PathNode previous;
	private Tuple data;
	private double distance;

	public PathNode() {
		super();
	}

	public PathNode(PathNode previous, Tuple current, double distance) {
		super();
		this.previous = previous;
		this.data = current;
		this.distance = distance;
	}

	public PathNode getPrevious() {
		return previous;
	}

	public void setPrevious(PathNode previous) {
		this.previous = previous;
	}

	public Tuple getData() {
		return data;
	}

	public void setData(Tuple data) {
		this.data = data;
	}

	public double getDistance() {
		return distance;
	}

	public void setDistance(double distance) {
		this.distance = distance;
	}

}
