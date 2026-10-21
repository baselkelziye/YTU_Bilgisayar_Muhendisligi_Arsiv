package mobilprogramlama.ders.berkay.hm1_quiz.adapter;

import android.content.Context;
import android.graphics.Color;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

import java.util.ArrayList;

import mobilprogramlama.ders.berkay.hm1_quiz.R;
import mobilprogramlama.ders.berkay.hm1_quiz.database.LocalDatabaseHandler;
import mobilprogramlama.ders.berkay.hm1_quiz.model.PlayerAnswer;

/**
 * Created by mberk on 20.11.2015.
 */
public class AnswersAdapter extends BaseAdapter {

    private ArrayList<PlayerAnswer> mPlayerAnswers; // List of player answers.
    private Context mContext;
    private LocalDatabaseHandler mLocalDatabaseHandler;

    public AnswersAdapter(Context context, long playerID){
        this.mContext = context;
        this.mLocalDatabaseHandler = LocalDatabaseHandler.getInstance(context);
        this.mPlayerAnswers = mLocalDatabaseHandler.GetPlayerAnswers(playerID);
    }

    @Override
    public int getCount() {
        return mPlayerAnswers.size();
    }

    @Override
    public PlayerAnswer getItem(int position) {
        return mPlayerAnswers.get(position);
    }

    @Override
    public long getItemId(int position) {
        return position;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        ViewHolder viewHolder;

        // If the convertView is deleted
        if(convertView == null){
            LayoutInflater inflater = (LayoutInflater) mContext.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            convertView = inflater.inflate(R.layout.list_item_answers, parent, false);

            viewHolder = new ViewHolder();
            viewHolder.orderNo = (TextView) convertView.findViewById(R.id.list_item_answers_orderNo);
            viewHolder.question = (TextView) convertView.findViewById(R.id.list_item_answers_question);
            viewHolder.info = (TextView) convertView.findViewById(R.id.list_item_answers_info);
            convertView.setTag(viewHolder);
        }
        else{
            viewHolder = (ViewHolder) convertView.getTag();
        }

        PlayerAnswer playerAnswer = getItem(position);

        viewHolder.orderNo.setText(String.valueOf(position + 1));
        viewHolder.question.setText(mLocalDatabaseHandler.GetQuestion(playerAnswer.getQuestionID()).getQuestion());

        if(playerAnswer.getPlayerAnswer() == mLocalDatabaseHandler.GetQuestion(playerAnswer.getQuestionID()).getAnswer()){
            viewHolder.info.setText("Your answer '" + playerAnswer.getPlayerAnswer() + "' was correct!");
            viewHolder.info.setTextColor(Color.parseColor("#008000"));
        }
        else{
            viewHolder.info.setText("Your answer '" + playerAnswer.getPlayerAnswer() + "' was wrong!");
            viewHolder.info.setTextColor(Color.parseColor("#FF4500"));
        }

        return convertView;
    }


    /**
     * Static class that holds the View objects for better performance in scrolling the ListView.
     */
    private static class ViewHolder{
        TextView orderNo;
        TextView question;
        TextView info;
    }
}
