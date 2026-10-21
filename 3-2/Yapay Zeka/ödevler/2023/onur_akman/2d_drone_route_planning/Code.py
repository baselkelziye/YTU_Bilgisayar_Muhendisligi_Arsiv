import numpy as np
import random
import matplotlib.pyplot as plt

#%%

# genetik algoritma
# fitness1: ziyaret edilen noktalar
# fitness2: tekrarlı ziyaret edilen noktalar
# fitness3: yön değiştirme maliyeti

#%% Degiskenler

drone_count = 4

mutation_rate = 0.01 # mutasyon orani
generation = 700 # nesil sayisi
population_size = 5000 # populasyon buyuklugu
cross = 2 # crossover kesme sayisi

x_dim = 9 #matrix buyuklugu
y_dim = x_dim
start_loc = [0, 0] #baslangic noktasi

plot_every = 70 # hangi aralıklarla cizdirilmeli

#%% Hareketler & Maliyetler

# olası hareketler - 0 olduğu yerde kalması 1-8 yönler
steps=[[0, 0], [1, 0], [1, -1], [0, -1], [-1, -1], [-1, 0], [-1, 1], [0, 1], [1, 1]]

# hareketler icin acisal degerler
step_angle = [-1, 0, 315, 270, 225, 180, 135, 90, 45]


# ardisik hareketler arasi maliyetler matrisi
step_expense = [];

for i in step_angle:
    satir = [];
    for j in step_angle:
        x, y = max(i, j), min(i, j)
        if y == -1:
            satir.append(180)
        else:
            if ((x-y) <= 180):
                satir.append((x-y))
            else:
                satir.append((360-(x-y)))
    step_expense.append(satir)
          
#print(step_expense)

#%% Bagli degiskenler
    
mtx = np.zeros((x_dim,y_dim), dtype=int) # matris ortam
person_length = (int)(x_dim*y_dim/drone_count)+2 # her bireyin uzunluğu
copy_to_next = (int)(population_size - population_size / 3) # sonraki nesle direkt kopyalanan en iyi birey sayisi
#copy_to_next = 0
current_gen = np.zeros((drone_count, population_size, person_length), dtype=int) # bireyler
best_of_gen = np.zeros((generation), dtype=float) # her neslin en iyi bireyinin iyilik degerini tutar
mean_of_gen = best_of_gen.copy() # her neslin ortalama degerini tutar

# ilk bireyler
current_gen = np.round(7*np.random.rand(drone_count, population_size, person_length)+1).astype(np.int)
#print(current_gen)

#%% Fitness fonksiyonlari max degerleri

max_f1 = (x_dim * y_dim) - 1
max_f2 = drone_count * (person_length+1)
max_f3 = drone_count * max(max(step_expense)) * (person_length-1)

#%% Genetik algoritma

for i in range (0, generation):
    
    # fitness
    f1 = np.zeros((population_size), dtype=int)
    f2 = f1.copy()
    f3 = f1.copy()
    
    for j in range (0, population_size):
        mtx = np.zeros((x_dim,y_dim), dtype=int) # ortamı 0 la
        indvs = [] # uzerinde calisiliacak bireyler
        kxy = [] # anlik konum
        for idx in range (0, drone_count):
            indvs.append(current_gen[idx][j])
            kxy.append(start_loc.copy()) # herkes ayni yerden baslar
        # bireyin hareketini olustur
        mtx[kxy[0][0]][kxy[0][1]] = 1  # baslangıçta
        for indv_index in range(0, drone_count):
            for k in range (0, person_length):
                p_kxy = [kxy[indv_index][0] + steps[indvs[indv_index][k]][0], kxy[indv_index][1] + steps[indvs[indv_index][k]][1]] # hareketi olustur
                if ((p_kxy[0] < 0) or (p_kxy[1] < 0) or (p_kxy[0] >= x_dim) or (p_kxy[1] >= y_dim)): 
                    indvs[indv_index][k] = 0 # disari cikarsa yerinde kalsin
                else: 
                    kxy[indv_index]=p_kxy # disari cikmadi hareket et
                mtx[kxy[indv_index][0]][kxy[indv_index][1]] += 1 

        # fitness skor hesaplamaları
        cntVisited = 0
        cntGreaterThanOnes = 0
        sumGreaterThanOnes = 0
        for row in mtx:
            for cell in row:
                if cell != 0:
                    cntVisited += 1
                if cell > 1:
                    cntGreaterThanOnes += 1
                    sumGreaterThanOnes += cell
        
        # f1 = max-gezdigi hucre sayisi            
        f1[j] = (x_dim * y_dim) - cntVisited; 
        # f2 = tekrar tekrar ziyaret edilen hucrelere gore score
        if cntGreaterThanOnes > 0:
            f2[j] = sumGreaterThanOnes / cntGreaterThanOnes
        # f3 = yön değiştirmelerinin maliyetleri
        fark = []
        for indv_index in range(0, len(indvs)):
            birey_2 = indvs[indv_index][1:]
            birey_1 = indvs[indv_index][0:-1] 
            for idx in range (0, len(birey_1)):
                fark.append(step_expense[birey_2[idx]][birey_1[idx]])
        f3[j] = sum(fark)
        
    # Fitness'a göre secim
    n_f1 = f1 / max_f1 
    n_f2 = f2 / max_f2
    n_f3 = f3 / max_f3
    
    w = n_f1 + n_f2 + n_f3
       
    n_w = w / sum(w) 
    n_w = 1 - n_w
    n_w = n_w / sum(n_w)
    
    # Siralamali secim
    inds = np.argsort(n_w)
    rn_w = np.zeros(inds.size, dtype=int)
    cnt = 0
    for idx in inds:
        rn_w[idx] = cnt
        cnt += 1
    rn_w = rn_w / sum(rn_w)
    best_ind = np.argmax(rn_w)
    
    # skorlar kayit altina alindi
    best_of_gen[i] = (float) (w[best_ind])
    mean_of_gen[i] = (float) (np.mean(w))
    
    if (i%plot_every == 0): # Plotting some generations
        indvs, kxy, points = [], [], []
        for idx in range (0,drone_count):
            points.append(np.zeros(((person_length+1),2), dtype=int))
            indvs.append(current_gen[idx][best_ind])
            kxy.append(start_loc.copy())        
        for idx in range (0,drone_count):
            points[idx][0] = kxy[idx]
            for k in range (0,person_length):
                kxy[idx] = [kxy[idx][0] + steps[indvs[idx][k]][0], kxy[idx][1] + steps[indvs[idx][k]][1]] # lokasyonu olustur
                points[idx][k+1] = kxy[idx]
        for idx in range (0,drone_count):
            plt.plot(points[idx][:, 0], points[idx][:, 1])
        plt.xlabel("Generation #"+str(i+1))
        plt.savefig("col_map_"+str(i+1)+".png")
        plt.show() 
        
    if (i < generation-1): # eger son gen degilse cross ve mutasyon
        chosen = random.choices(range(0,population_size), weights = rn_w, k = population_size)
        # yeni bireyleri üret % tek/cift noktali crossover
        next_gen = np.zeros((drone_count, population_size, person_length), dtype=int) # yeni bireyler
        for j in range (0,(int)(population_size/2)):
            b = []
            for idx in range (0, drone_count):
                b.append(current_gen[idx][chosen[j]])
                b.append(current_gen[idx][chosen[j+(int)(population_size/2)]])
            if cross == 1: # tek noktalı crossover
                cross_at = random.randint(1, person_length-2) # 2 - (person_length-1) arasi sayi
                for idx in range (0, drone_count):
                    next_gen[idx][j][0:cross_at] = b[2*idx][0:cross_at] 
                    next_gen[idx][j][cross_at:] = b[2*idx+1][cross_at:]
                    next_gen[idx][(int)(j+(population_size/2))][0:cross_at] = b[2*idx+1][0:cross_at]
                    next_gen[idx][(int)(j+(population_size/2))][cross_at:] = b[2*idx][cross_at:]
            else:  # =2 noktalı crossover
                cross_at = [random.randint(1, person_length-2)]
                cross_at.append(random.randint(1, person_length-2))
                cross_at.sort() # kucukten buyuge sirala
                for idx in range (0, drone_count):
                    next_gen[idx][j][0:cross_at[0]] = b[2*idx][0:cross_at[0]]
                    next_gen[idx][j][cross_at[0]:cross_at[1]] = b[2*idx+1][cross_at[0]:cross_at[1]]
                    next_gen[idx][j][cross_at[1]:] = b[2*idx][cross_at[1]:]
                    next_gen[idx][(int)(j+(population_size/2))][0:cross_at[0]] = b[2*idx+1][0:cross_at[0]]
                    next_gen[idx][(int)(j+(population_size/2))][cross_at[0]:cross_at[1]] = b[2*idx][cross_at[0]:cross_at[1]]
                    next_gen[idx][(int)(j+(population_size/2))][cross_at[1]:] = b[2*idx+1][cross_at[1]:]
                
        if copy_to_next > 0: # current_gen deki en iyi copy_to_next degeri next_gen e kopyala
            for idx in inds[copy_to_next+1:]:
                for idx2 in range (0, drone_count):
                    next_gen[idx2][idx] = current_gen[idx2][idx]
        
        # mutasyon uygula
        if mutation_rate > 0:
            for idx in range(0,population_size):
                d_ind1 = random.choices(range(0,(drone_count*person_length)-1), k = (int)(((drone_count*person_length)-1)*mutation_rate+1))
                yy = random.choices(range(1,8), k = len(d_ind1)) # nelerle degisecekleri
                for idx2 in range(0,len(d_ind1)):
                    next_gen[(int) (d_ind1[idx2] / person_length)][idx][d_ind1[idx2]%person_length] = yy[idx2]
        
        current_gen = next_gen # yeni nesil hazir
        print("\n", i+1, ". GENERATION!")
    else:
        print("\nRESULT:")
        
    # Her nesilde en iyi bireyleri yazdir
    for idx in range (0,drone_count):
        print("Best individual #", idx+1, ": ", current_gen[idx][best_ind])
              
    print("\nBest score: ", best_of_gen[i], "\nMean score: ", mean_of_gen[i])


print("\n\nCOMPLETED!\n")

#%% Grafiksel Gosterim

print("\nFor each generation, the best and the mean scores follow: ")  
plt.plot(best_of_gen, label="bests")
plt.plot(mean_of_gen, label="means")
plt.xlabel("Generations")
plt.ylabel("Score")
plt.savefig("best-mean.png")
plt.show()


indvs = []
kxy = []
points = []

mtx = []
for idx in range (0,drone_count):
    mtx.append(np.zeros((x_dim,y_dim), dtype=int))
    points.append(np.zeros(((person_length+1),2), dtype=int))
    indvs.append(current_gen[idx][best_ind])
    kxy.append(start_loc.copy())
    mtx[idx][kxy[0][0]][kxy[0][1]] = 1
    
mtx_Great = mtx[0]

for idx in range (0,drone_count):
    points[idx][0] = kxy[idx]
    for k in range (0,person_length):
        kxy[idx] = [kxy[idx][0] + steps[indvs[idx][k]][0], kxy[idx][1] + steps[indvs[idx][k]][1]] # lokasyonu olustur
        points[idx][k+1] = kxy[idx]
        mtx[idx][kxy[idx][0]][kxy[idx][1]] = k+2
    print("\nFor the drone number ", idx+1, ", map:")
    plt.plot(points[idx][:, 0], points[idx][:, 1])
    plt.show() 
    mtx_Great += mtx[idx]

for idx in range (0,drone_count):
    plt.plot(points[idx][:, 0], points[idx][:, 1])

plt.xlabel("Final Generation")   
print("\nCollective Map:\n")
plt.savefig("col_map_final.png")   
plt.show()    
print("\nAfterall!\n")
mtx_Great = mtx_Great[:][:]>0   
print(mtx_Great)  

print("\nThe best at its best at the generation #", np.argmin(best_of_gen), "with the score of ", min(best_of_gen))
print("The mean at its best at the generation #", np.argmin(mean_of_gen), "with the score of ", min(mean_of_gen))
      

#%% Detayli Gosterim

#for idx in range (0,len(best_of_gen)):
#    print(idx, ": Best: ", best_of_gen[idx], ", Mean: ", mean_of_gen[idx])
