package yazilim.classes;

public class Warehouse {
    private int id;
    private String email;

    public Warehouse(int id, String email) {
        this.id = id;
        this.email = email;
    }
    
    public Warehouse() {
    	
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    
    @Override
	public String toString() {    
    	return  "Warehouse{" +
		        "id=" + id +
		        ", email='" + email + '\'' +
		        '}';
	}
}
