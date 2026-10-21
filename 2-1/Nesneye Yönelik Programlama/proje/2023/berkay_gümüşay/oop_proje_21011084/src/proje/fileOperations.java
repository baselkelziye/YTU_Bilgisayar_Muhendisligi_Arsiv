package Proje;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Random;

import javax.xml.crypto.Data;

import java.io.FileWriter;
import java.io.File;
import java.io.IOException;

public class fileOperations {

    private String currentLine;
    BufferedReader br,br2;
    BufferedReader br1; 
    private String currentLine1;
    
    //DOSYADAN ÇOCUK/EBEVEYN OKUMA İŞLEMİ
    public User Oku(String ad, String soyad, String sifre)throws IOException {
        br = new BufferedReader(new FileReader("password.txt"));
        while ((currentLine = br.readLine()) != null) {
	        String[] kelimeler = currentLine.split(",");
	        if(kelimeler[0].equalsIgnoreCase(ad) && (kelimeler[1].equalsIgnoreCase(soyad)) && (kelimeler[2].equals(sifre))) {
	        	User user = new User(kelimeler[0],kelimeler[1],kelimeler[2],kelimeler[3]);
	        	return user;
	        }
        }
        return null;
    }
    
    //DOSYAYA ÇOCUK/EBEVEYN EKLEME İŞLEMİ
    public boolean addNewUser(String ad, String soyad, String sifre,String type) throws IOException {
    	try {
    		FileWriter fw = new FileWriter("password.txt",true);
			try (PrintWriter out = new PrintWriter(fw)) {
				out.println(ad+","+soyad+","+sifre+","+type);
				if(!type.equalsIgnoreCase("parent")) {
				//	File file = new File(ad+soyad+".txt");
					File file2 = new File(ad+soyad+"Results.txt");
		        //	file.createNewFile();
		        	file2.createNewFile();
				}
			}
			
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
    	return true;
    }
    public void createParentFile() throws IOException {
		br = new BufferedReader(new FileReader("password.txt"));
	    while ((currentLine = br.readLine()) != null) {
	        String[] kelimeler = currentLine.split(",");
	        if(kelimeler[3].equalsIgnoreCase("parent")) {
	        	File file = new File("parent.txt");
	        	if(!file.exists()) {
	        		file.createNewFile();
			        try {
			    		FileWriter fw = new FileWriter("parent.txt",true);
						try (PrintWriter out = new PrintWriter(fw)) {
							out.println("10,10,10");
						}
					} catch (FileNotFoundException e) {
						e.printStackTrace();
					}
	        	}
	        }
	    }
	}
    
    //DOSYADAKİ ÇOCUKLARIN LİSTESİNİ ALMA
    public ArrayList<User> getChildList() throws IOException{
    	br1 = new BufferedReader(new FileReader("password.txt"));
    	ArrayList<User> childList = new ArrayList<>();
    	currentLine1 = br1.readLine();
    	while (currentLine1 != null) {
    		String[] kelimeler = currentLine1.split(",");
	      //  kelimeler[0] = kelimeler[0].replaceAll("[^a-zA-Z]", "");
	        if(kelimeler[3].equalsIgnoreCase("child")) {
	        	User user = new User(kelimeler[0],kelimeler[1],kelimeler[2],kelimeler[3]);
		        childList.add(user);
	        }
	        currentLine1 = br1.readLine();
    	}
    	return childList;
    }
    //HER BİR ÇOCUĞUN İSMİNDE DOSYALARI OLUŞTURMA

    //ADI,SOYADI GİRİLEN ÇOCUĞUN DOSYADA OLUP OLMADIĞINI KONTROL ETME
    public boolean findChild(String ad,String soyad) throws IOException {
    	br = new BufferedReader(new FileReader("password.txt"));
        while ((currentLine = br.readLine()) != null) {
	        String[] kelimeler = currentLine.split(",");
	        if(kelimeler[0].equalsIgnoreCase(ad) && (kelimeler[1].equalsIgnoreCase(soyad))) {
	        	return true;
	        }
        }
        return false;
    }
    //İÇERİSİNDE TÜM KULANICILARIN, İSİM, SOYİSİM, ŞİFRELERİNİN BULUNDUĞU DOSYAYI AÇMA
    public void createPWFile() throws IOException {
    	File file = new File("password.txt");
		if(!file.exists()) {
			file.createNewFile();
		}
    }
    //SİSTEMDE HERHENAGİ BİR KULLANICI VAR MI YOK MU KONTROL ETME 
    public boolean isFileEmptyControl() throws IOException {
    	br = new BufferedReader(new FileReader("password.txt"));
        while ((currentLine = br.readLine()) != null) {
	        return false;
        }
    	return true;
    }
    //SİSTEMDE EBEVEYN VAR MI YOK MU KONTROL ETME
    public boolean parentControl() throws IOException {
    	br = new BufferedReader(new FileReader("password.txt"));
        while ((currentLine = br.readLine()) != null) {
        	String[] kelimeler = currentLine.split(",");
	        if(kelimeler[3].equalsIgnoreCase("parent")) {
	        	return true;
	        }
        }
    	return false;
    }
    //SORULARI OLUŞTURUP ÇOCUĞUN DOSYASINA YAZMA 
    public ArrayList<Question> prepareQuestions(User user,String strA, String strB, String strN) throws IOException {
    	int A=0,B=0,N = 0;
    //	String[] parameters;
    	Random random = new Random();
    	long seed = System.currentTimeMillis();
    	random.setSeed(seed);
    	A = Integer.parseInt(strA);
    	B = Integer.parseInt(strB);
    	N = Integer.parseInt(strN);
    	
    	int tmp1,tmp2,tmp3;
    	ArrayList<Question> childQuestions = new ArrayList<>();
		for(int i=0 ; i<N ; i++) {
			tmp1 = 1+random.nextInt(A-1);
			tmp2 = 1+random.nextInt(B-1);
			tmp3 = tmp1*tmp2;
			Question question = new Question(tmp1, tmp2, tmp3);
			childQuestions.add(question);
		}
    	return childQuestions;
    }
    //EBEVEYNİN DEĞİŞTİRDİĞİ A,B VE N DEĞERLERİNİ DOSYAYA YAZMA
    public void changeParameters(int A,int B,int N) throws IOException {
    	try {
    		FileWriter fw = new FileWriter("parent.txt",true);
			try (PrintWriter out = new PrintWriter(fw)) {
				out.println(A+","+B+","+N);
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
    }
    //ÇOCUĞUN SORULARINI LİSTE HALİNDE DOSYADAN ÇEKME
    public ArrayList<Question> getQuestions(User child) throws IOException{
    	ArrayList<Question> qList = new ArrayList<>();
    	br = new BufferedReader(new FileReader(child.getName()+child.getSurname()+".txt"));
        while ((currentLine = br.readLine()) != null) {
	        String[] values = currentLine.split(",");
	        int tmp1 = Integer.parseInt(values[0]);
	    	int tmp2 = Integer.parseInt(values[1]);
	    	int tmp3 = Integer.parseInt(values[2]);
	    	Question q = new Question(tmp1, tmp2, tmp3);
	    	qList.add(q);
        }
        return qList;
       
    }
    //ÇOCUĞUN TEST SONUÇLARINI SİSTEME EKLEME
    public void addResultToFile(Results childResults) throws IOException {
    	try {
    		File file = new File(childResults.getChild().getName()+childResults.getChild().getSurname()+"Results.txt");
    		if(!file.exists()) {
    			file.createNewFile();
    		}
    		try {
	    		FileWriter fw = new FileWriter(childResults.getChild().getName()+childResults.getChild().getSurname()+"Results.txt",true);
				try (PrintWriter out = new PrintWriter(fw)) {
				//	System.out.println("Length : "+childResults.getResults().length);
					out.println(childResults.returnOneString(childResults.getQuests(), childResults.getResults(), childResults.getAnswers(),childResults.getScore(),childResults.getParameters(),childResults.getTime())+":"+childResults.getStartDate());
				}
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
    	
    }
    //HER ÇOCUĞUN KENDİ SONUÇLARINI İÇERECEK OLAN DOSYAYI AÇMA 
    public void createResultFiles() throws IOException {
    	ArrayList<User> childs = getChildList();
    	for (User child : childs) {
    		File file = new File(child.getName()+child.getSurname()+"Results.txt");
    		if(!file.exists()) {
    			file.createNewFile();
    		}
		}
    }
    //İSMİ, SOYİSMİ GİRİLEN ÇOCUĞUN SONUÇLARINI DOSYADAN ÇEKME
    public ArrayList<Results> getResultsFromFile(String name,String surname) throws IOException {
    	ArrayList<Results> resultList = new ArrayList<>();
    	ArrayList<User> childList;
    	
    	if(name.equals("everyone")) {
    		try {
				childList = getChildList();
				for (User user : childList) {
					br = new BufferedReader(new FileReader(user.getName()+user.getSurname()+"Results.txt"));
		    		currentLine = br.readLine();
		    		while (currentLine != null) {
		    		//	System.out.println(currentLine);
		    			String[] allParams = currentLine.split(":");
		    			int[] finalResults = new int[4];
		    			User child = getChild(user.getName(), user.getSurname());
		    			String[] answers = new String[allParams.length];
		    			int score = 0;
		    			int[] time = new int[allParams.length];
		    			int[] gameParam = new int[3];
		    	        ArrayList<Question> quests = new ArrayList<>();
		    	        String[] dateTime = new String[3];
		    	        String finalDate = "";
		    	        int i = 0;
		    	        int j = 0;
		    			for (String string : allParams) {
		    				if(i >=(allParams.length -3) ) {
		    					dateTime[j] = string;
		    					if(j<2) {
		    						dateTime[j] = dateTime[j].concat(":");
		    					}
		    					i++;
		    					j++;
		    				}
		    				else if(i == (allParams.length -5)) {
								String[] params = string.split(","); 
								finalResults[0] = Integer.parseInt(params[0]);
								finalResults[1] = Integer.parseInt(params[1]);
								finalResults[2] = Integer.parseInt(params[2]);
								finalResults[3] = Integer.parseInt(params[3]);
								score = Integer.parseInt(params[4]);
								i++;
							}
							else if(i == (allParams.length -4 )) {
								String[] params = string.split(","); 
								gameParam[0] = Integer.parseInt(params[0]);
								gameParam[1] = Integer.parseInt(params[1]);
								gameParam[2] = Integer.parseInt(params[2]);
								i++;
							}
							else {
								String[] params = string.split(","); 
								Question quest = new Question(Integer.parseInt(params[0]),Integer.parseInt(params[1]) ,Integer.parseInt(params[2]));
								quests.add(quest);
								answers[i] = params[3];
								time[i] = Integer.parseInt(params[4]);
								i++;
							}
						}
		    			finalDate = finalDate.concat(dateTime[0]+dateTime[1]+dateTime[2]);
		    			Results result = new Results(child, quests, finalResults, answers, score, gameParam, time,finalDate);
		    			resultList.add(result);
		    			currentLine = br.readLine();
		    		}
				}
				return resultList;
			} catch (IOException e) {
				e.printStackTrace();
			}
    	}	
    	else {
    		br = new BufferedReader(new FileReader(name+surname+"Results.txt"));
    		currentLine = br.readLine();
    		while (currentLine != null) {
    			String[] allParams = currentLine.split(":");
    			int[] finalResults = new int[4];
    			User child = getChild(name, surname);
    			String[] answers = new String[allParams.length];
    			int score = 0;
    			int[] time = new int[allParams.length];
    			int[] gameParam = new int[3];
    			ArrayList<Question> quests = new ArrayList<>();
    			String[] dateTime = new String[2];
    	        String finalDate = "";
    	        int i = 0;
    	        int j = 0;
    			for (String string : allParams) {
    				if(i >=(allParams.length -3) ) {
    					if(j<2) {
    						dateTime[j] = string;
    					}
    					if(j<1) {
    						dateTime[j] = dateTime[j].concat(":");
    					}
    					i++;
    					j++;
    				}
    				else if(i == (allParams.length -5)) {
						String[] params = string.split(","); 
						finalResults[0] = Integer.parseInt(params[0]);
						finalResults[1] = Integer.parseInt(params[1]);
						finalResults[2] = Integer.parseInt(params[2]);
						finalResults[3] = Integer.parseInt(params[3]);
						score = Integer.parseInt(params[4]);
						i++;
					}
					else if(i == (allParams.length -4 )) {
						String[] params = string.split(","); 
						gameParam[0] = Integer.parseInt(params[0]);
						gameParam[1] = Integer.parseInt(params[1]);
						gameParam[2] = Integer.parseInt(params[2]);
						i++;
					}
					else {
						String[] params = string.split(","); 
						Question quest = new Question(Integer.parseInt(params[0]),Integer.parseInt(params[1]) ,Integer.parseInt(params[2]));
						quests.add(quest);
						answers[i] = params[3];
						time[i] = Integer.parseInt(params[4]);
						i++;
					}
				}
    			finalDate = finalDate.concat(dateTime[0]+dateTime[1]);
    			Results result = new Results(child, quests, finalResults, answers, score, gameParam, time,finalDate);
    			resultList.add(result);
    			currentLine = br.readLine();
    		}
    	}
    	return resultList;
    }
    //İSMİ, SOYİSMİ GİRİLEN ÇOCUĞU DOSYADAN ÇEKME
    public User getChild(String name, String surname) throws IOException {
    	ArrayList<User> childList = new ArrayList<>();
    	childList = getChildList();
    	for (User child : childList) {
			if(child.getName().equalsIgnoreCase(name) && child.getSurname().equalsIgnoreCase(surname)) {
				return child;
			}
		}
    	return null;
    }
    //HER ÇOCUK İÇİN KENDİ İSMİNDE, SKORLARINI İÇEREN DOSYAYI OLUŞTURMA
    public void createScoreTable() throws IOException {
    	ArrayList<User> childList = getChildList();
    	for (User child : childList) {
    		File file = new File(child.getName()+child.getSurname()+"Score.txt");
    		if(!file.exists()) {
    			file.createNewFile();
    		}
		}
    }
    //EBEVEYN PARAMETRELERİ DEĞİŞTİRDİĞİNDE HER ÇOCUĞUN SONUÇLARINI SIFIRLAMA İŞLEMİ
/*    public void resetResults() throws IOException {
    	ArrayList<User> childList = getChildList();
    	for (User child : childList) {
    		FileWriter file = new FileWriter(child.getName()+child.getSurname()+"Results.txt");
    		file.write("");
    		file.close();
		}
    }*/
    //GÜNCEL A,B VE N DEĞERLERİNİ SİSTEMDEN ALMA
    public int[] getParameters() throws IOException {
    	int[] params2 = new int[3];
    	br2 = new BufferedReader(new FileReader("parent.txt"));
    	String[] kelimeler = null;
    	while ((currentLine = br2.readLine()) != null) {
    		kelimeler  = currentLine.split(",");
        }
    	params2[0] = Integer.parseInt(kelimeler[0]);
    	params2[1] = Integer.parseInt(kelimeler[1]);
    	params2[2] = Integer.parseInt(kelimeler[2]);
    	return params2;
    }
    //ÇOCUĞUN SONUCUNU DOSYASINA EKLEME
    public void addScore(Results childResults) throws IOException {
    	File file = new File(childResults.getChild().getName()+childResults.getChild().getSurname()+"Score.txt");
    	if(!file.exists()) {
			file.createNewFile();
		}
    	FileWriter fw = new FileWriter(childResults.getChild().getName()+childResults.getChild().getSurname()+"Score.txt",true);
    	try (PrintWriter out = new PrintWriter(fw)) {
			out.println(childResults.getScore()+":"+childResults.getParameters()[0]+","+childResults.getParameters()[1]+","+childResults.getParameters()[2]+":"+childResults.getResults()[3]);
		}
    }
    //YÜKSEK SKORLARI İÇEREN MATRİSİ DOSYALARDAN ÇEKME İŞLEMİ
    public String[][] highScores(String A, String B, String N) throws IOException {
        br = new BufferedReader(new FileReader("password.txt"));
        int i=0;
        String[][] matris = new String[100][4];
        int params[] = getParameters();
        if(A.equalsIgnoreCase("0") && B.equalsIgnoreCase("0") && N.equalsIgnoreCase("0")) {
        	while ((currentLine = br.readLine()) != null) {
                String[] user = currentLine.split(",");
                if(!user[3].equalsIgnoreCase("parent")) {
                    br2 = new BufferedReader(new FileReader(user[0]+user[1]+"Score.txt"));
                    while ((currentLine1 = br2.readLine()) != null) {
                        String[] results = currentLine1.split(":");
                        String[] tmp = results[1].split(",");
                        if((tmp[0].equalsIgnoreCase(Integer.toString(params[0]))) && (tmp[1].equalsIgnoreCase(Integer.toString(params[1]))) && (tmp[2].equalsIgnoreCase(Integer.toString(params[2])))) {
                        	matris[i][0]=user[0];
    	                    matris[i][1]=user[1];
    	                    matris[i][2] = results[0];
    	                    matris[i][3] = results[2];
    	                    i++;
                        }
                        
                    }   
                }
            }
        }
        else {
        	while ((currentLine = br.readLine()) != null) {
                String[] user = currentLine.split(",");
                if(!user[3].equalsIgnoreCase("parent")) {
                    br2 = new BufferedReader(new FileReader(user[0]+user[1]+"Score.txt"));
                    while ((currentLine1 = br2.readLine()) != null) {
                        String[] results = currentLine1.split(":");
                        String[] tmp = results[1].split(",");
                        if((tmp[0].equalsIgnoreCase(A)) && (tmp[1].equalsIgnoreCase(B)) && (tmp[2].equalsIgnoreCase(N))) {
                        	matris[i][0]=user[0];
    	                    matris[i][1]=user[1];
    	                    matris[i][2] = results[0];
    	                    matris[i][3] = results[2];
    	                    i++;
                        }
                        
                    }   
                }
            }
        }
        String[][] filteredMatris = Arrays.stream(matris).filter(row -> row[0] != null && row[1] != null && row[2] != null && row[3] != null).toArray(String[][]::new);
		Arrays.sort(filteredMatris, new Comparator<String[]>() {
		    @Override
		    public int compare(String[] row1, String[] row2) {
		       int score1 = Integer.parseInt(row1[2]);
		       int score2 = Integer.parseInt(row2[2]);
		       if (score1 != score2) {
		           return Integer.compare(score2, score1);
		       } else {
		           int time1 = Integer.parseInt(row1[3]);
		           int time2 = Integer.parseInt(row2[3]);
		           return Integer.compare(time1, time2);
		       }
		    }
		});



        return filteredMatris;
    }
    //RAPOR OLARAK HER ÇOCUĞUN KENDİ İSMİNDE CSV DOSYALARINI ÜRETME
    public void createCSVFiles() throws IOException {
    	ArrayList<User> childList = getChildList();
    	for (User child : childList) {
			File file = new File(child.getName()+child.getSurname()+".csv");
			if(!file.exists()) {
				file.createNewFile();
			}
		}
    	File file = new File("AllScores.csv");
    	if(!file.exists()) {
    		file.createNewFile();
        	FileWriter fw = new FileWriter("AllScores.csv",true);
    		try (PrintWriter out = new PrintWriter(fw)) {
    			out.println("Isim;Soyisim;Skor;Sure;A;B;N");
    		}
    	}
    }
    //ÇOCUĞUN ELDE ETTİĞİ SKORU YÜKSEK SKORLAR ARASINA EKLEME
    public void addHighScoresCSV(Results result) throws IOException {
    	int a[] = getParameters();
    	FileWriter fw = new FileWriter(result.getChild().getName()+result.getChild().getSurname()+".csv",true);
    	try (PrintWriter out = new PrintWriter(fw)) {
    		out.println("Isim"+";"+"Soyisim"+";"+"Baslama Tarihi"+printCSVTitleQuest()+";A;B;N");
			out.println(result.gameToCSV()+";"+a[0]+";"+a[1]+";"+a[2]);
		}
    }
    //CSV DOSYASINDA BAŞLIKTA YAZACAK DEĞERLERİ TOPLUCA HYAZMA İŞLEMİ 
    //(DOSYA İŞLEMLERİ İLE ALAKASI YOK FAKAT TANIMLAYACAK BAŞKA YER BULAMADIM)
    public String printCSVTitleQuest() throws IOException {
    	int a = getParameters()[2];
    	String title = "";
    	for(int i = 0;i<a;i++) {
			title = title.concat(";Soru"+Integer.toString(i+1));
			title = title.concat(";Dogru Cevap");
			title = title.concat(";Verilen Cevap");
			title  =title.concat(";Sure");
		}
    	title = title.concat(";Skor;ToplamSure");
    	return title;
    }
  //ÇOCUĞUN ELDE ETTİĞİ SKORU YÜKSEK SKORLARI İÇEREN CSV DOSYASINA EKLEME
    public void addScoreToAllScores(int Score,int[] params) throws IOException {
    	String[][] allScores = highScores("0","0","0");
    	String[][] filteredMatris = Arrays.stream(allScores).filter(row -> row[0] != null && row[1] != null && row[2] != null && row[3] != null).toArray(String[][]::new);
    	FileWriter fw = new FileWriter("AllScores.csv",true);
		try (PrintWriter out = new PrintWriter(fw)) {
			for (String[] strings : filteredMatris) {
				if(strings[2].equalsIgnoreCase(Integer.toString(Score))) {
					out.println(strings[0]+";"+strings[1]+";"+strings[2]+";"+strings[3]+";"+Integer.toString(params[0])+";"+Integer.toString(params[1])+";"+Integer.toString(params[2])+";");
				}
			}
		}
    	
    	
    }
    public String[][] getAllExercises() throws IOException{
    	String [][] allExercises = new String[100][3];
    	br = new BufferedReader(new FileReader("parent.txt"));
    	int i = 0;
    	while ((currentLine = br.readLine()) != null) {
    		String[] exercise = currentLine.split(",");
    		allExercises[i][0] = exercise[0];
    		allExercises[i][1] = exercise[1];
    		allExercises[i][2] = exercise[2];
    		i++;
    	}
    	String[][] filteredMatris = Arrays.stream(allExercises).filter(row -> row[0] != null && row[1] != null && row[2] != null).toArray(String[][]::new);
    	return filteredMatris;
    }
}
