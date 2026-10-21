__author__ = 'vertexclique'

# Run with below command to inspect the output properly
# time python -u mlhwtwo.py | tee mlhwtwooutput.txt

import math
import numpy as np
from scipy.spatial import distance

def readcsv():
    """
    Read CSV. Doesn't need to user csv lib.
    :return: results in row-based list
    """
    allresults = []
    with open('sayi.dat') as f:
        for line in f:
            text = line.rstrip("\n").split(",")
            result = map(int, text)
            allresults.append(result)
        return allresults

def euclidean_distance(sample1, sample2):
    """
    Use euclidean distance to calculate set distances
    Also minkowski gives good results with polynomial 1

    :param sample1: First sample
    :param sample2: Second sample
    :return: distance between them
    """
    return distance.euclidean(sample1, sample2)

def evaluate(calculated, expected, matrix_10x10):
    """
    Fill the fold matrix and evaluate the predicted class

    :param calculated: k-NN calculated class
    :param expected: expected class at index 65
    :param matrix_10x10: 10x10 matrix for inspection of all
    :return: evaluated results and matrix itself
    """
    result = []

    # If expected length is not equal to calculated one dismiss it
    if calculated.__len__() != expected.__len__():
        raise "Error on calculation"
    else:
        for x in range(0, calculated.__len__()):
            # Substract two data to find which one is correct as class
            result.append(calculated[x] - expected[x])
            # Calculate 10x10 matrix for folding
            matrix_10x10[expected[x]][calculated[x]] += 1

    # make array of evaluation results
    eval_result = np.zeros(2,int)
    for x in result:
        # increment the correct prediction by 1
        if x == 0:
            eval_result[0] += 1
        # increment the wrong prediction by 1
        else:
            eval_result[1] += 1
    # return evaluation result
    return eval_result, matrix_10x10

def knn(kvalue, trainset, testset, classdata):
    """
    k-NN calculation

    :param kvalue: k-NN kvalue
    :param trainset: training set
    :param testset: testing set
    :param classdata: true class data
    :return: calculated classes of testing data
    """
    pred_class = []
    for testi, testd in enumerate(testset):
        distances = []
        for traini, traind in enumerate(trainset):
            # append euclidean distances to be sorted
            distances.append((euclidean_distance(testd, traind), traini))

        # sort distances inversely from smallest to largest and take kvalue times.
        k_nn = sorted(distances)[:kvalue]

        pred_class.append(classify(k_nn, classdata))

    # return prediction class
    return pred_class

def most_common(lst):
    """
    Find most common element in list so we can classify in_circle elements
    :param lst: list to find the most common element in it
    :return: most common element...
    """
    return max(set(lst), key=lst.count)

def classify(selected_knn, class_data):
    """
    Classify selected instances into class of them
    We can call them in_circle

    :param selected_knn: reached number of k elements
    :param class_data: class data of elements
    :return: the most common element in that class so sleected k-nn will be that
    """

    in_circle = []
    for index, value in selected_knn:
        in_circle.append(class_data[value])

    return most_common(in_circle)

def partition(waiting_list, indices):
    """
    Split a list into partition with given indexes

    :param waiting_list: list to be partitioned based on indices
    :param indices: indices that slices into pieces
    :return: slices...
    """
    return [waiting_list[i:j] for i, j in zip([0]+indices, indices+[None])]

def extract_classes(general_row):
    """
    Extract true classes from the end of data
    and make a classes list from them

    :param general_row: just a 65 indexed row
    :return: copy the last one and return it (it is not `.pop` method nor `del`)
    """
    classes = []
    for ex in general_row:
        classes.append(ex[-1])

    return classes

def kfold_partitioner(allresults, fold_count):
    """
    k-FOLD code to make folding properly
    It is flexible as you can see, it takes fold count
    and folds in for that count

    :param allresults: all data used in experimenting
    :param fold_count: fold count for slices
    :return: slices based on list of lists
    """
    slices = []
    ind = 0

    testslicecount = int(math.floor(allresults.__len__()/fold_count))

    training_set, testing_set, expects_train, expects_test = ([] for i in range(4))

    for x in xrange(0, fold_count):
        slices.append(partition(allresults, [ind, ind+testslicecount]))
        ind += testslicecount
        # print(slices[x][1].__len__()) # Going to be test data
        # slices [x][1] is going to be test data
        # Extend the list of first slice with others rather than testing set
        slices[x][0].extend(slices[x][2])
        # print(slices[x][0].__len__()) # Going to be train data
        # slices [x][0] is going to be train data
        expects_train.append(extract_classes(slices[x][0]))
        expects_test.append(extract_classes(slices[x][1]))

        training_set.append(slices[x][0])
        testing_set.append(slices[x][1])

    return training_set, testing_set, expects_train, expects_test


if __name__ == "__main__":
    # Read it first
    allresults = readcsv()

    # k-fold number
    foldnumber = 10

    # k-values for testing
    kvalues = [1, 3, 5]

    # Did i remove trailing true classes?
    remove_trailing = False
    # Store final evaluation results
    final_results = []
    # Store performance results
    performance = []

    # Apply k-fold partitioning to data set
    train, test, expected_train, expected_test = kfold_partitioner(allresults=allresults, fold_count=foldnumber)

    for kval in kvalues:
        matrix_10x10 = [[0 for i in range(10)] for _ in range(10)]
        # Cross validate with k-fold
        for x in xrange(0, foldnumber):
            # Remove trailing expected class values from sets at first iteration
            if remove_trailing == False:
                for row in train[x]:
                    del row[-1]
                for row in test[x]:
                    del row[-1]
                remove_trailing = True

            # Run k-NN and evaluate results
            pred_class = knn(kval, train[x], test[x], expected_train[x])
            eval_result, res_matrix_10x10 = evaluate(pred_class, expected_test[x], matrix_10x10)

            # Print result matrix and inspect it
            for a in res_matrix_10x10:
                print a

            # Print prediction class set and expected set just for inspection
            # print "==="
            # print(pred_class)
            # print(expected_test[x])
            # print "==="

            # Print how many is tru how many is false in evaluation and
            # calculate performance from evaluation results
            final_results.append(eval_result[0])
            final_results.append(eval_result[1])
            print final_results[0], final_results[1]
            performance.append(float(final_results[0]) / float(final_results[0] + final_results[1]))
            final_results = []
            print "PERFORMANCE for K=%i: " % kval
            print(performance)
        print "PERFORMANCE AVERAGE: %f" % np.mean(performance)
        performance = []