## Veri Yapıları ve Algoritmalar Proje Ödevi
## Bilimsel Hazırlık Öğrencisi
## Önder Görmez
## 21501035

### [Video Linki](https://youtu.be/rB_eiapGdTk)

[![Youtube Link](https://img.youtube.com/vi/rB_eiapGdTk/maxresdefault.jpg)](https://www.youtube.com/watch?v=rB_eiapGdTk)

# Kısaca Detaylar

* Projeyi **Linux'ta** gerçekleştirdim. **Windows** bilgisayarda **test edemedim**.
* Fakat Windows'ta **Cygwin** ile sorunsuz çalışacağını düşünüyorum.
* **Meson Build System** ve C/C++ dilleri için **ninja backend**'ini kullandım.
* Labirenti **dosyadan** okuyoruz.
* Komşuları gezerken West/**Batı** --> East/**Doğu** --> North/**Kuzey** --> South/**Güney** sıralamasına göre geziyoruz.
* Start index ve finish indexleri tutuyoruz.
* Elmalar boşluk sayısının onda biri olacak şekilde rastgele yerleştiriliyor.
* Eğer başlangıç noktasından çıkış noktasına gidecek bir yol yoksa bu bilgi tespit ederek ekrana yazdırılıyor.
* Kenar hücrelerdeki komşuluk tanımını (N+1) yerine daha farklı yaptım. Boşlukları ve boşlukların çevresindeki komşularını tutarak sonuca ilerliyoruz.
* 4 farklı labirentte test ettim. Hepsinde doğru çalıştığını gördüm.
* Ödev 2'de yaptığım stack modülünü kullanarak labirent içerisinde gezintiyi gerçekleştirdim. Duvarla karşılaşıldığı zaman geriye sararken stack i kullanıyorum.

# Labirentler

## maze4.txt

```
+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
|        |        |********************************************|
+  +--+  +  +--+--+**+--+--+--+--+--+--+--+--+--+  +--+--+--+**+
|     |     |********|     |     |**************| o   |******* |
+--+  +  +--+**+--+--+  +  +  +  +**+--+--+--+**+--+  +**+--+--+
|     |  |*****|        | o   |  | ****   |o |**|   o | ****|o |
+  +--+  +**+--+oo+--+--+--+--+--+--+**+--+--+**+--+--+--+**+--+
|  |     |**|o |  |              |  |**|*****|********|  |*****|
+  +--+--+**+--+  +  +--+--+--+  +  +**+**+**+--+  +**+--+--+**+
|        |**|o    |     |     |  |  |*****|*****|  |********** |
+  +--+  +**+  +--+--+  +--+  +  +--+--+--+--+**+  +--+--+--+--+
|  |     |**|        |     |  |              |**|           |  |
+  +  +--+**+--+--+--+--+  + o+--+--+--+--+  +**+--+  +--+  +--+
|  |  | ****               |              |  |*****|  | o|   o |
+  +  +**+--+--+--+--+--+--+--+  +--+--+  +- +--+**+o +  +--+  +
|  |   **** |     |        oo o      o |  |     |**|     |     |
+  +--+--+**+  +  + o+--+o +--+--+ o+--+--+  +  +**+--+  +  +--+
|  | *******|  |  |    o|o       |  |        |  |**|o |  |     |
+  +**+--+--+  +  +--+  +  +--+--+--+  +--+--+--+**+  +  +--+  +
|  |**|    o   |     |  |     |     |           |**|     |  |  |
+  +**+  +--+--+--+--+  +--+  +  +--+--+--+--+  +**+--+--+--+  +
|  |**  o    o  o  o       |o |     |  |  |     |********|  |  |
+  +**+--+--+--+--+--+--+--+--+--+  +--+--+  +--+--+--+**+--+ o+
|  |******* |     |  |        |  |  |  |              |**|  o  |
+--+--+--+**+  +  +o +  +--+  +--+  +--+  +--+  +--+--+**+  +--+
|     | ****|  |  |  |  |  |        |  |  |     |     |**|  o  |
+  +--+**+--+  +  +o +  +--+--+--+--+--+  +  +--+  +  +**+--+--+
|      ****o|  |  |  |                 |  |  |    o|o |********|
+--+--+--+**+--+  +  +--+--+--+--+--+  +  +  +--+--+--+--+--+**+
|b**********      |o    oo          |     |              |   *c|
+-----+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+

Total points: 610
Eaten Apple Counts: 65/105
Visited Room Counts: 674/1057
Dead End Count: 8
Congratulations. Exited from maze :)
onder@debian-onder:~/Repos/BLM2512_Data_Structures_and_Algorithms/build-dir$
```

## maze6.txt

```
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|o    |     |                       o     |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|   | o |     | o |   |         |   |    o|
+-+ + +-+ +-+-+ + + + +o+-+-+-+ +-+ + +-+-+
|   | |   |   o |   | |     | | | o |o  | |
+ +-+ + +-+ +-+-+-+-+-+-+ +-+-+ +-+-+-+ +-+
| |   | | | |         |o| |o  |o    | |   |
+ +-+-+ +-+ + +-+-+-+ +o+ +o+ +-+ + +-+-+ +
|     | |   |   |   | |o|   | o | | o o   |
+ +-+ + + +-+-+ +-+ + +-+-+-+-+ + +-+-+-+-+
| |   | |     |   | |         | |       | |
+ + +-+ +-+-+-+-+ + +-+-+-+-+ + +-+ +-+ +-+
| | |             |         | |   |o| |   |
+ + + +-+-+-+-+-+-+-+ +-+-+ + +-+ + + +-+ +
| |     |   |             | |   | |   |o  |
+ +-+-+ + + + +-+ +-+-+ +-+-+ + + +-+ + +-+
| |     | | |   |     | |     | | | | |   |
+ + +-+-+ + +-+ + +-+-+-+ +-+-+-+ + + +-+o+
| | |     |   | |   |   |       | |   | | |
+ + + +-+-+-+-+ +-+ + +-+-+-+-+ + +-+-+-+ +
| |               | |   | | |   |     | | |
+ + +-+-+-+-+-+-+-+-+-+ +-+-+ +-+-+-+ +-+ +
| |     |   | |     | | |o|         | |   |
+-+-+-+ + + +o+ +-+ +-+ +-+ +-+ +-+-+o+ +-+
|   |   | | | | | |     | | |   |  o| |o o|
+ +-+ +-+ + + + +-+-+-+-+-+ + +-+o+ + +-+-+
|       | | |o|           | | |   | |     |
+-+-+-+ +-+ + +-+-+-+-+-+ + + +-+-+-+-+-+ +
|b          |           |   |         |  c|
+-+-+-+-+-+-+---+-+-+-+-+-+-+-+-+-+-+-+-+-+

Total points: 225
Eaten Apple Counts: 31/60
Visited Room Counts: 337/606
Dead End Count: 17
Got stuck in maze. There is no exit :(
onder@debian-onder:~/Repos/BLM2512_Data_Structures_and_Algorithms/build-dir$
```

## maze5.txt

```
+-+-+-+-+
|***|***|
+*+*+*+*+
|b|***|c|
+-+-+-+-+

Total points: 10
Eaten Apple Counts: 1/1
Visited Room Counts: 14/15
Dead End Count: 0
Congratulations. Exited from maze :)
onder@debian-onder:~/Repos/BLM2512_Data_Structures_and_Algorithms/build-dir$
```

# Kaynaklar
[Ödev Linki](https://online.yildiz.edu.tr/upload/ytu/Evaluation/756b658c-392e-43ea-9972-75cfa48a5abc.pdf)  
[Abdul Bari - Graph Traversals - BFS & DFS](https://www.youtube.com/watch?v=pcKY4hjDrxk)
