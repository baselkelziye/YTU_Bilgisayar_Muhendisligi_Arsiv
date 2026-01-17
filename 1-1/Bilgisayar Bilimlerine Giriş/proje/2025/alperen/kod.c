#define NDEBUG

#include <stdio.h> /* printf, puts, scanf, getchar */
#include <stdlib.h> /* rand, srand, system, abs */
#include <time.h> /* time */
#include <assert.h> /* assert */

#define MAX_GAME_MATRIX_SIZE 	20 	/* En büyük matris boyutu */
#define MIN_GAME_MATRIX_SIZE 	3 	/* En küçük matris boyutu */

#define MAX_GAME_MATRIX_POSITION 	20 	/* Yer değiştirme veya patlama için girilebilecek en büyük koordinat */
#define MIN_GAME_MATRIX_POSITION 	1 	/* Yer değiştirme veya patlama için girilebilecek en küçük koordinat */

#define GAME_CHARACTERS_LENGTH 5 /* oyundaki toplam karakter çeşiti sayısı */

#define MIN_EXPLOSION_RANGE 3 /* en az bu kadar taş aynı tipte olmalı ki patlama olabilsin */

/* Oyun ön bilgisindeki n/2 satırının indisini bulan makro */
#define MIDDLE_ROW(n) ((n)-(n)/2)

/* oyun matrisini tanımlarken kullanacağımız tipi tanımladık (direkt char game_matrix[][20] diyebilirdik, daha temiz durması için) */
typedef char GameMatrix[MAX_GAME_MATRIX_SIZE][MAX_GAME_MATRIX_SIZE];

/* Oyun modlarının alabileceği değerler */
typedef enum GameMode
{
	GAME_MODE_UNKNOWN = 0, /* henüz bir değer almadığını göstermek için */
	GAME_MODE_NORMAL = 1,
	GAME_MODE_CONTROL = 2
}GameMode;

/* Oyun döngüsünde kullanıcının yapabileceği işlemler */
typedef enum GameOperation
{
	GAME_OPERATION_EXIT = -1,
	GAME_OPERATION_UNKNOWN = 0, /* henüz bir değer almadığını göstermek için */
	GAME_OPERATION_MOVE = 1,
	GAME_OPERATION_EXPLODE = 2
}GameOperation;

typedef enum ExplosionDirection
{
	EXPLOSION_DIRECTION_NOT_VALID = 0, /* patlama olamaz demek */
	EXPLOSION_DIRECTION_RIGHT = 1,
	EXPLOSION_DIRECTION_DOWN = 2
}ExplosionDirection;

/* Oyun matrisini ve matrisin boyutunu içinde tutan yapı */
typedef struct GameBoard
{
	GameMatrix matrix;
	int n; /* Row */
	int m; /* Column */
}GameBoard;

/* Oyun tahtasındaki bir noktayı gösteren koordinatı temsil eden yapı */
typedef struct Coord
{
	int i; /* Row */
	int j; /* Column */
}Coord;

typedef struct MatrixSize
{
	int n; /* Row */
	int m; /* Column */
}MatrixSize;

typedef struct ExplosionInfo
{
	ExplosionDirection explosionDirection;
	Coord coord;
	int range;
}ExplosionInfo;

/* Hareket hamlesi için gerekli olan iki koordinatı saklayan yapı */
typedef struct MovementCoords
{
	Coord c1;
	Coord c2;
}MovementCoords;

/* Oyun durumunu tek paket içinde tutmamızı sağlayan yapı */
typedef struct GameStatus
{
	GameMode gameMode;
	int movementCount, explosionCount;
}GameStatus;

/* oyunda kullanılacak karakterler */
const char gameCharacters[GAME_CHARACTERS_LENGTH] = {'*', '/', '+', '%', 'O'};

/* Stdin'deki çöp değerleri temizler */
void clear_stdin(void)
{
	int keyBuffer;
	while((keyBuffer = getchar()) != '\n' && keyBuffer != EOF);
}

/* Terminal ekranını temizler */
void clear_screen(void)
{
	/* terminali temizlemek için önişlemci komutları ile işletim sistemi tespit edilir */
	/* eğer herhangi geçerli bir sistem tespit edilmezse 1000 kere \n basılır (işlevsel) */
	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__) || defined(_WIN64) /* windows 32-bit veya 64-bit */
		system("cls");	
	#elif defined(__MSDOS__) || defined(__DOS__) || defined(MSDOS) || defined(_MSDOS) /* freedos veya dos-like (watcom) */
		system("cls");
	#elif defined(__APPLE__) || defined(__linux__) || defined(__unix__) /* unix like */
		system("clear");
	#else /* herhangi platform tespit edilemedi kaba yöntemle temizle */
		int i = 0;
		for(i = 0; i < 1000; i++)
		{
			printf("\n");
		}
	#endif
}

/* Oyun kurallarına göre en başta boş olması gereken yerlere '\0' karakterlerini doldurur */
void clear_matrix(GameBoard *gameBoard)
{
	int i = 0, j = 0;
	
	assert(gameBoard != NULL); /* yanlış parametre geçirilmesini önler (hata verir) */
	
	/* direkt tüm matrisi temizlemek yerine kullanıcıdan alınmayacak (boş bırakılacak) yerleri temizledik, daha az işlem yapar */
	for(i = 0; i < MIDDLE_ROW(gameBoard->n); i++)
	{
		for(j = 0; j < gameBoard->m; j++)
		{
			gameBoard->matrix[i][j] = '\0';
		}
	}
}

/* Mantık olarak powershell'deki pause komutuna benzer bir fonksiyon, enter tuşuna basana kadar bekler */
void pause(void) 
{
	printf("Devam etmek için Enter (Return) tuşuna basın . . .\n");
	clear_stdin(); /* bu fonksyion zaten getchar'ı çağırdığı için bir daha getchar çağırmamıza gerek yok */
}

/* Oyun ilk açıldığında ekrana yazılacak yazıları barındıran fonksiyon */
void print_splash_screen(void)
{
	/* stringleri parçalara ayırdık çünkü bu kadar uzun bir string c89 (ansi c) tarafından desteklenmez (null hariç en fazla 509 karakter) */
	puts(
			"Panel De Pon oyununa hoş geldiniz!\n"
			"Bu oyunun amacı karakterler en üst satıra değmeden en fazla sayıda element patlatmaya çalışmaktır\n"
			"Oyun karakterleri: [*/+%O]\n"
			"\n"
			"Oyun kuralları: \n"
			" 1- İki elementi yer değiştirmek istediğinizde sadece komşu iki elementlerin yerlerini değiştirebilirsiniz\n"
			" 2- Yerleri değişecek elemanlar birbirinden farklı olmalıdır\n"
			" 3- İki elementin yerleri değiştirildiğinde tüm satırlar birer yukarı kayar ve en alt satıra rastgele elementler eklenir"
		);
	puts(	" 4- En üst satıra herhangi bir element ulaştığında oyun direkt sona erer\n"
			" 5- Bir element grubunu patlatabilmek için en az 3 tane yan yana veya alt alta aynı elementten bulunmalıdır\n"
			" 6- Eğer hem dikey hem yatay patlama olabiliyorsa oyun en fazla element patlayabilecek olanı seçecektir\n"
			" 7- Eğer dikey ve yatay patlayabilecek element sayısı eşitse oyun yatay olanı seçer"
		);
	puts(	" 8- Bir element grubunu patlatmaya karar verdiğinizde bu grubun en üst veya en sol elementinin koordinatını girmeniz gerekmektedir\n"
			" 9- Yer değiştirme veya patlama işlemi seçildikten sonra koordinat yerine rakam olmayan bir karakter girmek işlemi iptal etmeyi sağlar\n"
			"\n"
			"Oyun Modları: \n"
			" 1- Normal Mod:\n"
			"  Bu modda oyun matrisinin alttan n/2 kadar satırı rastgele elementlerle doldurulur.\n"
			"  Her hamleden sonra oyun ekranı temizlenir"
		);
	puts(	" 2- Kontrol Mod:\n"
			"  Bu modda oyun matrisinin alttan n/2 kadar satırı ve M kadar sütununda bulunan elementler kullanıcıdan istenir\n"
		);
}

/* Oyun tahtasındaki matrisi boyuta uygun bir biçimde ekrana yazdırır */
void print_matrix(const GameBoard *gameBoard)
{
	int i = 0, j = 0;
	
	assert(gameBoard != NULL); /* yanlış parametre geçirilmesini önler (hata verir) */
	
	/* sütunun onlar basamağı yazılır, (en fazla 20'ye kadar destekler, daha fazlası için döngü mantığı kullanılmalı) */
	printf("\n  |%-.*s|\n  ", gameBoard->m*2-1, "0                 1                   2"); /* sütun sayısında göre 3. parametredeki string'in belli bir kısmı yazılır */
	/* sütun numarasının onlar basamağı yazıldı */
	
	/* sütun numarasının birler basamağı yazılır */
	for(j = 0; j < gameBoard->m; j++)
	{
		printf("|%d", (j+1)%10);
	}
	printf("|\n");
	/* sütun numarasının birler basamağı yazıldı */
	
	for(j = 0; j < gameBoard->m*2+3; j++) /* satırların en üstüne tire işaretleri konulur */
	{
		printf("-");
	}
	printf("\n");
	
	
	for(i = 0; i < gameBoard->n; i++)
	{
		printf("%02d", i+1); /* her satırın başında satır numarası yaz */
		for(j = 0; j < gameBoard->m; j++)
		{
			printf("|%c", (gameBoard->matrix[i][j] == '\0') ? ' ' : gameBoard->matrix[i][j]); /* tablo karakterini ve oyun karakterini yaz */
		}
		printf("|\n"); /* tablo karakterinin en sonuncusunu koy */
		for(j = 0; j < gameBoard->m*2+3; j++) /* yazılan satırın altına tire işaterlerini koy */
		{
			printf("-");
		}
		printf("\n");
	}
}

/* Oyunun o anki durumunu yazan fonksiyon, parametre olarak verilen değerlere ve moda göre ekranda yazılacak metinleri ayarlar. */
void print_status(const GameBoard *gameBoard, GameStatus gameStatus)
{
	assert(gameBoard != NULL); /* yanlış parametre geçirilmesini önler (hata verir) */
	assert(gameStatus.gameMode != GAME_MODE_UNKNOWN); /* oyun modu bilinmiyorsa hatalı */
	
	if(gameStatus.gameMode == GAME_MODE_NORMAL) /* eğer oyun modu ise ekranı temizle */
	{
		clear_screen();
	}
	/* durumu ekrana yaz */
	printf("\nToplam yer değişikliği: %d\nToplam patlatılan element: %d\n", gameStatus.movementCount, gameStatus.explosionCount);
	print_matrix(gameBoard);
}

/* Kullanıcıdan matrisin boyutunu ister */
MatrixSize get_matrix_size(void)
{
	int is_valid = 0, items_read = 0;
	MatrixSize matrixSize = {0, 0};
	do
	{
		is_valid = 1; /* Girdinin en başta doğru olduğu varsayılır */
		printf("Oyun alanının boyutlarını (N M) giriniz [%d-%d]: ", MIN_GAME_MATRIX_SIZE, MAX_GAME_MATRIX_SIZE);
		items_read = scanf("%d %d", &matrixSize.n, &matrixSize.m);
		clear_stdin();
		if(items_read != 2)
		{
			printf("Geçersiz girdi, bu girdi için 2 tane [%d-%d] arası tamsayı girmelisiniz!\n", MIN_GAME_MATRIX_SIZE, MAX_GAME_MATRIX_SIZE);
			is_valid = 0;
		}
		else /* girdi sayısı doğru bu yüzden n ve m'nin değerlerini kontrol edebiliriz */
		{
			if(matrixSize.n < MIN_GAME_MATRIX_SIZE || matrixSize.n > MAX_GAME_MATRIX_SIZE)
			{
				printf("N=%d değeri geçersiz aralıktadır!\n", matrixSize.n);
				is_valid = 0;
			}
			if(matrixSize.m < MIN_GAME_MATRIX_SIZE || matrixSize.m > MAX_GAME_MATRIX_SIZE)
			{
				printf("M=%d değeri geçersiz aralıktadır!\n", matrixSize.m);
				is_valid = 0;
			}
		}
		
		if(is_valid == 0) /* girdi hatalıysa kullanıcıyı bekle */
		{
			pause();
		}
		
	}while(is_valid == 0);
	return matrixSize;
}

/* Kullanıcıdan oyun modu istenir */
GameMode get_game_mode(void)
{
	int is_valid = 0, items_read = 0, gameMode = 0; /* return'de cast edilir */
	do
	{
		is_valid = 1;
		printf("Oyun modu için %d, kontrol modu için %d giriniz: ", GAME_MODE_NORMAL, GAME_MODE_CONTROL);
		items_read = scanf("%d", &gameMode);
		clear_stdin();
		if(items_read != 1)
		{
			printf("Geçersiz girdi, bu girdi için %d veya %d tamsayı değerlerini girmelisiniz!\n", GAME_MODE_NORMAL, GAME_MODE_CONTROL);
			is_valid = 0;
		}
		else if(gameMode != GAME_MODE_NORMAL && gameMode != GAME_MODE_CONTROL)
		{
			printf("Geçersiz mod, geçerli modlar: %d ve %d\n", GAME_MODE_NORMAL, GAME_MODE_CONTROL);
			is_valid = 0;
		}
		if(is_valid == 0)
		{
			pause();
		}
	}while(is_valid == 0);
	return (GameMode)gameMode;
}

/* Kullanıcıdan yer değişikliği mi patlama mı istediği sorulur */
GameOperation get_game_operation(void)
{
	int is_valid = 0, items_read = 0, gameOperation = 0; /* return'da cast edilir */
	do
	{
		is_valid = 1;
		printf( "Yer değişikliği için %d\n"
				"Patlama için %d\n"
				"Oyundan çıkmak için %d giriniz: ", GAME_OPERATION_MOVE, GAME_OPERATION_EXPLODE, GAME_OPERATION_EXIT);
		items_read = scanf("%d", &gameOperation);
		clear_stdin();
		if(items_read != 1)
		{
			printf("Geçersiz girdi, bu girdi için %d, %d veya %d tamsayı değerlerini girmelisiniz!\n", GAME_OPERATION_MOVE, GAME_OPERATION_EXPLODE, GAME_OPERATION_EXIT);
			is_valid = 0;
		}
		else if(gameOperation != GAME_OPERATION_MOVE && gameOperation != GAME_OPERATION_EXPLODE && gameOperation != GAME_OPERATION_EXIT)
		{
			printf("Geçersiz işlem, geçerli işlemler: {%d, %d, %d}\n", GAME_OPERATION_MOVE, GAME_OPERATION_EXPLODE, GAME_OPERATION_EXIT);
			is_valid = 0;
		}
		
		if(is_valid == 0)
		{
			pause();
		}
	}while(is_valid == 0);
	return (GameOperation)gameOperation;
}

/* Eğer işlem kullanıcı tarafından iptal edilmek istenirse (rakam olmayan bir karaktere basılırsa) koordinat olarak {{-1, -1},{-1, -1}} döner. (normal şartlarda olmayacak bir koordinat) */
MovementCoords get_movement_coordinates(const GameBoard *gameBoard, GameStatus gameStatus)
{
	int is_valid = 0, items_read = 0;
	MovementCoords movementCoords = {{0, 0}, {0, 0}};
	
	assert(gameBoard != NULL); /* yanlış parametre geçirilmesini önler (hata verir) */
	
	/* Yerleri değişecek iki koordinat kullanıcıdan alınır */
	do
	{
		is_valid = 1; /* girdinin en başta doğru olduğu varsayıldı */
		printf("Yerlerini değiştirmek istediğiniz iki koordinatı giriniz (format: r1,c1 r2,c2): ");
		items_read = scanf("%d , %d %d , %d", &movementCoords.c1.i, &movementCoords.c1.j, &movementCoords.c2.i, &movementCoords.c2.j);
		clear_stdin();
		if(items_read != 4)
		{
			printf("Geçersiz girdi, yer değiştirme işlemi iptal edildi\n");
			movementCoords.c1.i = 0, movementCoords.c1.j = 0, movementCoords.c2.i = 0, movementCoords.c2.j = 0;
			pause();
		}
		else
		{
			/* burada hataları else if.. diye değil de direkt if ile kontrol etmemizin sebebi */
			/* eğer birden fazla yanlış koordinat varsa hepsini birden kullanıcıya haber etsin için */
			if(movementCoords.c1.i < MIN_GAME_MATRIX_POSITION || movementCoords.c1.i > gameBoard->n)
			{
				is_valid = 0;
				printf("r1=%d değeri geçersiz aralıktadır!\n", movementCoords.c1.i);
			}
			if(movementCoords.c1.j < MIN_GAME_MATRIX_POSITION || movementCoords.c1.j > gameBoard->m)
			{
				is_valid = 0;
				printf("c1=%d değeri geçersiz aralıktadır!\n", movementCoords.c1.j);
			}
			if(movementCoords.c2.i < MIN_GAME_MATRIX_POSITION || movementCoords.c2.i > gameBoard->n)
			{
				is_valid = 0;
				printf("r2=%d değeri geçersiz aralıktadır!\n", movementCoords.c2.i);
			}
			if(movementCoords.c2.j < MIN_GAME_MATRIX_POSITION || movementCoords.c2.j > gameBoard->m)
			{
				is_valid = 0;
				printf("c2=%d değeri geçersiz aralıktadır!\n", movementCoords.c2.j);
			}
			if(is_valid == 1) /* koordinatlar geçerli aralıkta, şimdi koordinatların yer değiştirip değiştiremeyeceğini kontrol et */
			{
				if(gameBoard->matrix[movementCoords.c1.i-1][movementCoords.c1.j-1] == '\0')
				{
					is_valid = 0;
					printf("Girdiğiniz 1. koordinatlarda (%d,%d) herhangi bir karakter bulunmamaktadır!\n", movementCoords.c1.i, movementCoords.c1.j);
				}
				if(gameBoard->matrix[movementCoords.c2.i-1][movementCoords.c2.j-1] == '\0')
				{
					is_valid = 0;
					printf("Girdiğiniz 2. koordinatlarda (%d,%d) herhangi bir karakter bulunmamaktadır!\n", movementCoords.c2.i, movementCoords.c2.j);
				}
				if(movementCoords.c1.i != movementCoords.c2.i || abs(movementCoords.c1.j-movementCoords.c2.j) != 1) /* koordinatlar yan yana değil, sadece yan yana koordinatlar yer değiştirebilir*/
				{
					is_valid = 0;
					printf("(%d,%d) koordinatları ile (%d,%d) koordinatları yan yana değil!\n", movementCoords.c1.i, movementCoords.c1.j, movementCoords.c2.i, movementCoords.c2.j);
				}
				if(is_valid == 1) /* karakterlerin yer değiştimesinin önündeki tek engel: aynı olmaları */
				{
					if(gameBoard->matrix[movementCoords.c1.i-1][movementCoords.c1.j-1] == gameBoard->matrix[movementCoords.c2.i-1][movementCoords.c2.j-1])
					{
						is_valid = 0;
						printf("(%d,%d) koordinatındaki karakter ile (%d,%d) koordinatındaki karakter aynıdır: \'%c\'\n", movementCoords.c1.i, movementCoords.c1.j, movementCoords.c2.i, movementCoords.c2.j, gameBoard->matrix[movementCoords.c1.i-1][movementCoords.c1.j-1]);
					}
				}
			}
		}
		if(is_valid == 0) /* hata oldu, kullanıcıya bilgi verildi, bekle */
		{
			pause();
			print_status(gameBoard, gameStatus);
		}
	}while(is_valid == 0);
	movementCoords.c1.i--, movementCoords.c1.j--, movementCoords.c2.i--, movementCoords.c2.j--;
	return movementCoords;
}

/* Eğer işlem kullanıcı tarafından iptal edilmek istenirse (rakam olmayan bir karaktere basılırsa) koordinat olarak {-1, -1} döner. (normal şartlarda olmayacak bir koordinat) */
Coord get_explosion_coordinate(const GameBoard *gameBoard, GameStatus gameStatus)
{
	int is_valid = 0, items_read = 0;
	Coord coord = {0, 0};
	
	assert(gameBoard != NULL); /* yanlış parametre geçirilmesini önler (hata verir) */
	
	do
	{
		is_valid = 1; /* girdinin en başta doğru olduğu varsayıldı */
		printf("Patlatmak istediğiniz bloğun sol veya üst koordinatını giriniz (format: r,c): ");
		items_read = scanf("%d , %d", &coord.i, &coord.j);
		clear_stdin();
		if(items_read != 2)
		{
			printf("Patlatma işlemi iptal edildi\n");
			coord.i = 0, coord.j = 0;
			pause();
		}
		else
		{
			if(coord.i < MIN_GAME_MATRIX_POSITION || coord.i > gameBoard->n)
			{
				is_valid = 0;
				printf("r=%d değeri geçersiz aralıktadır!\n", coord.i);
			}
			if(coord.j < MIN_GAME_MATRIX_POSITION || coord.j > gameBoard->m)
			{
				is_valid = 0;
				printf("c=%d değeri geçersiz aralıktadır!\n", coord.j);
			}
			/* önce is_valid kontrol ettik ki eğer sınır dışında ise rastgele bellek adresine erişmeye çalışmasın */
			if(is_valid == 1 && gameBoard->matrix[coord.i-1][coord.j-1] == '\0') /* boş kutu patlatılamaz */
			{
				is_valid = 0;
				printf("Girdiğiniz koordinatta (%d,%d) herhangi bir karakter bulunmamaktadır!\n", coord.i, coord.j);
			}
		}
		if(is_valid == 0) /* hata oldu, kullanıcıya bilgi ver */
		{
			pause();
			print_status(gameBoard, gameStatus);
		}
	}while(is_valid == 0);
	coord.i--, coord.j--;
	return coord;
}

/* Oyun moduna göre gameMatrix'i kullanıcıdan alır veya rastgele oluşturur */
void do_initialize_game_matrix(GameBoard *gameBoard, GameMode gameMode)
{
	int is_valid = 0, i = 0, j = 0, k = 0;
	char ch = '\0';
	
	assert(gameBoard != NULL); /* yanlış parametre geçirilmesini önler (hata verir) */
	assert(gameMode != GAME_MODE_UNKNOWN); /* mod yoksa hata var */
	
	/* game_matrix'in boş kalması gereken kısımlarına '\0' değeri atanır */
	clear_matrix(gameBoard);
	
	if(gameMode == GAME_MODE_NORMAL)
	{
		for(i = MIDDLE_ROW(gameBoard->n); i < gameBoard->n; i++) /* ortadan sona kadar */
		{
			for(j = 0; j < gameBoard->m; j++)
			{
				gameBoard->matrix[i][j] = gameCharacters[rand() % GAME_CHARACTERS_LENGTH]; /* rastgele bir indisdeki karakteri alır */
			}
		}
	}
	else if(gameMode == GAME_MODE_CONTROL)
	{
		printf( "Kontrol modunu seçtiniz %d. satırın başından %d. satırın sonuna kadarki başlangıç durumlarını girmeniz gerekmektedir.\n"
				"Girebileceğiniz karakterler: [%.*s]\n", MIDDLE_ROW(gameBoard->n)+1, gameBoard->n, GAME_CHARACTERS_LENGTH, gameCharacters);
		for(i = MIDDLE_ROW(gameBoard->n); i < gameBoard->n; i++) /* ortadan sona kadar */
		{
			for(j = 0; j < gameBoard->m; j++)
			{				
				/* Girdi kontrolü yapılıp eğer doğru karakter girildi ise atama yapılır, hatalı girdi ise hata mesajı verilir. */
				do
				{
					is_valid = 1;
					printf("%d. satır, %d. sütun karakterini giriniz: ", i+1, j+1);
					scanf(" %c", &ch); /* %c değerinde bulunan boşluk kullanıcının hatalı girdi yapmasını önleyebilir. (girilen karakterden önceki white spaceleri atlayarak) */
					k = 0;
					while((k < GAME_CHARACTERS_LENGTH) && (ch != gameCharacters[k])) /* girilen karakterin oyun karakteri olup olmadığına karar veren döngü (döngü yerine 16-byte'lik (ascii ilk 128 byte) bitmap lookup table kullanılabilirdi, ancak veri 5'byte olduğu için değmez) */
					{
						k++;
					}
					if(k >= GAME_CHARACTERS_LENGTH) /* Geçersiz girdi */
					{
						printf( "\'%c\' karakteri geçerli bir oyun karakteri değil!\n"
								"Geçerli oyun karakterleri şunlardır: [%.*s]\n", ch, GAME_CHARACTERS_LENGTH, gameCharacters);
						is_valid = 0;
						clear_stdin();
						pause();
					}				
				}while(is_valid == 0);
				gameBoard->matrix[i][j] = ch; /* girdi kontrolü yapıldı, atama yapılabilir */
			}
		}
		clear_stdin(); /* döngü içinden çıkarıldı, çünkü girdi alırken matris kopyala yapıştıra engel oluyordu */
	}
}

/* ExplosionInfo'ya göre yer çekimi etkisini uygular */
void do_gravity(GameBoard *gameBoard, const ExplosionInfo *explosionInfo)
{
	int i = 0, j = 0;
	
	assert(gameBoard != NULL); /* yanlış parametre geçirilmesini önler (hata verir) */
	assert(explosionInfo != NULL); /* yanlış parametre geçirilmesini önler (hata verir) */
	
	if(explosionInfo->explosionDirection == EXPLOSION_DIRECTION_RIGHT)
	{
		for(j = explosionInfo->coord.j; j < explosionInfo->coord.j+explosionInfo->range; j++) /* sadece patlamanın etkilediği sütunlara bak */
		{
			for(i = explosionInfo->coord.i-1; i >= 0 && gameBoard->matrix[i][j] != '\0'; i--) /* patlamanın olduğu satırın bir üstünden başla ve en tepedeki boşluğu görene kadar devam et, normal şartlarda bir sütunda sadece patlama olan yerler ve boşluk '\0' olur */
			{
				gameBoard->matrix[i+1][j] = gameBoard->matrix[i][j];
			}
			gameBoard->matrix[i+1][j] = '\0'; /* aşağı alınan en son satırdaki değeri '\0' yaptık, çünkü o artık aşağıda */
		}
	}
	else if(explosionInfo->explosionDirection == EXPLOSION_DIRECTION_DOWN)
	{
		for(i = explosionInfo->coord.i-1; i >= 0 && gameBoard->matrix[i][explosionInfo->coord.j] != '\0'; i--) /* patlamanın olduğu satırın bir üstünden başla ve en tepedeki boşluğu görene kadar devam et, normal şartlarda bir sütunda sadece patlama olan yerler ve boşluk '\0' olur */
		{
			gameBoard->matrix[i+explosionInfo->range][explosionInfo->coord.j] = gameBoard->matrix[i][explosionInfo->coord.j]; /* üstteki değer patlama menzili kadar aşağı alındı */
			gameBoard->matrix[i][explosionInfo->coord.j] = '\0'; /* eskiden yukarıda olup sonradan aşağı alınan satırdaki değer '\0' yapıldı */
		}
	}
}

/* Verilen konuma göre patlama olup olamayacağını, olursa ne yöne olacağını ayarlar. ve patlama olacak yerleri '\0' karakteri ile doldurur. */
void do_explosion(GameBoard *gameBoard, ExplosionInfo *explosionInfo)
{
	int i = 0, j = 0;
	int right_length = 1, down_length = 1; /* 1'den başlıyor çünkü kendisini de sayar */
	
	assert(gameBoard != NULL); /* yanlış parametre geçirilmesini önler (hata verir) */
	assert(explosionInfo != NULL);
	
	/* ilk değerler patlama oladığını varsayar */
	explosionInfo->explosionDirection = EXPLOSION_DIRECTION_NOT_VALID;
	explosionInfo->range = 0;
	
	for(j = explosionInfo->coord.j+1; j < gameBoard->m && gameBoard->matrix[explosionInfo->coord.i][j-1] == gameBoard->matrix[explosionInfo->coord.i][j]; j++) /* sağa doğru */
	{
		right_length++;
	}
	for(i = explosionInfo->coord.i+1; i < gameBoard->n && gameBoard->matrix[i-1][explosionInfo->coord.j] == gameBoard->matrix[i][explosionInfo->coord.j]; i++) /* aşağı doğru */
	{
		down_length++;
	}
	/* Mesafeler hesaplandı, bu bilgilere göre ExplosionInfo doldurulur */
	
	/* Eğer mesafeler eşit ise sağa doğru olan patlamanın oyun ömrünü uzatması daha muhtemel olduğu için sağa doğru patlatılır */
	if(right_length >= down_length)
	{
		if(right_length >= MIN_EXPLOSION_RANGE)
		{
			explosionInfo->explosionDirection = EXPLOSION_DIRECTION_RIGHT;
			explosionInfo->range = right_length;
			/* Bu döngünün amacı sadece görselliktir, çünkü yer çekimi fonksiyonu değerin '\0'  olduğuna değil explosionInfo->range'ye bakar */
			/* kullanıcıya matrisin patlama olduktan sonraki, yer çekimi uygulanmadan önceki halini göstermek için */
			for(j = explosionInfo->coord.j; j < explosionInfo->coord.j+right_length; j++)
			{
				gameBoard->matrix[explosionInfo->coord.i][j] = '\0';
			}
		}
	}
	else /* aşağı */
	{
		if(down_length >= MIN_EXPLOSION_RANGE)
		{
			explosionInfo->explosionDirection = EXPLOSION_DIRECTION_DOWN;
			explosionInfo->range = down_length;
			/* Bu döngünün amacı sadece görselliktir, çünkü yer çekimi fonksiyonu değerin '\0'  olduğuna değil explosionInfo->range'ye bakar */
			/* kullanıcıya matrisin patlama olduktan sonraki, yer çekimi uygulanmadan önceki halini göstermek için */
			for(i = explosionInfo->coord.i; i < explosionInfo->coord.i+down_length; i++)
			{
				gameBoard->matrix[i][explosionInfo->coord.j] = '\0';
			}
		}
	}
}

/* geri dönüş değeri olarak oyunun bitip bitmediğini döner (0 bitmedi, 1 bitti) */
int do_append_new_random_row(GameBoard *gameBoard)
{
	int ended = 0, temp = 0, i = 0, j = 0;
	
	assert(gameBoard != NULL); /* yanlış parametre geçirilmesini önler (hata verir) */
	
	for(j = 0; j < gameBoard->m; j++) /* matrisin en altına yeni satırı ekleme döngüsü, her sütuna tek tek eklenir */
	{
		/* matrisin en alt satırından üst satırlara doğru kaydırma işlemi yapılır. */
		/* en üstten başlamak daha az değişken kullanmamızı sağlardı ancak bu sefer önce boş olmayan satırı bulmamız gerekirdi (veya boş yere işlem gücü harcardık, boş satırları kaydırarak) */
		temp = gameBoard->matrix[gameBoard->n-1][j]; /* en alttaki elemanı al */
		for(i = gameBoard->n-2; i >= 0 && temp != '\0'; i--) /* temp != '\0' kontrolü ile gereksiz kaydırma işlemlerinden kaçınmış olduk */
		{
			/* eski değeri old_val ile tut, alttaki değer bu yere atanınca temp'i old_val yap */
			int old_val = gameBoard->matrix[i][j];
			gameBoard->matrix[i][j] = temp;
			temp = old_val;
		}
		/* sütundaki her satır bir üste kaydırıldı, şimdi rastgele yeni bir karakteri en alta yaz */
		gameBoard->matrix[gameBoard->n-1][j] = gameCharacters[rand() % GAME_CHARACTERS_LENGTH];
		/* en üst satırı kontrol et, eğer bir taş varsa ended = 1 */
		if(gameBoard->matrix[0][j] != '\0')
		{
			ended = 1; /* yani kaybettin */
		}
	}
	/* döngüden ended 1 olduğu gibi çıkmıyorruz çünkü bunu yapmak bazı sütunlar yukarı kaydırılmadan döngüyü bitirmek demek olur */
	return ended;
}

/* İki taşın yerini değiştiren fonksiyon */
void do_movement(GameBoard *gameBoard, MovementCoords movementCoords)
{
	char ch = '\0';
	
	assert(gameBoard != NULL); /* yanlış parametre geçirilmesini önler (hata verir) */
	
	ch = gameBoard->matrix[movementCoords.c1.i][movementCoords.c1.j];
	gameBoard->matrix[movementCoords.c1.i][movementCoords.c1.j] = gameBoard->matrix[movementCoords.c2.i][movementCoords.c2.j];
	gameBoard->matrix[movementCoords.c2.i][movementCoords.c2.j] = ch;
}

/* Herhangi bir patlama veya yer değişikliği mümkün mü diye kontrol eder. (0 mümkün değil, 1 mümkün) */
int do_check_possible_mov_and_exp(GameBoard *gameBoard)
{
	int i = 0, j = 0;
	int possible = 0;
	
	assert(gameBoard != NULL);
	
	/* yer değişikliği mümkün mü onu kontrol et */
	/* en alt satırdan başlamak daha mantıklı, üst satırlara gittikçe yer değişikliği yapabilme şansı azalabilir. */
	for(i = gameBoard->n-1; (i >= 0) && (possible == 0); i--)
	{
		for(j = 0; (j < gameBoard->m-1) && (possible == 0); j++) /* en sağın bir soluna kadar git */
		{
			if(gameBoard->matrix[i][j] != '\0' && gameBoard->matrix[i][j+1] != '\0' &&
				gameBoard->matrix[i][j] != gameBoard->matrix[i][j+1]) /* ben null değilim, sağımdaki null değil ve birbirimizden farklıyız. yani yer değiştirebiliriz */
			{
				possible = 1;
			}
		}
	}
	
	/* herhangi bir yatay patlama olabilir mi diye kontrol et */
	/* en alt satırda daha fazla taş olabileceği için en alt satırdan kontrole başla */
	for(i = gameBoard->n-1; (i >= 0) && (possible == 0); i--)
	{
		for(j = 0; (j <= gameBoard->m-3) && (possible == 0); j++) /* en sağın 3 soluna kadar kontrol et */
		{
			if(gameBoard->matrix[i][j] != '\0' && gameBoard->matrix[i][j] == gameBoard->matrix[i][j+1] && gameBoard->matrix[i][j] == gameBoard->matrix[i][j+2]) /* boş değil, bir sağındaki ve 2 sağındaki karakter ile aynı */
			{
				possible = 1;
			}
		}
	}
	
	/* herhangi bir dikey patlama olabilir mi diye kontrol et */
	for(j = 0; (j < gameBoard->m) && (possible == 0); j++)
	{
		/* alt satırlarda daha fazla taş olabileceği için aşağıdan kontrol et */
		for(i = gameBoard->n-1; (i >= 2) && (possible == 0); i--) /* en üstün 3 altına kadar kontrol et */
		{
			if(gameBoard->matrix[i][j] != '\0' && gameBoard->matrix[i][j] == gameBoard->matrix[i-1][j] && gameBoard->matrix[i][j] == gameBoard->matrix[i-2][j]) /* boş değil, bir üstündeki ve 2 üstündeki karakter ile aynı */
			{
				possible = 1;
			}
		}
	}
		
	return possible;
}

int main()
{
	int ended = 0;
	GameBoard gameBoard = {0};
	GameStatus gameStatus = {GAME_MODE_UNKNOWN, 0, 0};
	GameOperation gameOperation = GAME_OPERATION_UNKNOWN;
	MatrixSize matrixSize = {0}; /* get_matrix_size fonksiyonunu geri dönüş değerini tutmak için kullanıldı */
	
	srand(time(NULL)); /* rastgele sayı üretmek için zamanı kullandık. basit bir oyun için yeterli "rastgelelik" sağlar */
	
	clear_screen();
	print_splash_screen();
	
	/* matrisin boyutunu al ve gameBoard'ın değişkenlerine ata */
	matrixSize = get_matrix_size();
	gameBoard.n = matrixSize.n;
	gameBoard.m = matrixSize.m;
	
	gameStatus.gameMode = get_game_mode();
	
	/* Modlara göre matrisi oluştur veya iste */
	do_initialize_game_matrix(&gameBoard, gameStatus.gameMode);
	
	/* Oyunun asıl döngüsü */
	do
	{
		print_status(&gameBoard, gameStatus);
		
		gameOperation = get_game_operation();
		
		if(gameOperation == GAME_OPERATION_EXIT) /* Oyundan çıkılmak istendiğinde */
		{
			printf("Oyun kullanıcı isteği ile sonlandırılmıştır.\n");
			ended = 1;
		}
		else if(gameOperation == GAME_OPERATION_MOVE) /* İki karakterin yerini değiştirmek istediğinde */
		{
			MovementCoords movementCoords = get_movement_coordinates(&gameBoard, gameStatus);
			if(movementCoords.c1.i != -1) /* işlem iptal edilmedi */
			{
				do_movement(&gameBoard, movementCoords);
				
				gameStatus.movementCount++;
				
				print_status(&gameBoard, gameStatus);
				printf("Yer değiştirildi. Yeni satır ekleniyor\n");
				pause();
				
				ended = do_append_new_random_row(&gameBoard);
				
				if(ended == 1) /* en üst satırda 0 olmayan eleman var */
				{
					print_status(&gameBoard, gameStatus);
					printf("Oyun en üst satırda eleman bulunduğu için sonlandırılmıştır.\n");		
				}
				
			}
		}
		else if(gameOperation == GAME_OPERATION_EXPLODE) /* patlama yapmak istediğinde */
		{
			Coord coord = get_explosion_coordinate(&gameBoard, gameStatus);
			if(coord.i != -1) /* kullanıcı işlemi iptal etmediyse */
			{
				ExplosionInfo explosionInfo = {EXPLOSION_DIRECTION_NOT_VALID, {0, 0}, 0}; /* ilk değeri bilmiyoruz */
				explosionInfo.coord = coord;
				do_explosion(&gameBoard, &explosionInfo);
				if(explosionInfo.range > 0) /* patlama olmadıysa yer çekimi uygulamaya ve kilitlenme kontrolü yapmaya gerek yok */
				{
					gameStatus.explosionCount += explosionInfo.range;
					
					print_status(&gameBoard, gameStatus);
					printf("Patlama gerçekleşti. Yer çekimi uygulanıyor\n");
					pause();
					
					do_gravity(&gameBoard, &explosionInfo);
					
					ended = !do_check_possible_mov_and_exp(&gameBoard); /* hareket mümkün değilse biter */
					
					/* sadece patlama durumunda oyun kilitlenebilir */
					if(ended == 1)
					{
						print_status(&gameBoard, gameStatus);
						printf("Oyun kilitlendi!\n");		
					}
					
				}
				else /* patlama olamadığını kullanıcıya bildir */
				{
					printf("Herhangi bir patlama olamadı!\n");
					pause();
				}
				
			}
		}
	}while(ended == 0);
	
	return 0;
}