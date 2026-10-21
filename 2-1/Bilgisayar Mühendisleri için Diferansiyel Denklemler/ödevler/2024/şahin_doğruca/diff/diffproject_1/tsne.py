import numpy as np
from sklearn.manifold import TSNE
import matplotlib.pyplot as plt
import pandas as pd


def load_data():
    data = pd.read_csv('weights.txt', sep=',', header=None).to_numpy()

    tsne = TSNE(n_components=2, random_state=0)
    data = tsne.fit_transform(data)

    plt.figure(figsize=(8, 6))

    plt.scatter(data[:, 0], data[:, 1],
                c=np.repeat(np.arange(5), 1000), cmap='viridis')
    plt.title('t-SNE Visualization of Weight Evolution')
    plt.xlabel('Dimension 1')
    plt.ylabel('Dimension 2')
    plt.colorbar(label='Initialization')
    plt.show()


def load_data_2():
    data = pd.read_csv('weights.txt', sep=',', header=None).to_numpy()

    reshaped_data = np.reshape(data, (5, 1000, -1))

    print(reshaped_data.shape)

    tsne = TSNE(n_components=2, random_state=42)

    tsne_transformed = []

    for init_data in reshaped_data:
        # Reshape data for t-SNE
        init_data_2d = np.reshape(init_data, (init_data.shape[0], -1))
        print(init_data_2d.shape)
        # Apply t-SNE
        init_tsne = tsne.fit_transform(init_data_2d)
        tsne_transformed.append(init_tsne)

    plt.figure(figsize=(10, 8))
    for i, init_tsne in enumerate(tsne_transformed):
        plt.plot(init_tsne[:, 0], init_tsne[:, 1],
                 label=f'Initialization {i+1}')

    plt.title('t-SNE Visualization of Initialization Evolution')
    plt.xlabel('Dimension 1')
    plt.ylabel('Dimension 2')
    plt.legend()
    plt.show()


load_data()
