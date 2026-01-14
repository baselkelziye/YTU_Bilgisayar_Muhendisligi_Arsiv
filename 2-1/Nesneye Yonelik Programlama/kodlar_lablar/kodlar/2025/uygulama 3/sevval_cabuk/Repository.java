package Uyg3;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;

// Generics + Interface + HashMap örneği
public class Repository<T extends Identifiable> {

    private Map<String, T> items = new HashMap<>();

    public void add(T item) {
        items.put(item.getId(), item);
    }

    public T findById(String id) throws ItemNotFoundException {
        T t = items.get(id); //HashMap'te get() metoduna parametre olarak key verilir, value değerine ulaşılır.
        if (t == null) {
            throw new ItemNotFoundException("ID bulunamadı: " + id);
        }
        return t;
    }

    public Collection<T> getAll() {
        return items.values();
    }
}
