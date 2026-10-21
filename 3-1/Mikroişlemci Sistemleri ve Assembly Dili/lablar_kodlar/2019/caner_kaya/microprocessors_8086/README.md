# microprocessors-8086

## 1- Basic I/O Keypad
* Keypad Aracılığıyla girilen son 4 rakamın seven segment displaylerde görüntülenmesini sağlar.
* Yeni bir rakam girilidiğinde önceki rakamlar sola kaydırılır.


![1](https://github.com/cnrkaya/microprocessors-8086/blob/master/1-8255_basic_io_keypad/ss.png)

## 2- Handshaking Calculator
* Girilen iki sayı arasında 4 işlem yapılmasını sağlayan basit bir hesap makinesidir.
* Keypad ile 8255 arasında kurulan iletişimde handshaking mekanizması kullanılmıştır.
* Girilen sayılar bir basamaklı veya iki basamaklı olabilir. (state machine diagram yapısı tasarlanmıştır)
* 2 adet seven segment kullanıldığı için gösterilebilen sonuçlar 0-99 aralığındadır.
[Lab Sorusu](https://github.com/cnrkaya/microprocessors-8086/blob/master/2-8255_handshaking_calculator/soru.pdf)


![21](https://github.com/cnrkaya/microprocessors-8086/blob/master/2-8255_handshaking_calculator/ss1.png )


# 3- Serial Communication

* 8251 aracılığıyla seri haberleşme gerçekleştirilmesidir.
* TOPSECRET isimli baudrate i bilinmeyen entegre ile uygun frekansta iletişim başlatılmıştır.
[Lab sorusu](https://github.com/cnrkaya/microprocessors-8086/blob/master/3-8251_serial_communication/labsorusu.pdf)


![31](https://github.com/cnrkaya/microprocessors-8086/blob/master/3-8251_serial_communication/ss.png)

# 4- Pulse and Square Wave Generator 

* 8254 aracılığıyla darbe ve kare dalga üretilmesi
[Lab sorusu](https://github.com/cnrkaya/microprocessors-8086/blob/master/4-8253_pulse_and_squarewawe_generator/soru_6.pdf)


![41](https://github.com/cnrkaya/microprocessors-8086/blob/master/4-8253_pulse_and_squarewawe_generator/ss1.png )
![42]( https://github.com/cnrkaya/microprocessors-8086/blob/master/4-8253_pulse_and_squarewawe_generator/ss2.png)

# 5- Digital-Analog & Analog-Digital Conversions

* DAC0830 ve ADC0834 entegreleri kullanılarak yapılan Dijital & Analog sinyal dönüşümleri
[Lab sorusu](https://github.com/cnrkaya/microprocessors-8086/blob/master/5-dac0830_adc0834-conversion/labsorusu.pdf)


![51](https://github.com/cnrkaya/microprocessors-8086/blob/master/5-dac0830_adc0834-conversion/ss1.png)
![52](https://github.com/cnrkaya/microprocessors-8086/blob/master/5-dac0830_adc0834-conversion/ss2.PNG)

# 6- Interrupts

* 8259 entegresi kullanılarak interrupt servislerinin yönetilmesi.
* Interrup Vektör tablosunda bulunan NMI ve Software interrupt servis programlarının değiştirilmesi.
* Interrup tetiklendiğinde yeni yazılan kesme programların çalıştırılması sağlanmıştır.

[Lab Sorusu](https://github.com/cnrkaya/microprocessors-8086/blob/master/6-8259_interrupts/soru.pdf)


![61](https://github.com/cnrkaya/microprocessors-8086/blob/master/6-8259_interrupts/ss1.PNG)
![62](https://github.com/cnrkaya/microprocessors-8086/blob/master/6-8259_interrupts/ss2.png)
