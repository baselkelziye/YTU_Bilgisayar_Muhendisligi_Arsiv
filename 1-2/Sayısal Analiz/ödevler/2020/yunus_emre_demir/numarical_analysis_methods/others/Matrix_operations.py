
m1 = m2 = [[2,0,4],
           [3,4,5],
           [8,7,1]]

m3 = [[0,0,0],[0,0,0],[0,0,0]]

for i in range(len(m1)):
    for j in range(len(m1[0])):         # 1. satırın uzunluğu yani : sütün uzunluğu
        m3[i][j] = m1[i][j]+m2[i][j]

for i in range(len(m1)):
    print(m1[i], "\t\t", m2[i])

print("Toplamları : ")
for i in range(len(m3)):
    print("\t\t\t\t\t\t\t",m3[i])




m4 =list()
for i in range(3):
    for j in range(3):
        m4[i][j].append(0)


