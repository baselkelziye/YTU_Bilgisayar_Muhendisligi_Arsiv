package nyp06;

public class Main {

	public static void main(String[] args) {
		Item anItem = new Toy("Iþýn kýlýcý","123445",10);
		System.out.println(anItem.getDescription());
		System.out.println(Item.getType());
		Child ahmet = new Child("Ahmet Küçük",5); //5 aylýk
		Toy lego = new Toy("123456","Lego Star Wars",4); //4 yaþ
		Clothing pinny = new Clothing("86978945","mama önlüðü",0,24); //0-24 ay
		if( lego.isSuitable(ahmet) )
			System.out.println("Deneme 1 hatalý");
		else
			System.out.println("Deneme 1 tamam");
		if( pinny.isSuitable(ahmet) )
			System.out.println("Deneme 2 tamam");
		else
			System.out.println("Deneme 2 hatalý");
		Kindergarten yuva = new Kindergarten(2);
		if( yuva.addChild(ahmet) )
			System.out.println("Deneme 3 tamam");
		else
			System.out.println("Deneme 3 hatalý");
		if( yuva.findChild("AHMET KÜÇÜK") == ahmet )
			System.out.println("Deneme 4 tamam");
		else
			System.out.println("Deneme 4 hatalý");
		if( yuva.findChild("Yunus Selçuk") == null )
			System.out.println("Deneme 5 tamam");
		else
			System.out.println("Deneme 5 hatalý");
		yuva.addChild( new Child("Ayþe Minik",24) );
		if( yuva.addChild( new Child("Zeki Çalýþkan",28) ) )
			System.out.println("Deneme 7 hatalý");
		else
			System.out.println("Deneme 7 tamam");
		yuva.setCapacity(5);	
		if( yuva.findChild("AHMET KÜÇÜK") == ahmet )
			System.out.println("Deneme 6 tamam");
		else
			System.out.println("Deneme 6 hatalý");
		
	}

}
