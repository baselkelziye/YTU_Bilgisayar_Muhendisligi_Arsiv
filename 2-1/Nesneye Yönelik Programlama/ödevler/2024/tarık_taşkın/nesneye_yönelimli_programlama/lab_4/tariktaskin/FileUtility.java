package tariktaskin;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.List;
import java.util.Scanner;
import java.util.ArrayList;


@SuppressWarnings("serial")
public class FileUtility implements Serializable{
	
	public static List<Employee> readEmployeesFromFile(String fileName){
		List<Employee> list = new ArrayList<Employee>();
		
		File file = new File(fileName);
		
		try {
			Scanner scanner = new Scanner(file);
			while(scanner.hasNextLine()) {
				String temp = scanner.nextLine();
				String[] data = temp.split(",");
				String name = data[0];
				double salary = Double.parseDouble(data[1]);
				if(data.length == 2) {
					list.add(new Employee(name, salary));
				}else if(data.length == 3) {
					double bonus = Double.parseDouble(data[2]);
					list.add(new Manager(name, salary, bonus));
				}
			}
			scanner.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		return list;
	}
	
	public static void writeEmployeesToFile(List<Employee> list, String fileName) {
		try {
			FileWriter file = new FileWriter(fileName);
			for(Employee i : list) {
				String out;
				if(i instanceof Manager) {
					Manager j = (Manager) i;
					out = j.getName() + "," + j.getSalary() + "," + j.getBonus() + "\n";
				}else {
					out = i.getName() + "," + i.getSalary() + "\n";
				}
				file.write(out);
			}
			file.close();
			
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}
	
	
}
