# Ders 10 Genişletilmiş Notu: Broadcast Receiver'lar

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Dönemin Konularına Kısa Bakış
- 2. Broadcast Receiver Nedir?
- 3. Broadcast Türleri ve Kaynakları
- 4. Statik ve Dinamik Receiver'lar
- 5. Manifest'te Tanımlanan Receiver'lar
- 6. Context'e Kaydedilen Receiver'lar
- 7. onReceive, Ana Thread ve Uzun İşler
- 8. Broadcast Gönderme Yöntemleri
- 9. Receiver'dan Servis Başlatma ve İzinler
- 10. Gelen Aramaları İzleyen Receiver
- 11. Intent ile Broadcast Gönderme ve İzinlerle Kısıtlama
- 12. Alarm, PendingIntent ve Titreşim Örneği
- 13. Sticky Broadcast Intent'ler
- 14. Android Sürümlerindeki Değişiklikler ve Öneriler
- 15. Kod Örneği: Uçak Modu
- 16. Kod Örneği: Statik ve Dinamik Aksiyon
- 17. Kod Örneği: Güç ve Pil Durumu
- 18. Uygulama: Şarjda Sensör Takibini Durdurmak
- Örnek Sorular
- Dersin Toparlaması

## 1. Dönemin Konularına Kısa Bakış

Ders, dönem başında paylaşılan izlencenin üzerinden geçilerek açılır (ekrandan, 00:25:00). Şimdiye kadar mobil dünyadaki terminoloji, mobil cihazlar, mobil işletim sistemleri ve bunların masaüstü işletim sistemlerinden farkı, mobil uygulama geliştirme teknikleri ve dilleri konuşuldu. Geliştirme araçları ve ortamları tanıtıldı, Android mimarisine giriş yapıldı. Android tarafında uygulama yaşam döngüsü (Application Lifecycle) ve aktivite yaşam döngüsü (Activity Lifecycle), intent'ler ve layout'lar, bileşenler, aktivitelerin birbiriyle haberleşme yolları ve kullanıcı arayüzü bileşenleri işlendi. Ardından verinin hangi yollarla saklandığı ve son olarak telefonların veriyi hangi kaynaklardan (sensörlerden) toplayıp nasıl işlediği konuşuldu.

Bu dersin konusu Broadcast Receiver'lardır. Konu çok uzun olmadığı için derste iki üç farklı kod örneği gösterilir. Hoca, Broadcast Receiver'ların aslında arka plan işlerinin (background tasks) bir parçası olduğunu, bu yüzden arka plan işleri konusunun öne alınabileceğini söyler. Dönemin geri kalanında konum tabanlı servisler ve haritalar ile uygulamayı markete yüklerken dikkat edilmesi gereken kurallar işlenecektir.

Hoca, izlencede adı geçen kaynakların (ana kaynak olarak developer.android.com ve ders kitapları) konu başlıkları takip edilerek bir hazırlık aracı olarak kullanılmasını önerir; çünkü anlatım sırasında bazı ayrıntılar dikkatten kaçmış olabilir. Ezber beklenmez, ama bilgiyi kullanabilmek ve kod geliştirirken ihtiyaç duyulan bilgiye hızlıca erişebilmek önemlidir. Bu ders, pratik yaparak ve kurcalayarak öğrenilen bir derstir.

## 2. Broadcast Receiver Nedir?

Hoca Broadcast Receiver'ları, Android işletim sisteminde PC ortamındaki kesmelerin (interrupt) karşılığı olarak tanıtır. <!-- BELİRSİZ: altyazıda "inter-app" (00:27:16) ve "inter-up noktaları" (00:30:08) geçiyor; bağlamdan "interrupt" olduğu düşünüldü. --> Sistem düzeyinde ya da uygulama düzeyinde gerçekleşen değişikliklerden diğer uygulamaların haberdar olmasını sağlayan temel yapı taşlarıdır.

Daha önce aktiviteler anlatılırken uygulamaya giriş noktalarından (entry point) bahsedilmişti. Broadcast Receiver da uygulamaya bir başka giriş noktasıdır: bir sistem ya da uygulama değişikliğinden sonra o uygulamada bir kodun çalışmasını mümkün kılar.

Buradaki tasarım kalıbı (design pattern) publish-subscribe'dır. Sistem düzeyinde ya da farklı uygulamalarda gerçekleşen değişiklikler bir merkeze bildirilir. Bu değişikliği izlemek isteyen (abone olan) uygulamalar da değişiklik gerçekleştiğinde haberdar edilir.

Slayttaki şemada üç kaynak bir Broadcast Receiver'a bağlanır: şarj cihazının takılması (charger connected), Android sistemi ve gelen mesaj (message received) (ekrandan, 00:30:00).

## 3. Broadcast Türleri ve Kaynakları

Temelde iki tür broadcast vardır:

- **Sistem broadcast'leri:** sistemsel değişiklikleri uygulamalara aktarır.
- **Özel (custom) broadcast'ler:** bir uygulamaya özel değişikliklerin diğer uygulamalara ya da uygulamanın kendi içine haber verilmesinde kullanılan intent'lerdir.

Derste ilgilenilen üç yol vardır: broadcast'lerin diğer uygulamalardan gelmesi, sistem tarafından gönderilmesi ve `LocalBroadcastManager` ile uygulamanın kendi içinde, örneğin bir aktivitede gerçekleşen bir değişikliğin diğer aktivitelere ve uygulamanın diğer bileşenlerine bildirilmesi.

Telefonun şarja takılması, uçak moduna geçmesi, yeniden başlatılması sistemsel değişikliklerdir. Uygulamalar yeri geldiğinde bunları önemser ve değişiklik olduğunda kendilerini buna göre konumlandırır. Hocanın verdiği örnekler:

- Telefon şarja takıldığında ya da şarj belli bir seviyenin (örneğin %50) üstündeyken güncelleme yapmak.
- Hücresel ağdaki kota dolmasın diye işi yalnız Wi-Fi ağına bağlanıldığında yapmak.
- İşi gece, belli bir saatte ya da gün değiştiğinde, yani telefonun daha az meşgul olduğu dönemde yapmak.

Bunların hepsi sistemsel değişikliklerin izlenmesini gerektirir.

Sistem broadcast'lerinin sayısı 200'ün üzerindedir. Slaytta listelenenler arasında pil durumunun değişmesi, pilin belli bir seviyenin altına düşmesi, cihazın yeniden başlaması, bir güç kaynağına takılması, uçak moduna geçilmesi, ekranın açılması ya da kapanması, bir SMS ulaşması ve bir telefon araması gelmesi vardır. Bunları izlemek için kayıt (register) olunabilir.

> **Hocanın vurgusu:** Register olmanın bir maliyeti vardır; gerçekten ihtiyaç duyuluyorsa register olunmalıdır.

## 4. Statik ve Dinamik Receiver'lar

Sistemsel ya da uygulamasal değişiklikleri izlemek için receiver tanımlanır. İki tür vardır (ekrandan, 00:30:00):

1. **Manifest'te tanımlanan (manifest-declared) receiver'lar:** statik olarak tanımlanır.
2. **Context'e kaydedilen (context-registered) receiver'lar:** dinamik olarak, çalışma zamanında tanımlanır.

Statik ve dinamik tanımlamanın örnekleri daha önce başka konularda (izinler gibi) görülmüştü. Broadcast Receiver'larda bu ayrım özellikle önemlidir: manifest'te tanımlanan receiver'lar uygulama kapalıyken de ilgili değişiklikleri izler; context'e kaydedilen receiver'lar ise yalnız uygulama ya da ilgili aktivite yok edilmediği (destroy) sürece izler.

Her sistem olayı manifest tanımıyla sürekli izlenemez; Android buna kısıtlar getirdi. Bunun temel sebebi, bir değişikliği izlemek isteyen uygulama ya da aktivite sayısı arttıkça sistem kaynağı tüketiminin artmasıdır. Her şey manifest'te tanımlanınca izlenebilseydi, herkes her şeyi istediği gibi izler ve telefonun kaynakları çok hızlı tükenirdi. Android bu yüzden sürümler içinde kısıtlar getirdi. Eskiden yalnız manifest'te tanımlanan birçok özellik (izinler dahil) için artık çalışma zamanında, iş ihtiyaç duyulduğu sürece tanımlama yapılıp sonra kaydın silinmesi (unregister) beklenir.

## 5. Manifest'te Tanımlanan Receiver'lar

Bir broadcast receiver manifest'te tanımlanırsa, broadcast gönderildiğinde uygulama çalışmıyorsa bile sistem uygulamayı başlatır (ekrandan, 00:35:00). Yani uygulama yüklendiği andan itibaren, manifest'te izlemek istediği sistem düzeyindeki bir değişiklik kodlanmışsa ve bu API seviyesine uygunsa, uygulama hiç açılmasa bile izleme başlar. Değişiklik olduğunda yapılacak işin kodu `onReceive` metoduna yazılır.

Slayttaki ikinci madde şudur: uygulama API 26 ya da üstünü hedefliyorsa, uygulamayı özel olarak hedeflemeyen (implicit) broadcast'ler için manifest'te receiver tanımlanamaz (ekrandan, 00:35:00). Hoca bunu, sistem düzeyindeki bazı broadcast'lerin API 26'dan sonra manifest'te tanımlanamadığı şeklinde açıklar. Bunun listesi vardır; ezberlemek gerekmez, ama fikir sahibi olmakta fayda vardır.

Manifest'te receiver'ın hangi sınıf olduğu ve hangi aksiyonları izleyeceği belirtilir. Örnekte iki aksiyon vardır: `BOOT_COMPLETED` ve `INPUT_METHOD_CHANGED`. Bir Broadcast Receiver birden fazla aksiyonu izleyebilir; gerekirse hepsi için aynı işi, gerekirse gelen aksiyonun türüne göre farklı işler yapabilir (ekrandan, 00:35:00):

```xml
<receiver android:name=".MyBroadcastReceiver" android:exported="true">
    <intent-filter>
        <action android:name="android.intent.action.BOOT_COMPLETED"/>
        <action android:name="android.intent.action.INPUT_METHOD_CHANGED" />
    </intent-filter>
</receiver>
```

Kendi yazılan `MyBroadcastReceiver` sınıfı `BroadcastReceiver`'dan türetilir ve `onReceive` metodunu içerir. Gelen bilgi intent üzerinden alınır, log'a ve `Toast` mesajı olarak ekrana yazılır (ekrandan, 00:35:00):

```java
public class MyBroadcastReceiver extends BroadcastReceiver {
    private static final String TAG = "MyBroadcastReceiver";
    @Override
    public void onReceive(Context context, Intent intent) {
        StringBuilder sb = new StringBuilder();
        sb.append("Action: " + intent.getAction() + "\n");
        sb.append("URI: " + intent.toUri(Intent.URI_INTENT_SCHEME).toString() + "\n");
        String log = sb.toString();
        Log.d(TAG, log);
        Toast.makeText(context, log, Toast.LENGTH_LONG).show();
    }
}
```

## 6. Context'e Kaydedilen Receiver'lar

Çalışma zamanında receiver kaydetmek için bir Broadcast Receiver nesnesi ve bir `IntentFilter` tanımlanır. İzlenecek aksiyon `addAction` ile eklenir. Önceki örnekte aksiyon XML etiketi içine yazılmıştı; burada aynı iş kaynak kodun içinde Java ile yapılır. Son olarak receiver ve izlemesi istenen intent filter `registerReceiver`'a parametre olarak verilir (ekrandan, 00:40:00):

```java
BroadcastReceiver br = new MyBroadcastReceiver();

IntentFilter filter = new IntentFilter(ConnectivityManager.CONNECTIVITY_ACTION);
    filter.addAction(Intent.ACTION_AIRPLANE_MODE_CHANGED);
    this.registerReceiver(br, filter);
```

Kayıt silme metodu slaytta `unregisterReceiver(android.content.BroadcastReceiver)` olarak verilir.

> **Hocanın vurgusu:** Bir receiver register ediliyorsa mutlaka unregister edilmelidir ki iş bitince kaynaklar serbest kalsın. Yoksa manifest tanımından bir farkı kalmaz ve daha fazla kaynak tüketilir.

Kayıt ve silme, birbirine birebir karşılık gelen yaşam döngüsü metotlarında yapılır; Android bunun daha verimli olduğunu tanımlamıştır:

- `onStart`'ta register edildiyse `onStop`'ta unregister edilir.
- `onResume`'da register edildiyse `onPause`'da unregister edilir.
- `onCreate`'te register edildiyse `onDestroy`'da unregister edilir.

Slaytta bu eşler `onCreate(Bundle)` - `onDestroy()` ve `onResume()` - `onPause()` olarak gösterilir; altta `onSaveInstanceState(Bundle)` da yer alır (ekrandan, 00:40:00).

Context'e kaydedilen receiver'lar, kaydedildikleri context geçerli olduğu sürece broadcast alır. Slayttaki açıklamaya göre bir Activity context'inde kayıt yapılırsa aktivite yok edilmediği sürece broadcast alınır; Application context'inde kayıt yapılırsa uygulama çalıştığı sürece alınır (ekrandan, 00:40:00). Hoca bunu şöyle anlatır: Activity context'inde kayıt yapılıp uygulama içinde başka bir ekrana geçildiğinde receiver izlemeyi bırakır; Application context'inde kayıt yapıldıysa başka aktivitelere geçilse de uygulama ayakta kaldığı sürece izleme devam eder.

## 7. onReceive, Ana Thread ve Uzun İşler

`onReceive` metodunda daha fazla iş de yapılabilir, ama önemli bir kısıt vardır. Bir UI thread, yani ana (main) thread vardır. Receiver bir değişiklik karşısında iş yaparken bu iş genellikle saniyeler sürmemelidir; milisaniyeler, en fazla bir saniyeye yakın mertebede tamamlanmalıdır. Uygulama açıkken ya da arka plandayken yapılan iş çok uzun sürerse `onReceive` ana thread'i bloklar. Bu yüzden `onReceive`'deki kodların çok uzun sürecek işler yapmaması istenir. `onReceive` içinden arka planda bir servis başlatılabilir, ama bunun da dikkat edilmesi gereken başka noktaları vardır.

Slayttaki bir sonraki örnek, ilerleyen haftalarda konuşulacak bir konunun kodudur: bir Broadcast Receiver bir durum değişikliğini yakaladığında, `onReceive` içinde yapılacak işi bir pending (bekleyen) sonuç üzerinden bir AsyncTask'a devreder. AsyncTask, işin asenkron yürümesi için kullanılan yapı taşlarından biridir. `onReceive`'de daha uzun sürecek bir iş varsa (örneğin bir dosya yüklemek ya da bir bitmap üzerinde işlem yapmak; bunlar saniyeler sürebilir), bir AsyncTask yaratılıp çalıştırılarak iş ana thread'den ayrılır ve arka planda devam eder. Arka plan işleri sınavdan sonra anlatıldığında receiver'larla bağlantı daha iyi kurulacaktır. <!-- BELİRSİZ: bu slaytın karesi yok; kodun ayrıntısı doğrulanamadı. -->

> **Ek bilgi (derste anlatılmadı):** Android belgelerindeki bu tür örnekte büyük olasılıkla `onReceive` içinde `goAsync()` çağrılır. Bu metot bir `PendingResult` döndürür; arka plandaki iş bitince `pendingResult.finish()` çağrılarak sisteme broadcast'in işlendiği bildirilir. Böylece receiver `onReceive`'den döndükten sonra da kısa bir süre canlı kalabilir.

## 8. Broadcast Gönderme Yöntemleri

Receiver'lar gönderilen broadcast intent'leri izler; uygulamalar izlemek istedikleri olayları ya manifest'te ya da çalışma zamanında bildirir. Ama bir uygulama yalnız izlemez; kendisi de broadcast mesajı yayınlayabilir, broadcast intent gönderebilir. Üç yol vardır (ekrandan, 00:45:00):

1. **`sendOrderedBroadcast`:** Broadcast'i her seferinde tek bir receiver'a gönderir. Her receiver sırayla çalışırken sonucu bir sonraki receiver'a aktarabilir ya da broadcast'i tamamen kesebilir; böylece broadcast diğer receiver'lara geçmez. Receiver'ların çalışma sırası, eşleşen intent-filter'daki `android:priority` niteliğiyle denetlenir; aynı önceliğe sahip receiver'lar rastgele sırada çalışır.
2. **`sendBroadcast`:** Broadcast'i bütün receiver'lara belirsiz bir sırada gönderir. Buna normal broadcast denir. Daha verimlidir, ama receiver'lar diğer receiver'ların sonuçlarını okuyamaz, broadcast'ten aldıkları veriyi aktaramaz ve broadcast'i kesemez.
3. **`LocalBroadcastManager.sendBroadcast`:** Broadcast'i yalnız gönderenle aynı uygulamadaki receiver'lara gönderir. Uygulamalar arası gönderim gerekmiyorsa yerel broadcast kullanılmalıdır. Süreçler arası iletişim gerekmediği için çok daha verimlidir ve diğer uygulamaların broadcast'i alması ya da göndermesiyle ilgili güvenlik kaygısı yoktur.

Hoca yerel broadcast'i şöyle açıklar: mesaj işletim sistemi düzeyine çıkmadan iç döngüde aktiviteler arasında paylaşılır; bu kaynak tüketimi açısından çok verimlidir. Başka bir uygulamayı bilgilendirme niyeti yoksa, yalnız kendi uygulamasındaki başka aktiviteler bilgilendirilecekse `LocalBroadcastManager` üzerinden gitmek çok daha sağlıklı ve etkilidir.

Sıralı broadcast'in amacını hoca şöyle anlatır: birden fazla receiver gönderilen mesajı dinliyor olsun. Mesajın önce ulaşması istenen bir receiver vardır ve onun yapacağı işe göre diğer receiver'ın bir şey yapıp yapmayacağına karar verilmek istenir. Bu durumda intent `sendOrderedBroadcast` ile gönderilir ve sıraya göre ilgili receiver'lara uğrar; bir tür önceliklendirme yapılmış olur.

> **Hocanın vurgusu:** `sendOrderedBroadcast` ile çok sık karşılaşılmaz, ama ihtiyaç duyulduğunda hayat kurtarabilecek bir yaklaşım olduğu için bilinmesinde fayda vardır.

> **Ek bilgi (derste anlatılmadı):** `LocalBroadcastManager` daha sonraki AndroidX sürümlerinde büyük olasılıkla kullanımdan kaldırılmış (deprecated) olarak işaretlenmiştir; uygulama içi haberleşme için LiveData ya da benzeri gözlemlenebilir yapılar önerilir. Derste anlatılan verimlilik ve güvenlik mantığı yine geçerlidir.

## 9. Receiver'dan Servis Başlatma ve İzinler

Slayttaki örnekte `BroadcastReceiver`'dan türetilen kendi receiver'ınızın `onReceive` metodunda bir intent yaratılır ve bu intent aracılığıyla bir servis başlatılır. Teknik olarak "şöyle bir değişiklik olduğunda bu servisi başlat" denmektedir. Değişikliğin ne olduğu yandaki manifest kodunda görülür: receiver etiketindeki aksiyon, cihazın yeniden başlatıldığı anı yakalamak ister. Manifest'teki bu aksiyona abone olunduktan sonra telefon her baştan başladığında servis bu uygulama aracılığıyla çalıştırılır ve arka planda çalışmaya başlar. <!-- BELİRSİZ: bu slaytın (00:45:37 civarı) karesi yok; servis ve aksiyon adları ekrandan doğrulanamadı. -->

Arka plan işleri konusunda, arka plan servislerinden ve uzun süre çalışan (long running) servislerden mümkün olduğunca uzak durulmasının istendiği çokça konuşulacaktır. Yine de arka planda bir şey çalıştırmak gerekebilir. Hocanın örneği: yakın gelecekte makine öğrenmesi telefonlarda daha yaygın kullanıldığında, bilgiler alındıkça belli değişikliklerin arka planda bir model üzerinde çalıştırılması gerekebilir. Bu servis şeklinde de olabilir. Broadcast Receiver ile böyle bir giriş noktasını tetikleme imkânı vardır.

Bazı sistem düzeyindeki olayları izlemek için mutlaka izin almak gerekir. Örnekte cihazın açılıp açılmadığını (`BootCompleted`) izlemek için manifest'in üstünde `uses-permission` ile izin alınmıştır. İlgili izin yoksa olay izlenemez; uygulama hata mesajı verebilir ya da olay gerçekleştiğinde izleme şansı olmaz.

> **Ek bilgi (derste anlatılmadı):** `BOOT_COMPLETED` aksiyonunu almak için gereken izin büyük olasılıkla `android.permission.RECEIVE_BOOT_COMPLETED`'dir; manifest'e `<uses-permission android:name="android.permission.RECEIVE_BOOT_COMPLETED"/>` satırı eklenir.

## 10. Gelen Aramaları İzleyen Receiver

Bir başka slaytta solda bir Broadcast Receiver, sağda manifest vardır (ekrandan, 00:50:00). Receiver gelen intent'in içinden telefonun durumunu (çalıyor mu) ve arayan numarayı alır:

```java
package de.vogella.android.receiver.phone;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.telephony.TelephonyManager;
import android.util.Log;

public class MyPhoneReceiver extends BroadcastReceiver {

    @Override
    public void onReceive(Context context, Intent intent) {
        Bundle extras = intent.getExtras();
        if (extras != null) {
            String state = extras.getString(TelephonyManager.EXTRA_STATE);
            Log.w("MY_DEBUG_TAG", state);
            if (state.equals(TelephonyManager.EXTRA_STATE_RINGING)) {
                String phoneNumber = extras
                        .getString(TelephonyManager.EXTRA_INCOMING_NUMBER);
                Log.w("MY_DEBUG_TAG", phoneNumber);
            }
        }
    }
}
```

Manifest'in ilgili kısımları (ekrandan, 00:50:00):

```xml
<uses-sdk android:minSdkVersion="15" />

<uses-permission android:name="android.permission.READ_PHONE_STATE" >
</uses-permission>

<application ...>
    ...
    <receiver android:name="MyPhoneReceiver" >
        <intent-filter>
            <action android:name="android.intent.action.PHONE_STATE" >
            </action>
        </intent-filter>
    </receiver>
</application>
```

Uygulama bir telefon aramasıyla ilgileniyorsa, arama geldiğinde bunu izleyebilir. Hoca bir örnek anlatır: telefon servislerinin yaygın olmadığı dönemde operatörler, telefon kapalıyken arayan numaraları SMS olarak gönderiyordu. Operatör rehberi bilmediği için mesajda yalnız numara yazıyordu; numarayı ezbere bilmeyen kişi arayanın yabancı biri mi yoksa rehberindeki biri mi olduğunu anlayamıyordu. O dönemde geliştirdikleri küçük bir uygulama, arka planda bir SMS alındığında SMS'i açıyor, numarayı rehberde arıyor ve kime aitse onun adını SMS'in içine koyarak "şu saatte şu kişi aramıştır" şeklinde mesajı değiştiriyordu.

Gelen SMS'i yakalamak, bir telefon numarasını işlemek, arama istatistiği tutmak, arama geldiği anda yapılacak bir iş (örneğin bir numarayı sessize almak) bu tür receiver'larla yapılabilir. Gelen aramalar ve giden mesajlar sistem düzeyinde izlenip üzerinde değişiklik yapılabilir. Ama bu, ilgili izinlerin alınması koşuluyla mümkündür. Her uygulama telefonun durumunu izinsiz izleyebilseydi, birçok uygulama kullanıcının hiç haberi olmadan sistem düzeyindeki bütün değişiklikleri izler ve telefona ya da kullanıcıya zarar verme potansiyeli taşırdı. Bugün izin almadan Broadcast Receiver'larla bu tür izleme yapmak neredeyse mümkün değildir.

## 11. Intent ile Broadcast Gönderme ve İzinlerle Kısıtlama

Dersin ikinci bölümünde broadcast intent gönderme tarafına bakılır. Bir uygulamanın bir aksiyon olduğunda diğer uygulamaları ya da kendi içini bilgilendirmesi isteniyorsa bir intent tanımlanır. Diğerlerinin izleyeceği aksiyon `setAction` ile belirtilir. Paylaşılacak bir bilgi varsa `putExtra` ile intent'e konur ve intent `sendBroadcast` metoduyla gönderilir.

Burada intent, bir aksiyondan abone olanların haberdar olması için paylaşılır. `startActivity` ile gönderilen intent ile buradaki intent teknik olarak birbirinden farklıdır.

İzinlerin paylaşılması ve broadcast'i izleyenlerin bu izne sahip olması da önemlidir (ekrandan, 01:05:00). Gönderen taraf, izlenen aksiyonla ilgili olarak alıcının kullanıcıdan örneğin SMS gönderme iznini almış olmasını istiyorsa, bu izni `sendBroadcast`'e parametre olarak verir:

```java
sendBroadcast(new Intent("com.example.NOTIFY"),
              Manifest.permission.SEND_SMS);
```

```xml
<uses-permission android:name="android.permission.SEND_SMS"/>
```

Karşılığında alıcı taraf bu izni kullanıcıdan almış olmalıdır. İzinle alma tarafı ise şöyledir (ekrandan, 01:05:00):

```xml
<receiver android:name=".MyBroadcastReceiver"
          android:permission="android.permission.SEND_SMS">
    <intent-filter>
        <action android:name="android.intent.action.AIRPLANE_MODE"/>
    </intent-filter>
</receiver>
```

```java
IntentFilter filter = new IntentFilter(Intent.ACTION_AIRPLANE_MODE_CHANGED);
registerReceiver(receiver, filter, Manifest.permission.SEND_SMS, null );
```

Hocaya göre bu, son API'lerde daha sık öne çıkan bir kullanım şeklidir. Bu sayede herkesin herhangi bir broadcast'e istediği gibi talip olması engellenir; izni almamış bir uygulamanın boşuna sistem kaynağı harcamasının önüne geçilir.

## 12. Alarm, PendingIntent ve Titreşim Örneği

Bir sonraki slaytta basit bir örnek vardır: bir buton ve sağ tarafta XML arayüzü. Hoca örneği, butona 10 defa basıldığında Broadcast Receiver'ın bunu yakalaması olarak anlatır. <!-- BELİRSİZ: bu slaytın karesi yok; tetikleyicinin "10 defa basma" mı yoksa girilen bir süre mi olduğu ekrandan doğrulanamadı. -->

Örnekte bir alarm üretilir ve böylece ileride gerçekleşecek bir aksiyon kurulur. Alarm da arka planda gerçekleşen bir görevdir, ama arka plan işlerini yapan yapılardan belli ölçüde ayrışır: arka plandaki işlerin tam istenen (exact) zamanda yapılıp yapılmaması konusunda bir ayrım vardır. Alarm, beklenen işleri yönetmek için kurulur. Telefondaki alarm saat 8.30 için kurulduysa mutlaka 8.30'da devreye girmelidir.

İleride gerçekleşecek bir iş için pending intent'lerden (`PendingIntent`) faydalanılır. Broadcast Receiver'larda bir değişikliğin ne zaman gerçekleşeceği bilinmez: kullanıcı 10 defa tıklamayı 3 saniye sonra da yapabilir, 3 dakika sonra da. Bu yüzden intent `PendingIntent` statüsünde tanımlanır; sisteme bu intent'i application context'ini gözeterek oluşturması ve görevini `AlarmManager` üzerinden yapması söylenir. İlgili `AlarmManager` devreye girer ve yapılması gereken iş tamamlanır. Böylece hem izleme mümkün kılınır hem de bir aksiyon alınması sağlanır.

Bu örneğin `onReceive` metodu yazıldığında (örnekteki `MyBroadcastReceiver`), "Don't Panic, But Your Time Is Up" mesajı `Toast` ile gösterilir; aynı zamanda vibrator aracılığıyla telefonun 2 saniye boyunca titremesi sağlanır.

Bu davranış bildirimlerde (notification) sık görülür: bildirim gelince telefon bazen ses çıkarır, bazen titrer. Uygulamada yapılan bir aksiyon sonucunda kullanıcının böyle bir bilgilendirmeye maruz kalması isteniyorsa aynı yol kullanılır. Telefonun şarjı %20'nin altına düştüğünde çıkan uyarı gibi, uygulamaya özel olarak da "enerji çok kısa sürede tükenecek, uygulamanın şu özelliğini kapatıyorum" şeklinde kullanıcıya bilgi verilebilir.

## 13. Sticky Broadcast Intent'ler

Sticky (yapışkan) broadcast intent'ler artık kullanılmaz. Hocaya göre bunlar özellikle Android 5'e kadar olan dönemde aynı intent'in ya da gelişmenin tekrar tekrar izlenmesini sağlıyordu: bir aksiyon gerçekleştikten sonra sistemden temizlenen intent yeniden yaratılıyordu. Bu güvenlik açıklarına yol açtığı için artık böyle bir özellik kullandırılmaz; ama varlığından haberdar olmakta fayda vardır.

Slayttaki kod pil durumu değişikliği için kayıt yapar (ekrandan, 01:10:00):

```java
// Register for the battery changed event
IntentFilter filter = new
IntentFilter(Intent.ACTION_BATTERY_CHANGED);

/ Intent is sticky so using null as receiver works fine
// return value contains the status
Intent batteryStatus = this.registerReceiver(null,
filter);

// Are we charging / charged?
int status =
batteryStatus.getIntExtra(BatteryManager.EXTRA_STATUS,
-1);
boolean isCharging = status ==
BatteryManager.BATTERY_STATUS_CHARGING
    || status == BatteryManager.BATTERY_STATUS_FULL;

boolean isFull = status ==
BatteryManager.BATTERY_STATUS_FULL;

// How are we charging?
int chargePlug =
batteryStatus.getIntExtra(BatteryManager.EXTRA_PLUGGED,
-1);
boolean usbCharge = chargePlug ==
BatteryManager.BATTERY_PLUGGED_USB;
boolean acCharge = chargePlug ==
BatteryManager.BATTERY_PLUGGED_AC;
```

(Slayttaki ikinci yorum satırı tek `/` ile başlamaktadır; ekranda olduğu gibi aktarıldı. Derlenecekse `//` olmalıdır.)

> **Ek bilgi (derste anlatılmadı):** Sticky broadcast gönderen `sendStickyBroadcast` metodu büyük olasılıkla API 21 (Android 5.0) ile kullanımdan kaldırılmıştır. Ancak `ACTION_BATTERY_CHANGED` gibi sistemin kendi sticky broadcast'leri hâlâ vardır; slayttaki gibi `registerReceiver(null, filter)` çağrısı son yayınlanan pil durumunu bir intent olarak döndürür.

## 14. Android Sürümlerindeki Değişiklikler ve Öneriler

Her Android sürümünde broadcast'lerle ilgili yenilikler gelir:

- **Android 7:** medya ile ilgili `ACTION_NEW_PICTURE` ve `ACTION_NEW_VIDEO` sistem broadcast'leri artık gönderilmez. Çok fazla uygulamanın izlediği bir değişiklik olduğu ve sistem kaynaklarını gereksiz tükettiği düşünüldüğü için devre dışı bırakıldı.
- **Android 8:** manifest'te tanımlanan receiver'larla ilgili yeni kısıtlamalar geldi. Bazı sistem broadcast'lerinin manifest'te tanımlanma imkânı kaldırıldı, yalnız context'e kayıtla izlenebilir oldu. Böylece uygulama ayakta değilken arka planda izlemeye enerji harcanması yerine, değişiklikler yalnız uygulama kullanılırken izlenir.
- **Ağ durumu:** güvenlik amacıyla `NETWORK_STATE_CHANGED_ACTION` broadcast'i artık kullanıcının konumuyla ilgili ve onu tanımlayabilecek bilgi sunmaz. Bunun başka bir yolu vardır: `getConnectionInfo` kullanılır, ama o da çeşitli izinlere tabidir. Böylece Wi-Fi'den hücresel ağa ya da hücresel ağdan Wi-Fi'ye geçiş yine izlenebilir, ama buradan konum bilgisi alınamaz.

> **Ders sonrası not:** Hoca ağ durumu değişikliğini Android 8 maddesinin ardından anlattı; bu değişiklik büyük olasılıkla Android 9 (API 28) ile gelmiştir.

Uygulamanın hedef kitlesindeki API seviyelerine sahip telefonlar için herkesi kapsayacak çözümler koda yerleştirilmelidir. Daha önceki kodlarda görüldüğü gibi API seviyesine bakılarak çeşitli önlemler alınabilir. Her telefonda farklı bir durumla karşılaşmamak için sürümlerdeki yenilikler yakından takip edilmelidir.

Son olarak iki öneri vardır:

- Uygulama içinde kalınacaksa, mesajlar ya da değişiklikler yalnız aktiviteler arasında paylaşılacaksa mutlaka `LocalBroadcastManager` kullanılmalıdır.
- Arka planda uzun süre devam etmesi beklenen işler `JobScheduler`'a emanet edilmelidir. Broadcast Receiver bir sistem değişikliğini fark ettiğinde bu işi devreye sokar.

## 15. Kod Örneği: Uçak Modu

İlk örnek gerçek bir telefonda çalıştırılır. Uçak modu açıldığında ekranda "Airplane Mode is On", kapatıldığında "Airplane Mode is off" `Toast` mesajı görünür.

Android Studio'da iki sınıf vardır: `AirplaneModeActivity` ve `AirplaneModeChangeReceiver` (proje ağacında görünür, ekrandan, 01:20:00). `AirplaneModeChangeReceiver`, `BroadcastReceiver`'ı genişletir. `onReceive` metodunda application context üzerinden sistem ayarlarına gidilir ve `Settings.Global` içindeki uçak modu değeri (`AIRPLANE_MODE_ON`) kontrol edilir. Uçak modu açıldıysa `Toast` ile "Airplane Mode is on", kapandıysa "off" yazılır. Bunu tetikleyen, kullanıcının uçak moduna girip çıkmasıdır: uygulama bu modu izlemek istediğini belirtmiş ve olay gerçekleştiğinde yapacaklarını `onReceive`'e yazmıştır. <!-- BELİRSİZ: bu kodun karesi yok; sınıf adları proje ağacından, ayrıntılar altyazıdan alındı. -->

Aktivite tarafında `onCreate`'te layout'un ayarlandığı normal kısım vardır. Bir receiver tanımlanır ve `new IntentFilter(...)` ile bir intent filter oluşturulur. Burada context'e kayıtlı (context-registered) receiver tanımlanır: bir intent filter ve ardından `registerReceiver` ile hangi receiver'ın, hangi filter'ı (hangi intent'i) izleyeceği söylenir. İzlenecek aksiyon parametre olarak verilir. `onStart`'ta `registerReceiver`, `onStop`'ta `unregisterReceiver` yapılır. Hoca bunun `onResume` ve `onPause`'da da yapılabileceğini ekler.

## 16. Kod Örneği: Statik ve Dinamik Aksiyon

İkinci örnekte iki farklı aksiyon izlenir, ama tek bir Broadcast Receiver tanımlanmıştır (ekrandan, 01:20:00). Kodun açıklamasına göre `ACTION1` ve `ACTION2` değişkenleri ana aktivitede de tanımlıdır:

```java
public class BRStaticDynamicReceiver extends BroadcastReceiver {

    @Override
    public void onReceive(Context context, Intent intent) {

        Toast.makeText(context, "Received an intent.", Toast.LENGTH_SHORT).show();

        if (intent.getAction().equals(BRStaticDynamicActivity.ACTION1)) { //is it our action1?
            Toast.makeText(context, "We received an intent for Action1.", Toast.LENGTH_SHORT).show();
        } else if (intent.getAction().equals(BRStaticDynamicActivity.ACTION2)) { //is it our action2?
            Toast.makeText(context, "We received an intent for Action2.", Toast.LENGTH_SHORT).show();
        }
    }
}
```

Receiver çağrıldığında önce bir intent ulaştığını `Toast` ile gösterir. Sonra gelen intent'ten aksiyon bilgisini alır: `ACTION1` ise "We received an intent for Action1.", `ACTION2` ise "We received an intent for Action2." yazar. Bu, bir receiver'ın birden fazla aksiyonu izleyip aksiyona göre farklı iş yapmasının örneğidir.

Aktivitede (`BRStaticDynamicActivity`) iki buton vardır; biri "statik", diğeri "dinamik" intent göndermek içindir. Aktivite içinde receiver sınıfından bir nesne (`mReceiver`) yaratılır. Telefonda "Send static intent" butonuna basınca "Received an intent" ve ardından Action1 mesajı, ikinci butona basınca Action2 mesajı görünür.

Birinci butonun kodunda intent `ACTION1` ile oluşturulur ve kodun bulunduğu paketin adı set edilir (ekrandan, 01:25:00):

```java
Intent i = new Intent(BRStaticDynamicActivity.ACTION1);
i.setPackage("com.example.myapplication"); //in API 26, it must be explicit now.
//since it's registered as a global (in the manifest), use sendBroadcast
//LocalBroadcastManager.getInstance(getContext()).sendBroadcast(i);
//LocalBroadcastManager.getInstance(getBaseContext()).sendBroadcast(i);
sendBroadcast(i);
```

Paket adı yazılır, çünkü broadcast bu paket aracılığıyla karşı tarafa gönderilir; bunu karşı tarafa tanıtmanın yolu budur. Başka uygulamaların da izlemesi istenseydi paketi bu şekilde set etmeye gerek olmazdı ya da paket bilgisinin karşı tarafa verilmesi gerekirdi. `sendBroadcast` ile intent gönderilince broadcast işi tamamlanır.

İkinci buton ve yaşam döngüsü metotları şöyledir (ekrandan, 01:25:00 ve 01:30:00):

```java
//setup button to send an intent for dynamic registered receiver, which is registered in MainActivity.
findViewById(R.id.button2).setOnClickListener(new View.OnClickListener() {
    @Override
    public void onClick(View view) {
        Intent i = new Intent(BRStaticDynamicActivity.ACTION2);
        //since it's registered a local, use the LocalBroadcastManager.
        LocalBroadcastManager.getInstance(getApplicationContext()).sendBroadcast(i);
        //use this if registered as a global receiver.
        //getActivity().sendBroadcast(i);
        Log.v(TAG, "Should have sent the broadcast.");
    }
});

@Override
public void onResume() {
    super.onResume();
    // Register mReceiver to receive messages.  This is using the local broadcast, instead of a global.
    LocalBroadcastManager.getInstance(this).registerReceiver(mReceiver, new IntentFilter(ACTION2));
    //the one below registers a global receiver.
    //registerReceiver(mReceiver, new IntentFilter(ACTION2));
    //Log.v(TAG, "receiver should be registered");
}

@Override
protected void onPause() {  //or onDestory()
    // Unregister since the activity is not visible.  This is using the local broadcast, instead of a global.
    LocalBroadcastManager.getInstance(this).unregisterReceiver(mReceiver);
    //the one below unregisters a global receiver.
    //unregisterReceiver(mReceiver);
    Log.v(TAG, "receiver should be unregistered");
    super.onPause();
}
```

Hoca burada öğrencilere, iki aksiyondan hangisinin statik (manifest'te), hangisinin dinamik tanımlandığını sorar (bkz. Örnek Sorular). Cevap: `ACTION1` manifest'te statik, `ACTION2` context'e bağlı olarak dinamik tanımlanmıştır. Bunu 64. satırdaki `LocalBroadcastManager...sendBroadcast` ifadesinden ve `onResume`/`onPause`'daki kayıt-silme kodundan anlamak mümkündür.

Kritik nokta şudur: birinci butondaki `sendBroadcast(i)` yerine yorum satırındaki `LocalBroadcastManager` ile gönderme açılıp kod öyle çalıştırılırsa, kodun içindeki yoruma göre ("since it's registered as a global, use sendBroadcast") global düzeyde (manifest'te) tanımlanmış aksiyon yerel broadcast ile yayınlandığı için sistem tarafından algılanmaz ve beklenen `onReceive` çalışmaz. Bir aksiyon manifest düzeyinde statik tanımlandıysa herkesin görebileceği, herkese açık düzeyde tanımlanmış demektir. Kendi ürettiğiniz broadcast'i yerel olarak gönderirseniz, manifest'te izlenmek istenen işi üst düzeydeki sistem göremez; izleme global düzeyde olduğu için `onReceive` de çalışmaz. Yani mesaj yerelde gönderilir ama izleme global düzeydedir. Bu yüzden `ACTION1` `LocalBroadcastManager` ile değil, `sendBroadcast` ile gönderilir.

> **Hocanın vurgusu:** Burası kritiktir. Bu, statik ve dinamik aksiyon tanımı arasındaki önemli farklardan biridir.

Hoca şunu da ekler: izlenen aksiyon sistem düzeyinde bir broadcast olsaydı, onu izlemek için yine context'e kayıt yapılabilirdi; bunda bir sorun yoktur. Sorun, kendi ürettiğiniz aksiyonu manifest'te izleyip yerel olarak göndermektir.

## 17. Kod Örneği: Güç ve Pil Durumu

Üçüncü örnek telefonun pil durumunu izler. Telefon kabloyla bağlı olduğu için ekranda "Status is Charging" ve pilin %90 seviyesinde olduğu görünür; kablo çekildiği anda mesaj "Status is not Charging" olarak değişmelidir.

`PowerStatusActivity`'de farklı bir yaklaşım vardır: receiver sınıfı da aynı kaynak dosyanın içine konmuştur. Hocaya göre genelde böyle yapılmaz, ama bu şekilde kullanılan senaryolarla da karşılaşılabilir.

Aktivitede mesajların gösterildiği bir `TextView` vardır. Pil durumu değişikliğini izleyen bir intent filter tanımlanır ve pil durumunu izlemek için `registerReceiver` çağrılır; bu çağrıdan bir değer dönmesi beklenir. Dönen değerle pilin o anda şarj oluyor mu, tam dolu mu olduğu kontrol edilir. Pil seviyesiyle ilgili iki bilgi alınıp pilin ne kadarının dolu olduğu hesaplanır. Sonra şarj durumuna göre "Status is Charging" yazılır; hesaplanan yüzde ve şarjın ne aracılığıyla yapıldığı da ekrana yazdırılır.

Receiver için intent filter'a şu aksiyonlar eklenir:

- `ACTION_POWER_CONNECTED`: güce bağlandığını anlamak için.
- `ACTION_POWER_DISCONNECTED`: kablo çekilince "Not Charging" yazmak için. Durum her değiştiğinde bildirim istenir.
- `ACTION_BATTERY_LOW`: pil düşük seviyenin altına indiğinde sistem bir broadcast üretir.
- `ACTION_BATTERY_OKAY`: pil tekrar yeterli seviyeye çıktığında.

Ardından register ve unregister işleri yapılır. Receiver'ın kodu şöyledir (ekrandan, 01:35:00):

```java
public class MyReceiver extends BroadcastReceiver {
    public MyReceiver() {
    }

    @Override
    public void onReceive(Context context, Intent intent) {

        Log.wtf("myReceiver", "received an intent");
        String info = "\n something wrong.";
        int level = intent.getIntExtra(BatteryManager.EXTRA_LEVEL, -1);
        int scale = intent.getIntExtra(BatteryManager.EXTRA_SCALE, -1);
        float batteryPct = level * 100 / (float)scale;

        int mStatus = 0;
        if (intent.getAction().equals(Intent.ACTION_BATTERY_LOW)) {  //battery is low!

            info = "\n batter low. should shut down things. battery at " + batteryPct;
            mStatus = 1;
            Log.v("myReceiver", "battery low");
        } else if (intent.getAction().equals(Intent.ACTION_BATTERY_OKAY)) {  //battery is now ok!
            info = "\n battery Okay.  " + batteryPct;
            mStatus = 2;
            Log.v("myReceiver", "battery okay");
        } else if (intent.getAction().equals(Intent.ACTION_POWER_CONNECTED)) {  //battery is charging.
            info = "\n Power connected, so phone is charging." + batteryPct;
            ...
```

Karede kod `ACTION_POWER_CONNECTED` dalının ortasında kesilir; hocanın anlatımına göre devamında `ACTION_POWER_DISCONNECTED` için de bir mesaj yazdırılır. Receiver mesajlarını log'a yazar ve hesaplamalarda intent'ten aldığı bilgileri kullanır.

Pil yüzdesi `level * 100 / (float) scale` ile hesaplanır. Örneğin `level = 90`, `scale = 100` için sonuç $90 \cdot 100 / 100 = 90.0$ olur; ekranda görülen %90 bu tür bir hesaptır (python ile doğrulandı).

> **Ders sonrası not:** Hoca `BATTERY_LOW` eşiğini telefonlarda "genellikle %20", `BATTERY_OKAY` eşiğini %80 olarak söyledi (kendisi de "yanlış hatırlamıyorsam" dedi). Aynı dosyanın üstündeki yorum satırlarında ise "power capacity 15 low (when unplugged)", "power capacity 30 okay.. (when plugged in and was low)", "power capacity 100 full charge." yazmaktadır (ekrandan, 01:35:00). Eşik cihaz üreticisinin yapılandırmasına bağlıdır; Android'in varsayılan düşük pil eşiği büyük olasılıkla %15 civarındadır.

## 18. Uygulama: Şarjda Sensör Takibini Durdurmak

Bir önceki derste ışık sensörü ve hareket (doğrusal ivme) sensöründen yararlanan bir uygulama yapılması istenmişti. Bu sensörlerle telefonun cepte mi, masanın üzerinde mi, çantada mı olduğu ya da kişinin hareket edip etmediği anlaşılacaktı.

Bu derste istenen eklenti şudur: telefon şarja takıldığında hareketsiz bir konumda, bir masanın üzerinde ya da bir yerde duracağı için sensörler boşuna izleme yapmasın. Bir Broadcast Receiver ile telefonun şarja takıldığı anlaşılmalı ve sensör takibi durdurulmalıdır (sensör dinleyicisinin kaydı silinir). Telefon şarjdan çekildiğinde takip yeniden başlatılmalıdır (yeniden register edilir). <!-- BELİRSİZ: altyazıda yeniden kaydın "onVisim metodu üzerinden" yapılacağı söyleniyor (01:49:38); hangi metot olduğu anlaşılamadı. --> Hoca kolay olan örneğin (güç durumu örneği) kodlarını chat üzerinden paylaşır.

Uygulama bölümünde bir öğrenci evde fiziksel bir Android telefonu olmadığını ve bu tür alıştırmaları test edemediğini söyler.

**Soru:** Fiziksel telefon olmadan bu alıştırmaları yapamamak ne kadar önemli? **Cevap:** Sorun yalnız sensörlerle ilgili olabilir. Telefonun şarja takılıp takılmadığı emülatörde simüle edilebilir; emülatörde bu durumlar değiştirilebilir. Önemli olan mantıklı bir şey yapmak ve öğrenilenleri uygulamaktır; alıştırmalar elin alışması ve genel konseptin anlaşılması için basit tutulur. Kısa bir süre için bir telefon edinilip denenebilir; çok fazla test gerektirmeyen, 5-10 dakikalık bir iştir.

## Örnek Sorular

**Soru 1** (ekrandan ve derste sözlü, 01:24:53; kod: ekrandan, 01:25:00)

`BRStaticDynamicActivity` kodunda iki buton vardır. Birinci buton `ACTION1` intent'ini `setPackage` + `sendBroadcast(i)` ile, ikinci buton `ACTION2` intent'ini `LocalBroadcastManager.getInstance(getApplicationContext()).sendBroadcast(i)` ile gönderir. `onResume`'da `LocalBroadcastManager...registerReceiver(mReceiver, new IntentFilter(ACTION2))`, `onPause`'da `unregisterReceiver(mReceiver)` çağrılır. Hangi aksiyon manifest'te statik, hangisi dinamik tanımlanmıştır? Neye dayanarak?

> **Çözüm (derste verildi):** `ACTION1` statik (manifest'te), `ACTION2` dinamik (context'e kayıtlı) tanımlanmıştır. Bir öğrencinin cevabı: `ACTION2` için register/unregister yapılıyor. Kayıt kodu görülmese bile 64. satırdaki `LocalBroadcastManager...sendBroadcast` ifadesi, `ACTION2`'nin manifest düzeyinde değil context düzeyinde tanımlandığını gösterir. `ACTION1` global tanımlı olduğu için `sendBroadcast` ile gönderilir; `LocalBroadcastManager` ile gönderilseydi sistem bunu görmez ve `onReceive` çalışmazdı.

**Soru 2** (derste sözlü, 01:59:38)

Işık sensörü ve doğrusal ivme (hareket) sensörü verisiyle telefonun nerede olduğu nasıl anlaşılır?

> **Çözüm (derste verildi, hoca ve bir öğrenci birlikte kurdu):** Işık, telefonun cepte mi yoksa masada ya da elde mi olduğunu ayırır; hareket, telefonun kişiyle birlikte hareket edip etmediğini gösterir.
>
> - Işık var, hareket var: telefon kullanılıyordur.
> - Işık yok, hareket var: telefon cepte ve kişi hareket ediyordur.
> - Işık var, hareket yok: telefon masanın üzerinde duruyordur (orada kullanılıyor da olabilir, ama bu hassasiyette bir ayrım beklenmez).
>
> Dördüncü durum (ışık yok, hareket yok) derste ayrıca söylenmedi; önceki derste konuşulan "cepte ya da çantada, hareketsiz" durumu büyük olasılıkla buna karşılık gelir.

**Soru 3** (derste verilen alıştırma, 01:35:44 ve 01:47:51)

Önceki haftanın sensör uygulamasına, telefon şarja takıldığında sensör takibini durduran, şarjdan çekildiğinde yeniden başlatan bir Broadcast Receiver ekleyin.

> **Çözüm (derste verilmedi):** Derste gösterilen yapı taşlarıyla bir çözüm yolu (kod derlenmedi, yalnız adımlar):
>
> 1. Aktivitede bir `BroadcastReceiver` ve bir `IntentFilter` oluşturulur; filter'a `Intent.ACTION_POWER_CONNECTED` ve `Intent.ACTION_POWER_DISCONNECTED` aksiyonları eklenir.
> 2. Receiver, karşılık gelen yaşam döngüsü metotlarında (örneğin `onResume`/`onPause` ya da `onStart`/`onStop`) `registerReceiver` ve `unregisterReceiver` ile kaydedilir ve silinir.
> 3. `onReceive` içinde `intent.getAction()` kontrol edilir: `ACTION_POWER_CONNECTED` ise sensör dinleyicisinin kaydı `SensorManager` üzerinden silinir (takip durur); `ACTION_POWER_DISCONNECTED` ise dinleyici yeniden kaydedilir (takip başlar).
> 4. Uygulama açılırken telefon zaten şarjdaysa, sticky `ACTION_BATTERY_CHANGED` için `registerReceiver(null, filter)` ile `EXTRA_STATUS` okunup başlangıç durumu belirlenebilir.

## Dersin Toparlaması

Bu derste Broadcast Receiver'lar, Android'de sistem ya da uygulama düzeyindeki değişikliklerden haberdar olmanın publish-subscribe tabanlı yolu olarak ele alındı. Sistem ve özel broadcast'ler, manifest'te statik ve context'e dinamik kayıt arasındaki fark, dinamik kayıtta register/unregister eşlerinin yaşam döngüsü metotlarına bağlanması ve `onReceive`'in ana thread'i bloklamaması gerektiği vurgulandı. Gönderme tarafında `sendOrderedBroadcast`, `sendBroadcast` ve `LocalBroadcastManager.sendBroadcast` karşılaştırıldı; izinlerle gönderme ve alma, alarm ve `PendingIntent`, sticky intent'ler ve Android sürümlerinin getirdiği kısıtlar konuşuldu. Uçak modu, statik/dinamik aksiyon ve güç durumu örnekleri gerçek cihazda gösterildi; en kritik ders, manifest'te tanımlı bir aksiyonun yerel broadcast ile gönderilirse yakalanamayacağıdır.

Hoca, `onReceive`'den uzun işleri ayırmak için kullanılan asenkron yapıların, servislerin ve `JobScheduler`'ın arka plan işleri konusunda ayrıntılı işleneceğini ve receiver'larla bağlantının orada daha iyi kurulacağını belirtti.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
