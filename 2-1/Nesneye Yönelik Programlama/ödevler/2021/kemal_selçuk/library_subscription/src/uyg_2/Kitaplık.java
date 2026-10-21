package uyg2;

public class Kitaplık {
    
    private Raf[] raf;

    public Kitaplık(int n) {
        this.raf = new Raf[n];
        for (int i = 0; i < raf.length; i++){
            raf[i] = new Raf();
        }
    }
    
    public void kitapEkle(Kitap k, int RafNo){
        raf[RafNo].kitapEkle(k);
    }
    public void kitapSil(int RafNo, int SıraNo){
        raf[RafNo].kitapSil(SıraNo);
    }
    public void kitapSil(int RafNo, Kitap k){
        raf[RafNo].kitapSil(k);
    }
    public void rafGoster(int n){
        raf[n].rafGoster();
    }
    public void tumRaflariGoster(){
        for (int i = 0; i < raf.length; i++){
            System.out.println(i + ". Raftaki Kitaplar");
            rafGoster(i);
        }
    }
    public int kitapAra(String KitapAdı){
        int n = raf.length;
        for (int i = 0; i < n; i++){
            for(Kitap kitap: raf[i].getKitaplar()){
                if(kitap != null && kitap.getAd().equals(KitapAdı))
                {
                    System.out.println("Aranan kitap " + i + ". rafta bulunuyor.");
                    return i;
                }                    
            }
        }
        System.out.println("Kitap Yok");
        return -1;
    }
    

    
    
    
}
