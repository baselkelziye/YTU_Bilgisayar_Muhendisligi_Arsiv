<#
.SYNOPSIS
    Belirtilen karakterlerden rastgele N x M boyutunda bir matris oluşturur.
.DESCRIPTION
    Bu script, N (satır) ve M (sütun) parametrelerini alarak 
    {'*', '/', '+', '%', 'O'} kümesinden rastgele seçilen karakterlerle 
    bir matris oluşturur ve Write-Output ile ekrana yazar.
#>

param (
    [Parameter(Mandatory=$true, HelpMessage="Satır sayısını giriniz (N)")]
    [int]$N,

    [Parameter(Mandatory=$true, HelpMessage="Sütun sayısını giriniz (M)")]
    [int]$M
)

# Kullanılacak karakter seti
$karakterler = @('*', '/', '+', '%', 'O')

# Rastgelelik için nesne oluştur (Döngü içinde Get-Random çağırmaktan daha performanslıdır)
$random = New-Object System.Random

# Matris oluşturma döngüsü
for ($i = 0; $i -lt $N; $i++) {
    $satirDizisi = New-Object System.Collections.Generic.List[string]
    
    for ($j = 0; $j -lt $M; $j++) {
        # Rastgele bir index seç ve karakteri al
        $index = $random.Next(0, $karakterler.Count)
        $secilenKarakter = $karakterler[$index]
        $satirDizisi.Add($secilenKarakter)
    }

    # Satırı birleştir (görsel olarak ayrışması için araya boşluk konulmuştur)
    # Boşluksuz isterseniz -join "" yapabilirsiniz.
    $sonucSatiri = $satirDizisi -join " "
    
    # Standart output'a yaz
    Write-Output $sonucSatiri
}