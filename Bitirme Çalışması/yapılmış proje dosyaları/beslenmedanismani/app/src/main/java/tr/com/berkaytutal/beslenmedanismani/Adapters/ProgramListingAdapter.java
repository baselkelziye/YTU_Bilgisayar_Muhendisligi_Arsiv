package tr.com.berkaytutal.beslenmedanismani.Adapters;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.graphics.Color;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;

import tr.com.berkaytutal.beslenmedanismani.AllListingsActivity;
import tr.com.berkaytutal.beslenmedanismani.ProgramDetailActivity;
import tr.com.berkaytutal.beslenmedanismani.R;
import tr.com.berkaytutal.beslenmedanismani.Utils.GlobalVariables;
import tr.com.berkaytutal.beslenmedanismani.Utils.ProgramPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.TrainerPOJO;

/**
 * Created by berka on 15.05.2017.
 */

public class ProgramListingAdapter extends BaseAdapter {


    private LayoutInflater li;
    private ArrayList<ProgramPOJO> list;
    View.OnClickListener onClickListener;
    private Context context;


    public ProgramListingAdapter(Activity activity, ArrayList<ProgramPOJO> arrayList) {
        this.context = activity.getApplicationContext();

        li = (LayoutInflater) activity.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        list = arrayList;
    }


    @Override
    public int getCount() {
        return list.size();
    }

    @Override
    public Object getItem(int i) {
        return list.get(i);
    }

    @Override
    public long getItemId(int i) {
        return i;
    }

    @Override
    public View getView(final int i, View view, ViewGroup viewGroup) {
        final View listeElemani = li.inflate(R.layout.listing_adapter_program, null);
        final ProgramPOJO programPOJO = list.get(i);

        ImageView image = (ImageView) listeElemani.findViewById(R.id.listingImage);
        TextView title = (TextView) listeElemani.findViewById(R.id.listingTitle);
        TextView difficulty = (TextView) listeElemani.findViewById(R.id.listingDifficulty);
        TextView category = (TextView) listeElemani.findViewById(R.id.listingCategory);
        TextView trainerName = (TextView) listeElemani.findViewById(R.id.listingProgramTrainer);
        TextView ratingTxt = (TextView) listeElemani.findViewById(R.id.listingRatingTextView);
        TextView commentTxt = (TextView) listeElemani.findViewById(R.id.listingCommentTextView);
        TextView isPublishedTextView = (TextView) listeElemani.findViewById(R.id.listingPublishedTextview);
        TextView isDownloadedTextView = (TextView) listeElemani.findViewById(R.id.listingDownloadedTextview);
        TextView isBannedTextView = (TextView) listeElemani.findViewById(R.id.listingBannedTextview);
        TextView priceTextView = (TextView) listeElemani.findViewById(R.id.listingPriceTextView);


        if(programPOJO.getPrice()==0){
            priceTextView.setText("FREE");
            priceTextView.setTextColor(Color.GREEN);
        }
        else{
            priceTextView.setText(programPOJO.getPrice() + " TL");
        }


        if(programPOJO.isBanned()){
            isBannedTextView.setVisibility(View.VISIBLE);
        }
        if(programPOJO.getExercisez()!=null){
            isDownloadedTextView.setVisibility(View.VISIBLE);
        }



        ratingTxt.setText(programPOJO.getRating() + "/5");
        commentTxt.setText(programPOJO.getCommentCount() + "");

        image.setImageBitmap(programPOJO.getProgramPhoto());
        title.setText(programPOJO.getProgramTitle());
        difficulty.setText(programPOJO.getDifficulty());
        category.setText(programPOJO.getProgramSpec());
        trainerName.setText(programPOJO.getTrainerName() + " " + programPOJO.getTrainerSurname());

        if(!programPOJO.isPublished()){
            isPublishedTextView.setVisibility(View.VISIBLE);
        }




        listeElemani.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //Toast.makeText(view.getContext(), i + "", Toast.LENGTH_SHORT).show();

                Intent intent = new Intent(view.getContext(), ProgramDetailActivity.class);
                intent.putExtra("programID",programPOJO.getProgramID());
                view.getContext().startActivity(intent);

            }
        });


        return listeElemani;
    }
}
