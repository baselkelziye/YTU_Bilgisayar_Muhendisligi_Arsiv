package artificial.intelligence.assignment.one.image;

import java.awt.Image;
import java.awt.image.BufferedImage;
import java.awt.image.RenderedImage;
import java.io.File;
import java.io.IOException;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.Collection;

import javax.imageio.ImageIO;

import artificial.intelligence.assignment.one.model.PathNode;

public class ImageService {
	private ImageService() {
		super();
	}

	public static Image openImage(String imagePath) throws IOException {
		URL url = null;
		try {
			url = new URL(imagePath);
		} catch (MalformedURLException e) {
			return ImageIO.read(new File(imagePath));
		}
		return ImageIO.read(url);
	}
	
	public static void drawRedLine(BufferedImage image, PathNode path) {
		while (path != null) {
			image.setRGB(path.getData().getX(), path.getData().getY(), 0x000000);
			path = path.getPrevious();
		}
	}
	
	public static void drawRedLine(BufferedImage image, Collection<PathNode> path) {
		for(PathNode node: path) {
			image.setRGB(node.getData().getX(), node.getData().getY(), 0x0000ff);
		}
	}
	
	public static void saveImage(Image image, String imageName) {
		try {
			ImageIO.write((RenderedImage) image, "jpg", new File(imageName));
		} catch (IOException e) {
			System.out.println("Could not save image!");
			e.printStackTrace();
		}
	}
}