package yazilim.classes;

import java.sql.Timestamp;

public class Customer {
    private int customerId;
    private String email;
    private String firstName;
    private String lastName;
    private String phoneNumber;
    private String gender;
    private int age;
    private String profession;
    private String incomeLevel;
    private String city;
    private Timestamp firstVisitDate;

    public Customer(int customerId, String email, String firstName, String lastName,
                    String phoneNumber, String gender, int age, String profession, String incomeLevel,
                    String city, Timestamp firstVisitDate) {
        this.customerId = customerId;
        this.email = email;
        this.firstName = firstName;
        this.lastName = lastName;
        this.phoneNumber = phoneNumber;
        this.gender = gender;
        this.age = age;
        this.profession = profession;
        this.incomeLevel = incomeLevel;
        this.city = city;
        this.firstVisitDate = firstVisitDate;
    }
    
    public Customer() {
    	
    }

    public int getCustomerId() {
        return customerId;
    }

    public void setCustomerId(int customerId) {
        this.customerId = customerId;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public String getProfession() {
        return profession;
    }

    public void setProfession(String profession) {
        this.profession = profession;
    }

    public String getIncomeLevel() {
        return incomeLevel;
    }

    public void setIncomeLevel(String incomeLevel) {
        this.incomeLevel = incomeLevel;
    }

    public String getCity() {
        return city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public Timestamp getFirstVisitDate() {
        return firstVisitDate;
    }

    public void setFirstVisitDate(Timestamp firstVisitDate) {
        this.firstVisitDate = firstVisitDate;
    }
    
    @Override
	public String toString() {
	    return "Customer{" +
	            "customerId=" + customerId +
	            ", email='" + email + '\'' +
	            ", firstName='" + firstName + '\'' +
	            ", lastName='" + lastName + '\'' +
	            ", phoneNumber='" + phoneNumber + '\'' +
	            ", gender='" + gender + '\'' +
	            ", age=" + age +
	            ", profession='" + profession + '\'' +
	            ", incomeLevel='" + incomeLevel + '\'' +
	            ", city='" + city + '\'' +
	            ", firstVisitDate=" + firstVisitDate +
	            '}';
	}
}
