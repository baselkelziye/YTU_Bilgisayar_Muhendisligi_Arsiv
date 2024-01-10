package lab4_2021;

import java.util.LinkedList;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;

public class Management {

	private LinkedList<Customer> first_list;
	private LinkedList<Customer> readed_list;

	public Management(String string) {
		
	}

	public void saveBookings(LinkedList<Customer> list) {
		first_list = list;
		try{
			ObjectOutputStream out = new ObjectOutputStream(new FileOutputStream("bookings.ser"));
			out.writeObject(list);
			out.close();
			}catch(IOException e){
				e.printStackTrace();
			}
		
	}
	
	@SuppressWarnings("unchecked")
	public void getList(){
		try{
			ObjectInputStream in = new ObjectInputStream(new FileInputStream("bookings.ser"));
			readed_list = (LinkedList<Customer>) in.readObject();
			in.close();
			}catch(IOException e){
				e.printStackTrace();
			} catch (ClassNotFoundException e) {
				
				e.printStackTrace();
			}
		
	}


	
	public void changeBooking(Customer c, int day) {
		
		for(Customer iter:first_list){
			if(iter.getSSN()==c.getSSN()){
				iter.setDays(day);
				break;
			}
		}
		
		saveBookings(first_list);
		
		
	}
	
	public String customerInfo(Customer c){
		getList();
		for(Customer iter: readed_list){
			if(iter.getSSN()==c.getSSN()){
				System.out.println("Customer Name: "+ iter.getName());
				System.out.println("Room Number: "+ iter.getRoom().getNumber());
				System.out.println("Stay Time: "+ iter.getDays() + " days");
				System.out.println("Total Cost: "+ iter.getDays()*iter.getRoom().getPrice());
				return "";
			}
			
			
		}
		
		System.out.println("Customer not found!");
		return "";
		
		
	}

	
	
	

}
