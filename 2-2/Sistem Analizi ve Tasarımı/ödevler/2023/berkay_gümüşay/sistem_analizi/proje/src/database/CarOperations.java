package Database;

import Entities.Car;
import Helper.DBConnector;

import javax.swing.text.html.parser.Entity;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Date;

public class CarOperations {
    public void addCar(Entities.Car car) {
        PreparedStatement statement = null;
        try{
            String query = "INSERT INTO arabalar (plaka, modelAdi, fiyat, yil, toplamVergi) VALUES (?, ?, ?, ?, ?)";
            statement = DBConnector.getConnection().prepareStatement(query);
            statement.setString(1, car.getPlate());
            statement.setString(2, car.getModel());
            statement.setDouble(3, car.getPrice());
            statement.setInt(4, car.getYear());
            statement.setDouble(5,car.getTotalTax());
            statement.executeUpdate();
        }catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public int deleteCar(String plate) {
        PreparedStatement statement = null;
        try{
            String query = "DELETE FROM arabalar WHERE plaka=?";
            statement = DBConnector.getConnection().prepareStatement(query);
            statement.setString(1, plate);
            int rowsDeleted = statement.executeUpdate();
            return rowsDeleted;
        }catch (SQLException e) {
            e.printStackTrace();
        }
        return -1;
    }


    public void renting(String tc, String plate, Integer totalDay) {
        PreparedStatement upd_stmnt = null;
        try{
            LocalDate tdy_temp = LocalDate.now();
            LocalDate lastDay_temp = tdy_temp.plusDays(totalDay);
            java.sql.Date tdy = java.sql.Date.valueOf(tdy_temp);
            java.sql.Date lastDay = java.sql.Date.valueOf(lastDay_temp);

            String upd = "UPDATE arabalar SET sahip = ? , alinanTarih = ?, verilecekTarih = ? WHERE plaka = ?";
            upd_stmnt = DBConnector.getConnection().prepareStatement(upd);
            upd_stmnt.setString(1,tc);
            upd_stmnt.setDate(2,tdy);
            upd_stmnt.setDate(3,lastDay);
            upd_stmnt.setString(4,plate);
            upd_stmnt.executeUpdate();

        }catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void updateCars(){
         CustomerOperations updateCustomer = new CustomerOperations();
         Statement statement = null;

         try{
             statement = DBConnector.getConnection().createStatement();
             String query = "SELECT sahip,plaka, verilecekTarih FROM arabalar";
             ResultSet resultSet = statement.executeQuery(query);
             LocalDate tdy = LocalDate.now();

             while(resultSet.next()) {
                 String plate = resultSet.getString("plaka");
                 java.sql.Date lastDay = resultSet.getDate("verilecekTarih");
                 if(lastDay != null && lastDay.toLocalDate().isBefore(tdy)) {
                     String tc = resultSet.getString("sahip");
                     updateCustomer.updateCustomer(tc,plate);
                     String upd = "UPDATE arabalar SET sahip = ?, alinanTarih = ?, verilecekTarih = ? WHERE plaka = ?";
                     PreparedStatement upd_stmnt = DBConnector.getConnection().prepareStatement(upd);
                     upd_stmnt.setString(1,null);
                     upd_stmnt.setDate(2,null);
                     upd_stmnt.setDate(3,null);
                     upd_stmnt.setString(4,plate);
                     upd_stmnt.executeUpdate();
                 }
             }

         }catch (SQLException e) {
             e.printStackTrace();
         }
    }

    public List<Entities.Car> setList() {
        List<Entities.Car> newList = new ArrayList<Entities.Car>();
        Statement statement = null;
        try{
            statement = DBConnector.getConnection().createStatement();
            ResultSet rs = statement.executeQuery("SELECT * FROM arabalar");

            while(rs.next()) {
                Entities.Car tempCar = new Car();
                tempCar.setModel(rs.getString("modelAdi"));
                tempCar.setPlate(rs.getString("plaka"));
                tempCar.setOwnerName(rs.getString("sahip"));
                tempCar.setYear(rs.getInt("yil"));
                tempCar.setPrice(rs.getDouble("fiyat"));
                tempCar.setTotalTax(rs.getDouble("toplamVergi"));
                tempCar.setFirstDate(rs.getDate("alinanTarih"));
                tempCar.setLastDate(rs.getDate("verilecekTarih"));

                newList.add(tempCar);
            }


        }catch (SQLException e) {
            e.printStackTrace();
        }

        return newList;
    }
}
