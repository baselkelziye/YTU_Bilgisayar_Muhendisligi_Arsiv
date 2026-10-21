/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.ytu.elderlycarecenter;

/**
 *
 * @author ohkam
 */
import java.sql.Date;
import java.sql.*;
import java.util.ArrayList;

public class dbOP {
    private final String host;
    private final String userName;
    private final String password;
    private final Connection connection;

    public dbOP(String host, String userName, String password) throws SQLException {
        this.host = host;
        this.userName = userName;
        this.password = password;
        connection = DriverManager.getConnection(this.host, this.userName, this.password);
        if (connection != null) {
            System.out.println("Connection Complete");
        } else {
            System.out.println("Cannot connect DB ");
        }
    }

    /**
     *
     * CONSTRUCTOR
     * @author omerhamidkamisli
     * @throws java.sql.SQLException
     *
     */
    public dbOP() throws SQLException {
        this.host = "jdbc:postgresql://localhost:5432/elder2";
        this.userName = "postgres";
        this.password = "230905";
        connection = DriverManager.getConnection(this.host, this.userName, this.password);
        if (connection != null) {
            System.out.println("Connection Complete");
        } else {
            System.out.println("Cannot connect DB ");
        }
    }

    public ArrayList<Room> get_rooms(int value) throws SQLException {
        ArrayList<Room> rooms = new ArrayList<>();
        String query = "SELECT get_rooms("+value+")";
        Statement stmt = connection.createStatement();
        ResultSet rs = stmt.executeQuery(query);
        while (rs.next()) {
            String result = rs.getString(1);
            result = result.replace("(","") ;
            result = result.replace(")", "");
            String[] tokens = result.split(",");
            int id= Integer.parseInt(tokens[0]);
            int room_number = Integer.parseInt(tokens[1]);
            Room tmp = new Room(id,room_number);
            rooms.add(tmp);
        }
        return rooms;
    }

    public ArrayList<Elder> get_elders(int value) throws SQLException {
        ArrayList<Elder> elders = new ArrayList<>();
        String query = "SELECT * FROM get_elders_by_age("+value+")";
        Statement stmt = connection.createStatement();
        ResultSet rs = stmt.executeQuery(query);
        while (rs.next()) {
            int id= rs.getInt("id");
            String first_name = rs.getString("first_name");
            String last_name = rs.getString("last_name");
            Date date_of_birth = rs.getDate("date_of_birth");
            String gender = rs.getString("gender");
            int visit_count = rs.getInt("visit_count");
            int room_id = rs.getInt("room_number");
            int room_number = rs.getInt("room_number");
            Room second = new Room(room_id,room_number);
            Elder tmp = new Elder(id,first_name,last_name,date_of_birth,gender, visit_count, second);
            elders.add(tmp);
        }
        return elders;
    }

    public ArrayList<Visitor> get_visitors(int value) throws SQLException {
        ArrayList<Visitor> visitors = new ArrayList<>();
        String query = "SELECT get_visitors("+value+")";
        Statement stmt = connection.createStatement();
        ResultSet rs = stmt.executeQuery(query);
        while (rs.next()) {
            String result = rs.getString(1);
            result = result.replace("(","") ;
            result = result.replace(")", "");
            String[] tokens = result.split(",");
            int id= Integer.parseInt(tokens[0]);
            String first_name = tokens[1];
            String last_name = tokens[2];
            int visit_count = Integer.parseInt(tokens[3]);
            Visitor tmp = new Visitor(id,first_name,last_name,visit_count);
            visitors.add(tmp);
        }
        return visitors;
    }

    public ArrayList<Visit> get_visits() throws SQLException {
        ArrayList<Visit> visits = new ArrayList<>();
        String query = "SELECT * FROM visit_view ORDER BY visit_id";
        Statement stmt = connection.createStatement();
        ResultSet rs = stmt.executeQuery(query);
        while (rs.next()) {
            int visit_id = rs.getInt("visit_id");
            int elder_id = rs.getInt("elder_id");
            String elder_first_name = rs.getString("elder_first_name");
            String elder_last_name = rs.getString("elder_last_name");
            Date visit_time = rs.getDate("visit_time");
            int first_visitor_id = rs.getInt("visitor1_id");
            String first_visitor_first_name = rs.getString("visitor1_first_name");
            String first_visitor_last_name= rs.getString("visitor1_last_name");
            int second_visitor_id = rs.getInt("visitor2_id");
            String second_visitor_first_name = rs.getString("visitor2_first_name");
            String second_visitor_last_name = rs.getString("visitor2_last_name");

            Visit tmp = new Visit(visit_id,elder_id,elder_first_name,elder_last_name,visit_time,first_visitor_id,first_visitor_first_name,first_visitor_last_name,second_visitor_id,second_visitor_first_name,second_visitor_last_name);
            visits.add(tmp);
        }
        return visits;
    }

    public ArrayList<Visit> search_visits(String name) throws SQLException {
        ArrayList<Visit> visits = new ArrayList<>();
        String query = "SELECT * FROM visit_view WHERE elder_first_name LIKE '%"+name+"%' OR elder_last_name LIKE '%"+name+"%' OR visitor1_first_name LIKE '%"+name+"%' OR visitor1_last_name LIKE '%"+name+"%' OR visitor2_first_name LIKE '%"+name+"%' OR visitor2_last_name LIKE '%"+name+"%' ORDER BY visit_id";
        Statement stmt = connection.createStatement();
        ResultSet rs = stmt.executeQuery(query);
        while (rs.next()) {
            int visit_id = rs.getInt("visit_id");
            int elder_id = rs.getInt("elder_id");
            String elder_first_name = rs.getString("elder_first_name");
            String elder_last_name = rs.getString("elder_last_name");
            Date visit_time = rs.getDate("visit_time");
            int first_visitor_id = rs.getInt("visitor1_id");
            String first_visitor_first_name = rs.getString("visitor1_first_name");
            String first_visitor_last_name= rs.getString("visitor1_last_name");
            int second_visitor_id = rs.getInt("visitor2_id");
            String second_visitor_first_name = rs.getString("visitor2_first_name");
            String second_visitor_last_name = rs.getString("visitor2_last_name");

            Visit tmp = new Visit(visit_id,elder_id,elder_first_name,elder_last_name,visit_time,first_visitor_id,first_visitor_first_name,first_visitor_last_name,second_visitor_id,second_visitor_first_name,second_visitor_last_name);
            visits.add(tmp);
        }
        return visits;
    }

    public int insert_visit(int elder_id, int first_visitor_id, int second_visitor_id) throws SQLException {
        PreparedStatement insert = connection.prepareStatement("INSERT INTO visit(first_visitor_id, second_visitor_id, elder_id) VALUES (?, ?, ?)");
        insert.setInt(1, first_visitor_id);
        insert.setInt(2,second_visitor_id);
        insert.setInt(3,elder_id);
        return insert.executeUpdate();
    }

    public int insert_room() throws SQLException {
        PreparedStatement insert = connection.prepareStatement("INSERT INTO room(room_number) VALUES(nextval('room_number'))");
        return insert.executeUpdate();
    }

    public int delete_room(int id) throws SQLException {
        PreparedStatement delete = connection.prepareStatement("DELETE FROM room WHERE id=?");
        delete.setInt(1, id);
        return delete.executeUpdate();
    }

    public int insert_visitor(String first_name, String last_name) throws SQLException {
        PreparedStatement insert = connection.prepareStatement("INSERT INTO visitor(first_name, last_name) VALUES (?, ?)");
        insert.setString(1, first_name);
        insert.setString(2, last_name);
        return insert.executeUpdate();
    }
    
    public int update_visitor(int id,String first_name, String last_name) throws SQLException {
        PreparedStatement insert = connection.prepareStatement("UPDATE visitor SET first_name=?, last_name=? WHERE id=?");
        insert.setString(1, first_name);
        insert.setString(2, last_name);
        insert.setInt(3,id);
        return insert.executeUpdate();
    }
    
     public int delete_visitor(int id) throws SQLException {
        PreparedStatement delete = connection.prepareStatement("DELETE FROM visitor WHERE id=?");
        delete.setInt(1, id);
        return delete.executeUpdate();
    }
    
    public int insert_elder(String first_name,String last_name,Date date_of_birthday,String gender) throws SQLException{
        PreparedStatement insert = connection.prepareStatement("INSERT INTO elder(first_name, last_name, date_of_birth, gender) VALUES (?, ?, ?, ?)");
        insert.setString(1, first_name);
        insert.setString(2, last_name);
        insert.setDate(3,date_of_birthday);
        insert.setString(4,gender);
        return insert.executeUpdate();
    }
    
    public int update_elder(int id,String first_name,String last_name,Date date_of_birthday,String gender) throws SQLException{
        PreparedStatement insert = connection.prepareStatement("UPDATE elder SET first_name=?, last_name=?, date_of_birth=?, gender=? WHERE id=?");
        insert.setString(1, first_name);
        insert.setString(2, last_name);
        insert.setDate(3,date_of_birthday);
        insert.setString(4,gender);
        insert.setInt(5,id);
        return insert.executeUpdate();
    }
    
    public int delete_elder(int id) throws SQLException {
        PreparedStatement delete = connection.prepareStatement("DELETE FROM elder WHERE id=?");
        delete.setInt(1, id);
        return delete.executeUpdate();
    }
    
    public ArrayList<Filter> filter_visit(int count) throws SQLException {
        ArrayList<Filter> visits = new ArrayList<>();
        String query = "SELECT elder_first_name AS NAME,elder_last_name AS SURNAME,COUNT(elder_id) FROM visit_view GROUP BY elder_first_name,elder_last_name HAVING COUNT(elder_id)>="+count+" UNION SELECT visitor1_first_name AS NAME,visitor1_last_name AS SURNAME,COUNT(visitor1_id) FROM visit_view GROUP BY visitor1_first_name,visitor1_last_name HAVING COUNT(visitor1_id)>="+count+" UNION SELECT visitor2_first_name as NAME,visitor2_last_name as SURNAME,COUNT(visitor2_id) FROM visit_view GROUP BY visitor2_first_name,visitor2_last_name HAVING COUNT(visitor2_id)>="+count;
        Statement stmt = connection.createStatement();
        ResultSet rs = stmt.executeQuery(query);
        while (rs.next()) {
            String name = rs.getString("name");
            String surname = rs.getString("surname");
            int visit_count = rs.getInt("count");
           

            Filter tmp = new Filter(name,surname,visit_count);
            visits.add(tmp);
        }
        return visits;
    }
}

