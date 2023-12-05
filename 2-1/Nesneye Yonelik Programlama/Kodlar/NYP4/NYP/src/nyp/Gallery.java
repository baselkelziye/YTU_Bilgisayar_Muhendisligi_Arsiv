package nyp;

import java.util.Scanner;

public class Gallery {
    private String galleryName;
    private Car[] cars;
    private int carCount;
    private Person galleryOwner;

    public Gallery(String galleryName, Person galleryOwner, int capacity) {
        this.galleryName = galleryName;
        this.galleryOwner = galleryOwner;
        carCount = 0;
        cars = new Car[capacity];
    }

    public String getGalleryName() {
        return galleryName;
    }

    public void setGalleryName(String galleryName) {
        this.galleryName = galleryName;
    }
    
    public int addCar(Car araba){
        Scanner temp = new Scanner(System.in);
        if(!searchCar(araba) && carCount < cars.length/* && araba.getOwner() == galleryOwner*/){
            cars[carCount] = araba;
            carCount++;
            return 0;
        }else{
            if(searchCar(araba)){
                return 1; //araba galeride oldugu icin ekleyemedim.
            /*else if(araba.getOwner() != galleryOwner){
                System.err.println("Galeri sahibiyle araç sahibi aynı kişi değil" +
                        "\nEğer bu aracı galeri sahibinin üzerine almak istiyorsanız " +
                        "1'i, eklemek istemiyorsanız 0'ı giriniz!!");
                if(temp.nextInt() == 1){
                    araba.setOwner(galleryOwner);
                    cars[carCount] = araba;
                    carCount++;
                    return 0;
                }else
                    return 3; //bu araba galeri sahibinin uzerine olmadigi icin ekleyemedim.*/
            }else
                return 2; //galerinin kapasitesi doldugu icin ekleyemedim.
        }
    }
    
    public boolean searchCar(Car oto){
        for (Car dizidekiarabalar : cars) 
            if(dizidekiarabalar == oto)
                return true;
        return false;
    }
    
    public Car searchCar(String plakaNo){
        for (int i = 0; i < carCount; i++)
            if(cars[i].getPlate().compareTo(plakaNo) == 0 )
                return cars[i];
        return null;
    }
    
    public Car removeCar(String plakaNo){
        for (int i = 0; i < carCount; i++)
            if(cars[i].getPlate().compareTo(plakaNo) == 0){
                Car theCar = cars[i];
                carCount--;
                for (int j = i; j < carCount; j++)
                    cars[j] = cars[j+1];
                cars[carCount] = null;
                return theCar;
            }
        return null;   
    }
    
    public boolean sellCar(String plakaNo, Person sahip){
        Car satilan = removeCar(plakaNo);
        if(satilan == null){
            return false;
        }else{
            satilan.setOwner(sahip);
            return true;
        }
    }
    
    public String introduceSelf(){
        String intro = "";
        intro = intro + "\nBu galerinin ismi: " + getGalleryName() +
                "\nSahibinin ismi: " + galleryOwner.getName() + 
                " Şuan bu galeride " + carCount + " adet araba satılıktır.\n";
        return intro;
    }
}
