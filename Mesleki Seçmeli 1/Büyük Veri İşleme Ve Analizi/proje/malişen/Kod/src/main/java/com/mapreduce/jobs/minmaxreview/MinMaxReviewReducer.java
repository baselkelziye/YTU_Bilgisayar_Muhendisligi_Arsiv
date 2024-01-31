package com.mapreduce.jobs.minmaxreview;

import java.io.IOException;
import java.util.Iterator;

import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapred.MapReduceBase;
import org.apache.hadoop.mapred.OutputCollector;
import org.apache.hadoop.mapred.Reducer;
import org.apache.hadoop.mapred.Reporter;

public class MinMaxReviewReducer extends MapReduceBase implements Reducer<Text, MinMaxTuple, Text, MinMaxTuple> {
	private MinMaxTuple result = new MinMaxTuple();

	public void reduce(Text key, Iterator<MinMaxTuple> values, OutputCollector<Text, MinMaxTuple> output, Reporter reporter) throws IOException {
		result.setMin(null);
		result.setMax(null);
		while (values.hasNext()) {
			MinMaxTuple minMaxTuple = values.next();
			if (result.getMax() == null || (minMaxTuple.getMax() > result.getMax())) {
				result.setMax(minMaxTuple.getMax());
			}
			if (result.getMin() == null || (minMaxTuple.getMin() < result.getMin())) {
				result.setMin(minMaxTuple.getMin());
			}
		}
		output.collect(key, result);
	}
}
