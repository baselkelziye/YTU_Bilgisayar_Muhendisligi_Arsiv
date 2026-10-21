# db.py

import psycopg2
from psycopg2.extras import RealDictCursor
import config

def get_connection():
    conn = psycopg2.connect(
        host=config.DB_HOST,
        database=config.DB_NAME,
        user=config.DB_USER,
        password=config.DB_PASS,
        port=config.DB_PORT
    )
    return conn

def execute_query(query, params=None):
    """
    INSERT, UPDATE, DELETE gibi veri değiştiren sorgular.
    Etkilenen satır sayısını (rowcount) döndürür.
    """
    conn = None
    cursor = None
    try:
        conn = get_connection()
        cursor = conn.cursor()
        cursor.execute(query, params)
        conn.commit()
        return cursor.rowcount
    except Exception as e:
        print("DB Error:", e)
        if conn:
            conn.rollback()
        return 0
    finally:
        if cursor:
            cursor.close()
        if conn:
            conn.close()

def fetch_query(query, params=None):
    """
    SELECT gibi veri çeken sorgular.
    Sonucu list of dict formatında döndürür.
    """
    conn = None
    cursor = None
    try:
        conn = get_connection()
        cursor = conn.cursor(cursor_factory=RealDictCursor)
        cursor.execute(query, params)
        results = cursor.fetchall()
        return results
    except Exception as e:
        print("DB Error:", e)
        return []
    finally:
        if cursor:
            cursor.close()
        if conn:
            conn.close()
