package com.example.MyCalendar;


import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import java.util.ArrayList;

public class CustomListViewAdapter extends ArrayAdapter<Event> {
    private final LayoutInflater inflater;
    private final Context context;
    private ViewHolder holder;
    private final ArrayList<Event> events;

    public CustomListViewAdapter(Context context, ArrayList<Event> events) {
        super(context, 0, events);
        this.context = context;
        this.events = events;
        inflater = LayoutInflater.from(context);
    }


    @Override
    public int getCount() {
        return events.size();
    }

    @Override
    public Event getItem(int position) {
        return events.get(position);
    }

    @Override
    public long getItemId(int position) {
        return events.get(position).hashCode();
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {

        if (convertView == null) {

            convertView = inflater.inflate(R.layout.list_view_item, null);

            holder = new ViewHolder();
            holder.eventNameLabel = (TextView) convertView.findViewById(R.id.event_name_label);
            holder.eventDateLabel = (TextView) convertView.findViewById(R.id.event_date_label);
            holder.eventTimeLabel = (TextView) convertView.findViewById(R.id.event_time_label);
            convertView.setTag(holder);

        } else {
            holder = (ViewHolder) convertView.getTag();
        }

        Event event = events.get(position);
        if (event != null) {
            holder.eventNameLabel.setText(event.getName());
            holder.eventDateLabel.setText(event.getDay() + "/" + Integer.toString(event.getMonth() + 1) + "/" + event.getYear());
            holder.eventTimeLabel.setText(event.getStarthr() + "." + event.getStartmin() + " - " + event.getEndhr() + "." + event.getEndmin());
        }
        return convertView;
    }

    private static class ViewHolder {
        TextView eventNameLabel;
        TextView eventDateLabel;
        TextView eventTimeLabel;
    }

}


