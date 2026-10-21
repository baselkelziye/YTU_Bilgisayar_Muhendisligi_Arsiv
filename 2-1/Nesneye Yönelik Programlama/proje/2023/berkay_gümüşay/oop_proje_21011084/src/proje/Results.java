package Proje;


import java.util.ArrayList;

public class Results {
		
	// KULLANICININ SONUÇLARINI TUTAN CLASS YAPISI
	
	private User child;// ÇOCUK
	private ArrayList<Question> quests;// SORULAR
	private int[] results;// SORU SAYISI , DOĞRU SAYISI , YANLIŞ SAYISI, SÜRE
	private String[] answers;// CEVAPLAR 
	private int score;// SKOR
	private int[] parameters;// A,B VE N DEĞERLERİ
	private int [] time;// SORU BAŞINA GEÇEN ZAMAN
	private String startDate;// TESTE BAŞLANAN ZAMAN
	
	public Results(User child, ArrayList<Question> quests, int[] results, String[] answers, int score, int[] parameters,int[] time, String startDate) {
		super();
		this.child = child;
		this.quests = quests;
		this.results = results;
		this.answers = answers;
		this.score = score;
		this.parameters = parameters;
		this.time = time;
		this.startDate = startDate;
	}
	
	public User getChild() {
		return child;
	}


	public void setChild(User child) {
		this.child = child;
	}


	public ArrayList<Question> getQuests() {
		return quests;
	}


	public void setQuests(ArrayList<Question> quests) {
		this.quests = quests;
	}


	public int[] getResults() {
		return results;
	}


	public void setResults(int[] results) {
		this.results = results;
	}


	public String[] getAnswers() {
		return answers;
	}


	public void setAnswers(String[] answers) {
		this.answers = answers;
	}
	// TEST HAKKINDA OLAN BİLGİLERİ EKRANA YAZDIRMA
	public String printQuestionInfo(int[] results) {
		String allParameters = "";
		allParameters = allParameters.concat(" Soru Sayısı: "+Integer.toString(results[0])+"  |  "+"Doğru Sayısı: "+Integer.toString(results[1])+"  |  "+"Yanlış Sayısı: "+Integer.toString(results[2])+"  |  "+"Bitirme Süresi: "+Integer.toString(results[3])+" Saniye");
		return allParameters;
	}
	// SORULARI EKRANA YAZDIRMA
	public String printAllQuests(ArrayList<Question> quests,String[] answers,int i, int[] time) {
		String allParameters = "";
		allParameters = allParameters.concat((i+1)+".Soru ) "+quests.get(i).panelQuestions(quests.get(i).getNum1(), quests.get(i).getNum2(), quests.get(i).getAnswer()));
		allParameters = allParameters.concat(" Verilen Cevap: "+answers[i]+" | Süre: "+ time[i]+" Saniye");
		if(answers[i].equalsIgnoreCase(Integer.toString(quests.get(i).getAnswer()))) {
			allParameters = allParameters.concat("| Doğru\n");
		}
		else {
			allParameters = allParameters.concat("| Yanlış\n");
		}
		return allParameters;
	}
	// SONUÇLARI TXT DOSYASINA UYGUN HALDE YAZDIRMA
	public String returnOneString(ArrayList<Question> quests, int[] results, String[] answers, int score, int[] parameters,int[] time) {
		String allParameters = "";
		for(int i = 0;i<quests.size();i++) {
			allParameters = allParameters.concat(quests.get(i).getString(quests.get(i).getNum1(), quests.get(i).getNum2(), quests.get(i).getAnswer()));
			allParameters = allParameters.concat(answers[i]+","+Integer.toString(time[i])+":");
		}
		allParameters = allParameters.concat(Integer.toString(results[0])+","+Integer.toString(results[1])+","+Integer.toString(results[2])+","+Integer.toString(results[3])+","+Integer.toString(score));
		allParameters = allParameters.concat(":"+Integer.toString(parameters[0])+","+Integer.toString(parameters[1])+","+Integer.toString(parameters[2]));
		return allParameters;
	}
	public int getScore() {
		return score;
	}
	public void setScore(int score) {
		this.score = score;
	}


	public int[] getParameters() {
		return parameters;
	}


	public void setParameters(int[] parameters) {
		this.parameters = parameters;
	}

	public int[] getTime() {
		return time;
	}

	public void setTime(int[] time) {
		this.time = time;
	}

	public String getStartDate() {
		return startDate;
	}

	public void setStartDate(String startDate) {
		this.startDate = startDate;
	}
	// TEST SONUÇLARINI CSV DOSYASINA UYGUN HALDE YAZDIRMA
	public String gameToCSV() {
		String title = "";
		int i = 0;
		title = title.concat(child.getName()+";"+child.getSurname()+";"+startDate+";");
		for (Question quest : quests) {
			title = title.concat(quest.getNum1()+"*"+quest.getNum2()+";"+quest.getAnswer()+";"+answers[i]+";"+Integer.toString(time[i])+";");
			
			i++;
		}
		title = title.concat(Integer.toString(score)+";"+Integer.toString(results[3]));
		return title;
	}
	
	
	
}
