package uyg2;

public class Raf {
    private Kitap[] kitaplar;

    public Raf() {
        this.kitaplar = new Kitap[10];
    }
    
    public void kitapEkle(Kitap k){
        int i = 0;
        while(i < kitaplar.length && kitaplar[i] != null)
            i++;
        
        if (i != kitaplar.length)
            kitaplar[i] = k;
        
        
       
    }
    
    
    public void kitapSil(int SıraNo){
        if (SıraNo < kitaplar.length)
            kitaplar[SıraNo] = null;
    }
    
    public void kitapSil(Kitap k){
        int i = 0;
        while(i < kitaplar.length && kitaplar[i] != k)
            i++;        
        if (i != kitaplar.length)
            kitaplar[i] = null;
    }
    
    public void rafGoster(){
        int i = 0;
        for(i = 0; i < kitaplar.length;i++ )
            System.out.println(kitaplar[i]);
    }

    public Kitap[] getKitaplar() {
        return kitaplar;
    }
    
    
}
