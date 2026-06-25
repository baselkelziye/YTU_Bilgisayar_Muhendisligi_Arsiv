package yusufsafakoksal;

import java.util.LinkedList;

public class Patient implements IMedicalPersonel {
	private String name;
	private LinkedList<Treatment> treatments;
	
	public Patient(String name) {
		this.name = name;
		treatments=new LinkedList<Treatment>();
	}
	
	public LinkedList<Treatment> getTreatments(){
		return treatments;
	}

	@Override
	public String getName() {
		return this.name;
	}

	@Override
	public String toString() {
		return "Patient [name=" + name + ", treatments=" + treatments + "]";
	}
}
