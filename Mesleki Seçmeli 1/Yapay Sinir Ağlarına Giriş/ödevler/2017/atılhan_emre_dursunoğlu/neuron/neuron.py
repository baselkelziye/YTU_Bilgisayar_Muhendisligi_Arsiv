import numpy as np
import random
import math

def return_neural_layer_output(data, weight, acti_func):
    ret_val = np.dot(data, weight)
    acti_func = np.vectorize(acti_func)
    return acti_func(ret_val)

def run_an_instance(_input, all_weights, acti_func):
    all_layer_input = []
    all_layer_input.append(_input)

    neuron_inputs = _input
    for weight in all_weights:
        ret_vals = return_neural_layer_output(neuron_inputs, weight, acti_func)
        all_layer_input.append(ret_vals)
        neuron_inputs = ret_vals

    return all_layer_input

def calc_sq_error(ex_output, output):
    error = ex_output - output
    return error * error / 2

def backpropogation(all_layer_input, all_weights, layer_no, acti_func_diff, deltaW, ret_val):
    if len(all_layer_input) - 2 > layer_no:
        deltaW = np.dot(deltaW, np.transpose(all_weights[layer_no + 1]))

    deltaW *= acti_func_diff(all_layer_input[layer_no + 1])

    if layer_no > 0:
        backpropogation(all_layer_input, all_weights, layer_no - 1, acti_func_diff, deltaW, ret_val)

    ret_val.append(np.outer(all_layer_input[layer_no], deltaW))

def shuffle_ios(inputs, outputs):
    state = random.getstate()
    random.shuffle(inputs)
    random.setstate(state)
    random.shuffle(outputs)

def start_train(inputs, ex_outputs, network_struct, total_epoch, acti_func, acti_func_diff):
    #assigning random weights for each layer
    all_weights = []
    for i in range(0, len(network_struct) - 1):
        current_layer, next_layer = network_struct[i], network_struct[i + 1]
        rand_weight = np.random.rand(current_layer, next_layer)
        all_weights.append(rand_weight)

    #epoch starts
    all_sq_error = []
    for i in range(0, total_epoch):
        print("epoch: {}".format((i)))
        for _input, ex_output in zip(inputs, ex_outputs):
            all_layer_input = run_an_instance(_input, all_weights, acti_func)

            new_ex_output = np.zeros((1,4))
            new_ex_output[0][ex_output] = 1
            all_delta = []
            deltaW = all_layer_input[-1] - new_ex_output
            backpropogation(all_layer_input, all_weights, len(network_struct) - 2, acti_func_diff, deltaW, all_delta)
            all_weights = [weight - delta for weight, delta in zip(all_weights, all_delta)]
        sq_error = calc_sq_error(new_ex_output, all_layer_input[-1])
        all_sq_error.append(np.sum(sq_error))
        shuffle_ios(inputs, ex_outputs)

    return all_weights, all_sq_error

def start_test(inputs, ex_outputs, all_weights, acti_func):
    prediction_vals = []
    for _input, ex_output in zip(inputs, ex_outputs):
        all_layer_input = run_an_instance(_input, all_weights, acti_func)

        output = all_layer_input[-1]
        prediction_vals.append(np.argmax(output))

    return prediction_vals

