package myPackage;
import java.util.*;
public class EquationClass {
	public String esitlik;
	public int sonuc;
	public EquationClass() {
		esitlik=this.generateEquation();
	}
	public String getEsitlik() {
		return esitlik;
	}
	//Bu metod, rakam seçimine yarýyor.
	public int getRandomRakam() {
		return (int)Math.floor(Math.random()*(9-1+1)+1);
	}
	//Bu metod, iþlem seçimine yarýyor.
	public char getRandomOperator() {
		Random operatorChoice = new Random();
        int operator = operatorChoice.nextInt(4);

        switch (operator){

            case 0: 
                return '+';
            case 1: 
                return '*';
            case 2: 
                return '/';
            case 3:
            	return '-';
            default:
            	return '-';
        }
	}
	public void setEsitlik(String esitlik) {
		this.esitlik = esitlik;
	}
	public void setSonuc(int sonuc) {
		this.sonuc = sonuc;
	}
	//Bu metod, uzunluk kontrolüne yarýyor.
	public boolean kiyas(String esitlik) {
		if(esitlik.length()<7 || esitlik.length()>9) {
			return false;
		}
		return true;
	}
	//Bu metod, 10-99 arasý rastgele sayý seçimine yarýyor.
	public int getRandomSayi() {
		return (int)Math.floor(Math.random()*(99-1+10)+10);
	}
	//Bu metod, 100-999 arasý rastgele sayý seçimine yarýyor.
	public int getRandomUcBasamakliSayi() {
		return (int)Math.floor(Math.random()*(999-100+1)+100);
	}
	//Tam bölünmeyen sayýlarda ekok alýyorum.
	public int ekok(int sayi1,int sayi2) {
        int ekok = 0;
        int max;
        max = sayi1 * sayi2;
        /* 2 sayý eger aralarýnda asal ise ekoku
        çarpýmlarýdýr. Yaný 2 sayýnýn ekoku maximum çarpýmlarýdýr.*/
        
        for(int i = max; i > 0; i--)
        {
            if(i % sayi1 == 0 && i % sayi2 == 0) {
                ekok = i;
            }
        }
        return ekok;
	}
	//Bu metod, iþlem yapmaya yarýyor.
	public int islemYap(int ilkSayi, int ikinciSayi, char operator) {
		switch (operator){
        case '+': 
            return ilkSayi+ikinciSayi;
        case '*': 
            return ilkSayi*ikinciSayi;
        case '/': 
            return ilkSayi/ikinciSayi;
        case '-':
        	return ilkSayi-ikinciSayi;
        default:
        	return 0;
    }
	}
	//Çok Kolay denklem üretiyor.
	public void setVeryEasyEquation() {
		int ilkSayi;
		int rand;
		int ikinciSayi;
		char operator;
		do {
		rand=getRandomRakam();
		if(rand>5) {
			ilkSayi=getRandomSayi();
		}
		else {
			ilkSayi=getRandomRakam();
		}
		ikinciSayi=getRandomRakam();
		operator = getRandomOperator();
		if(operator=='/') {
			if(ilkSayi%ikinciSayi!=0) {
					ilkSayi=ekok(ilkSayi,ikinciSayi);
			}}
			esitlik=ilkSayi+Character.toString(operator)+ikinciSayi+"="+(islemYap(ilkSayi,ikinciSayi,operator));
		}while(esitlik.length()!=7);
		
		
	}
	//Kolay denklem üretiyor.
	public void setEasyEquation() {
		int ilkSayi;
		int rand;
		int ikinciSayi;
		char operator;
		do {
		rand=getRandomRakam();
		if(rand>5) {
			ilkSayi=getRandomSayi();
		}
		else {
			ilkSayi=getRandomRakam();
		}
		ikinciSayi=getRandomSayi();
		operator = getRandomOperator();
		if(operator=='/') {
			if(ilkSayi%ikinciSayi!=0) {
					ilkSayi=ekok(ilkSayi,ikinciSayi);
					
			}}
		esitlik=ilkSayi+Character.toString(operator)+ikinciSayi+"="+(islemYap(ilkSayi,ikinciSayi,operator));
		}while(esitlik.length()!=7 && esitlik.length()!=8);
	}
	//4 sayýlý denklem üretmek için kullanýyorum.
	public int[] dortSayi() {
		int[] sayilar=new int[4];
		for(int i=0;i<4;i++) 
			sayilar[i]=getRandomRakam();
		return sayilar;
	}
	//3 iþlemli denklem üretmek için kullanýyorum.
	public char[] ucIslem() {
		char[] islemler=new char[3];
		for(int i=0;i<3;i++) 
			islemler[i]=getRandomOperator();
		return islemler;
	}
	//Üç basamaklý sayý olan denklem üretmek için þartlý seçim.
	public int[] ucBasamak() {
		int[] sayilar=new int[2];
		switch((int)Math.floor(Math.random()*(4-1+1)+1)){
			case 1:
					sayilar[0]=getRandomRakam();
					sayilar[1]=getRandomUcBasamakliSayi();
					break;
			case 2:
					sayilar[0]=getRandomUcBasamakliSayi();
					sayilar[1]=getRandomRakam();
					break;
			case 3:
					sayilar[0]=getRandomUcBasamakliSayi();
					sayilar[1]=getRandomSayi();
					break;
			case 4:
					sayilar[0]=getRandomSayi();
					sayilar[1]=getRandomUcBasamakliSayi();
		}
		return sayilar;
	}
	//Üç basamaklý sayý iþlemlerinde çarpma olamaz.
	private char getRandomUcBasamakliOperator() {
	Random operatorChoice = new Random();
    int operator = operatorChoice.nextInt(3);

    switch (operator){

        case 0: 
            return '+';
        case 1: 
            return '-';
        case 2: 
            return '/';
        default:
        	return '-';
    }
	}
	//Zor denklem üretiyor.
	public String generateEquation() {
		int[] sayilar;
		char[] islemler;
		String sonuc;
		int elemanSayisi=(int)Math.floor(Math.random()*(5-2+1)+2);
		switch(elemanSayisi) {
			case 4:
				do {
				sayilar=dortSayi();
				int[] Sayilar = new int[4];
				for(int i=0;i<4;i++) {
					Sayilar[i]=sayilar[i];
				}
				int iterator=0;
				islemler=ucIslem();
				String operator="";
				for(int i=0;i<3;i++) {
					operator+=Character.toString(islemler[i]);
				}
				for(int i=0;i<operator.length();i++) {
					if(isPriority(operator.charAt(i))) {
						if(operator.charAt(i)=='/') {
							while(sayilar[i]%sayilar[i+1]!=0) {
								sayilar[i+1]=getRandomRakam();
							}
							Sayilar[iterator+1]=sayilar[i+1];	
						}
						sayilar[i]=islemYap(sayilar[i],sayilar[i+1],operator.charAt(i));
						operator=operator.substring(0,i)+operator.substring(i+1,operator.length());
						for(int j=i+1;j<operator.length()+1;j++) {
							sayilar[j]=sayilar[j+1];
						}
						i--;
					}
					iterator++;
					}

					int j;
					for(int i=0;operator.length()!=0;) {
						sayilar[i]=islemYap(sayilar[i],sayilar[i+1],operator.charAt(i));
						operator=operator.substring(0,i)+operator.substring(i+1,operator.length());
			
						for(j=i+1;j<operator.length()+1;j++) {
							sayilar[j]=sayilar[j+1];
						}
					}
					sonuc=Sayilar[0] + "" + Character.toString(islemler[0])+Sayilar[1]+Character.toString(islemler[1])+Sayilar[2]+
							Character.toString(islemler[2])+Sayilar[3] +"="+Integer.toString(sayilar[0]);
				}while(sonuc.length()>9);
				this.esitlik=sonuc;
				break;
			case 3:
				do {
				sayilar=ucBasamak();
				islemler=new char[1];
				islemler[0]=getRandomUcBasamakliOperator();
				if(islemler[0]=='/' && sayilar[0]%sayilar[1]!=0) 
					sayilar[0]=ekok(sayilar[0],sayilar[1]);
				sonuc=sayilar[0]+Character.toString(islemler[0])+sayilar[1]+"="+islemYap(sayilar[0],sayilar[1],islemler[0]);
				}while(sonuc.length()>9);
				this.esitlik=sonuc;
				break;
			default:
				setNormalEquation();	
		}
		return esitlik;
	}
	public boolean isPriority(char o) {
		return o=='/' || o=='*';
	}
	//Orta denklem üretiyor.
	public void setNormalEquation() {
		int ilkSayi;
		int ikinciSayi;
		int tmp=0;
		int ucuncuSayi;
		String esitlik="";
		char islem2;
		char islem;
		do {
		ilkSayi=getRandomSayi();
		ikinciSayi=getRandomSayi();
		islem=getRandomOperator();
		if(ilkSayi<10 && ikinciSayi<10) {
			ucuncuSayi=getRandomSayi();
			islem2=getRandomOperator();
			if(islem2=='/' || islem2=='*') {
				if(islem2=='/') {
					while((float)ikinciSayi/ucuncuSayi!=(int)(ikinciSayi/ucuncuSayi) || ikinciSayi>9) {
		        		ikinciSayi=getRandomSayi();
		        		ucuncuSayi=getRandomSayi();
		        	}
					esitlik=ikinciSayi+"/"+ucuncuSayi;
					ikinciSayi=ikinciSayi/ucuncuSayi;}
				else {
					esitlik=ikinciSayi+"*"+ucuncuSayi;
					ikinciSayi=ikinciSayi*ucuncuSayi;
				}
					tmp=1;
				}
			else {
				switch(islem) { 
				 case '+': 
					esitlik=ilkSayi+"+"+ikinciSayi;
			        ilkSayi=ikinciSayi+ilkSayi;
			        ikinciSayi=ucuncuSayi;
			        break;
				 case '-': 
					 esitlik=ilkSayi+"-"+ikinciSayi;
					 ilkSayi=ilkSayi-ikinciSayi;
					 ikinciSayi=ucuncuSayi;
			        break;
				 case '/':
					 while((float)ilkSayi/ikinciSayi!=(int)(ilkSayi/ikinciSayi) || ilkSayi>9 || ikinciSayi>9) {
			        		ikinciSayi=getRandomSayi();
			        		ilkSayi=getRandomSayi();
			        	}
					 esitlik=ilkSayi+"/"+ikinciSayi;
					 ilkSayi=ilkSayi/ikinciSayi;
					 ikinciSayi=ucuncuSayi;
		        	break;
				 case '*':
					 esitlik=ilkSayi+"*"+ikinciSayi;
					ilkSayi=ikinciSayi*ilkSayi;
					ikinciSayi=ucuncuSayi;
			        break;
				
		}
				islem=islem2;
				tmp=2;
			}

		}
		switch (islem){

        case '+': 
        	sonuc=ikinciSayi+ilkSayi;
        	break;
        case '-': 
        	sonuc=ilkSayi-ikinciSayi;
        	break;
        case '/': 
 
        	while((float)ilkSayi/ikinciSayi!=(int)(ilkSayi/ikinciSayi)) {
        		ikinciSayi=getRandomSayi();
        		ilkSayi=getRandomSayi();
        		tmp=0;
        		esitlik="";
        	}
        	sonuc=ilkSayi/ikinciSayi;
        	break;
        case '*':
        	sonuc=ikinciSayi*ilkSayi;
        	while(!kiyas((ilkSayi+Character.toString(islem)+ikinciSayi+"="+sonuc))) {
        		ilkSayi=getRandomSayi();
        		ikinciSayi=getRandomSayi();
        		sonuc=ikinciSayi*ilkSayi;
        		tmp=0;
        		esitlik="";
        	}
        	break;
        
    }	if(tmp==0)
			esitlik=ilkSayi+Character.toString(islem)+ikinciSayi+"="+sonuc;
    	if(tmp==1)
    		esitlik=ilkSayi+Character.toString(islem)+esitlik+"="+sonuc;
    	if(tmp==2)
    		esitlik=esitlik + Character.toString(islem)+ikinciSayi+"="+sonuc;
		}while(!kiyas(esitlik) );
		this.esitlik=esitlik;
		
	}
	//Renklendirme iþlemlerini yapýyor.
	public int[] colors(String myString) {
		int myEsitlik=esitlik.length();
		int[] renkDizisi=new int[myEsitlik];
		String yedek=esitlik;
		String yedek2=myString;
		for(int i=0;i<esitlik.length();i++) {
			renkDizisi[i]=2;
		}
		for(int i=0;i<esitlik.length();i++) {
			//Ýndis indise eþitlik varsa boyayýp diziden atýyorum.
			if(yedek.charAt(i)==yedek2.charAt(i)) {
				renkDizisi[i]=0;
				yedek=yedek.substring(0, i)+"y"+yedek.substring(i+1,yedek.length());
				yedek2=yedek2.substring(0, i)+"w"+yedek2.substring(i+1,yedek2.length());
			}
		}
		//Herhangi bir varlýk söz konusuysa boyayýp, diziden atýyorum. Ýndis indise olanlarý zaten boyadým.
		for(int i=0;i<esitlik.length();i++) {
			if(yedek.contains(Character.toString(yedek2.charAt(i)))) {
				renkDizisi[i]=1;
				int index=yedek.indexOf(yedek2.charAt(i));
				yedek=yedek.substring(0, index)+"y"+yedek.substring(index+1,yedek.length());
			}
				
		}
		
		return renkDizisi;
	}
}
