import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Sistem {
    private static Connection con = null;
    private static Statement statement = null;
    private static PreparedStatement preparedStatement = null;
    
    private static ArrayList<Musteri> musteriler;
    private static ArrayList<Siparis> siparisler;
    private static ArrayList<Ilac> ilaclar;
    
    public static void baglan(){
        // "jbdc:mysql://localhost:3306/demo" 
        String url = "jdbc:mysql://" + DataBase.host + ":" + DataBase.port + "/" + DataBase.db_ismi+ "?useUnicode=true&characterEncoding=utf8";
        
        try {
            Class.forName("com.mysql.jdbc.Driver");
        } catch (ClassNotFoundException ex) {
            System.out.println("Driver Bulunamadi....");
        }
        
        try {
            con = DriverManager.getConnection(url, DataBase.kullanici_adi, DataBase.parola);
            System.out.println("Baglanti Basarili...");
        } catch (SQLException ex) {
            System.out.println("Baglanti Basarisiz...");
            //ex.printStackTrace();
        }
    }
    
    public static ArrayList<Ilac> ilaclariGetir(){
        ilaclar = new ArrayList<>();
        
        try {
            statement = con.createStatement();
            String sorgu="Select * From  ilaclar";
            
            ResultSet rs = statement.executeQuery(sorgu);
            
            while (rs.next()) {                
                String isim =rs.getString("isim");
                int barkodno=rs.getInt("barkodno");
                String tur= rs.getString("tur");
                int fiyat = rs.getInt("fiyat");
                int adet = rs.getInt("adet");
                
                ilaclar.add(new Ilac(isim, barkodno, tur, fiyat, adet));
            }
            
            return ilaclar;
            
        } catch (SQLException ex) {
            Logger.getLogger(Sistem.class.getName()).log(Level.SEVERE, null, ex);
            return null;
        }
    }
    
    public static void ilacEkle(String isim , String tur , String fiyat , String adet){
        String  sorgu = "Insert Into ilaclar (isim,tur,fiyat,adet) VALUES(?,?,?,?)";
        
        try {
            preparedStatement = con.prepareStatement(sorgu);
            
            preparedStatement.setString(1, isim);
            preparedStatement.setString(2, tur);
            preparedStatement.setString(3, fiyat);
            preparedStatement.setString(4, adet);
            
            preparedStatement.executeUpdate();
        } catch (SQLException ex) {
            Logger.getLogger(Sistem.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public static void stokGuncelle(String isim , int yeniadet ){
        String sorgu = "Update ilaclar set  adet = ?  where isim = ?";
        
        try {
            preparedStatement=con.prepareStatement(sorgu);
            
            preparedStatement.setString(1, String.valueOf(yeniadet));
            preparedStatement.setString(2, isim);
            
            preparedStatement.executeUpdate();
        } catch (SQLException ex) {
            Logger.getLogger(Sistem.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    
    
    public static void ilacGuncelle(int barkodno,String yeni_isim ,String yeni_tur , String yeni_fiyat ,String yeni_adet){
        String sorgu = "Update ilaclar set isim = ? , tur = ? , fiyat = ? , adet = ?  where barkodno = ?";
        
        try {
            preparedStatement=con.prepareStatement(sorgu);
            
            preparedStatement.setString(1, yeni_isim);
            preparedStatement.setString(2, yeni_tur);
            preparedStatement.setString(3, yeni_fiyat);
            preparedStatement.setString(4, yeni_adet);
            
            preparedStatement.setInt(5, barkodno);
            
            preparedStatement.executeUpdate();
        } catch (SQLException ex) {
            Logger.getLogger(Sistem.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    
    
    public static boolean girisYapAdmin(String kullanici_adi , String parola){
        String sorgu ="Select * From adminler where username = ? and password = ?";
        
        try {
            preparedStatement=con.prepareStatement(sorgu);
            
            preparedStatement.setString(1, kullanici_adi);
            preparedStatement.setString(2, parola);
            
            ResultSet rs= preparedStatement.executeQuery();
            
            return rs.next();
            
        } catch (SQLException ex) {
            Logger.getLogger(Sistem.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }
    }
    
    public static void ilacSil(int barkodno){
        String sorgu ="Delete from ilaclar where barkodno = ?";
        
        try {
            preparedStatement=con.prepareStatement(sorgu);
            
            preparedStatement.setInt(1, barkodno);
            
            preparedStatement.executeUpdate();
        } catch (SQLException ex) {
            Logger.getLogger(Sistem.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public static void siparisEkle(String eczaneismi , String eczaneno ,String siparis ,String tutar ){
        String  sorgu = "Insert Into siparisler (eczaneismi,eczaneno,siparis,tutar,tamamlandi) VALUES(?,?,?,?,?)";
        
        try {
            preparedStatement = con.prepareStatement(sorgu);
            
            preparedStatement.setString(1, eczaneismi);
            preparedStatement.setString(2, eczaneno);
            preparedStatement.setString(3, siparis);
            preparedStatement.setString(4, tutar);
            preparedStatement.setString(5, "0");
            
            preparedStatement.executeUpdate();
            
        } catch (SQLException ex) {
            Logger.getLogger(Sistem.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public static void musteriEkle(String isim , String adres , String telefonno , String username,String password){
        String  sorgu = "Insert Into eczaneler (isim,adres,telefonno,username,password) VALUES(?,?,?,?,?)";
        
        try {
            preparedStatement = con.prepareStatement(sorgu);
            
            preparedStatement.setString(1, isim);
            preparedStatement.setString(2, adres);
            preparedStatement.setString(3, telefonno);
            preparedStatement.setString(4, username);
            preparedStatement.setString(5, password);
            
            preparedStatement.executeUpdate();
        } catch (SQLException ex) {
            Logger.getLogger(Sistem.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public static Musteri musteriBul(String kullanici_adi){
        musteriler =musterileriGetir();
        
        for(Musteri i : musteriler) {
            if(i.getKullaniciadi().equals(kullanici_adi)) {
                return i;
            }
        }
        return null;
        
    }
    
    public static void musteriBilgisiGuncelle(int eczaneno ,String isim, String adres,String telefonno,String kullaniciadi,String parola){
        String sorgu = "Update eczaneler set isim = ? , adres = ? , telefonno = ? , username = ? , password = ?  where eczaneno = ?";
        
        try {
            preparedStatement=con.prepareStatement(sorgu);
            
            preparedStatement.setString(1, isim);
            preparedStatement.setString(2, adres);
            preparedStatement.setString(3, telefonno);
            preparedStatement.setString(4, kullaniciadi);
            preparedStatement.setString(5, parola);
            
            preparedStatement.setInt(6, eczaneno);
            
            preparedStatement.executeUpdate();
        } catch (SQLException ex) {
            Logger.getLogger(Sistem.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public static ArrayList<Musteri> musterileriGetir(){
        musteriler = new ArrayList<Musteri>();
        
        try {
            statement = con.createStatement();
            String sorgu ="Select * From eczaneler";
            
            ResultSet rs = statement.executeQuery(sorgu);
            
            while (rs.next()){
                String isim = rs.getString("isim");
                String adres = rs.getString("adres");
                int eczaneno = rs.getInt("eczaneno");
                String telno = rs.getString("telefonno");
                String kullaniciadi = rs.getString("username");
                String parola = rs.getString("password");
                musteriler.add(new Musteri(eczaneno,isim,adres,telno,kullaniciadi, parola));
            }
            return musteriler;
        } catch (SQLException ex) {
            Logger.getLogger(Sistem.class.getName()).log(Level.SEVERE, null, ex);
            return null;
        }
    }
    
    
    public static boolean girisYapMusteri(String kullanici_adi , String parola){
        String sorgu ="Select * From eczaneler where username = ? and password = ?";
        
        try {
            statement = con.createStatement();
            preparedStatement=con.prepareStatement(sorgu);
            
            preparedStatement.setString(1, kullanici_adi);
            preparedStatement.setString(2, parola);
            
            ResultSet rs= preparedStatement.executeQuery();
            
            return rs.next();
            
        } catch (SQLException ex) {
            Logger.getLogger(Sistem.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }
    }
    
    public static void siparisGonder(int siparisno ){
        String sorgu = "Update siparisler set tamamlandi = ? where siparisno = "+siparisno;
        
        try {
            preparedStatement=con.prepareStatement(sorgu);
            
            preparedStatement.setString(1, "1");
           
            preparedStatement.executeUpdate();
        } catch (SQLException ex) {
            Logger.getLogger(Sistem.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    public static String siparisGetir(int siparisno){
        String siparis = null;
        
        try {
            statement = con.createStatement();
            String sorgu="SELECT siparis FROM siparisler WHERE siparisno = "+siparisno;
            
            ResultSet rs =statement.executeQuery(sorgu);
            
            while(rs.next()){
                siparis =rs.getString("siparis");
            }
            return siparis;
        } catch (SQLException ex) {
            Logger.getLogger(Sistem.class.getName()).log(Level.SEVERE, null, ex);
            return null;
        }
    }
    
    public static ArrayList<Siparis> siparisleriGetir(){
        siparisler = new ArrayList<Siparis>();
        
        try {
            statement = con.createStatement();
            String sorgu="Select * From  siparisler";
            
            ResultSet rs = statement.executeQuery(sorgu);
            
            while (rs.next()) {                
                String eczaneisim =rs.getString("eczaneismi");
                int eczaneno=rs.getInt("eczaneno");
                int siparisno= rs.getInt("siparisno");
                String siparis = rs.getString("siparis");
                String tutar = rs.getString("tutar");
                String tamamlandi=rs.getString("tamamlandi");
                
                siparisler.add(new Siparis(eczaneisim, eczaneno, siparisno, siparis, tutar,tamamlandi));
            }
            return siparisler;
        } catch (SQLException ex) {
            Logger.getLogger(Sistem.class.getName()).log(Level.SEVERE, null, ex);
            return null;
        }
    }

    public static ArrayList<Musteri> getMusteriler() {
        return musteriler;
    }

    public static ArrayList<Siparis> getSiparisler() {
        return siparisler;
    }

    public static ArrayList<Ilac> getIlaclar() {
        return ilaclar;
    }
    
    
    
}
