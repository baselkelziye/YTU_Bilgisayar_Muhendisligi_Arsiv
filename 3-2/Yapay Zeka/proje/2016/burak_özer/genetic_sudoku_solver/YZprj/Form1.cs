using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace YZprj
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        TextBox[,] cell = new TextBox[9,9];
        TextBox[,] cell2 = new TextBox[9, 9];
        Genome gen = new Genome();

        private void Form1_Load(object sender, EventArgs e)
        {
            int en = 35;
            int boy = 35;
            int yukseklik = 20;
            this.Text = "YZ Projesi - Burak Özer || İlyas Oktay";

            //giriş alanı
            for (int satir = 0; satir < 9; satir++)
            {
                int sol = 20;
                for (int sutun = 0; sutun < 9; sutun++)
                {
                    cell[satir, sutun] = new TextBox();
                    cell[satir, sutun].Size = new Size(en,boy);
                    cell[satir, sutun].Left = sol;
                    cell[satir, sutun].Top = yukseklik;
                    cell[satir, sutun].BorderStyle = BorderStyle.FixedSingle;
                    cell[satir, sutun].AutoSize = false;
                    cell[satir, sutun].TextAlign = HorizontalAlignment.Center;
                    cell[satir, sutun].Font = new Font(Font.FontFamily, 18);
                    cell[satir, sutun].Tag = satir + ";" + sutun;

                    this.Controls.Add(cell[satir, sutun]);
                    sol += en;

                    int a = satir / 3 + sutun / 3;
                    if (a % 2 == 1)
                    {
                        cell[satir, sutun].BackColor = Color.LightBlue;
                    }

                    //arayüze sabit değerler yazılıyor
                    if (gen.staticValues[satir, sutun] != 0)
                    {
                        cell[satir, sutun].Text = Convert.ToString(gen.staticValues[satir, sutun]);                  
                    }
                }
                yukseklik += boy;			
            }

            //çözüm alanı
            yukseklik = 20;
            for (int satir = 0; satir < 9; satir++)
            {
                int sol = 350;
                for (int sutun = 0; sutun < 9; sutun++)
                {
                    cell2[satir, sutun] = new TextBox();
                    cell2[satir, sutun].Size = new Size(en, boy);
                    cell2[satir, sutun].Left = sol;
                    cell2[satir, sutun].Top = yukseklik;
                    cell2[satir, sutun].BorderStyle = BorderStyle.FixedSingle;
                    cell2[satir, sutun].AutoSize = false;
                    cell2[satir, sutun].TextAlign = HorizontalAlignment.Center;
                    cell2[satir, sutun].Font = new Font(Font.FontFamily, 18);
                    cell2[satir, sutun].Tag = satir + ";" + sutun;

                    this.Controls.Add(cell2[satir, sutun]);
                    sol += en;

                    int a = satir / 3 + sutun / 3;
                    if (a % 2 == 1)
                    {
                        cell2[satir, sutun].BackColor = Color.LightBlue;
                    }
                }
                yukseklik += boy;

            }
            ReadOnly(cell);
            ReadOnly(cell2);
        }

        private void ReadOnly(TextBox[,] a) 
        {
            for (int satir = 0; satir < 9; satir++)
            {
                for (int sutun = 0; sutun < 9; sutun++)
                {
                    a[satir, sutun].ReadOnly = true;
                }
            }         
        }

        private void Onayla_Click(object sender, EventArgs e)
        {            
            //durum.Text = "Durum: Çalışıyor...";
            genetikAlgoritma(Convert.ToInt32(jenerasyon.Text));
        }

        int ToPercent(float val)
        {
            return (int)(val * 100);
        }

        Genome gene = null;
        Genome g = null;
        int a=0;
        public void genetikAlgoritma(int GenerationSayisi)
        {
            int previousFitness = 0;
            Population TestPopulation = new Population();
            TestPopulation.set_baslangicPopulasyonu (Convert.ToInt32(textbox_population.Text));
            TestPopulation.set_mutasyonOranı ((float.Parse(mutate.Text)/100));
            TestPopulation.set_populasyonLimiti(Convert.ToInt32(limit.Text));

            for (int i = 0; i < GenerationSayisi; i++)
            {
                TestPopulation.yeniJenerasyon();
                g = TestPopulation.getEnYuksekFitness_genomes();

                if (i % 100 == 0)
                {
                    if (ToPercent(g.fitness) != previousFitness)
                    {
                        gene = g;
                        //fitness.Text = "Fitness: " + g.fitness;
                        //generation.Text = "Generation: "+ i;
                        Invalidate();
                        previousFitness = ToPercent(g.fitness);
                    }

                    if (g.fitness > 0.9999)
                    {
                        //generation.Text = "Generation: " + i;
                        break;
                    }
                    this.Text = "YZ Projesi - Burak Özer || İlyas Oktay |||| Durum: Calısıyor... | Fitness: " + g.fitness + " | Generation: " + i;
                    a = i;
                }
            }
            // ekrana (cell2) yazdıran kısım
            for (int satir = 0; satir < 9; satir++)
            {
                for (int sutun = 0; sutun < 9; sutun++)
                {
                    cell2[satir, sutun].Text = Convert.ToString(g.getIntArray(satir, sutun));
                }
            }
            fitness.Text = "Fitness: " + g.fitness;
            generation.Text = "Generation: " + a;
            durum.Text = "Durum: Bitti.";
            this.Text = "YZ Projesi - Burak Özer || İlyas Oktay |||| Durum: Bitti | Fitness: " + g.fitness + " | Generation: " + a;
        }
    }
}
