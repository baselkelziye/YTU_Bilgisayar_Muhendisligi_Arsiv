package com.mapreduce.jobs.minmaxreview;

import java.io.IOException;

import com.mapreduce.util.JSONParser;

import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapred.MapReduceBase;
import org.apache.hadoop.mapred.Mapper;
import org.apache.hadoop.mapred.OutputCollector;
import org.apache.hadoop.mapred.Reporter;
import org.json.JSONObject;

public class MinMaxReviewMapper extends MapReduceBase implements Mapper<LongWritable, Text, Text, MinMaxTuple> {
	public void map(LongWritable key, Text value, OutputCollector<Text, MinMaxTuple> output, Reporter reporter) throws IOException {
		String valueString = value.toString();
		JSONObject obj = JSONParser.parse(valueString);
		try {
			Integer rating = Integer.parseInt(
				obj.getString("rating")
			);
			output.collect(
				new Text(
					obj.getString("movie")
				),
				new MinMaxTuple(rating, rating)		
			);
		} catch (Exception e) {}
	}
}