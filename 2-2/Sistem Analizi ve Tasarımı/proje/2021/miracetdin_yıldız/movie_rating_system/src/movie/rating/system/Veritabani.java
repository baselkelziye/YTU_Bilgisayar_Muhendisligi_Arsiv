/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package movie.rating.system;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author bilal
 */
public class Veritabani {
    static String url = "jdbc:postgresql://localhost:5432/postgres";
    static Connection connection = null;
    
    
    static void connect(){
        try {
            connection = DriverManager.getConnection(url,"postgres","0000");
            System.out.println("Veritabanı bağlantısı gerçekleşti");
        } catch (SQLException ex) {
            Logger.getLogger(Veritabani.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    static ResultSet list(String query){
        try {
            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery(query);
            return resultSet;
        } catch (SQLException ex) {
            Logger.getLogger(Veritabani.class.getName()).log(Level.SEVERE, null, ex);
            return null;
        }
    }
    
    static boolean checkUser(String username){
        String SQL = "select * from kullanici where username='"+username+"'";
        Statement statement;
        try {
            statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery(SQL);
            if(resultSet.next()){
                return true;
            }
        } catch (SQLException ex) {
            Logger.getLogger(Veritabani.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }
        return false;
    }
    
    static void insertUser(String username,String password,String name,String surname,String gender){
        String SQL = "insert into kullanici(username,password,name,surname,gender) "
                + "values(?,?,?,?,?)";
        try {
            PreparedStatement preparedStatement = connection.prepareStatement(SQL);
            preparedStatement.setString(1, username);
            preparedStatement.setString(2, password);
            preparedStatement.setString(3, name);
            preparedStatement.setString(4, surname);
            preparedStatement.setString(5, gender);
            preparedStatement.executeUpdate();
            preparedStatement.close();
        } catch (SQLException ex) {
            Logger.getLogger(Veritabani.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    static boolean isUserExists(String username,String password){
        String SQL = "select * from kullanici where username='"+username+"' and password='"+password+"'";
        Statement statement;
        try {
            statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery(SQL);
            if(resultSet.next()){
                return true;
            }
        } catch (SQLException ex) {
            Logger.getLogger(Veritabani.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }
        return false;
    }
    
    static int getCount(String table,String username){
        int count=0;
        String SQL = "select count(*) from "+table+" where username='"+username+"'";
        Statement statement;
        try {
            statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery(SQL);
            if(resultSet.next()){
                count = resultSet.getInt("count");
            }
        } catch (SQLException ex) {
            Logger.getLogger(Veritabani.class.getName()).log(Level.SEVERE, null, ex);
            count = 0;
        }
        return count;
    }
    
    static int getFilmCount(String SQL){
        int count=0;
        Statement statement;
        try {
            statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery(SQL);
            if(resultSet.next()){
                count = resultSet.getInt("count");
            }
        } catch (SQLException ex) {
            Logger.getLogger(Veritabani.class.getName()).log(Level.SEVERE, null, ex);
            count = 0;
        }
        return count;
    }
    
    static void updateUserInfo(String Column, String username, String newName){
        String SQL = "update kullanici set "+Column+"=? where username='"+username+"'";
        try {
            PreparedStatement preparedStatement = Veritabani.connection.prepareStatement(SQL);
            preparedStatement.setString(1, newName);
            preparedStatement.executeUpdate();
        } catch (SQLException ex) {
            Logger.getLogger(Veritabani.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
}
