package Database;

import Entities.Car;
import Entities.Customer;
import Helper.DBConnector;

import javax.swing.*;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class CustomerOperations {

    public void addCustomer(Entities.Customer customer) {
         PreparedStatement statement = null;
        try{
            String query = "INSERT INTO musteriler (Name, Surname, TCNo, BirthDate) VALUES (?, ?, ?, ?)";
            statement = DBConnector.getConnection().prepareStatement(query);
            statement.setString(1, customer.getName());
            statement.setString(2, customer.getSurname());
            statement.setString(3, customer.getTC());
            statement.setString(4, customer.getBirthDate());
            statement.executeUpdate();

        }catch (SQLException e){
            e.printStackTrace();

        }
    }

    public int deleteCustomer(String tc) {
        PreparedStatement statement = null;
        try{
            String query = "DELETE FROM musteriler WHERE TCNo=?";
            statement = DBConnector.getConnection().prepareStatement(query);
            statement.setString(1, tc);
            int rowsDeleted = statement.executeUpdate();
            return rowsDeleted;
        }catch (SQLException e) {
            e.printStackTrace();
        }
        return -1;
    }

    public void renting(String tc, String plate , Double totalPrice) {
        FinanceOperations fo = new FinanceOperations();
        fo.rentingUpdate(plate,tc,totalPrice);
        PreparedStatement statement = null;
        try{
            String query = "SELECT Car , toplamGider FROM musteriler WHERE TCNo = ?";
            statement = DBConnector.getConnection().prepareStatement(query);
            statement.setString(1,tc);
            ResultSet resultSet = statement.executeQuery();
            while(resultSet.next()) {
                String car = resultSet.getString("Car");
                Integer currentValue = resultSet.getInt("toplamGider");
                if(car.equals("Yok")) {
                    String upd = "UPDATE musteriler SET Car = ? , toplamGider = ? WHERE TCNo = ?";
                    PreparedStatement upd_stmnt = DBConnector.getConnection().prepareStatement(upd);
                    upd_stmnt.setString(1, plate);
                    upd_stmnt.setDouble(2,totalPrice + currentValue);
                    upd_stmnt.setString(3, tc);
                    upd_stmnt.executeUpdate();
                }
                else {
                    String upd = "UPDATE musteriler SET Car = CONCAT(Car, ? ) , toplamGider = ? WHERE TCNo = ?";
                    PreparedStatement upd_stmnt = DBConnector.getConnection().prepareStatement(upd);
                    upd_stmnt.setString(1,"," + plate);
                    upd_stmnt.setDouble(2,totalPrice + currentValue);
                    upd_stmnt.setString(3,tc);
                    upd_stmnt.executeUpdate();
                }
            }

        }catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void updateCustomer(String tc, String plate) {
        PreparedStatement checkStatement = null;
        try{
            String checkQuery = "SELECT Car FROM musteriler WHERE TCNo = ?";
            checkStatement = DBConnector.getConnection().prepareStatement(checkQuery);
            checkStatement.setString(1,tc);
            ResultSet resultSet = checkStatement.executeQuery();
            if (resultSet.next()) {
                String carValue = resultSet.getString("Car");
                String[] carNames = carValue.split(",");
                String newCar = "";
                boolean isDeleted = false;

                for(int i=0;i<carNames.length;i++) {
                    if(!carNames[i].equals(plate)) {
                        newCar += carNames[i];
                        if((i+1 < carNames.length && isDeleted) || (i+2 < carNames.length && !isDeleted) )
                            newCar += ",";
                    }
                    else
                        isDeleted = true;
                }
                if(newCar.equals("")) newCar = "Yok";

                String upd = "UPDATE musteriler SET Car = ?  WHERE TCNo = ?";
                PreparedStatement upd_stmnt = DBConnector.getConnection().prepareStatement(upd);
                upd_stmnt.setString(1, newCar);
                upd_stmnt.setString(2, tc);
                upd_stmnt.executeUpdate();
            }
        }catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public List<Entities.Customer> setList() {
        List<Entities.Customer> newList =  new ArrayList<Entities.Customer>();
        Statement statement = null;
        try{
            statement = DBConnector.getConnection().createStatement();
            ResultSet rs = statement.executeQuery("SELECT * FROM musteriler");

            while(rs.next()) {
                String name = rs.getString("Name");
                String surName = rs.getString("Surname");
                String tc = rs.getString("TCNo");
                String birthDate = rs.getString("BirthDate");
                String carNames = rs.getString("Car");
                Double totalDebt = rs.getDouble("toplamGider");
                Entities.Customer tempCustomer = new Customer(name,surName,tc,birthDate);
                tempCustomer.setCarNames(carNames);
                tempCustomer.setTotalDebt(totalDebt);
                newList.add(tempCustomer);
            }


        }catch (SQLException e) {
            e.printStackTrace();
        }


        return newList;

    }


}
