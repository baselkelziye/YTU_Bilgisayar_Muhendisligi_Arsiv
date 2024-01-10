package nyp12b;

import java.io.*;
import java.util.*;

public class ShowContacts {
@SuppressWarnings("unchecked")
  public static void main( String[] args ) {
	String fileName = "contacts.dat";
	try {
		ObjectInputStream reader = new ObjectInputStream( 
				new FileInputStream( fileName ) );
		LinkedList<Contact> contacts = (LinkedList<Contact>)reader.readObject();
		for( Contact aContact : contacts ) {
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

}
