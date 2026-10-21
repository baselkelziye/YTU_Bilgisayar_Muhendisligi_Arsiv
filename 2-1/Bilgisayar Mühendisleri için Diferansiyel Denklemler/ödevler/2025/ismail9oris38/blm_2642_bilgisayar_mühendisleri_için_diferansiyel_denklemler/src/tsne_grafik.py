import numpy as np
import matplotlib.pyplot as plt
from sklearn.manifold import TSNE


def Tsne_grafik():
    FONTSIZE = 7
    W_GD = np.load("W_value/W_GD.npy")
    W_SGD = np.load("W_value/W_SGD.npy")
    W_AG = np.load("W_value/W_AG.npy")
    W_ADAM = np.load("W_value/W_ADAM.npy")

    tsne = TSNE(
        n_components=2,
        perplexity=5,
        learning_rate=200,
        max_iter=1000,
        random_state=10,
    )

    W_GD_2D = tsne.fit_transform(W_GD)
    W_SGD_2D = tsne.fit_transform(W_SGD)
    W_AG_2D = tsne.fit_transform(W_AG)
    W_ADAM_2D = tsne.fit_transform(W_ADAM)

    plt.figure("Cosmos ",figsize=(16, 9))

    colors = ["red", "blue", "green", "orange", "purple"]
    plt.subplot(4, 1, 1)
    for i in range(5):
        W_value = W_GD_2D[i * 100: i * 100 + 100]
        plt.plot(W_value[:,0], W_value[:, 1], color=colors[i], label=f"W_GD_{i}", lw=1.5)
        plt.scatter(W_value[0, 0], W_value[0, 1], color=colors[i], marker='o')
        plt.scatter(W_value[-1, 0], W_value[-1, 1], color=colors[i], marker='x')
        plt.title("T-SNE 2D Gradient Descent")
        plt.xlabel("T-SNE Boyut 1")
        plt.ylabel("T-SNE Boyut 2")
    plt.grid()
    plt.legend(loc="upper right", fontsize= FONTSIZE)

    plt.subplot(4, 1, 2)
    for i in range(5):
        W_value = W_SGD_2D[i * 100: i * 100 + 100]
        plt.plot(W_value[:,0], W_value[:, 1], color=colors[i], label=f"W_SGD_{i}", lw=1.5)
        plt.scatter(W_value[0, 0], W_value[0, 1], color=colors[i], marker='o')
        plt.scatter(W_value[-1, 0], W_value[-1, 1], color=colors[i], marker='x')
        plt.title("T-SNE 2D SGD")
        plt.xlabel("T-SNE Boyut 1")
        plt.ylabel("T-SNE Boyut 2")
    plt.grid()
    plt.legend(loc="upper right", fontsize= FONTSIZE)

    plt.subplot(4, 1, 3)
    for i in range(5):
        W_value = W_AG_2D[i * 100: i * 100 + 100]
        plt.plot(W_value[:,0], W_value[:, 1], color=colors[i], label=f"W_AG_{i}", lw=1.5)
        plt.scatter(W_value[0, 0], W_value[0, 1], color=colors[i], marker='o')
        plt.scatter(W_value[-1, 0], W_value[-1, 1], color=colors[i], marker='x')
        plt.title("T-SNE 2D AdaGrad")
        plt.xlabel("T-SNE Boyut 1")
        plt.ylabel("T-SNE Boyut 2")
    plt.grid()
    plt.legend(loc="upper right", fontsize= FONTSIZE)

    plt.subplot(4, 1, 4)
    for i in range(5):
        W_value = W_ADAM_2D[i * 100: i * 100 + 100]
        plt.plot(W_value[:,0], W_value[:, 1], color=colors[i], label=f"W_ADAM_{i}", lw=1.5)
        plt.scatter(W_value[0, 0], W_value[0, 1], color=colors[i], marker='o')
        plt.scatter(W_value[-1, 0], W_value[-1, 1], color=colors[i], marker='x')
        plt.title("T-SNE 2D ADAM")
        plt.xlabel("T-SNE Boyut 1")
        plt.ylabel("T-SNE Boyut 2")
    plt.grid()
    plt.legend(loc="upper right", fontsize= FONTSIZE)

    plt.tight_layout()
    plt.show()
