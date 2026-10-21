import matplotlib.pyplot as plt

def grafik(gradient_descents, SGDs, AGs, ADAMs):
    SIZE = len(gradient_descents)
    FONTSIZE = 5

    hata_epochs_GDs = []
    hata_time_GDs = []
    basari_epochs_GDs = []
    basari_time_GDs = []
    hata_epochs_SGDs = []
    hata_time_SGDs = []
    basari_epochs_SGDs = []
    basari_time_SGDs = []
    hata_epochs_AGs = []
    hata_time_AGs = []
    basari_epochs_AGs = []
    basari_time_AGs = []
    hata_epochs_ADAMs = []
    hata_time_ADAMs = []
    basari_epochs_ADAMs = []
    basari_time_ADAMs = []

    for i in range(SIZE):

        hata_epochs_GD, hata_time_GD, basari_epochs_GD, basari_time_GD = gradient_descents[i]
        hata_epochs_SGD, hata_time_SGD, basari_epochs_SGD, basari_time_SGD = SGDs[i]
        hata_epochs_AG, hata_time_AG, basari_epochs_AG, basari_time_AG = AGs[i]
        hata_epochs_ADAM, hata_time_ADAM, basari_epochs_ADAM, basari_time_ADAM = ADAMs[i]

        hata_epochs_GDs.append(hata_epochs_GD)
        hata_time_GDs.append(hata_time_GD)
        basari_epochs_GDs.append(basari_epochs_GD)
        basari_time_GDs.append(basari_time_GD)
        hata_epochs_SGDs.append(hata_epochs_SGD)
        hata_time_SGDs.append(hata_time_SGD)
        basari_epochs_SGDs.append(basari_epochs_SGD)
        basari_time_SGDs.append(basari_time_SGD)
        hata_epochs_AGs.append(hata_epochs_AG)
        hata_time_AGs.append(hata_time_AG)
        basari_epochs_AGs.append(basari_epochs_AG)
        basari_time_AGs.append(basari_time_AG)
        hata_epochs_ADAMs.append(hata_epochs_ADAM)
        hata_time_ADAMs.append(hata_time_ADAM)
        basari_epochs_ADAMs.append(basari_epochs_ADAM)
        basari_time_ADAMs.append(basari_time_ADAM)

    plt.figure("Cosmos",figsize=(16, 9))  # figürü büyüt

    for i in range(SIZE):
        plt.subplot(SIZE,4, i * 4 + 1)
        plt.title(f"Hata - Epochs W_{i + 1}")
        plt.xlabel("Epochs")
        plt.ylabel("Hata")
        plt.plot(hata_epochs_GDs[i][:, 0], hata_epochs_GDs[i][:, 1], color="red")
        plt.plot(hata_epochs_SGDs[i][:, 0], hata_epochs_SGDs[i][:, 1], color="blue")
        plt.plot(hata_epochs_AGs[i][:, 0], hata_epochs_AGs[i][:, 1], color="purple")
        plt.plot(hata_epochs_ADAMs[i][:, 0], hata_epochs_ADAMs[i][:, 1], color="green")
        plt.legend(["Gradient Descent", "Stochastic Gradient Descent","AdaGrad", "ADAM"], loc="upper right", fontsize=FONTSIZE)
        plt.grid()

        plt.subplot(SIZE,4,i * 4 + 2)
        plt.title(f"Hata - Zaman W_{i + 1}")
        plt.xlabel("Zaman")
        plt.ylabel("Hata")
        plt.plot(hata_time_GDs[i][:, 0], hata_time_GDs[i][:, 1], color="red")
        plt.plot(hata_time_SGDs[i][:, 0], hata_time_SGDs[i][:, 1], color="blue")
        plt.plot(hata_time_AGs[i][:, 0], hata_time_AGs[i][:, 1], color="purple")
        plt.plot(hata_time_ADAMs[i][:, 0], hata_time_ADAMs[i][:, 1], color="green")
        plt.legend(["Gradient Descent", "Stochastic Gradient Descent","AdaGrad", "ADAM"], loc="upper right", fontsize=FONTSIZE)
        plt.grid()

        plt.subplot(SIZE,4,i * 4 + 3)
        plt.title(f"Başarı - Epochs W_{i + 1}")
        plt.xlabel("Epochs")
        plt.ylabel("Başarı")
        plt.plot(basari_epochs_GDs[i][:, 0], basari_epochs_GDs[i][:, 1], color="red")
        plt.plot(basari_epochs_SGDs[i][:, 0], basari_epochs_SGDs[i][:, 1], color="blue")
        plt.plot(basari_epochs_AGs[i][:, 0], basari_epochs_AGs[i][:, 1], color="purple")
        plt.plot(basari_epochs_ADAMs[i][:, 0], basari_epochs_ADAMs[i][:, 1], color="green")
        plt.legend(["Gradient Descent", "Stochastic Gradient Descent","AdaGrad", "ADAM"], loc="lower right", fontsize=FONTSIZE)
        plt.grid()

        plt.subplot(SIZE,4,i * 4 + 4)
        plt.title(f"Başarı - Zaman W_{i + 1}")
        plt.xlabel("Zaman")
        plt.ylabel("Başarı")
        plt.plot(basari_time_GDs[i][:, 0], basari_time_GDs[i][:, 1], color="red")
        plt.plot(basari_time_SGDs[i][:, 0], basari_time_SGDs[i][:, 1], color="blue")
        plt.plot(basari_time_AGs[i][:, 0], basari_time_AGs[i][:, 1], color="purple")
        plt.plot(basari_time_ADAMs[i][:, 0], basari_time_ADAMs[i][:, 1], color="green")
        plt.legend(["Gradient Descent", "Stochastic Gradient Descent","AdaGrad", "ADAM"], loc="lower right", fontsize=FONTSIZE)
        plt.grid()

    plt.tight_layout()
    plt.show()