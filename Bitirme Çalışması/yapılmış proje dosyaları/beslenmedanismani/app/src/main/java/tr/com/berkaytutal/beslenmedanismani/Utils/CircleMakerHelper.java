package tr.com.berkaytutal.beslenmedanismani.Utils;

import java.util.ArrayList;

/**
 * Created by berka on 6.06.2017.
 */

public class CircleMakerHelper {


    public ArrayList<CircleTekrarAbsPOJO> makeCircleWithThis(ArrayList<ExercisePOJO> exercisePOJOs) {

        ArrayList<CircleTekrarAbsPOJO> tempExercisez = new ArrayList<>();
        tempExercisez.addAll(exercisePOJOs);

//        return handleTekrars(tempExercisez);
        return handleCircles(tempExercisez);

    }


    private ArrayList<CircleTekrarAbsPOJO> handleTekrars(ArrayList<ExercisePOJO> exercisePOJOs) {

        ArrayList<CircleTekrarAbsPOJO> arrayListTOTAL = new ArrayList<>();


        for (int i = 0; i < exercisePOJOs.size(); i++) {
            if (i + 1 < exercisePOJOs.size()) {
                if (exercisePOJOs.get(i).getExercises_ID() == exercisePOJOs.get(i + 1).getExercises_ID()) {
                    ArrayList<ExercisePOJO> arrayList2 = new ArrayList<>();
                    int j = i;
                    while ((exercisePOJOs.get(i).getExercises_ID() == exercisePOJOs.get(j).getExercises_ID())) {
                        arrayList2.add(exercisePOJOs.get(j));
                        j++;
                        if (j >= exercisePOJOs.size()) {
                            break;
                        }
                    }

                    arrayListTOTAL.add(new TekrarPOJO(arrayList2));

                    i = j - 1;
                } else {
                    arrayListTOTAL.add(exercisePOJOs.get(i));

                }
            } else {
                arrayListTOTAL.add(exercisePOJOs.get(i));
            }

        }

        return arrayListTOTAL;

    }

    public ArrayList<CircleTekrarAbsPOJO> handleCircles(ArrayList<CircleTekrarAbsPOJO> exercisePOJOs) {

        ArrayList<CircleTekrarAbsPOJO> arrayList = new ArrayList<>(exercisePOJOs);


        for (int i = 0; i < arrayList.size(); i++) {


            Integer circleStart = arrayList.get(i).getCircleID();
            if (circleStart != null) {
                arrayList = makeCircleBetween(arrayList, circleStart, i);

                i = -1;

            }

        }
        return arrayList;


    }

    protected ArrayList<CircleTekrarAbsPOJO> makeCircleBetween(ArrayList<CircleTekrarAbsPOJO> arrayList, int orderStart, int indexEndIncluded) {
        ArrayList<CircleTekrarAbsPOJO> temp = new ArrayList<>();
        ArrayList<CircleTekrarAbsPOJO> temp2 = new ArrayList<>();

        int i = 0;

        boolean makeCircle = false;
        while (i <= indexEndIncluded) {
            CircleTekrarAbsPOJO obj = arrayList.get(i);
            if (obj.getOrder() == orderStart) {
                makeCircle = true;
            }
            if (makeCircle) {
                temp2.add(obj);
            } else {
                temp.add(obj);
            }
            i++;
        }


        temp.add(new CirclePOJO(temp2, temp2.get(0).getOrder(), temp2.get(0).getCircleID(), temp2.get(0).getCircleID(), temp2.get(temp2.size() - 1).getCircleCount()));
        while (i < arrayList.size()) {
            temp.add(arrayList.get(i));
            i++;
        }

        return temp;
    }
}
