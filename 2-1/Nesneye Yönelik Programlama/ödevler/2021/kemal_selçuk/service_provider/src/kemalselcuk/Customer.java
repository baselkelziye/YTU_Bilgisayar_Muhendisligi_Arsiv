package kemalselcuk;

public abstract class Customer {
	private String CitizenshipNr;	//attributes
	private String name,tel,mail;
	public Customer(String citizenshipNr) {		//constructor
		CitizenshipNr = citizenshipNr;
	}
	public String getCitizenshipNr() {
		return CitizenshipNr;
	}
	public void setCitizenshipNr(String citizenshipNr) {
		CitizenshipNr = citizenshipNr;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getTel() {
		return tel;
	}
	public void setTel(String tel) {
		this.tel = tel;
	}
	public String getMail() {
		return mail;
	}
	public void setMail(String mail) {
		this.mail = mail;
	}
	
	
	
}
