import socket
import serial

ser = serial.Serial('COM1', baudrate = 9600, timeout=1)              # COM1 portundan 9600 bandında seri haberleşme başlat
s = socket.socket()                                                  # socket haberleşme kütüphanesini import et
host = "25.59.84.210"                                                # Sunucunun ip adresi
port = 80                                                            # Sunucunun port numarası


try:
    s.connect((host, port))                                          # Verilen host ve port numarasındaki sokete bağlan
    s.settimeout(0.1)                                                # Soket haberleşmenin zaman aşımını 0.1 saniye yap
    print('Sunucuya bağlanıldı.')                                    # Ekrana bilgi yazdır
    yanit = s.recv(1024)                                             # Sunucudan gönderilen veri varsa al
    getData = yanit.decode('utf-8');                                 # Alınan veriyi okunabilir hale getir
    print(getData)                                                   # Ekrana yazdır
    while True:                                                      # sonsuz döngüye gir
        arduinoData = ser.readline().decode('utf-8')                 # Arduino'dan gelen veriyi al  
        if arduinoData == "":                                        # Eğer veri boşsa
            print("Bir veri yok")                                    # Ekrana bilgi yazdır
            continue                                                 # while döngüsünün başına dön
        else:                                                        # Eğer veri boş değilse
            print('Arduino Verisi: ' + arduinoData)                  # Ekrana gelen veriyi yazdır
            s.send(arduinoData.encode('utf-8'))                      # Sunucuya veriyi gönder
            print("Sunucuya yollandı: " + arduinoData)               # Bilgiyi ekrana yazdır
            try:
                yanit = s.recv(1024)                                 # Sunucudan gönderilen veri varsa al
                getData = yanit.decode('utf-8');                     # Alınan veriyi okunabilir hale getir 
                if getData != "":                                    # Veri boş değilse
                    print('Sunucu yeni sıcaklık talebi: ' + getData) # Ekrana sunucudan gelen veriyi yazdır
                    ser.write(getData.encode())                      # Arduino'ya sunucudan gelen veriyi yolla
            except:                                                  # Bu işlemlerde hata çıkarsa
                continue                                             # while döngüsünün başına dön
    s.close()                                                        # Herhangi bir şekilde while döngüsünden çıkarsa sunucuya olan bağlantıyı kes
except socket.error as e:                                            # Soket haberleşmede herhangi bir sorun çıkarsa
    print("[Server aktif değil.] Mesaj:", e)                         # Ekrana bilgi yazdır
