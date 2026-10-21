package department_information;

public abstract class Staff {
	
	private String mail;
	private String name;
	private String web;
	private int staff_id;
	
	public Staff(int staff_id,String name, String web) {
		this.name = name;
		this.web = web;
		this.staff_id = staff_id;
	}
	
	public Staff(int staff_id, String name, String web, String mail) {
		this.mail = mail;
		this.name = name;
		this.web = web;
		this.staff_id = staff_id;
	}

	public String getMail() {
		return mail;
	}

	public void setMail(String mail) {
		this.mail = mail;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getWeb() {
		return web;
	}

	public void setWeb(String web) {
		this.web = web;
	}

	public int getStaff_id() {
		return staff_id;
	}
	
	public abstract void print_staff_information();

	
	
}
