package com.taskagitmakas.hog;


 
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import org.opencv.core.Core;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import org.opencv.core.MatOfPoint;
import org.opencv.core.Point;
import org.opencv.core.Scalar;
import org.opencv.core.Size;
import org.opencv.imgproc.Imgproc;

public class ColorBlobDetector {
    // Lower and Upper bounds for range checking in HSV color space
    private Scalar mLowerBound = new Scalar(0);
    private Scalar mUpperBound = new Scalar(0);
    // Minimum contour area in percent for contours filtering
    private static double mMinContourArea = 0.1;
    // Color radius for range checking in HSV color space
    private Scalar mColorRadius = new Scalar(25,50,50,0); 
    private Mat mSpectrum = new Mat();
    private List<MatOfPoint> mContours = new ArrayList<MatOfPoint>();
	private Imshow showBinaryImage, showHSVImage, showImageAftermorphologyOperation;

    // Cache
    Mat mPyrDownMat = new Mat();
    Mat mHsvMat = new Mat();
    Mat mMask = new Mat();
    Mat mDilatedMask = new Mat();
    Mat mHierarchy = new Mat();
    Mat mGray = new Mat();
    
    public ColorBlobDetector(){
    	
    	showBinaryImage=new Imshow("Binary Resim");
    	showHSVImage=new Imshow("HSV Resim");
    	showImageAftermorphologyOperation=new Imshow("Morphology İşleminden Sonra Resim");

    }
    
    public void setColorRadius(Scalar radius) {
        mColorRadius = radius;
    }

    public void setHsvColor(Scalar hsvColor) {
       
/*	    	 
    mLowerBound.val[0] = (hsvColor.val[0] > 10) ? hsvColor.val[0] - 10 : 0;
		mUpperBound.val[0] = (hsvColor.val[0] < 245) ? hsvColor.val[0] + 10 : 255;

		mLowerBound.val[1] = (hsvColor.val[1] > 130) ? hsvColor.val[1] - 100 : 30;
		mUpperBound.val[1] = (hsvColor.val[1] < 155) ? hsvColor.val[1] + 100 : 255;

		mLowerBound.val[2] = (hsvColor.val[2] > 130) ? hsvColor.val[2] - 100 : 30;
		mUpperBound.val[2] = (hsvColor.val[2] < 155) ? hsvColor.val[2] + 100 : 255;

		mLowerBound.val[3] = 0;
		mUpperBound.val[3] = 255;
 */
    	
    	double minH = (hsvColor.val[0] >= mColorRadius.val[0]) ? hsvColor.val[0]-mColorRadius.val[0] : 0;
        double maxH = (hsvColor.val[0]+mColorRadius.val[0] <= 255) ? hsvColor.val[0]+mColorRadius.val[0] : 255;

        mLowerBound.val[0] = minH;
        mUpperBound.val[0] = maxH;

        mLowerBound.val[1] = hsvColor.val[1] - mColorRadius.val[1];
        mUpperBound.val[1] = hsvColor.val[1] + mColorRadius.val[1];

        mLowerBound.val[2] = hsvColor.val[2] - mColorRadius.val[2];
        mUpperBound.val[2] = hsvColor.val[2] + mColorRadius.val[2];

        mLowerBound.val[3] = 0;
        mUpperBound.val[3] = 255;

        Mat spectrumHsv = new Mat(1, (int)(maxH-minH), CvType.CV_8UC3);

        for (int j = 0; j < maxH-minH; j++) {
            byte[] tmp = {(byte)(minH+j), (byte)255, (byte)255};
            spectrumHsv.put(0, j, tmp);
        }

        Imgproc.cvtColor(spectrumHsv, mSpectrum, Imgproc.COLOR_HSV2RGB_FULL, 3); 
    }

    public Mat getSpectrum() {
        return mSpectrum;
    }

    public void setMinContourArea(double area) {
        mMinContourArea = area;
    }

    public void process(Mat rgbaImage) {
    	
        Imgproc.pyrDown(rgbaImage, mPyrDownMat);
        Imgproc.pyrDown(mPyrDownMat, mPyrDownMat);
        Imgproc.cvtColor(mPyrDownMat, mHsvMat, Imgproc.COLOR_RGB2HSV_FULL,3);
 
        showHSVImage.showImage(mHsvMat);

        Core.inRange(mHsvMat, mLowerBound, mUpperBound, mMask);
        showBinaryImage.showImage(mMask);
        mMask.copyTo(mGray);
        mMask.copyTo(mDilatedMask);

   /*    
        Mat kernel=Imgproc.getStructuringElement(Imgproc.MORPH_ELLIPSE,new Size(17,17),new Point(8,8));
        Mat kernel2=Imgproc.getStructuringElement(Imgproc.MORPH_ELLIPSE,new Size(5,5),new Point(0,0));

        Imgproc.erode(mMask, mDilatedMask, kernel2);
        Imgproc.dilate(mDilatedMask, mDilatedMask,kernel);
        */

        Mat kernel=Imgproc.getStructuringElement(Imgproc.MORPH_ELLIPSE,new Size(17,17),new Point(8,8));
        Imgproc.erode(mMask, mDilatedMask, new Mat());
        Imgproc.dilate(mDilatedMask, mDilatedMask,kernel);
        showImageAftermorphologyOperation.showImage(mDilatedMask);
        List<MatOfPoint> contours = new ArrayList<MatOfPoint>();
  
        
        
        
 
        Imgproc.findContours(mDilatedMask, contours, mHierarchy, Imgproc.RETR_EXTERNAL, Imgproc.CHAIN_APPROX_SIMPLE);

        // Find max contour area
        double maxArea = 0;
        Iterator<MatOfPoint> each = contours.iterator();
        while (each.hasNext()) {
            MatOfPoint wrapper = each.next();
            double area = Imgproc.contourArea(wrapper);
            if (area > maxArea)
                maxArea = area;
        }

        // Filter contours by area and resize to fit the original image size
        mContours.clear();
        each = contours.iterator();
        while (each.hasNext()) {
            MatOfPoint contour = each.next();
            if (Imgproc.contourArea(contour) > mMinContourArea*maxArea) {
                Core.multiply(contour, new Scalar(4,4), contour);
                mContours.add(contour);
            }
        }
    }

    public List<MatOfPoint> getContours() {
        return mContours;
    }
}


