package artificial.intelligence.assignment.one.search;

import java.awt.Image;
import java.io.IOException;
import java.util.Collection;

import artificial.intelligence.assignment.one.image.ImageService;
import artificial.intelligence.assignment.one.model.PathNode;
import artificial.intelligence.assignment.one.model.Tuple;

public abstract class AbstractImageSearch {
	protected static final long MAX_ITERATION = 100000;
	
	private Image image;

	public AbstractImageSearch() {
		super();
		image = null;
	}

	protected Image getImage() {
		return image;
	}

	protected void setImage(Image image) {
		this.image = image;
	}

	public void populateSearchQueueWithNeigborsOfAPixel(PathNode pixel, Collection<PathNode> searchQueue) {
		int x = pixel.getData().getX();
		int y = pixel.getData().getY();

		for (int i = x - 1; i < x + 2; i++) {
			for (int j = y - 1; j < y + 2; j++) {
				if (i != x || j != y) {
					try {
						Tuple tuple = new Tuple(i, j);
						double distance = pixel.getDistance() + costOfAPixel(tuple);
						searchQueue.add(new PathNode(pixel, tuple, distance));

					} catch (IndexOutOfBoundsException e) {
						// ignoring the exception
					}
				}
			}
		}
	}

	public void loadImage(String path) throws IOException {
		setImage(ImageService.openImage(path));
	}

	public abstract double costOfAPixel(Tuple pixel);
}
