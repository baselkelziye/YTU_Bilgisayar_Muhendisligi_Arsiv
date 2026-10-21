FilmRadar, popüler filmleri The Movie Database (TMDB) API üzerinden listeleyen, favorilere ekleme, detay görüntüleme ve arama/filtreleme özellikleri sunan bir mobil uygulamadır.

Özellikler

- Popüler filmleri TMDB API'den anlık olarak çeker ve listeler.
- Filmlere tıklayarak detay (afiş, açıklama, yıl, puan) görebilirsiniz.
- Filmleri favorilere ekleyebilir ve sadece favorileri görüntüleyebilirsiniz.
- Arama kutusu ile film adına göre anlık filtreleme yapabilirsiniz.
- Modern ve kullanıcı dostu mobil tasarım.
- Mizahi ve bilgilendirici “Hakkında” bölümü.

Kullanılan API

- [TMDB - The Movie Database API](https://www.themoviedb.org/documentation/api)
- Not: TMDB API’sinde zaman zaman veri tutarsızlıkları yaşanabiliyor. Bazı filmlerin açıklamaları yanlış veya başka bir filme ait görünebilir. Uygulama teknik olarak doğru çalışmaktadır; bu durum API tarafında yaşanan bir veri problemidir.

Kurulum ve Çalıştırma

1. Projeyi indirin veya klonlayın:
git clone https://github.com/nnisaayaz/FilmRadar.git

2. Proje klasörüne geçin:
cd FilmRadar

3. Gerekli paketleri yükleyin:
npm install

4. Expo ile başlatın:
npx expo start

5. QR kodu telefonunuzdaki Expo Go uygulamasıyla okutun.

Not: Kendi TMDB API anahtarınızı [buradan](https://www.themoviedb.org/settings/api) ücretsiz alıp (çok kolay alması), HomeScreen.js’deki `API_KEY` değişkenine eklemelisiniz.

Ekranlar ve Kullanım

- Ana Sayfa: Popüler filmler listelenir. Üstte “Favorilerim” butonuyla sadece favorilere geçiş yapılır. En alta kaydırınca “Hakkında” butonu ve uygulama bilgileri görünür.
- Detay: Seçilen filmin afişi, adı, yılı, puanı ve açıklaması görüntülenir.
- Favoriler: Favoriye eklenen filmleri tek tuşla görürsünüz.
- Hakkında: Uygulama ve geliştiriciye dair mizahi bilgiler, teşekkürler ve teknik detaylar yer alır.

Kullandıklarım:

- React Native (Expo)
- React Navigation
- Axios (API çekme)
- Context API (Global state/favoriler)
- Expo Vector Icons

Geliştirici
Nisa Ayaz

Her türlü öneri ve katkı için teşekkürler.
