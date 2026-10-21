package berkay.ders.mobilprogramlama.semesterproject.fragment;


import android.content.Intent;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ListView;

import berkay.ders.mobilprogramlama.semesterproject.R;
import berkay.ders.mobilprogramlama.semesterproject.activity.SingleContactActivity;
import berkay.ders.mobilprogramlama.semesterproject.adapter.ContactsAdapter;
import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseContract;
import berkay.ders.mobilprogramlama.semesterproject.database.DatabaseOperations;

public class SpeedDialFragment extends Fragment {
    private ListView listView_speedDialContacts;
    private ContactsAdapter mSpeedDialContactsAdapter;
    private DatabaseOperations mDatabaseOperations;

    public SpeedDialFragment() { }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        // Inflate the layout for this fragment
        View view = inflater.inflate(R.layout.fragment_speed_dial, container, false);

        mDatabaseOperations = DatabaseOperations.get(getContext());
        mSpeedDialContactsAdapter = new ContactsAdapter(getContext(), mDatabaseOperations.getAllSpeedDialContacts());

        listView_speedDialContacts = (ListView) view.findViewById(R.id.listView_speedDialContactsFragment_speedDialContacts);
        listView_speedDialContacts.setAdapter(mSpeedDialContactsAdapter);

        listView_speedDialContacts.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Intent singleContact = new Intent();
                singleContact.setClass(getContext(), SingleContactActivity.class);
                singleContact.putExtra(DatabaseContract.ContactsContract.COLUMN_NAME_CONTACT_ID, id);
                startActivity(singleContact);
            }
        });

        return view;
    }

    public void refreshListView() {
        if(mDatabaseOperations == null || mSpeedDialContactsAdapter == null){
            mDatabaseOperations = DatabaseOperations.get(getContext());
            mSpeedDialContactsAdapter = new ContactsAdapter(getContext(), mDatabaseOperations.getAllSpeedDialContacts());
        }

        mSpeedDialContactsAdapter.updateItems(mDatabaseOperations.getAllSpeedDialContacts());
    }
}
