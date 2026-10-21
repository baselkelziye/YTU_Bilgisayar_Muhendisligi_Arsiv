package lab3_2023;
import java.util.List;

public class InfoClass<T, E> {
	T obj1;
	E obj2;
	
    public static<T> void getObjectInfo(T obj) {
        System.out.println("Object Info: " + obj.toString());
    }

    public static<E> void getListInfo(List<E> list) {
        System.out.println("List Info: " + list.toString());
    }
}
