package nyp12c;

public class Contact implements java.io.Serializable {
	private static final long serialVersionUID = 1L;
	private String name, phone, eMail;
	public Contact( String name ) { this.name = name; }
	public String getName( ) { return name; }
	public String getPhone( ) { return phone; }
	public void setPhone( String telefon ) {
		this.phone = telefon;	}
	public String getEMail( ) { return eMail; }
	public void setEMail( String mail ) { eMail = mail; }
	public String toString( ) {
		return name + " - " + phone + " - " + eMail;
	}
}
