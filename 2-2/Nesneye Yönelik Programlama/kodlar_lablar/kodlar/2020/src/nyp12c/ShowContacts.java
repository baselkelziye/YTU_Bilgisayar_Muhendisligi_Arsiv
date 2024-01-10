package nyp12c;

import java.io.*;

public class ShowContacts {
  public static void main( String[] args ) {
	String fileName = "contacts.dat";
	try {
		ObjectInputStream reader = new ObjectInputStream( 
				new FileInputStream( fileName ) );
		Contact[] contacts = (Contact[])reader.readObject();
		for( Contact aContact : contacts )
			System.out.println(aContact);
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
