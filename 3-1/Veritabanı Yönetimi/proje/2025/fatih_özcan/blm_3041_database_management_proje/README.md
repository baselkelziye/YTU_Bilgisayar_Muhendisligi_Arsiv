# VetCare Yönetim Sistemi

## Açıklama
VetCare, evcil hayvan sahipleri için bir yönetim sistemidir. Kullanıcılar, evcil hayvanlarını ekleyebilir, randevu alabilir, aşı takibi yapabilir ve ürün satın alabilirler. Bu sistem, kullanıcı dostu bir arayüz ile PostgreSQL veritabanı kullanarak çalışmaktadır.

## Özellikler
- **Evcil Hayvan Yönetimi**: Kullanıcılar evcil hayvanlarını ekleyebilir, güncelleyebilir ve silebilir.
- **Randevu Yönetimi**: Kullanıcılar, evcil hayvanları için randevu alabilir ve mevcut randevularını görüntüleyebilir.
- **Aşı Takibi**: Kullanıcılar, evcil hayvanlarının aşılarını takip edebilir ve yeni aşı kayıtları ekleyebilir.
- **Mağaza**: Kullanıcılar, evcil hayvan ürünlerini görüntüleyebilir ve sepete ekleyebilir.

## Kurulum
1. **Gereksinimler**:
   - Python 3.x
   - PostgreSQL
   - Gerekli Python kütüphaneleri: `tkinter`, `psycopg2`

2. **Veritabanı Ayarları**:
   - PostgreSQL'de `PYvetcareDB` adında bir veritabanı oluşturun.
   - Gerekli tabloları oluşturmak için SQL komutlarını çalıştırın.

3. **Kodu Çalıştırma**:
   - Terminal veya komut istemcisinde `mainApp.py` dosyasını çalıştırın:
     ```bash
     python VetCare/mainApp.py
     ```

## Kullanım
- Uygulama açıldığında, kullanıcı giriş penceresi görüntülenecektir.
- Kullanıcı adı ve şifre ile giriş yaparak uygulamanın ana arayüzüne erişebilirsiniz.
- Evcil hayvanlarınızı eklemek, randevu almak ve aşı takibi yapmak için ilgili sekmelere gidin.

---

# VetCare Management System

## Description
VetCare is a management system for pet owners. Users can add their pets, schedule appointments, track vaccinations, and purchase products. This system operates using a user-friendly interface and a PostgreSQL database.

## Features
- **Pet Management**: Users can add, update, and delete their pets.
- **Appointment Management**: Users can schedule appointments for their pets and view existing appointments.
- **Vaccination Tracking**: Users can track their pets' vaccinations and add new vaccination records.
- **Shop**: Users can view pet products and add them to their cart.

## Installation
1. **Requirements**:
   - Python 3.x
   - PostgreSQL
   - Required Python libraries: `tkinter`, `psycopg2`

2. **Database Setup**:
   - Create a database named `PYvetcareDB` in PostgreSQL.
   - Run SQL commands to create the necessary tables.

3. **Running the Code**:
   - Run the `mainApp.py` file in the terminal or command prompt:
     ```bash
     python VetCare/mainApp.py
     ```

## Usage
- When the application opens, a login window will be displayed.
- You can access the main interface of the application by logging in with your username and password.
- Navigate to the relevant tabs to add your pets, schedule appointments, and track vaccinations.
