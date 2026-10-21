import socket
import os
import time
from _thread import *
import threading
import re

class Client:
    def __init__(self):
        self.isConnected = False
        self.ip = ""
        self.conn = ""
        self.name = ""
        

class Manager(Client):
    def __init__(self):
        Client.__init__(self)
        
class Greenhouse(Client):
    def __init__(self):
        Client.__init__(self)
        self.gCode = 0
        self.goal = 52                                                              # 51 -> OFF, 52-> DC
        self.temperature = 0


manager = Manager()
manager.name = "manager"

greenHouses = []                                                                    #The array of greenhouses, we have 4

HEADER = 64 
CLIENTHEADER = 1024
port = 8000
FORMAT = 'utf-8'
DISCONNECT_MESSAGE = "!DISCONNECT"
ServerSocket = socket.socket()      


manager.ip = "25.74.127.57"                                                         # [REPLACE]
greenhouseIp = ['25.65.81.190', '25.60.221.166', 'yyy', '25.39.123.162']                                # [REPLACE]
host = "25.74.127.57"                                                               # [REPLACE]                                        


def handleGreenhouse(Client,address):                                                   # Clientlerden gelen verilerle işlem yapma fonksiyonu 
    global greenHouses
    ilkmesaj = "Welcome "                                                 
    idx = greenhouseIp.index(address[0])                                                # ip adresine göre 
    greenHouses[idx].goal = 51
    greenHouses[idx].isConnected = True
    greenHouses[idx].conn = Client
    Client.send(ilkmesaj.encode('utf-8') + greenHouses[idx].name.encode('utf-8'))       # Seraya hoşgeldin mesajı yolla
    try:
        while True:                                                                     # sonsuz döngüye gir
            data = Client.recv(1024)                                                    # Clientten veri bekle gelen veriyi dataya eşitle
            if not data:                                                                # Eğer veri gelmemişse
                continue                                                                # while döngüsünün başına ilerle
            else:                                                                       # Eğer veri gelirse
                veri = data.decode(FORMAT);                                             # veriyi okunabilir formata çevir
                try:
                    greenHouses[idx].temperature = int(float(veri))
#                   print(greenHouses[idx].name + ' Clientinin Sıcaklık Değeri: ' + veri)   # ekrana gelen veriyi yazdır  
                except Exception as e:
                    print(e)
        greenHouses[idx].isConnected = False
        greenHouses[idx].goal = 52
        Client.close()                                                                  # Herhangi bir şekilde while döngüsünden çıkarsa client bağlantısını kes
    except Exception as e:
        print(e)
        print("Greenhouse ", idx+1, "has been disconnected.")
        greenHouses[idx].isConnected = False
        greenHouses[idx].goal = 52
#        Client.close() 

#def input_girisi(Client,address):                                                  # Cliente veri yollama işlemleri fonksiyonu
#    idx = greenhouseIp.index(address[0])                                           # yap ve client_name eşitle
#    while True:                                                                    # sonsuz döngüye gir
#        user = input();                                                            # kullanıcıdan veri yazmasını bekle
#        Client.send(user.encode('utf-8'))                                          # Yazdığı veriyi byte dizisine çevir ve cliente yolla
#        print(greenHouses[idx].name + ' Clientinin sıcaklık değeri değiştirildi.') # Ekrana bilgi yazdır


def handleManager(conn, addr): 
    print(f"\n[NEW MANAGER CONNECTION] {addr} connected.")
    manager.conn = conn
    manager.isConnected = True 
    try:
        while manager.isConnected:                                                   # Connected oldugu surece
            msgLength = conn.recv(HEADER).decode(FORMAT)                             # Oncelikle mesajin uzunlugunu al
            if msgLength:                                                            # Boyle bir header bilgisi geldiyse, mesaj da gelecek demektir
                msgLength = int(msgLength) 
                msg = conn.recv(msgLength).decode(FORMAT)                            # mesaji al
                print(f"Message from manager: [{manager.name}][{addr}]: {msg}")
                if msg and msg == DISCONNECT_MESSAGE:                                #mesaji aldiysan ve disconnect mesajiysa...
                    print(f"DC message from manager: [{addr}]: {msg}")
                    manager.isConnected = False
                    print(f"\n[MANAGER DISCONNECT] {addr} disconnected.")
                elif msg: 
                    gCode, command = parseManagerCommand(msg)
                    print("Manager message parsed as ", gCode, " ", command)
                    if command !=  'X':
                        try:
                            postToGreenhouse(gCode, command)
                        except Exception as e:
                            print("Error passing command to the client: ", command)
                            print(e)
                            print('\n')
                    else:
                        try:
                            postToManager(conn, createMessageAbout(gCode))
                        except Exception as e:
                            print("Error passing data to the manager.")
                            print(e)
                            print('\n')
                postToManager(conn, "RCVD")
        conn.close() 
        manager.isConnected = False                                                               
    except Exception as e:
        print("Manager connection error.")
        print(e)
        manager.isConnected = False

def postToManager(conn, msg): 
    message = msg + '\n'
    message = message + ( ' ' * (HEADER - len(message)))
    conn.send(message.encode(FORMAT))

def postToGreenhouse(gCode, command):
    global greenHouses
    if greenHouses[int(gCode)-1].isConnected:
        client = greenHouses[int(gCode)-1].conn
        message = command
        message = message + ( ' ' * (CLIENTHEADER - len(message)))
        client.send(message.encode(FORMAT)) 
        greenHouses[int(gCode)-1].goal = int(command)
        if greenHouses[int(gCode)-1].goal == 51:
            print(greenHouses[int(gCode)-1].name + ' system has been powered off.')
        elif greenHouses[int(gCode)-1].goal < 51:
            print(greenHouses[int(gCode)-1].name + ' temperature goal has been updated.')
    else:
        print("Manager is trying to send command to a disconnected greenhouse.")

def sendEmptyPackages(conn):
    while (manager.isConnected) and (manager.conn == conn):
        time.sleep(0.15)
        try:
            postToManager(conn, "")
        except:
            continue

def parseManagerCommand(command):
    pieces = re.findall(r"\.?([a-zA-z0-9]+)\.?\s?", command)
    command = pieces[0]
    gCode = pieces[1]
    return gCode, command

def createMessageAbout(gCode):
    global greenHouses
    message = ""
    gCode = int(gCode)
    message = message + str(gCode)
    message += "."
    message += str(greenHouses[gCode-1].goal)
    message += "."
    message += str(greenHouses[gCode-1].temperature)
    message += "-"
    return message

def informer():
    global greenHouses
    while True:
        time.sleep(2)
        if manager.isConnected:
            print("Manager is connected.")
        if greenHouses[0].isConnected:
            print("Greenhouse 1 Temperature: ", greenHouses[0].temperature, ", Goal: ", greenHouses[0].goal)
        if greenHouses[1].isConnected:
            print("Greenhouse 2 Temperature: ", greenHouses[1].temperature, ", Goal: ", greenHouses[1].goal)
        if greenHouses[2].isConnected:
            print("Greenhouse 3 Temperature: ", greenHouses[2].temperature, ", Goal: ", greenHouses[2].goal)
        if greenHouses[3].isConnected:
            print("Greenhouse 4 Temperature: ", greenHouses[3].temperature, ", Goal: ", greenHouses[3].goal)
        print("")

def start():
    global greenHouses
    for i in range (1,5):
        gh = Greenhouse()
        gh.gCode = i
        gh.ip = greenhouseIp[i-1]
        gh.name = "Greenhouse " + str(i)
        greenHouses.append(gh)

    try:
        ServerSocket.bind((host, port))                                         # Verilen host ve porta göre socket haberleşmeyi başlat
    except socket.error as e:                                                   # hata çıktıysa
        print(str(e))                                                           # ekrana hatanın kodunu yazdır
        print("Could not bind socket...")
        return

    print('Server listening...')                                                # ekrana bilgi mesajı yazdır
    ServerSocket.listen(5)                                                      # Socket sunucuya bağlanacak client sayısını belirle

    informerThread = threading.Thread(target = informer, args = ())
    informerThread.start()

    while True:                                                                 # sonsuz döngüye gir
        Client, address = ServerSocket.accept()                                 # Sunucuyla bağlantı kurulursa clientin bağlantısını ve ip adresini tut
        print(address[0] + ':' + str(address[1]) + ' NEW CONNECTION')           # Ekrana bağlanan clientin ip adresini yansıt
        if address[0]== manager.ip:
            thread = threading.Thread(target = handleManager, args = (Client, address))
            thread2 = threading.Thread(target = sendEmptyPackages, args = (Client,))
            thread.start()
            thread2.start()
        else:    
            start_new_thread(handleGreenhouse, (Client, address,  ))             # threaded_client fonksiyonunu çalıştır (Birden çok kullanıcı için ayrı ayrı başlatılır / Multithreading)
#            start_new_thread(input_girisi, (Client, address,  ))                # input_girisi fonksiyonunu çalıştır (Birden çok kullanıcı için ayrı ayrı başlatılır / Multithreading)
    ServerSocket.close()                                                         # Herhangi bir şekilde while döngüsünden çıkarsa socket haberleşmeyi bitir.

start()

