package nyp12a;

import java.io.*;

public class ShowContactsV2 {
  public static void main( String[] args ) {
	String fileName = "contacts.dat";
	try {
		ObjectInputStream reader = new ObjectInputStream( 
				new FileInputStream( fileName ) );
		Integer contactCount = (Integer) reader.readObject();
		for( int i=0; i<contactCount; i++ ) {
			Contact aContact = (Contact)reader.readObject();
			System.out.println(aContact);
		}
		reader.close();
	} 
	catch( IOException | ClassNotFoundException e ) {
		System.out.println("An exception has occured during file reading or class loading.");
		e.printStackTrace();
	} 
  }
}//Alternative: You could populate an array, too.
