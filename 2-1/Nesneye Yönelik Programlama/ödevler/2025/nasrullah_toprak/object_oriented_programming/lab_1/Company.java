package nasrullahtoprak;

public class Company {
    private String companyName;
    private Tour[] tours;
    private Ticket[] tickets;
    private Staff[] staff;

    public Company(String companyName, int tourCount, int ticketCount, int staffCount){
        this.companyName=companyName;
        this.tours = new Tour[tourCount];
        this.tickets = new Ticket[ticketCount];
        this.staff = new Staff[staffCount];
    }

    public void addTour(Tour tour){
        int i = 0;
        while(this.tours[i] != null){
            i++;
        }
        this.tours[i] = tour;
    }

    public void addTicket(Ticket ticket){
        int i = 0;
        while(this.tickets[i] != null){
            i++;
        }
        this.tickets[i] = ticket;
    }

    public void listTours(){
        int i=0;
        System.out.println("--- Available Tours ---");
        while(tours[i]!=null){
            System.out.println("Tour: " + tours[i].getTourName() + " | City: " + tours[i].getCity() + " | Price: " + tours[i].getPrice() + "$");
            i++;
        }
    }

    public void listTickets(){
        int i=0;
        System.out.println("--- Available Tickets ---");
        while(tickets[i]!=null){
            System.out.println("From: " + tickets[i].getArrival() + " | To: " + tickets[i].getDeparture() + " | Airplane: " + tickets[i].getAirlineCompany() + " | Price " + tickets[i].getPrice() + "$");
            i++;
        }
    }

    public void searchTour(String tourCity){
        int i=0;
        boolean success=true;
        System.out.println("Tours found in " + tourCity);
        while(tours[i]!=null){
            if(tours[i].getCity().equalsIgnoreCase(tourCity)){
                System.out.println("Tour name: " + tours[i].getTourName() + " | Price: " + tours[i].getPrice() + "$");
            }
            i++;
        }
        if (!success){
            System.out.println("No tours found in: " + tourCity);
        }
    }

    public void searchCheapestTicket(String cityName){
        int i=0;
        int min=0;
        boolean found = true;
        while(tickets[i]!=null && found){
            if(tickets[i].getDeparture().equalsIgnoreCase(cityName)){
                found=false;
                min=i;
            }
            i++;
        }
        while(tickets[i]!=null){
            if(tickets[i].getPrice()<tickets[min].getPrice() && tickets[i].getDeparture().equalsIgnoreCase(cityName)){
                min=i;
            }
            i++;
        }
        System.out.println("Cheapest ticket to " + tickets[min].getDeparture() + " is " + tickets[min].getPrice() + "$ from " + tickets[min].getAirlineCompany());
    }

    public void showCitiesWithToursAndFlights(){
        System.out.println("cities that have both a tour and a flight available: ");
        int count = 0;
        String[] common = new String[3];
        int j=0;
        int k;
        int m;
        boolean found = false;

        while(tours[j]!=null){
            k=0;
            while(tickets[k]!=null){
                found=false;
                if(tours[j].getCity().equalsIgnoreCase(tickets[k].getDeparture())){
                    for(m=0;m<count;m++){
                        if (tickets[k].getDeparture().equalsIgnoreCase(common[m])){
                            found = true;
                        }
                    }
                    if(!found){ //not found in common
                        System.out.println("- " + tickets[k].getDeparture());
                        common[count] = tickets[k].getDeparture();
                        count++;
                    }
                }
                k++;
            }
            j++;
        }

        System.out.println("\nSummary list:");
        for(j=0;j<count;j++){
            System.out.println("- " + common[j]);
        }
    }


    public void addStaff(Staff staff){
        int i = 0;
        while(this.staff[i] != null){
            i++;
        }
        this.staff[i] = staff;
    }

    public double averageStaffSalary(){
        int count=0;
        double average;
        double total=0;
        int i=0;
        while(staff[i]!=null){
            total+= staff[i].getSalary();
            count++;
            i++;
        }
        if(count==0){
            average=0.0;
        }else{
            average=total/count;
        }
        return average;
    }

    public int findOldestStaffAge(){
        int max = staff[0].getAge();
        int i=1;
        while(staff[i]!=null){
            if(staff[i].getAge()>max){
                max=staff[i].getAge();
            }
            i++;
        }
        return max;
    }
}
