# Ders 5 Lab Çalışma Özeti

## Genel Konular

- Buffer overflow uygulama mantığı
  - Yerel buffer sınırının aşılması, stack üzerindeki kontrol verisinin değiştirilebilmesi ve shellcode çalıştırma fikri uygulamalı bağlamda ele alınır.
- Derleme ve çalışma zamanı etkileri
  - Derleyici seçenekleri, stack korumaları, yürütülebilir stack, ASLR ve canary mekanizmaları exploit davranışını değiştirir.
- Debug ve bellek gözlemi
  - Girdi uzunluğu, stack düzeni, dönüş adresi ve register değerleri debug araçlarıyla incelenir.

## Hocanın Özellikle Vurguladığı Kısımlar

- Teori exploit üretmek için tek başına yetmez
  - Adresler, derleyici çıktısı ve çalışma zamanı korumaları pratikte kontrol edilmelidir.
- Koruma mekanizmaları bilinçli kapatıldığında saldırı gözlemlenebilir
  - Lab ortamı saldırıyı anlamak içindir; gerçek sistemlerde bu korumalar açık kalmalıdır.

## Kısa Tekrar Notları

- Buffer overflow stack üzerindeki dönüş adresini hedefleyebilir.
- ASLR adres tahminini zorlaştırır.
- Canary taşmayı tespit etmeye yarar.
- NX/DEP veri bölgesinden kod çalıştırmayı engeller.

## Detaylı Açıklamalar

- Laboratuvar içeriğinde buffer overflow saldırısının yalnızca kavramsal değil, çalışma zamanı üzerinde nasıl gözlemlendiği vurgulanır. Girdi uzunluğu artırıldığında programın stack üzerinde hangi alanları ezdiği, dönüş adresinin nasıl etkilendiği ve saldırganın kontrol akışını nasıl yönlendirebildiği incelenir.
- Modern sistemlerde exploitin başarısı bellek korumalarıyla doğrudan ilişkilidir. ASLR adresleri rastgeleleştirir, stack canary dönüş adresinden önce beklenmeyen değişimi fark eder, NX/DEP veri alanlarının kod gibi çalıştırılmasını engeller. Bu mekanizmaların etkisini anlamak güvenli geliştirme ve zafiyet analizi için gereklidir.

* **Not:** İsterseniz bu dersin altyazı (.srt) dosyasını NotebookLM gibi bir yapay zeka aracına yükleyerek ders hakkında daha detaylı soru-cevaplar yapabilir ve dersi verimli çalışabilirsiniz.
