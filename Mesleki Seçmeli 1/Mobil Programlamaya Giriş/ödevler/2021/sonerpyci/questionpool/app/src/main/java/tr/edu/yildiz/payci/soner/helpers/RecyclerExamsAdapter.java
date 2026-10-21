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

import java.util.List;

import tr.edu.yildiz.payci.soner.R;
import tr.edu.yildiz.payci.soner.model.Exam;
import tr.edu.yildiz.payci.soner.model.Question;

public class RecyclerExamsAdapter extends RecyclerView.Adapter<RecyclerExamsAdapter.MyViewHolder> implements OnItemClickListener {
    private List<Exam> mListenerList;
    private final OnItemClickListener listener;

    Context mContext;
    LayoutInflater inflater;

    public RecyclerExamsAdapter(List<Exam> mListenerList, Context mContext, OnItemClickListener listener) {
        this.mListenerList = mListenerList;
        this.mContext = mContext;
        this.listener = listener;
        inflater = LayoutInflater.from(mContext);
    }

    @Override
    public MyViewHolder onCreateViewHolder(ViewGroup parent, int viewType) {
        View itemView = LayoutInflater.from(parent.getContext())
                .inflate(R.layout.exam_item, parent, false);
        return new MyViewHolder(itemView);
    }

    @Override
    public void onBindViewHolder(final MyViewHolder holder, final int position) {
        Exam exam = mListenerList.get(position);

        // get a get b get c get exam fields.
        holder.exam_number.setText(String.valueOf(exam.getId()));
        holder.exam_name.setText(exam.getExamName());
        if(exam.getQuestions() != null) {
            holder.total_question_number.setText(String.valueOf(exam.getQuestions().size()) + " questions" );
        } else {
            holder.total_question_number.setText(String.valueOf(0) + " questions");
        }


        holder.bind(mListenerList.get(position), listener);
    }

    @Override
    public int getItemCount() {
        return mListenerList.size();
    }

    public void addItem(Exam item) {
        this.mListenerList.add(item);
        this.notifyItemRangeInserted(getItemCount() - 1, getItemCount());
    }

    public void editItem(Exam oldItem, Exam newItem) {
        int index = mListenerList.indexOf(oldItem);
        this.mListenerList.set(index, newItem);
        this.notifyItemChanged(index);
    }

    public void removeItem(Exam item) {
        this.mListenerList.remove(item);
        this.notifyDataSetChanged();
    }

    public void refresh() {
        this.notifyDataSetChanged();
    }

    @Override
    public void onQuestionItemClick(View v, Question item) {
        throw new UnsupportedOperationException("This Event as Not been implemented on questions {onExamItemClick}");
    }

    @Override
    public boolean onQuestionItemLongClick(View v, Question item) {
        throw new UnsupportedOperationException("This Event as Not been implemented on questions {onExamItemClick}");
    }

    @Override
    public void onExamItemClick(View v, Exam item) {

    }

    @Override
    public boolean onExamItemLongClick(View v, Exam item) {
       return true;
    }

    public class MyViewHolder extends RecyclerView.ViewHolder {
        TextView exam_name;
        TextView exam_number;
        TextView total_question_number;
        ImageView question_image_content;

        public MyViewHolder(View view) {
            super(view);
            exam_name = (TextView) view.findViewById(R.id.exam_text);
            exam_number = (TextView) view.findViewById(R.id.exam_number);
            total_question_number = (TextView) view.findViewById(R.id.exam_total_question_number);
        }

        public void bind(final Exam item, final OnItemClickListener listener) {
            itemView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    listener.onExamItemClick(v, item);
                }
            });
            itemView.setOnLongClickListener(new View.OnLongClickListener() {
                @Override
                public boolean onLongClick(View v) {
                    return listener.onExamItemLongClick(v, item);
                }
            });
        }
    }
}