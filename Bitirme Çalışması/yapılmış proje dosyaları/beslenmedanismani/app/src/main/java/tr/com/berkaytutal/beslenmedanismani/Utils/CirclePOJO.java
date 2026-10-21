package tr.com.berkaytutal.beslenmedanismani.Utils;

import java.util.ArrayList;

/**
 * Created by berka on 6.06.2017.
 */

public class CirclePOJO extends CircleTekrarAbsPOJO {
    private ArrayList<CircleTekrarAbsPOJO> arraylist;


    private int order;
    private Integer circleID;
    private Integer circleCount;
    private int tekrarCount;

    public CirclePOJO(ArrayList<CircleTekrarAbsPOJO> arraylist, int order, Integer circleID, Integer circleCount, int tekrarCount) {
        this.arraylist = arraylist;
        this.circleCount = circleCount;

        this.order = order;
        this.circleID = circleID;
        this.circleCount = circleCount;
        this.tekrarCount = tekrarCount;
    }

    public ArrayList<CircleTekrarAbsPOJO> getArraylist() {
        return arraylist;
    }

    public void setArraylist(ArrayList<CircleTekrarAbsPOJO> arraylist) {
        this.arraylist = arraylist;
    }


    public int getOrder() {
        return order;
    }

    public void setOrder(int order) {
        this.order = order;
    }

    public Integer getCircleID() {
        return circleID;
    }

    public void setCircleID(Integer circleID) {
        this.circleID = circleID;
    }

    public Integer getCircleCount() {
        return circleCount;
    }

    public void setCircleCount(Integer circleCount) {
        this.circleCount = circleCount;
    }

    public int getTekrarCount() {
        return tekrarCount;
    }

    public void setTekrarCount(int tekrarCount) {
        this.tekrarCount = tekrarCount;
    }

    @Override
    public boolean isCircle() {
        return true;
    }

    @Override
    public boolean isTekrar() {
        return false;
    }

    @Override
    public int getID() {
        return arraylist.get(0).getID();
    }

}
