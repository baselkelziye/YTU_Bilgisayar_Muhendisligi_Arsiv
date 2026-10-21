package ce.yildiz.android.ui.download.fragments;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.fragment.app.DialogFragment;

import ce.yildiz.android.R;

public class DownloadCompleteDialogFragment extends DialogFragment {
    public DownloadCompleteDialogFragment() {

    }

    public static DownloadCompleteDialogFragment newInstance(int imageId) {
        DownloadCompleteDialogFragment fragment = new DownloadCompleteDialogFragment();
        Bundle args = new Bundle();

        args.putInt("image_id", imageId);

        fragment.setArguments(args);

        return fragment;
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {
        return inflater.inflate(R.layout.fragment_download_complete_dialog, container);
    }

    @SuppressWarnings("deprecation")
    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);

        ImageView downloadIV = view.findViewById(R.id.download_complete_fragment_image);

        Bundle args = getArguments();

        if (args == null) return;

        int imageId = args.getInt("image_id", R.drawable.ic_file_download_accent_48dp);

        downloadIV.setImageDrawable(getResources().getDrawable(imageId));
    }
}
