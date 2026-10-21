
#include <stdio.h>
#define SIZE 100
int main(void)
{
	int N, i, a, b, s, j, k, c, d, birinci, ikinci, üçüncü;
	int tmp[SIZE];
	char mtr[SIZE][SIZE];

	printf("lutfen kare matrisin boyutunu yazınız:");  //matrisi boyutunu kullanıcıdan alma...
	scanf("%d", &N);
	for (i = 0; i < N; i++)   //matrisin içini boşaltma...
	{
		for (j = 0; j < N; j++)
		{
			mtr[i][j] = '_';
		}
	}
	mtr[N / 2][N / 2] = 'K';  //ilk taşı yerine koyma...//
	printf("\n");
	for (i = 0; i < N; i++)   //ilk işlem sonrasında matrisi kullanıcıya gösterme...
	{
		for (j = 0; j < N; j++)
		{
			printf(" %c ", mtr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (i = 1; i < N * N; i++)  //bütün kutucuklar dolana kadar döngüye girme...//
	{
		printf("%d .oyuncu lütfen yukardaki tabloya bakarak geçerli olan bir kutucuklardan hangi satır ve sütuna taş koyacağınızı yazınız,(satır sütün):", i % 3 + 1);
		scanf("%d %d", &c, &d);
		a = c - 1;  //c diline göre satır ve sütünu güncelleme...
		b = d - 1;
        while(mtr[a][b]!='_')  //başka bir taşın üstüne tekrardan koymamasını ve tahtanın dışına yazmamayı sağlama işlemi...//
        {
            if(a < 0 || a >= N || b<0 || b >= N)
            {
                printf("yazdığınız kutucuk oyun tahtasının dışındadır.lütfen geçerli bir kutucuk seçiniz,(satır sütün):");
                scanf("%d %d", &c, &d);
                a = c - 1;
                b = d - 1;
            }
            else
            {
                printf("girdiğiniz kutucuk doludur.lütfen geçerli bir kutucuk seçiniz,(satır sütün):");
                scanf("%d %d", &c, &d);
                a = c - 1;
                b = d - 1;
            }
           
        }
        while((mtr[a + 1][b]=='_'||a + 1>=N) && (mtr[a - 1][b]=='_'||a - 1<0) && (mtr[a][b + 1]=='_'||b + 1>=N) && (mtr[a][b - 1]=='_'||b - 1<0) && 
		(mtr[a + 1][b + 1]=='_'||a + 1>=N||b + 1>=N) && (mtr[a + 1][b - 1]=='_'||a + 1>=N||b - 1<0) && (mtr[a - 1][b + 1]=='_'||a - 1<0||b + 1>=N) && (mtr[a - 1][b - 1]=='_'||a - 1<0||b - 1<0))  
		//koyulan taşın diğer taşların bitişiğinde olmasını sağlama...
        {
            printf("girdiğiniz kutucuk diğer taşlara bitişik değildir.lütfen geçerli bir kutucuk seçiniz,(satır sütün):");
            scanf("%d %d", &c, &d);
            a = c - 1;
            b = d - 1;
            while(mtr[a][b]!='_')
            {
                if(a < 0 || a >= N || b<0 || b >= N)
                {
                    printf("yazdığınız kutucuk oyun tahtasının dışındadır.lütfen geçerli bir kutucuk seçiniz,(satır sütün):");
                    scanf("%d %d", &c, &d);
                    a = c - 1;
                    b = d - 1;
                }
                else
                {
                    printf("girdiğiniz kutucuk doludur.lütfen geçerli bir kutucuk seçiniz,(satır sütün):");
                    scanf("%d %d", &c, &d);
                    a = c - 1;
                    b = d - 1;
                }
            
            }
        }

		if (i % 3 == 0)  //hangi rengi yazılacağını belirleme...
		{
			mtr[a][b] = 'K';
		}
		if (i % 3 == 1)
		{
			mtr[a][b] = 'S';
		}
		if (i % 3 == 2)
		{
			mtr[a][b] = 'M';
		}
		s = 1;  
		for(j=0;j<8;j++)
		{
			tmp[j]=0;
		}
		while ((a + s - 1 < N || b + s - 1 < N || a - s + 1 >= 0 || b - s + 1 >= 0)) //koyulan taşılan çevresine bakılmada bütün kenarlara gelinceye kadar döngüye girme... //
        {
			if (mtr[a][b] == mtr[a + s][b] && a + s - 1 < N && tmp[0]==0)  //eğer koyulan taşın kenarlarında o taşın renginde başka taş varsa onu belirleme..//
			{
				j = 1;
				while (j < s && mtr[a + j][b] != '_' && mtr[a][b] != mtr[a + j][b])    //eğer koyulan taşın kenarlarında o taşın renginde var ise bu sefer iki taşın arasında boşluk var mı yok mu belirleme ve bitişiğindeki taşı görmeyip işlemi yanlış durumdan kurtarma...//
				{
					j++;
				}
				if (j == s) //eğer iki taş arasında boşluk yoksa aradaki diğer renkteki taşları koyulan rengin taşına çevirme...
				{
					tmp[0] = 1;  //eğer koyulan taşın kenarlarında aynı renkten bulduysak döngüden çıkma...
					for (j = 1; j < s; j++)  //aradaki taşların rengini değiştirme işlemi...
					{
						mtr[a + j][b] = mtr[a][b];
					}
				}
			}
			if (mtr[a][b] == mtr[a - s][b] && a - s + 1 >= 0 && tmp[1]==0)
			{
				j = 1;
				while (j < s && mtr[a - j][b] != '_'&& mtr[a][b] != mtr[a - j][b])
				{
					j++;
				}
				if (j == s)
				{
					tmp[1] = 1;
					for (j = 1; j < s; j++)
					{
						mtr[a - j][b] = mtr[a][b];
					}
				}
			}
			if (mtr[a][b] == mtr[a][b + s] && b + s - 1 < N && tmp[2]==0)
			{
				j = 1;
				while (j < s && mtr[a][b+j] != '_' && mtr[a][b] != mtr[a][b + j])
				{
					j++;
				}
				if (j == s)
				{
					tmp[2] = 1;
					for (j = 1; j < s; j++)
					{
						mtr[a][b + j] = mtr[a][b];
					}
				}
			}
			if (mtr[a][b] == mtr[a][b - s] && b - s + 1 >= 0 && tmp[3]==0)
			{
				j = 1;
				while (j < s && mtr[a][b-j] != '_' && mtr[a][b] != mtr[a][b - j])
				{
					j++;
				}
				if (j == s)
				{
					tmp[3] = 1;
					for (j = 1; j < s; j++)
					{
						mtr[a][b - j] = mtr[a][b];
					}
				}
			}
			if (mtr[a][b] == mtr[a + s][b + s] && a + s - 1 < N && b + s - 1 < N && tmp[4]==0)
			{
				j = 1;
				while (j < s && mtr[a + j][b + j] != '_' && mtr[a][b] != mtr[a + j][b + j])
				{
					j++;
				}
				if (j == s)
				{
					tmp[4] = 1;
					for (j = 1; j < s; j++)
					{
						mtr[a + j][b + j] = mtr[a][b];
					}
				}
			}
			if (mtr[a][b] == mtr[a + s][b - s] && a + s - 1 < N && b - s + 1 >= 0 && tmp[5]==0)
			{
				j = 1;
				while (j < s && mtr[a + j][b-j] != '_' && mtr[a][b] != mtr[a + j][b - j])
				{
					j++;
				}
				if (j == s)
				{
					tmp[5] = 1;
					for (j = 1; j < s; j++)
					{
						mtr[a + j][b - j] = mtr[a][b];
					}
				}
			}
			if (mtr[a][b] == mtr[a - s][b + s] && a - s + 1 >= 0 && b + s - 1 < N && tmp[6] ==0)
			{
				j = 1;
				while (j < s && mtr[a - j][b+j] != '_' && mtr[a][b] != mtr[a - j][b + j])
				{
					j++;
				}
				if (j == s)
				{
					tmp[6] = 1;
					for (j = 1; j < s; j++)
					{
						mtr[a - j][b + j] = mtr[a][b];
					}
				}
			}
			if (mtr[a][b] == mtr[a - s][b - s] && a - s + 2 >= 0 && b - s + 2 >= 0 && tmp[7] ==0)
			{
				j = 1;
				while (j < s && mtr[a - j][b-j] != '_' && mtr[a][b] != mtr[a - j][b - j])
				{
					j++;
				}
				if (j == s)
				{
					tmp[7] = 1;
					for (j = 1; j < s; j++)
					{
						mtr[a - j][b - j] = mtr[a][b];
					}
				}
			}
			s++; //her seferinde koyulan taşın kenarlarından aynı anda teker teker uzaklaşma...//
		}
		for (j = 0; j < N; j++)  //koyulduktan sonraki durumu ve eğer sıkıştırma işlemi varsa onunla beraber son durumu kullanıcıya gösterme...
		{
			for (k = 0; k < N; k++)
			{
				printf(" %c ", mtr[j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	birinci = 0;
	ikinci = 0;
	üçüncü = 0;
	for (i = 0; i < N; i++)  //oyunun sonunda hangi renkten kaç tane olduğunu belirleme...
	{
		for (j = 0; j < N; j++)
		{
			if (mtr[i][j] == 'K')
			{
				birinci++;
			}
			if (mtr[i][j] == 'S')
			{
				ikinci++;
			}
			if (mtr[i][j] == 'M')
			{
				üçüncü++;
			}
		}
	}
	printf("\nkırmızı %d kadar taş vardır.\n", birinci);
	printf("sarı %d kadar taş vardır.\n", ikinci);
	printf("mavi %d kadar taş vardır.\n", üçüncü);

	if (birinci > ikinci)    //oyunun sonunda en çok kendi renginde taşı olan oyuncuyu ilan etme...
	{
		if (birinci > üçüncü)
		{
			printf("birinci oyuncu kazanmıştır.Tebrikler...");
		}
		else if (üçüncü > birinci)
		{
			printf("üçüncü oyuncu kazanmıştır.Tebrikler...");
		}
        else
        {
            printf("birininci ve üçüncü oyuncu berbabere kalmıştır.ikinizede tebrikler...");
        }
	}
	else if (ikinci > üçüncü)
	{
		printf("ikinci oyuncu kazanmıştır.Tebrikler...");
	}
	else if (üçüncü > ikinci)
	{
		printf("üçüncü oyuncu kazanmıştır.Tebrikler...");
	}
    else if (ikinci == üçüncü && ikinci == birinci)
    {
        printf("herkez eşit kimse kazanmadı.");
    }
    else if (ikinci == birinci)
    {
        printf("birinci ve ikinci oyuncu berbabere kalmıştır.ikinizede tebrikler...");
    }
    else
    {
        printf("ikinci ve üçüncü oyuncu berabere kalmıştır.ikinizede tebrikler...");
    }

	return 0;
}
