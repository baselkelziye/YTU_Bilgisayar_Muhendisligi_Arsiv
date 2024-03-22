
#include<iostream>
#include<stack>

using namespace std;



int hesapla(char islem, int sayi1 , int sayi2){  	//yap�lacak islemin hangi d�rt islem oldu�unu bulal�m ve
	if(islem == '+'){ 								//o i�lemi yapal��m		
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


int ilkyap(char ch)						//stack ' e konulacak �nceli�i belirleyelim, matematik i�lemlerinin aksine
{										//parantez i�lemleri en �nceliksizdir ��nk� parantez kapama gelmeden
										// parantez a�ma d��ar� ��kmamal�d�r.
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
	
	
	char str[] = "8 + 2 * (21 / (7 � 4) + 2)";  // yap�lacak i�lem 
//	char str[] = "(0)";
	int sayi1 = sizeof(str)/sizeof(char);
	int k = 0;
	stack<char> sonucsayi;
	stack<int> islem_sonucsayi;
	cout <<"Hesaplanacak sayi : " << str << endl;
	int i = 0; 
	while(str[i] != '\0'){     		//e�er hesaplanacak de�er girilmediyse bo� d�nd�r
		if(str[i] == '('){ 			//e�er hesaplanacak de�er girilmediyse bo� d�nd�r
			sonucsayi.push('(');	 //e�er hesaplanacak de�er girilmediyse bo� d�nd�r	  	
		
		}else if(str[i] == ')'){								//islermler yap�l�r
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
		}else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^'){  //islemler yap�l�r
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
			islem_sonucsayi.push(int(str[i])- 48);  //ascii tablosundaki 0'�n kar��l��� ��kar�ld�.
		}
		i++;
	}
	
	while(!sonucsayi.empty()){                     //islermler yap�l�r
		int sayi2 = islem_sonucsayi.top();
		islem_sonucsayi.pop();
		int sayi1 = islem_sonucsayi.top();
		islem_sonucsayi.pop();
		int sonuc = hesapla(sonucsayi.top(),sayi1,sayi2);
		islem_sonucsayi.push(sonuc);
		sonucsayi.pop(); 
		
	}

	cout <<"ISLEMIN SONUCU : " << islem_sonucsayi.top() << endl;  //sonuc yazd�r�l�r.
	
	return 0;
}



