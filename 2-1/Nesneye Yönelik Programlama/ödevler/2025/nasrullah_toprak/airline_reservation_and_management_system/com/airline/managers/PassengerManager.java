package com.airline.managers;

import com.airline.models.Passenger;
import com.airline.util.FileUtil;
import java.util.*;

public class PassengerManager {
    private static final String FILE = "data/passengers.txt";
    private List<Passenger> passengers = new ArrayList<>();

    public PassengerManager() {
        load();
    }

    private void load() {
        for (String line : FileUtil.readAllLines(FILE)) {

            if (line == null || line.trim().isEmpty()) {
                continue;
            }

            String[] p = line.split(";");

            if (p.length != 4) {
                System.out.println("⚠️ Skipped invalid passenger line: " + line);
                continue;
            }

            passengers.add(new Passenger(
                    p[0].trim(),
                    p[1].trim(),
                    p[2].trim(),
                    p[3].trim()));
        }
    }

    public void addPassenger(Passenger p) {
        passengers.add(p);
        save();
    }

    private void save() {
        List<String> lines = new ArrayList<>();
        for (Passenger p : passengers) {
            lines.add(p.getPassengerID() + ";" + p.getName() + ";" + p.getSurname() + ";" + p.getContactInfo());
        }
        FileUtil.writeAllLines(FILE, lines);
    }

    public List<Passenger> getAllPassengers() {
        return passengers;
    }
}