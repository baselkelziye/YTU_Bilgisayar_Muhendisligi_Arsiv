package savtproje.database;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import savtproje.database.entities.Bicycle;
import savtproje.database.entities.Review;
import savtproje.database.entities.Student;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;
import java.util.function.Predicate;


public abstract class AbstractTable<T> {

    protected final String jsonPath;
    public final LinkedList<T> table = new LinkedList<>();

    public AbstractTable(String jsonPath) {
        this.jsonPath = jsonPath;
    }

    public T find(Predicate<T> func) {
        for(T t : table) {
            if(func.test(t)) return t;
        }
        return null;
    }

    public void add(T t) {
        table.add(t);
    }

    public boolean remove(T t) {
        return table.remove(t);
    }

    public boolean removeAll(LinkedList<T> list) {
        return table.removeAll(list);
    }

    public LinkedList<T> findAll(Predicate<T> func) {
        LinkedList<T> matches = new LinkedList<>();

        for(T t : table) {
            if(func.test(t)) matches.add(t);
        }

        return matches;
    }

    public LinkedList<T> getAllRows() {
        return new LinkedList<>(table);
    }

    public void save() {
        try {
            Gson gson = new GsonBuilder().setPrettyPrinting().serializeNulls().create();
            String jsonContent = gson.toJson(this);
            Files.writeString(Path.of(this.jsonPath), jsonContent);
        }
        catch (IOException e) { throw new RuntimeException(e); }
    }

}
