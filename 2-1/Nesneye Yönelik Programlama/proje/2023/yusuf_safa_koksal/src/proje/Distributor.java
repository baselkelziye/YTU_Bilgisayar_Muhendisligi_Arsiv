package proje;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Hashtable;
import java.util.LinkedList;
import java.util.List;
import java.util.Vector;

public class Distributor implements Runnable {
	private Hashtable<String,Journal> journals;
	private Vector<Subscriber> subscribers;
	
	public Distributor() {
		journals=new Hashtable<String,Journal>();
		subscribers=new Vector<Subscriber>();
		loadState("data.ser");
	}
	
	public boolean addJournal(Journal journal) { 
		if(journals.containsKey(journal.getIssn())) {
			System.out.println("Eklemek istediginiz dergi zaten mevcut!");
			return false;
		}
		
		journals.put(journal.getIssn(), journal);
		return true;
	}
	
	public boolean deleteJournal(String issn) {
		if(journals.containsKey(issn)) {
			journals.remove(issn);
			System.out.println(issn+ " issn numaralı dergi başarıyla silindi.");
			return true;
		}
		
		return false;
	}
	
	public Journal searchJournal(String issn) { 
		if(journals.containsKey(issn)) {
			return journals.get(issn);
		}
		System.out.println("Aradiginiz dergi bulunamadi.");
		return null;
	}
	
	public boolean addSubscriber(Subscriber subscriber) {
		if(subscribers.contains(subscriber)) {
			System.out.println("Eklemek istediginiz abone zaten mevcut!");
			return false;
		}
		
		subscribers.add(subscriber);
		return true;
	}
	
	public boolean deleteSubscriber(Subscriber sub) {
		if(subscribers.contains(sub)) {
			subscribers.remove(sub);
			System.out.println(sub.getName()+" isimli abonelik başarıyla silindi.");
			return true;
		}
		
		return false;
	}
	
	public Subscriber searchSubscriber(String name) {
		for(Subscriber sub:subscribers) {
			if(sub.getName().equals(name)) {
				return sub;
			}
		}
		System.out.println("Aradiginiz abone bulunamadi");
		return null;
	}
	
	public boolean addSubscription(String issn, Subscription subscription, Subscriber subscriber) {
		if(!subscribers.contains(subscriber)) {
			return false;
		}
		
		if(!journals.containsKey(issn)) {
			return false;
		}
		
		if(subscription.getSubscriber()==subscriber && subscription.getJournal()==journals.get(issn)) {
			subscription.setCopies(subscription.getCopies()+1);
			return true;
		}
		return false; 
	}
	
	public void listAllSendingOrders(int month, int year) { 
		for(Journal journal:journals.values()) {
			for(Subscription subscription:journal.getSubscriptions()) {
				if(subscription.getDates().getStartYear()==year && subscription.canSend(month)) {
					System.out.println(journal.getName()+" dergisi "+subscription.getSubscriber().getName()+" adlı kişiye gönderildi.");
				}
			}
		}
	}
	
	public void listSendingOrders(String issn, int month, int year) { 
		Journal currentJournal=journals.get(issn);
		for(Subscription subscription:currentJournal.getSubscriptions()) {
			if(subscription.getDates().getStartYear()==year && subscription.canSend(month)) {
				System.out.println(currentJournal.getName()+" dergisi "+subscription.getSubscriber().getName()+" adlı kişiye gönderildi.");
			}
		}
	}
	
	public void listlncompletePayments(String issn, int month, int year) {
		Journal currentJournal=journals.get(issn);
		for(Subscription subscription:currentJournal.getSubscriptions()) {
			if(subscription.getDates().getStartYear()==year && !subscription.canSend(month)) {
				System.out.println(currentJournal.getName()+" dergisi "+subscription.getSubscriber().getName()+" adlı kişiye gönderildi.");
			}
		}
	}
	
	public void listSubscriptionsByName(String subscriberName) {
		for(Journal journal:journals.values()) {
			for(Subscription subscription:journal.getSubscriptions()) {
				if(subscription.getSubscriber().getName().equals(subscriberName)) {
					System.out.println(subscription.toString());
				}
			}
		}
	}
	
	public void listSubscriptionsByIssn(String issn) {
		for(Journal journal:journals.values()) {
			if(journal.getIssn().equals(issn)) {
				for(Subscription subscription:journal.getSubscriptions()) {
					System.out.println(subscription.toString());
				}
			}
		}
	}
	
	public synchronized void saveState(String fileName) {
		try {
		     FileOutputStream fileOut = new FileOutputStream(fileName);
		     ObjectOutputStream out = new ObjectOutputStream(fileOut);
		     out.writeObject(journals);
		     out.writeObject(subscribers);
		     out.close();
		     fileOut.close();
		     System.out.println("Veriler kaydedildi");
	    } 
		catch (IOException i) {
	         i.printStackTrace();
	    }
	}
	
	public synchronized void loadState(String fileName) {
		  try {
		     FileInputStream fileIn = new FileInputStream(fileName);
		     ObjectInputStream in = new ObjectInputStream(fileIn);
		 
		     journals = (Hashtable<String,Journal>) in.readObject();
		     subscribers=(Vector<Subscriber>)in.readObject();
		
		     in.close();
		     fileIn.close();
		  } catch (IOException i) {
		     i.printStackTrace();
		     return;
		  } catch (ClassNotFoundException c) {
		     System.out.println("Class not found");
		     c.printStackTrace();
		     return;
		  }
	}
	
	public String report(int month, int year) {
		double receivedAnnualPayments=0;
		String result="";
		for(Journal journal:journals.values()) {
			for(Subscription subscription:journal.getSubscriptions()) {
				if(subscription.getDates().getStartYear()+1<year) {
					System.out.println("Suresı dolan abonelik --> "+subscription.toString());
					result+="Suresı dolan abonelik --> "+subscription.toString()+"\n";
				}
				else if(subscription.getDates().getStartYear()+1==year) {
					if(subscription.getDates().getEndMonth()<month) {
						System.out.println("Suresı dolan abonelik --> "+subscription.toString());
						result+="Suresı dolan abonelik --> "+subscription.toString()+"\n";
					}
				}
				else if(subscription.getDates().getStartYear()==year) {
					if(subscription.getDates().getEndMonth()==12) {
						System.out.println("Suresı dolan abonelik --> "+subscription.toString());
						result+="Suresı dolan abonelik --> "+subscription.toString()+"\n";
					}
				}
			}
		}
		
		for(Journal journal:journals.values()) {
			for(Subscription subscription:journal.getSubscriptions()) {
				if(subscription.getDates().getStartYear()==year) {
					receivedAnnualPayments+=subscription.getPayment().getReceivedPayment();
				}
			}
		}
		
		System.out.println(year+ " yilinda odenen toplam tutar: "+receivedAnnualPayments);
		result+= year+" yilinda odenen toplam tutar: " + receivedAnnualPayments;
		return result;
	}
	
	public Collection<Journal> getJournals(){
		return journals.values();
	}
	
	public Collection<Subscriber> getSubscribers(){
		return subscribers;
	}

	@Override
	public void run() {
		//report();
	}
}
