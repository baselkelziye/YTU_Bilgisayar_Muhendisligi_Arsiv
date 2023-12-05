package nyp;

public class NYP4 {
    public static void main(String[] args){
        Person furkan = new Person("Furkan");
        Gallery galeri = new Gallery("Furkan'ın Galerisi", furkan, 3);
        Person mehmet = new Person("Mehmet");
        Car araba1 = new Car("34ABC123", furkan);
        Car araba2 = new Car("34ABC456", mehmet);
        Car araba3 = new Car("34ABC789", mehmet);
        
        int state = galeri.addCar(araba1);
        if(state == 0)
            System.out.println(araba1.getPlate() + " plakalı araba galeriye eklendi.");
        else if(state == 1)
            System.out.println("Aynı araba var !!! EKLEYEMEYİZ");
        else if(state == 2)
            System.out.println("Kapasite dolu olduğu için yeni araba EKLEYEMİYORUZ !!");
        else
            System.out.println("Araba'nın sahibi galeri sahibinden farklı olduğu için EKLEYEMEDİM !!");
        
        state = galeri.addCar(araba1);
        if(state == 0)
            System.out.println(araba1.getPlate() + " plakalı araba galeriye eklendi.");
        else if(state == 1)
            System.out.println("Aynı araba var !!! EKLEYEMEYİZ");
        else if(state == 2)
            System.out.println("Kapasite dolu olduğu için yeni araba EKLEYEMİYORUZ !!");
        else
            System.out.println("Araba'nın sahibi galeri sahibinden farklı olduğu için EKLEYEMEDİM !!");
        
        state = galeri.addCar(araba2);
        if(state == 0)
            System.out.println(araba2.getPlate() + " plakalı araba galeriye eklendi.");
        else if(state == 1)
            System.out.println("Aynı araba var !!! EKLEYEMEYİZ");
        else if(state == 2)
            System.out.println("Kapasite dolu olduğu için yeni araba EKLEYEMİYORUZ !!");
        else
            System.out.println("Araba'nın sahibi galeri sahibinden farklı olduğu için EKLEYEMEDİM !!");
        
        state = galeri.addCar(araba3);
        if(state == 0)
            System.out.println(araba3.getPlate() + " plakalı araba galeriye eklendi.");
        else if(state == 1)
            System.out.println("Aynı araba var !!! EKLEYEMEYİZ");
        else if(state == 2)
            System.out.println("Kapasite dolu olduğu için yeni araba EKLEYEMİYORUZ !!");
        else
            System.out.println("Araba'nın sahibi galeri sahibinden farklı olduğu için EKLEYEMEDİM !!");
    
        System.out.println(galeri.introduceSelf());
        
        Car tempCar = galeri.removeCar("34ABC123");
        if(tempCar == null)
            System.out.println("Silmek istediğini plakalı araç yoktur !!");
        else
            System.out.println("Araç SİLİNDİ");
        
        System.out.println(galeri.introduceSelf());
        
        //System.out.println(furkan.introduceSelf());
    }   
}
