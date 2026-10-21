using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


namespace _18058029
    {
        class Program
        {
            static int ortak;

            static void Main(string[] args)
            {
                int m, n;
                int i, j, k;

                Console.WriteLine("Lutfen A'nin boyutunu girin: ");
                m = Convert.ToInt32(Console.ReadLine());
                Console.WriteLine("Lutfen B'nin boyutunu girin: ");
                n = Convert.ToInt32(Console.ReadLine());

                int[] a = new int[m];
                int[] b = new int[n];

                Console.WriteLine("Lutfen A'nin 1. elemanini girin. (Her elemandan bir tane bulunabilir!)");
                a[0] = Convert.ToInt32(Console.ReadLine());
                KumeGir(a);
                KumeYazdir(a);

                Console.WriteLine("\nLutfen B'nin 1. elemanini girin. (Her elemandan bir tane bulunabilir!)");
                b[0] = Convert.ToInt32(Console.ReadLine());
                KumeGir(b);
                KumeYazdir(b);

                for(i=0; i<a.Length; i++)
                {
                    for(j=0; j<b.Length; j++)
                    {
                        if(a[i] == b[j])
                        {
                        ortak++;
                        }
                    }
                }

                int[] c = new int[ortak];
                k = 0;

                for (i = 0; i < a.Length; i++)
                {
                    if (k == ortak)
                        break;
                    else for (j = 0; j < b.Length; j++)
                        {
                            if (a[i] == b[j])
                            {
                                c[k] = a[i];
                                k++;
                            }
                        }
                }

            Console.WriteLine("\n\nA n B : ");
                intersect(c);
            Console.WriteLine("\nA u B : ");
                union(a, b, c);
            Console.WriteLine("\nA x B : ");
                cartesian(a, b);
            Console.WriteLine("\nB x A : ");
                cartesian(b, a);
            Console.WriteLine("\nA - B : ");
                fark(a, c);
            Console.WriteLine("\nB - A : ");
                fark(b, c);

                Console.ReadLine();
            }

            static void KumeGir(int[] a)
            {
                int i, j, temp;

                for (i = 1; i < a.Length; i++)
                {
                    Console.WriteLine("Lutfen dizinin {0}. elemanini girin. (Her elemandan bir tane bulunabilir!)", i + 1);
                    temp = Convert.ToInt32(Console.ReadLine());
                    for (j = 0; j < i; j++)
                    {
                        while (temp == a[j])
                        {
                            Console.WriteLine("Ayni deger girdiniz, degistirin. Yeni deger : ");
                            temp = Convert.ToInt32(Console.ReadLine());
                        }
                    }
                    a[i] = temp;
                }
            }

            static void KumeYazdir(int[] a)
            {
            int i;
                Console.WriteLine("Diziniz : ");

                for (i = 0; i < a.Length; i++)
                {
                    Console.Write("{0} ", a[i]);
                }
            }

            static void union(int[] a, int[] b, int[] c)
            {
                int[] union = new int[a.Length + b.Length - c.Length];
                int i, j, k;
                int pres;

                int add = 1;

                for (i = 0; i < a.Length; i++)
                {
                    union[i] = a[i];
                }

                for (j = 0; j < b.Length; j++)
                {
                    pres = 0;
                    for (k = 0; k < c.Length; k++)
                    {
                        if (b[j] == c[k])
                        {
                            k = c.Length;
                            pres = 1;
                        }
                    }
                    if (pres == 0)
                    {
                        union[a.Length + add - 1] = b[j];
                        add++;
                    }
                }

                for (i = 0; i < a.Length + b.Length - ortak; i++)
                {
                    Console.Write(union[i] + "  ");
                }
            }

            static void intersect(int[] c)
            {
                int i;
                for (i = 0; i < c.Length; i++)
                {
                    Console.Write(c[i] + " ");
                }
            }

            static void cartesian(int[] a, int[] b)
            {
                int i, j;
                for (i = 0; i < a.Length; i++)
                {
                    for (j = 0; j < b.Length; j++)
                    {
                        Console.Write("(" + a[i] + "," + b[j] + ")" + "  ");
                    }
                }
            }

            static void fark(int[] a, int[] c)
            {
                int i, j;
                int pres = 0;

                for (i = 0; i < a.Length; i++)
                {
                    pres = 0;
                    for (j = 0; j < ortak; j++)
                    {
                        if (a[i] == c[j])
                        {
                            pres = 1;
                        }
                    }

                    if (pres == 0)
                    {
                        Console.Write(a[i] + "  ");
                    }
                }
            }
        }
    }

