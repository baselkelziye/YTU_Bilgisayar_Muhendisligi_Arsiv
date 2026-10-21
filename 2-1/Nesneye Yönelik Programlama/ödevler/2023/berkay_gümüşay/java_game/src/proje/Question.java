package Proje;

public class Question {
	
	private int num1;
	private int num2;
	private int answer;
	
	// SORUYU TUTAN CLASS YAPISI
	
	public Question(int num1, int num2, int answer) {
		super();
		this.num1 = num1;
		this.num2 = num2;
		this.answer = answer;
	}


	public int getNum1() {
		return num1;
	}


	public void setNum1(int num1) {
		this.num1 = num1;
	}


	public int getNum2() {
		return num2;
	}


	public void setNum2(int num2) {
		this.num2 = num2;
	}


	public int getAnswer() {
		return answer;
	}


	public void setAnswer(int answer) {
		this.answer = answer;
	}
	// SORULARI CSV DOSYASINA UYGUN HALDE YAZDIRMA
	public String getString(int num1,int num2,int num3) {
		String str="";
		str = str.concat(Integer.toString(num1)+","+Integer.toString(num2)+","+Integer.toString(num3)+",");
		return str;
	}
	// SORULARI EKRANA UYGUN HALDE YAZDIRMA
	public String panelQuestions(int num1,int num2,int num3) {
		String str="";
		str = str.concat(Integer.toString(num1)+" * "+Integer.toString(num2)+" = "+Integer.toString(num3));
		return str;
	}


	
	
}
