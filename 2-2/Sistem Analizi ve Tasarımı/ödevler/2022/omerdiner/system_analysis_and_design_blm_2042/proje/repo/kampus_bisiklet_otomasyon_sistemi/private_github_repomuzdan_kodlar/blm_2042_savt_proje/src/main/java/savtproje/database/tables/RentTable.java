package savtproje.database.tables;

import com.google.gson.Gson;
import savtproje.database.AbstractTable;
import savtproje.database.entities.*;

import java.util.LinkedList;
import java.util.Random;


public class RentTable extends AbstractTable<Rent> {

    public static final String JSON_PATH = "database/rents.json";

    public RentTable() {
        super(JSON_PATH);
    }

    public boolean isBicycleRented(int bicycleID) {
        for(Rent x : table) {
            if(x.bicycleID == bicycleID) return true;
        }
        return false;
    }

    public LinkedList<Rent> getAllRentHistoryOf(int bicycleID) {
        return findAll(rent -> rent.bicycleID == bicycleID);
    }

    public void createNewRent(int studentID, int bicycleID, int mins) {
        Rent rent = new Rent(Math.abs(new Random().nextInt()), studentID, bicycleID, mins);
        add(rent);
        save();
    }

}