package kemalselcuk;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.LinkedList;




public class Management {
	private String name;
	
	public Management(String name) {
		this.name = name;
	}

	public void saveBookings(LinkedList<Customer> list) {
		
		try {
	         FileOutputStream fileOut = new FileOutputStream("myfile.ser");
	         ObjectOutputStream out = new ObjectOutputStream(fileOut);
	         out.writeObject(list);
	         out.close();
	         fileOut.close();
	      } catch (IOException i) {
	         i.printStackTrace();
	      }
	   }
		
	

	public void customerInfo(Customer c4) {
		LinkedList<Customer> okunacak_liste;
	      try {
	         FileInputStream fileIn = new FileInputStream("myfile.ser");
	         ObjectInputStream in = new ObjectInputStream(fileIn);
	         
	         
	         okunacak_liste = (LinkedList<Customer>) in.readObject();
	    
	         in.close();
	         fileIn.close();
	      } catch (IOException i) {
	         i.printStackTrace();
	         return;
	      } catch (ClassNotFoundException c) {
	         System.out.println("Employee class not found");
	         c.printStackTrace();
	         return;
	      }
	      
	      int flag=1;
	      for(Customer iter: okunacak_liste) {
	    	  
	    	  if(c4.getId() == iter.getId()) {
	    	  System.out.println("Customer Name: " + iter.getName());
	    	  System.out.println("Room Number: " + iter.getR().getNo());
	    	  System.out.println("Stay Time: " + iter.getDays());
	    	  System.out.println("Total Cost: " + iter.getR().getPrice() * iter.getDays());
	    	  flag = 0;
	    	  }
	      }
	      if(flag == 1) {
	    	  System.out.println("Customer Not Found!");
	      }

	}

	public void changeBooking(Customer c3, int k) {
		LinkedList<Customer> okunacak_liste;
	      try {
	         FileInputStream fileIn = new FileInputStream("myfile.ser");
	         ObjectInputStream in = new ObjectInputStream(fileIn);
	         
	         
	         okunacak_liste = (LinkedList<Customer>) in.readObject();
	    
	         in.close();
	         fileIn.close();
	      } catch (IOException i) {
	         i.printStackTrace();
	         return;
	      } catch (ClassNotFoundException c) {
	         System.out.println("Employee class not found");
	         c.printStackTrace();
	         return;
	      }
	      for(Customer iter: okunacak_liste) {
	    	  
	    	  if(c3.getId() == iter.getId()) {
	    		  iter.setDays(10);
	    	  }
	      }
	      Management mng = new Management("Big Five Hotel");
	      mng.saveBookings(okunacak_liste);
	}
	      
		
	

	public String getName() {
		return name;
	}
	

}
