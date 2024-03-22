| Kullanım Senaryosu:        | Birden fazla şube merkezi bir sunucu altında toplanabilmeli, bir şubeden her şube ile ilgili işlem yapılabilmelidir. |
| -------------------------- | -------------------------------------------------------------------------------------------------------------------- |
| Birincil Aktör:            | Şubeler                                                                                                              |
| İlgililer ve Beklentileri: | İlgili 1: Kayıt Görevlisi. Tüm şubelerle ilgili kayıt işlemlerini yapabilmeyi beklemektedir.                         |
|                            | İlgili 2: Sistem Yöneticisi: Tüm şubelerle ilgili tüm işlemleri yapabilmeyi beklemektedir.                           |
| Ön Koşullar:               | Şube aktif olarak hizmet verebiliyor olmalıdır. Kapatılmış veya yeni açılacak bir şube olmamalıdır.                  |
| Son Koşullar:              | Şube ile ilgili işlemler tamamlanır. Öğrenci kaydı yapılabiliyor olmalıdır.                                          |
| Ana Senaryo:               |                                                                                                                      |
| Alternatif Senaryo:        |                                                                                                                      |

| Kullanım Senaryosu:        | Öğrencinin Ders Kaydı                                                                               |
| -------------------------- | --------------------------------------------------------------------------------------------------- |
| Birincil Aktör:            | Kayıt Görevlisi                                                                                     |
| İlgililer ve Beklentileri: | İlgili 1: Öğrenci. Kaydının düzgün bir şekilde tamamlanmış olmasını beklemektedir.                  |
|                            | İlgili 2: Kayıt Görevlisi: Sistemin kullanımının kolay olmasını beklemektedir.                      |
| Ön Koşullar:               | Şube aktif olarak hizmet verebiliyor olmalıdır. Kapatılmış veya yeni açılacak bir şube olmamalıdır. |
|                            | Öğrencinin belgeleri tamamlanmış olmalı ve kayıt koşullarını sağlamalıdır.                          |
|                            | Şubede öğrencinin kayıt olmak istediği dersin açılmış olması gerekmektedir.                         |
|                            | Öğrencinin kayıt olmak istediği dersin kotası dolmamış olmalıdır.                                   |
| Son Koşullar:              | Öğrenci kaydının başarılı bir şekilde tamamlanması.                                                 |
| Ana Senaryo:               | 1) Kayıt görevlisi sisteme kullanıcı adı ve şifresi ile giriş yapar.                                |
|                            | 2) Kayıt görevlisi öğrenci modülüne girer.                                                          |
|                            | 3) Yeni öğrenci kaydı bölümüne girer.                                                               |
|                            | 4) Öğrenci isim, yazıldığı kurs ve kur, ev ve cep telefonları, ödeme bilgilerini girer.             |
|                            | 5) Kaydet butonuna basarak kaydı tamamlar.                                                          |
| Alternatif Senaryo:        | 1a) Kayıt görevlisi yanlış şifre girdiğinde sistem hata verir ve giriş yapılmaz.                    |
|                            | 4a) Öğrencinin yazılmak istediği derste kota yok ise sistem uyarı verir ve kayıt işlemini yapmaz.   |
|                            | 4b) Cep telefonu numarası formata uygunsuz girildiğinde hata verir.                                 |
|                            | 4c) Ödeme bilgileri doğrulaması başarısız olursa hata verir.                                        |
