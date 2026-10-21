program SymbolPredictionGame;
uses crt;
label start;
var
boardSize,level,i,j,k,l,m,n,x,player,computer,turn,a,b:integer;
tmp:char;
flag,flagg,controlflag:boolean;
control:string;
symbols:array [1..100] of char;
playGround:array [1..100,1..100] of char;
memo:array[1..100,1..100] of char;
done:array[1..100] of integer;
//boardSize:oyun sahasının boyutu, i,j,k,l:döngü yardımcıları ve tahmin yaparken kullanılan elemanlar, m:başarılı tahmin sayacı,
//n,a,b:döngü yardımcıları,  player,computer:skor tutucular, turn:kalan el sayısı, x:memoya atılacak tahminlerin belirlenmesine yardımcı
//flag: nizami tahmin denetleyici, flagg: doğru tahminden sonraki ekstra tahmin haklarının kalıp kalmamasını denetleyici
//symbols: kullanılacak sembollerin tutulduğu ve karıldığı dizi, playground:sembol dizilimini tutan çift boyutlu dizi,
//done:bulunan sembolleri tutan dizi, memo:bilgisayarın hafızasına attığı tahminleri tutan dizi
//control: girilen değerin istenen türde olmaması durumunda programın çökmemesi için yapılan kontrolde kullanılan string
//controlflag: bir önceki satırda bahsedilen kontrolde rol alan boolean

begin
textcolor(15);
start: //replay için kullanılan etiket
Randomize;
clrscr;

//sembol dizisi oluşturan bölüm, oyunda ascii değeri 48-97 olan semboller kullanılıyor
         for i:=1 to 50 do
         begin
         symbols[2*i]:=char(47+i);
         symbols[(2*i)-1]:=char(47+i);
         end;

//---------------------------------------------------------------------------------------------------------------------------------------------------------------

//saha boyutunu alan ve girilen değerin kontrolünü yapan bölüm
       repeat
       gotoxy(1,1);
       writeln('Please select the size of the playground(6/8/10)..');
       gotoxy(1,2);
       clrEOL;
       readln(control);
                     if ((length(control)=2) AND (control[1]='1') AND (control[2]='0')) then
                     //girilen değerin istenen tür ve değerlerde olup olmamasının kontrolü
                     boardSize:=10
                     else if ((length(control)=1) AND (control[1]='6') OR (control[1]='8')) then
                     boardSize:= integer(control[1])-48
                     else boardSize:=5;
       until (boardSize<>5);

writeln;
//oyun zorluğunun seçildiği ve girilen değerin kontrolünün yapıldığı bölüm
       repeat
       gotoxy(1,4);
       writeln('Please select the difficulty..');
       writeln('1-Beginner');
       writeln('2-Intermediate');
       writeln('3-Advanced');
       writeln('4-Professional');
       writeln('5-Surprise');
       gotoxy(1,10);
       clrEOL;
       readln(control);
                     if (length(control)=1) then
                     level:=integer(control[1])-48
                     else level:=6;
                     if (level=5) then
                     begin
                     level:=random(4)+1;
                     end;
       until (level<5) AND (level>0);

writeln;
//oynanacak el sayısının belirlendiği bölüm
       repeat
       gotoxy(1,12);
       writeln('Please enter the number of turns you want to play (min 5)..');
       gotoxy(1,13);
       clrEOL;
       readln(control);
       controlflag:=true;
       j:=1;
       turn:=0;
                       for a:=1 to length(control) do begin
                           if ((integer(control[a])<48) OR (integer(control[a])>57)) then
                           controlflag:=false; end;
                       if (controlflag) then begin
                       for a:=length(control) downto 1 do begin
                       turn:=turn+((integer(control[a])-48)*j);
                       j:=j*10; end; end
                       else turn:=4;
       until (turn>4);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------

//saha boyutuna göre kullanılacak olan sembolleri karan bölüm. Örneğin 6x6 bir saha için sadece ilk 36 karılır.
       for i:=1 to boardSize*boardSize do
       begin
       k:=random(boardSize*boardSize)+1;
       tmp:=symbols[k];
       symbols[k]:=symbols[i];
       symbols[i]:=tmp;
       end;
//clrscr; for i:=1 to 100 do begin write(symbols[i],' '); end; readln(k);
//yukarıdaki kodu aktifleştirirseniz sadece kullanılacak sayıda sembolün karıldığını, kalanının sıralı durduğunu görürsünüz

//sembolleri iki boyutlu diziye dizen bölüm
k:=1;
     for i:=1 to boardSize do
     begin
          for j:=1 to boardSize do
          begin
          playGround[i][j]:=symbols[k];
          k:=k+1;
          end;
     end;
//clrscr; for i:=1 to boardSize do begin for j:=1 to boardSize do begin write(playGround[i][j],' '); end; writeln; end; readln(k);

//---------------------------------------------------------------------------------------------------------------------------------------------------------------

//oyun sahasını çizen bölüm
clrscr;

write(' ');
        for j:=1 to boardSize do
        begin write('___ ');
        end;
writeln;

        for i:=1 to boardSize do
        begin

        write('|');
                   for j:=1 to boardsize do
                   begin
                   write('   |');
                   end;
        writeln;
        write('|');
                   for j:=1 to boardsize do
                   begin
                   write(' * |');
                   end;
        writeln;
        write('|');
                   for j:=1 to boardsize do
                   begin
                   write('___|');
                   end;
        writeln;
        end;


player:=0;
computer:=0;
gotoxy(boardSize*4+4,4);
write('Player: ', player);
gotoxy(boardSize*4+4,5);
write('Computer: ',computer);
gotoxy(boardSize*4+4,7);
write('Turns left: ',turn);

//--------------------------------------------------------------------------------------------------------------------------------------------------------------

//oyunun başlangıcı
m:=1; //başarılı tahmin sayısı tutucu, her zaman 1 fazladır, bilinen değerlerin tekrar girilmemesinde kullanılır. done arrayinin indisidir
x:=0; //değerinin mod4 değerine ve level derecesine göre hafızaya kaydedilecek tahminleri seçmede kullanılır
flag:=true; //nizami tahmin yapılmasını denetler
for i:=1 to 100 do begin done[i]:=0; end; //done dizisinin boşlukla doldurulması. bilinen sembollerin koordinatları done dizisinde 10*i+j diye tutulur.
for i:=1 to boardSize do begin for j:=1 to boardSize do begin memo[i][j]:=' '; end; end; //memo dizisinin boşlukla doldurulması

    repeat //oyunu döndüren ve turn sıfırlanınca oyunu bitiren repeat

    //oyuncunun tahmini
                repeat //doğru tahmin durumunda ekstra tahmin hakkı veren repeat
                       if (turn>0) then
                       begin
                         repeat //yapılacak tahminin nizami olup olmamasını denetleyen repeat
                         flag:=true;

                         gotoxy(1,boardSize*3+4);
                         writeln('Select a row..');
                         gotoxy(1,boardSize*3+5); clrEOL;
                         read(i);

                         gotoxy(1,boardSize*3+6);
                         writeln('Select a column..');
                         gotoxy(1,boardSize*3+7); clrEOL;
                         read(j);
                                 if (m>1) then begin for n:=1 to m-1 do begin if   ((10*i+j)=done[n]) then flag:=false; end; end;
                                 //eğer daha önce bilinmiş sembol varsa, kullanıcının girdiği değerlerin gösterdiği yerler zaten bilinmiş sembollere ait mi kontrolü
                                 if (i<1) OR (i>boardSize) OR (j<1) OR (j>boardSize) then flag:=false;
                                 //kullanıcı oyun alanında olmayan bir koordinat mı girdi kontrolü
                         until flag;

                       gotoxy(j*4-1,i*3);  //nizami tahminin tabloda açılması
                       write(playGround[i][j]);
                       gotoxy(boardSize*4+4,2);
                       write('YOU FOUND A "',playground[i][j],'", WHAT IS NEXT?   ' );

                         repeat //2. tahminin nizami olup olmadığının kontrolü
                         gotoxy(1,boardSize*3+5); write('            '); gotoxy(1,boardSize*3+7); write('            ');
                         flag:=true;
                         gotoxy(1,boardSize*3+4);
                         writeln('Select a row..');
                         read(k);
                         writeln('Select a column..');
                         read(l);
                                 if (m>1) then begin for n:=1 to m-1 do begin if ((10*k+l)=done[n]) then flag:=false; end; end;
                                 if (k<1) OR (k>boardSize) OR (l<1) OR (l>boardSize) then flag:=false;
                                 if ((10*k+l)=(10*i+j)) then flag:=false;
                                 //kullanıcı bir önceki tahminiyle aynı değeri mi girdi kontrolü
                         until flag;

                       gotoxy(l*4-1,k*3);
                       write(playGround[k][l]);

                                              if (playGround[i][j]=playGround[k][l]) then //tahminin doğruluğunun kontrolü.
                                              begin
                                              flagg:=false; //2. tahmin hakkı verildi
                                              player:=player+1; //skor arttırıldı
                                              done[m]:=10*i+j; done[m+1]:=10*k+l; m:=m+2;
                                              memo[i][j]:=' ';  //bilinen sembol bilgisayarın hafızasında varsa silinir
                                              memo[k][l]:=' ';
                                              gotoxy(boardSize*4+4,2);
                                              write('YOU FOUND A COUPLE!              ');
                                              gotoxy(boardSize*4+4,4);
                                              write('Player: ', player);
                                              delay(4000);
                                              gotoxy(boardSize*4+4,2);
                                              write('YOUR TURN                        ');
                                              gotoxy(j*4-1,i*3); write(' ');
                                              gotoxy(l*4-1,k*3); write(' ');
                                              end else begin
                                              flagg:=true; //ikinci hak verilmeyecek
                                              x:=x+1;
                                                     if (((level=1) AND (x mod 4=1)) OR ((level=2) AND ((x mod 4=1) OR (x mod 4=2))) OR ((level=3) AND (x mod 4<>0)) OR (level=4)) then
                                                     memo[i][j]:=playGround[i][j];; //tahmin memoya eklenir
                                              x:=x+1;
                                                     if (((level=1) AND (x mod 4=1)) OR ((level=2) AND ((x mod 4=1) OR (x mod 4=2))) OR ((level=3) AND (x mod 4<>0)) OR (level=4)) then
                                                     memo[k][l]:=playGround[k][l];
                                              gotoxy(boardSize*4+4,2);
                                              write('YOU COULD NOT A FIND A COUPLE.   ');
                                              delay(10000);
                                              gotoxy(j*4-1,i*3); write('*');
                                              gotoxy(l*4-1,k*3); write('*'); //bilinemeyen değerler kapatılır
                                              end;


                       end else
                       flagg:=true;

                       if (m>boardSize*boardSize) then
                       turn:=0;   //tüm tablo bulunduysa kalan el sayısının sıfırlanması

                until flagg;



    //bilgisayar tahmini
             repeat
                   if (turn>0) then
                   begin
                   tmp:=' ';
                        for i:=1 to boardSize do //hafızaya atılmış 2 aynı sembol koordinatı kontrolü. iç içe 4 for 1 if
                        begin
                             for j:=1 to boardSize do
                             begin
                                  for k:=1 to boardSize do
                                  begin
                                       for l:=1 to boardSize do
                                       begin
                                            if (memo[k][l]<>' ') AND ((memo[i][j]=memo[k][l]) AND ((i<>k) OR (j<>l))) then
                                            //memoda aynı olduğu tespit edilen sembollerin hafızada farklı yerlerde olduğu kontrol ediliyor.
                                            tmp:=memo[i][j];
                                       end;
                                  end;
                             end;
                        end;

                        if (tmp<>' ') then  //bulunduysa kullanılması, bulunmadıysa random tahmin edilecek.
                        begin
                             for k:=1 to boardSize do
                             begin
                                  for l:=1 to boardSize do
                                  begin
                                       if (memo[k][l]=tmp) then
                                       begin
                                       i:=k;
                                       j:=l;
                                       end;
                                  end;
                             end;
                        end else begin //bulunmadıysa burası devreye girecek
                            repeat //random seçimin nizami oluşunun kontrolü
                            flag:=true;
                            i:=random(boardSize)+1;
                            j:=random(boardSize)+1;
                                 if (m>1) then begin
                                 for n:=1 to m-1 do begin
                                 if ((10*i+j)=done[n]) then flag:=false; end; end;
                            until flag;
                        end;

                   gotoxy(j*4-1,i*3);
                   write(playGround[i][j]);
                   gotoxy(boardSize*4+4,2);
                   write('COMPUTER MADE ITS 1ST PREDICTION.');
                   delay(1500);

                        tmp:=' ';
                        for a:=1 to boardSize do //hafızada ilk tahminle aynı sembolün olup olmadığının kontrolü
                        begin
                             for b:=1 to boardSize do
                             begin
                                  if ((memo[a][b]=playGround[i][j]) AND ((a<>i) OR (b<>j))) then
                                  begin
                                  tmp:=memo[a][b];
                                  k:=a;
                                  l:=b;
                                  end;
                             end;
                        end;

                        if (tmp=' ') then  //eğer bulunamadıysa random tahmin
                        begin
                             repeat
                             flag:=true;
                             k:=random(boardSize)+1;
                             l:=random(boardSize)+1;
                                                    if (m>1) then begin for n:=1 to m-1 do begin if ((10*k+l)=done[n]) then flag:=false; end; end;
                                                    if ((10*k+l)=(10*i+j)) then flag:=false;
                                                    if ((memo[k][l]<>' ') AND (playGround[i][j]<>memo[k][l])) then flag:=false;
                                                    //yapılan random tahmin yanlış olduğu zaten hafızada biliniyorsa random tahmin tekrarlanır
                             until flag;
                        end;

                   gotoxy(l*4-1,k*3);
                   write(playGround[k][l]);

                        if (playGround[i][j]=playGround[k][l]) then
                        begin
                        flagg:=false;
                        computer:=computer+1;
                        done[m]:=10*i+j; done[m+1]:=10*k+l; m:=m+2;
                        memo[i][j]:=' ';
                        memo[k][l]:=' ';
                        gotoxy(boardSize*4+4,2);
                        write('COMPUTER FOUND A COUPLE!         ');
                        gotoxy(boardSize*4+4,5);
                        write('Computer: ',computer);
                        delay(4000);
                        gotoxy(j*4-1,i*3); write(' ');
                        gotoxy(l*4-1,k*3); write(' ');
                        end else begin
                        x:=x+1;
                               if (((level=1) AND (x mod 4=1)) OR ((level=2) AND ((x mod 4=1) OR (x mod 4=2))) OR ((level=3) AND (x mod 4<>0)) OR (level=4)) then
                               memo[i][j]:=playGround[i][j];
                        x:=x+1;
                               if (((level=1) AND (x mod 4=1)) OR ((level=2) AND ((x mod 4=1) OR (x mod 4=2))) OR ((level=3) AND (x mod 4<>0)) OR (level=4)) then
                               memo[i][j]:=playGround[i][j];
                        flagg:=true;
                        gotoxy(boardSize*4+4,2);
                        write('COMPUTER COULD NOT FIND A COUPLE.');
                        delay(4000);
                        gotoxy(boardSize*4+4,2);
                        write('YOUR TURN                        ');
                        gotoxy(j*4-1,i*3); write('*');
                        gotoxy(l*4-1,k*3); write('*');
                        end;

                   end else flagg:=true;
                   if (m>boardSize*boardSize) then
                   turn:=0;

             until flagg;

             if (turn>0) then begin //turn değerinin her elden sonra azaltılması. eğer tablonun bitiminden turn 0landıysa azaltma yapılmıyor.
                   turn:=turn-1;
                   gotoxy(boardSize*4+4,7);
                   write('                    ');
                   gotoxy(boardSize*4+4,7);
                   write('Turns left: ');
                   if (turn<4) then textcolor(12);
                   write(turn); textcolor(15) end;

    until turn=0;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------

//Oyunun sonunda tablonun gösterilmesi, kazananların ilan edilmesi
clrscr;
write(' ');
        for j:=1 to boardSize do
        begin write('___ ');
        end;
writeln;

        for i:=1 to boardSize do
        begin

        write('|');
           for j:=1 to boardsize do
           begin
           write('   |');
           end;
        writeln;

        write('|');
           for j:=1 to boardsize do
           begin
           write(' ',playGround[i][j],' |');
           end;
        writeln;

        write('|');
           for j:=1 to boardsize do
           begin
           write('___|');
           end;
        writeln;
        end;

gotoxy(boardSize*4+4,4);
write('Player: ', player);
gotoxy(boardSize*4+4,5);
write('Computer: ',computer);

gotoxy(boardSize*4+4,7);
write('You played on '); //oynanan levelın gösterilmesi
if (level=1) then begin textcolor(10); write('Beginner'); end;
if (level=2) then begin textcolor(2); write('Intermediate'); end;
if (level=3) then begin textcolor(12); write('Advanced'); end;
if (level=4) then begin textcolor(4); write('Professional'); end;

      if (player>computer) then begin
         for i:=1 to 10 do begin
         gotoxy(boardSize*4+4,2);
         if (i mod 2 = 1) then textcolor(10) else textcolor(2);
         write('GAME OVER, YOU WON!');
         delay(750); end; end
      else if (player=computer) then begin
         for i:=1 to 10 do begin
         gotoxy(boardSize*4+4,2);
         if (i mod 2 = 1) then textcolor(15) else textcolor(7);
         write('GAME OVER, DRAW.');
         delay(750); end; end
      else if (computer>player) then begin
         for i:=1 to 10 do begin
         gotoxy(boardSize*4+4,2);
         if (i mod 2 = 1) then textcolor(12) else textcolor(4);
         write('GAME OVER, YOU LOST.');
         delay(750); end; end;

textcolor(15);
                        repeat
                        gotoxy(1,boardSize*3+4);
                        writeln('Replay?(1/0)');
                        readln(i);
                        until ((i=0) OR (i=1));

          if (i=1) then
          goto start;

end.
