package com.example.blm3520_hw1;

import android.widget.Filter;

import java.util.ArrayList;

public class UserFilter extends Filter {

    ArrayList<User> filterList;
    RecycleAdapter adapter;

    public UserFilter(ArrayList<User> filterList, RecycleAdapter adapter) {
        this.filterList = filterList;
        this.adapter = adapter;
    }

    @Override
    protected FilterResults performFiltering(CharSequence constraint) {

        FilterResults results = new FilterResults();

        if (constraint != null && constraint.length() > 0) {
            constraint = constraint.toString().toUpperCase();
            ArrayList<User> filterModels = new ArrayList<>();

            for (int i = 0; i < filterList.size(); i++) {
                if (filterList.get(i).getName().toUpperCase().contains(constraint)) {
                    filterModels.add(filterList.get(i));
                }
            }

            results.count = filterModels.size();
            results.values = filterModels;

        }
        else {
            results.count = filterList.size();
            results.values = filterList;
        }

        return results;
    }

    @Override
    protected void publishResults(CharSequence constraint, FilterResults results) {

        adapter.userList = (ArrayList<User>) results.values;
        adapter.notifyDataSetChanged();

    }
}



