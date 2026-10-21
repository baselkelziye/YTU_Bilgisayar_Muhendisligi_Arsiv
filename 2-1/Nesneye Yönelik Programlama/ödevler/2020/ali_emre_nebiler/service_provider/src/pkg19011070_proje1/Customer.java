package pkg19011070_proje1;

public abstract class Customer {

    private String CitizenshipNr;
    private String name, tel, mail;
    
    public Customer(String CitizenshipNr, String name) {
        this.CitizenshipNr = CitizenshipNr;
        this.name = name;
    }
    
    public String getCitizenshipNr() {
        return CitizenshipNr;
    }

    public void setCitizenshipNr(String CitizenshipNr) {
        this.CitizenshipNr = CitizenshipNr;
    }
    
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
    
    // not used but can be used if neccessary
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
