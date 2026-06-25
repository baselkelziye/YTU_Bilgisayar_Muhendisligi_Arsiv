package paket1;

public class Main {

	public static void main(String[] args) {
		Car nissan_gtr = new Car("34 AA 12","nissan","GTR R35");
		Person batuhan= new Person("Batuhan","Odçıkın",20);
		
		System.out.println(nissan_gtr.getPlate());
		System.out.println(batuhan.getName());
		
		nissan_gtr.setOwner(batuhan);
		batuhan.setCar(nissan_gtr);
		
		System.out.println(nissan_gtr.getOwner().getSurname());
		System.out.println(batuhan.getCar().getBrand());
		
	}
}
