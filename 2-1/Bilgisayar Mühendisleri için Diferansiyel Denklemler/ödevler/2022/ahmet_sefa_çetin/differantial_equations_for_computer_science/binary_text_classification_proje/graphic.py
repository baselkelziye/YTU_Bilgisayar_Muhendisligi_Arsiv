import matplotlib.pyplot as plt

epoch_values = []
loss_values = []
time_values = []

# Dosyadan verileri oku
with open("gdDatasFile.txt", "r") as file:
    for line in file:
        epoch, loss, time = map(float, line.split())
        epoch_values.append(epoch)
        loss_values.append(loss)
        time_values.append(time)

# Loss vs Epoch grafiği
plt.plot(epoch_values, loss_values, label='Loss')
plt.xlabel('Epoch')
plt.ylabel('Loss')
plt.legend()
plt.show()

# Loss vs Time grafiği
plt.plot(time_values, loss_values, label='Loss')
plt.xlabel('Time')
plt.ylabel('Loss')
plt.legend()
plt.show()
