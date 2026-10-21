package hospital;

import java.util.ArrayList;

public class Room {
    private static int nextRoomNumber = 1;
    private int roomNumber;
    private int durationOfStay;
    private ArrayList<Treatment> treatments;

    public Room(int durationOfStay) {
        this.durationOfStay = durationOfStay;
        roomNumber = nextRoomNumber++;
        treatments = new ArrayList<>();
    }

    public int getRoomNumber(){
        return nextRoomNumber;
    }

    public void addTreatment(Treatment a){
        if(a == null) return;
        for(Treatment b: treatments){
            if(b.equals(a)) return;
        }
        treatments.add(a);
    }

    @Override
    public String toString() {
        return "Room{" +
                "RoomNumber=" + roomNumber +
                ", durationOfStay=" + durationOfStay + " days" +
                '}';
    }
}
