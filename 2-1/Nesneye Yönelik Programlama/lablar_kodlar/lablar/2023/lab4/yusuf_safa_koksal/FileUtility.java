package yusufsafakoksal;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class FileUtility {
	
	public static List<Staff> readStaffFromFile(String fileName){
		Staff newPerson;
		
		List<Staff> staffList=new ArrayList<Staff>();

		try {
	      File myObj = new File("Staff.txt");
	      Scanner myReader = new Scanner(myObj);
	      
	      while (myReader.hasNextLine()) {
	        String data = myReader.nextLine();
	        System.out.println(data);
	        String[] splittedArray = data.split(",");
	        
	        double salary = Double.parseDouble(splittedArray[2]);
	        if(splittedArray[0]=="Academic") {
	        	int numberOfCourses = Integer.parseInt(splittedArray[3]);
	        	newPerson=new AcademicStaff(splittedArray[1],salary,numberOfCourses);
	        }
	        else {
	        	newPerson=new Staff(splittedArray[1],salary);
	        }
	        
	        staffList.add(newPerson);
		  } 
	      myReader.close();
		} 
		catch (FileNotFoundException e) 
		{
	      System.out.println("An error occurred.");
	      e.printStackTrace();
	    }
		
		return staffList;
	}
	
	public static void writeStaffToFile(List<Staff> staffList, String fileName) {
		try {
	      FileWriter myWriter = new FileWriter(fileName);
	      
	      for(Staff person:staffList) {
	    	  if(person!=null) {
	    		  
	    		  if(person instanceof AcademicStaff) {
	    			  AcademicStaff newPerson=(AcademicStaff)person;
	    			  myWriter.write("Academic,"+newPerson.getName()+","+newPerson.getSalary()+","+newPerson.getNumberOfCourses()+"\n");
	    			  
	    		  }
	    		  else {
	    			  myWriter.write("Staff,"+person.getName()+","+person.getSalary()+"\n");
	    		  }
	    	  }
	      }
	    } 
		catch (IOException e) {
	      System.out.println("An error occurred.");
	      e.printStackTrace();
	    }
	}
}
