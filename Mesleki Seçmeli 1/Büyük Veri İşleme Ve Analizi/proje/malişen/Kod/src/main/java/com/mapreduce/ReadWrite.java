package com.mapreduce;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

import com.mapreduce.util.DirectoryFilter;

import org.apache.commons.io.IOUtils;
import org.apache.hadoop.fs.FSDataInputStream;
import org.apache.hadoop.fs.FSDataOutputStream;
import org.apache.hadoop.fs.LocatedFileStatus;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.fs.PathFilter;
import org.apache.hadoop.fs.RemoteIterator;

public class ReadWrite {
	public static Path root = Singletons.fileSystem.getHomeDirectory();

	private static Path appendToRoot(String path) {
		return new Path(root.toString() + (path.startsWith("/") ? path : ("/" + path)));
	}

	public static void readFile(String fileName) throws IOException {
		Path path = appendToRoot(fileName);
		FSDataInputStream inputStream = Singletons.fileSystem.open(path);
		byte[] buffer = new byte[100 * 1024];
		System.out.println("\n\n");
		while (inputStream.read(buffer, 0, buffer.length) != -1) {
			System.out.print(IOUtils.toString(buffer, "UTF-8").trim());
		}
		inputStream.close();
	}

	public static Object[][] readTabular(String fileName) throws IOException {
		Path path = appendToRoot(fileName);
		FSDataInputStream inputStream = Singletons.fileSystem.open(path);
		Scanner scanner = new Scanner(inputStream);
		List<List<Object>> list = new ArrayList<List<Object>>();
		while (scanner.hasNextLine()) {
			String[] line = scanner.nextLine().split("\t");
			List<Object> row = new ArrayList<>();
			for (String col : line) {
				row.add(col);
			}
			list.add(row);
		}
		scanner.close();
		inputStream.close();
		return list.stream().map(i -> i.stream().toArray(Object[]::new)).toArray(Object[][]::new);
	}

	public static void writeFile(String fileName, String src) throws IOException {
		Path path = appendToRoot(fileName);
		FSDataOutputStream fsDataOutputStream = Singletons.fileSystem.create(path, true);
		FileInputStream fis = new FileInputStream(src);
		byte[] buffer = new byte[100 * 1024 * 1024];
		int read, size = 0;
		while ((read = fis.read(buffer, 0, buffer.length)) != -1) {
			size += read;
			fsDataOutputStream.write(buffer, 0, read);
		}
		System.out.println("\n\n");
		System.out.println("Bytes written: " + size);
		fis.close();
		fsDataOutputStream.close();
	}

	public static void removeFile(String fileName) throws IOException {
		Path path = appendToRoot(fileName);
		Singletons.fileSystem.delete(path, false);
	}

	public static void listFiles(String path) throws FileNotFoundException, IllegalArgumentException, IOException {
		System.out.println("\n\n");
		String[] directories = getDirectories(path, false);
		for (String dir : directories) {
			System.out.println(dir);
		}
		String[] files = getFiles(path);
		for (String file : files) {
			System.out.println(file);
		}
	}
	
	private static Comparator<String> depth = (a, b) -> (int) (a.chars().filter(i -> i == '/').count() - b.chars().filter(i -> i == '/').count());

	public static String[] getFiles(String path) throws FileNotFoundException, IllegalArgumentException, IOException {
		RemoteIterator<LocatedFileStatus> iter =
			Singletons.fileSystem.listFiles(appendToRoot(path), true);
		List<String> files = new ArrayList<>();
		while (iter.hasNext()) {
			files.add(iter.next().getPath().toString().replace(root.toString(), ""));
		}
		files.sort((a, b) -> depth.compare(a, b) == 0 ? a.compareTo(b) : (depth.compare(a, b) > 0 ? -1 : 1));
		return files.stream().toArray(String[]::new);
	}
	
	private static List<String> getDir(String path, PathFilter filter) {
		try {
			return Arrays
				.asList(Singletons.fileSystem.listStatus(new Path(path), filter))
				.stream()
				.map(i -> i.getPath().toString())
				.collect(Collectors.toList());
		} catch (IllegalArgumentException | IOException e) {
			e.printStackTrace();
			return Arrays.asList();
		}
	};

	public static String[] getDirectories(String path, boolean includeRoot) throws FileNotFoundException, IllegalArgumentException, IOException {
		DirectoryFilter directoryFilter = new DirectoryFilter();
		List<String> files = getDir(root.toString() + path, directoryFilter);
		for (int i = 0; i < files.size(); i++) {
			files.addAll(getDir(files.get(i), directoryFilter));
		}
		files.sort((a, b) -> depth.compare(a, b) == 0 ? a.compareTo(b) : (depth.compare(a, b) > 0 ? -1 : 1));
		if (includeRoot) files.add(0, "");
		return files.stream().map(i -> i.replace(root.toString(), "") + "/").toArray(String[]::new);
	}

	public static void createDirectory(String directoryName) throws IOException {
		Path path = appendToRoot(directoryName);
		Singletons.fileSystem.mkdirs(path);
	}

	public static void removeDirectory(String directoryName) throws IOException {
		Path path = appendToRoot(directoryName);
		Singletons.fileSystem.delete(path, true);
	}
}
