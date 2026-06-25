package com.mapreduce.jobs.totalreviews;

import com.mapreduce.Singletons;
import com.mapreduce.util.JSONParser;
import com.mapreduce.util.XmlInputFormat;

import org.apache.hadoop.fs.Path;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapred.FileInputFormat;
import org.apache.hadoop.mapred.FileOutputFormat;
import org.apache.hadoop.mapred.JobClient;
import org.apache.hadoop.mapred.JobConf;
import org.apache.hadoop.mapred.TextOutputFormat;

public class TotalReviewsDriver {
	public static void run(String[] inputs, String output) {
		JobConf jobConf = new JobConf(TotalReviewsDriver.class);

		jobConf.set(XmlInputFormat.START_TAG_KEY, JSONParser.prefix);
		jobConf.set(XmlInputFormat.END_TAG_KEY, JSONParser.suffix);

		jobConf.setJobName("TotalReviews");

		jobConf.setOutputKeyClass(Text.class);
		jobConf.setOutputValueClass(IntWritable.class);

		jobConf.setMapperClass(TotalReviewsMapper.class);
		jobConf.setReducerClass(TotalReviewsReducer.class);

		jobConf.setInputFormat(XmlInputFormat.class);
		jobConf.setOutputFormat(TextOutputFormat.class);

		Path[] inputPaths = new Path[inputs.length];
		for (int i = 0; i < inputPaths.length; i++) {
			inputPaths[i] = new Path(inputs[i]);
		}
		FileInputFormat.setInputPaths(jobConf, inputPaths);
		FileOutputFormat.setOutputPath(jobConf, new Path(output));

		Singletons.jobClient.setConf(jobConf);
		try {
			JobClient.runJob(jobConf);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
