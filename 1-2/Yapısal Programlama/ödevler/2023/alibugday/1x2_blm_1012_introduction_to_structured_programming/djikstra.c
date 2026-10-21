#include<stdio.h>
#define INFINITY 1000
#define MAX 50

//algoritmanýn olduðu fonksiyon
void dijkstra(int dizi[MAX][MAX],int N,int ilk_nokta);

int main(){
	int j,i,N,ilk;
	/*
	N:nokta sayýsý, ayný zamanda dizi matrisinin satýr ve stünu sayýsý 
	ilk: ilerde scanf ile alacaðýmýz iki nokta arasý mesafeyi ölceceðimiz noktalardan baþlangýc olaný
	*/
	int dizi[MAX][MAX];
	//dizi:noktalarýn birbirine olan uzaklýðý yazýlan matris
	
	printf("toplam nokta sayýsýný giriniz:");
	scanf("%d",&N);
	
	printf("Noktanin kendisine olan uzakligini ve birbirine bagli olmayan noktalar arasi uzakliði sifir olacak þekilde matrisi giriniz\n");
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%d\'inci noktanin %d\'inci noktasina olan uzakliðini giriniz",i+1,j+1);
			scanf("%d",&dizi[i][j]);
		}
	}
	
	//matrisi kod üzerinden direk almak icin asagýsý kullanýlabilir ama 15-29. satýrlarý yorum haline getirmemiz lazým kullanmak icin
	/*int dizi[MAX][MAX]={{ 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    N=9;                    
	*/
	
	printf("baslangic noktasini giriniz(sayilar birden basliyor):");
	scanf("%d",&ilk);
	
	dijkstra(dizi,N,ilk-1);	
	
}

void dijkstra(int dizi[MAX][MAX],int N,int ilk_nokta){
	int maliyet[MAX][MAX],mesafe[MAX],yol[MAX];
	/*
	maliyet[][]:main icerisinde aldýðýmýz dizi[][] arrayinin düzenlenecek hali
	mesafe[]:hedef noktaya gidene kadar toplam maliyeti hesaplayýp saklayacaðýmýz dizi
	yol[]:hedef noktaya giderekn izlediðimiz rotayý saklayan dizi   
	*/
	
	int visited[MAX],count,min_mesafe,next_nokta,i,j;
	/*
	vizited[]:daha önce bulunulan noktalarýn takibini tutar
	count:while icin sayac
	min_mesafe:her bir noktanýn üzerinde o ana kadarki maliyetidir. Hesaplanmamýþ ise sonsuz
	next_nokta:hesaplanan maliyetler üzerinden gidilecek olan nokta numarasý atanýr 
	*/
	
	
	/*
	parametre olarak aldýðýmýz dizi arrayin icerisinde atadýðýmýz '0' degerlerine degeri 1000 olan ýnfinity degerini atar ve
	bu yolu cok yüksek deðerinden dolayý kullanmaz. böylece aralarýnda baglantý olmayan iki nokta arasýnda yol yokmuþ gibi olur. 
	*/
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			if(dizi[i][j]==0)
				maliyet[i][j]=INFINITY;
			else
				maliyet[i][j]=dizi[i][j];
	
	
	/*
	1.noktadan diðer noktalara olan uzaklýklarý mesafe[i]'ye atar daha sonraki while icerisinde en kücüðünü bulup o noktaya doðru haraket edecek bu sadece
	döngüyü baþlatmak icin 
	ayný þekilde yol ve visited dizileri de ilk deðerlerini alýr   
	*/
	for(i=0;i<N;i++)
	{
		mesafe[i]=maliyet[ilk_nokta][i];
		yol[i]=ilk_nokta;
		visited[i]=0;
	}
	
	//1. noktamýzýn maliyeti sýfýr, ziyaret edilmiþ oldu ve count 1 olarak atanýyor. 
	mesafe[ilk_nokta]=0;
	visited[ilk_nokta]=1;
	count=1;
	
	//algoritma burda baþlýyor
	//ilk noktayý visit ettiðimiz için count 1 den baþlýyor ve son noktadan sonra gidecek baþka nokta olmadýðý icin while N-1 de bitiyor.
	int sayac=0;
	while(count<N-1)
	{
		//baþlangýçta bütün noktalarýn maliyeti sonsuz 
		min_mesafe=INFINITY;
	
		//bulunduðumuz noktadan sonraki noktalara ziyaret edilmemiþ ve minimum mesafesi olan noktayý hepsini karþýlaþtýrarak bulur. 
		for(i=0;i<N;i++)
		{
			sayac+=1;
			if(mesafe[i]<min_mesafe&&!visited[i])
			{
				min_mesafe=mesafe[i];
				next_nokta=i;
			}
		}
		//daha iyi bir yol var mý diye bakarýz
		/*
		bunun icin next_nokta ile geldiðimiz noktadan diðer ziyaret edilmemiþ noktalarýn maliyeti hesaplanmýþ ve bizim þimdiki
		maliyetimizden düþük ise geri dönülüp o noktaya gidilir.
		*/
		visited[next_nokta]=1;
		for(i=0;i<N;i++)
			if(!visited[i])
				//aslýnda buraya da sayaç eklenebilir ama bu karmaþýklýðý etkilemeyeceði icin gerek duymadým. 
				if(min_mesafe+maliyet[next_nokta][i]<mesafe[i])
				{
					mesafe[i]=min_mesafe+maliyet[next_nokta][i];
					yol[i]=next_nokta;
				}
		count++;
	}
	
	//izlenilen rota ve noktaya olan mesafe terminale bastýrýlýr.
	printf("noktalar:\n");
	for (i=0;i<N;i++){
		printf("%d-",i+1);
	}
	
	int iki;
	printf("\nmesafeyi hesaplamak istediðniz ikinci noktayi giriniz");
	scanf("%d",&iki);
	iki-=1;
	
	printf("\n%d yolunun maliyeti=%d\n",iki+1,mesafe[iki]);
	
	int sira;
	sira=iki;
	printf("========\nyol:\n");
	printf("%d",iki+1);
	do{
		sira=yol[sira];
		printf("<=%d",sira+1);
	}while(sira!=ilk_nokta);
	printf("\nsayac:%d",sayac);
}

