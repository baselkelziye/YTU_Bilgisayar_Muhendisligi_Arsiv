package artificial.intelligence.assignment.one;

import java.io.IOException;

import artificial.intelligence.assignment.one.exception.MaxIterationAmountExceededException;
import artificial.intelligence.assignment.one.exception.NoImageLoadException;
import artificial.intelligence.assignment.one.model.Tuple;
import artificial.intelligence.assignment.one.search.ImageFirstBestSearchStackUsed;
import artificial.intelligence.assignment.one.search.ImageFirstBestSearchHeapUsed;

public class Main {
	public static void main(String[] args) {
		System.out.println("The current working directory is " + System.getProperty("user.dir"));

		ImageFirstBestSearchStackUsed stackSearch = new ImageFirstBestSearchStackUsed();
		ImageFirstBestSearchHeapUsed heapSearch = new ImageFirstBestSearchHeapUsed();
		try {
			stackSearch.loadImage("1.JPG");
			heapSearch.loadImage("1.JPG");
			System.out.println("Stack: " + stackSearch.search(new Tuple(20, 30), new Tuple(400, 800)));
			System.out.println("Queue: " + heapSearch.search(new Tuple(20, 30), new Tuple(400, 800)));
		} catch (IOException | MaxIterationAmountExceededException | NoImageLoadException e) {
			e.printStackTrace();
		}
	}
}
