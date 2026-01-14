import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

public class Repository<T extends Identifiable> {
    private Map<String, T> items = new HashMap<>();

    public void add(T item) {
        items.put(item.getId(), item);
    }

    public T findById(String id) throws ItemNotFoundException {
        T t = items.get(id);
        if (t == null) {
            throw new ItemNotFoundException("ID not found " + id);
        }
        return t;
    }

    public Collection<T> getAll() {
        return items.values();
    }
}
