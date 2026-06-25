package com.mapreduce.util;

import java.io.IOException;

import com.mapreduce.Singletons;

import org.apache.hadoop.fs.Path;
import org.apache.hadoop.fs.PathFilter;

public class DirectoryFilter implements PathFilter {
	@Override
	public boolean accept(Path p) {
		try {
			return Singletons.fileSystem.getFileStatus(p).isDirectory();
		} catch (IOException e) {
			e.printStackTrace();
			return false;
		}
	}
}
