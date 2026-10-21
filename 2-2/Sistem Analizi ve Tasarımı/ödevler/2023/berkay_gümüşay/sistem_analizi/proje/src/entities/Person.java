package Entities;

public abstract class Person {
    private String name;
    private String surname;
    private String TC;
    private String birthDate;


    public Person(String name, String surname, String TC, String birthDate) {
        this.name = name;
        this.surname = surname;
        this.TC = TC;
        this.birthDate = birthDate;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSurname() {
        return surname;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public String getTC() {
        return TC;
    }

    public void setTC(String TC) {
        this.TC = TC;
    }

    public String getBirthDate() {
        return birthDate;
    }

    public void setBirthDate(String birthDate) {
        this.birthDate = birthDate;
    }
}
