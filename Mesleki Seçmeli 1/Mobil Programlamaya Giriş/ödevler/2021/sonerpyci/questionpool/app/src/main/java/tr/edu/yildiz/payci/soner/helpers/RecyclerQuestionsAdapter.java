package tr.edu.yildiz.payci.soner.helpers;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.VideoView;

import java.lang.ref.WeakReference;
import java.util.List;

import tr.edu.yildiz.payci.soner.R;
import tr.edu.yildiz.payci.soner.model.Exam;
import tr.edu.yildiz.payci.soner.model.Question;

public class RecyclerQuestionsAdapter extends RecyclerView.Adapter<RecyclerQuestionsAdapter.MyViewHolder> implements OnItemClickListener {
    private List<Question> mListenerList;
    private final OnItemClickListener listener;

    Context mContext;
    LayoutInflater inflater;

    public RecyclerQuestionsAdapter(List<Question> mListenerList, Context mContext, OnItemClickListener listener) {
        this.mListenerList = mListenerList;
        this.mContext = mContext;
        this.listener = listener;
        inflater = LayoutInflater.from(mContext);
    }

    @Override
    public MyViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View itemView = LayoutInflater.from(parent.getContext())
                .inflate(R.layout.question_item, parent, false);
        return new MyViewHolder(itemView);
    }

    @Override
    public void onBindViewHolder(final MyViewHolder holder, final int position) {
        Question question = mListenerList.get(position);

        // get a get b get c get question fields.
        holder.question_number.setText(String.valueOf(question.getId()));
        holder.question_text.setText(question.getText());

        if (question.getQuestionMedia() != null) {
            if (question.getQuestionMedia().getContentType().contains("image")) {
                Bitmap bmp = BitmapFactory.decodeByteArray(question.getQuestionMedia().getContent(), 0, question.getQuestionMedia().getContent().length);
                holder.question_image_content.setImageBitmap(null);
                holder.question_image_content.setImageBitmap(Bitmap.createScaledBitmap(bmp, holder.question_image_content.getWidth(), holder.question_image_content.getHeight(), false));
                holder.question_video_content.setVisibility(View.GONE);
                holder.question_audio_content.setVisibility(View.GONE);
                holder.question_image_content.setVisibility(View.VISIBLE);

            } else if (question.getQuestionMedia().getContentType().contains("video")) {
                // TODO : Process Video Here
            } else if (question.getQuestionMedia().getContentType().contains("audio")) {
                holder.audioBytes = question.getQuestionMedia().getContent();
                holder.question_video_content.setVisibility(View.GONE);
                holder.question_image_content.setVisibility(View.GONE);
                holder.question_audio_content.setVisibility(View.VISIBLE);
            }
        } else {
            holder.question_image_content.setImageBitmap(null);
        }

        holder.bind(mListenerList.get(position), listener);
    }

    @Override
    public int getItemCount() {
        return mListenerList.size();
    }

    public void addItem(Question item) {
        this.mListenerList.add(item);
        this.notifyItemRangeInserted(getItemCount() - 1, getItemCount());
    }

    public void editItem(Question oldItem, Question newItem) {
        int index = mListenerList.indexOf(oldItem);
        this.mListenerList.set(index, newItem);
        this.notifyItemChanged(index);
    }

    public void removeItem(Question item) {
        this.mListenerList.remove(item);
        this.notifyDataSetChanged();
        //this.notifyItemRangeInserted(getItemCount() - 1, getItemCount());
    }

    public void refresh() {
        this.notifyDataSetChanged();
    }

    @Override
    public void onQuestionItemClick(View v, Question item) {

    }

    @Override
    public boolean onQuestionItemLongClick(View v, Question item) {
        return true;
    }

    @Override
    public void onExamItemClick(View v, Exam item) {
        throw new UnsupportedOperationException("This Event as Not been implemented on questions {onExamItemClick}");
    }

    @Override
    public boolean onExamItemLongClick(View v, Exam item) {
        throw new UnsupportedOperationException("This Event as Not been implemented on questions {onExamItemClick}");
    }

    public class MyViewHolder extends RecyclerView.ViewHolder {
        TextView question_text;
        TextView question_number;
        ImageView question_image_content;
        ImageView question_audio_content;
        byte[] audioBytes;
        VideoView question_video_content;
        private WeakReference<OnItemClickListener> listenerRef;

        public MyViewHolder(View view) {
            super(view);
            listenerRef = new WeakReference<>(listener);
            question_text = (TextView) view.findViewById(R.id.question_text);
            question_number = (TextView) view.findViewById(R.id.question_number);
            question_image_content = (ImageView) view.findViewById(R.id.question_image_view);
            question_video_content = (VideoView) view.findViewById(R.id.question_video_view);
            question_audio_content = (ImageView) view.findViewById(R.id.question_audio_view);
        }

        public void bind(final Question item, final OnItemClickListener listener) {
            itemView.setOnClickListener(new View.OnClickListener() {
                @Override public void onClick(View v) {
                    listener.onQuestionItemClick(v, item);
                }
            });
            itemView.setOnLongClickListener(new View.OnLongClickListener() {
                @Override
                public boolean onLongClick(View v) {
                    return listener.onQuestionItemLongClick(v, item);
                }
            });
        }
    }
}