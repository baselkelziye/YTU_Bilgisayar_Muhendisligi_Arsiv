using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Threading;
namespace YZSudokuSolver
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        int counter = 0; int counter1 = 0;
        public TextBox[,] tablo1 = new TextBox[9, 9];
        public TextBox[,] tablo2 = new TextBox[9, 9];
        public int[,] tempMatrix = new int[9, 9];
        

        Random rnd = new Random();
        Color renk;
        /*
         * Burada formumuzda dinamik olarak textboxlarımızı oluşturuyoruz.Bu textboxlar sayesinde
         * sudoku için baslangıc degerleri alabiliyoruz
         * **/
        void tabloOlustur(TextBox[,] sayilar, int x, int y)
        {

            counter = 0;
            counter1 = 0;
            int tmpx = x + 10, tmpy = y;
            for (int i = 0; i < 9; i++)
            {

                x = tmpx; y += 21;
                if (counter % 27 == 0)
                {
                    y += 15;
                }

                for (int j = 0; j < 3; j++)
                {
                    x += 5;

                    for (int k = 0; k < 3; k++)
                    {
                        x += 30;

                        if (((j) % 2 == 0))
                        {
                            if (i == 3 || i == 4 || i == 5)
                            {
                                if (j == 1) renk = Color.PaleGreen;

                                renk = Color.White;
                            }

                            else
                            {
                                renk = Color.PaleGreen;
                            }
                        }
                        else
                        {
                            if ((i == 3 || i == 4 || i == 5) && (j == 1)) renk = Color.PaleGreen;
                            else
                                renk = Color.White;

                        }
                        //Renk

                        TextBox textBox = new TextBox();
                        textBox.TextAlign = HorizontalAlignment.Center;
                        textBox.Width = textBox.Height = 30;
                        textBox.BackColor = renk;
                        textBox.Location = new Point(x, y);
                        textBox.MaxLength = 1;
                        sayilar[counter, counter1] = textBox;
                        textBox.KeyPress += this.textBox_KeyPress;
                        this.Controls.Add(textBox);
                        if (counter1 != 8) counter1++; else { counter++; counter1 = 0; }
                    }
                }
            }



        }
        /*
         * Burada tahtadaki textboxlara sadece rakam girilmesini sagladık -*-*
         * **/
        void textBox_KeyPress(object sender, KeyPressEventArgs e)
        {

            if (e.KeyChar == '1' || e.KeyChar == '2' || e.KeyChar == '3' || e.KeyChar == '4' || e.KeyChar == '5' || e.KeyChar == '6' || e.KeyChar == '7' || e.KeyChar == '8' || e.KeyChar == '9')
            {
                e.Handled = !char.IsDigit(e.KeyChar) && char.IsControl(e.KeyChar);
            }
            else if (!char.IsControl(e.KeyChar))
            {
                e.Handled = !char.IsControl(e.KeyChar);
            }
        }
        private void Form1_Load(object sender, EventArgs e)
        {

            progressBar1.Maximum = Convert.ToInt32(textBox4.Text);
            tabloOlustur(tablo1, 40, 20);
            tabloOlustur(tablo2, 350, 20);

        }
/*
 * Tahdadaki degerleri alıp tempMatrix'ine atıyoruz -*-*
 * **/
        public void ilkDegerAl()
        {

            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    if (tablo1[i, j].Text != "")
                    {
                        tempMatrix[i, j] = Convert.ToInt32(tablo1[i, j].Text);
                    }
                    else
                    {
                        tempMatrix[i, j] = 0;
                    }
                }
            }

        }

        private void button1_Click(object sender, EventArgs e)
        {
            
            label8.Text = "";      
            ilkDegerAl();
            int limit = Convert.ToInt32(textBox2.Text);
            int GenSayisi = Convert.ToInt32(textBox4.Text);           
            solver(GenSayisi); //Sudokuyu çözecek olan esas fonksiyonumuzu çağırıyoruz.
           
        }
   
        /*
         * 
         * Burası sudokunu cozum işlemleri baslatan kısım
         * 
         * **/
        public void solver(int GenerationSayisi)
        {
            Olustur g=null;
            int tempUygunluk = 0;
            int i=0, yuzde;
            float uygunlukKontrol = 0.0f;
            int baslangıcPopulasyonu = Convert.ToInt32(textBox1.Text);
            int limit = Convert.ToInt32(textBox2.Text);
            float mutasyonOran = float.Parse(textBox3.Text) / 100.0f;
            progressBar1.Maximum = GenerationSayisi;
            Populasyon populasyon = new Populasyon(this, baslangıcPopulasyonu, limit, mutasyonOran);

            //burada jenarasyon sayısı kadar gen olusturuyoruz ve olusan bu genlerin
            //işlemler sonucunda uygunluk degerini kontrol ediyoruz
            //bu şekilde oluşan genler arasındaki en uygun sudoku tahtasını ekranda gösteriyoruz
            while (i < GenerationSayisi && uygunlukKontrol != 1.0){
                populasyon.NewGeneration();
                 g = populasyon.getEnYuksekHesap();
                if ((int)(g.uygunlukSonuc * 100) > tempUygunluk)
                {
                    tempUygunluk = (int)(g.uygunlukSonuc * 100);
                }
                yuzde = (int)(((double)progressBar1.Value / (double)progressBar1.Maximum) * 100);
                progressBar1.Value = i;
                progressBar1.PerformStep();
                progressBar1.CreateGraphics().DrawString("EN YUKSEK UYGUNLUK: " + g.uygunlukSonuc + "  " + yuzde.ToString() + "%  ADIM SAYISI " + i, new Font("Arial", (float)8.25, FontStyle.Regular), Brushes.Black, new PointF(progressBar1.Width / 2 - 150, progressBar1.Height / 2 - 7));
                i++;
                uygunlukKontrol = g.uygunlukSonuc;
            }
            yazdir(g);
          
            label8.Text = ("EN YUKSEK UYGUNLUK: " + g.uygunlukSonuc + "  ADIM SAYISI " + i );
        }


        void yazdir(Olustur o)
        {

            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    tablo2[i, j].Text = o.sudokuMatrix[i, j].ToString();
                }

            }

        }
        private void button2_Click(object sender, EventArgs e)
        {
            int islem;
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {
                    islem = (i * 3 + i / 3 + j) % 9 + 1;
                    tablo1[i, j].Text = islem.ToString();
                }
            }
        }
        void temizle(TextBox[,] tablo) 
        {

            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 9; j++)
                {

                    tablo[i, j].Text = "";

                }
            }
        }
    
        private void button5_Click(object sender, EventArgs e)
        {
            temizle(tablo2);
         
        }

        private void button4_Click(object sender, EventArgs e)
        {
            temizle(tablo1);
           
        }
        
     
        }

    }

