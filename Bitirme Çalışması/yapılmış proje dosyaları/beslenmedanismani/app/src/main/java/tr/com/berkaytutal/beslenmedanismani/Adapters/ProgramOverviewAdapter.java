package tr.com.berkaytutal.beslenmedanismani.Adapters;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;

import java.util.ArrayList;

import tr.com.berkaytutal.beslenmedanismani.ProgramOverviewActivity;
import tr.com.berkaytutal.beslenmedanismani.ProgramPlayActivity;
import tr.com.berkaytutal.beslenmedanismani.R;
import tr.com.berkaytutal.beslenmedanismani.Utils.CirclePOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.CircleTekrarAbsPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.ExercisePOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.GlobalVariables;
import tr.com.berkaytutal.beslenmedanismani.Utils.TekrarPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.FunctionUtils;

import static android.view.View.GONE;

/**
 * Created by berka on 5.06.2017.
 */

public class ProgramOverviewAdapter extends BaseAdapter {

    private Context context;
    private ArrayList<CircleTekrarAbsPOJO> exercises;
    private LayoutInflater li;
    private Activity activity;
    private boolean comingFromCircle = false;

    public ProgramOverviewAdapter(Activity activity, ArrayList<CircleTekrarAbsPOJO> exercises) {
        this.context = activity.getApplicationContext();
        this.exercises = exercises;
        this.activity = activity;

        li = (LayoutInflater) activity.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
    }

    public void setComingFromCircle(boolean cc) {
        comingFromCircle = cc;
    }

    @Override
    public int getCount() {
        return exercises.size();
    }

    @Override
    public Object getItem(int i) {
        return exercises.get(i);
    }

    @Override
    public long getItemId(int i) {
        int id = -1;
//        return exercises.get(i).getOrder();
        if (exercises.get(i).isTekrar() && !exercises.get(i).isCircle()) {
            id = ((TekrarPOJO) exercises.get(i)).getID();
        } else if (!exercises.get(i).isTekrar() && !exercises.get(i).isCircle()) {
            id = ((ExercisePOJO) exercises.get(i)).getExercises_ID();
        }

        return exercises.get(i).getOrder();
    }

    @Override
    public View getView(final int i, View view, ViewGroup viewGroup) {
//        if(exercises.get(i).isCircle()){

        int berkay = 0;
        if (exercises.get(i).isCircle()) {
            View listeElemani = li.inflate(R.layout.listing_adapter_program_overview_circle, null);
            TextView countText = (TextView) listeElemani.findViewById(R.id.programOverviewCircleCount);
            ListView listView = (ListView) listeElemani.findViewById(R.id.programOverviewCircleListview);

            ProgramOverviewAdapter adapter = new ProgramOverviewAdapter(activity, ((CirclePOJO) exercises.get(i)).getArraylist());

            //adapter.setComingFromCircle(true);
            listView.setAdapter(adapter);


            FunctionUtils.setListViewHeightBasedOnItems(listView);


            countText.setText("x" + ((CirclePOJO) exercises.get(i)).getTekrarCount());
            return listeElemani;


        } else {
            final View listeElemani = li.inflate(R.layout.listing_adapter_program_overview, null);


            ImageView image = (ImageView) listeElemani.findViewById(R.id.listingExerciseImage);
            TextView title = (TextView) listeElemani.findViewById(R.id.listingExerciseTitle);
            TextView tekrar = (TextView) listeElemani.findViewById(R.id.listingExerciseTekrar);

            Bitmap bitmap = null;
            String titleString = "";
            String tekrarString = "";


            if (exercises.get(i).isTekrar() && !exercises.get(i).isCircle()) {
                bitmap = ((TekrarPOJO) exercises.get(i)).getPhoto1();
                titleString = ((TekrarPOJO) exercises.get(i)).getName();
                tekrarString = "x" + ((TekrarPOJO) exercises.get(i)).getTekrarCount();
            } else if (!exercises.get(i).isTekrar() && !exercises.get(i).isCircle()) {
                bitmap = ((ExercisePOJO) exercises.get(i)).getPhoto1();
                titleString = ((ExercisePOJO) exercises.get(i)).getName();
                tekrar.setVisibility(GONE);
            }


            image.setImageBitmap(bitmap);
            title.setText(titleString);
            tekrar.setText(tekrarString);

            listeElemani.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    Intent intent = new Intent(context, ProgramPlayActivity.class);
                    int programID = ((ProgramOverviewActivity)activity).programID;
                    intent.putExtra("programID",programID);
                    ExercisePOJO exx;
                    if(exercises.get(i).isTekrar()){
                        exx = ((TekrarPOJO)exercises.get(i)).getExercisez().get(0);
                    }
                    else{
                        exx = (ExercisePOJO) exercises.get(i);
                    }
                    intent.putExtra("currentExerciseIndex",((GlobalVariables)context.getApplicationContext()).getUserDataPOJO().getProgramByID(programID).getExercisez().indexOf(exx));
                    activity.startActivity(intent);


                }
            });
            return listeElemani;

        }

    }
}
