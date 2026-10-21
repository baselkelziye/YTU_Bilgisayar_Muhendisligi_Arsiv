using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace YZprj
{
    public class Population
    {
        // kullanılan değişkenler
        Random rand = new Random();
        protected int Generation                 = 1;
        protected int baslangicPopulasyonu = 1000;
        protected int guncelPopulasyon           = 1000;
        protected int populasyonLimiti     = 50;
       //protected bool Best                      = true;
        protected  float mutasyonOrani      = 0.33f;
        protected  float oldurmeUygunlugu   = -1.00f;
        protected  float cogaltmaUygunlugu  = 0.00f;

        protected ArrayList genomes = new ArrayList();
        protected ArrayList genomeCogalticilar = new ArrayList();
        protected ArrayList genomeSonuclar = new ArrayList();
        protected ArrayList genomeAilesi = new ArrayList();

        public void set_mutasyonOranı(float deger)
        {
            this.mutasyonOrani = deger;
        }

        public void set_baslangicPopulasyonu(int deger)
        {
            this.baslangicPopulasyonu = deger;
        }

        public void set_populasyonLimiti(int deger)
        {
            this.populasyonLimiti = deger;
        }

        //constructor func. 
        //baslangıç popülasyonu oluşturuldu.
        public Population()
        {
            //baslangıç popülasyonu kadar genome oluşturuldu.
            for (int i = 0; i < baslangicPopulasyonu; i++)
            {
                Genome gen = new Genome();
                gen.FitnessFunction();
                genomes.Add(gen);
            }
        }



        //olasılıksal mutasyon oluşturma fonk.
        private void theMutations(Genome gen)
        {
            if (rand.Next(100) < (int)(mutasyonOrani * 100.0))
            {
                gen.Mutation();
            }
        }

        //yeni Jenerasyon yarat
        public void yeniJenerasyon()
        {
            //jenerasyon değişkenini arttır.
            Generation++;

            //kimler ölebilir kontrol et!
            for (int i = 0; i < genomes.Count; i++)
            {
                if (((Genome)genomes[i]).yokEt(oldurmeUygunlugu))
                {   
                    // genomu sil 
                    // i değerini azalt
                    genomes.RemoveAt(i);
                    i--;
                }
            }

            //çoğaltmayı belirle
            genomeCogalticilar.Clear();
            genomeSonuclar.Clear();

            for (int i = 0; i < genomes.Count; i++)
            {
                if (((Genome)genomes[i]).cogalt(cogaltmaUygunlugu))
                {
                    genomeCogalticilar.Add(genomes[i]);
                }
            }

            // genlere crossover yap ve populasyona ekle
            crossoverYap(genomeCogalticilar);

            genomes = (ArrayList)genomeSonuclar.Clone();

            // yeni populasyondaki birkaç gene mutasyon uygula
            for (int i = 0; i < genomes.Count; i++)
            {
                theMutations((Genome)genomes[i]);
            }

            //tüm genomların fitness degerlerini hesapla
            for (int i = 0; i < genomes.Count; i++)
            {
                ((Genome)genomes[i]).FitnessFunction();
            }

            //genomes.Sort();

            //populasyon limitinin üzerindeki tüm genleri sil 
            if (genomes.Count > populasyonLimiti)
            {
                genomes.RemoveRange(populasyonLimiti, genomes.Count - populasyonLimiti);
            }
            guncelPopulasyon = genomes.Count;
        }

        //Crossover Yap
        public void crossoverYap(ArrayList genler)
        {
            ArrayList anneGenler = new ArrayList();
            ArrayList babaGenler = new ArrayList();

            for (int i = 0; i < genler.Count; i++)
            {
                // anne ve babadan birine rastgele gen ekle
                if (rand.Next(100) % 2 > 0)
                {
                    anneGenler.Add(genler[i]);
                }
                else
                {
                    babaGenler.Add(genler[i]);
                }
            }
            // iki array list eşitle
            //anneler babalardan büyükse anneden al babaya ver
            if (anneGenler.Count > babaGenler.Count)
            {
                while (anneGenler.Count > babaGenler.Count)
                {
                    babaGenler.Add(anneGenler[anneGenler.Count - 1]);
                    anneGenler.RemoveAt(anneGenler.Count - 1);
                }
                //eşit olduğundan emin ol
                if (babaGenler.Count > anneGenler.Count)
                {
                    babaGenler.RemoveAt(babaGenler.Count - 1);
                }
            }
            // iki array listti eşitle
            //babalar anneden büyükse babadan al anneye ver
            else
            {
                while (babaGenler.Count > anneGenler.Count)
                {
                    anneGenler.Add(babaGenler[babaGenler.Count - 1]);
                    babaGenler.RemoveAt(babaGenler.Count - 1);
                }
                //eşit olduğundan emin ol
                if (anneGenler.Count > babaGenler.Count)
                {
                    anneGenler.RemoveAt(anneGenler.Count - 1); 
                }
            }

            //Crossover yap ve fitnesslarına göre sırala
            for (int i = 0; i < babaGenler.Count; i++)
            {
                //ailelerden en iyi iki çocuğu seç
                Genome cocukGen1 = ((Genome)babaGenler[i]).Crossover((Genome)anneGenler[i]);
                Genome cocukGen2 = ((Genome)anneGenler[i]).Crossover((Genome)babaGenler[i]);

                genomeAilesi.Clear();
                genomeAilesi.Add(babaGenler[i]);
                genomeAilesi.Add(anneGenler[i]);
                genomeAilesi.Add(cocukGen1);
                genomeAilesi.Add(cocukGen2);
                fitnessHesapla(genomeAilesi);
                genomeAilesi.Sort();

                genomeSonuclar.Add(genomeAilesi[0]);
                genomeSonuclar.Add(genomeAilesi[1]);             
            }
        }

        //fitness hesapla
        public void fitnessHesapla(ArrayList genes)
        {
            foreach (Genome gen in genes)
            {
                gen.FitnessFunction();
            }
        }

        //genomes listesindeki en yüksek fitnesslı genom geri döner;
        public Genome getEnYuksekFitness_genomes()
        {
            genomes.Sort();
            return (Genome)genomes[0];
        }

        public virtual void WriteNextGeneration()
        {
            // just write the top 20
            Console.WriteLine("Generation {0}\n", Generation);
            if (Generation % 1 == 0) // just print every 100 generations
            {
                genomes.Sort();
                for (int i = 0; i < guncelPopulasyon; i++)
                {
                    Console.WriteLine(((Genome)genomes[i]).ToString());
                }
                Console.WriteLine("Hit the enter key to continue...\n");
                Console.ReadLine();
            }
        }
    }
}
