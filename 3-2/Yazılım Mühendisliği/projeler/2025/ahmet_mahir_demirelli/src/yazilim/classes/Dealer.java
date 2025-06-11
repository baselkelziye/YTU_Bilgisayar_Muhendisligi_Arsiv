package yazilim.classes;

public class Dealer {
    private int id;
    private String email;

    public Dealer(int id, String email) {
        this.id = id;
        this.email = email;
    }
    
    public Dealer() {
    	
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
    	return "Dealer{" +
		        "id=" + id +
		        ", email='" + email + '\'' +
		        '}';
	}
}
