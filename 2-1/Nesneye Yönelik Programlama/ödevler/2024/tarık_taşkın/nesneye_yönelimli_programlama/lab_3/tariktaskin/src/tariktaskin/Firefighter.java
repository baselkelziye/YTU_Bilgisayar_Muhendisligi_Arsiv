package tariktaskin;

import java.util.ArrayList;

public class Firefighter implements IRescuer, IMedicalPersonnel{
	private static ArrayList<Firefighter> fireFighterList = new ArrayList<>();
	private String name;
	private double experience=0;
	private int interventions;

	public Firefighter(String name) {
		super();
		this.name = name;
		fireFighterList.add(this);
	}

	public static ArrayList<Firefighter> getFirefighterList() {
		return fireFighterList;
	}

	public double getInterventions() {
		return interventions;
	}

	@Override
	public String toString() {
		return "FireFighter: " + name + ", Experience:" + experience + ", interventions:" + interventions + "]";
	}

	@Override
	public String getName() {
		return name;
	}

	@Override
	public void performRescue() throws RescueUnsuccesfulException {
		double perform = Math.random();
		if(perform<0.2) {
			throw new RescueUnsuccesfulException("Rescue by " + getName() + " unsuccesfull.");
		}else {
			experience += 2.5;
			interventions++;
		}
	}
	
	

}
