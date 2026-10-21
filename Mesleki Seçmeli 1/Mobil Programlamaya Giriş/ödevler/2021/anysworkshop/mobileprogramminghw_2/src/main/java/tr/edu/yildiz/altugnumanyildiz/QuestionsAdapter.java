package tr.edu.yildiz.altugnumanyildiz;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.ArrayList;

public class QuestionsAdapter extends RecyclerView.Adapter<QuestionsAdapter.QuestionsViewHolder> {

    private ArrayList<Question> mQuestionArrayList;
    private OnItemClickListener mListener;

    public interface OnItemClickListener {
        void onItemClick(int position);
    }

    public void setOnItemClickListener(OnItemClickListener listener){
        mListener = listener;
    }

    public static class QuestionsViewHolder extends RecyclerView.ViewHolder{
        public ImageView imageView;
        public TextView textView1;
        public TextView textView2;

        public QuestionsViewHolder(@NonNull View itemView, final OnItemClickListener listener) {
            super(itemView);
            imageView = itemView.findViewById(R.id.imageViewCard);
            textView1 = itemView.findViewById(R.id.textViewCard1);
            textView2 = itemView.findViewById(R.id.textViewCard2);

            itemView.setOnClickListener(new View.OnClickListener(){

                @Override
                public void onClick(View view) {
                    if (listener != null) {
                        int position = getAdapterPosition();
                        if (position != RecyclerView.NO_POSITION) {
                            listener.onItemClick(position);
                        }
                    }
                }
            });

        }
    }

    public QuestionsAdapter(ArrayList<Question> questionArrayList){
        mQuestionArrayList = questionArrayList;
    }

    @NonNull
    @Override
    public QuestionsViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View v = LayoutInflater.from(parent.getContext()).inflate(R.layout.question_item,parent,false);
        QuestionsViewHolder evh = new QuestionsViewHolder(v,mListener);
        return evh;
    }

    @Override
    public void onBindViewHolder(@NonNull QuestionsViewHolder holder, int position) {
        Question currentItem = mQuestionArrayList.get(position);

        Bitmap bitmap = BitmapFactory.decodeByteArray(currentItem.getByteArrays(),0,currentItem.getByteArrays().length);
        holder.imageView.setImageBitmap(bitmap);
        holder.textView1.setText(currentItem.getQuestionText());
        holder.textView2.setText(currentItem.getCorrectAnswer());
    }

    @Override
    public int getItemCount() {
        return mQuestionArrayList.size();
    }



}
