package com.mapreduce.util;

import java.io.IOException;
import java.util.Scanner;

public class ProcessHandler {
	public static void run(String cmd) throws IOException {
		Process process = new ProcessBuilder(cmd).start();
		Scanner in = new Scanner(process.getInputStream());
		Scanner err = new Scanner(process.getErrorStream());
		System.out.println("\n\n");
		while (in.hasNextLine() || err.hasNextLine()) {
			if (in.hasNextLine()) System.out.println(in.nextLine());
			else System.err.println(err.nextLine());
		}
		in.close();
		err.close();
	}
}
