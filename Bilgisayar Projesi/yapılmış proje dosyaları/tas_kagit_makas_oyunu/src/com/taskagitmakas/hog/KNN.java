package com.taskagitmakas.hog;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashSet;
import java.util.List;
import java.util.Random;
import java.util.Set;

import com.taskagitmakas.dao.ImageDao;
import com.taskagitmakas.dao.ImageImp;
import com.taskagitmakas.entity.Image;
import com.taskagitmakas.form.LoginForm;
import static java.lang.Math.toIntExact;
public class KNN {

	public List<Image> myTrainSet;
	public double[][] descriptionGeneral, descriptionBaseOnUser, descriptionWithOutUser;
	public ImageDao imageService;

	public KNN() {
		int userId = LoginForm.selectedUser.getId();
		System.out.println("userid "+userId);
		imageService = new ImageImp();
		myTrainSet = new ArrayList<Image>();
		myTrainSet = imageService.all();
		descriptionGeneral = new double[myTrainSet.size()][myTrainSet.get(1).getRowCount()];
		descriptionBaseOnUser = new double[toIntExact(imageService.getCountByUser(userId))][myTrainSet.get(1).getRowCount()];
		descriptionWithOutUser = new double[myTrainSet.size()-toIntExact(imageService.getCountByUser(userId))][myTrainSet.get(1).getRowCount()];

		int j = 0;
		int k = 0;

		int l = 0;
		int m = 0;

		int x = 0;
		int y = 0;

		for (Image image : myTrainSet) {

			String data[] = image.getHogDescriptionVector().split(",");
			k = 0;
			m = 0;
			y = 0;

			for (int i = 0; i < image.getRowCount(); i++) {
				descriptionGeneral[j][k] = Double.parseDouble(data[i]);
				k++;
				
					/*	if (userId == image.getId()) {
		
							descriptionBaseOnUser[l][m] = Double.parseDouble(data[i]);
							m++;
						}
						
						if (userId != image.getUserId()) {
		
							descriptionWithOutUser[x][y] = Double.parseDouble(data[i]);
							y++;
						}
				*/

				
			}
					/*	if (userId == image.getUserId()) {
			
							l++;
			
						}
						if (userId != image.getUserId()) {
			
							x++;
			
						}
					*/
			j++;

		}
		System.out.println("Toplam sample: "+descriptionGeneral.length);
		System.out.println("Kullanıcaya ait sample: "+toIntExact(imageService.getCountByUser(userId)));
		System.out.println("Kullanıcaya ait olmayan sample: "+descriptionWithOutUser.length);

	}

	/**
	 * Returns the majority value in an array of strings majority value is the
	 * most frequent value (the mode) handles multiple majority values (ties
	 * broken at random)
	 *
	 * @param array
	 *            an array of strings
	 * @return the most frequent string in the array
	 */
	String findMajorityClass(String[] array) {
		// add the String array to a HashSet to get unique String values
		Set<String> h = new HashSet<String>(Arrays.asList(array));
		// convert the HashSet back to array
		String[] uniqueValues = h.toArray(new String[0]);
		// counts for unique strings
		int[] counts = new int[uniqueValues.length];
		// loop thru unique strings and count how many times they appear in
		// origianl array
		for (int i = 0; i < uniqueValues.length; i++) {
			for (int j = 0; j < array.length; j++) {
				if (array[j].equals(uniqueValues[i])) {
					counts[i]++;
				}
			}
		}

		for (int i = 0; i < uniqueValues.length; i++)
			System.out.println(uniqueValues[i]);
		for (int i = 0; i < counts.length; i++)
			System.out.println(counts[i]);

		int max = counts[0];
		for (int counter = 1; counter < counts.length; counter++) {
			if (counts[counter] > max) {
				max = counts[counter];
			}
		}
		System.out.println("max # of occurences: " + max);

		// how many times max appears
		// we know that max will appear at least once in counts
		// so the value of freq will be 1 at minimum after this loop
		int freq = 0;
		for (int counter = 0; counter < counts.length; counter++) {
			if (counts[counter] == max) {
				freq++;
			}
		}

		// index of most freq value if we have only one mode
		int index = -1;
		if (freq == 1) {
			for (int counter = 0; counter < counts.length; counter++) {
				if (counts[counter] == max) {
					index = counter;
					break;
				}
			}
			// System.out.println("one majority class, index is: "+index);
			return uniqueValues[index];
		} else {// we have multiple modes
			int[] ix = new int[freq];// array of indices of modes
			System.out.println("multiple majority classes: " + freq + " classes");
			int ixi = 0;
			for (int counter = 0; counter < counts.length; counter++) {
				if (counts[counter] == max) {
					ix[ixi] = counter;// save index of each max count value
					ixi++; // increase index of ix array
				}
			}

			for (int counter = 0; counter < ix.length; counter++)
				System.out.println("class index: " + ix[counter]);

			// now choose one at random
			Random generator = new Random();
			// get random number 0 <= rIndex < size of ix
			int rIndex = generator.nextInt(ix.length);
			System.out.println("random index: " + rIndex);
			int nIndex = ix[rIndex];
			// return unique value at that index
			return uniqueValues[nIndex];
		}

	}

	/**
	 * Returns the mean (average) of values in an array of doubless sums
	 * elements and then divides the sum by num of elements
	 *
	 * @param array
	 *            an array of doubles
	 * @return the mean
	 */
	private double meanOfArray(double[] m) {
		double sum = 0.0;
		for (int j = 0; j < m.length; j++) {
			sum += m[j];
		}
		return sum / m.length;
	}

	// simple class to model instances (features + class)
	class ImageSamples {
		double[] hogDescription;
		String classType;

		public ImageSamples(double[] hogDescription, String classType) {
			this.classType = classType;
			this.hogDescription = hogDescription;
		}
	}

	// simple class to model results (distance + class)
	class Result {
		double distance;
		String classType;

		public Result(double distance, String classType) {
			this.classType = classType;
			this.distance = distance;
		}
	}

	// simple comparator class used to compare results via distances
	class DistanceComparator implements Comparator<Result> {
		@Override
		public int compare(Result a, Result b) {
			return a.distance < b.distance ? -1 : a.distance == b.distance ? 0 : 1;
		}
	}

	public void testFromDB(Image image) {

		int k = 1;// # of neighbours

		List<ImageSamples> imagesSampleList = new ArrayList<ImageSamples>();
		List<Result> resultList = new ArrayList<Result>();
		for (int b = 0; b < myTrainSet.size(); b++) {

			imagesSampleList.add(new ImageSamples(descriptionGeneral[b], " " + myTrainSet.get(b).getClassType() + ""));

		}

		double[] query = new double[5940];
		String data[] = image.getHogDescriptionVector().split(",");
		int xx = 0;
		for (int i = 0; i < image.getRowCount(); i++) {
			query[xx] = Double.parseDouble(data[i]);

			xx++;
		}

		// find disnaces
		for (ImageSamples sample : imagesSampleList) {
			double dist = 0.0;
			for (int j = 0; j < sample.hogDescription.length; j++) {
				dist += Math.pow(sample.hogDescription[j] - query[j], 2);

			}

			double distance = Math.sqrt(dist);
			resultList.add(new Result(distance, sample.classType));
		}

		// System.out.println(resultList);
		Collections.sort(resultList, new DistanceComparator());
		String[] ss = new String[k];
		for (int x = 0; x < k; x++) {
			System.out.println(resultList.get(x).classType + " .... " + resultList.get(x).distance);
			// get classes of k nearest instances (city names) from the list
			// into an array
			ss[x] = resultList.get(x).classType;
		}
		String majClass = findMajorityClass(ss);
		System.out.println("Class of new instance is: " + majClass);

	}

	public String testFromDescription(double[] descriptionFromUser) {

		int k = 1;// # of neighbours

		List<ImageSamples> imagesSampleList = new ArrayList<ImageSamples>();
		List<Result> resultList = new ArrayList<Result>();
		for (int b = 0; b < myTrainSet.size(); b++) {

			imagesSampleList.add(new ImageSamples(descriptionGeneral[b], " " + myTrainSet.get(b).getClassType() + ""));

		}

		// find distances
		for (ImageSamples sample : imagesSampleList) {
			double dist = 0.0;
			for (int j = 0; j < sample.hogDescription.length; j++) {
				dist += Math.pow(sample.hogDescription[j] - descriptionFromUser[j], 2);

			}

			double distance = Math.sqrt(dist);
			resultList.add(new Result(distance, sample.classType));
		}

		// System.out.println(resultList);
		Collections.sort(resultList, new DistanceComparator());
		String[] ss = new String[k];
		for (int x = 0; x < k; x++) {
			System.out.println(resultList.get(x).classType + " .... " + resultList.get(x).distance);
			// get classes of k nearest instances (city names) from the list
			// into an array
			ss[x] = resultList.get(x).classType;
		}
		String majClass = findMajorityClass(ss);
		System.out.println("Class of new instance is: " + majClass);

		return majClass;
	}

	public String testFromDescriptionBaseOnUser(double[] descriptionFromUser) {

		int k = 1;// # of neighbours

		List<ImageSamples> imagesSampleList = new ArrayList<ImageSamples>();
		List<Result> resultList = new ArrayList<Result>();
		for (int b = 0; b < myTrainSet.size(); b++) {

			imagesSampleList.add(new ImageSamples(descriptionGeneral[b], " " + myTrainSet.get(b).getClassType() + ""));

		}

		// find distances
		for (ImageSamples sample : imagesSampleList) {
			double dist = 0.0;
			for (int j = 0; j < sample.hogDescription.length; j++) {
				dist += Math.pow(sample.hogDescription[j] - descriptionFromUser[j], 2);

			}

			double distance = Math.sqrt(dist);
			resultList.add(new Result(distance, sample.classType));
		}

		// System.out.println(resultList);
		Collections.sort(resultList, new DistanceComparator());
		String[] ss = new String[k];
		for (int x = 0; x < k; x++) {
			System.out.println(resultList.get(x).classType + " .... " + resultList.get(x).distance);
			// get classes of k nearest instances (city names) from the list
			// into an array
			ss[x] = resultList.get(x).classType;
		}
		String majClass = findMajorityClass(ss);
		System.out.println("Class of new instance is: " + majClass);

		return majClass;
	}

}
