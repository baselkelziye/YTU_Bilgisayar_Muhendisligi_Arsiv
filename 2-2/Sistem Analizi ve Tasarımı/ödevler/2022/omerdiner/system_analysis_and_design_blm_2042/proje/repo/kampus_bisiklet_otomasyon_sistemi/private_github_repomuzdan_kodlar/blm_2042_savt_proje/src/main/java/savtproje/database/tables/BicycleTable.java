package savtproje.database.tables;

import com.google.gson.Gson;
import savtproje.database.AbstractTable;
import savtproje.database.entities.Bicycle;

import java.util.Random;

public class BicycleTable extends AbstractTable<Bicycle> {

    public static final String JSON_PATH = "database/bicycles.json";

    public BicycleTable() {
        super(JSON_PATH);
    }


    public void addNewBicycle(String brand, String model, int year, int cost) {
        Bicycle bicycle = new Bicycle(Math.abs(new Random().nextInt()), brand, model, year, cost);
        add(bicycle);
        save();
    }
}