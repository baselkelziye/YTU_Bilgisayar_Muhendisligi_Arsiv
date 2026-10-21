package berkay.ders.mobilprogramlama.semesterproject.adapter;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import java.util.ArrayList;

import berkay.ders.mobilprogramlama.semesterproject.R;
import berkay.ders.mobilprogramlama.semesterproject.model.Contact;

/**
 * Created by mberk on 14.12.2015.
 */
public class ContactsAdapter extends BaseAdapter {
    private Context mContext;
    private ArrayList<Contact> mContactList;

    public ContactsAdapter(Context context, ArrayList<Contact> contacts){
        this.mContext = context;
        this.mContactList = contacts;
    }

    public void updateItems(ArrayList<Contact> contacts){
        mContactList = contacts;
        notifyDataSetChanged();
    }

    @Override
    public int getCount() {
        return mContactList.size();
    }

    @Override
    public Contact getItem(int position) {
        return mContactList.get(position);
    }

    @Override
    public long getItemId(int position) {
        return mContactList.get(position).getContactID();
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        ViewHolder viewHolder;

        // If the convertView is deleted
        if(convertView == null){
            LayoutInflater inflater = (LayoutInflater) mContext.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            convertView = inflater.inflate(R.layout.list_item_contact, parent, false);

            viewHolder = new ViewHolder();
            viewHolder.textView_name = (TextView) convertView.findViewById(R.id.list_item_contact_name);
            convertView.setTag(viewHolder);
        }
        else{
            viewHolder = (ViewHolder) convertView.getTag();
        }

        Contact contact = getItem(position);

        viewHolder.textView_name.setText(String.format("%s %s", contact.getName(), contact.getSurname()));

        return convertView;
    }

    private final class ViewHolder{
        TextView textView_name;
    }
}
