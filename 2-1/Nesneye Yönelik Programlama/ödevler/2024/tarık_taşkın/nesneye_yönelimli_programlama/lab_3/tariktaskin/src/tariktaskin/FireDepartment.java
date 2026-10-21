package tariktaskin;

import java.util.ArrayList;
import java.util.List;

public class FireDepartment {
	private ArrayList<Firefighter> rescuePersonnelList;
	
	public FireDepartment() {
		super();
		rescuePersonnelList = new ArrayList<Firefighter>();
	}
	
	public void addRescuePersonnel(Firefighter personnel) {
		rescuePersonnelList.add(personnel);
	}
	
	public void assignVictimToFirefighter(Firefighter fireFighter, Victim victim, EmergencyProcedure procedure) {
		int dailyFee=100;
		int totalFee=0;
		int success = 1;
		int i=0;
		
		while(i<2 && success==1) {
			try {
				fireFighter.performRescue();
				int rand = (int) Math.random()*11;
				EmergencyRoom room = new EmergencyRoom(rand);
				room.addEmergencyProcedure(procedure);
				System.out.println(fireFighter.getName() + " performed succesful intervention on " + victim);
				System.out.println("Prescribed Emergency Procedure: " + procedure);
				System.out.println("Allocated Emergency Room: " + room );
				
				totalFee += dailyFee;
				System.out.println("Daily Fee for " + victim + ": $" + dailyFee);
				System.out.println("Total Fee for " + victim + ": $" + totalFee);
			
				System.out.println("******* Emergency Procedure End ******");
				System.out.println();
				
			} catch (RescueUnsuccesfulException e) {
				System.out.println(e.getMessage());
				System.out.println(victim + " was not succesfully rescued.");
				System.out.println("Total Fee for " + victim + ": $" + totalFee);
				System.out.println("******* Emergency Procedure Fail ******");
				System.out.println();
				success = 0;
			}
			i++;
		}
		
	}
	
	public static <Z> void showList(List<Z> fireFighters) {
		for(Z x : fireFighters) {
			System.out.println(x);
		}
	}
}
