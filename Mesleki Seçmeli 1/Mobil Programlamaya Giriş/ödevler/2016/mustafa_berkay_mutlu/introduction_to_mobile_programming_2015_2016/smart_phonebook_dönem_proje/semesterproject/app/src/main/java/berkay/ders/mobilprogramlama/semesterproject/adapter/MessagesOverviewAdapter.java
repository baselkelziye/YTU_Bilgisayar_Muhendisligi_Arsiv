package berkay.ders.mobilprogramlama.semesterproject.adapter;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import java.util.ArrayList;

import berkay.ders.mobilprogramlama.semesterproject.R;
import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseOperations;
import berkay.ders.mobilprogramlama.semesterproject.model.Contact;
import berkay.ders.mobilprogramlama.semesterproject.model.Message;

/**
 * Created by mberk on 28.12.2015.
 */
public class MessagesOverviewAdapter extends BaseAdapter {
    private Context mContext;
    private ArrayList<Message> mMessagesOverviewList;
    private DatabaseOperations mDatabaseOperations;

    public MessagesOverviewAdapter(Context context, ArrayList<Message> messagesOverview){
        this.mContext = context;
        this.mMessagesOverviewList = messagesOverview;
        this.mDatabaseOperations = DatabaseOperations.get(context);
    }

    public void updateItems(ArrayList<Message> messagesOverviewList) {
        this.mMessagesOverviewList = messagesOverviewList;
        notifyDataSetChanged();
    }

    @Override
    public int getCount() {
        return mMessagesOverviewList.size();
    }

    @Override
    public Message getItem(int position) {
        return mMessagesOverviewList.get(position);
    }

    @Override
    public long getItemId(int position) {
        return mMessagesOverviewList.get(position).getMessageID();
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        ViewHolder viewHolder;

        // If the convertView is deleted
        if(convertView == null){
            LayoutInflater inflater = (LayoutInflater) mContext.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            convertView = inflater.inflate(R.layout.list_item_message_overview, parent, false);

            viewHolder = new ViewHolder();
            viewHolder.editText_fromTo = (TextView) convertView.findViewById(R.id.list_item_messageOverview_fromTo);
            viewHolder.editText_messageText = (TextView) convertView.findViewById(R.id.list_item_messageOverview_messageText);
            viewHolder.editText_messageDate = (TextView) convertView.findViewById(R.id.list_item_messageOverview_messageDate);
            convertView.setTag(viewHolder);
        }
        else{
            viewHolder = (ViewHolder) convertView.getTag();
        }

        Message message = getItem(position);


        viewHolder.editText_messageText.setText(message.getText());
        viewHolder.editText_messageDate.setText(message.getDateDisplayString());

        Contact contact = mDatabaseOperations.getContact(message.getRemotePhoneNumber());
        if(contact != null){
            viewHolder.editText_fromTo.setText(String.format("%s %s", contact.getName(), contact.getSurname()));
        } else{
            viewHolder.editText_fromTo.setText(message.getRemotePhoneNumber());
        }

        return convertView;
    }

    private final class ViewHolder{
        TextView editText_fromTo;
        TextView editText_messageText;
        TextView editText_messageDate;
    }
}
