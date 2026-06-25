package mertguler;

//import java.util.*;

public class Main {
    public static void main(String[] args) {
 
            RentACarCompany rentACarCompany = new RentACarCompany("Global Rent A Car");

            // Araç nesneleri
            Car car1 = new PassengerCar(1, "Toyota", "Corolla", 50);
            Car car2 = new CommercialCar(2, "Ford", "Transit", 100);
            Car car3 = new TransportCar(3, "Mercedes", "Sprinter", 120, 20); // 20 yolcu kapasiteli

            // Araç listesine ekleme
            rentACarCompany.getCarList().add(car1);
            rentACarCompany.getCarList().add(car2);
            rentACarCompany.getCarList().add(car3);

            // Müşteri şirketleri
            CustomerCompany customer1 = new CustomerCompany("Company A");
            CustomerCompany customer2 = new CustomerCompany("Company B");

            // Araç kiralamaları
            rentACarCompany.rentCar(customer1, car1);
            rentACarCompany.rentCar(customer1, car2);
            rentACarCompany.rentCar(customer2, car3);

            // En sık kiralayan müşteri
            System.out.println("Most frequent customer: " + rentACarCompany.mostFrequentCustomer());

            // Kiralanan gun sayisi uzerinden herbir sirketin toplam maliyetini hesaplama
            int rentalDays = 30;
            rentACarCompany.calculateTotalCosts(rentalDays);
            
            //100 km'lik yolculuk icin, litre fiyatı 45 TL olan benzin üzerinden toplam maliyet
            System.out.println("Fuel costs for car1: "+ car1.calculateFuelCost(100, 45) + " TL");
          
        }

        
}

