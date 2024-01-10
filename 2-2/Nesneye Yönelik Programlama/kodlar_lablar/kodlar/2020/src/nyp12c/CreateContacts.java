package nyp12c;

import java.util.*;
import java.io.*;

public class CreateContacts {
	public static void main(String[] args) {
		Scanner input = new Scanner( System.in );
		System.out.println("This program saves information of your " +
				" contacts to a file on your drive.");
		System.out.print("How many contacts will you enter? ");
		Integer contactCount = input.nextInt( );
		Contact[] contacts = new Contact[contactCount];
		input.nextLine( );
		for( int i = 0; i < contactCount; i++ ) {
			System.out.print("What is the name of the contact #"+(i+1)+"? ");
			contacts[i] = new Contact( input.nextLine() );
			System.out.print("What is the phone number of this contact? ");
			contacts[i].setPhone( input.nextLine() );
			System.out.print("What is the e-mail address of this contact? ");
			contacts[i].setEMail( input.nextLine() );
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
}//HW: Do not use an array 

