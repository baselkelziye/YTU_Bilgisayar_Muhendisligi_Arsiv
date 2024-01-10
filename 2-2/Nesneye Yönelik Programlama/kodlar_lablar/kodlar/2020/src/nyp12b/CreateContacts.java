package nyp12b;

import java.util.*;
import java.io.*;

public class CreateContacts {
	public static void main(String[] args) {
		LinkedList<Contact> contacts = new LinkedList<Contact>();
		Scanner input = new Scanner( System.in );
		System.out.println("This program saves information of your " +
				" contacts to a file on your drive.");
		System.out.print("How many contacts will you enter? ");
		int contactCount = input.nextInt( );
		input.nextLine( );
		for( int i = 0; i < contactCount; i++ ) {
			System.out.print("What is the name of the contact #"+(i+1)+"? ");
			Contact aContact = new Contact( input.nextLine() );
			System.out.print("What is the phone number of this contact? ");
			aContact.setPhone( input.nextLine() );
			System.out.print("What is the e-mail address of this contact? ");
			aContact.setEMail( input.nextLine() );
			contacts.add(aContact);
		}
		try {
			String fileName = "contacts.dat";
			ObjectOutputStream yazici = new ObjectOutputStream( 
					new FileOutputStream( fileName )  );
			yazici.writeObject( contacts );
			yazici.close();
			System.out.println("The information you have entered has "
					+ "been successfully saved in file " + fileName);
		} 
		catch( IOException e ) {
			System.out.println("An exception has occured during writing to file.");
			e.printStackTrace();
		}
		input.close();
	}
}
