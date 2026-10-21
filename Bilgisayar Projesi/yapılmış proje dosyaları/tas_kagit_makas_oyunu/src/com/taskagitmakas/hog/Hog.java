package com.taskagitmakas.hog;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import org.opencv.core.Core;
import org.opencv.core.Mat;
import org.opencv.core.MatOfFloat;
import org.opencv.core.MatOfPoint;
import org.opencv.core.Size;
import org.opencv.highgui.Highgui;
import org.opencv.imgproc.Imgproc;
import org.opencv.objdetect.HOGDescriptor;

import com.taskagitmakas.dao.ImageDao;
import com.taskagitmakas.dao.ImageImp;
import com.taskagitmakas.entity.Image;
import com.taskagitmakas.form.LoginForm;

public class Hog {

	private String directoryPath;
	private Size blockSize;
	private Size cellSize;
	private Size blockStride;
	private Size winStride;
	private Size padding;
	private int bin;
	public List<MatOfFloat> descriptorsList;
	public List<MatOfPoint> locationsList;
	public ImageDao imageService;

	public Hog(Size blockSize, Size cellSize, Size blockStride, Size winStride, Size padding,
			int bin) {
  
		
		this.blockSize = blockSize; //new Size(8, 8)
		this.cellSize = cellSize;//new Size(4, 4)
		this.blockStride = blockStride;//new Size(4, 4)
		this.winStride = winStride;//new Size(0, 0)
		this.padding = padding;//new Size(0, 0)
		this.bin = bin; //9
		this.blockSize = new Size(8, 8);
		this.cellSize = new Size(4, 4);
		this.blockStride = new Size(4, 4);
		this.winStride = new Size(0, 0);
		this.padding =new Size(0, 0);
		this.bin = 9;
		
		descriptorsList = new ArrayList<MatOfFloat>();
		locationsList = new ArrayList<MatOfPoint>();
		imageService = new ImageImp();
	}
	public Hog() {
  
		this.blockSize = new Size(8, 8);
		this.cellSize = new Size(4, 4);
		this.blockStride = new Size(4, 4);
		this.winStride = new Size(0, 0);
		this.padding =new Size(0, 0);
		this.bin = 9;
		
		descriptorsList = new ArrayList<MatOfFloat>();
		locationsList = new ArrayList<MatOfPoint>();
		imageService = new ImageImp();
	}
	public void addFromImageFile(String path, int classType) {

		Mat img = new Mat();
		img = Highgui.imread(path);
		
		DateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd-HH-mm-ss-SSS");
		Date date = new Date();			
		Highgui.imwrite("train/"+dateFormat.format(date)+"_"+classType+".jpg",img);
		Imgproc.resize(img, img, new Size(64, 48));
		Imgproc.cvtColor(img, img, Imgproc.COLOR_RGB2GRAY);
		MatOfFloat descriptor = new MatOfFloat();
		MatOfPoint location = new MatOfPoint();
		HOGDescriptor hogDescriptor = new HOGDescriptor(new Size(64, 48), blockSize, blockStride, cellSize, bin);
		hogDescriptor.compute(img, descriptor, winStride, padding, location);
		String myDescription = "";
			for (int j = 0; j < descriptor.rows(); j++) {
	
				myDescription = myDescription + descriptor.get(j, 0)[0] + ",";
	
			}

		Image image = new Image();
		image.setRowCount(descriptor.rows());
		image.setColCount(descriptor.cols());
		image.setHogDescriptionVector(myDescription);
		image.setClassType(classType);
		imageService.insert(image);
	}

	public void addFromMat(Mat img, int classType,boolean isTest) {
		System.loadLibrary(Core.NATIVE_LIBRARY_NAME);
		DateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd-HH-mm-ss-SSS");
		Date date = new Date();
		Highgui.imwrite("train/"+dateFormat.format(date)+"_"+LoginForm.selectedUser.getId()+"_"+classType+".jpg",img);
		Imgproc.resize(img, img, new Size(64, 48));
		Imgproc.cvtColor(img, img, Imgproc.COLOR_RGB2GRAY);
		MatOfFloat descriptor = new MatOfFloat();
		MatOfPoint location = new MatOfPoint();
		HOGDescriptor hogDescriptor = new HOGDescriptor(new Size(64, 48), blockSize, blockStride, cellSize, bin);
		hogDescriptor.compute(img, descriptor, winStride, padding, location);
		
		String myDescription = "";
			for (int j = 0; j < descriptor.rows(); j++) {
	
				myDescription = myDescription + descriptor.get(j, 0)[0] + ",";
			}
		Image image = new Image();
		image.setRowCount(descriptor.rows());
		image.setColCount(descriptor.cols());
		image.setHogDescriptionVector(myDescription);
		image.setClassType(classType);
		image.setUserId(LoginForm.selectedUser.getId());
		image.setTest(isTest);
		System.out.println("ClassType: "+classType+" ,isTest: "+isTest);
		imageService.insert(image);
	}
	
	public double[] getDescriptionFromMat(Mat img) {
		
		DateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd-HH-mm-ss-SSS");
		Date date = new Date();
		Highgui.imwrite("test/"+dateFormat.format(date)+".jpg",img);
		Imgproc.resize(img, img, new Size(64, 48));
		Imgproc.cvtColor(img, img, Imgproc.COLOR_RGB2GRAY);
		MatOfFloat descriptor = new MatOfFloat();
		MatOfPoint location = new MatOfPoint();
		HOGDescriptor hogDescriptor = new HOGDescriptor(new Size(64, 48), blockSize, blockStride, cellSize, bin);
		hogDescriptor.compute(img, descriptor, winStride, padding, location);
		double[] query=new double[descriptor.rows()];

		for (int j = 0; j < descriptor.rows(); j++) {

			query[j]=descriptor.get(j, 0)[0];
		}

		 return query;
	}

	public void addfromDirectory(String path) {


		Mat image = new Mat();
		image = Highgui.imread(directoryPath + path);
		Imgproc.resize(image, image, new Size(64, 48));
		Imgproc.cvtColor(image, image, Imgproc.COLOR_RGB2GRAY);
		MatOfFloat descriptor = new MatOfFloat();
		MatOfPoint location = new MatOfPoint();
		HOGDescriptor hogDescriptor = new HOGDescriptor(new Size(64, 48), blockSize, blockStride, cellSize, bin);
		hogDescriptor.compute(image, descriptor, winStride, padding, location);
		descriptorsList.add(descriptor);
		locationsList.add(location);
	}

}
