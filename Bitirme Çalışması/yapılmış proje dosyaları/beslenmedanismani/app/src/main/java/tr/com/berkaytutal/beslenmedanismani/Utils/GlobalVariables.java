package tr.com.berkaytutal.beslenmedanismani.Utils;

import android.app.Application;

import java.util.ArrayList;
import java.util.HashMap;

/**
 * Created by berka on 21.05.2017.
 */

public class GlobalVariables extends Application {

    private boolean isOnline = true;

    private boolean switchOnlineOffline = false;
    private boolean switchFromOffline = false;
    private boolean isShowingOnlineOfflineDialog = false;

    public boolean isShowingOnlineOfflineDialog() {
        return isShowingOnlineOfflineDialog;
    }

    public void setShowingOnlineOfflineDialog(boolean showingOnlineOfflineDialog) {
        isShowingOnlineOfflineDialog = showingOnlineOfflineDialog;
    }

    public HashMap<Integer,Integer> circleCountHolder;



    private ArrayList<ProgramPOJO> allPrograms;
    private ArrayList<TrainerPOJO> allUsers;
    private UserDataPOJO userDataPOJO;
    private ArrayList<ProgramDifficultyPOJO> programDifficulties;
    private ArrayList<ProgramCategoryPOJO> programCategories;


    public boolean isSwitchFromOffline() {
        return switchFromOffline;
    }

    public void setSwitchFromOffline(boolean switchFromOffline) {
        this.switchFromOffline = switchFromOffline;
    }

    public boolean isSwitchOnlineOffline() {
        return switchOnlineOffline;
    }

    public void setSwitchOnlineOffline(boolean switchOnlineOffline) {
        this.switchOnlineOffline = switchOnlineOffline;
    }

    public HashMap<Integer, Integer> getCircleCountHolder() {
        return circleCountHolder;
    }

    public void setCircleCountHolder(HashMap<Integer, Integer> circleCountHolder) {
        this.circleCountHolder = circleCountHolder;
    }

    public boolean isOnline() {
        return isOnline;
    }

    public void setOnline(boolean online) {
        isOnline = online;
    }

    public ArrayList<ProgramDifficultyPOJO> getProgramDifficulties() {

        return programDifficulties;
    }

    public void setProgramDifficulties(ArrayList<ProgramDifficultyPOJO> programDifficulties) {
        this.programDifficulties = programDifficulties;
    }

    public ArrayList<ProgramCategoryPOJO> getProgramCategories() {
        return programCategories;
    }

    public void setProgramCategories(ArrayList<ProgramCategoryPOJO> programCategories) {
        this.programCategories = programCategories;
    }

    public void setUserDataPOJO(UserDataPOJO userDataPOJO){
        this.userDataPOJO=userDataPOJO;
    }

    public UserDataPOJO getUserDataPOJO(){
        return  userDataPOJO;
    }

    public ArrayList<ProgramPOJO> getAllPrograms() {
        return allPrograms;
    }

    public void setAllPrograms(ArrayList<ProgramPOJO> allPrograms) {
        this.allPrograms = allPrograms;
    }

    public ArrayList<ProgramPOJO> getProgramsByTrainerID(int trainerID){
        ArrayList<ProgramPOJO> programs = new ArrayList<>();

        for (ProgramPOJO program : allPrograms) {
            if(program.getTrainerID() == trainerID){
                programs.add(program);
            }

        }
        return programs;


    }

    public ProgramPOJO getProgramByID(int programID){
        for (ProgramPOJO program: allPrograms) {

            if(program.getProgramID() == programID){
                return program;
            }
        }
        return null;
    }

    public ProgramPOJO getProgramByIndex(int index){
        return allPrograms.get(index);
    }

    public ArrayList<TrainerPOJO> getAllUsers() {
        return allUsers;
    }

    public void setAllUsers(ArrayList<TrainerPOJO> allUsers) {
        this.allUsers = allUsers;
    }

    public boolean updateUser(TrainerPOJO trainer){

        for (TrainerPOJO user: allUsers) {

            if(user.getUserID() == trainer.getUserID()){
                int index = allUsers.indexOf(user);
                allUsers.remove(index);
                allUsers.add(index,trainer);
                return true;
            }
        }
        return false;
    }

    public TrainerPOJO getUserByID(int userID){
        for (TrainerPOJO user: allUsers) {

            if(user.getUserID() == userID){
                return user;
            }
        }
        return null;
    }

    public TrainerPOJO getUserByIndex(int index){
        return allUsers.get(index);
    }
}
