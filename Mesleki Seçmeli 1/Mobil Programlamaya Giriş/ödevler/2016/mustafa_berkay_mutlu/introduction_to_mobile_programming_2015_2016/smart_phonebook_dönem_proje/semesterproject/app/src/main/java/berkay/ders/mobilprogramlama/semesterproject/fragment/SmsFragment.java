package berkay.ders.mobilprogramlama.semesterproject.fragment;

import android.content.Intent;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ListView;

import berkay.ders.mobilprogramlama.semesterproject.Config;
import berkay.ders.mobilprogramlama.semesterproject.R;
import berkay.ders.mobilprogramlama.semesterproject.activity.MessageActivity;
import berkay.ders.mobilprogramlama.semesterproject.adapter.MessagesOverviewAdapter;
import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseContract;
import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseOperations;

public class SmsFragment extends Fragment {

    private ListView mMessagesOverviewListView;
    private MessagesOverviewAdapter mMessagesOverviewAdapter;
    private DatabaseOperations mDatabaseOperations;


    public SmsFragment() { }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View view = inflater.inflate(R.layout.fragment_sms, container, false);

        mDatabaseOperations = DatabaseOperations.get(getContext());
        mMessagesOverviewAdapter = new MessagesOverviewAdapter(getContext(), mDatabaseOperations.getAllMessagesOverview());

        mMessagesOverviewListView = (ListView) view.findViewById(R.id.listView_smsFragment_messagesOverview);

        mMessagesOverviewListView.setAdapter(mMessagesOverviewAdapter);
        mMessagesOverviewListView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Intent messageActivity = new Intent();
                messageActivity.setClass(getContext(), MessageActivity.class);
                messageActivity.putExtra(DatabaseContract.MessagesContract.COLUMN_NAME_REMOTE_PHONE_NUMBER,
                        DatabaseOperations.get(getContext()).getMessage(id).getRemotePhoneNumber());
                messageActivity.putExtra(Config.TAG_IS_NEW_MESSAGE, false);
                startActivity(messageActivity);
            }
        });

        return view;
    }

    public void refreshListView(){
        if(mDatabaseOperations == null || mMessagesOverviewAdapter == null){
            mDatabaseOperations = DatabaseOperations.get(getContext());
            mMessagesOverviewAdapter = new MessagesOverviewAdapter(getContext(), mDatabaseOperations.getAllMessagesOverview());
        }

        mMessagesOverviewAdapter.updateItems(mDatabaseOperations.getAllMessagesOverview());
    }

}
