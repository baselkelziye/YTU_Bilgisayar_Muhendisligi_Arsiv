import numpy as np
import matplotlib.pyplot as plt

class MyLogisticRegression():

    @staticmethod
    def sigmoid_activation_function(x):
        """
        This function calculates the sigmoid of the input x.
        The sigmoid function is defined as:
        sigmoid(x) = 1 / (1 + exp(-x))
        """
        return 1 / (1 + np.exp(-x))
    
    @staticmethod
    def plot_sigmoid_function():
        """
        This function plots the sigmoid function in the range of -10 to 10.
        Used for the visualization of the sigmoid function.
        """

        # Create a range of values for x
        x = np.linspace(-10, 10, 100)

        # Calculate the sigmoid of x
        y = MyLogisticRegression.sigmoid_activation_function(x)

        # Plot the sigmoid function
        plt.figure(figsize=(7, 7))
        plt.plot(x, y)
        plt.title('Sigmoid Function')
        plt.xlabel('x')
        plt.ylabel('sigmoid(x)')
        plt.grid()
        plt.show()

    @staticmethod
    def calculate_cross_entropy_loss(y_true, y_pred):
        """
        Calculate the cross-entropy loss.

        Parameters:
        y_true (array-like): True labels.
        y_pred (array-like): Predicted probabilities.

        Returns:
        float: Cross-entropy loss.
        """
        # To avoid division by zero use epsilon
        epsilon = 1e-15
        y_pred = np.clip(y_pred, epsilon, 1 - epsilon)
        return -np.mean(y_true * np.log(y_pred) + (1 - y_true) * np.log(1 - y_pred))
    
    def __init__(self, learning_rate=0.001, n_of_iterations=1000):
        self.lr = learning_rate
        self.n_of_iterations = n_of_iterations
        self.weights = None
        self.bias = None
        self.losses = []


    def feed_forward(self,X):
        """"
        This function calculates the feed forward step of the logistic regression model.
        It calculates the dot product of the input X and the weights, adds the bias term and applies the sigmoid activation function.
        returns the activation value.
        """
        z = np.dot(X, self.weights) + self.bias
        A = self.sigmoid_activation_function(z)
        return A

    def fit(self, X, y):
        """
        Fit the logistic regression model using gradient descent.
        """
        n_samples, n_features = X.shape

        # init parameters
        self.weights = np.zeros(n_features)
        self.bias = 0

        # gradient descent
        for _ in range(self.n_of_iterations):
            A = self.feed_forward(X)
            self.losses.append(self.calculate_cross_entropy_loss(y, A))
            dz = A - y # derivative of sigmoid and bce X.T*(A-y)
            # compute gradients
            dw = (1 / n_samples) * np.dot(X.T, dz)
            db = (1 / n_samples) * np.sum(dz)
            # update parameters
            self.weights -= self.lr * dw
            self.bias -= self.lr * db

    def get_losses(self):
        """
        Returns the losses of the model.
        """
        return self.losses
    
    def predict(self, X):
        """"
        This function predicts the class of the input X.
        It calculates the dot product of the input X and the weights, adds the bias term and applies the sigmoid activation function.
        If the result is greater than the threshold it returns 1, otherwise 0.
        """
        threshold = .5
        y_hat = np.dot(X, self.weights) + self.bias
        y_predicted = self.sigmoid_activation_function(y_hat)

        y_predicted_cls = []
        for i in y_predicted:
            if i > threshold:
                y_predicted_cls.append(1)
            else:
                y_predicted_cls.append(0)

        
        return np.array(y_predicted_cls)
