package mertguler.Person;

import mertguler.Hospital.Schedule;

public class Doctor extends Person{
    private final int diploma_id;
    private Schedule schedule;
    private int maxPatientPerDay;

    public Doctor(String name, long national_id, int diploma_id){
        super(name,national_id);
        this.diploma_id = diploma_id;
        maxPatientPerDay = 10;
        createSchedule();
    }

    private void createSchedule(){
        schedule = new Schedule(maxPatientPerDay);
        schedule.setDoctor(this);
    }

    public Schedule getSchedule(){
        return schedule;
    }

    public int getDiploma_id(){
        return diploma_id;
    }

    // Might be used in the future
    public void resetSchedule(){
        schedule.getSessions().clear();
    }

    // Might be used in the future
    public void changeMaxPatientPerDay(int maxPatientPerDay){
        this.maxPatientPerDay = maxPatientPerDay;
    }


    @Override
    public boolean equals(Object object){
        if (this == object){
            return true;
        }

        if (!(object instanceof Doctor)){
            return false;
        }

        Doctor comparedDoctor = (Doctor) object;

        // Should we check for national id, would be better for frauds of course.
        if (this.diploma_id == comparedDoctor.getDiploma_id() || this.getNational_id() == (comparedDoctor.getNational_id())){
            return true;
        }

        return false;
    }

    @Override
    public String toString(){
        return super.getName() + ", Diploma ID: " + diploma_id;
    }

}
