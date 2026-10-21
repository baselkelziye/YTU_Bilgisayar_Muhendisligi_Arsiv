using HtmlAgilityPack;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Web;
using System.Data.OleDb;
using System.Threading;
using System.Data.SqlClient;

namespace KitapOneri
{
    public partial class Form1 : Form
    {
               public string UserAgent { get; }
        public Form1()
        {
            InitializeComponent();
        }
       OleDbConnection conn;
     
       
        private void button1_Click(object sender, EventArgs e)
        {
            int toplam = 0;// çekilen toplam kitap sayısını tutan değişken
            //listbox içindeki herbir linki tek tek alacak olan döngümüz
            for (int j = 0; j < listBox5.Items.Count; j++) {
                listBox5.SelectedIndex=(j);
                string[] urlArr = listBox5.SelectedItem.ToString().Split('"');
                //her bir link düzenlenip atıldığından tırnak içinde ilk başta o linkten gelen tür bilgisi yazılmıştır
                //bu bilgiyi almak için seçilen item split ile bölünür
                textBox2.Text = urlArr[1];//tür bilgisi
                textBox1.Text = urlArr[2].Trim();//link bilgisi
            
           
            int Eser, Yazar, YayinEvi,Resim, eserBitis, yazarBitis,yayinEviBitis,resimBitis;
                //yukarıdaki değişkenler site içerinde aradığımız yerin başlangıç ve bitiş indexlerini tutacaklar

            string eserText, yazarText,yayinEviText,resimText;
           // alacağımız verileri yazacağımız değişkenler          
            string[] resimArr;
           //resim bilgisi site içinde karışık geldiğinden bu bilgiyi almak için split uygulanacaktır o nedenle dizi kullanılmıştır
            HttpWebRequest SiteyeBaglantiTalebi;//bağlantı talebi
            WebResponse GelenCevap;//siteden gelen cevap
            SiteyeBaglantiTalebi = (HttpWebRequest)WebRequest.Create(textBox1.Text +"1");
                //linkimize ilklendirme yapıyoruz 1. sayfadan başlayacak ve siteye bağlanmak istiyoruz
            SiteyeBaglantiTalebi.UserAgent = ".NET Framework Test Client";
            //site bot olduğumuzu anlamasın diye userAgent kullandık
            GelenCevap = SiteyeBaglantiTalebi.GetResponse();
            //siteden gelen cevabı aldık
            StreamReader CevapOku1 = new StreamReader(GelenCevap.GetResponseStream());
             // gelen streaam içinden bize gerekli olan kısmı çekmemiz gerekecek
            string KaynakKodlar1 = CevapOku1.ReadToEnd();// gelen streami sonuna kadar oku
            int sayfaSay = KaynakKodlar1.IndexOf(@"<div class=""results"">");//sayfa sayısını öğrenmek için sayfa sayısı bilgisinin başladığı tag i hedef gösterdik
            int sayfaSayBitis = KaynakKodlar1.Substring(sayfaSay).IndexOf("</div>");// sayfasayısını bilgisinin bittiği tag i hedef gösterdik
           string sayfa = ToClearText((KaynakKodlar1.Substring(sayfaSay, sayfaSayBitis)));//sub string ile kaç safadan oluştuğu bilgisini aldık
                //gelen veri (530 Sayfa) şeklindedir
            string[] sayfaarr = sayfa.Split('(');//gelen veriden sadece rakamı almak için önce paranteze göre
            sayfaarr = sayfaarr[1].Split('S');//sonra parantezin sağında kalan yeri S ye göre ayırıp sadece sayfa bilgisini elde ettik.
          
            int  sayfaSayisi= Convert.ToInt32(sayfaarr[0]);
                toplam += sayfaSayisi;
              //sayfa sayısı kadar döngüde dönerek gerekli verileri çektik
            for (int i = 1; i <= sayfaSayisi; i++)
            {
                
                    SiteyeBaglantiTalebi = (HttpWebRequest)WebRequest.Create(textBox1.Text + i.ToString());
                    SiteyeBaglantiTalebi.UserAgent = ".NET Framework Test Client";
                    //UserAgent sitenin bot olduğumuzu anlamaması için kullanılmıştır
                    GelenCevap = SiteyeBaglantiTalebi.GetResponse();

                    StreamReader CevapOku = new StreamReader(GelenCevap.GetResponseStream());
                    string KaynakKodlar = CevapOku.ReadToEnd();

                    //< div class="author">
                    Eser = KaynakKodlar.IndexOf(@"<div class=""name ellipsis"">");
                    Yazar = KaynakKodlar.IndexOf(@"<div class=""author compact ellipsis"">");
                    YayinEvi = KaynakKodlar.IndexOf(@"<div class=""publisher"">");
                    Resim = KaynakKodlar.IndexOf(@"<div class=""cover"">");
                    //Yukarıdaki kodlar ilk eserin stream içindeki başlangıç yerlerinin index cindsinden değerini almak için kullanılır
                    eserBitis = KaynakKodlar.Substring(Eser).IndexOf("</span>");
                    yazarBitis = KaynakKodlar.Substring(Yazar).IndexOf("</a>");
                    yayinEviBitis = KaynakKodlar.Substring(YayinEvi).IndexOf("</span>");
                    resimBitis = KaynakKodlar.Substring(Resim).IndexOf("alt");
                    //Yukarıdaki kodlar ilk eserin stream içindeki bitiş yerlerinin index cindsinden değerini almak için kullanılır
                    eserText = ToClearText((KaynakKodlar.Substring(Eser, eserBitis)));
                    yazarText = ToClearText((KaynakKodlar.Substring(Yazar, yazarBitis)));
                    yayinEviText = ToClearText((KaynakKodlar.Substring(YayinEvi, yayinEviBitis)));
                    resimText = ToClearText((KaynakKodlar.Substring(Resim, resimBitis)));
                    //Yukarıdaki kodlar ise bitiş ile başlangıç arasında kalan yerleri işaretleyip ilgili değişkenlere aktarır
                    resimArr = resimText.Split('"');
                    if (resimArr.Length >= 3) { 
                        resimText = resimArr[3];
                    }
                    //resim bilgisi kontrol edilmedilir. site de bazı resimler farklı şekilde sisteme konulmuştur çoğunluğun formatına göre ayarlanmıştır
                    else //bulamadığı yani bizim kısıtlarımızın dışında resim eklenmişse null olarak değişkene atanacak
                        resimText = ("NULL");

                    insertToDatabase(eserText, yazarText.Trim(), yayinEviText, textBox2.Text, resimText);
                    //insertToDtabase methodu ile alınan veriler veri tabanına yazılacak                  

                    //Aşağıdaki kodlarda aynı işlemer ikinci kitap için yapılmıştır.
                    Eser = KaynakKodlar.LastIndexOf(@"<div class=""name ellipsis"">");
                    Yazar = KaynakKodlar.LastIndexOf(@"<div class=""author compact ellipsis"">");
                    YayinEvi = KaynakKodlar.LastIndexOf(@"<div class=""publisher"">");
                    Resim = KaynakKodlar.LastIndexOf(@"<div class=""cover"">");

                    eserBitis = KaynakKodlar.Substring(Eser).IndexOf("</span>");
                    yazarBitis = KaynakKodlar.Substring(Yazar).IndexOf("</a>");
                    yayinEviBitis = KaynakKodlar.Substring(YayinEvi).IndexOf("</span>");
                    resimBitis = KaynakKodlar.Substring(Resim).IndexOf("alt");

                    eserText = ToClearText((KaynakKodlar.Substring(Eser, eserBitis)));
                    yazarText = ToClearText((KaynakKodlar.Substring(Yazar, yazarBitis)));
                    yayinEviText = ToClearText((KaynakKodlar.Substring(YayinEvi, yayinEviBitis)));
                    resimText = ToClearText((KaynakKodlar.Substring(Resim, resimBitis)));

                  
                    resimArr = resimText.Split('"');
                    if (resimArr.Length >= 3)
                    {
                       
                        resimText = resimArr[3];
                    }

                    else 
                        resimText = ("NULL");

                    insertToDatabase(eserText, yazarText.Trim(), yayinEviText, textBox2.Text, resimText);
        
                }
           
        
        }
            toplam = toplam * 2;
            MessageBox.Show(toplam.ToString());//çekilen toplam kitap sayısını mesaj olarak gösteriri


        }
        /// <summary>
        /// Kayıtları veri tabanına yazdığımız kısım
        /// </summary>
        /// <param name="eser"> Kitabın adı </param>
        /// <param name="yazar"> yazarın adı soyadı </param>
        /// <param name="yayinEvi"> yayın evi</param>
        /// <param name="tur"> kitabın türü </param>
        /// <param name="resim"> resimin linki </param>
        private void insertToDatabase(string eser,string yazar,string yayinEvi,string tur,string resim )
        {
            string puan = "10";
            try
            {
            conn.Close();
            OleDbCommand cmd = new OleDbCommand();
            cmd.CommandType = CommandType.Text;
            cmd.CommandText = @"insert into kitap1(Eser,Yazar,YayinEvi,Tur,Resim,Puan) values ('" + eser + "','" + yazar + "','" + yayinEvi + "','" + tur + "','" + resim + "','" + puan + "')";
            //sql cümleciği ile gelen verileri veri tabanına yazıyoruz
            cmd.Connection = conn;
          
            conn.Close();
                //Bağlantı kapalı ise açılır:
                if (conn.State == ConnectionState.Closed)
                {
                    conn.Open();          
                  
                }
                // Sorgu çalıştırılır:
                cmd.ExecuteNonQuery();
                // Bağlantı kapatılır:
                conn.Close();          
               
            }
            // Bir yerde hata varsa catch ile yakalanır ve mesaj verilir:
            catch (OleDbException)
            {
                MessageBox.Show("Bir Hata Olustu!");
            }
        }


        /// <summary>
        /// webden çekilen veriler içindeki gereksiz bazı kısımları temizlemek için kullanılan method
        /// </summary>
        /// <param name="text"> çekilen veri  </param>

        public static string ToClearText(string text)
        {
            return Regex.Replace(text, @"<(.|\n)*?>", string.Empty);
        }

        

       
        private void Form1_Load(object sender, EventArgs e)
        {
            conn = new OleDbConnection("Provider=Microsoft.Ace.oledb.12.0;data source= Kitaplar.mdb");
           
        }
    }
}
