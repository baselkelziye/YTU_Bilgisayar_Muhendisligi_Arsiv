#!/bin/bash

# Projedeki tüm PDF ve görsel dosyaların standart seviyede sıkıştırılması için

# Kontrol: Klasör yolu argüman olarak verilmiş mi?
if [ -z "$1" ]; then
  echo "Kullanım: $0 <klasör_yolu> [çekirdek_sayısı]"
  exit 1
fi

HEDEF_KLASOR="$1"
CEKIRDEK_SAYISI="${2:-2}"

# Kontrol: Çekirdek sayısı pozitif bir tam sayı mı?
if ! [[ "$CEKIRDEK_SAYISI" =~ ^[0-9]+$ ]] || [ "$CEKIRDEK_SAYISI" -le 0 ]; then
  echo "Hata: Çekirdek sayısı pozitif bir tam sayı olmalıdır."
  exit 1
fi

# Kontrol: Verilen yol bir dizin mi?
if [ ! -d "$HEDEF_KLASOR" ]; then
  echo "Hata: '$HEDEF_KLASOR' bir dizin değil."
  exit 1
fi

# Gerekli komutları kontrol etme
GEREKLI_KOMUTLAR=("gs" "mogrify" "pngquant" "optipng" "exiftool" "git")
EKSIK_KOMUTLAR=()

for komut in "${GEREKLI_KOMUTLAR[@]}"; do
  if ! command -v "$komut" >/dev/null 2>&1; then
    EKSIK_KOMUTLAR+=("$komut")
  fi
done

if [ ${#EKSIK_KOMUTLAR[@]} -ne 0 ]; then
  echo "Hata: Aşağıdaki komutlar sisteminizde yüklü değil:"
  for eksik in "${EKSIK_KOMUTLAR[@]}"; do
    echo "- $eksik"
  done
  echo ""
  echo "Lütfen eksik komutları aşağıdaki şekilde yükleyin:"
  echo ""
  if [[ " ${EKSIK_KOMUTLAR[@]} " =~ " gs " ]]; then
    echo "Ghostscript (gs) yüklemek için:"
    echo "sudo apt-get install ghostscript"
  fi
  if [[ " ${EKSIK_KOMUTLAR[@]} " =~ " mogrify " ]]; then
    echo "ImageMagick (mogrify'i içerir) yüklemek için:"
    echo "sudo apt-get install imagemagick"
  fi
  if [[ " ${EKSIK_KOMUTLAR[@]} " =~ " pngquant " ]]; then
    echo "pngquant yüklemek için:"
    echo "sudo apt-get install pngquant"
  fi
  if [[ " ${EKSIK_KOMUTLAR[@]} " =~ " optipng " ]]; then
    echo "optipng yüklemek için:"
    echo "sudo apt-get install optipng"
  fi
  if [[ " ${EKSIK_KOMUTLAR[@]} " =~ " exiftool " ]]; then
    echo "exiftool yüklemek için:"
    echo "sudo apt-get install libimage-exiftool-perl"
  fi
  if [[ " ${EKSIK_KOMUTLAR[@]} " =~ " git " ]]; then
    echo "Git'i yüklemek için:"
    echo "sudo apt-get install git"
  fi
  exit 1
fi

echo "Tüm gerekli paketler yüklü. Sıkıştırma işlemine başlıyor..."

# Görsel dosya uzantıları
GORSEL_UZANTILAR=("jpg" "jpeg" "png" "gif" "tif" "tiff")

# PDF dosyalarını sıkıştırma fonksiyonu
sikistir_pdf() {
  yerel_dosya="$1"

  # Zaten sıkıştırılmışsa pas geç
  if exiftool "$yerel_dosya" 2>/dev/null | grep -q "CompressedBySikistirScript"; then
    echo "Zaten sıkıştırılmış (pas geçiliyor): $yerel_dosya"
    return
  fi

  echo "PDF sıkıştırılıyor: $yerel_dosya"

  # Orijinal dosya boyutunu al
  eski_boyut=$(git show HEAD:"$yerel_dosya" 2>/dev/null | wc -c)
  # Eğer dosya git ile takip edilmiyorsa veya daha önce commit edilmediyse
  if [ "$eski_boyut" -eq 0 ]; then
    eski_boyut=$(wc -c < "$yerel_dosya")
  fi

  # Geçici bir dosyaya sıkıştır
  gs -sDEVICE=pdfwrite \
     -dCompatibilityLevel=1.4 \
     -dPDFSETTINGS=/ebook \
     -dNOPAUSE -dQUIET -dBATCH \
     -sOutputFile="${yerel_dosya}.tmp" "$yerel_dosya"

  # Yeni dosya boyutunu al
  yeni_boyut=$(wc -c < "${yerel_dosya}.tmp")

  # Eğer yeni boyut eski boyuttan büyük veya eşitse, eski halini geri yükle ve etiketle
  if [ "$yeni_boyut" -ge "$eski_boyut" ]; then
    echo "Sıkıştırma sonucu dosya boyutu azalmadı, orijinal dosya korunuyor ve etiketleniyor: $yerel_dosya"
    rm "${yerel_dosya}.tmp"
    git checkout HEAD -- "$yerel_dosya" 2>/dev/null || true
    exiftool -Keywords="CompressedBySikistirScript" -overwrite_original "$yerel_dosya" >/dev/null 2>&1
  else
    mv "${yerel_dosya}.tmp" "$yerel_dosya"
    # Sıkıştırılmış dosyaya etiket ekle
    exiftool -Keywords="CompressedBySikistirScript" -overwrite_original "$yerel_dosya" >/dev/null 2>&1
  fi
}

# Görsel dosyalarını sıkıştırma fonksiyonu
sikistir_gorsel() {
  yerel_dosya="$1"
  uzanti="${yerel_dosya##*.}"
  uzanti="${uzanti,,}"

  # Zaten sıkıştırılmışsa pas geç
  if exiftool "$yerel_dosya" 2>/dev/null | grep -q "CompressedBySikistirScript"; then
    echo "Zaten sıkıştırılmış (pas geçiliyor): $yerel_dosya"
    return
  fi

  # Orijinal dosya boyutunu al
  eski_boyut=$(git show HEAD:"$yerel_dosya" 2>/dev/null | wc -c)
  # Eğer dosya git ile takip edilmiyorsa veya daha önce commit edilmediyse
  if [ "$eski_boyut" -eq 0 ]; then
    eski_boyut=$(wc -c < "$yerel_dosya")
  fi

  # Dosyanın bir yedeğini alın
  cp "$yerel_dosya" "${yerel_dosya}.sikistir_bak"

  case "$uzanti" in
    jpg|jpeg)
      echo "JPEG sıkıştırılıyor: $yerel_dosya"
      mogrify -strip \
              -interlace Plane \
              -sampling-factor 4:2:0 \
              -quality 85 \
              "$yerel_dosya"
      ;;
    png)
      echo "PNG sıkıştırılıyor: $yerel_dosya"
      pngquant --quality=80-85 --ext .png --force "$yerel_dosya" 2>/dev/null \
      || optipng -clobber -o2 "$yerel_dosya" >/dev/null
      ;;
    gif|tif|tiff)
      echo "Görsel sıkıştırılıyor: $yerel_dosya"
      mogrify -strip "$yerel_dosya"
      ;;
    *)
      echo "Desteklenmeyen dosya türü: $yerel_dosya"
      rm "${yerel_dosya}.sikistir_bak"
      return
      ;;
  esac

  # Yeni dosya boyutunu al
  yeni_boyut=$(wc -c < "$yerel_dosya")

  # Eğer yeni boyut eski boyuttan büyük veya eşitse, eski halini geri yükle ve etiketle
  if [ "$yeni_boyut" -ge "$eski_boyut" ]; then
    echo "Sıkıştırma sonucu dosya boyutu azalmadı, orijinal dosya korunuyor ve etiketleniyor: $yerel_dosya"
    mv "${yerel_dosya}.sikistir_bak" "$yerel_dosya"
    git checkout HEAD -- "$yerel_dosya" 2>/dev/null || true
    exiftool -Comment="CompressedBySikistirScript" -overwrite_original "$yerel_dosya" >/dev/null 2>&1
  else
    rm "${yerel_dosya}.sikistir_bak"
    # Sıkıştırılmış dosyaya etiket ekle
    exiftool -Comment="CompressedBySikistirScript" -overwrite_original "$yerel_dosya" >/dev/null 2>&1
  fi
}

# Sıkıştırılacak dosyayı yönlendiren sarmalayıcı fonksiyon (xargs paralel çalıştırabilmesi için)
sikistir_dosya() {
  local dosya="$1"
  local uzanti="${dosya##*.}"
  uzanti="${uzanti,,}"
  local gorsel_uzantilar=("jpg" "jpeg" "png" "gif" "tif" "tiff")

  if [ "$uzanti" == "pdf" ]; then
    sikistir_pdf "$dosya"
  elif [[ " ${gorsel_uzantilar[@]} " =~ " $uzanti " ]]; then
    sikistir_gorsel "$dosya"
  fi
}

# Fonksiyonları alt kabuklara (xargs'ın erişebilmesi için) aktar
export -f sikistir_pdf
export -f sikistir_gorsel
export -f sikistir_dosya

echo "Sıkıştırma paralel olarak ($CEKIRDEK_SAYISI çekirdek) yürütülüyor..."

# Rekürsif olarak dosyaları bul (venv, .venv, node_modules, .git, .github, graphify-out vb. bağımlılık ve sistem klasörlerini pas geçerek) ve paralel olarak sıkıştır
find "$HEDEF_KLASOR" \
  -type d \( -name "venv" -o -name ".venv" -o -name "node_modules" -o -name ".git" -o -name ".github" -o -name "graphify-out" \) -prune \
  -o -type f \( -iname "*.pdf" $(for ext in "${GORSEL_UZANTILAR[@]}"; do echo -o -iname "*.$ext"; done) \) -print0 | \
  xargs -0 -P "$CEKIRDEK_SAYISI" -n 1 bash -c 'sikistir_dosya "$1"' _