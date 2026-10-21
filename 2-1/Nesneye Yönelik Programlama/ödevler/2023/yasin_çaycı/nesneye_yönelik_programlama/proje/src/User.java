package a;

import java.io.Serializable;
import java.util.ArrayList;

public class User extends Person implements Serializable{

	private static final long serialVersionUID = 1L;
	private ArrayList<Exercise> exercises;
	private static int ID = 2001100001;
	public User(String username, String password, ArrayList<Exercise> exercises) {
        super(username,password);
        this.exercises = exercises;
        ID++;
    }
	public ArrayList<Exercise> getExercises() {
		return exercises;
	}
	public void setExercises(ArrayList<Exercise> exercises) {
		this.exercises = exercises;
	}
	public static int getID() {
		return ID;
	}
	
}
