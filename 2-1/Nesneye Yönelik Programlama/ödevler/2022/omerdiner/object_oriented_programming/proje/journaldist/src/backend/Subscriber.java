package backend;

import java.io.Serial;
import java.io.Serializable;

public abstract class Subscriber implements Serializable {
    @Serial
    private static final long serialVersionUID = 1L;
    private  String name;
    private String address;

    public Subscriber(String name, String address) {
        this.name = name;
        this.address = address;
    }

    public abstract  String getBillingInformation();

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getAddress() {
        return address;
    }

    public void setAddress(String address) {
        this.address = address;
    }

    @Override
    public String toString() {
        return "Subscriber{" +
                "name='" + name + '\'' +
                ", address='" + address + '\'' +
                '}';
    }
}
