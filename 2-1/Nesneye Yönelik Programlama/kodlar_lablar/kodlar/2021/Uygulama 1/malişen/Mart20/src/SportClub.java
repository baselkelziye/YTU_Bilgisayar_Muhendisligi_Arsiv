
public class SportClub {
	
	public static void main(String[] args) {
		
		Sports s1 = new Sports("tennis", 15, 450);
		Sports s2 = new Sports("soccer", 10, 100);
		Sports s3 = new Sports("basketball", 15, 300);
		
		Member m1 = new Member("Jane Doe", 500);
		m1.registerCourse(s1);
		m1.registerCourse(s2);
		m1.registerCourse(s3);
		m1.listCourses();
		m1.getInfo();  //kisinin adini ve card id'sini yazdirir.
		
		System.out.println();
		
		Member m2 = new Member("Elly West", 400);
		m2.registerCourse(s1);
		m2.getInfo();
		System.out.println(m2+"\n\n"); //2 satir bosluk birakir.
		
		
		System.out.println(ClubCard.getCounter()); // static metodlara sinif adi uzerinden erisebiliriz.
		
		
		/*
		 * Homework (teslim edilmesi gerekli birþey deðil, kendinizi denemeniz için)
		 * Uygulama þunlarý gerçekleþtirebilsin:
		 * -Kiþi bir spora kayýt olunca bakiyesinden düþüþ yapýlmasý.
		 * -Card'a bakiye eklemesi yapýlabilmesi.
		 * 
		 */
		 
		
		
		
		
		
		
		
	}

}
