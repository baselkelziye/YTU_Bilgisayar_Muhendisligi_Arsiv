
#include<iostream>
#include<stack>

using namespace std;



int hesapla(char islem, int sayi1 , int sayi2){  	//yapýlacak islemin hangi dört islem olduðunu bulalým ve
	if(islem == '+'){ 								//o iþlemi yapalýým		
		return sayi1 + sayi2;
	
	}else if(islem == '-'){
		return sayi1 - sayi2;
	}else if(islem == '*'){
		return sayi1 * sayi2;
	}else if(islem == '/'){
					if(sayi2 > 0){
						return sayi1/sayi2;
					}
					return 0;
	}else if(islem == '^'){
		return sayi1 ^ sayi2;
	}
	return -1;
}


int ilkyap(char ch)						//stack ' e konulacak önceliði belirleyelim, matematik iþlemlerinin aksine
{										//parantez iþlemleri en önceliksizdir çünkü parantez kapama gelmeden
										// parantez açma dýþarý çýkmamalýdýr.
    switch (ch)
    {
    	case '(':
    		return 1;
	    case '+':
	    case '-':
		    return 2;

	    case '*':
	    case '/':	    	
	        return 3;

	    case '^':
	        return 4;
    }
    return -1;
}
int main(void){
	
	
	char str[] = "8 + 2 * (21 / (7 – 4) + 2)";  // yapýlacak iþlem 
//	char str[] = "(0)";
	int sayi1 = sizeof(str)/sizeof(char);
	int k = 0;
	stack<char> sonucsayi;
	stack<int> islem_sonucsayi;
	cout <<"Hesaplanacak sayi : " << str << endl;
	int i = 0; 
	while(str[i] != '\0'){     		//eðer hesaplanacak deðer girilmediyse boþ döndür
		if(str[i] == '('){ 			//eðer hesaplanacak deðer girilmediyse boþ döndür
			sonucsayi.push('(');	 //eðer hesaplanacak deðer girilmediyse boþ döndür	  	
		
		}else if(str[i] == ')'){								//islermler yapýlýr
			while(sonucsayi.top() != '('){
				int sayi2 = islem_sonucsayi.top();
				islem_sonucsayi.pop();
				int sayi1 = islem_sonucsayi.top();
				islem_sonucsayi.pop();
				int sonuc = hesapla(sonucsayi.top(),sayi1,sayi2);
				islem_sonucsayi.push(sonuc);
			  sonucsayi.pop();
		
			}
			sonucsayi.pop();  
		}else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^'){  //islemler yapýlýr
			int pC = ilkyap(str[i]);
			while(!sonucsayi.empty() && ilkyap(sonucsayi.top()) >= pC){
				int sayi2 = islem_sonucsayi.top();
				islem_sonucsayi.pop();
				int sayi1 = islem_sonucsayi.top();
				islem_sonucsayi.pop();
				int sonuc = hesapla(sonucsayi.top(),sayi1,sayi2);
				islem_sonucsayi.push(sonuc);
				sonucsayi.pop(); 
			}
			sonucsayi.push(str[i]);
		}else{
			islem_sonucsayi.push(int(str[i])- 48);  //ascii tablosundaki 0'ýn karþýlýðý çýkarýldý.
		}
		i++;
	}
	
	while(!sonucsayi.empty()){                     //islermler yapýlýr
		int sayi2 = islem_sonucsayi.top();
		islem_sonucsayi.pop();
		int sayi1 = islem_sonucsayi.top();
		islem_sonucsayi.pop();
		int sonuc = hesapla(sonucsayi.top(),sayi1,sayi2);
		islem_sonucsayi.push(sonuc);
		sonucsayi.pop(); 
		
	}

	cout <<"ISLEMIN SONUCU : " << islem_sonucsayi.top() << endl;  //sonuc yazdýrýlýr.
	
	return 0;
}



