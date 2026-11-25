# Ders 22 Genişletilmiş Notu: Java ile GUI Programlama: Swing, JFrame, JPanel ve Olay Yönetimi

> Bu not, ders kaydının altyazısından hazırlanmış ayrıntılı ders notudur. Kısa tekrar için aynı dersin kısa notuna bakın.

## İçindekiler

- 1. Yeniden Kullanılabilirlik ve Tasarım Kalıpları
- 2. Swing Paketi ve Model-View-Controller
- 3. Swing Kalıtım Hiyerarşisi: JFrame ve JPanel
- 4. İlk Pencere: SimpleWindow
- 5. Ekrana Göre Boyut ve Simge: SizedWindowWithIcon
- 6. Swing'i Olay Dağıtım İş Parçacığında Başlatmak ve Adsız Sınıf
- 7. Panel ve Çizim: NotHelloWorld Örneği
- 8. Çerçevenin Diğer Metotları ve Ara Toparlama
- 9. Java ile Olay Yönetimi
- 10. Düğme Olayları: ButtonTest
- 11. Pencere Olayları: WindowEventTest
- 12. Adaptör Sınıfları
- 13. Fare Olayları: MouseEventsTest
- 14. Klavye Olayları: KeyboardEventTest
- Örnek Sorular

## 1. Yeniden Kullanılabilirlik ve Tasarım Kalıpları

Dersin konusu Java'da grafik kullanıcı arayüzü (GUI) programlamadır. Hoca konuya girmeden önce Swing'in dayandığı tasarım kalıbını anlatmak için tasarım kalıpları (design patterns) fikrine değindi.

Nesneye yönelik programlamada yeniden kullanılabilirlik (reusability) çok kullanılır: yazılan bir metot aynı sınıftaki başka metotlarca kullanılabildiği gibi başka sınıflara da kullandırılabilir. Hoca bunun sınavlarda da beklendiğini vurguladı.

> **Hocanın vurgusu:** Bir sınıfta zaten bir iş yapan metot varsa ve bu metodun girdilerini, çıktısını ve ne yaptığını biliyorsanız, aynı işi başka bir metodun içinde yeniden kodlamayın. Örneğin bir veri yapısına nesne koyan bir `add` metodu yazıyorsanız ve nesnenin yapıda olup olmadığını denetlemeniz gerekiyorsa, aynı sınıftaki `search` metodunu çağırın; ona girdileri verip döndürdüğü sonucu kullanın. Arama kodunu `add`'in içinde tekrar yazmayın.

Tasarım kalıpları da iyi bir yazılım tasarımı için şablonlar sunar ve kodun yeniden kullanılabilirliğini artırmaya çalışır. Her kalıbın farklı bir amacı vardır. Hoca ileride görülecek kalıplara örnek olarak Singleton, Adapter (adaptör), Facade ve şimdi görülecek Model-View-Controller'ı saydı.

## 2. Swing Paketi ve Model-View-Controller

Java'da kullanıcı arayüzü geliştirmek için Java 2 ile gelen `javax.swing` paketi kullanılır. Java dünyasında başka arayüz kütüphaneleri de vardır: Swing masaüstü tabanlı arayüzler oluşturur; Java Server Faces ve Java Server Pages gibi kütüphaneler ise web tabanlı arayüzler oluşturur. Derste Swing işlendi.

Slayttaki genel bilgiler şunlardır (ekrandan, 00:15:00):

- Java'daki GUI düzenleyicileri Microsoft'un programlama ortamları kadar kolay kullanılmaz.
- Java'da GUI işlemlerinin öğrenme eğrisi oldukça diktir.
- Java'nın yerleşik GUI paketi `javax.swing`'dir:
  - Java 1.2'den beri kullanılan güncel pakettir.
  - `java.awt` içindeki sınıflara dayanır.
  - Sınıf adları `J` ile başlar: `javax.swing.JFrame` ile `java.awt.Frame` farklıdır. "J'yi unutmayın!"
- Eclipse vakfının SWT'si gibi üçüncü taraf paketler de vardır; bu derste işlenmez.

Swing, Model-View-Controller (MVC) tasarım kalıbını gerçekler. Bu kalıp, gerçeklemede birbirinden bağımsız üç bileşen olmasını ister:

- **Model:** ham veriyi (raw data) temsil eder.
- **View (görünüm):** bu ham verinin farklı görünüşlerini yönetir ve temsil eder.
- **Controller (denetleyici):** kullanıcıyla etkileşir, kullanıcının komutlarını karşılar ve buna dayanarak veriyi okur ya da değiştirir.

## 3. Swing Kalıtım Hiyerarşisi: JFrame ve JPanel

Hoca, Swing ile gelen arayüz sınıflarının kalıtım hiyerarşisini gösterdi (slayt 6, ekrandan, 00:20:00):

```text
java.lang.Object
  └─ java.awt.Component
       └─ java.awt.Container
            ├─ javax.swing.JComponent
            │    └─ javax.swing.JPanel
            └─ java.awt.Window
                 └─ java.awt.Frame
                      └─ javax.swing.JFrame
```

En tepede bütün sınıfların kökü olan `java.lang.Object` vardır. Ondan `Component`, ondan da `Container` türer. Yukarıda tanımlanan bütün metotlar aşağıdaki, onları genişleten sınıflar tarafından kullanılır.

Swing'den önce AWT adlı bir kullanıcı arayüzü kütüphanesi vardı; sonra Swing geldi. Swing, AWT'nin bazı genel sınıflarını genişletir. Bu yüzden hiyerarşide `java.awt` ve `javax.swing` sınıfları birlikte görülür.

Derste iki tür kap (container) kullanılacak: çerçeve (`JFrame`) ve panel (`JPanel`). Hoca bunu bir çizim tahtasıyla anlattı: `JFrame` en altta kullanılan kaptır, bir çizim tahtası gibidir. Onun üzerine `JPanel` konur; panel tek başına kullanılmaz, çerçevenin üzerine yerleştirilir. Kullanıcı arayüzü bileşenleri de panelin üzerine konur. İkisi de kaptır: çerçeve panelleri, paneller de arayüz bileşenlerini içinde tutar.

## 4. İlk Pencere: SimpleWindow

İlk örnek basit bir pencere oluşturur (slayt 4, ekrandan, 00:25:00). Slaytta: "Temel bir pencere oluşturma: `javax.swing.JFrame` sınıfı temel bir pencereyi temsil eder. Kendi pencerelerinizi bu sınıftan kalıtımla oluşturun."

```java
package oop08;
import javax.swing.*;
@SuppressWarnings("serial")
public class SimpleWindow extends JFrame {
    public static final int DEFAULT_WIDTH = 300;
    public static final int DEFAULT_HEIGHT = 200;
    public SimpleWindow( ) {
        setSize( DEFAULT_WIDTH, DEFAULT_HEIGHT );
    }
    public static void main(String[] args) {
        SimpleWindow window = new SimpleWindow( );
        window.setTitle("A Simple Window");
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setVisible(true);
    }
}
```

Kodun parçaları şöyle açıklandı:

- `import javax.swing.*;` ile Swing paketindeki bütün sınıflar kullanılabilir hâle gelir.
- `JFrame` genişletildiği için derleyici bir seri numarası (serial version) ister; bu durumla daha önce `Serializable` arayüzü gerçeklenirken de karşılaşılmıştı. `@SuppressWarnings("serial")` anotasyonu "bunun farkındayız, seri numarası vermek istemiyoruz, uyarı verme" demektir.
- `DEFAULT_WIDTH` ve `DEFAULT_HEIGHT` çerçevenin genişliğini ve yüksekliğini belirleyen `int` alanlardır. Değişmeyecekleri için `final`, sınıfın birden çok nesnesi oluşturulursa hepsi aynı değerleri paylaşacağı için `static` tanımlanmıştır.
- Varsayılan kurucuda `setSize` çağrılır. `setSize` bu sınıfta tanımlı değildir; `JFrame` genişletildiği için oradan gelir.
- Sınıfın kendi `main` metodu vardır, yani tek başına çalıştırılabilir. `main` içinde nesne oluşturulur ve `setTitle` (pencere başlığı), `setDefaultCloseOperation` (sağ üst köşedeki X'e basılınca pencerenin kapanması ve programın durması), `setVisible(true)` (çerçevenin görünür olması gerekir) çağrılır. Bunların hepsi `JFrame`'den gelir.

Hoca kodu Eclipse'te çalıştırdı. Pencere ekranın sol üst köşesinde açıldı, çünkü ekranın neresinde duracağı söylenmemişti. Başlık verildi, X'e basılınca kapandı.

## 5. Ekrana Göre Boyut ve Simge: SizedWindowWithIcon

İkinci örnekte çerçevenin ekranın neresinde görüneceği ayarlanır ve çerçeveye bir simge (icon) eklenir (ekrandan, 00:30:00):

```java
package oop08;
import java.awt.*;
import javax.swing.*;

@SuppressWarnings("serial")
public class SizedWindowWithIcon extends JFrame {

    public SizedWindowWithIcon( ) {
        Toolkit kit = Toolkit.getDefaultToolkit();
        Dimension screenSize = kit.getScreenSize();
        int screenHeight = screenSize.height;
        int screenWidth = screenSize.width;

        setSize(screenWidth / 2, screenHeight / 2);

        setLocation(screenSize.width / 4, screenSize.height / 4);

        Image img = kit.getImage("icon.jpg");

        setIconImage(img);

        setTitle("A Sized Window With Icon");
    }

    public static void main(String[] args) {
        SizedWindowWithIcon window = new SizedWindowWithIcon( );
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.setVisible(true);
    }
}
```

AWT'den gelen `Toolkit` sınıfı statik metotlar içeren bir sınıftır; daha önce de statik metotlu sınıflar görülmüştü. `getDefaultToolkit()` ile bir `Toolkit` nesnesi alınır. Bu nesnenin `getScreenSize()` metodu kullanılan donanımın, yani ekranın boyutunu bir `Dimension` nesnesi olarak verir. `Dimension` da bu iki paketin altındaki sınıflardandır. `screenSize.height` ve `screenSize.width` o anda kullanılan ekranın boyutlarıdır.

Önceki örnekte boyut elle verilmişti. Bu sefer genişlik ve yükseklik ekranın genişlik ve yüksekliğinin yarısı yapılır. Ardından üst sınıftan gelen yeni bir metot kullanılır: `setLocation`. Bu metot çerçeveyi bir dikdörtgen olarak düşünürsek, sol üst köşesinin ekranın hangi noktasına konacağını söyler. Konum ekran boyutlarının dörtte biri olduğu için pencere ekranı ortalar: ekran genişliği $W$, yüksekliği $H$ ise pencere $(W/4, H/4)$ noktasından başlar, $W/2 \times H/2$ boyutundadır ve sağ alt köşesi $(3W/4, 3H/4)$ olur (ara adım eklendi).

`Toolkit`'in `getImage` metodu projenin bulunduğu dizindeki bir simge dosyasını alır ve bir `Image` nesnesi olarak verir. Böylece `Dimension`'ın yanında `Image` sınıfı da görülmüş olur. `JFrame`'den gelen `setIconImage` metodu bu resmi çerçeveye ekler. `main` içinde nesne oluşturulur, kapanma işlemi ve görünürlük ayarlanır.

Çalıştırıldığında pencere ekranın tam ortasında, ekranın yarısı boyutunda açıldı; istenen başlık ve simge göründü, X'e basılınca program durdu.

## 6. Swing'i Olay Dağıtım İş Parçacığında Başlatmak ve Adsız Sınıf

Şimdiye kadar çerçevenin içine bir şey çizdirilmedi. Panel eklemeden önce hoca bir noktaya değindi: kullanıcı arayüzündeki her işlem hızlı çalışması gereken ve kullanıcıyla etkileşimi fazla olan işlemlerdir. Bu yüzden arayüz bir iş parçacığı (thread) olarak oluşturulur. Bu zorunlu değildir; ilk iki örnek iş parçacığı olmadan yazıldı. Ama arayüzü iş parçacığı olarak oluşturmak kullanıcı etkileşimleri sırasında hızı artırır ve daha etkileşimli bir arayüz sağlar.

Slayttaki ifade şöyledir (slayt 11, ekrandan, 00:45:00):

- Swing'i başlatmanın doğru yolu: Swing bileşenleri oldukça karmaşıktır, bu yüzden GUI bileşenlerini ayrı bir iş parçacığında başlatmamız gerekir.
- Bu, olay dağıtım iş parçacığından (event dispatch thread) yapılmalıdır; yani fare tıklamaları ve tuş vuruşları gibi olayları kullanıcı arayüzü bileşenlerine ileten iş parçacığından.
- Bu amaçla kullanılan kod parçası:

```java
EventQueue.invokeLater(new Runnable() {
    public void run() {
        /* statements */
    }
});
```

İş parçacıkları konusunda görüldüğü gibi, `Runnable` arayüzünü gerçekleyen sınıflar iş parçacığına dönüştürülebiliyordu: bir `Thread` nesnesi yaratılır ve ona `Runnable`'ı gerçekleyen bir sınıfın nesnesi verilirdi. Burada ise `EventQueue` sınıfının statik `invokeLater` metodu kullanılır. Bu metoda `Runnable`'ı gerçekleyen, yani iş parçacığı yapılmak istenen sınıfın nesnesi verilir.

Burada ilginç bir şey yapılır. `Runnable`'ı gerçekleyen ayrı bir adlı sınıf yazılıp nesnesi burada oluşturulabilirdi. Ama bu nesne yalnız tek bir yerde kullanılacağı için sınıfa ad verip ayrıca tanımlamak yerine `new Runnable() { ... }` yazılır. Bu, `Runnable` arayüzünü gerçekleyen bir sınıf olacağını söyler; süslü parantezin içine de sınıfa normalde konacak her şey konur. Böylece bir arayüzden yola çıkarak ad vermeden bir sınıf tanımlanır (adsız ya da anonim sınıf) ve nesnesi yalnız orada kullanılır. Sınıf `Runnable`'ı gerçeklediği için içinde mutlaka `run` metodu bulunur.

> **Hocanın vurgusu:** Bir arayüzü kullanarak ad vermeden bir sınıf tanımlamak ve nesnesini oluşturmak önemlidir; bununla sınavda karşılaşabilirsiniz. `new` sözcüğünden sonra arayüzün adı yazılır, süslü parantezin içine o sınıfta tanımlanması gereken her şey konur.

## 7. Panel ve Çizim: NotHelloWorld Örneği

`NotHelloWorld` sınıfı yukarıdaki kalıbı kullanır (ekrandan, 00:35:00):

```java
package oop08;

import javax.swing.*;
import java.awt.*;
public class NotHelloWorld {
    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            public void run() {
                NotHelloWorldFrame frame = new NotHelloWorldFrame();
                frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                frame.setVisible(true);
            }
        });
    }
}
```

`run` içindekiler önceki örneklerden tanıdıktır: bir çerçeve nesnesi oluşturulur, X'e basılınca kapanması ve görünür olması söylenir. Buradaki tek yenilik adsız sınıftır. `EventQueue`, iş parçacığı oluşturmaya yardım eden ve statik metotlar içeren bir sınıftır; `invokeLater` ile istenen iş parçacığı çalıştırılır.

`NotHelloWorldFrame` da `JFrame`'i genişletir. Kurucusunda `setTitle` ile başlık ve `setSize` ile boyut verilir. Ardından bir `NotHelloWorldPanel` nesnesi oluşturulur ve çerçevenin `add` metoduyla panel çerçevenin üzerine konur. <!-- BELİRSİZ: NotHelloWorldFrame sınıfının kodu karelerde görünmüyor; başlık ve boyut değerleri bilinmiyor. -->

Panel sınıfı ilk kez burada görülür (ekrandan, 00:40:00):

```java
package oop08;
import javax.swing.*;
import java.awt.*;
//A component that displays a message.
@SuppressWarnings("serial")
public class NotHelloWorldPanel extends JPanel {
    public void paintComponent(Graphics g){
        super.paintComponent(g);
        g.drawString("Not a Hello, World program", 60, 80);
    }
}
```

<!-- BELİRSİZ: Karede ikinci import satırı daraltılmış görünüyor; Graphics kullanıldığı için java.awt importu olmalıdır. -->

`paintComponent` panelin üzerine ne çizileceğini ya da yazılacağını belirleyen metottur. `Graphics` türünde bir nesne alır. Metot içinde önce üst sınıfın `paintComponent` metodu aynı girdiyle çağrılır, sonra `Graphics` sınıfının `drawString` metoduyla panelin üzerine bir metin yazılır. `Graphics` sınıfının başka metotlarıyla panele başka şeyler de çizdirilebilir.

> **Ders sonrası not:** Hoca `JPanel`'in soyut (abstract) bir sınıf olduğunu ve `paintComponent`'in soyut bir metot olarak mutlaka gerçeklenmesi gerektiğini söyledi; benzer biçimde `JFrame` için de "abstract sınıf" dedi. Doğrusu: `JFrame` ve `JPanel` somut sınıflardır (derste `new JPanel()` ile doğrudan nesne de oluşturuldu). `paintComponent`, `JComponent`'te gövdesi olan `protected` bir metottur; panele kendi çizimimizi yapmak istediğimizde geçersiz kılınır (override), zorunlu değildir. Geçersiz kılarken önce `super.paintComponent(g)` çağırmak arka planın doğru boyanması için doğru alışkanlıktır.

Hoca örneği çalıştırdı: çerçevenin içinde bir panel, panelin içinde de yazılan metin göründü.

## 8. Çerçevenin Diğer Metotları ve Ara Toparlama

`JFrame` üst sınıflarından gelen başka metotlar da sağlar:

- `setResizable`: pencerenin yeniden boyutlandırılabilir olup olmadığı. <!-- BELİRSİZ: Altyazıda "setRecyple" geçiyor; büyük olasılıkla setResizable. -->
- `setExtendedState`: çerçevenin bütün ekranı kaplaması, simge durumuna getirilmesi, yatayda ya da dikeyde büyütülmesi gibi durumlar bu metotla ayarlanır.
- `setLocation`: derste kullanıldı.
- `repaint`: yeniden çizim.
- `add`: panel eklemek için kullanıldı. Bunun dışında `setContentPane` metodu da vardır.

Bu noktaya kadar görülenler: çerçeve ve panel; bir çerçevenin iş parçacığı olarak nasıl oluşturulacağı; statik metotlu yardımcı sınıflar (`Toolkit`) ile `Dimension` ve `Image` sınıfları; `Runnable`'ın adsız sınıfla nesnesini oluşturup `EventQueue.invokeLater`'a vermek; bir paneli `JPanel`'den türetip `paintComponent` içinde `Graphics` metotlarıyla yazı yazdırmak ve paneli çerçeveye eklemek.

## 9. Java ile Olay Yönetimi

Şimdiye kadarki örneklerde kullanıcıyla hiç etkileşim olmadı: klavyeden ya da fareden bir girdi alınmadı, yalnız kodlanan şey kullanıcıya gösterildi. Kullanıcıyla etkileşim için olay yönetimi (event handling) gerekir.

Klavye, dokunmatik ekran ya da fare gibi dış kaynaklarla bir şey girildiğinde makinedeki işletim sistemi bu kaynaklardan gelen olayları yakalar. İşletim sistemi üzerinde yazılan programlar, işletim sisteminin olay yönetimiyle ilgili sistem çağrılarını kullanarak bu olayları kendileri de yakalayabilir. Java bu sistem çağrıları için kütüphaneler sağlar. Bunlar `java.awt.event` paketinde, yani Swing'in kalıtım hiyerarşisindeki üst sınıflardan birinin bulunduğu AWT altındadır.

Bundan sonra panelin içine bileşenler konacak: bir düğme (button), bir metin kutusu (text box) gibi. Çerçevenin ya da panelin kendisi de bir olay kaynağı olabilir. Bu bileşenlere dinleyiciler (event listener) eklenir.

Slayttaki ifade şöyledir (slayt 18, ekrandan, 00:50:00):

- Farklı türde olay kaynakları farklı türde olaylar üretir:
  - `JButton`, `JCheckBox` gibi GUI bileşenleri.
  - İşletim sisteminin kendisi: fare ve klavye olayları vb.
- Olay dinleyicileri tercih ettikleri olayları dinler:
  - Dinleyiciler `java.util.EventListener` arayüzünün `java.awt.event` paketindeki alt arayüzlerini gerçeklemelidir.
  - Olayları işleyen kod bu arayüzlerde tanımlı metotlara yazılır.
- Programcı olay kaynaklarını olay dinleyicileriyle ilişkilendirir. Genel biçim:
  - `eventSourceObj.addEventNameListener(aListenerObj);`

Sürekli görülecek yapı şudur: bir bileşen olur, bu bileşene bir dinleyici eklenir; `EventName` yazan kısma dinlenecek olayın adı gelir; ekleme metodu dinleyici nesnesini girdi olarak alır. Bir bileşene sıfır ya da birden çok dinleyici eklenebilir. Dinleyiciler o bileşen üzerinde kullanıcı etkileşimiyle oluşan olayları dinler ve olay gerçekleşince yapılması gereken işi yapar. Örneğin `ActionListener` `actionPerformed` metodunu içerir; arayüzü gerçekleyen sınıf bu metodu yazmak zorundadır ve olay olunca yapılacak iş bu metoda yazılır.

Olay türlerine örnekler:

- **Key event:** klavyede bir tuşa basılınca oluşur.
- **Window event:** pencerenin üzerindeki kare, X ya da çizgi işaretlerine basarak küçültme, büyütme, geri yükleme, kapatma.
- **Mouse event:** fare olayları.
- **Action event:** bir düğmeye basılınca oluşur.

Dinleyicilere örnekler: `ActionListener` bir düğme bileşenine bağlanabilir ve oradaki bütün eylemleri dinler. `WindowListener`, `WindowFocusListener`, `WindowStateListener` bir çerçeveye bağlanabilir ve o çerçevede oluşan olayları dinler.

Slayttaki örnekte olay kaynağı Swing'in `JButton` sınıfıdır; ona bağlanan dinleyici `ActionListener`'dır ve `ActionEvent` türündeki olayları dinler. Düğmede bir olay gerçekleşince `actionPerformed` metodu çalışır ve gerçekleşen `ActionEvent` nesnesini girdi olarak alır.

## 10. Düğme Olayları: ButtonTest

Hoca örneği doğrudan kod üzerinde gösterdi (ekrandan, 00:55:00, 01:00:00 ve 01:05:00). `java.awt`, olay yönetimi yapılacağı için `java.awt.event` ve `javax.swing` paketleri içe aktarılır. `main` içinde arayüz yine iş parçacığı olarak, `EventQueue.invokeLater` ve adsız `Runnable` sınıfıyla yaratılır; `run` içinde bir `ButtonFrame` nesnesi oluşturulur, kapanma işlemi ve görünürlük ayarlanır.

```java
package oop09;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class ButtonTest {
    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            public void run() {
                ButtonFrame frame = new ButtonFrame();
                frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                frame.setVisible(true);
            }
        });
    }
}

@SuppressWarnings("serial")
class ButtonFrame extends JFrame {
    private JPanel buttonPanel;
    public static final int DEFAULT_WIDTH = 300;
    public static final int DEFAULT_HEIGHT = 200;

    public ButtonFrame() {
        setTitle("ButtonTest");
        setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);

        // create buttons
        JButton yellowButton = new JButton("Yellow");
        JButton blueButton = new JButton("Blue");
        JButton redButton = new JButton("Red");

        buttonPanel = new JPanel();

        // add buttons to panel
        buttonPanel.add(yellowButton);
        buttonPanel.add(blueButton);
        buttonPanel.add(redButton);

        // add panel to frame
        add(buttonPanel);

        // create button actions (listeners)
        ColorAction yellowAction = new ColorAction(Color.YELLOW);
        ColorAction blueAction = new ColorAction(Color.BLUE);
        ColorAction redAction = new ColorAction(Color.RED);

        // associate actions with buttons
        yellowButton.addActionListener(yellowAction);
        blueButton.addActionListener(blueAction);
        redButton.addActionListener(redAction);
    } //end of ButtonFrame constructor.

    //An action listener that sets the panel's background color.
    private class ColorAction implements ActionListener {
        private Color backgroundColor;
        public ColorAction(Color c){ backgroundColor = c; }
        public void actionPerformed(ActionEvent event){
            buttonPanel.setBackground(backgroundColor);
        }
    }/* coded as an inner class. You can write an alternative
        version with regular classes (ButtonTestV2) */
}
```

(Kod karedeki gibidir; yalnız slayt bölme yorumları "continues in the next slide" çıkarıldı. Ajan bu kodu `java ButtonTest.java` ile ekransız ortamda derledi; pencere açılamadığı için çalışma anında `HeadlessException` alındı, arayüz davranışı denenemedi.)

### 10.1 Çerçeve ve panel

Çerçevenin içine bir panel konacağı için panel global bir alan (`buttonPanel`) olarak tanımlanır. Kurucuda başlık ve boyut verildikten sonra ilk kez panelin içine bileşenler konmaya başlanır: Swing'in `JButton` sınıfıyla "Yellow", "Blue" ve "Red" adlı üç düğme nesnesi oluşturulur. Ardından panel nesnesi oluşturulur ve düğmeler `add` ile tek tek panele eklenir. Son olarak panel, çerçevenin `add` metoduyla (bu metot `JFrame`'den gelir) çerçeveye eklenir.

Hoca sırayı şöyle özetledi: önce panel oluşturulur, içine konacak bileşenler konur, sonra panel çerçeveye eklenir. Hoca çerçeveye arayüz bileşenlerinin doğrudan eklenemediğini, yalnız panelin eklenebildiğini söyledi.

> **Ders sonrası not:** Hoca bileşenlerin çerçeveye doğrudan eklenemediğini söyledi. Doğrusu: `JFrame.add(bilesen)` çağrısı bileşeni çerçevenin içerik bölmesine (content pane) ekler ve çalışır. Bileşenleri bir panelde toplayıp paneli çerçeveye eklemek ise yerleşimi düzenlemek için yaygın ve önerilen yoldur.

### 10.2 Dinleyiciler

Dinlenmek istenen olayları üreten kaynaklar düğmelerdir; bu yüzden düğmelere dinleyici eklenir. Dinleyici `ActionListener` türündedir. Bunun için çerçevenin içinde ayrı bir iç sınıf (inner class) tanımlanır: `ActionListener`'ı gerçekleyen `ColorAction`. Bu sınıfın üç nesnesi (`yellowAction`, `blueAction`, `redAction`) oluşturulur; her biri ayrı bir dinleyicidir ve bir düğmeyi dinleyecektir.

`ColorAction` programcı tarafından yazıldığı için, olay yakalanınca nasıl davranacağını belirleyen parametre de programcı tarafından tanımlanmıştır: ekranın rengini değiştiren bir dinleyici istendiği için kurucuya `Color` türünde bir nesne verilir.

Dinleyiciler `addActionListener` ile düğmelere bağlanır. Genel biçimdeki `EventName` yerine burada `Action` gelir; metot adı `addActionListener` olur ve girdi olarak dinleyici nesnesi verilir.

`actionPerformed` olmazsa olmaz metottur, çünkü `ActionListener` arayüzü bunu gerçeklemeyi zorunlu kılar. Bir eylem olayı gerçekleşince bu metot çalışır ve panelin arka planını kurucuya verilen renkle değiştirir. `buttonPanel` çerçevenin global alanı olduğundan ve `ColorAction` çerçevenin iç sınıfı olduğundan, `actionPerformed` içindeki çağrı doğrudan bu panelin `setBackground` metodunu çağırır. Koddaki yorum, aynı örneğin iç sınıf yerine sıradan sınıflarla yazılmış bir sürümünün (`ButtonTestV2`) olduğunu söyler.

### 10.3 Çalıştırma

Hoca örneği çalıştırdı: çerçevede bir panel, panelde üç düğme (Yellow, Blue, Red) göründü (ekrandan, 01:05:00). Her düğmenin üzerinde ayrı bir `ColorAction` dinleyici nesnesi vardır. Bir düğmeye basılınca işletim sistemi eylem olayını yakalar; program da `java.awt.event` kütüphanesinin sağladığı `ActionListener` ile bu olayı yakalar ve `actionPerformed` metodunda yapılması gerekeni yapar: panelin arka planı sarı, mavi ya da kırmızı olur.

## 11. Pencere Olayları: WindowEventTest

Aynı şey bu sefer düğme yerine çerçeve bileşeni için yapılır. Slayttaki başlık: "Pencere olaylarını işlemeye çalışan bir örnek: kod `oop09.WindowEventTest`; `WindowListener` ve `WindowStateListener` arayüzleri gerçeklenmiştir" (slayt 25, ekrandan, 01:10:00):

```java
package oop09;
import java.awt.EventQueue;
import java.awt.event.*;
import javax.swing.*;

public class WindowEventTest {
    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            public void run() {
                CaptureWindowEventsFrame frame =
                new CaptureWindowEventsFrame();
                frame.setVisible(true);
            }
        });
    }
}
//continues in the next slide.
```

### 11.1 Çerçeve ve iki dinleyici

`CaptureWindowEventsFrame` `JFrame`'i genişletir. Bu sınıfta bir seri numarası (`serialVersionUID`) verildiği için `@SuppressWarnings` eklenmemiştir. Genişlik ve yükseklik tanımlanır; kurucuda başlık ve boyut ayarlanır.

Düğme örneğinde dinleyici, düğme nesnesine `addActionListener` ile eklenmişti. Burada ise çerçevenin kalıtımla aldığı `addWindowListener` metodu kullanılır ve ayrı bir sınıf olan `MyWindowListener`'ın nesnesi eklenir. İkinci bir dinleyici de `addWindowStateListener` ile eklenir: `MyWindowStateListener` nesnesi. Böylece bir olay kaynağına birden çok dinleyici eklenmiş olur. Kaynak çerçevedir; çerçevede oluşan olayların türü `WindowEvent`'tir.

Kurucunun son satırları karede şöyle görünür (ekrandan, 01:25:00):

```java
        //addWindowListener( new MyWindowListener( ) );
        addWindowListener( new MyWindowAdapter( ) );
        addWindowStateListener( new MyWindowStateListener( ) );
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
```

<!-- BELİRSİZ: Hoca anlatırken MyWindowListener nesnesinin eklendiğini söyledi; karede ise bu satır yorum satırı, yerine MyWindowAdapter ekleniyor. Satırın ne zaman değiştirildiği ve MyWindowAdapter sınıfının içeriği altyazı ve karelerden çıkmıyor. -->

### 11.2 MyWindowListener: yedi zorunlu metot

`ActionListener` bir düğmedeki tıklamaları izler; `WindowListener` ise bir pencerede, bir çerçevede oluşabilecek olayları izler. Arayüzü gerçekleyen sınıf, arayüzde tanımlı bütün metotları yazmak zorundadır. `WindowListener`'da yedi metot vardır; belki yalnız biri ya da ikisi kullanılacaktır, ama arayüz gerçeklendiği için hepsi sınıfta bulunmak zorundadır (slayt 27, ekrandan, 01:20:00):

```java
class MyWindowListener implements WindowListener {
    public void windowOpened(WindowEvent e) {
        System.out.println("Window has been opened");
    }
    public void windowClosing(WindowEvent e) {
        System.out.println("Window is to be closed");
    }
    public void windowClosed(WindowEvent e) {
        System.out.println("Window is closed");
    }
    public void windowActivated(WindowEvent e) {
        System.out.println("Window has gained focus");
    }
    public void windowDeactivated(WindowEvent e) {
        System.out.println("Window has lost the focus");
    }
    public void windowIconified(WindowEvent e) {
        System.out.println("Window is minimized");
    }
    public void windowDeiconified(WindowEvent e) {
        System.out.println("Window is de-minimized");
    }
}//continues in the next slide.
```

### 11.3 MyWindowStateListener

İkinci dinleyici `WindowStateListener`'ı gerçekleyen sıradan (regular) bir sınıftır. Arayüzden gelen `windowStateChanged` metodunu yazmak zorundadır. Bir pencere durum değişikliği olayı yakalandığında eski ve yeni durumu ekrana yazar (ekrandan, 01:25:00):

```java
/**
 * Meaning of returns from WindowEvent.getOldState()
 * and WindowEvent.getNewState() methods:
 * Frame.NORMAL (0), Frame.ICONIFIED (1) ,
 * Frame.MAXIMIZED_HORIZ (4), Frame.MAXIMIZED_VERT (...)
 * Frame.MAXIMIZED_BOTH (6=4+2)
 */
class MyWindowStateListener implements WindowStateListener {
    public void windowStateChanged( WindowEvent e ) {
        System.out.print( "Old state: " + e.getOldState() );
        System.out.println( ", New state: " + e.getNewState() );
    }
}
```

<!-- BELİRSİZ: Karede satırların sağ ucu kesik; MAXIMIZED_VERT değeri ve ikinci print satırının sonu okunamıyor. İkinci satır konsol çıktısına ("Old state: 0, New state: 1") göre tamamlandı. -->

> **Ders sonrası not:** Koddaki yorumda `Frame.MAXIMIZED_HORIZ (4)` yazıyor. Doğrusu: `Frame.MAXIMIZED_HORIZ` 2, `Frame.MAXIMIZED_VERT` 4'tür; `MAXIMIZED_BOTH` bunların toplamı olan 6'dır. `NORMAL` 0, `ICONIFIED` 1'dir (ajan `java` ile sabitleri yazdırarak denedi).

### 11.4 Çalıştırma

Hoca örneği çalıştırıp konsola bakılmasını istedi. Pencere ilk açıldığında `System.out.println` iletisi yazıldı. Pencere simge durumuna küçültülünce durum değiştiği için "Old state: 0, New state: 1" yazıldı; odak iletileri de ("Window has gained focus", "Window has lost the focus") konsola düştü (ekrandan, 01:25:00). Pencere eski hâline getirilince durum yeniden değişti ve odak yeniden kazanıldı. Böylece hem durum değişimi hem de penceredeki odak değişikliği yakalanıp yazdırılabildi. X'e basıldığında program doğrudan durduğu için bir şey yazılmadı.

## 12. Adaptör Sınıfları

`WindowEventTest`'te iki dinleyici vardı: biri pencere durum olaylarını, diğeri pencere olaylarını dinliyordu. `WindowListener` arayüzünde yedi metot tanımlı olduğu için, sıradan sınıfta yalnız ikisi kullanılsa bile diğerleri de yazılmak zorunda kalındı.

Dinleyici arayüzlerinde tanımlı çok sayıda metodun gereksiz olanlarının yazılmasını önlemek için `java.awt.event` paketinde adaptör sınıfları vardır. Adaptör sınıfları soyut (abstract) sınıflardır ve ilgili dinleyici arayüzünü gerçeklerler; yani her dinleyici arayüzü için bir soyut sınıf yazılmış ve arayüzün metotları bu sınıfta gerçeklenmiştir. Bir dinleyici sınıfı yazmak isteyen programcı, arayüzü gerçeklemek yerine ilgili adaptörü genişletir ve yalnız geçersiz kılmak (override) istediği metotları yazar. Diğerleri üst sınıfta gerçeklendiği için yeniden yazılmaları gerekmez. Hoca gösterdiği adaptör kullanımında iki metodun geçersiz kılındığını belirtti.

> **Ek bilgi (derste anlatılmadı):** Adaptör sınıflarındaki metotların gövdeleri boştur; yani geçersiz kılınmayan olaylar için hiçbir şey yapılmaz. Adaptörler yalnız birden çok metodu olan dinleyici arayüzleri için vardır (`WindowAdapter`, `MouseAdapter`, `KeyAdapter` gibi); tek metotlu `ActionListener` için bir adaptör yoktur. Java sınıf olarak tek kalıtıma izin verdiği için, zaten başka bir sınıfı genişleten bir sınıf adaptör kullanamaz ve arayüzü gerçeklemek zorunda kalır.

**Soru:** Bu adaptör sınıflarının Adapter (adaptör) tasarım kalıbıyla bir ilgisi var mı?

**Cevap:** Hayır. Yalnız böyle bir ad verilmiş.

## 13. Fare Olayları: MouseEventsTest

Şimdiye kadar çerçevedeki olaylar (pencere olayları) ve bir düğmedeki olaylar (eylem olayları) dinlendi. Şimdi fareden gelebilecek olaylar konuşulur: `MouseEvent` ve fare hareketi olayları (ekrandan, 01:30:00).

```java
package oop09;

import java.awt.*;
// (diğer importlar karede daraltılmış)

public class MouseEventsTest {
    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable() {
            public void run() {
                CaptureMouseEventsFrame frame = new CaptureMouseEventsFrame();
                frame.setVisible(true);
            }
        });
    }
}

@SuppressWarnings("serial")
class CaptureMouseEventsFrame extends JFrame {
    public static final int DEFAULT_WIDTH = 300;
    public static final int DEFAULT_HEIGHT = 200;
    public CaptureMouseEventsFrame(){
        setTitle("CaptureMouseEventsTest");
        setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
        addMouseListener( new MouseHandler() );
        addMouseMotionListener( new MouseMotionHandler() );
    }
}
class MouseMotionHandler implements MouseMotionListener {
    public void mouseDragged(MouseEvent event) {
        double x,y;
        x = event.getPoint().getX();
        y = event.getPoint().getY();
        System.out.println("A mouse drag at ("+x+","+y+")");
    }
    public void mouseMoved(MouseEvent event) {
        double x,y;
        x = event.getPoint().getX();
        y = event.getPoint().getY();
        System.out.println("A mouse move at ("+x+","+y+")");
    }
}
class MouseHandler extends MouseAdapter {
    public void mouseClicked(MouseEvent event) {
        double x,y;int z, e;
        x = event.getPoint().getX(); y = event.getPoint().getY();
        // ... (devamı karede görünmüyor)
    }
}
```

<!-- BELİRSİZ: MouseHandler.mouseClicked gövdesinin devamı karede görünmüyor; karede yalnız tıklama sayısı ve değiştirici tuşların okunduğu satırın başı seçiliyor. -->

Ana sınıf `MouseEventsTest` çerçeve nesnesini yine bir iş parçacığı nesnesi olarak oluşturur. Çerçeve `CaptureMouseEventsFrame`'in kurucusunda başlık ve boyut ayarlanır ve çerçeveye iki dinleyici eklenir: fare dinleyicisi ve fare hareketi dinleyicisi. Böylece pencere olaylarını çerçeve üzerinden dinlediğimiz gibi, fare tıklamaları da çerçeve bileşeni üzerinden dinlenir.

`MouseMotionHandler` `MouseMotionListener` arayüzünü gerçekler. Bu arayüzde iki metot vardır: `mouseDragged` ve `mouseMoved`. İkisi de fare hareket ederken hangi X, Y koordinatlarından geçtiğini `System.out.println` ile yazar.

`MouseHandler` ise ilgili arayüzü gerçeklemek yerine onu gerçeklemiş olan adaptörü, `MouseAdapter` soyut sınıfını genişletir. Arayüzde çok sayıda olay ve dolayısıyla çok sayıda metot olduğu için yalnız istenen metot yazılır: `mouseClicked`. Bu metotta farenin Ctrl, Alt, Shift gibi özel tuşlarla birlikte ya da sol tıkla kullanılmasına göre ayrı ayrı ileti yazdırılır.

Çalıştırıldığında çerçevenin üzerinde fare gezdirildikçe konsolda farenin konumu göründü. Ctrl ile ve Shift ile tıklandığında, tıklamanın hangi özel tuşla yapıldığı da yakalandı.

## 14. Klavye Olayları: KeyboardEventTest

Son örnek klavye olaylarını dinler (ekrandan, 01:35:00). Yine bir çerçeve iş parçacığı olarak oluşturulur ve çerçeveye iki dinleyici eklenir: biri özel tuşlar, biri normal tuşlar için.

```java
        setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
        addKeyListener(new SpecialKeyHandler() );
        addKeyListener(new KeyHandler() );
    }
}

class KeyHandler implements KeyListener {
    int lastKey; char lastChar; static String keyText;
    public void keyPressed(KeyEvent event) {
        int keyCode = event.getKeyCode();
        if( keyCode != lastKey ) {
            System.out.print( "Key pressed, code: " + keyCode );
            lastKey = keyCode;
        }
    }
    public void keyReleased(KeyEvent event) {
        int keyCode = event.getKeyCode();
        System.out.println( "\nKey released, logical code: " +      KeyEvent.getKeyText(keyCode) );
    }
    public void keyTyped(KeyEvent event) {
        char keyChar = event.getKeyChar();
        if( keyChar != lastChar ) {
            System.out.print( "\nKey typed: " + keyChar );
            lastChar = keyChar;
        }
        else
            System.out.print( keyChar );
    }
}
class SpecialKeyHandler extends KeyAdapter {
    public void keyTyped(KeyEvent event) {
        if( event.isShiftDown() )
            System.out.print("***Shift key is used***");
        if( event.isControlDown() )
            System.out.print("***Control key is used***");
        if( event.isAltDown() )
            System.out.print("***Alt key is used***");
        if( event.isAltGraphDown() )
            System.out.print("***AltGR key is used***");
        if( event.isMetaDown() )
            System.out.print("***Meta key is used***");
    }
}
```

<!-- BELİRSİZ: KeyboardEventTest'in ana sınıfı ve çerçeve sınıfının başı karede görünmüyor. -->

Normal tuşlar için kullanılan `KeyHandler` `KeyListener` arayüzünü gerçekler; burada adaptör kullanılmamıştır. Bu yüzden üç metot yazılmak zorundadır: bir tuşa basıldığında (`keyPressed`), tuş bırakıldığında (`keyReleased`) ve bir karakter yazıldığında (`keyTyped`) oluşan olaylar yakalanır.

Özel tuşlar için kullanılan `SpecialKeyHandler` ise `KeyListener`'ı gerçeklemiş olan adaptörü, `KeyAdapter`'ı genişletir ve yalnız bir metot yazar: özel bir tuş kullanıldığında olayı yakalayan `keyTyped`. Böylece aynı örnekte hem dinleyici arayüzünü gerçekleme hem de adaptör genişletme kullanımı görülür.

Çalıştırıldığında herhangi bir tuşa basılınca ilgili iletiler göründü. F tuşuna basılınca F yakalandı; Ctrl+F'ye basılınca özel tuşla birlikte basıldığı için bu da yakalandı.

Ajan `KeyHandler`, `SpecialKeyHandler` ve `MouseMotionHandler` sınıflarını `java` ile ekransız ortamda derledi ve elle üretilen olaylarla çağırdı: F tuşu için "Key pressed, code: 70", "Key typed: f", "Key released, logical code: F"; Ctrl ile yazılan karakter için "\*\*\*Control key is used\*\*\*" yazıldı.

## Örnek Sorular

**1.** (derste sözlü, 01:28:41) `java.awt.event` paketindeki `WindowAdapter`, `MouseAdapter`, `KeyAdapter` gibi adaptör sınıflarının Adapter tasarım kalıbıyla ilgisi var mı?

> **Cevap (derste verildi):** Hayır, yalnız böyle adlandırılmışlar. Bu sınıflar, çok metotlu bir dinleyici arayüzünü gerçekleyen soyut sınıflardır; programcı adaptörü genişletip yalnız gereken metotları geçersiz kılar.

**2.** (ekrandan, 01:25:00) `WindowEventTest`'te pencere simge durumuna küçültüldüğünde `MyWindowStateListener` ne yazar?

> **Cevap (derste verildi):** "Old state: 0, New state: 1". Pencere normal durumdan (`Frame.NORMAL`, 0) simge durumuna (`Frame.ICONIFIED`, 1) geçmiştir. Aynı anda `MyWindowListener`/adaptör tarafındaki odak iletileri de yazılır.

## Dersin Toparlaması

Bu derste Java'da Swing ile grafik kullanıcı arayüzü geliştirmenin temelleri işlendi. Swing, AWT'ye dayanan ve MVC kalıbını gerçekleyen bir pakettir; sınıfları `J` ile başlar. `JFrame` en dış kap, `JPanel` çerçevenin üzerindeki kaptır; bileşenler panele, panel çerçeveye eklenir. `SimpleWindow` ve `SizedWindowWithIcon` örnekleriyle `JFrame`'den gelen `setSize`, `setLocation`, `setTitle`, `setIconImage`, `setDefaultCloseOperation`, `setVisible` metotları ve AWT'nin `Toolkit`, `Dimension`, `Image` sınıfları görüldü. Arayüzün `EventQueue.invokeLater` ile olay dağıtım iş parçacığında başlatılması ve bunun için kullanılan adsız `Runnable` sınıfı vurgulandı; `NotHelloWorld` örneğinde panelin `paintComponent` metodunda `Graphics.drawString` ile yazı yazdırıldı.

Dersin ikinci kısmında olay yönetimi işlendi: olay kaynağı, olay nesnesi ve dinleyici; `kaynak.addXxxListener(dinleyici)` biçimi. Düğme olayları (`ActionListener`, iç sınıf `ColorAction`), pencere olayları (`WindowListener`'ın yedi metodu ve `WindowStateListener`), fare olayları (`MouseMotionListener`, `MouseAdapter`) ve klavye olayları (`KeyListener`, `KeyAdapter`) örneklerle çalıştırıldı. Çok metotlu dinleyici arayüzlerinde gereksiz metotları yazmamak için soyut adaptör sınıflarının genişletildiği gösterildi. Hoca, bundan sonraki konunun Swing'de yerleşim yönetimi (layout management) olduğunu söyledi.

**Not:** İsterseniz bu kayıtları Gemini Notebook gibi bir araca atıp daha istifadeli hale getirebilirsiniz.
