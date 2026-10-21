package mobilprogramlama.ders.berkay.hm1_quiz.model;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;

/**
 * Created by mberk on 18.11.2015.
 */
public class Player {
    private long playerID;
    private String name;
    private String birthday;
    private int score;

    public Player(String name, String birthday){
        this.name = name;
        this.birthday = birthday;
    }

    public Player(long playerID, String name, String birthday){
        this.playerID = playerID;
        this.name = name;
        this.birthday = birthday;
    }

    public long getPlayerID() {
        return playerID;
    }

    public void setPlayerID(long playerID) {
        this.playerID = playerID;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getBirthday() {
        return birthday;
    }

    public int getAge(){
        SimpleDateFormat format1 = new SimpleDateFormat("dd-MM-yyyy");

        try {
            Date date = format1.parse(birthday);

            Calendar dob = Calendar.getInstance();
            dob.setTime(date);
            Calendar today = Calendar.getInstance();
            int age = today.get(Calendar.YEAR) - dob.get(Calendar.YEAR);
            if (today.get(Calendar.DAY_OF_YEAR) < dob.get(Calendar.DAY_OF_YEAR))
                age--;
            return age;
        } catch (ParseException e) {
            e.printStackTrace();

            return -1;
        }

    }

    public void setBirthday(String birthday) {
        this.birthday = birthday;
    }

    public int getScore() {
        return score;
    }

    public void setScore(int score) {
        this.score = score;
    }
}
