package tr.com.berkaytutal.beslenmedanismani.Adapters;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.ArrayList;

import tr.com.berkaytutal.beslenmedanismani.R;
import tr.com.berkaytutal.beslenmedanismani.TrainerDetailPage;
import tr.com.berkaytutal.beslenmedanismani.Utils.CommentPOJO;
import tr.com.berkaytutal.beslenmedanismani.Utils.TrainerPOJO;

/**
 * Created by berka on 21.06.2017.
 */

public class ProgramCommentsAdapter extends BaseAdapter {


    private Activity activity;
    private ArrayList<CommentPOJO> comments;
    private LayoutInflater li;

    public ProgramCommentsAdapter(Activity activity, ArrayList<CommentPOJO> comments) {
        this.activity = activity;
        this.comments = comments;
        li = (LayoutInflater) activity.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
    }

    @Override
    public int getCount() {
        return comments.size();
    }

    @Override
    public Object getItem(int i) {
        return comments.get(i);
    }

    @Override
    public long getItemId(int i) {
        return i;
    }

    @Override
    public View getView(int i, View view, ViewGroup viewGroup) {
        final View item = li.inflate(R.layout.comment_item, null);
        final CommentPOJO comment = comments.get(i);
        TextView commentNumber = (TextView) item.findViewById(R.id.commentItemNumber);
        ImageView commenterPhoto = (ImageView) item.findViewById(R.id.commentItemPhoto);
        TextView commenterName = (TextView) item.findViewById(R.id.commentItemName);
        TextView commentText = (TextView) item.findViewById(R.id.commentItemComment);
        TextView commentPoints = (TextView) item.findViewById(R.id.commentStarPoint);

        commentNumber.setText("#" + (i+1));
        commenterPhoto.setImageBitmap(comment.getCommenterPhoto());
        commenterName.setText(comment.getCommenterName());
        commentText.setText(comment.getCommentText());
        commentPoints.setText(comment.getStarPoints() + "/5");


        return item;
    }
}
