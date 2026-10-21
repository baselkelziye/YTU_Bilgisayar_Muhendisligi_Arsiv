package tr.com.berkaytutal.beslenmedanismani.Utils;

import java.io.Serializable;

/**
 * Created by berka on 10.06.2017.
 */

public class ProgramDifficultyPOJO implements Serializable {
    private int id;
    private String name;

    public ProgramDifficultyPOJO(int id, String name) {
        this.id = id;
        this.name = name;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return name;
    }
}
