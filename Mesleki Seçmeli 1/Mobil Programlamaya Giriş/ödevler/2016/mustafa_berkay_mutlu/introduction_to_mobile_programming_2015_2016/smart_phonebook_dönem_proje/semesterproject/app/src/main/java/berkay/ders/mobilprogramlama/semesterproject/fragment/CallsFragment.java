package berkay.ders.mobilprogramlama.semesterproject.fragment;


import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ListView;
import android.widget.TextView;

import berkay.ders.mobilprogramlama.semesterproject.R;
import berkay.ders.mobilprogramlama.semesterproject.adapter.CallsAdapter;
import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseOperations;

public class CallsFragment extends Fragment {
    private ListView mCallsListView;
    private CallsAdapter mCallsAdapter;
    private DatabaseOperations mDatabaseOperations;

    public CallsFragment() { }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_calls, container, false);

        mDatabaseOperations = DatabaseOperations.get(getContext());
        mCallsAdapter = new CallsAdapter(getContext(), mDatabaseOperations.getAllCalls());

        mCallsListView = (ListView) view.findViewById(R.id.listView_callsFragment_calls);
        mCallsListView.setAdapter(mCallsAdapter);
        mCallsListView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                String phoneNumber = ((TextView)view.findViewById(R.id.list_item_call_textView_phoneNumber)).getText().toString();
                Intent callIntent = new Intent(Intent.ACTION_CALL, Uri.parse("tel:" + phoneNumber));

                startActivity(callIntent);
            }
        });

        return view;
    }

    public void refreshListView(){
        if(mDatabaseOperations == null ||mCallsAdapter == null){
            mDatabaseOperations = DatabaseOperations.get(getContext());
            mCallsAdapter = new CallsAdapter(getContext(), mDatabaseOperations.getAllCalls());
        }

        mCallsAdapter.updateItems(mDatabaseOperations.getAllCalls());
    }

}
