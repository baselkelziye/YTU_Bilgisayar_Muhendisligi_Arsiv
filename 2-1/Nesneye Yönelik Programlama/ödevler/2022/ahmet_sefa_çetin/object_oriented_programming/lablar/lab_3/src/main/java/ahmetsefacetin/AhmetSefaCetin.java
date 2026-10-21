package ahmetsefacetin;

public class AhmetSefaCetin {

    public static void main(String[] args) {
        FireDepartment fireDepartment = new FireDepartment();

        Firefighter firefighter1 = new Firefighter("Firefighter Jacob");
        Firefighter firefighter2 = new Firefighter("Firefighter Halsin");
        Victim victim1 = new Victim("Henry Dovsen");
        Victim victim2 = new Victim("Lily Robin");

        EmergencyProcedure emergencyProcedure1 = new EmergencyProcedure("First Aid", 3, 0.0);
        EmergencyProcedure emergencyProcedure2 = new EmergencyProcedure("Oxygen Therapy", 5, 1000.0);

        System.out.println("****** Firefighters ******");
        FireDepartment.showList(Firefighter.getFirefighterList());

        System.out.println("\n****** Emergency Procedures ******");
        fireDepartment.assignVictimToFirefighter(firefighter1, victim1, emergencyProcedure1);
        fireDepartment.assignVictimToFirefighter(firefighter2, victim2, emergencyProcedure2);

        System.out.println("\n****** Firefighters after interventions ******");
        FireDepartment.showList(Firefighter.getFirefighterList());
    }
}
