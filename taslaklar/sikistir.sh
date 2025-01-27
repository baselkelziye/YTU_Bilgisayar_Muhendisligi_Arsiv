#!/bin/bash

# Projedeki tüm PDF ve görsel dosyaların standart seviyede sıkıştırılması için

# Kontrol: Klasör yolu argüman olarak verilmiş mi?
if [ -z "$1" ]; then
  echo "Kullanım: $0 <klasör_yolu>"
  exit 1
fi

HEDEF_KLASOR="$1"

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
GORSEL_UZANTILAR=("jpg" "jpeg" "png" "bmp" "gif" "tif" "tiff")

# PDF dosyalarını sıkıştırma fonksiyonu
sikistir_pdf() {
  yerel_dosya="$1"
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

  # Eğer yeni boyut eski boyuttan büyükse, eski halini geri yükle
  if [ "$yeni_boyut" -gt "$eski_boyut" ]; then
    echo "Sıkıştırma sonucu dosya boyutu arttı, eski dosya geri yükleniyor: $yerel_dosya"
    rm "${yerel_dosya}.tmp"
    git checkout HEAD -- "$yerel_dosya" 2>/dev/null || true
  else
    mv "${yerel_dosya}.tmp" "$yerel_dosya"
  fi
}

# Görsel dosyalarını sıkıştırma fonksiyonu
sikistir_gorsel() {
  yerel_dosya="$1"
  uzanti="${yerel_dosya##*.}"
  uzanti="${uzanti,,}"

  # Orijinal dosya boyutunu al
  eski_boyut=$(git show HEAD:"$yerel_dosya" 2>/dev/null | wc -c)
  # Eğer dosya git ile takip edilmiyorsa veya daha önce commit edilmediyse
  if [ "$eski_boyut" -eq 0 ]; then
    eski_boyut=$(wc -c < "$yerel_dosya")
  fi

  # Dosyanın bir yedeğini alın
  cp "$yerel_dosya" "${yerel_dosya}.bak"

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
      || optipng -o2 "$yerel_dosya" >/dev/null
      ;;
    bmp|gif|tif|tiff)
      echo "Görsel sıkıştırılıyor: $yerel_dosya"
      mogrify -strip "$yerel_dosya"
      ;;
    *)
      echo "Desteklenmeyen dosya türü: $yerel_dosya"
      ;;
  esac

  # Yeni dosya boyutunu al
  yeni_boyut=$(wc -c < "$yerel_dosya")

  # Eğer yeni boyut eski boyuttan büyükse, eski halini geri yükle
  if [ "$yeni_boyut" -ge "$eski_boyut" ]; then
    echo "Sıkıştırma sonucu dosya boyutu arttı, eski dosya geri yükleniyor: $yerel_dosya"
    mv "${yerel_dosya}.bak" "$yerel_dosya"
    git checkout HEAD -- "$yerel_dosya" 2>/dev/null || true
  else
    rm "${yerel_dosya}.bak"
  fi
}

# Rekürsif olarak dosyaları bul ve sıkıştır
find "$HEDEF_KLASOR" -type f \( -iname "*.pdf" $(for ext in "${GORSEL_UZANTILAR[@]}"; do echo -o -iname "*.$ext"; done) \) | while read -r dosya; do
  uzanti="${dosya##*.}"
  uzanti="${uzanti,,}"

  if [ "$uzanti" == "pdf" ]; then
    sikistir_pdf "$dosya"
  elif [[ " ${GORSEL_UZANTILAR[@]} " =~ " $uzanti " ]]; then
    sikistir_gorsel "$dosya"
  fi
done