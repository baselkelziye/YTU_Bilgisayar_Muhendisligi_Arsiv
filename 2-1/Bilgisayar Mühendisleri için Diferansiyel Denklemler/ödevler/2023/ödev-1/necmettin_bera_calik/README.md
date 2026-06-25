# binaryTextClassificationC

This repository contains a simple implementation of a neural network for binary classification using a single-layer perceptron with the hyperbolic tangent (tanh) activation function. The code is written in C and includes functionality for creating a dataset, generating hot vectors, and implementing various optimization algorithms.

## Features

- Binary classification using a single-layer perceptron
- Support for multiple optimization algorithms: gradient descent, stochastic gradient descent, and Adam optimization
- Dataset creation and processing functions
- Tanh activation function for limiting output values between -1 and 1
- parameters such as epsilon, learninRate and batchSize are set to give maximum accuracy after trying a bunch of possible combinations.  

## Usage

- clone to your local and make sure that you have A.txt B.txt file prepared properly
- bash ```cc ml.c -lm && ./a.out```

## Notes
- to observe training step by step set DEBUG to 1
- TYPE should be changed to use intended optimisation algorithm
- TRI can be set to 1 to tokenize data as trigrams
