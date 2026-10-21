package com.taskagitmakas.hog;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
 

import com.taskagitmakas.dao.ImageDao;
import com.taskagitmakas.dao.ImageImp;
import com.taskagitmakas.entity.Image;

import weka.classifiers.Evaluation;
import weka.classifiers.functions.SMO;
import weka.classifiers.lazy.IBk;
import weka.core.Instances;




public class TestHog {

	
	public static ImageDao imageService=new ImageImp();
	public static List<Image> myTrainSet,myTestSet,myTestSetNoTrainedUser;

	
	public static BufferedReader readDataFile(String filename) {
		BufferedReader inputReader = null;
 
		try {
			inputReader = new BufferedReader(new FileReader(filename));
		} catch (FileNotFoundException ex) {
			System.err.println("File not found: " + filename);
		}
 
		return inputReader;
	}
 
	public static void createWekaFile(){
		myTrainSet = imageService.all(false);
		myTestSet = imageService.all(true);
		myTestSetNoTrainedUser=imageService.all(10);
		
		try{
		    PrintWriter myTrainWriter = new PrintWriter("myTrain.arff", "UTF-8");
		    myTrainWriter.println("@relation handDescriptionTrain");
		    myTrainWriter.println("@attribute class {1, 2, 3}");
		    for(int i=0;i<myTrainSet.get(0).getRowCount();i++){
		    	myTrainWriter.println("@attribute feature"+i+" numeric");
 	
		    }
		    
		    myTrainWriter.println("@data");
		   
		    for (Image image : myTrainSet) {
		    	myTrainWriter.println(image.getClassType()+","+image.getHogDescriptionVector().substring(0,image.getHogDescriptionVector().length()-1));
 
			} 
		    myTrainWriter.close();
		    
		    /*---------------------*/
		    PrintWriter myTestWriter = new PrintWriter("myTest.arff", "UTF-8");
		    myTestWriter.println("@relation handDescriptionTest");
		    myTestWriter.println("@attribute class {1, 2, 3}");
		    for(int i=0;i<myTestSet.get(0).getRowCount();i++){
		    	myTestWriter.println("@attribute feature"+i+" numeric");
 	
		    }
		    
		    myTestWriter.println("@data");
		   
		    for (Image image : myTestSet) {
		    	myTestWriter.println(image.getClassType()+","+image.getHogDescriptionVector().substring(0,image.getHogDescriptionVector().length()-1));
 
			} 
		    myTestWriter.close();
		    
		    /*--------------*/

		    PrintWriter myTestNoTrainedUserWriter = new PrintWriter("myTestNoTrainedUser.arff", "UTF-8");
		    myTestNoTrainedUserWriter.println("@relation handDescriptionTestNoTrainedUser");
		    myTestNoTrainedUserWriter.println("@attribute class {1, 2, 3}");
		    for(int i=0;i<myTestSetNoTrainedUser.get(0).getRowCount();i++){
		    	myTestNoTrainedUserWriter.println("@attribute feature"+i+" numeric");
 	
		    }
		    
		    myTestNoTrainedUserWriter.println("@data");
		   
		    for (Image image : myTestSetNoTrainedUser) {
		    	myTestNoTrainedUserWriter.println(image.getClassType()+","+image.getHogDescriptionVector().substring(0,image.getHogDescriptionVector().length()-1));
 
			} 
		    myTestNoTrainedUserWriter.close();
		    
		    
		    
		} catch (IOException e) {
		   // do something
		}		
		
	}
 
	public static void main(String[] args) throws Exception {
		
		createWekaFile();
		BufferedReader trainDatafile = readDataFile("myTrain.arff");
		BufferedReader testDatafile = readDataFile("myTest.arff");
		BufferedReader testNoTrainedUserDatafile = readDataFile("myTestNoTrainedUser.arff");
 		Instances trainData = new Instances(trainDatafile);
 		trainData.setClassIndex(0);
 		
 		Instances testData = new Instances(testDatafile);
 		testData.setClassIndex(0);
 		
 		Instances testNoTrainedUserData = new Instances(testNoTrainedUserDatafile);
 		testNoTrainedUserData.setClassIndex(0);
 		
		 
		System.out.println("Trainin Data Size:"+trainData.size());
		System.out.println("Test Data Size:"+testData.size());
		System.out.println("TestNoTrainedUser Data Size:"+testNoTrainedUserData.size());
 		
 		IBk ibk=new IBk();
 		ibk.buildClassifier(trainData);
		Evaluation evaluation=new Evaluation(trainData);
		evaluation.evaluateModel(ibk, testData);
		
		System.out.println(evaluation.toSummaryString("------------Result-------------",true));
		 System.out.println(evaluation.toMatrixString());
 
   
	}


}