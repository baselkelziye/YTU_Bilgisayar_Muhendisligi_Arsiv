using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.Collections;
namespace YZSudokuSolver
{
    class Olustur : IComparable
    {
        Form1 f;
        Random rnd = new Random();
        public int[,] tempMatrix = new int[9, 9]; //kullanıcıdan aldıgımız matrix
        public int[,] sudokuMatrix = new int[9, 9]; // işlem yaptıgımız matrix
        public int[] array = new int[10];
        public float uygunlukSonuc = 0.0f;
        /*
         *  her tahta üretilince çalışacak olan fonksiyon
         *  içerisinde tempMatrix'inde bulunan sayıları kontrol edip boş olan yerlere
         *  random sayılar üretip yazacak ve bu sudokuMatrix'i oluşturacak
         */
        public Olustur(Form1 f)
        {
            this.f = f;
            setTempMatrix(f);

            for (int satir = 0; satir < 9; satir++)
            {
                for (int sutun = 0; sutun < 9; sutun++)
                {
                    if (tempMatrix[satir, sutun] != 0)
                        array[tempMatrix[satir, sutun]] = 1;
                }

                for (int sutun = 0; sutun < 9; sutun++)
                {
                    if (tempMatrix[satir, sutun] == 0)
                    {
                        bool don = true;
                        while (don)
                        {
                            int a = rnd.Next(1, 10);

                            if (array[a] == 0)
                            {
                                sudokuMatrix[satir, sutun] = a;
                                array[a] = 1;
                                don = false;
                            }
                        }
                    }
                    else
                    {
                        sudokuMatrix[satir, sutun] = tempMatrix[satir, sutun];
                    }
                }
                Array.Clear(array, 0, array.Length);
            }

        }
        /*
         * Bu method da genler arası caprazlama yapıyoruz.Bu caprazlama sonucunda olusturdugumuz
         * 2tane genden rasgele birini seçiyoruz
         * **/
        public Olustur caprazla(Olustur o)
        {
            Olustur olustur1 = new Olustur(f);
            Olustur olustur2 = new Olustur(f);
            Olustur caprazlamaOlustur = o;
            int degisimYeri;
    
            //burada satirlar arası caprazlama yapıyoruz
            if (rnd.Next(2) == 1)
            {
                for (int j = 0; j < 9; j++)
                {
                    degisimYeri = rnd.Next(8) + 1;
                    for (int k = 0; k < degisimYeri; k++)
                    {
                        olustur1.sudokuMatrix[k, j] = caprazlamaOlustur.sudokuMatrix[k, j];
                        olustur2.sudokuMatrix[k, j] = sudokuMatrix[k, j];
                    }

                    for (int k = degisimYeri; k < 9; k++)
                    {
                        olustur2.sudokuMatrix[k, j] = caprazlamaOlustur.sudokuMatrix[k, j];
                        olustur1.sudokuMatrix[k, j] = sudokuMatrix[k, j];
                    }
                }
            }

            // burada sutunlar arası caprazlama yapıyoruz
       
            else
            {
                for (int j = 0; j < 9; j++)
                {
                    degisimYeri = rnd.Next(8) + 1;
                    for (int k = 0; k < degisimYeri; k++)
                    {
                        olustur1.sudokuMatrix[j, k] = caprazlamaOlustur.sudokuMatrix[j, k];
                        olustur2.sudokuMatrix[j, k] = sudokuMatrix[j, k];
                    }

                    for (int k = degisimYeri; k < 9; k++)
                    {
                        olustur2.sudokuMatrix[j, k] = caprazlamaOlustur.sudokuMatrix[j, k];
                        olustur1.sudokuMatrix[j, k] = sudokuMatrix[j, k];
                    }
                }
            }

            // olustur1 veya olustur2 den herhangi biri döndürülüyor.
         
            if (rnd.Next(2) == 1)
            {
                return olustur1;
            }
            else
            {
                return olustur2;
            }
            
        }

        //Burada bir gene ait satir,sutun ve kare alanlarının uygunluk degerlerini hesaplayıp
        //o gene ait genel bir uygunluk degeri buluyoruz
        public float hesapla()
        {
           
            Hashtable SatirTablo = new Hashtable();
            Hashtable SutunTablo = new Hashtable();
            Hashtable KareTablo = new Hashtable();

            float sutunUygunluk = 0;
            float satirUygunluk = 0;
            float kareUygunluk = 0;

            //burada her sutuna bakarak o sutunun uygunluk degerini hesaplayıp daha sonra tum sutunların 
            //uygunluk degerlerini toplarak o gene ait sutunların uygunluk degerlerini hesaplıyoruz
            for (int i = 0; i < 9; i++)
            {
                 
                SutunTablo.Clear();
                for (int j = 0; j < 9; j++)
                {
                    // Burada eger sudokuMatrisinin ilgili degeri null ise ona default olarak 
                    //0 atıyoruz
                    if (SutunTablo[sudokuMatrix[i, j]] == null)
                    {
                        SutunTablo[sudokuMatrix[i, j]] = 0;
                    }

                    SutunTablo[sudokuMatrix[i, j]] = ((int)SutunTablo[sudokuMatrix[i, j]]) + 1;
                }

                //burada sutuna ait uygunluk degerini buluyoruz
                sutunUygunluk += (float)(1.0f / (10 - SutunTablo.Count)) / 9.0f;
            }

            // bu kısım ise satirlar için uygunluk degerini hesaplıyor
            for (int i = 0; i < 9; i++)
            {
               
                SatirTablo.Clear();
                for (int j = 0; j < 9; j++)
                {
                    
                    if (SatirTablo[sudokuMatrix[j, i]] == null)
                    {
                        SatirTablo[sudokuMatrix[j, i]] = 0;
                    }

                    SatirTablo[sudokuMatrix[j, i]] = ((int)SatirTablo[sudokuMatrix[j, i]]) + 1;
                }

               
                satirUygunluk += (float)(1.0f / (10 - SatirTablo.Count)) / 9.0f;
            }

            // Bu kısım ise kareler için uygunluk degerini hesaplıyor
            for (int l = 0; l < 3; l++)
            {
                for (int k = 0; k < 3; k++)
                {
                    
                    KareTablo.Clear();
                    for (int i = 0; i < 3; i++)
                    {
                        for (int j = 0; j < 3; j++)
                        {

                          
                            if (KareTablo[sudokuMatrix[i + k * 3, j + l * 3]] == null)
                            {
                                KareTablo[sudokuMatrix[i + k * 3, j + l * 3]] = 0;
                            }
 
                            KareTablo[sudokuMatrix[i + k * 3, j + l * 3]] = ((int)KareTablo[sudokuMatrix[i + k * 3, j + l * 3]]) + 1;
                        }
                    }

                    kareUygunluk += (float)(1.0f / (10 - KareTablo.Count)) / 9.0f;
                }

            }

            // sonuc olarak ise bu 3 alanın uygunluk degerlerini carparak o gene ait genel uygunluk degerini
            //buluyoruz
           return uygunlukSonuc = sutunUygunluk * satirUygunluk * kareUygunluk;
               
        }
        /*
         * 
         * Burada mutasyon işlemlerini olasılıksal olarak gerçekleştiriyoruz
         * 
         * **/
        public void mutasyon()
        {
            int m1 = rnd.Next(0, 9);
            int m2 = rnd.Next(0, 9);
            int m3 = rnd.Next(0, 9);
            int tmp;
            if (rnd.Next(2) == 0)
            {
                if (tempMatrix[m1, m2] == 0)
                {
                    sudokuMatrix[m1, m2] = m3 + 1;
                }

            }
            else
            {
                tmp = 0;
                if (rnd.Next(2) == 0)
                {
                    if (tempMatrix[m1, m2] == 0 && tempMatrix[m3, m2] == 0)
                    {
                        tmp = sudokuMatrix[m1, m2];
                        sudokuMatrix[m1, m2] = sudokuMatrix[m3, m2];
                        sudokuMatrix[m3, m2] = tmp;
                    }

                }
                else
                {
                    if (rnd.Next(2) == 0)
                    {
                        if (tempMatrix[m2, m1] == 0 && tempMatrix[m2, m3] == 0)
                        {
                            tmp = sudokuMatrix[m2, m1];
                            sudokuMatrix[m2, m1] = sudokuMatrix[m2, m3];
                            sudokuMatrix[m2, m3] = tmp;
                        }

                    }

                }

            }

        }
        /*
         *Form1 deki Başlangıç tablasunu alan fonksiyon
         */
        public void setTempMatrix(Form1 f)
        {
            this.f = f;
            Array.Clear(array, 0, array.Length);
            this.tempMatrix = f.tempMatrix;
        }
        public int CompareTo(object obj)
        {
            Olustur gen1 = this;
            Olustur gen2 = (Olustur)obj;
            return Math.Sign(gen2.uygunlukSonuc - gen1.uygunlukSonuc);
        }

    }
}
