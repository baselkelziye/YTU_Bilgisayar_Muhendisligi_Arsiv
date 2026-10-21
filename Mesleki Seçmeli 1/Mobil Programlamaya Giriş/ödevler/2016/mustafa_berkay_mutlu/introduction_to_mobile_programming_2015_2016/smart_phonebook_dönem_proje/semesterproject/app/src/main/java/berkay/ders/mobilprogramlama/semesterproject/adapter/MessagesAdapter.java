package berkay.ders.mobilprogramlama.semesterproject.adapter;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.RelativeLayout;
import android.widget.TextView;

import java.util.ArrayList;

import berkay.ders.mobilprogramlama.semesterproject.R;
import berkay.ders.mobilprogramlama.semesterproject.model.Message;

/**
 * Created by mberk on 28.12.2015.
 */
public class MessagesAdapter extends BaseAdapter {
    private Context mContext;
    private ArrayList<Message> mMessagesList;

    public MessagesAdapter(Context context, ArrayList<Message> messages){
        this.mContext = context;
        this.mMessagesList = messages;
    }

    public void updateItems(ArrayList<Message> messages){
        mMessagesList = messages;
        notifyDataSetChanged();
    }

    @Override
    public int getCount() {
        return mMessagesList.size();
    }

    @Override
    public Message getItem(int position) {
        return mMessagesList.get(position);
    }

    @Override
    public long getItemId(int position) {
        return mMessagesList.get(position).getMessageID();
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        ViewHolder viewHolder;
        Message message = getItem(position);

        // If the convertView is deleted
        if(convertView == null){
            LayoutInflater inflater = (LayoutInflater) mContext.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            convertView = inflater.inflate(R.layout.list_item_message, parent, false);

            viewHolder = new ViewHolder();
            viewHolder.relativeLayout = (RelativeLayout) convertView.findViewById(R.id.list_item_message_relativeLayout);
            viewHolder.editText_messageText = (TextView) convertView.findViewById(R.id.list_item_message_messageText);
            viewHolder.editText_messageDate = (TextView) convertView.findViewById(R.id.list_item_message_messageDate);
            convertView.setTag(viewHolder);
        }
        else{
            viewHolder = (ViewHolder) convertView.getTag();
        }

        if(message.isFromMe()) {
            RelativeLayout.LayoutParams params = (RelativeLayout.LayoutParams) viewHolder.relativeLayout.getLayoutParams();
            params.addRule(RelativeLayout.ALIGN_PARENT_RIGHT);
            viewHolder.relativeLayout.setLayoutParams(params);
        }

        viewHolder.editText_messageText.setText(message.getText());
        viewHolder.editText_messageDate.setText(message.getDateDisplayString());

        return convertView;
    }

    private final class ViewHolder{
        RelativeLayout relativeLayout;
        TextView editText_messageText;
        TextView editText_messageDate;
    }
}
