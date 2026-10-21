package tr.com.berkaytutal.beslenmedanismani.Adapters;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.ArrayList;

import tr.com.berkaytutal.beslenmedanismani.R;
import tr.com.berkaytutal.beslenmedanismani.TrainerDetailPage;
import tr.com.berkaytutal.beslenmedanismani.Utils.TrainerPOJO;

/**
 * Created by berka on 15.05.2017.
 */

public class UserListingAdapter extends BaseAdapter {


    private LayoutInflater li;
    private ArrayList<TrainerPOJO> list;
    private Context context;


    public UserListingAdapter(Activity activity, ArrayList<TrainerPOJO> arrayList) {
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
        final View listeElemani = li.inflate(R.layout.listing_adapter_user, null);
        final TrainerPOJO user = list.get(i);

        ImageView image = (ImageView) listeElemani.findViewById(R.id.trainerListingImage);
        TextView trainerName = (TextView) listeElemani.findViewById(R.id.trainerNameText);
        TextView certificateCountText = (TextView) listeElemani.findViewById(R.id.trainerCertificateCount);

//        certificateCountText.setText(user.getCertificateCount() + "");

        trainerName.setText(user.getName() + " " + user.getSurname());
        image.setImageBitmap(user.getPhoto());


        listeElemani.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                Intent intent = new Intent(view.getContext(), TrainerDetailPage.class);
                intent.putExtra("trainerID",user.getUserID());
                view.getContext().startActivity(intent);

            }
        });


        return listeElemani;
    }
}
