#include <stdio.h>

int main(void)
{

	char D[7] = {'k', 'a', 'm', 'n', 'e', 'r', 'i'};
	char kelimeler[][7] = {"anemik", "kameri", "marine", "minare", "makine", "anemi", "mekan", "krema", "kerim", "inmek", "imkan", "imren", "imran", "erkan", "ekran", "mera", "krem", "mine", "mira", "name", "ekim", "erik", "kim", "nem", "nam", "ani", "kin", "kir"};
	

	int uzunlukD = sizeof(D) / sizeof(D[0]), uzunlukKelimeler = sizeof(kelimeler) / sizeof(kelimeler[0]), i, j, puan, toplamPuan = 0, harfKontrol, ayniHarfKontrol, kelimeKontrol;
	char tahmin[100];

	printf("Kullanabileceginiz karakterler: ");
	for (i = 0; i < uzunlukD; i++)
	{
		printf("%c ", D[i]);
	}

	while (tahmin[0] != '0')
	{
		puan = 0;

		printf("\ntahmin giriniz: ");
		scanf("%s", tahmin);

		if (tahmin[0] != '0')
		{
			// tahmindeki harfler ile D dizisindeki harfler eslesiyor mu?
			harfKontrol = 0;
			i = 0;
			do
			{
				j = 0;
				harfKontrol = 0;
				while (j < uzunlukD && harfKontrol != 1)
				{
					if (tahmin[i] == D[j])
					{
						harfKontrol = 1;
					}
					else
					{
						harfKontrol = 0;
					}
					j++;
				}
				i++;
			} while (tahmin[i] != '\0' && harfKontrol != 0);

			// eger D dizisindeki harflerle eslesiyor ise ayni harf birden fazla kullanilmis mi ? ayniHarfKontrol : 1 ise kullanilmis, 0 ise kullanılmamis
			ayniHarfKontrol = 0;
			i = 0;
			while (tahmin[i] != '\0' && ayniHarfKontrol != 1)
			{
				j = i + 1;
				while (tahmin[j] != '\0' && ayniHarfKontrol != 1)
				{
					if (tahmin[i] == tahmin[j])
					{
						ayniHarfKontrol = 1;
					}
					j++;
				}
				i++;
			}

			// harfler dizidekilerle eslesiyor mu?
			//  harfKontrol : 1 ise D dizisinde vardir, 0 ise D dizisinde yoktur
			if (harfKontrol == 1 && ayniHarfKontrol == 0)
			{

				// listede boyle bir kelime var mi? kelimeKontrol : 1 ise listede vardir, 0 ise listede yoktur
				kelimeKontrol = 0;
				for (i = 0; i < uzunlukKelimeler; i++)
				{
					for (j = 0; tahmin[j] == kelimeler[i][j] && tahmin[j] != '\0'; j++)
						;
					if (tahmin[j] == kelimeler[i][j])
					{
						kelimeKontrol = 1;
						kelimeler[i][0] = '0';
					}
				}

				if (kelimeKontrol == 1)
				{
					for (i = 0; tahmin[i]; i++)
					{
						puan += 1;
						toplamPuan += 1;
					}
				}

				else
				{

					for (i = 0; tahmin[i]; i++)
					{
						puan -= 1;
						toplamPuan -= 1;
					}
				}
			}
			else
			{
				for (i = 0; tahmin[i]; i++)
				{
					puan -= 1;
					toplamPuan -= 1;
				}
				printf("Hatali harf kullanimi, ");
			}

			printf("Puaniniz: %d", puan);
		}
	}

	printf("Oyun bitmistir. Tebrikler! Toplam puaniniz: %d\n", toplamPuan);

	return 0;
}
