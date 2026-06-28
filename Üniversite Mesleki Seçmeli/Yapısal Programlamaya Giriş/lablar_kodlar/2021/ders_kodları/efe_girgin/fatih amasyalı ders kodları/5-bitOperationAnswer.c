/*16 soruluk yes/no testi yapýlýyor */
/* cevap anahtarýný y/n þekline al 16bitlik answers'da tut */
/* short olarak kiþinin verdiði cevabý al*/
/* kaç soru bildiðini short olarak yaz*/
#include <stdio.h>
int main()
{ 
	unsigned short correctanswers = 0,answer2=0,testanswer,result; 
	short int j,score=0; 
	char c; 
	printf("sizeof short %d\n",sizeof(j));
	/* eger ilk soru en sol bitte tutuluyorsa*/
	/*for (j=0; j <= 15; j++)
	{ 
		scanf ("%c", &c); 
		if (c == 'y' || c == 'Y') 
		{
			answer2=1<<(15-j);
			correctanswers = answer2 | correctanswers;
			answer2=0;
		}
	}
	*/
	/* eger ilk soru en sað bitte tutuluyorsa*/
	answer2=1;
	for (j=0; j <= 15; j++)
	{ 
		c=getch();
		putch(c);
		if (c == 'y' || c == 'Y') 
			correctanswers = answer2 | correctanswers;
		answer2<<=1;
	}
	
	
	printf( "Correct answers :%d\n",correctanswers);
	printf("Kullanýcýnýn verdiði cevaplar?\n");
	scanf("%d",&testanswer);
	result=testanswer^correctanswers;  //aynýysa 0 farklýysa 1
	printf("result:%d",result);
	answer2=1;
	for (j=0; j <= 15; j++)
	{ 
		if (answer2&result)
			score++;
		answer2=answer2<<1;
	}
	printf("score:%d\n",16-score);
	
}
