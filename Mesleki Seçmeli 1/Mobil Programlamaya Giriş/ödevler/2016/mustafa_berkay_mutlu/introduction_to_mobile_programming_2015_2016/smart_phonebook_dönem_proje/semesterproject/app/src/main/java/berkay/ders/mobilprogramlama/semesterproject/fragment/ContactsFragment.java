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

public class ContactsFragment extends Fragment {
    private ListView mContactsListView;
    private ContactsAdapter mContactsAdapter;
    private DatabaseOperations mDatabaseOperations;

    public ContactsFragment() { }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_contacts, container, false);

        mDatabaseOperations = DatabaseOperations.get(getContext());
        mContactsAdapter = new ContactsAdapter(getContext(), mDatabaseOperations.getAllContacts());

        mContactsListView = (ListView) view.findViewById(R.id.listView_contactsFragment_contacts);

        mContactsListView.setAdapter(mContactsAdapter);
        mContactsListView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
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

    public void refreshListView(){
        if(mDatabaseOperations == null || mContactsAdapter == null){
            mDatabaseOperations = DatabaseOperations.get(getContext());
            mContactsAdapter = new ContactsAdapter(getContext(), mDatabaseOperations.getAllContacts());
        }

        mContactsAdapter.updateItems(mDatabaseOperations.getAllContacts());
    }

}
