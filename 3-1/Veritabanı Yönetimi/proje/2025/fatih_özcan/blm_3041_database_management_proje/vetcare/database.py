# database.py (İsteğe bağlı - veritabanı işlemleri için)
import psycopg2
from psycopg2 import Error

class Database:
    def __init__(self):
        self.conn = None
        self.cur = None

    def connect(self):
        try:
            self.conn = psycopg2.connect(
                database="PYvetcareDB",
                user="postgres",
                password="123456",
                host="localhost",
                port="5432"
            )
            self.cur = self.conn.cursor()
            return True
        except Error as e:
            print(f"Error: {e}")
            return False

    def disconnect(self):
        if self.cur:
            self.cur.close()
        if self.conn:
            self.conn.close()