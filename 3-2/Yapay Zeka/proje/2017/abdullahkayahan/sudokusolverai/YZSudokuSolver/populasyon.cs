using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace YZSudokuSolver
{
    class Populasyon
    {
        Form1 f;
        Random rnd = new Random();
        protected int generation;
        protected int baslangicPo;
        protected int gulcelPop;
        protected int limit;
        protected float mutasyonOran;
        protected float oldurmeUygunlugu = -1.00f;
        protected float cogaltmaUygunlugu = 0.00f;

        protected ArrayList genler = new ArrayList();
        protected ArrayList genCogaltici = new ArrayList();
        protected ArrayList genSonuc = new ArrayList();
        protected ArrayList genAilesi = new ArrayList();


        public int deger = 0;

        /*
         Burada başlangıcda belirttigimiz populason sayısı kadar
         * sudoku tahtası oluşturuyoruz.Oluşturulan her bir tahda bir gen olarak ifade edilmiştir.
         
         */
        int p = 0;

        /*
         * burada başlangıc populasyonu kadar gen oluşturutoruz
         * **/
        public Populasyon(Form1 f, int b, int l, float mo)
        {

            this.limit = l;
            this.baslangicPo = b;
            this.mutasyonOran = mo;
            this.f = f;
            for (int i = 0; i < baslangicPo; i++)
            {
                Olustur gen = new Olustur(f);
                gen.hesapla();
                genler.Add(gen);

            }
        }

        //Mutasyon işlemini olasılıksal olarak yapıyoruz
        private void olsıMut(Olustur o)
        {

            if (rnd.Next(100) < (int)(mutasyonOran * 100.0))
            {
                o.mutasyon();
            }
        }

        //Burada yeni jenerasyonlar yaratıyoruz
        public void NewGeneration()
        {
            generation++;
            int i=0;
        
             while(i<genler.Count)
            {
                 //burada en kotu uygunluga sahip olan genleri siliyoruz.
                if (rnd.Next(100) <= Convert.ToInt32(oldurmeUygunlugu * 100.0f))
                {
                    // geni sil 
                    // i değerini azalt
                    genler.RemoveAt(i);
                    i--;
                }
                i++;
            }

            genCogaltici.Clear();
            genSonuc.Clear();

            //burada yeni genler oluşturuyoruz
            for (i = 0; i < genler.Count; i++)
            {
                if (rnd.Next(100) >= Convert.ToInt32(cogaltmaUygunlugu * 100.0f))
                {
                    genCogaltici.Add(genler[i]);
                }

            }


            caprazlamaYap(genCogaltici);
            genler = (ArrayList)genSonuc.Clone();

            //olusan bu genlere mutasyon uyguluyoruz
            for (i = 0; i < genler.Count; i++)
            {
                olsıMut((Olustur)genler[i]);

            }

            //genlerin herbirinin uygunluk degerlerini hesaplıyoruz
            for (i = 0; i < genler.Count; i++)
            {
                ((Olustur)genler[i]).hesapla();

            }

            if (genler.Count > limit)
            {
                genler.RemoveRange(limit, genler.Count - limit);
            }
            gulcelPop = genler.Count;

        }

        //burada genler arası caprazlama yapıyoruz
        public void caprazlamaYap(ArrayList genler)
        {

            ArrayList p1 = new ArrayList();
            ArrayList p2 = new ArrayList();

            //tüm genleri 2 parcaya arıyoruz.Bunun için rasgele urettigimiz sayının 
            //2 ye gore modunu alıp cıkan sonuca gore p1 veya p2 arraylistine atıyoruz
            //Burada rasgele sayının mod2 sini almamızın sebebi çeşitliligi arttırmak
            //Ayrıca burada i nin tek veya çift olmasına görede ayrılabilirdi.Ama o zaman
            //çeşitliiligin az olucagını dusundugumuz random secmeyi tercih ettik.Bunun nedenide
            //işin içine sans faktorunun girmesi gerektigini dusunmemiz
            for (int i = 0; i < genler.Count; i++)
            {
                if (rnd.Next(100) % 2 == 0)
                {
                    p1.Add(genler[i]);
                }
                else
                {
                    p2.Add(genler[i]);
                }
            }

            //burada caprazlama yapabilmemiz için iki ye ayırdıgımız gen gruplarının sayılarının
            //eşit olması gerekiyor
            if (p1.Count > p2.Count)
            {
                while (p1.Count > p2.Count)
                {
                    p2.Add(p1[p1.Count - 1]);
                    p1.RemoveAt(p1.Count - 1);
                }
            }
            else
            {
                while (p2.Count > p1.Count)
                {
                    p1.Add(p2[p2.Count - 1]);
                    p2.RemoveAt(p2.Count - 1);
                }

            }

            int count = 0;
            if (p1.Count > p2.Count)
            {
                count = p2.Count;
            }
            else
            {
                count = p1.Count;
            }

            for (int i = 0; i < count; i++)
            {
                Olustur c1 = (((Olustur)p2[i]).caprazla((Olustur)p1[i]));
                Olustur c2 = (((Olustur)p1[i]).caprazla((Olustur)p2[i]));

                genAilesi.Clear();
                //bu kısımda olusturugumuz genleri genAilesi arraylistine ekleyip
                //daha sonra uygunlugunu hesaplayarak oluşan bu gen ailesindeki
                //en iyi uygunluga sahip ikitanesini alıyoruz
                genAilesi.Add(p2[i]);
                genAilesi.Add(p1[i]);
                genAilesi.Add(c1);
                genAilesi.Add(c2);

                uygunlukHesapla(genAilesi);
                genAilesi.Sort();
                //burada olusan en iyi iki geni alıyoruz
                genSonuc.Add(genAilesi[0]);
                genSonuc.Add(genAilesi[1]);
            }
        }
        //gönderilen dizinin tüm tahtalarının uygunluklarını hesaplıyor
        public void uygunlukHesapla(ArrayList genler)
        {
            foreach (Olustur gen in genler)
            {
                gen.hesapla();
            }
        }

        public Olustur getEnYuksekHesap()
        {
            genSonuc.Sort();

            return ((Olustur)genSonuc[0]);
        }

    }
}