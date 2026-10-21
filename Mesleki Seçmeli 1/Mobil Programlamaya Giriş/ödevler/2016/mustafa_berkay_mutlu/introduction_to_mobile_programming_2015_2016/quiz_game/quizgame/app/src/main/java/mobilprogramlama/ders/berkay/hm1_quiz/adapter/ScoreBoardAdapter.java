package mobilprogramlama.ders.berkay.hm1_quiz.adapter;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

import mobilprogramlama.ders.berkay.hm1_quiz.R;
import mobilprogramlama.ders.berkay.hm1_quiz.database.LocalDatabaseHandler;
import mobilprogramlama.ders.berkay.hm1_quiz.model.Player;

/**
 * Created by mberk on 19.11.2015.
 */
public class ScoreBoardAdapter extends BaseAdapter {
    private ArrayList<Player> mPlayerList;
    private LocalDatabaseHandler mLocalDatabaseHandler;
    private Context mContext;

    public ScoreBoardAdapter(Context context){
        mContext = context;
        mLocalDatabaseHandler = LocalDatabaseHandler.getInstance(context);
        mPlayerList = mLocalDatabaseHandler.GetAllPlayers();

        for(Player player : mPlayerList){
            player.setScore(mLocalDatabaseHandler.GetPlayerScore(player.getPlayerID()));
        }

        Collections.sort(mPlayerList, new Comparator<Player>() {
            @Override
            public int compare(Player player1, Player player2) {
                return player2.getScore() - player1.getScore();
            }
        });
    }

    @Override
    public int getCount() {
        return mPlayerList.size();
    }

    @Override
    public Player getItem(int position) {
        return mPlayerList.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {

        ViewHolder viewHolder;

        if(convertView == null){
            LayoutInflater inflater = (LayoutInflater) mContext.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            convertView = inflater.inflate(R.layout.list_item_scoreboard, parent, false);

            viewHolder = new ViewHolder();
            viewHolder.orderNo = (TextView) convertView.findViewById(R.id.list_item_scoreBoard_orderNo);
            viewHolder.score = (TextView) convertView.findViewById(R.id.list_item_scoreBoard_playerScore);
            viewHolder.name = (TextView) convertView.findViewById(R.id.list_item_scoreBoard_playerName);
            convertView.setTag(viewHolder);
        }
        else{
            viewHolder = (ViewHolder) convertView.getTag();
        }

        Player player = getItem(position);

        viewHolder.orderNo.setText(String.valueOf(position + 1)); // We are adding +1 because "position" variable is starting from 0.
        viewHolder.name.setText(String.format("%s, %d", player.getName(), player.getAge()));
        viewHolder.score.setText(String.valueOf(player.getScore()));

        return convertView;
    }

    /**
     * Static class that holds the View objects for better performance in scrolling the ListView.
     */
    private static class ViewHolder{
        TextView orderNo;
        TextView score;
        TextView name;
    }
}
