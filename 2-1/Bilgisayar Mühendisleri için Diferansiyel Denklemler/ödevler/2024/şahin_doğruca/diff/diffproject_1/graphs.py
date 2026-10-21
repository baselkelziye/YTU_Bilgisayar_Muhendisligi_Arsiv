import matplotlib.pyplot as plt
import numpy as np
import pandas as pd


def get_costs():
    data = pd.read_csv('costs.txt', sep=',', header=None)
    costs = data.iloc[:, 0].to_numpy()
    values = data.iloc[:, 1:].to_numpy()

    return costs, values


def plot_costs():
    costs, values = get_costs()

    plt.plot(np.linspace(0, costs[0], 10000), values[0])

    plots = [plt.plot(np.linspace(0, costs[i], 10000), values[i])
             for i in range(0, 3)]

    plots = [plt.plot(np.arange(0, 10000, 1), values[i])
             for i in range(3, 6)]

    fig, axs = plt.subplots(2, 3, figsize=(18, 8))

    axs = axs.flatten()

    for i in range(0, 3):
        axs[i].plot(np.linspace(0, costs[i], 10000), values[i])
        if i % 3 == 1:
            axs[i].set_title("Gradient Descent")
        elif i % 3 == 2:
            axs[i].set_title("Stochastic Gradient Descent")
        else:
            axs[i].set_title("Adam")

        axs[i].set_xlabel("Time")
        axs[i].set_ylabel("Cost")

    for i in range(3, 6):
        axs[i].plot(np.arange(0, 10000, 1), values[i])
        if i % 3 == 1:
            axs[i].set_title("Gradient Descent")
        elif i % 3 == 2:
            axs[i].set_title("Stochastic Gradient Descent")
        else:
            axs[i].set_title("Adam")

        axs[i].set_xlabel("Epocs")
        axs[i].set_ylabel("Cost")

    plt.show()


plot_costs()
