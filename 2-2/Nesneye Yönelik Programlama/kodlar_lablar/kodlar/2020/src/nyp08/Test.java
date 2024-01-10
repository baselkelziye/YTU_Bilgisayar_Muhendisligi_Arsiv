package nyp08;

public class Test {

	public static void main(String[] args) {
		Tariff tariff4 = Tariff.NET4;
		Person yunus = new Person("Yunus Emre");
		yunus.subscribeTo(tariff4);
		tariff4.setFee(35);
		Tariff tariff5 = Tariff.NETFREE;
		Person berkin = new Person("Berkin Gülay");
		berkin.subscribeTo(tariff5);
		System.out.println(yunus);
		System.out.println(berkin);
	}

}
