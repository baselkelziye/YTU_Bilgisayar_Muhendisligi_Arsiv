package mertguler;

public class Applicant {
    private String name;
    private String passportNumber;
    private boolean hasWorkPermit;


    public Applicant(String name, String passportNumber, boolean hasWorkPermit) {
        this.name = name;
        this.passportNumber = passportNumber;
        this.hasWorkPermit = hasWorkPermit;
    }

    public String getName() {
        return name;
    }

    public String getPassportNumber() {
        return passportNumber;
    }

    public boolean hasWorkPermit() {
        return hasWorkPermit;
    }

    @Override
    public String toString() {
        String turkceWorkPermit = "Yok";
        if (hasWorkPermit) {
            turkceWorkPermit = "Var";
        }
        return "Basvuru Sahibi: " + name + "\nPasaport Numarasi: " + passportNumber + "\nCalisma Izni: " + turkceWorkPermit;
    }
}

