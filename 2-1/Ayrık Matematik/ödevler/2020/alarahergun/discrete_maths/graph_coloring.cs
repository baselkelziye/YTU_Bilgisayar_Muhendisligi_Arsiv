using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;
using System.Threading;
using System.CodeDom.Compiler;

namespace proje_odevi
{
    class Program
    {
        public static bool renkKontrol;
        static void Main(string[] args)
        {
            int i, j, k, h;
            List<int> kullanilanRenkler = new List<int>();
            string file = "Dersler.txt";
            List<int> renkListesi = new List<int>();

            StreamReader sr = new StreamReader(file);
            string unedited = sr.ReadToEnd();
            string[] dersler = Regex.Split(unedited, @"\W+");

            for (i = 0; i < dersler.Length; i++) //bütün derslerin boyanmamış olarak atandığı dizi açıldı
            {
                renkListesi.Add(-1);
            }

            //kaç ders olduğu öğrenildi, ona uygun matris açılacak
            int[,] matrix = new int[dersler.Length, dersler.Length];
            List<List<string>> studentList = new List<List<string>>(); //öğrenci numaralarının kaydedileceği 2 boyutlu dinamik liste

            //her ders kodunun okunup bir listeye alınan öğrencilerin kaydedilmesi

            for (i = 0; i < dersler.Length; i++) //her öğrenci numarası 2 boyutlu listeye kaydedilecek
            {
                string fileYeni = dersler[i] + ".txt";
                StreamReader sr_2 = new StreamReader(fileYeni);
                string unedited_2 = sr_2.ReadToEnd();
                string[] kodluDers = Regex.Split(unedited_2, @"\W+");

                studentList.Add(new List<string>());
                studentList[i].AddRange(kodluDers);
                sr_2.Close();
            }

            for (i = 0; i < dersler.Length; i++) //2 boyutlu listeye göre komşuluk matrisi oluşturma
            {
                List<string> liste1 = studentList[i];
                for (j = 0; j < dersler.Length; j++)
                {
                    List<string> liste2 = studentList[j];
                    for (k = 0; k < liste2.Count; k++)
                    {
                        if (liste1.Contains(liste2[k]) && i != j)
                        {
                            matrix[i, j] = 1;
                            matrix[j, i] = 1;
                            if (renkListesi[i] == -1)
                            {
                                Renklendir(i, dersler.Length, matrix, renkListesi, 1);
                            }
                        }
                    }
                }
            }

            for (h = 0; h < renkListesi.Count; h++) //hiçbir komşusu olmayan ayrık bir node varsa hedef renkten veriyoruz 
            {
                if (renkListesi[h] == -1)
                {
                    renkListesi[h] = 1;
                }
            }

            //matris yazdırma
            for (i = 0; i < dersler.Length; i++)
            {
                for (j = 0; j < dersler.Length; j++)
                {
                    Console.Write(matrix[i, j] + " ");
                }
                Console.WriteLine("");
            }

            int boyamaMax = renkListesi[0]; //renk ölçümü 

            for (i = 1; i < renkListesi.Count; i++)
            {
                if (renkListesi[i] > boyamaMax)
                {
                    boyamaMax = renkListesi[i];
                }
            }

            Console.WriteLine("\nBu listelerde yapılabilecek olan boyama sayısı : " + boyamaMax);
            Console.WriteLine("\nBu listelerde yapılması gereken minimum oturum sayısı : " + boyamaMax);

            for (i = 0; i < dersler.Length; i++)
            {
                Console.WriteLine(dersler[i] + " --> " + renkListesi[i]);
            }

            sr.Close();
            Console.ReadLine();
        }

        public static bool Renklendir(int i, int dersSayisi, int[,] matris, List<int> renkListesi, int hedefRenk)
        {
            renkKontrol = true;

            for (int j = 0; j < dersSayisi; j++)
            {
                if (matris[i, j] == 1 && i != j) 
                {
                    if (renkListesi[i] == -1) 
                    {
                        if (hedefRenk == renkListesi[j] && renkListesi[j] != -1) 
                            renkKontrol = false;
                    }
                }
            }
            if (renkKontrol)
            {
                renkListesi[i] = hedefRenk;
                return true;
            }
            else
                return Renklendir(i, dersSayisi, matris, renkListesi, hedefRenk + 1); 
        }
    }
}


