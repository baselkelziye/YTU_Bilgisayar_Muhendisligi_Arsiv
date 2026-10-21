Program SymbolGame;
Uses crt, sysutils;
Label
	Inception, PlayAgain;
var
	A: Array [1..50, 1..50] of Integer;
	B: Array [1..50, 1..50] of Char;
	Symbol, Memorize: Array [1..100] of Char;
 	Menu, Player: Array [1..100] of String;
	Duration, Score: Array [1..100] of Integer;
	i, j, k, p, n, m, StoneRatio, SymbolNumber, tmp, step, old_step, go, up, wrong, FinishTime, StartTime, ResMM, ResSS, ResMS: Integer;
	ratio: Real;
	press: Char;
	HH, MM, SS, MS: Word;
	
	procedure PrintTable; {Bu prosedürde tablo oyuncuya gösterilir.}
	begin
		TextColor(LightCyan);
		Write('        ');
		for i := 97 To m+96 Do {10 ve üzeri sayıda sütunda tablo kaydığından dolayı harflendirdim.}
			Write('   ', chr(i));
		WriteLn;
		for i := 1 To n Do
		begin
            Write('         ');
			TextColor(LightBlue);
            for j := 1 To m Do
				Write(' ---');
            WriteLn;
			TextColor(LightCyan);
			Write('       ', i);
			TextColor(LightBlue);
			Write(' | ');
			for j := 1 To m Do
				if B[i,j] = 'P' Then {Oyuncu göstergesi kırmızı renkli olarak gösterilir.}
				begin
					TextColor(LightRed);
					Write(B[i,j]);
					TextColor(LightBlue);
					Write(' | ');
				end
				else
					Write(B[i,j], ' | ');
            WriteLn;
		end;

        Write('         ');
        for j := 1 To m Do
            Write(' ---');
	end;
	
	procedure Stopwatch; {Bu prosedürde oyun zamanı oyuncuya gösterilir.}
	begin
		{* Oyun içerisinde zaman milisaniye cinsinden Duration[p] dizisine kaydedilir. Aşağıdaki kısımda yazdırılırken tekrar dakika/saniye/milisaniye cinsine çevrilir. ('Res'ten kasıt 'result'.)*}
		ResMM := (Duration[p] DIV 1000) DIV 60;
		ResSS := (Duration[p] DIV 1000) - (ResMM*60);
		ResMS := Duration[p] - (ResMM*60*1000) - (ResSS*1000);
		
		{* Aşağıdaki if/else kontrolünün uygulanma sebebi oyun süresinin oyuncuya düzgün bir şekilde gösterilmesidir. Böylece 5 dakika 3 saniye 25 milisaniyede oyunu bitiren oyuncunun süresi 5:3.25 olarak değil, 05:03.025 olarak yazdırılır. *}					
		TextColor(Yellow);
		Write('      ');
		Write('Your time: ');
		TextColor(LightGreen);
		if ResMM DIV 10 = 0 Then
			Write('0', ResMM, ':')
		else
			Write(ResMM, ':');
		if ResSS DIV 10 = 0 Then
			Write('0', ResSS, '.')
		else
			Write(ResSS, '.');
		if ResMS DIV 10 = 0 Then
			Write('00', ResMS)
		else if ResMS DIV 100 = 0 Then
			Write('0', ResMS)
		else
			Write(ResMS);		
	end;
	
	procedure ScoreBoard; {Puan tablosu prosedürü.}
	var
		tmp1, tmp2, count: Integer;
		tmp3: String;
    begin
    	{Bubble sort ile oyuncu skorları karşılaştırılır ve büyükten küçüğe doğru sıralanır.}
		repeat 
			count := 0;
			for i := 1 To p-1 Do
			begin
				if Score[i] < Score[i+1] Then
				begin
					tmp1 := Score[i];
					Score[i] := Score[i+1];
					Score[i+1] := tmp1;
					tmp2 := Duration[i];
					Duration[i] := Duration[i+1];
					Duration[i+1] := tmp2;
					tmp3 := Player[i];
					Player[i] := Player[i+1];
					Player[i+1] := tmp3;
					count := count+1;					
				end;				
			end;			
		until (count = 0);		
		
		TextColor(LightCyan);		
		WriteLn; WriteLn;
		Write('         ');
		WriteLn('Ranking List: ');
		Write('         -------------');
		WriteLn;
		
		if p = 0 Then
		begin
			TextColor(White);
			WriteLn;
			Write('         Nobody played yet.');
		end		
		else
		begin			
			for i := 1 To p Do
			begin			
				ResMM := (Duration[i] DIV 1000) DIV 60;
				ResSS := (Duration[i] DIV 1000) - (ResMM*60);
				ResMS := Duration[i] - (ResMM*60*1000) - (ResSS*1000);	
				
				WriteLn;
				Write('         ');
				TextColor(LightCyan);
				Write(i, '. ');
				TextColor(LightGreen);
				Write(Player[i],': ');
				TextColor(Yellow);
				Write(Score[i]);
				TextColor(Yellow);
				Write(' (');
				
				if ResMM DIV 10 = 0 Then
					Write('0', ResMM, ':')
				else
					Write(ResMM, ':');
				if ResSS DIV 10 = 0 Then
					Write('0', ResSS, '.')
				else
					Write(ResSS, '.');
				if ResMS DIV 10 = 0 Then
					Write('00', ResMS)
				else if ResMS DIV 100 = 0 Then
					Write('0', ResMS)
				else
					Write(ResMS);
				Write(')');	
			end;		
		end;
	end;

    procedure MainMenu; {Ana menü elemanlarını renlendirme prosedürü.}
	begin
		Menu[1] := '        >  Play Game';
		Menu[2] := '        >  Scoreboard';
		Menu[3] := '        >  How to Play';
		Menu[4] := '        >  Credits';
		Menu[5] := '        >  Exit';
		
		up := 0; {* Up değişkeni yukarı tuşa her basıldığında bir arttırılır, aşağı tuşa her basıldığında bir azaltılır. Enter tuşuna basılana kadar up değişkeni değer değiştirir. Her değer değiştirdiğinde up değişkeninin 5 sayısına göre moduna göre menü elemanlarını renklendirir. Enter'a basıldığında en son renklenen kısmın içine gidilir. *}
		repeat
			TextColor(LightCyan);
			WriteLn; WriteLn; 
			WriteLn('        -----------------------------'); 
			TextColor(LightRed);
			WriteLn('         Welcome to the Symbol Game!');
			TextColor(LightCyan);
			WriteLn('        -----------------------------'); 
			WriteLn; WriteLn; 
			
			if (up MOD 5) = 0 Then
			begin
				TextColor(Yellow);
				WriteLn(Menu[1]);
				TextColor(White);
				for i := 2 To 5 Do						
					WriteLn(Menu[i]);					
			end;
					
			if (up MOD 5 = 1) OR (up MOD 5 = -4) Then
			begin
				TextColor(White);
				for i := 1 To 4 Do						
					WriteLn(Menu[i]);										
				TextColor(Yellow);
				WriteLn(Menu[5]);
			end;
					
			if (up MOD 5 = 2) OR (up MOD 5 = -3) Then
			begin
				TextColor(White);
				for i := 1 To 3 Do						
					WriteLn(Menu[i]);									
				TextColor(Yellow);
				WriteLn(Menu[4]);
				TextColor(White);
				WriteLn(Menu[5]);
			end;
					
			if (up MOD 5 = 3) OR (up MOD 5 = -2) Then
			begin
				TextColor(White);
				for i := 1 To 2 Do					
					WriteLn(Menu[i]);					
				TextColor(Yellow);
				WriteLn(Menu[3]);
				TextColor(White);					
				for i := 4 To 5 Do				
					WriteLn(Menu[i]);					
			end;
				
			if (up MOD 5 = 4) OR (up MOD 5 = -1) Then
			begin
				TextColor(White);
				WriteLn(Menu[1]);
				TextColor(Yellow);
				WriteLn(Menu[2]);
				TextColor(White);			
				for i := 3 To 5 Do					
					WriteLn(Menu[i]);					
			end;	
			
			Press := ReadKey;
			ClrScr;	
			if Press = #72 Then
				up := up + 1;
			if Press = #80 Then
				up := up - 1;
		until (Press = #13);		 
	end;
	
	procedure BackToTheMainMenu; {Menü elemanlarının sonunda kod tekrarı olmaması için kullanıldı.}
	begin
		repeat
			TextColor(White);
			WriteLn; WriteLn; WriteLn;
			Write('         ');
			WriteLn('To back to the main menu press ESC on your keyboard.');
			press := ReadKey;
			ClrScr;
		until ((press = #27) OR (press = #13));
	end;
	
begin
	ClrScr;
	Randomize;
	p := 0;

	Inception: {Label fonksiyonu. Menü elemanlarındayken ESC tuşuna basıldığında GoTo kullanımıyla bu bölüme dönülür.}
	MainMenu; {MainMenu prosedürü kullanıldı.}
	
	if (up MOD 5) = 0 Then
	begin
		PlayAgain: {Label fonksiyonu. Oyun sonunda ENTER tuşuna basılırsa GoTo kullanımıyla bu bölüme dönülür.}
		p := p + 1; {Oyuncu numarasını belirtir.}
		
		{Aşağıdaki bölümde oyuncudan oyuncu ve tablo bilgileri alınır.}
		ClrScr;
		WriteLn; WriteLn; WriteLn; WriteLn;
		Write('          ');
		Write('What is your nickname?: ');
		ReadLn(Player[p]);
		ClrScr;
		WriteLn; WriteLn; WriteLn; WriteLn;
		TextColor(LightGreen);
		Write('                       ');
		WriteLn('Good luck ', Player[p], '!');
		WriteLn;
		TextColor(Yellow);
		Write('         ');
		WriteLn('To start the game press ENTER on your keyboard.');
		ReadLn;
		ClrScr;
		
		WriteLn; WriteLn; WriteLn; WriteLn;
		TextColor(White);
			
		repeat
			Write('      What is the length of the board? (5 <= length <= 10): ');
			ReadLn(n);
		until ((n >= 5) AND (n <= 10));

		repeat
			Write('      What is the width of the raceway? (8 <= width <= 12): ');
			ReadLn(m);
		until ((m >= 8) AND (m <= 12));
		
		repeat
			Write('      What is the ratio percentage of stones? (70 <= ratio <= 100): ');
			ReadLn(StoneRatio);
		until ((StoneRatio >= 70) AND (StoneRatio <= 100));
		
		repeat
			Write('      What is the number of symbols? (5 <= symbols <= 20): ');
			ReadLn(SymbolNumber);
		until ((SymbolNumber >= 5) AND (SymbolNumber <= 20));
		WriteLn;
		
		for i := 1 To n Do
		begin
			{Oyuncuya gösterilecek olan ham tabloda tüm elemanlar yıldız işaretiyle gösterilir.}
			for j := 1 To m Do
				B[i,j] := '*';
			
			{* Oyuncuya gösterilmeyen, yıldızların asıl değerlerini belirten tablo elemanları başka bir dizide saklanır. Bu tablo elemanlarına [0,3] aralığında rastgele değerler atanır. Oyuncunun oyunun başında girdiği taş/delik oranına uyulması için repeat until döngüsü kullanılır. *}	
			repeat
				k := 0;
				for j := 1 To m Do
				begin
					tmp := Random(2);
					if tmp = 0 Then
						A[j,i] := Random(4)
					else				
						A[j,i] := 0; 

					{0 gelme ihtimalinin artması için yukarıdaki işlemler yapıldı. Tablo elemanlarının büyük bir kısmı zaten 0'dan oluşacak.}

					if A[j,i] = 0 Then
						k := k+1;
				end;
				ratio := (k * 100) / m;
			until (ratio > StoneRatio);
		end;
			
		ClrScr;
		WriteLn; WriteLn; WriteLn;
		PrintTable;	{Tablo yazdırma prosedürü kullanıldı.}
		WriteLn;
			
		DeCodeTime(Time,HH,MM,SS,MS); {Zamanı ölçen fonksiyon.}
		StartTime := (HH*60*60*1000)+(MM*60*1000)+(SS*1000)+MS; {Zaman milisaniye cinsinden kaydedildi.}
			
		step := 1; {Oyuncunu hangi sütunda olduğunu belirtir.}
		repeat {Oyuncu son sütunu geçene kadar aşağıdaki döngü tekrarlanır.}
			go := 0;
			repeat
				TextColor(Yellow);
				WriteLn;
				Write('        Which row that do you want to go on the column [', chr(step+96), ']?: ');
				ReadLn(go);
			until ((go >= 1) AND (go <= n));
				
			ClrScr;
			
			{Eğer seçilen karenin değeri 0 ise oyuncu yoluna devam eder ve bulunduğu yer 'P' ile oyuncuya gösterilir. Eğer 0 değilse, oyuncu karenin değeri kadar adım geriye gider.}

			if A[go,step] = 0 Then 
				B[go,step] := 'P'
			else
			begin
				old_step := step;
				TextColor(LightRed);
				WriteLn; WriteLn;
				Write('        You fell into a hole! ');
				step := step - A[go,step] - 1;
					
				if step <= 0 Then
					step := 0;
						
				WriteLn('Go back to column [', chr(step+97), ']!');
				
				{Oyuncu geriye gittikten sonra tablo temizleme aşağıdaki for döngüsüyle yapılır.}	
				for i := 1 To n Do
				begin
					for j := step + 1 To old_step Do
						B[i,j] := '*';
				end;			
			end;
				
			WriteLn; WriteLn; WriteLn;
			PrintTable; {Tablo yazdırma prosedürü.}
			WriteLn;
			step := step + 1;
				
		until (step = m+1);
			
		TextColor(LightGreen);
		ClrScr;
		WriteLn; WriteLn; WriteLn; WriteLn;
		Write('       ');
		WriteLn('Congratulations! Now you have to memorize a set of randomly generated symbols as fast as you can do!');  
		Write('                                  ');
		WriteLn('Press any key on your keyboard when you ready.');
		ReadLn;
		
		{Aşağıdaki döngüde oyuncunun oyunun başında belirtmiş olduğu sayı kadar rastgele sembol yazdırılır.}	
		for i := 1 To SymbolNumber Do
		begin
			tmp := Random(3);
			if tmp = 0 Then
				Symbol[i] := chr(Random(26)+65)
			else if tmp = 1 Then
				Symbol[i] := chr(Random(26)+97)
			else
				Symbol[i] := chr(Random(10)+48);
		end;
			
		ClrScr;
		WriteLn; WriteLn; WriteLn; WriteLn;
			
		repeat {Oyuncu sembolleri doğru sırayla girene kadar aşağıdaki döngü tekrarlanır.}
			WriteLn; WriteLn;
			Write('                                               ');
			for i := 1 To SymbolNumber Do {Yukarıda rastgele oluşturulan semboller yazdırılır.}
			begin
				TextColor(yellow);
				Write(Symbol[i], ' ');
			end;

			WriteLn; WriteLn;
			TextColor(LightGreen);
			Write('                                  ');
			WriteLn('Press any key on your keyboard when you ready.');
			ReadLn;
			ClrScr;
				
			wrong := 0;
			WriteLn; WriteLn;
			Write('          ');
			WriteLn('Write the symbols sequentially: ');
			WriteLn;

			for i := 1 To SymbolNumber Do {Oyuncu verilen sembolleri ezberler ve hatasız şekilde klavyeye girmeye çalışır.}
			begin
				Write('          ');
				TextColor(White);
				ReadLn(Memorize[i]);
				if Symbol[i] <> Memorize[i] Then
					wrong := wrong + 1; {Oyuncu her hata yaptığında hata değişkeni artar.}
			end;
				
			ClrScr;
			WriteLn; WriteLn; WriteLn; WriteLn;

			if wrong > 0 Then {Hata değişkeninin 0'dan fazla olması durumunda program hata verir.}
			begin
				TextColor(LightRed);
				Write('                                      ');
				WriteLn('You made a mistake! Try again.');
				WriteLn;
				TextColor(LightGreen);
				Write('                                ');
				WriteLn('Press any key on your keyboard when you ready.');
				ReadLn;
				ClrScr;
			end
			else {Hata değişkenin 0 olması durumunda aşağıdaki işlemler yapılır.}
			begin
				DeCodeTime(Time,HH,MM,SS,MS); {Zaman fonksiyonuyla zaman ölçülür.}
				FinishTime := (HH*60*60*1000)+(MM*60*1000)+(SS*1000)+MS; {Zaman milisaniye cinsinden kaydedilir.}
				Duration[p] := FinishTime - StartTime; 
				{Oyuncunun süresi son zamanın milisaniye değerinden ilk zamanın milisaniye değeri çıkarılarak bulunur.}
				Score[p] := ((n+5) * (SymbolNumber+10) * (50 - (StoneRatio MOD 69))* 1000) DIV (Duration[p] DIV 100);
				{* Oyuncu puanları sütun sayısı, karakter sayısı, taş/delik oranı ve oyunun tamamlanma süresi paremetreleri kullanılarak hesaplanır. Satır sayısı hesaba katılmaz çünkü o kısımda zorluğu belirleyen satır sayısı değil taş/delik oranıdır. *}
				Stopwatch; {Oyuncunun süresini yazdırmak için kronometre prosedürü kullanılır.}
				WriteLn;
				TextColor(Yellow);
				Write('      Your score: ');
				TextColor(LightGreen);
				Write(Score[p]); {Oyuncunun puanı yazdırılır.}
				ReadLn;
				ClrScr;
				ScoreBoard; {Puan tablosu yazdırma prosedürü.}
				WriteLn; WriteLn;
			end;
		until (wrong = 0);

		TextColor(White);
		WriteLn; WriteLn; WriteLn;
		Write('         ');
		WriteLn('To play again press ENTER on your keyboard.');		
		Write('         ');
		WriteLn('To back to the main menu press ESC on your keyboard.');
		press := ReadKey;
		ClrScr;

		if Press = #13 Then
			GoTo PlayAgain {Oyunun yeniden başlamak için Label fonksiyonu.}
		else if Press = #27 Then
			GoTo Inception;	{Başlangıca dönüş için Label fonksiyonu.}
	end
	
	else if (up MOD 5 = 2) OR (up MOD 5 = -3) Then
	begin
		WriteLn; WriteLn;
		TextColor(LightRed);
		WriteLn('                ---------------------------------------');
		TextColor(LightCyan);
		WriteLn;		
		WriteLn('                 Introduction to Computer Science - I'); 
		WriteLn('                          SEMESTER PROJECT');
		WriteLn;
		WriteLn('                             Osman Araz');
		WriteLn('                              16011020');
		WriteLn;
		TextColor(LightRed);
		WriteLn('                ---------------------------------------');
		BackToTheMainMenu; {Ana menüye dönüş için prosedür.}
		GoTo Inception; {Başlangıca dönüş için Label fonksiyonu.}
	end
	
	else if (up MOD 5 = 3) OR (up MOD 5 = -2) Then
	begin
		TextColor(LightGreen);
		WriteLn; WriteLn;
		WriteLn('                                 How to Play?');
		TextColor(LightRed);
		WriteLn; WriteLn; 
		WriteLn('   -------------------------------------------------------------------------'); 
		TextColor(LightCyan);
		WriteLn;
		WriteLn('     This game aims at reaching the end of a given board and then writing');	
		WriteLn('     the symbols given in random order as fast as possible.');
		WriteLn;
		WriteLn('     First, you need to move on a board consisting of holes and stones. On');
		WriteLn('     this board, you should reach the finish line as soon as possible. In');
		WriteLn('     each round you should try to predict one of the stones in the next step');
		WriteLn('     on a given board. After reaching the final destination, the system will'); 
		WriteLn('     produce symbols consisting of numbers and small/big letters display'); 
		WriteLn('     these symbols on the screen until you press any button. You should');
		WriteLn('     memorize the order and write the symbols in given order. If you make');
		WriteLn('     a mistake then the system will give an alert and the system will');
		WriteLn('     redisplay the correct order of symbols. When you find the correct');
		WriteLn('     order of the symbols you will complete the game.');
		WriteLn;
		WriteLn('     Do not forget, you will earn more points if you select bigger size for');
		WriteLn('     the table, less percenatge for the stones and bigger size for the number');
		WriteLn('     of symbols in the beginning of the game.');
		TextColor(LightRed);
		WriteLn;
		WriteLn('   -------------------------------------------------------------------------'); 

		BackToTheMainMenu; {Ana menüye dönüş için prosedür.}
		GoTo Inception; {Başlangıca dönüş için Label fonksiyonu.}
	end
	
	else if (up MOD 5 = 4) OR (up MOD 5 = -1) Then
	begin
		ScoreBoard; {Puan tablosu yazdırma prosedürü.}
		BackToTheMainMenu; {Ana menüye dönüş için prosedür.}
		GoTo Inception; {Başlangıca dönüş için Label fonksiyonu.}
	end
	else {Up değerinin 5'e göre modu 1 veya -4 iken ENTER tuşuna basılması sonucu programdan çıkılır.}
end.