package com.ohk.calendar101;
import androidx.room.Dao;
import  androidx.room.Delete;
import  androidx.room.Insert;
import androidx.room.OnConflictStrategy;
import  androidx.room.Query;
import  androidx.room.Update;
import java.util.List;

@Dao
public interface EventDao {

    @Query("SELECT * FROM event")
    List<Event> getAllEvents();

    @Query("SELECT * FROM event WHERE calendarStart>:date AND calendarStart<:finishDate")
    List<Event> getEvent(Long date,Long finishDate);

    @Query("SELECT * FROM event WHERE id=:id")
    Event selectEvent(int id);
    @Insert(onConflict = OnConflictStrategy.REPLACE)
    void insert(Event event);

    @Update
    void update(Event event);

    @Delete
    void delete(Event event);
}
