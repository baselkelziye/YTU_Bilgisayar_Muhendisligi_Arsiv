package Hospital;

class Treatment {
 private String medication;
 private int restPeriodDays;
 private double surgeryCost;

 public Treatment(String medication, int restPeriodDays, double surgeryCost) {
     this.medication = medication;
     this.restPeriodDays = restPeriodDays;
     this.surgeryCost = surgeryCost;
 }

 @Override
 public String toString() {
     return "Medication: " + medication + ", Rest Period: " + restPeriodDays + " days, Surgery Cost: $" + surgeryCost;
 }

}

