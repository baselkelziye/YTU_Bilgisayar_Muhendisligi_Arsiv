# Ders 22 Çalışma Özeti

## Genel Konular

- Java ile GUI programlama ve Swing paketi
  - Java'da kullanıcı arayüzü (GUI) için hazır gelen paket `javax.swing`'dir. Slayttaki bilgiler (ekrandan, 00:15:00): Java 1.2'den beri kullanılan güncel pakettir, `java.awt` sınıflarına dayanır, sınıf adları `J` ile başlar (`javax.swing.JFrame` ile `java.awt.Frame` farklıdır, "J'yi unutmayın"). Eclipse vakfının SWT'si gibi üçüncü taraf paketler de vardır ama derste işlenmez.
  - Swing masaüstü tabanlı arayüz üretir. Java dünyasında web tabanlı arayüz üreten başka kütüphaneler de vardır (Java Server Faces, Java Server Pages gibi).
  - Swing'den önce AWT kütüphanesi vardı; Swing, AWT'nin bazı genel sınıflarını genişletir (extend eder).
- Tasarım kalıpları ve Model-View-Controller (MVC)
  - Tasarım kalıpları iyi bir yazılım tasarımı için şablonlar sunar ve kodun yeniden kullanılabilirliğini artırır. Örnekler: Singleton, Adapter, Facade, MVC.
  - Swing, MVC kalıbını gerçekler. Model ham veriyi (raw data) temsil eder; View bu verinin farklı görünüşlerini yönetir; Controller kullanıcının komutlarını karşılar ve buna göre veriyi okur ya da değiştirir. Üç bileşen birbirinden bağımsızdır.
- Swing kalıtım hiyerarşisi (slayt 6, ekrandan, 00:20:00)
  - `java.lang.Object` → `java.awt.Component` → `java.awt.Container`.
  - `Container` altında iki dal: `javax.swing.JComponent` → `javax.swing.JPanel` ve `java.awt.Window` → `java.awt.Frame` → `javax.swing.JFrame`.
  - Yukarıda tanımlı metotlar aşağıdaki bütün sınıflarca kullanılabilir.
  - İki tür kap (container) kullanılır: `JFrame` en alttaki çizim tahtasıdır; onun üzerine `JPanel` konur, kullanıcı arayüzü bileşenleri de panelin üzerine konur.
- Basit pencere: `SimpleWindow` (slayt 4, ekrandan, 00:25:00)
  - `JFrame`'i genişleten sınıf; `public static final int DEFAULT_WIDTH = 300;` ve `DEFAULT_HEIGHT = 200;` sabitleri, kurucuda `setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT)`.
  - `main` içinde nesne oluşturulur; `setTitle("A Simple Window")`, `setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE)`, `setVisible(true)` çağrılır. Bu metotların hepsi `JFrame`'den (üst sınıflardan) gelir.
  - `@SuppressWarnings("serial")`: `JFrame` serileştirilebilir olduğu için seri numarası (serialVersionUID) verilmezse derleyici uyarı verir; bu anotasyonla uyarı bastırılır.
  - Konum verilmediği için pencere ekranın sol üst köşesinde açılır.
- Ekrana göre boyut ve simge: `SizedWindowWithIcon` (ekrandan, 00:30:00)
  - `Toolkit kit = Toolkit.getDefaultToolkit();` ve `Dimension screenSize = kit.getScreenSize();` ile ekranın boyutu alınır; `screenSize.height` ve `screenSize.width` kullanılır.
  - `setSize(screenWidth / 2, screenHeight / 2)` pencereyi ekranın yarısı boyutunda yapar; `setLocation(screenSize.width / 4, screenSize.height / 4)` pencereyi ekranın ortasına yerleştirir.
  - `Image img = kit.getImage("icon.jpg"); setIconImage(img);` ile pencereye simge eklenir; `setTitle("A Sized Window With Icon")`.
  - Böylece AWT'den gelen `Toolkit`, `Dimension` ve `Image` sınıfları görülmüş olur.
- Swing'i doğru başlatma: olay dağıtım iş parçacığı (slayt 11, ekrandan, 00:45:00)
  - Swing bileşenleri karmaşıktır; GUI bileşenleri ayrı bir iş parçacığında, olay dağıtım iş parçacığında (event dispatch thread) başlatılmalıdır. Bu iş parçacığı fare tıklamaları ve tuş vuruşları gibi olayları arayüz bileşenlerine iletir.
  - Kalıp: `EventQueue.invokeLater(new Runnable() { public void run() { /* statements */ } });`
  - `new Runnable() { ... }` adsız (anonim) bir sınıftır: `Runnable` arayüzünü gerçekleyen, ad verilmeden tanımlanan ve nesnesi yalnız orada kullanılan sınıf. İçinde `run` metodu bulunmak zorundadır.
- Panel ve çizim: `NotHelloWorld` örneği (ekrandan, 00:35:00 ve 00:40:00)
  - `NotHelloWorld.main`, `invokeLater` ile bir `NotHelloWorldFrame` oluşturur, kapanma işlemini ve görünürlüğü ayarlar.
  - `NotHelloWorldFrame` kurucusunda başlık ve boyut verilir, bir `NotHelloWorldPanel` nesnesi oluşturulup `add` ile çerçeveye eklenir. <!-- BELİRSİZ: NotHelloWorldFrame kodu karelerde görünmüyor; ayrıntılar altyazıdan. -->
  - `NotHelloWorldPanel extends JPanel`; `paintComponent(Graphics g)` içinde önce `super.paintComponent(g);`, sonra `g.drawString("Not a Hello, World program", 60, 80);`.
- Çerçevenin diğer metotları
  - `setResizable`, `setExtendedState` (tam ekran, simge durumuna küçültme, yatay ya da dikey büyütme), `setLocation`, `repaint`, `add`, `setContentPane`. Hepsi üst sınıflardan gelir.
- Java ile olay yönetimi (event handling) (slayt 18, ekrandan, 00:50:00)
  - Klavye, fare, dokunmatik ekran gibi kaynaklardan gelen olayları işletim sistemi yakalar; Java'nın olay kütüphaneleri (`java.awt.event`) ile program da bu olayları yakalar.
  - Farklı olay kaynakları farklı olaylar üretir: `JButton`, `JCheckBox` gibi GUI bileşenleri; fare ve klavye olayları için işletim sistemi.
  - Dinleyiciler (listener) `java.util.EventListener`'ın `java.awt.event` paketindeki alt arayüzlerini gerçekler; olayı işleyen kod bu arayüzlerin metotlarına yazılır.
  - Genel biçim: `eventSourceObj.addEventNameListener(aListenerObj);`
  - Bir bileşene sıfır ya da birden çok dinleyici eklenebilir.
  - Olay türleri: `ActionEvent` (düğmeye basma), `WindowEvent` (küçültme, büyütme, geri yükleme, kapatma), `MouseEvent`, `KeyEvent`. Dinleyiciler: `ActionListener`, `WindowListener`, `WindowFocusListener`, `WindowStateListener` vb.
- Düğme olayları: `ButtonTest` (ekrandan, 00:55:00, 01:00:00, 01:05:00)
  - `ButtonFrame extends JFrame`; alan olarak `private JPanel buttonPanel;`. Kurucuda "Yellow", "Blue", "Red" adlı üç `JButton` oluşturulur, panele `add` ile eklenir, panel de çerçeveye eklenir.
  - Her düğme için bir `ColorAction` nesnesi (`Color.YELLOW`, `Color.BLUE`, `Color.RED`) oluşturulur ve `yellowButton.addActionListener(yellowAction);` biçiminde düğmeye bağlanır.
  - `ColorAction`, `ActionListener`'ı gerçekleyen bir iç sınıftır (inner class); kurucusu rengi alır, `actionPerformed(ActionEvent event)` içinde `buttonPanel.setBackground(backgroundColor);` çağrılır. İç sınıf olduğu için dış sınıfın `buttonPanel` alanına doğrudan erişir.
  - Düğmeye basılınca panelin arka planı o renge döner.
- Pencere olayları: `WindowEventTest` (slayt 25 ve 27, ekrandan, 01:10:00, 01:20:00, 01:25:00)
  - `CaptureWindowEventsFrame` kurucusunda `addWindowListener(...)` ve `addWindowStateListener(new MyWindowStateListener())` ile çerçeveye iki dinleyici eklenir.
  - `MyWindowListener implements WindowListener`: arayüzdeki yedi metodun hepsi yazılmak zorundadır: `windowOpened`, `windowClosing`, `windowClosed`, `windowActivated`, `windowDeactivated`, `windowIconified`, `windowDeiconified`. Her biri konsola bir ileti yazar.
  - `MyWindowStateListener implements WindowStateListener`: tek metodu `windowStateChanged(WindowEvent e)`; eski ve yeni durumu `e.getOldState()` ve `e.getNewState()` ile yazar.
  - Pencere küçültülünce konsolda "Old state: 0, New state: 1" ve odak iletileri görüldü (ekrandan, 01:25:00).
- Adaptör sınıfları
  - Bir dinleyici arayüzünü gerçekleyen sınıf, kullanmadığı metotları da yazmak zorundadır. Bunu önlemek için `java.awt.event` paketinde her çok metotlu dinleyici arayüzü için bir soyut adaptör sınıfı vardır (`WindowAdapter`, `MouseAdapter`, `KeyAdapter`). Adaptör arayüzü gerçekler; programcı adaptörü genişletir ve yalnız istediği metotları geçersiz kılar (override).
  - Bu sınıfların Adapter tasarım kalıbıyla ilgisi yoktur, yalnız adları öyledir.
- Fare olayları: `MouseEventsTest` (ekrandan, 01:30:00)
  - `CaptureMouseEventsFrame` kurucusunda `addMouseListener(new MouseHandler())` ve `addMouseMotionListener(new MouseMotionHandler())`.
  - `MouseMotionHandler implements MouseMotionListener`: `mouseDragged` ve `mouseMoved` metotları `event.getPoint().getX()` ve `getY()` ile koordinatları yazar.
  - `MouseHandler extends MouseAdapter`: yalnız `mouseClicked` geçersiz kılınır; tıklamanın Ctrl, Alt, Shift gibi özel tuşlarla ya da sol tuşla yapılmasına göre farklı ileti yazar. <!-- BELİRSİZ: mouseClicked gövdesinin tamamı karede görünmüyor. -->
- Klavye olayları: `KeyboardEventTest` (ekrandan, 01:35:00)
  - Çerçeveye `addKeyListener(new SpecialKeyHandler())` ve `addKeyListener(new KeyHandler())` eklenir.
  - `KeyHandler implements KeyListener`: üç metot zorunludur: `keyPressed` (tuş kodu), `keyReleased` (`KeyEvent.getKeyText` ile mantıksal ad), `keyTyped` (yazılan karakter).
  - `SpecialKeyHandler extends KeyAdapter`: yalnız `keyTyped` geçersiz kılınır; `isShiftDown`, `isControlDown`, `isAltDown`, `isAltGraphDown`, `isMetaDown` ile özel tuşlar denetlenir.
  - Aynı örnekte hem arayüz gerçekleme hem de adaptör genişletme birlikte görülür.

## Hocanın Özellikle Vurguladığı Kısımlar

- Yeniden kullanılabilirlik
  - Bir sınıfta işi yapan bir metot zaten varsa aynı kodu başka metotta tekrar yazmayın. Örneğin bir veri yapısına ekleme yapan `add` metodu, nesnenin yapıda olup olmadığını denetlemek için aynı sınıftaki `search` metodunu çağırmalı, aramayı yeniden kodlamamalıdır. Hoca sınavlarda bu yeniden kullanımın beklendiğini söyledi.
- Adsız (anonim) sınıf
  - Bir arayüzden (`Runnable`) ad vermeden sınıf tanımlayıp nesnesini oluşturmak önemlidir; hoca bununla sınavda karşılaşılabileceğini söyledi.
- Bileşen, panel ve çerçeve sırası
  - Önce panel oluşturulur, bileşenler panele eklenir, panel de çerçeveye eklenir. Hoca bileşenlerin çerçeveye doğrudan eklenemediğini söyledi (bkz. ders sonrası not).
- Dinleyici arayüzü gerçeklenince bütün metotları yazılmalıdır
  - `WindowListener` yedi metot içerir; yalnız biri ya da ikisi kullanılsa bile hepsi yazılmalıdır. Adaptör sınıfları bu zorunluluğu kaldırır.

## Kısa Tekrar Notları

- Swing sınıf adları `J` ile başlar; `JFrame` en dış kap, `JPanel` onun üzerindeki kap, bileşenler panelin üzerindedir.
- `JFrame` üzerinden gelen metotlar: `setTitle`, `setSize`, `setLocation`, `setIconImage`, `setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE)`, `setVisible(true)`, `setExtendedState`, `add`.
- `Toolkit.getDefaultToolkit().getScreenSize()` ekran boyutunu `Dimension` olarak verir; `getImage` ile `Image` alınır.
- GUI, `EventQueue.invokeLater(new Runnable() { public void run() { ... } });` ile olay dağıtım iş parçacığında başlatılır.
- Panele çizim için `paintComponent(Graphics g)` geçersiz kılınır, önce `super.paintComponent(g)` çağrılır, `g.drawString(...)` ile yazı yazılır.
- Olay bağlama biçimi: `kaynak.addXxxListener(dinleyiciNesnesi)`.
- `ActionListener` → `actionPerformed`; `WindowListener` → 7 metot; `WindowStateListener` → `windowStateChanged`; `MouseMotionListener` → `mouseDragged`, `mouseMoved`; `KeyListener` → `keyPressed`, `keyReleased`, `keyTyped`.
- Adaptör (`WindowAdapter`, `MouseAdapter`, `KeyAdapter`) soyut sınıftır; genişletilir, yalnız gereken metot geçersiz kılınır.

## Detaylı Açıklamalar

- Swing'de bir pencere oluşturmak için `JFrame`'i genişleten bir sınıf yazılır. Bu sınıf kendi kodunda `setTitle` ya da `setSize` tanımlamasa da bu metotları kullanabilir, çünkü bunlar kalıtım hiyerarşisinde (`Component`, `Container`, `Window`, `Frame`, `JFrame`) yukarıdan gelir. İlk örnek `SimpleWindow`'da boyut sabitlerle (300 x 200) verilir; pencerenin konumu söylenmediği için pencere ekranın sol üst köşesinde açılır. İkinci örnek `SizedWindowWithIcon`'da boyut ekranın boyutundan hesaplanır: genişlik ve yükseklik ekranın yarısı, konum ise ekranın dörtte biri olur. Sol üst köşe $(W/4, H/4)$ noktasına konan $W/2 \times H/2$ boyutlu pencere ekranın tam ortasına gelir.
- `NotHelloWorld` örneğinde ilk kez panel kullanılır. Panel sınıfı `JPanel`'i genişletir ve `paintComponent` metodunu yazar; bu metot panelin üzerine ne çizileceğini ya da yazılacağını belirler. `Graphics` nesnesinin `drawString` metodu verilen metni verilen koordinata yazar. Çerçevenin kurucusu panel nesnesini oluşturup `add` ile kendine ekler. Uygulama `EventQueue.invokeLater` ile başlatılır; buradaki `new Runnable() { ... }` ifadesi adsız bir sınıf tanımlar. Ayrı bir adlı sınıf yazmak da mümkündü, ama nesne yalnız burada kullanılacağı için adsız sınıf yeterlidir.
- Olay yönetiminde üç parça vardır: olay kaynağı (düğme, çerçeve, metin kutusu), olay nesnesi (`ActionEvent`, `WindowEvent`, `MouseEvent`, `KeyEvent`) ve dinleyici. Dinleyici, ilgili arayüzü gerçekleyen bir sınıfın nesnesidir ve `addXxxListener` ile kaynağa bağlanır. Olay gerçekleşince dinleyicinin ilgili metodu (`actionPerformed` gibi) olay nesnesini girdi olarak alıp çalışır. `ButtonTest`'te üç düğmenin her birine ayrı bir `ColorAction` nesnesi bağlanır; `ColorAction` kurucusuna verilen rengi saklar ve `actionPerformed` içinde panelin arka planını bu renge çevirir. `ColorAction` çerçevenin iç sınıfı olduğundan `buttonPanel` alanına erişebilir. Koddaki yorumda aynı örneğin sıradan sınıflarla yazılmış bir sürümünün (`ButtonTestV2`) olduğu belirtilir (ekrandan, 01:05:00).
- `WindowEventTest`'te çerçevenin kendisi olay kaynağıdır ve ona iki dinleyici eklenir. `WindowListener` arayüzünün yedi metodu olduğu için `MyWindowListener` hepsini yazar. Pencere simge durumuna küçültülüp geri getirildiğinde hem durum değişikliği (`windowStateChanged`) hem de odak değişikliği (`windowActivated`, `windowDeactivated`) iletileri konsola düşer. Durum değerleri koddaki yoruma göre `Frame.NORMAL` (0), `Frame.ICONIFIED` (1), `Frame.MAXIMIZED_BOTH` (6) biçimindedir (ekrandan, 01:25:00).
- Adaptör sınıfları, çok metotlu dinleyici arayüzlerini boş gövdelerle gerçekleyen soyut sınıflardır. Programcı arayüz yerine adaptörü genişletir ve yalnız gereken metotları yazar. `MouseEventsTest`'te `MouseMotionHandler` arayüzü gerçeklerken `MouseHandler` `MouseAdapter`'ı genişletir; `KeyboardEventTest`'te de `KeyHandler` arayüzü gerçeklerken `SpecialKeyHandler` `KeyAdapter`'ı genişletir. Böylece iki yol yan yana görülür.
- Ders sonrası notlar
  - Hoca `JFrame`'in soyut (abstract) bir sınıf olduğunu, `JPanel`'in de soyut olup `paintComponent`'in soyut bir metot olarak mutlaka gerçeklenmesi gerektiğini söyledi. Doğrusu: `JFrame` ve `JPanel` somut sınıflardır (`new JPanel()` derste de kullanıldı), `paintComponent` ise `JComponent`'te gövdesi olan `protected` bir metottur; panel üzerine çizim yapılmak istendiğinde geçersiz kılınır, zorunlu değildir.
  - Hoca bileşenlerin çerçeveye doğrudan eklenemediğini, yalnız panelin eklenebildiğini söyledi. Doğrusu: `JFrame.add(bilesen)` bileşeni çerçevenin içerik bölmesine (content pane) ekler ve çalışır; bileşenleri bir panelde toplayıp paneli eklemek düzen açısından tercih edilen yoldur.
  - Koddaki yorumda `Frame.MAXIMIZED_HORIZ (4)` yazıyor (ekrandan, 01:25:00). Doğrusu: `MAXIMIZED_HORIZ` 2, `MAXIMIZED_VERT` 4'tür; `MAXIMIZED_BOTH` 6'dır (ajan `java` ile denedi).
  - Derste gösterilen kodların bir kısmı (`ButtonTest`, `NotHelloWorldPanel`, dinleyici sınıfları) ajan tarafından `java Dosya.java` ile ekransız (headless) ortamda derlendi; dinleyici metotları elle üretilen olaylarla çalıştırıldı. Pencere açılamadığı için arayüz davranışı denenmedi.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını Gemini Notebook gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
