package com.mapreduce.util;

import java.io.IOException;
import java.util.Scanner;

public class ServiceStatus {
	private static String jps() {
		Process process;
		try {
			process = new ProcessBuilder("jps").start();
		} catch (IOException e) {
			e.printStackTrace();
			return "";
		}
		Scanner in = new Scanner(process.getInputStream());
		String result = "";
		while (in.hasNextLine()) {
			result += in.nextLine() + "\n";
		}
		in.close();
		return result;
	}

	public static boolean hadoop() {
		return jps().contains("DataNode");
	}

	public static boolean yarn() {
		return jps().contains("NodeManager");
	}
}
