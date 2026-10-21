package yelizCengiz;

public class Patient extends Person{

	private Rendezvous rendezvous;
	
	public Patient(String name, long national_id) {
		super(name, national_id);
	}
	
	public Patient(String name, long national_id, Rendezvous rendezvous) {
		super(name, national_id);
		this.rendezvous = rendezvous;
	}

	public void setRendezvous(Rendezvous r) {
		this.rendezvous=r;
	}

	public Rendezvous getRendezvous() {
		return rendezvous;
	}
	@Override
	public String toString() {
		return getName();
	}
}
