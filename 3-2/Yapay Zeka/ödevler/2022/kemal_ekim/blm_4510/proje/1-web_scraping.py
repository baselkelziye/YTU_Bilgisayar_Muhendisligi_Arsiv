# Mustafa Kemal Ekim - 18011072
# Gerekli kütüphanelerin yüklenmesi
from selenium import webdriver
from selenium.webdriver.common.by import By
import time
import pandas as pd
from datetime import datetime


# chrome driverin yolu
driver_path = "D:\chromedriver_win32\chromedriver.exe"
browser = webdriver.Chrome(driver_path)

ilan_linkleri = []
fiyat = []
metre_kare = []
oda_salon = []
kat = []
kat_sayisi = []
net_m_2 = []
esyali_mi = []
bina_yasi = []


sayfa_linkleri = ['https://www.hepsiemlak.com/istanbul-satilik', 'https://www.hepsiemlak.com/istanbul-satilik/daire-2-1?buildingAges=11-15&bathroomStatuses=ONE', 'https://www.hepsiemlak.com/istanbul-satilik/daire?buildingAges=11-15&bathroomStatuses=ONE',
                  'https://www.hepsiemlak.com/istanbul-satilik/daire?buildingAges=6-10&bathroomStatuses=TWO', 'https://www.hepsiemlak.com/istanbul-satilik/daire?buildingAges=1-5&bathroomStatuses=ONE']


now = datetime.now()
current_time = now.strftime("%H:%M:%S")
print("Islem basliyor: ", current_time)

# belirlediğimiz linklerdeki ilanların sayfaları bir listede tutulmuştur
for i in range(len(sayfa_linkleri)):
    try:
        browser.get(sayfa_linkleri[i])
    except:
        pass

    # fiyatların tutulması
    fiyatlar = browser.find_elements_by_css_selector(".list-view-price")
    for i in fiyatlar:
        fiyat.append(i.text[:-3]) # sonda \nTL olduğundan son 3 harfi almaya gerek yoktur

    # ilan linklerinin tutulması
    links = browser.find_elements_by_class_name("card-link")
    for link in links:
        #print(link.get_attribute("href"))
        ilan_linkleri.append(link.get_attribute("href"))
    
#print("Len_ilan_linkleri: ", len(ilan_linkleri))


# ilan linklerine gidilerek kullanılacak özelliklerin tutulması
for link in ilan_linkleri:
    try:
        browser.get(link)
        print("Link", link)
    except:
        break

    try:
        metre_kare.append(browser.find_element(By.XPATH, "(//span[contains(text(),'m2')])[1]").text.replace(" m2",""))
    except:
        metre_kare.append("NaN")

    try:
        net_m_2.append(browser.find_element(By.XPATH, "/html[1]/body[1]/div[1]/div[1]/div[1]/div[1]/section[3]/div[1]/div[1]/div[1]/section[1]/div[4]/div[1]/ul[1]/li[6]/span[3]").text.replace(" m2",""))
    except:
        pass

    try:
        oda_salon.append(browser.find_element(By.XPATH,
        "/html[1]/body[1]/div[1]/div[1]/div[1]/div[1]/section[3]/div[1]/div[1]/div[1]/section[1]/div[4]/div[1]/ul[1]/li[5]/span[2]").text)
    except:
        oda_salon.append("NaN")

    try:
        esyali_mi.append(browser.find_element(By.XPATH, "//span[contains(text(),'Eşyalı Değil')]").text)
    except:
        esyali_mi.append("NaN")

    try:
        kat.append(browser.find_element(By.XPATH, "//span[contains(text(),'. Kat')]").text.replace(". Kat",""))
    except:
        kat.append("0")

    try:
        kat_sayisi.append(browser.find_element(By.XPATH, "(//span[contains(text(),' Katlı')])[1]").text.replace(" Katlı",""))
    except:
        kat_sayisi.append("NaN")

    try:
        bina_yasi.append(browser.find_element(By.XPATH, "//span[contains(text(),'Yaşında')]").text.replace(" Yaşında",""))
    except:
        bina_yasi.append("0")

    time.sleep(0.1)


    
now = datetime.now()
current_time = now.strftime("%H:%M:%S")
print("Islem bitti: ", current_time)

# ayrı listelerde tutulan özelliklerin birleştirilmesi
col = list(zip(fiyat, metre_kare, oda_salon, kat, kat_sayisi, net_m_2, esyali_mi, bina_yasi))
df = pd.DataFrame(col)

basliklar = ['fiyat', 'metre_kare', 'oda_salon', 'kat', 'kat_sayisi', 'net_m_2', 'esyali_mi', 'bina_yasi']
df.columns = basliklar

# csv'ye aktarılması
df.to_csv("ilanlar_df.csv")

browser.quit()
