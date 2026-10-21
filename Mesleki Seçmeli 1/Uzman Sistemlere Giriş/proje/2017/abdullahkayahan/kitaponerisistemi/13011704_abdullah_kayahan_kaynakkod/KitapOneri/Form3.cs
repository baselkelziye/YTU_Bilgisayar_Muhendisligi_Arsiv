using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.OleDb;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.VisualBasic;
using System.Windows.Forms;

namespace KitapOneri
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }
      
        #region değişkenler
        int kisi;
        OleDbConnection conn;
        float puan = 0.0f,toplamPuan = 0.0f;
        bool aramaOneri = false;
        ArrayList id = new ArrayList();
        ArrayList eser = new ArrayList();
        ArrayList yazar = new ArrayList();
        ArrayList tur = new ArrayList();
        ArrayList yayinevi = new ArrayList();
        int eserCount = 0, maxEserCount = 0;
        int oneriCount = 0;/// getirilecek önerinin sayısı
        int basari = 0;
       

        #endregion

        private void Form3_Load(object sender, EventArgs e)
        {
            conn = new OleDbConnection("Provider=Microsoft.Ace.oledb.12.0;data source= Kitaplar.mdb");
            //veri tabanı bağlantı cümleciği.

           
            string ilkPuan = "", kullaniciSayisi = "";
             try
                {
                    conn.Close();
                    conn.Open();
                    DataSet dtst1 = new DataSet();
                    OleDbDataAdapter adtr1 = new OleDbDataAdapter("select * From puanlama  where id=1", conn);
                    adtr1.Fill(dtst1, "puanlama");

                    idTxt.Clear();
                    idTxt.DataBindings.Clear();
                    idTxt.DataBindings.Add("text", dtst1, "puanlama.kisiSayisi");
                    kullaniciSayisi = idTxt.Text;

                    idTxt.Clear();
                    idTxt.DataBindings.Clear();
                    idTxt.DataBindings.Add("text", dtst1, "puanlama.puan");
                    ilkPuan = idTxt.Text;
                    idTxt.Clear();
                label52.Visible = true;
                    label52.Text = "Toplam : "+kullaniciSayisi+" Kisi "+ ilkPuan +" Puan Verdi";
                    adtr1.Dispose();
                    conn.Close();
                }
                catch
                {
                    MessageBox.Show("Bir Hata Oluştu", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }



            }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            //Otomatik arama işlemi için harf girildikçe vt içinde arama işlemi yapar.
            // bunun tek şartı ilgili radiobButtonun seçili olmasıdır.
            if (radioButton1.Checked == true) {
            try
            {
                conn.Close();
                conn.Open();
                DataSet dtst1 = new DataSet();
                OleDbDataAdapter adtr1 = new OleDbDataAdapter("select id as[ID],Eser As [ESER İSMİ],Yazar As[YAZAR İSMİ],yayinEvi as [YAYIN EVİ],Tur As [TUR],Puan As [PUAN],OylamaSayisi As[OYLAMA SAYISI],Resim As [RESİM] From kitap1  where Eser like'%" + textBox1.Text + "%'", conn);
                adtr1.Fill(dtst1, "kitap1");
                DG1.DataSource = dtst1.Tables["kitap1"];//datagrid de bulunan sonuçları listeledil
                adtr1.Dispose();
                conn.Close();
        }
            catch
            {
                MessageBox.Show("Bir Hata Oluştu", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
      }//if
    }
     
        /// <summary>
        /// CellClik olayı DatagididViewde seçilen satırın bilgilerinin  alınması işlemidir.
        /// Aşağıdaki kodlarda ilgili listboxa seçilen kayıtların eklenmesi işlemidir.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void DG1_CellClick(object sender, DataGridViewCellEventArgs e)
        {
            
           

                if (maxEserCount == 0) MessageBox.Show("Lütfen Oylayacağınız Eser Sayısını Giriniz");
                else if (eserCount < maxEserCount)
                {
                    try
                    {
                    id.Add(DG1.Rows[e.RowIndex].Cells[0].Value.ToString());
                    //id isimli ArrayListe DGVnin seçilen satırının 0. sütununda bulunan veri eklenir
                    eser.Add(DG1.Rows[e.RowIndex].Cells[1].Value.ToString());
                    //Eser isimli ArrayListe DGVnin seçilen satırının 1. sütununda bulunan veri eklenir
                    yazar.Add(DG1.Rows[e.RowIndex].Cells[2].Value.ToString());
                    // yazar isimli ArrayListe DGVnin seçilen satırının 2. sütununda bulunan veri eklenir
                    tur.Add(DG1.Rows[e.RowIndex].Cells[4].Value.ToString());
                    //tur isimli ArrayListe DGVnin seçilen satırının 4. sütununda bulunan veri eklenir
                    yayinevi.Add(DG1.Rows[e.RowIndex].Cells[3].Value.ToString());
                    //yayinevi isimli ArrayListe DGVnin seçilen satırının 3. sütununda bulunan veri eklenir
                    listBox1.Items.Add(id[eserCount] + "_" + eser[eserCount]);
                        // belirtilen bir formatta eserin id değeri ile eserin ismi listboxa eklenir
                    eserCount++;// seçilen eser countunu 1 artıtır
                        if (eserCount == maxEserCount) button5.Enabled = true;
                        //oylanacak eser sayısı kadar eser seçilmeden öneri sisteminin çalıştırılmasını enlemek için 
                    }
                    catch { MessageBox.Show("Bir Hata Oluştu"); }
                }
                             
                else MessageBox.Show("Seçim Hakkınız Doldu");
                //oylanacak eser sayısıdan fazla kitap eklemek istenirse dönderilecek mesaj
            

        }

     
        /// <summary>
        /// Öneri sistemine girdi olarak verdiğimiz
        /// daha önce okuduğumuz kitapların olduğu list box içinden seçim yaptığımızda
        /// bu seçimlerin puanlama kısmında gürülmesini sağlayan kodlar
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            try
            {
                if (listBox1.Items.Count > 0)
                {
                    string[] id = listBox1.SelectedItem.ToString().Split('_');
                    //listboxa gönderilen formatı bölüyoruz
                    //bu bölünen formata göre sistemde arama yapıyoruz.
                    conn.Close();
                    conn.Open();
                    DataSet dtst1 = new DataSet();
                    OleDbDataAdapter adtr1 = new OleDbDataAdapter("select * From kitap1  where id =" + Convert.ToInt32(id[0]) + "", conn);
                    //sql sorgu cümlesi
                    adtr1.Fill(dtst1, "kitap1");
                    #region sonucları puanlama kısmında gösterme

                    idTxt.Clear();
                    idTxt.DataBindings.Clear();
                    idTxt.DataBindings.Add("text", dtst1, "kitap1.id");
                    //vt'deki id bilgisi ilgi textBoxa aktarıldı
                    eserTxt.Clear();
                    eserTxt.DataBindings.Clear();
                    eserTxt.DataBindings.Add("text", dtst1, "kitap1.Eser");
                    //vt'deki eser bilgisi ilgi textBoxa aktarıldı
                    yazarTxt.Clear();
                    yazarTxt.DataBindings.Clear();
                    yazarTxt.DataBindings.Add("text", dtst1, "kitap1.Yazar");
                    //vt'deki yazar bilgisi ilgi textBoxa aktarıldı
                    yayinEviTxt.Clear();
                    yayinEviTxt.DataBindings.Clear();
                    yayinEviTxt.DataBindings.Add("text", dtst1, "kitap1.YayinEvi");
                    //vt'deki yayın evi bilgisi ilgi textBoxa aktarıldı
                    turTxt.Clear();
                    turTxt.DataBindings.Clear();
                    turTxt.DataBindings.Add("text", dtst1, "kitap1.Tur");
                    //vt'deki tür bilgisi ilgi textBoxa aktarıldı
                    resimTxt.Clear();
                    resimTxt.DataBindings.Clear();
                    resimTxt.DataBindings.Add("text", dtst1, "kitap1.Resim");
                    //vt'deki resim bilgisi ilgi textBoxa aktarıldı
                    puanTxt.Clear();
                    puanTxt.DataBindings.Clear();
                    puanTxt.DataBindings.Add("text", dtst1, "kitap1.Puan");
                    //vt'deki puan bilgisi ilgi textBoxa aktarıldı
                    oylamaTxt.Clear();
                    oylamaTxt.DataBindings.Clear();
                    oylamaTxt.DataBindings.Add("text", dtst1, "kitap1.OylamaSayisi");
                    //vt'deki oylama saysısı bilgisi ilgi textBoxa aktarıldı

                    pictureBox1.ImageLocation = (resimTxt.Text);
                    //vt'deki resim bilgisi ilgi alana aktarılıp Picturbox üzerinde görüntülendi
                    #endregion
                    adtr1.Dispose();
                    conn.Close();
                }
            }
            catch (Exception)
            {

             
            }
            
        }

        /// <summary>
        /// Geri Al Buttonu
        /// Yanlış seçimleri geri almak için kullanılan button
        /// listboxtan son kaydı siler ve seçim hakkına ekleme yapar
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button3_Click(object sender, EventArgs e)
        {
            int count = id.Count-1;
            listBox1.SelectedIndex= (listBox1.Items.Count) - 1;
            listBox1.Items.Remove (listBox1.SelectedItem);
            temizle();
            if (eserCount > 0) {
                eserCount--;
                id.RemoveAt(count);
                eser.RemoveAt(count);
                yazar.RemoveAt(count);
                tur.RemoveAt(count);
                yayinevi.RemoveAt(count);             
               
            }

        }
        /// <summary>
        /// Temizle Buttonu
        /// temizle fonksiyonunu çağırarak puanlama alanındaki neslerin içerisini temizler
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button6_Click(object sender, EventArgs e)
        {
            temizle();

        }
        /// <summary>
        /// hangi şekilde arama yapacağımızı belirlediğimiz yer
        /// tam isimmi yoksa içinde geçene göreme arayacağız onu seçiyoruz.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void radioButton2_CheckedChanged(object sender, EventArgs e)
        {
            if (radioButton2.Checked) button1.Visible = true; else button1.Visible = false;
        }
        /// <summary>
        /// Oylanacak eser sayısını onayladığımız button
        /// kaç adet kitap seçeceğimizi girdiğimiz bölüm
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button4_Click(object sender, EventArgs e)
        {
            button4.Enabled = false;
            numericUpDown1.Enabled = false;
            maxEserCount =Convert.ToInt32(numericUpDown1.Value);        

        }
       /// <summary>
       /// ÖNERİ GETİR BUTTONU
       /// </summary>
       /// <param name="sender"></param>
       /// <param name="e"></param>
        private void button5_Click(object sender, EventArgs e)
        {
            aramaOneri = true;
            label14.Text = "ÖNERİLER"; // arama yazan labeli Öneri olarak değiştir
            textBox1.Enabled = false;// arama çubuğunu engelle
            button1.Enabled = false;// ara buttonunu engelle
            button3.Enabled = false;
            DG1.Visible = false; // gridi görnmez yap
            panel7.Visible = true; // içerisinde pictureboxların bulunduğu paneli görünür yap
            string querryEser="(";
            string querryYazar = "(";
            string querryTur = "(";
            string querryYayin = "(";
            int i;
            /// yukarıdaki string değişkenler sisteme girilen eserlerin bilgilerini 
            /// belirli bir formata getirerek sorguya sokmak için kullanılan değişkenlerdir.

            /// aşağıdaki döngü formatlama işleminin yapıldığı yerdir. 
            /// girilen eser, yazar,tür ve yayın evi bilgisi sql sorgu formatına uygun hale getirir.
            for (i = 0; i < maxEserCount; i++)
            {
                if (i == 0) {

                    querryEser += "'" + eser[i] + "'";
                    querryYazar += "'" + yazar[i] + "'";
                    querryTur+= "'" + tur[i] + "'";
                    querryYayin += "'" + yayinevi[i] + "'";

                }
                else {
                    querryEser += ",'" + eser[i] + "'";
                    querryYazar += ",'" + yazar[i] + "'";
                    querryTur += ",'" + tur[i] + "'";
                    querryYayin += ",'" + yayinevi[i] + "'";
                }
                
            }
            querryEser += ")";
            querryYazar += ")";
            querryYayin += ")";
            querryTur += ")";
           //formatlama işleminin son basamağıdır döngüde oluşan textleri sonuna ")" koyarak 
           //formatlama işlemini tamamlar.

            conn.Close();
            conn.Open();        

            OleDbCommand command = new OleDbCommand(); //command değişkeni oluşturalım.

            command.Connection = conn; // command.Connection ile bağlan değişkenini bağlayalım.
            
            command.CommandText = "Select DISTINCT top 100 kitap.* From  (Select  * From kitap1 Where id in ( Select id from kitap1 where yazar in "
                + querryYazar + "and Eser not in "
                + querryEser + "and  Tur in "
                + querryTur + " and YayinEvi in "
                + querryYayin + " ) union All (Select * From kitap1 Where id in (Select id from kitap1 where yazar in"
                + querryYazar + " and Eser not in"
                + querryEser + "and Tur in"
                + querryTur + "))  union All (Select * From kitap1 Where id in (Select id from kitap1 where yazar in"
                + querryYazar + "))union All (Select * From kitap1 Where id in (Select top 10 id from kitap1 where yazar not in"
                + querryYazar + "and  Tur not in "
                + querryTur + " and YayinEvi  in "
                + querryYayin + " )) union All (Select * From kitap1 Where id in (Select top 10 id from kitap1 where yazar not in"
                + querryYazar + "and  Tur  in "
                + querryTur + " and YayinEvi  not in "
                + querryYayin + " )))  as kitap  order by Puan desc";
            ///yukarıda formatlanan veriler sqş cümlesine eklenir
            ///burada öncelikle yazar tür yayın evi uyumuna, ardından yazar tür uyumuna 
            ///ardından yazar uyumuna 
            ///tür uyumuna
            ///her birine ayrı ayrı bakılarak bize sonuç döndermesi istenilir.
             OleDbDataReader reader = command.ExecuteReader(); //bu kod ile tablonun içeriğini okutuyoruz.

            while (reader.Read()) //yukarıdaki sorgudan bulduğu sonuçları listboxa belirli bir formatla yazar
            {
                listBox2.Items.Add(reader["id"] + "_" + reader["Eser"] + "_" + reader["Yazar"] + "_" + reader["Tur"] + "_" + reader["Resim"] + "_" + reader["YayinEvi"] + "_" + reader["Puan"] + "_" + reader["OylamaSayisi"]);//verileri listboxa ekliyoruz .
            }           

            conn.Close();// bağlantıyı kapatır.
            oneriGetir(oneriCount);// öneri getir fonksiyonunu ÖneriCount değeri yani 0 olarak çağırır.


        }
             

        /// <summary>
        /// Öneri getir fonksiyonu
        /// bu fonksiyon bize seçtiğimi kitaplara göre bulduğu alternatif kitapları gösteren fonksiyon
        /// her seferinde 5 adet kitap gösterir 
        /// ileri ve geri butonları ile liste içinde gezinilebiir.
        /// 
        /// </summary>
        /// <param name="limit"></param>
        void oneriGetir(int limit)
    {
          


            foreach (Control c in panel7.Controls)
            {
                if (c is PictureBox) ((PictureBox)c).ImageLocation = "";
                //panel içindeki pictureBox nesnelerinin resimlerini temizliyor.
                else if (c is Label) if(c != label30)((Label)c).Text = "";
                //panel içindeki label30 dışındaki label nesnelerinin textlerini temizliyor.

            }

            int toplamSayfa = listBox2.Items.Count / 5;
            if (toplamSayfa * 5 < listBox2.Items.Count)
                label30.Text = "Öneri Sayısı : " + listBox2.Items.Count + " Toplam Sayfa Sayısı : " + (toplamSayfa + 1) + " Görüntülenen Sayfa " + (limit + 1);
            else
                label30.Text = "Öneri Sayısı : " + listBox2.Items.Count + " Toplam Sayfa Sayısı : " + (toplamSayfa) + " Görüntülenen Sayfa " + (limit + 1);
            string[] ayirma;
            string secilen;
            int i = 0;

           //gösterme kısmı burada bir döngü belirtilen limit değerleri aralığında
           //dönerek listbox2 içindeki (önerilen kitaplar) kitapları bize gösteriyor
            #region gösterme
            for (i = 1 + (5 * limit); i <= (5 + 5 * limit); i++)
                { 
                if (i>0 && i <=listBox2.Items.Count)//listboxın sınırları içinde olduğunu garantiledik
                { 
                    listBox2.SelectedIndex = i - 1;// listboxtan elemanı seçiyor
                    secilen = listBox2.SelectedItem.ToString(); /// seçilen elemanın textini alıyor
                    ayirma = secilen.Split('_');//alınan texti "_" işaretine göre bölüyor
                    
                    if (i == 1 + (5 * limit))
                    {
                        label47.Text = ayirma[0];//seçilen elemanın id değeri
                        pictureBox2.ImageLocation = ayirma[4];//seçilen elemanın resim değeri
                        label15.Text = ayirma[1];//seçilen elemanın eserAdı değeri
                        label16.Text = ayirma[2];//seçilen elemanın yazar değeri
                        label17.Text = ayirma[3];//seçilen elemanın tür değeri
                        label31.Text = ayirma[5];//seçilen elemanın yayın evi değeri
                        label32.Text = "Puan: " + ayirma[6];//seçilen elemanın puan değeri
                        label33.Text = "Oylama Sayısı: " + ayirma[7]; //seçilen elemanın oylayan kişi sayısı değeri
                        pictureBox2.Visible = true;
                        checkBox1.Visible = true;
                    }
                    if (i == 2 + (5 * limit))
                    {
                        label48.Text = ayirma[0];
                        pictureBox3.ImageLocation = ayirma[4];
                        label18.Text = ayirma[1];
                        label19.Text = ayirma[2];
                        label20.Text = ayirma[3];
                        label34.Text = ayirma[5];
                        label35.Text = "Puan: " + ayirma[6];
                        label36.Text = "Oylama Sayısı: " + ayirma[7];
                        checkBox2.Visible = true;
                        pictureBox3.Visible = true;
                    }
                    if (i == 3 + (5 * limit))
                    {
                        label49.Text = ayirma[0];
                        pictureBox4.ImageLocation = ayirma[4];
                        label21.Text = ayirma[1];
                        label22.Text = ayirma[2];
                        label23.Text = ayirma[3];
                        label37.Text = ayirma[5];
                        label38.Text ="Puan: "+ ayirma[6];
                        label39.Text ="Oylama Sayısı: "+ayirma[7];
                        pictureBox4.Visible = true;
                        checkBox3.Visible = true;
                    }
                    if (i == 4 + (5 * limit))
                    {
                        label50.Text = ayirma[0];
                        pictureBox5.ImageLocation = ayirma[4];
                        label24.Text = ayirma[1];
                        label25.Text = ayirma[2];
                        label26.Text = ayirma[3];
                        label40.Text = ayirma[5];
                        label41.Text = "Puan: " + ayirma[6];
                        label42.Text = "Oylama Sayısı: " + ayirma[7];
                        checkBox4.Visible = true;
                        pictureBox5.Visible = true;
                    }
                    if (i == 5 + (5 * limit))
                    {
                        label51.Text = ayirma[0];
                        pictureBox6.ImageLocation = ayirma[4];
                        label27.Text = ayirma[1];
                        label28.Text = ayirma[2];
                        label29.Text = ayirma[3];
                        label43.Text = ayirma[5];
                        label44.Text = "Puan: " + ayirma[6];
                        label45.Text = "Oylama Sayısı: " + ayirma[7];
                        pictureBox6.Visible = true;
                        checkBox5.Visible = true;
                    }                 

                }
            }
            #endregion 



        }


        void gorunmez()
        {
            pictureBox2.Visible = false;
            pictureBox3.Visible = false;
            pictureBox4.Visible = false;
            pictureBox5.Visible = false;
            pictureBox6.Visible = false;
            checkBox1.Visible = false;
            checkBox2.Visible = false;
            checkBox3.Visible = false;
            checkBox4.Visible = false;
            checkBox5.Visible = false;
        }
        ///Button7
        /// <summary>
        /// ileri butonu için kullanılan kodlar 
        /// listbox üzerinden bir sonraki 5 li yi ekrana basmak için kullanılan button
        /// </summary>
        private void button7_Click(object sender, EventArgs e)
        {
           
            foreach (Control c in panel7.Controls)
            {
                if (c is CheckBox)
                {
                    if (((CheckBox)c).Checked == true)
                    {
                        basari++;//işaretli olan checkboxlar ile başarı puanımızı artırıyoruz
                        ((CheckBox)c).Checked = false;// o checkbox'ı işaretsiz hale getiriyoruz

                    }

                }
            }

            label46.Text = "Önerilen " + listBox2.Items.Count + " Kitaptan " + basari + " Tanesi Okundu";
            label46.Visible = true;
            int toplamSayfa = listBox2.Items.Count / 5;//sayfasayını bulmak için kullanıyoruz
            // int değer tam sayı gösterdiğinden eğer çarpımı counttan küçükse sayfa sayısı değerine 1 ekliyoruz
            if (toplamSayfa * 5 < listBox2.Items.Count) 
                toplamSayfa++;
            //if kontrolü olmayan sayfayalara geçişi önlemek için
            if ((oneriCount+1) < toplamSayfa) {
                gorunmez();
                oneriCount++;
            oneriGetir(oneriCount);
            }


        }

        ///Button8
        /// <summary>
        /// Geri butonu için kullanılan kodlar 
        /// listbox üzerinden bir önceki 5 li yi ekrana basmak için kullanılan button
        /// </summary>
        
        private void button8_Click(object sender, EventArgs e)
        {
            //if kontrolü olmayan sayfayalara geçişi önlemek için
            if (oneriCount > 0) { 
            oneriCount--;
            oneriGetir(oneriCount);//öneri getir fonksiyonuna sayfa sayısını gönderiyoruz
                                   // yani kaçıncı beşli olduğunu
            }
        }


        /// <summary>
        /// PictureBox clik olayları
        /// listelenen kitapların ekrana geldiğinde istediğimiz kitabı puanlamak için
        /// kitabın resmine tıklayarak bilgilerinin ilgili alanlara geçmesi sağlanmalıdı
        /// bu işlemi sağlayan kodlar bu region içinde bulunur. her bir picturebox için ayrı ayrı yazılmıştır.
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
       
            #region pictureBox Click olayları
        string[] puanlama;
        private void pictureBox2_Click(object sender, EventArgs e)
        {
            pictureBox1.ImageLocation = pictureBox2.ImageLocation;
            eserTxt.Text = label15.Text;
            yazarTxt.Text = label16.Text;
            turTxt.Text = label17.Text;
            yayinEviTxt.Text = label31.Text;
            idTxt.Text = label47.Text;
            resimTxt.Text = pictureBox1.ImageLocation.ToString();
            puanlama = label32.Text.Split(':');
            puanTxt.Text = puanlama[1].Trim();

            puanlama = label33.Text.Split(':');
            oylamaTxt.Text = puanlama[1].Trim();
  

        }

        private void pictureBox3_Click(object sender, EventArgs e)
        {
            pictureBox1.ImageLocation = pictureBox3.ImageLocation;
            eserTxt.Text = label18.Text;
            yazarTxt.Text = label19.Text;
            turTxt.Text = label20.Text;
            yayinEviTxt.Text = label34.Text;
            idTxt.Text = label48.Text;
            resimTxt.Text = pictureBox1.ImageLocation.ToString();
      

            puanlama = label35.Text.Split(':');
            puanTxt.Text = puanlama[1].Trim();

            puanlama = label36.Text.Split(':');
            oylamaTxt.Text = puanlama[1].Trim();
        }
       
        private void pictureBox4_Click(object sender, EventArgs e)
        {
            pictureBox1.ImageLocation = pictureBox4.ImageLocation;
            eserTxt.Text = label21.Text;
            yazarTxt.Text = label22.Text;
            turTxt.Text = label23.Text;
            yayinEviTxt.Text = label37.Text;
            idTxt.Text = label49.Text;
            resimTxt.Text = pictureBox1.ImageLocation.ToString();
            puanlama = label38.Text.Split(':');
            puanTxt.Text = puanlama[1].Trim();

            puanlama = label39.Text.Split(':');
            oylamaTxt.Text = puanlama[1].Trim();
        }

        private void pictureBox5_Click(object sender, EventArgs e)
        {
            pictureBox1.ImageLocation = pictureBox5.ImageLocation;
            eserTxt.Text = label24.Text;
            yazarTxt.Text = label25.Text;
            turTxt.Text = label26.Text;
            yayinEviTxt.Text = label40.Text;
            idTxt.Text = label50.Text;
            resimTxt.Text = pictureBox1.ImageLocation.ToString();
            puanlama = label41.Text.Split(':');
            puanTxt.Text = puanlama[1].Trim();

            puanlama = label42.Text.Split(':');
            oylamaTxt.Text = puanlama[1].Trim();
        }

       

        private void pictureBox6_Click(object sender, EventArgs e)
        {
            pictureBox1.ImageLocation = pictureBox6.ImageLocation;
            eserTxt.Text = label27.Text;
            yazarTxt.Text = label28.Text;
            turTxt.Text = label29.Text;
            yayinEviTxt.Text = label43.Text;
            idTxt.Text = label51.Text;
            resimTxt.Text = pictureBox1.ImageLocation.ToString();
            puanlama = label44.Text.Split(':');
            puanTxt.Text = puanlama[1].Trim();

            puanlama = label45.Text.Split(':');
            oylamaTxt.Text = puanlama[1].Trim();
        }

        #endregion


        /// <summary>
        /// Tam Eser Adına Göre Arama İçin Kullanılan Button
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button1_Click(object sender, EventArgs e)
        {
           
            try
            {
                conn.Close();
                conn.Open();
                DataSet dtst1 = new DataSet();
                OleDbDataAdapter adtr1 = new OleDbDataAdapter("select id as[ID],Eser As [ESER İSMİ],Yazar As[YAZAR İSMİ],yayinEvi as [YAYIN EVİ],Tur As [TUR],Puan As [PUAN],OylamaSayisi As[OYLAMA SAYISI],Resim As [RESİM] From kitap1  where Eser='" + textBox1.Text + "'", conn);
                adtr1.Fill(dtst1, "kitap1");
                DG1.DataSource = dtst1.Tables["kitap1"];
                adtr1.Dispose();
                conn.Close();
            }
            catch
            {
                MessageBox.Show("Bir Hata Oluştu", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void Form3_FormClosing(object sender, FormClosingEventArgs e)
        {


            string puanGiris = "";
            string ilkPuan = "", kullaniciSayisi = "";
            string id = "1";
            if (aramaOneri)
            {
                try
                {
                    conn.Close();
                    conn.Open();
                    DataSet dtst1 = new DataSet();
                    OleDbDataAdapter adtr1 = new OleDbDataAdapter("select * From puanlama  where id=1", conn);
                    adtr1.Fill(dtst1, "puanlama");

                    idTxt.Clear();
                    idTxt.DataBindings.Clear();
                    idTxt.DataBindings.Add("text", dtst1, "puanlama.kisiSayisi");
                    kullaniciSayisi = idTxt.Text;

                    idTxt.Clear();
                    idTxt.DataBindings.Clear();
                    idTxt.DataBindings.Add("text", dtst1, "puanlama.puan");
                    ilkPuan = idTxt.Text;


                    adtr1.Dispose();
                    conn.Close();
                }
                catch
                {
                    MessageBox.Show("Bir Hata Oluştu", "Hata", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }




                while (puanGiris == "")
                {
                    puanGiris = Interaction.InputBox("Önerilerimizi Beğendiniz Mi? \n\n1 - (Çok Kötü) \n10 - (Çok İyi)", "Bize Destek Verin", "Örn: 7");

                }

                kisi = Convert.ToInt32(kullaniciSayisi);// kaç kişi oylamış
                toplamPuan = (float)(Convert.ToDouble(ilkPuan));/// vt de kayıtlı puanı
                toplamPuan = (float)(toplamPuan * kisi);
                //vt de ortalma puan kayıtlı olduğundan esas puanı bulmak için çarptık        

                toplamPuan += Convert.ToInt32(puanGiris); //yeni gelen puan toplam puana ekle   
                                                          //vermek istediğimiz puan toplam puana eklendi.
                kisi++;
                // kişi sayısı artırıldı ve sisteme yazılacak puanı hesaplamak için toplampuan kişi sayısına bölündü
                puan = (float)(toplamPuan / kisi);

                conn.Close();
                conn.Open();
                OleDbCommand gncl = new OleDbCommand(@"UPDATE  puanlama set puan='" + puan.ToString() + "', kisiSayisi='" + kisi.ToString() + "' where id=" + Convert.ToInt32(id) + "", conn);
                gncl.ExecuteNonQuery();
                conn.Close();
                MessageBox.Show("Katılımınız İçin Teşekkür Ederiz \nGirdiğiniz Puan: " + puanGiris);
            }






        }

       

       
        /// <summary>
        /// Puan buttonu
        /// 
        /// Seçtiğimiz kitabı puanlamak için kullanılan buttondur
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void button2_Click(object sender, EventArgs e)
        {       conn.Close();
                conn.Open();
        
                kisi = Convert.ToInt32(oylamaTxt.Text);// kaç kişi oylamış
                toplamPuan = (float)(Convert.ToDouble(puanTxt.Text));/// vt de kayıtlı puanı
                toplamPuan = (float)(toplamPuan * kisi);  
                //vt de ortalma puan kayıtlı olduğundan esas puanı bulmak için çarptık        
           
                toplamPuan += Convert.ToInt32(puanSendTxt.Value); //yeni gelen puan toplam puana ekle   
                //vermek istediğimiz puan toplam puana eklendi.
            kisi++;
            // kişi sayısı artırıldı ve sisteme yazılacak puanı hesaplamak için toplampuan kişi sayısına bölündü
                puan = (float)(toplamPuan / kisi);           
            
                OleDbCommand gncl = new OleDbCommand("update kitap1 set puan='" + puan.ToString() + "',OylamaSayisi='" + kisi.ToString() + "'where id=" + Convert.ToInt32(idTxt.Text) + "", conn);
               //yeni puan vt'de güncellendi
                gncl.ExecuteNonQuery();                
                conn.Close();
           
            MessageBox.Show("Puan Verme İşlemi Tamamlandı");
            temizle();



        }
        //puanlama alanındaki temizleme işleminin yapıldığı method
        void temizle()
        {
            idTxt.Clear();
            eserTxt.Clear();
            yazarTxt.Clear();
            yayinEviTxt.Clear();
            resimTxt.Clear();
            turTxt.Clear();
            puanTxt.Clear();
            oylamaTxt.Clear();
            puanSendTxt.Value = 1;
            pictureBox1.ImageLocation=("");

        }


      
    }
}
