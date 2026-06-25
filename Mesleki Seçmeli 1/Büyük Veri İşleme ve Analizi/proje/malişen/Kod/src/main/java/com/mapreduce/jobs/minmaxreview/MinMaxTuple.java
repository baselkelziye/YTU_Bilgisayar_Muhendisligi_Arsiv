package com.mapreduce.jobs.minmaxreview;

import java.io.DataInput;
import java.io.DataOutput;
import java.io.IOException;

import org.apache.hadoop.io.Writable;

public class MinMaxTuple implements Writable {
	private Integer min = Integer.valueOf(0);
	private Integer max = Integer.valueOf(0);

	public MinMaxTuple() {}

	public MinMaxTuple(Integer min, Integer max) {
		this.min = min;
		this.max = max;
	}

	public Integer getMin() {
		return min;
	}

	public void setMin(Integer min) {
		this.min = min;
	}

	public Integer getMax() {
		return max;
	}

	public void setMax(Integer max) {
		this.max = max;
	}

	public void readFields(DataInput in) throws IOException {
		min = in.readInt();
		max = in.readInt();
	}

	public void write(DataOutput out) throws IOException {
		out.writeInt(min);
		out.writeInt(max);
	}

	public String toString() {
		return min + "\t" + max;
	}
}