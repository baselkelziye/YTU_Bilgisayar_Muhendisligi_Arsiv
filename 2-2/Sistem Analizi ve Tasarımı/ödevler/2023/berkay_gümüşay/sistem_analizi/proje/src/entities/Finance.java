package Entities;

import Database.FinanceOperations;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class Finance {
    private String definition;
    private Date releaseDate;
    private Double cost;


    public Finance(String definition, Date releaseDate, Double cost) {
        this.definition = definition;
        this.releaseDate = releaseDate;
        this.cost = cost;
    }

    public static List<Finance> setList() {
        FinanceOperations sl = new FinanceOperations();
        return sl.setList();

    }

    public String getDefinition() {
        return definition;
    }

    public void setDefinition(String definition) {
        this.definition = definition;
    }

    public Date getReleaseDate() {
        return releaseDate;
    }

    public void setReleaseDate(Date releaseDate) {
        this.releaseDate = releaseDate;
    }

    public Double getCost() {
        return cost;
    }

    public void setCost(Double cost) {
        this.cost = cost;
    }

    public Object[] getObjects() {
        Object[] data = {releaseDate,definition,cost};
        return data;
    }
}
