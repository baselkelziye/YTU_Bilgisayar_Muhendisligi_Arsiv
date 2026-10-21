package ahmetsefacetin;

import java.util.ArrayList;

public class EmergencyRoom {
    private static int nextEmergencyRoomNumber = 0;
    private int emergencyRoomNumber;
    private int durationOfStay;
    private ArrayList<EmergencyProcedure> emergencyProcedures;

    public EmergencyRoom(int durationOfStay) {
        emergencyRoomNumber = nextEmergencyRoomNumber;
        nextEmergencyRoomNumber++;
        this.durationOfStay = durationOfStay;
        this.emergencyProcedures = new ArrayList<EmergencyProcedure>();
    }

    public int getEmergencyRoomNumber() {
        return emergencyRoomNumber;
    }

    public void addEmergencyProcedure(EmergencyProcedure emergencyProcedure) {
        emergencyProcedures.add(emergencyProcedure);
    }

    @Override
    public String toString() {
        return "EmergencyRoom{" + "emergencyRoomNumber=" + emergencyRoomNumber + ", durationOfStay=" + durationOfStay + ", emergencyProcedures=" + emergencyProcedures + '}';
    }
    
    
    
    
}
