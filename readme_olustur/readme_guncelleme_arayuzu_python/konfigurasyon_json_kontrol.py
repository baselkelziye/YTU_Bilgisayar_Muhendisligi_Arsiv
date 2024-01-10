from degiskenler import *
import json
import subprocess
import urllib.parse
import os
def get_git_repo_url():
    current_directory = os.getcwd()
    py_bulamadi = False
    # Mevcut dizinde .py dosyası olduğu sürece üst dizine çık
    while not py_bulamadi:
        # Eğer mevcut dizinde .py dosyası varsa, döngüyü kır
        for file in os.listdir(current_directory):
            if file.endswith(".py"):
                py_bulamadi = False
                break
            else:
                py_bulamadi = True
        # Bir üst dizine çık
        if not py_bulamadi:
            current_directory = os.path.dirname(current_directory)

        # Eğer en üst dizine ulaşırsa ve hala .py dosyası yoksa, çık
        if current_directory == '/' or current_directory == '':
            return "Python dosyası bulunamadı."

    try:
        # Git reposunun URL'sini al
        git_url = subprocess.check_output(["git", "config", "--get", "remote.origin.url"], cwd=current_directory)
        return git_url.decode().strip()
    except subprocess.CalledProcessError:
        # Eğer mevcut dizin bir git reposu değilse
        return "Mevcut dizin bir git reposu değil."
def konfigurasyon_json_guncelle(file_path):
    # Anahtarları kontrol et ve güncelle
    updated = False
    try:
        # JSON dosyasını oku
        if os.path.exists(file_path):
            with open(file_path, 'r', encoding='utf-8') as file:
                data = json.load(file)
        else:
            data = {}
        if GITHUB_URL_ANAHTARI not in data or not isinstance(data[GITHUB_URL_ANAHTARI], str):
            data[GITHUB_URL_ANAHTARI] = get_git_repo_url()
            updated = True
        for key, default_link in ANAHTAR_VE_LINKLER.items():
            if key not in data or not isinstance(data[key], str) or (not urllib.parse.urlparse(data[key]).scheme and key != DOKUMANLAR_REPO_YOLU_ANAHTARI):
                data[key] = default_link
                updated = True

        # Eğer güncelleme yapıldıysa, dosyayı yeniden yaz
        if updated:
            with open(file_path, 'w', encoding='utf-8') as file:
                json.dump(data, file, indent=4, ensure_ascii=False)

    except Exception as e:
        print(f"Konfigurasyon dosyası güncellenirken hata oluştu: {e}")
    return updated
