package artificial.intelligence.assignment.one.search;

import java.awt.image.BufferedImage;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;
import java.util.List;

import artificial.intelligence.assignment.one.exception.MaxIterationAmountExceededException;
import artificial.intelligence.assignment.one.exception.NoImageLoadException;
import artificial.intelligence.assignment.one.image.ImageService;
import artificial.intelligence.assignment.one.model.PathNode;
import artificial.intelligence.assignment.one.model.Result;
import artificial.intelligence.assignment.one.model.SearchObject;
import artificial.intelligence.assignment.one.model.SearchResult;
import artificial.intelligence.assignment.one.model.Time;
import artificial.intelligence.assignment.one.model.Tuple;

public class ImageFirstBestSearchStackUsed extends AbstractImageSearch implements HeuristiclySearchable {

	public ImageFirstBestSearchStackUsed() {
		super();
	}
/*
	@Override//çebişevi
	public int heuristicFunction(SearchObject startPoint, SearchObject endPoint) {
		return Math.max(Math.abs(((Tuple) startPoint).getX() - ((Tuple) endPoint).getX()),
				Math.abs(((Tuple) startPoint).getY() - ((Tuple) endPoint).getY()));
	}
*/
	//manhatten
		public int heuristicFunction(SearchObject startPoint, SearchObject endPoint) {
			return Math.abs(((Tuple) startPoint).getX() - ((Tuple) endPoint).getX()) +
					Math.abs(((Tuple) startPoint).getY() - ((Tuple) endPoint).getY());
		}

	@Override
	public Result search(SearchObject startPoint, SearchObject endPoint)
			throws MaxIterationAmountExceededException, NoImageLoadException {

		if (getImage() == null) {
			throw new NoImageLoadException();
		}

		List<PathNode> searchList = new ArrayList<>();
		int iteration = 0;

		searchList.add(new PathNode(null, (Tuple) startPoint, 0));

		Deque<SearchObject> path = new ArrayDeque<>();
		long startTime = System.currentTimeMillis();
		int topQueueSize = 0;
		for (PathNode point = getSearchElement(searchList, (Tuple) endPoint); point != null; point = getSearchElement(
				searchList, (Tuple) endPoint)) {
			if (iteration == MAX_ITERATION) {
				throw new MaxIterationAmountExceededException(new SearchResult(null, 0,
						new Time(System.currentTimeMillis() - startTime), iteration, topQueueSize));
			}

			if (searchList.size() > topQueueSize) {
				topQueueSize = searchList.size();
			}

			if (point.getData().equals(endPoint)) {
				long finishTime = System.currentTimeMillis() - startTime;
				ImageService.drawRedLine((BufferedImage) getImage(), point);
				ImageService.drawRedLine((BufferedImage) getImage(), searchList);
				ImageService.saveImage(getImage(), "output-stack.jpg");

				double distance = point.getDistance();

				while (point != null) {
					path.add(point.getData());
					point = point.getPrevious();
				}

				return new SearchResult(path, distance, new Time(finishTime), iteration,
						topQueueSize);
			}

			populateSearchQueueWithNeigborsOfAPixel(point, searchList);
			iteration++;
		}

		return null;
	}

	@Override
	public double costOfAPixel(Tuple pixel) {
		int p = ((((BufferedImage) getImage()).getRGB(pixel.getX(), pixel.getY())));

		int r = (p >> 16) & 0xff;
		int g = (p >> 8) & 0xff;
		int b = p & 0xff;

		return (double) 1 / ((double) r / (r + g + b + 1) + 1);

//		return (double) 1 / ((((BufferedImage) getImage()).getRGB(pixel.getX(), pixel.getY()) >> 16) & 0xff + 1);
	}

	private PathNode getSearchElement(List<PathNode> searchList, Tuple endPoint) {
		PathNode minDistancePath = searchList.get(0);
		double minsScore = 0;
		double nodesScore = 0;
		for (PathNode node : searchList) {
			minsScore = heuristicFunction(minDistancePath.getData(), endPoint) + minDistancePath.getDistance();
			nodesScore = heuristicFunction(node.getData(), endPoint) + node.getDistance();

			if (nodesScore < minsScore) {
				minDistancePath = node;
			}
		}
		searchList.remove(minDistancePath);
		return minDistancePath;
	}
}
