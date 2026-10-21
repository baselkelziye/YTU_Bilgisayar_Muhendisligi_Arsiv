/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package movie.rating.system;

/**
 *
 * @author bilal
 */
public class MovieRatingSystem {

    /**
     */
    
    static Kullanici kullanici;
    public MovieRatingSystem(){
        Veritabani.connect();
        
    }
    
    public static void main(String[] args) {
        // TODO code application logic here
        MovieRatingSystem movieRatingSystem = new MovieRatingSystem();
        
        GirisEkrani girisEkrani = new GirisEkrani();
        girisEkrani.setLocation(550,250);
        girisEkrani.setVisible(true);
        
    }
    
}
