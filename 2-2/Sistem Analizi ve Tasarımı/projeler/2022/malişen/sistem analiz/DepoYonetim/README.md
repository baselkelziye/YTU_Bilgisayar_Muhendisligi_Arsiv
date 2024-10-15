Sistemin çalışması için
1:  Bilgisayarınızda Visual Studio 2022 https://visualstudio.microsoft.com/tr/thank-you-downloading-visual-studio/?sku=Community&channel=Release&version=VS2022&source=VSLandingPage&cid=2030&passive=false
2: Sql server 2019 https://www.microsoft.com/tr-tr/sql-server/sql-server-downloads
3: Sql server management studio https://docs.microsoft.com/en-us/sql/ssms/download-sql-server-management-studio-ssms?view=sql-server-ver15
kurulu bulnumsaı gereklidir
Tüm gereksinimler gerçekleştirildikten sonra 
1: sql server 2019 açılarak connection string kopyalanır
2: \DepoYonetim\DepoYonetim\PersonelMVCUII\Web.config dosyası açılır
3: <connectionStrings> tag'inin altında yer alan DepoYonetimSistemiEntities satırı
data source=BİLGİSAYAR ADI 
olarak değiştirlir
4: programa giriş için admin eklenmesi gereklidir. Admini eklemek için Sql server management studio açılır
5: database/DepoYonetimSistemi/dbo.Kullanici üzerine sağ tık basılıp edit top 200 rows basılır
6:KullaniciAdi kismi : admin sifre: admin rol:A yazılır.	
7:Visual studio üzrinden sistem çalıştırılır ve oluşturulan Kullanıcı Adı ve Şifre ile oturum açılır.