/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package credibility_system;

/**
 *
 * @author Miracetdin
 */

import java.io.File;
import java.sql.*;
import java.util.logging.Level;
import java.util.logging.Logger;


public class Database {
    static String url = "jdbc:postgresql://localhost:5432/Credibility";
    static Connection connection = null;
    
    // database connection function
    static void connect(){
        try {
            connection = DriverManager.getConnection(url,"postgres","password");
            System.out.println("Database connection is established.");
        } catch (SQLException ex) {
            System.out.println("Error: Database connection is not established!");
            Logger.getLogger(Database.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    // function that checks whether the searched user/banker exists in the database
    static boolean isUserExists(String username,String password){
        String SQL = "select * from banker where username='"+username+"' and password='"+password+"'";
        Statement statement;
        try {
            statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery(SQL);
            if(resultSet.next()){
                return true;
            }
        } catch (SQLException ex) {
            Logger.getLogger(Database.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }
        return false;
    }
    
    static ResultSet list(String query){
        try {
            Statement statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery(query);
            return resultSet;
        } catch (SQLException ex) {
            Logger.getLogger(Database.class.getName()).log(Level.SEVERE, null, ex);
            return null;
        }
    }
    
    // function that checks informations on the login screen
    static String logIn(String username, String password){
        String string = null;
        
        if(isUserExists(username, password)){
            String SQL = "select name from banker where username='"+username+"'";
            Statement statement;
        try {
            statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery(SQL);
            while(resultSet.next()){
                string = resultSet.getString("name");
            }
        } catch (SQLException ex) {
            Logger.getLogger(Database.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        String[] parts = string.split(",");
        String surname = parts[0];
        String name = parts[1];

        return ("Welcome" + name + " " + surname);
            
        }
        else{
            System.out.println("Login failed!");
        }
        return null;
    }
    
    // function that checks whether the searched customer exists in the database
    static boolean isCustomerExists(int id){
        String SQL = "select * from customer where ID='"+id+"'";
        Statement statement;
        try {
            statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery(SQL);
            if(resultSet.next()){
                return true;
            }
        } catch (SQLException ex) {
            Logger.getLogger(Database.class.getName()).log(Level.SEVERE, null, ex);
            return false;
        }
        return false;
    }
    
    // function that updates the customer's information about accepting the loan and the interest rate
    static void updateCustomerAccept(String Column, int id, String accept){
        String SQL = "update customer set "+Column+"=? where ID='"+id+"'";
        try {
            PreparedStatement preparedStatement = Database.connection.prepareStatement(SQL);
            preparedStatement.setString(1, accept);
            preparedStatement.executeUpdate();
        } catch (SQLException ex) {
            Logger.getLogger(Database.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    // function that adds a customer to the database
    static void insertCustomer(int id, String name, int age, String sex, String education, int income, String home, int debt, int amount, String loan, double rate, String accept, int grade){
        String SQL = "insert into customer(ID, name, age, sex, education, income, home, debt, amount, loan, rate, accept, grade)"
                + "values(?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";
        try {
            PreparedStatement preparedStatement = connection.prepareStatement(SQL);
            preparedStatement.setInt(1, id);
            preparedStatement.setString(2, name);
            preparedStatement.setInt(3, age);
            preparedStatement.setString(4, sex);
            preparedStatement.setString(5, education);
            preparedStatement.setInt(6, income);
            preparedStatement.setString(7, home);
            preparedStatement.setInt(8, debt);
            preparedStatement.setInt(9, amount);
            preparedStatement.setString(10, loan);
            preparedStatement.setDouble(11, rate);
            preparedStatement.setString(12, accept);
            preparedStatement.setInt(13, grade);
            preparedStatement.executeUpdate();
            preparedStatement.close();
        } catch (SQLException ex) {
            Logger.getLogger(Database.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    // The function that finds the total number of customers who accept the loan among the customers who can get a loan
    static int getCountAccept(String table, String accept, String approve){
        int count=0;
        String SQL = "select count(*) from " + table + " where accept='" + accept + "' and loan='" + approve + "'";
        Statement statement;
        try {
            statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery(SQL);
            if(resultSet.next()){
                count = resultSet.getInt("count");
            }
        } catch (SQLException ex) {
            Logger.getLogger(Database.class.getName()).log(Level.SEVERE, null, ex);
            count = 0;
        }
        return count;
    }
    
    // The function that finds the total number of customers who do not accept the loan among the customers who can get a loan
    static int getCountNotaccept(String table, String notaccept, String approve){
        int count=0;
        String SQL = "select count(*) from " + table + " where accept='" + notaccept + "' and loan='" + approve + "'";
        Statement statement;
        try {
            statement = connection.createStatement();
            ResultSet resultSet = statement.executeQuery(SQL);
            if(resultSet.next()){
                count = resultSet.getInt("count");
            }
        } catch (SQLException ex) {
            Logger.getLogger(Database.class.getName()).log(Level.SEVERE, null, ex);
            count = 0;
        }
        return count;
    }
}
