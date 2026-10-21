import neuron
import neuron_utils as nu
import math
import matplotlib.pyplot as plt
import numpy as np


def sigmoid(x):
  return 1 / (1 + math.exp(-x))

def sigmoid_diff(x):
    return x * (1 - x)

def run_network(epoch, input_size, train_input, train_ex_output, classes):
    network_struct = [input_size, 7, 4, len(classes)]
    all_weights, all_sq_error = neuron.start_train(
        train_input, train_ex_output, network_struct, epoch, sigmoid, sigmoid_diff)

    show_error_plot(classes, epoch, all_sq_error)
    save_weights(all_weights, epoch)

    return all_weights

def show_error_plot(classes, epoch, all_sq_error):
    for i in range(0, len(classes)):
        class_name = list(classes.keys())[list(classes.values()).index(i)]
        print(class_name)
        plt.plot(range(1, epoch + 1), all_sq_error, label=class_name)
    plt.legend(loc='best')
    plt.savefig("{}e_error_rate.jpg".format((epoch)))

def save_weights(all_weights, epoch):
    for i in range(1, len(all_weights)):
        np.savetxt("{0}e_layer_{1}_weight.txt".format(epoch, i), all_weights[i], fmt="%1.3f", newline='\n')


input_size = 901
train_input, train_ex_output, classes = nu.get_images_as_inputs("./data/train", input_size - 1)

epoch = 1000
run_network(epoch, input_size, train_input, train_ex_output, classes)


