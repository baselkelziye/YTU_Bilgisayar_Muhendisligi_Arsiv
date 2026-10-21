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
import tr.com.berkaytutal.beslenmedanismani.Utils.CertificatePOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.TrainerPOJO;

/**
 * Created by berka on 29.06.2017.
 */

public class CertificatesAdapter extends BaseAdapter {


    private LayoutInflater li;
    private ArrayList<CertificatePOJO> list;
    private Context context;

    public CertificatesAdapter(Activity activity, ArrayList<CertificatePOJO> arrayList) {
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
    public View getView(int i, View view, ViewGroup viewGroup) {
        final View listeElemani = li.inflate(R.layout.adapter_item_certificate, null);
        final CertificatePOJO certificate = list.get(i);


        TextView certName = (TextView) listeElemani.findViewById(R.id.certificateName);
        TextView certInst = (TextView) listeElemani.findViewById(R.id.certificateInst);
        TextView certID = (TextView) listeElemani.findViewById(R.id.certificateIDTextView);

        certName.setText(certificate.getCertificateName());
        certInst.setText(certificate.getCertificateInstution());
        certID.setText("#" + (i+1));


        return listeElemani;
    }
}
