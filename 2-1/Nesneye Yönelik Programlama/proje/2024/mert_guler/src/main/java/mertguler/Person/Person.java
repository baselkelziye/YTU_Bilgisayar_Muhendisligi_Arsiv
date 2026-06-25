package mertguler.Person;

import java.io.Serial;
import java.io.Serializable;

public class Person implements Serializable {
    @Serial
    private static final long serialVersionUID = 1L;
    
    private String name;
    private final long national_id;


    public Person(String name, long national_id){
        this.name = name;
        this.national_id = national_id;
    }

    public String getName(){
        return name;
    }

    public void setName(String name){
        this.name = name;
    }

    public long getNational_id(){
        return national_id;
    }

    @Override
    public boolean equals(Object object){
        if (this == object){
            return true;
        }

        if (!(object instanceof Person)){
            return false;
        }

        Person comparedPerson = (Person) object;

        if (this.national_id == comparedPerson.national_id){
            return true;
        }

        return false;
    }

    @Override
    public String toString(){
        return name + ", " + national_id;
    }
}
