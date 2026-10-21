using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace YZprj
{
    public class Genome: IComparable
    {
        Random rand = new Random();
        public int[,] intArray = new int[9,9];
        public int[,] staticValues = new int[9, 9] 
                                                   /*{{0,9,0,3,6,0,8,0,0},
                                                    {0,0,5,0,0,0,7,0,0},
                                                    {0,0,0,0,0,0,4,0,3},
                                                    {0,0,0,0,0,0,7,0,0},
                                                    {0,0,0,0,0,0,0,9,1},
                                                    {7,4,2,0,0,9,6,8,5},
                                                    {4,0,8,2,3,6,0,0,0},
                                                    {1,7,3,9,5,0,6,0,0},
                                                   {9,0,6,0,0,0,0,3,0}}; */

{{8,0,0,0,0,0,0,0,0},
{0,0,3,6,0,0,0,0,0},
{0,7,0,0,9,0,2,0,0},
{0,5,0,0,0,7,0,0,0},
{0,0,0,0,4,5,7,0,0},
{0,0,0,1,0,0,0,3,0},
{0,0,1,0,0,0,0,6,8},
{0,0,8,5,0,0,0,1,0},
{0,9,0,0,0,0,4,0,0}};
                                                    
/*
{{0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0}};*/

/*{{0,0,0,0,0,0,0,0,8},
{3,4,7,0,0,1,0,0,0},
{2,0,0,0,3,7,4,0,0},
{0,9,0,0,0,0,8,0,0},
{8,0,0,0,9,0,0,0,5},
{0,0,5,0,0,0,0,2,0},
{0,0,6,8,7,0,0,0,4},
{0,0,0,6,0,0,3,7,2},
{1,0,0,0,0,0,0,0,0}};*/


        int[] sayiDizisi = new int[10];
        int crossOverNoktası;
        public float fitness = 0.0f;
        
        // get intArray[i,j]
        public int getIntArray(int satir, int sutun)
        {
            return this.intArray[satir,sutun];
        }

        //constructor func. 
        //her satır 1 - 9 arasında random değer atılıyor (1 kere )
        public Genome()
        {          
            for (int satir = 0; satir < 9; satir++)
			{
                for (int sutun = 0; sutun < 9; sutun++)
                {
                    if (staticValues[satir, sutun] != 0)             
                        sayiDizisi[staticValues[satir, sutun]] = 1;                 
                }

				for (int sutun = 0; sutun < 9; sutun++)
				{              
                    if (staticValues[satir, sutun] == 0)
                    {
                        bool don = true;
                        while (don)
                        {
                            int a = rand.Next(1, 10);
                            
                            if (sayiDizisi[a] == 0)
                            {
                                intArray[satir, sutun] = a;
                                sayiDizisi[a] = 1;
                                don = false;
                            }
                        }
                    }
                    else
                    {
                        intArray[satir, sutun] = staticValues[satir, sutun];
                    }
				}
                Array.Clear(sayiDizisi, 0, sayiDizisi.Length);
			}
        }

        //  Fitness (uygunluk) hesapla (intArray üzerinden hesaplama)
        public float FitnessFunction()
        {
            //fitness hesabı degiskenleri (satır, sutun, grid için)
            Hashtable RowMap    = new Hashtable();
            Hashtable ColumnMap = new Hashtable();
            Hashtable GridMap   = new Hashtable();

			float fitnessColumns = 0;
			float fitnessRows    = 0;
			float fitnessSquares = 0;

			// 1- her sutuna bak
			for (int i = 0; i < 9; i++)
			{
                //hastable sıfırla
				ColumnMap.Clear();
				for (int j = 0; j < 9; j++)
				{
					// değerlerin unique'liğine bak
					if (ColumnMap[intArray[i,j]] == null)
					{
						ColumnMap[intArray[i,j]] = 0;
					}

					 ColumnMap[intArray[i,j]] = ((int)ColumnMap[intArray[i,j]]) + 1;
				}

				//fitness ColoumnMap = [0,1] arasında
				fitnessColumns += (float)(1.0f/ (10-ColumnMap.Count))/9.0f;
			}

			// 2- her satıra bak
			for (int i = 0; i < 9; i++)
			{
                //hastable sıfırla
				RowMap.Clear();
				for (int j = 0; j < 9; j++)
				{
					// eşsizliğe bak
					if (RowMap[intArray[j,i]] == null)
					{
						RowMap[intArray[j,i]] = 0;
					}

					RowMap[intArray[j,i]] = ((int)RowMap[intArray[j,i]]) + 1;
				}

                //fitness RowMap = [0,1] arasında
				fitnessRows += (float)(1.0f/ (10-RowMap.Count))/9.0f;
			}

			// 3- grid hesapla
			for (int l = 0; l < 3; l++)
			{
				for (int k = 0; k < 3; k++)
				{
                    //gridMap sıfırla
                    GridMap.Clear();
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{

							// esşizliğe bak
                            if (GridMap[intArray[i + k * 3, j + l * 3]] == null)
							{
                                GridMap[intArray[i + k * 3, j + l * 3]] = 0;
							}

                            // fitness GridMap = [0,1] arasında
                            GridMap[intArray[i + k * 3, j + l * 3]] = ((int)GridMap[intArray[i + k * 3, j + l * 3]]) + 1;
						}
					}

                    fitnessSquares += (float)(1.0f / (10 - GridMap.Count)) / 9.0f;
				}

			}

            // hepsinin çarpımı tablonun uygunluğunu verir.
			fitness = fitnessColumns * fitnessRows * fitnessSquares;
			return fitness;
		}

        // Mutasyon yap (intArray random Değişir)
        public void Mutation()
        {
            int MutationDeger1 = rand.Next(0,9);
            int MutationDeger2 = rand.Next(0,9);
            int MutationDeger3 = rand.Next(0,9);
            
            if (rand.Next(2) == 0)
            {
                //static değerlere dokunmamak koşulu ile
                if (staticValues[MutationDeger1, MutationDeger2] == 0)
                {
                    intArray[MutationDeger1, MutationDeger2] = MutationDeger3+1;
                }
            }
            else
            {
                int temp = 0;
                if (rand.Next(2) == 0)
                {
                    //static değerlere dokunmamak koşulu ile
                    if (staticValues[MutationDeger1, MutationDeger2] == 0 && 
                        staticValues[MutationDeger3, MutationDeger2] == 0)
                    {
                        // 2 satırın değerini birbiriyle değiştir.
                        temp = intArray[MutationDeger1, MutationDeger2];
                        intArray[MutationDeger1, MutationDeger2] = intArray[MutationDeger3, MutationDeger2];
                        intArray[MutationDeger3, MutationDeger2] = temp;
                    }
                }
                else
                {
                    //static değerlere dokunmamak koşulu ile
                    if (staticValues[MutationDeger2, MutationDeger1] == 0 &&
                        staticValues[MutationDeger2, MutationDeger3] == 0)
                    {
                        // 2 sutunun degerini birbiri ile değiştir.
                        temp = intArray[MutationDeger2, MutationDeger1];
                        intArray[MutationDeger2, MutationDeger1] = intArray[MutationDeger2, MutationDeger3];
                        intArray[MutationDeger2, MutationDeger3] = temp;
                    }
                }
            }
        }
        
        // Crossover (parça değişimi yap)
        public Genome Crossover(Genome g)
        {
            Genome aGene1 = new Genome();
            Genome aGene2 = new Genome();
            Genome CrossingGene = g;

            // bu olasılıkta
            // agene1 ve agene2 child genleri "g" ve "intArray" degerleri ile
            // crossOverNoktasına göre oluşturuluyor (satırlar arası crossover)
            if (rand.Next(2) == 1)
            {
                for (int j = 0; j < 9; j++)
                {
                    crossOverNoktası = rand.Next(8) + 1;
                    for (int k = 0; k < crossOverNoktası; k++)
                    {                        
                        aGene1.intArray[k, j] = CrossingGene.intArray[k, j];
                        aGene2.intArray[k, j] = intArray[k, j];
                    }

                    for (int k = crossOverNoktası; k < 9; k++)
                    {
                        aGene2.intArray[k, j] = CrossingGene.intArray[k, j];
                        aGene1.intArray[k, j] = intArray[k, j];
                    }
                }
            }

            // bu olasılıkta
            // agene1 ve agene2 child genleri "g" ve "intArray" degerleri ile
            // crossOverNoktasına göre oluşturuluyor (sutunlar arası crossover)
            else
            {
                for (int j = 0; j < 9; j++)
                {
                    crossOverNoktası = rand.Next(8) + 1;
                    for (int k = 0; k < crossOverNoktası; k++)
                    {
                        aGene1.intArray[j, k] = CrossingGene.intArray[j, k];
                        aGene2.intArray[j, k] = intArray[j, k];
                    }

                    for (int k = crossOverNoktası; k < 9; k++)
                    {
                        aGene2.intArray[j, k] = CrossingGene.intArray[j, k];
                        aGene1.intArray[j, k] = intArray[j, k];
                    }
                }
            }

            // agene1 veya agene2 den herhangi biri döndürülüyor.
            Genome aGene = null;
            if (rand.Next(2) == 1)
            {
                aGene = aGene1;
            }
            else
            {
                aGene = aGene2;
            }
            return aGene;
        }

        // gFitness degerinin altında kalanları öldürsün mü?
        public bool yokEt(float gFitness)
        {
            if (fitness <= (int)(gFitness * 100.0f))
            {
                return true;
            }
            return false;
        }

        // çoğalsın mı? (rFitness değerinin sayısı belirler)
        public bool cogalt(float rFitness)
        {
            if (rand.Next(100) >= (int)(rFitness * 100.0f))
            {
                return true;
            }
            return false;
        }

        // IComparable özelliği olarak nesneler karşılaştırılabilir.
        // fitness değerlerine göre genleri karşılaştır.
        public int CompareTo(object obj)
        {
            Genome gen1 = this;
            Genome gen2 = (Genome)obj;
            return Math.Sign(gen2.fitness - gen1.fitness);
        }
    }
}
