# config.py

DB_HOST = "localhost"
DB_NAME = "craftmart"
DB_USER = "postgres"
DB_PASS = "12345"
DB_PORT = 1234

SECRET_KEY = "super-secret-key"  
# Flask oturum (session) yönetimi için gereklidir (örn. flash mesajları, login session).
# Production’da bunu çevresel değişkenlerden (ENV) okumanız önerilir.
