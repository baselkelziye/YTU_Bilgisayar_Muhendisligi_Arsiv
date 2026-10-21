package berkay.ders.mobilprogramlama.semesterproject.adapter;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.ArrayList;

import berkay.ders.mobilprogramlama.semesterproject.R;
import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseOperations;
import berkay.ders.mobilprogramlama.semesterproject.model.Call;
import berkay.ders.mobilprogramlama.semesterproject.model.Contact;

/**
 * Created by mberk on 29.12.2015.
 */
public class CallsAdapter extends BaseAdapter {
    private DatabaseOperations mDatabaseOperations;
    private Context mContext;
    private ArrayList<Call> mCallsList;

    public CallsAdapter(Context context, ArrayList<Call> calls){
        this.mDatabaseOperations = DatabaseOperations.get(context);
        this.mContext = context;
        this.mCallsList = calls;;
    }

    public void updateItems(ArrayList<Call> calls){
        mCallsList = calls;
        notifyDataSetChanged();
    }

    @Override
    public int getCount() {
        return mCallsList.size();
    }

    @Override
    public Call getItem(int position) {
        return mCallsList.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        ViewHolder viewHolder;

        // If the convertView is deleted
        if(convertView == null){
            LayoutInflater inflater = (LayoutInflater) mContext.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            convertView = inflater.inflate(R.layout.list_item_call, parent, false);

            viewHolder = new ViewHolder();
            viewHolder.textView_phoneNumber = (TextView) convertView.findViewById(R.id.list_item_call_textView_phoneNumber);
            viewHolder.textView_person = (TextView) convertView.findViewById(R.id.list_item_call_textView_person);
            viewHolder.textView_callDate = (TextView) convertView.findViewById(R.id.list_item_call_textView_when);
            viewHolder.imageView_callType = (ImageView) convertView.findViewById(R.id.list_item_call_imageView_callType);
            convertView.setTag(viewHolder);
        }
        else{
            viewHolder = (ViewHolder) convertView.getTag();
        }

        Call call = getItem(position);

        viewHolder.textView_phoneNumber.setText(call.getPhoneNumber());
        viewHolder.textView_callDate.setText(call.getDisplayCallDate());

        Contact contact = mDatabaseOperations.getContact(call.getPhoneNumber());
        if(contact != null){
            viewHolder.textView_person.setText(String.format("%s %s", contact.getName(), contact.getSurname()));
        } else{
            viewHolder.textView_person.setText(call.getPhoneNumber());
        }

        if(call.isFromMe()){
            viewHolder.imageView_callType.setBackgroundResource(R.drawable.ic_call_made_black_48dp);
        } else{
            if(call.isAnswered()){
                viewHolder.imageView_callType.setBackgroundResource(R.drawable.ic_call_received_black_48dp);
            } else{
                viewHolder.imageView_callType.setBackgroundResource(R.drawable.ic_call_missed_black_48dp);
            }
        }

        return convertView;
    }

    private final class ViewHolder{
        TextView textView_phoneNumber;
        TextView textView_person;
        ImageView imageView_callType;
        TextView textView_callDate;
    }
}
