using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GrafOdev
{
    class Program
    {

        static void Main(string[] args)
        {
            int node, edge;
            bool kenarBool = false;
            int[,] matris;
            int[] con = new int[2];
            List<List<int>> liste;

            Console.Write("Düğüm sayısı: ");
            node = Convert.ToInt32(Console.ReadLine());

            Console.Write("\nKenar sayısı (" + (node * (node - 1) / 2) + "'den büyük olamaz):");
            edge = Convert.ToInt32(Console.ReadLine());

            while (!kenarBool)
            {
                if (edge <= (node * (node - 1) / 2))
                {
                    kenarBool = true;
                }
                else
                {
                    Console.Write("\nKenar sayısı (" + (node * (node - 1) / 2) + "'den büyük olamaz):");
                    edge = Convert.ToInt32(Console.ReadLine());
                }
            }
            liste = new List<List<int>>(node);
            matris = new int[node, node];


            for (int i = 0; i < node; i++)
            {
                for (int j = 0; j < node; j++)
                {
                    matris[i, j] = 0;
                }
            }
            for (int i = 0; i < node; i++)
            {
                for (int j = 0; j < node; j++)
                {
                    liste.Add(new List<int>());
                }
            }

            for (int i = 1; i <= edge; i++)
            {
                Console.WriteLine(i + ".ci kenarın bağlantı düğümlerini seçin 0," + (node-1) + " arasında");

                bool kontrol = false;
                bool kontrol2 = true;
                int counter = 0;

                while (!kontrol)
                {
                    con[0] = Convert.ToInt32(Console.ReadLine());
                    con[1] = Convert.ToInt32(Console.ReadLine());

                    if (con[0] <= edge && con[1] <= edge)
                    {
                        kontrol = true;
                    }
                }

                while (counter <= con.Length)
                {
                    foreach (var item in liste[con[1]])
                    {
                        if (item == con[0])
                        {
                            Console.WriteLine("girilen düğümler arasında bağlantı var. tekrar deneyin");
                            con[0] = Convert.ToInt32(Console.ReadLine());
                            con[1] = Convert.ToInt32(Console.ReadLine());
                            counter--;
                        }
                    }
                    counter++;
                }

                if (kontrol2 == true)
                {
                    matris[con[0], con[1]] = 1;
                    matris[con[1], con[0]] = 1;

                    liste[con[0]].Add(con[1]);

                    if (con[1] != con[0])
                    {
                        liste[con[1]].Add(con[0]);
                    }
                    kontrol2 = true;
                }

            }
            Console.WriteLine("Matris\n");
            for (int i = 0; i < node; i++)
            {
                Console.Write(i + ")");
                for (int k = 0; k < node; k++)
                {
                    if (k == node - 1)
                    {
                        Console.WriteLine(matris[i, k] + " ");
                    }
                    else
                    {
                        Console.Write(matris[i, k] + " ");
                    }
                }
            }

            Console.WriteLine("Liste\n");
            for (int i = 0; i < node; i++)
            {
                Console.Write("\n" + i + " --> ");
                foreach (var item in liste[i])
                    Console.Write(item + " ");
            }


            MatrisKontrol(matris, node);

            ListeKontrol(liste, node);


            Console.ReadLine();
        }

        static void MatrisKontrol(int[,] matris, int node)
        {
            List<int>[] benzerlik = new List<int>[node];

            int kontrol = 1;
            for (int i = 0; i < node; i++)
            {
                benzerlik[i] = new List<int>();
                if (i != 0)
                {
                    benzerlik[i].Add(0);
                }
            }
            benzerlik[0].Add(1);

            for (int i = 0; i < node; i++)
            {
                for (int j = 0; j < node; j++)
                {
                    if (matris[i, j] == 1)
                    {
                        if (benzerlik[i].ElementAt(0) == 0 && benzerlik[j].ElementAt(0) == 0)
                        {
                            if (benzerlik[i].ElementAt(0) == 1)
                            {
                                benzerlik[j].Remove(benzerlik[j].ElementAt(0));
                                benzerlik[j].Add(2);
                            }
                            else
                            {
                                benzerlik[j].Remove(benzerlik[j].ElementAt(0));
                                benzerlik[j].Add(1);
                            }
                        }
                        else
                        {
                            if (benzerlik[i].ElementAt(0) == benzerlik[j].ElementAt(0))
                            {
                                kontrol = 0;
                            }
                            if (matris[i, i] == 1)
                            {
                                kontrol = 0;
                            }
                        }
                    }
                }
            }
            if (kontrol == 1)
            {
                Console.WriteLine("\nmatris bipartite");
            }
            else
            {
                Console.WriteLine("\nmatris bipartite değil");
            }
        }
        static void ListeKontrol(List<List<int>> liste, int node)
        {
            List<int>[] benzerlik = new List<int>[node];

            int kontrol = 1;
            for (int i = 0; i < node; i++)
            {
                benzerlik[i] = new List<int>();
                if (i != 0)
                {
                    benzerlik[i].Add(0);
                }
            }
            benzerlik[0].Add(1);


            for (int i = 0; i < node; i++)
            {
                foreach (var item in liste[i])
                {

                    if (benzerlik[i].ElementAt(0) == 0 && benzerlik[item].ElementAt(0) == 0)
                    {
                        if (benzerlik[i].ElementAt(0) == 1)
                        {
                            benzerlik[item].Remove(benzerlik[item].ElementAt(0));
                            benzerlik[item].Add(2);
                        }
                        else
                        {
                            benzerlik[item].Remove(benzerlik[item].ElementAt(0));
                            benzerlik[item].Add(1);
                        }
                    }
                    else
                    {
                        if (benzerlik[i].ElementAt(0) == benzerlik[item].ElementAt(0))
                        {
                            kontrol = 0;
                        }
                        if (item == i)
                        {
                            kontrol = 0;
                        }
                    }
                }
            }
            if (kontrol == 1)
            {
                Console.WriteLine("liste bipartite");
            }
            else
            {
                Console.WriteLine("liste bipartite değil");
            }

        }
    }
}

