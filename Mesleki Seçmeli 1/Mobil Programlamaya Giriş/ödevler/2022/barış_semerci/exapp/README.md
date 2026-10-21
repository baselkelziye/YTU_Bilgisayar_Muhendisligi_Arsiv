# Exapp
Mobil Programlamaya Giriş dersinin ödevi kapsamında sınav oluşturma uygulaması olarak Exapp uygulaması yapılmıştır.
Activity, Intent, RecyclerView, SharedPreferences, Internal Storage kavramları üzerinde durulmuştur.
Ödev dökümanına 
<a href="https://github.com/barissemerci/Exapp/blob/master/2020_2021_bahar_yarıyılı_blm_3520_mobil_programlamaya_giriş_ödev_2.pdf" target="_blank">buradan</a>
ulaşabilirsiniz.


Giriş ekranından Sign Up butonuna basılarak uygulamaya kayıt olunur. 

<img src="https://user-images.githubusercontent.com/68946715/154805879-f307b7fb-5c86-483a-b4f7-26708ff2350d.png" width="300" height="600">

Kayıt olma ekranında gerekli bilgiler doldurulur. Galeriden profil fotoğrafı seçilir. Şifrenin iki kez yazılması gereklidir. Eğer şifreler birbirleriyle aynı olmazsa kullanıcı uyarılır. Aynı ise başarılı bir şekilde kayıt yapılmış olur.
Burada girilen kullanıcı bilgileri yerel depolamada bir dosyanın içerisine kaydedilir.

<p float="left">
 
<img src="https://user-images.githubusercontent.com/68946715/154806076-37a7845e-52a2-4e27-ba2f-2bb5605bbe39.png" width="200" height="450">

<img src="https://user-images.githubusercontent.com/68946715/154806121-5343fd70-3bd7-4197-978f-5c6400ed07f1.png" width="200" height="450">

 <img src="https://user-images.githubusercontent.com/68946715/154806050-6d038a8c-93aa-4be1-9a6c-b77bb4858d01.png" width="200" height="450">
 
  <img src="https://user-images.githubusercontent.com/68946715/154806155-fa7f2a43-558b-4ef6-b8d7-516d12932068.png" width="200" height="450">
 
</p>

Kayıt olunduktan sonra tekrar giriş ekranına gelinir ve e-mail adresi ve şifre ile giriş yapılır.

<img src="https://user-images.githubusercontent.com/68946715/154806337-d0151937-9b54-4c1f-9179-4f98efbc7c93.png" width="300" height="600">

Giriş yapıldıktan sonra ana ekran açılır. Buradan istenilen işlem seçilir. İlk olarak soru eklenir.

<img src="https://user-images.githubusercontent.com/68946715/154806374-94e3aca5-2112-4a25-b0a3-4d5e160956ce.png" width="300" height="600">

Bunun için Add Question butonuna tıklanır. Soru yazılır, şıklar yazılır ve doğru cevap yanındaki kutucuk yardımıyla işaretlenir. 

<p float="left">

<img src="https://user-images.githubusercontent.com/68946715/154806451-099861f8-565a-42aa-8e2e-4d4e282c5ef6.png" width="300" height="600">

<img src="https://user-images.githubusercontent.com/68946715/154806452-8815d8e3-ab67-4860-bc26-03caedf10f2e.png" width="300" height="600">

</p>

Sorular eklendikten sonra ana ekrana geri dönülüp List Questions butonuna tıklanıldığında eklenen sorular listelenmiş bir şekilde görülebilir.

<img src="https://user-images.githubusercontent.com/68946715/154806606-d278f98b-c3c9-49fa-a15c-83c63efcdf95.png" width="300" height="600">

Ana ekrandan Customize Exam butonuna tıklanılarak açılan ekrandan sınav için uygun görülen süre, zorluk derecesi (soruların kaç şıklı olacağının sayısı), soruların puan değeri ve soru sayısı girilip kayıt edilir.

<img src="https://user-images.githubusercontent.com/68946715/154806652-830d1c84-c451-4699-961f-ebaa67f3e48e.png" width="300" height="600">

Ana ekrandan Create Exam butonuna tıklanarak sınav oluşturulur. Burada ilk olarak sınavın ismi girilir. Sınavın özellikleri Customize Exam ekranında girilen değerler ile doldurulur. İstenilirse değiştirilebilir. Sınavda bulunması istenilen sorular sağ üst tarafındaki kutucuk yardımıyla seçilir. 

<p float="left">

<img src="https://user-images.githubusercontent.com/68946715/154808460-9eb1a8ce-6c73-4f7f-873c-644cd52f88e9.png" width="300" height="600">

<img src="https://user-images.githubusercontent.com/68946715/154808457-be918633-b5d2-4c4e-b731-1b4bccb1e589.png" width="300" height="600">

</p>

Ana ekrandan Profile butonuna basılınca profil bilgileri görüntülenebilir. Ayrıca oluşturulan sınavlar burada gözükür. İstenilen sınav seçilip txt dosyası olarak istenilen uygulamada paylaşılabilir.

<p float="left">

<img src="https://user-images.githubusercontent.com/68946715/154808581-642ee767-3ede-4b0b-8afe-ada75c1708cf.png" width="300" height="600">

<img src="https://user-images.githubusercontent.com/68946715/154808573-3691c33a-8c98-46d9-a8c8-5a14b4732574.png" width="300" height="600">

</p>

Oluşan txt dosyasının içeriği aşağıdaki gibidir. Zorluk derecesi 3 olduğu için tüm soruların 3 şıklı olduğu bir sınav oluşturulmuştur. Burada bir doğru şık diğer ikisi kullanıcının girdiği dört şık içerisinden rastgele seçilen şıklardır. 

<img src="https://user-images.githubusercontent.com/68946715/154808684-a63067aa-40f4-45c1-9aff-6f8864468098.png" width="1059" height="313">



