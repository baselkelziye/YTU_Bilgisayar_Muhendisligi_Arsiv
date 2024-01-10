package nyp12a;

import java.io.*;

public class ShowContacts {
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
	catch( IOException e ) {
		System.out.println("An exception has occured during file reading.");
		e.printStackTrace();
	} 
	catch( ClassNotFoundException e ) {
		System.out.println("An exception has occured while processing read records.");
		e.printStackTrace();
	}
  }
}//Alternative: You could populate an array, too.
