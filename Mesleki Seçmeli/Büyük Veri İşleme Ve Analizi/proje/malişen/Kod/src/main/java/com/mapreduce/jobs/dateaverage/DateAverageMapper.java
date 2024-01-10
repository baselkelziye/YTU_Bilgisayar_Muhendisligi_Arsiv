package com.mapreduce.jobs.dateaverage;

import java.io.IOException;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;

import com.mapreduce.util.JSONParser;

import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapred.MapReduceBase;
import org.apache.hadoop.mapred.Mapper;
import org.apache.hadoop.mapred.OutputCollector;
import org.apache.hadoop.mapred.Reporter;
import org.json.JSONObject;

public class DateAverageMapper extends MapReduceBase implements Mapper<LongWritable, Text, Text, IntWritable> {
	public static DateFormat format = new SimpleDateFormat("dd MMMM yyyy", Locale.US);
	public static Date from;
	public static Date to;

	public void map(LongWritable key, Text value, OutputCollector<Text, IntWritable> output, Reporter reporter) throws IOException {
		String valueString = value.toString();
		JSONObject obj = JSONParser.parse(valueString);
		String dateString = obj.getString("review_date");
		try {
			Date date = format.parse(dateString);
			if (!(date.after(from) && date.before(to))) {
				return;
			}
		} catch (Exception e) {
			e.printStackTrace();
			return;
		}
		try {
			output.collect(
				new Text(
					obj.getString("movie")
				),
				new IntWritable(
					Integer.parseInt(
						obj.getString("rating")
					)
				)
			);
		} catch (Exception e) {}
	}
}