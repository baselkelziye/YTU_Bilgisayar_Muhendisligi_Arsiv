package tr.com.berkaytutal.beslenmedanismani.Utils;

/**
 * Created by berka on 6.06.2017.
 */

public abstract class CircleTekrarAbsPOJO {

    public boolean isCircle(){
        return false;
    }
    public boolean isTekrar(){
        return false;
    }
    private int order;
    private Integer circleID;
    private Integer circleCount;

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

    public abstract int getID();


}
