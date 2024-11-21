#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_TEXT_LENGTH 500
#define MAX_WORD_LENGTH 50
#define NUM_SAMPLES 200
#define TRAIN_RATIO 0.8
#define DICTIONARY_SIZE 1000
#define LEARNING_RATE 0.8
#define EPOCHS 500
#define BATCH_SIZE 5
#define EPS 0.1
#define TRI 0
#define DEBUG 0
#define TYPE 0
//TYPE 0: gradientDescent, 1:stochasticGradientDescent, 2:adam

// Veri Yapıları
typedef struct {
    char text[MAX_TEXT_LENGTH];
    int label;
} TextExample;



// Fonksiyon Prototipleri
void createDataset(TextExample dataset[]);
int createDictionary(TextExample dataset[], int tri, char** dictionary,int** hotVectors,int* y, int *dictionarySize);
void createHotVectors(TextExample dataset[], int tri, char** dictionary, int dictionarySize, int** hotVectors,int* y);
void splitDataset(TextExample dataset[], int** hotVectors,int* y);
double evaluateModel(int** hotVectors,int* y,double weights[],int dictionarySize,int isTrain);
void learn(double* weights,double* diffVals,int dictionarySize);
void adamOptimization(int** hotVectors, double* weights, double* diffVals, int* y, int dictionarySize, int batchSize);
void stochasticGradientDescent(int** hotVectors, double* weights, double* diffVals, int* y, int dictionarySize, double eps, int batchSize);
void gradientDescent(int** hotVectors,double* weights,double* diffVals,int* y,int dictionarySize, double eps);
double calcLoss(int** hotVectors,int* y,double* weights,int dictionarySize);
double calcLossSingle(int* hotVectors,int y,double* weights,int dictionarySize);
double forward(int* hotVectors,double* weights,int dictionarySize);
double tanhActivation(double x);




int main() {
    int i;
    int dictionarySize = 0;
    int wordLen;

    double defVal,accuracy;

    clock_t start,end;

    TextExample dataset[NUM_SAMPLES];
    char** dictionary;
    int** hotVectors;
    int* y;

    double* weights;
    double* diffVals;

    srand(time(NULL));

//  verilerin dosyadan okunması
    createDataset(dataset);

    //bellekte sınırlar çerçevesinde yer açma
    dictionary =  (char**) malloc(DICTIONARY_SIZE * sizeof(char*));

    for (i = 0; i < DICTIONARY_SIZE; i++) {
      dictionary[i] = (char*)malloc(MAX_WORD_LENGTH*sizeof(char));
    }

    y = (int*) malloc(NUM_SAMPLES * sizeof(int));

    hotVectors = (int**)malloc(NUM_SAMPLES * sizeof(int*));

    for (i = 0; i < NUM_SAMPLES; i++) {
      hotVectors[i] =  (int*)malloc(DICTIONARY_SIZE * sizeof(int));
    }

    // sözlük oluşturma esnasında hotVektörler de oluşturulur.
    wordLen = createDictionary(dataset, TRI, dictionary,hotVectors,y, &dictionarySize);
    wordLen++;

    // maximum büyüklükteki veriye göre daraltma işlemi
    for(i=0;i<dictionarySize;i++)
      dictionary[i] = (char*)realloc(dictionary[i],wordLen*sizeof(char));

      for (i = 0; i < NUM_SAMPLES; i++) {
        hotVectors[i] =  (int*)realloc(hotVectors[i],dictionarySize * sizeof(int));
      }

    dictionary =  (char**) realloc(dictionary,dictionarySize * wordLen*sizeof(char));

    splitDataset(dataset, hotVectors,y);


    weights = (double*) malloc(dictionarySize*sizeof(double));
    diffVals = (double*) malloc(dictionarySize*sizeof(double));

    defVal = rand() % 500;
    for (i = 0; i < dictionarySize; i++) {
      weights[i] = defVal/1000;
    }



    start = clock();

    printf("Initial Loss: %f\n",calcLoss(hotVectors,y,weights,dictionarySize));

    for (i = 0; i < EPOCHS; i++) {
      end = clock();
      if(DEBUG){
      accuracy = evaluateModel(hotVectors, y, weights,dictionarySize,0);
      printf("%d %f %f %f\n",i,((double) (end - start)) / CLOCKS_PER_SEC,accuracy,calcLoss(hotVectors,y,weights,dictionarySize));
    }
      if(TYPE==0)
      gradientDescent(hotVectors,weights,diffVals,y,dictionarySize,EPS);
      else if(TYPE==1)
      stochasticGradientDescent(hotVectors,weights,diffVals,y,dictionarySize,EPS,BATCH_SIZE);
      else if(TYPE==2)
      adamOptimization(hotVectors,weights,diffVals,y,dictionarySize,BATCH_SIZE);

  }
    accuracy = evaluateModel(hotVectors, y, weights,dictionarySize,0)*100;
    printf("after %d iteration of training in %.2f seconds model reached accuracy of %%%.2f with the loss %f\n",i,((double) (end - start)) / CLOCKS_PER_SEC,accuracy,calcLoss(hotVectors,y,weights,dictionarySize));

    return 0;
}

// Bir metnin hot vektörünü parametrelerle çarpar.
// Sonucu tanh aktivasyon fonksiyonuna geçirir.
double forward(int* hotVectors,double* weights,int dictionarySize)
{
    int i;
    double sum = 0.0;
    for (i = 0; i < dictionarySize; i++) {
      sum += weights[i]*hotVectors[i];
  }
  return tanhActivation(sum);
}

//Bir metnin tahmini değeri ile gerçek değeri arasındaki farkın karesi hesaplanır.
double calcLossSingle(int* hotVectors,int y,double* weights,int dictionarySize)
{
    double res = forward(hotVectors,weights,dictionarySize);
    double d = res - y;
    return d*d;
}

// Veri setindeki tüm metinlerin kayıplarının ortalaması hesaplanır.
double calcLoss(int** hotVectors,int* y,double* weights,int dictionarySize)
{
    int i;
    double c = 0;
    for (i = 0; i < NUM_SAMPLES * TRAIN_RATIO; ++i) {
        c += calcLossSingle(hotVectors[i],y[i],weights,dictionarySize);

    }
    return c/(NUM_SAMPLES*TRAIN_RATIO);
}

// Her parametre için gradyan hesaplanır.ve diffVals arrayine kaydedilir.
// learn fonksiyonu parametreleri bu veriler doğrultusunda günceller.
void gradientDescent(int** hotVectors,double* weights,double* diffVals,int* y,int dictionarySize, double eps)
{
    int i;
    double saved,lossMinus=0.0,lossPlus=0.0;

    for (i = 0; i < dictionarySize; ++i) {
        saved = weights[i];
        weights[i] -= eps;
        lossMinus = calcLoss(hotVectors,y,weights,dictionarySize);
        weights[i] = saved + eps;
        lossPlus =calcLoss(hotVectors,y,weights,dictionarySize);
        diffVals[i] = (lossPlus - lossMinus)/(2*eps);//yaklaşık türev hesaplaması
        weights[i] = saved;
    }

    learn(weights,diffVals,dictionarySize);
}
//Gradient Descentin aksine tüm veri setini değil random olarak belirtilen BATCH_SIZE kadar eleman seçerek gradyan hesaplar.
void stochasticGradientDescent(int** hotVectors, double* weights, double* diffVals, int* y, int dictionarySize, double eps, int batchSize)
{
    double saved,lossMinus=0.0,lossPlus=0.0;
    int i,j,randIndex;
    for (i = 0; i < batchSize; ++i) {
        randIndex = rand() % (int)(NUM_SAMPLES*TRAIN_RATIO);
        for (j = 0; j < dictionarySize; ++j) {
            saved = weights[j];
            weights[j] -= eps;
            lossMinus = calcLossSingle(hotVectors[randIndex], y[randIndex], weights, dictionarySize);
            weights[j] = saved + eps;
            lossPlus = calcLossSingle(hotVectors[randIndex], y[randIndex], weights, dictionarySize);
            diffVals[j] = (lossPlus - lossMinus) / (2* eps); //yaklaşık türev hesaplaması
            weights[j] = saved;

        }
        learn(weights,diffVals,dictionarySize);

    }

}
// Birinci ve ikinci moment tahminleri hesaplanır.
// parametreler moment tahminlerine göre güncellenir.
void adamOptimization(int** hotVectors, double* weights, double* diffVals, int* y, int dictionarySize,int batchSize)
{
    double* m = (double*)calloc(dictionarySize, sizeof(double));
    double* v = (double*)calloc(dictionarySize, sizeof(double));
    double saved,lossMinus,mHat,vHat;
    double beta1= 0.9;
    double beta2 = 0.999;
    double epsilon = 1e-8;

    int i,j,randIndex;

    for (i = 0; i < batchSize; ++i) {
      randIndex = rand() % (int)(NUM_SAMPLES*TRAIN_RATIO);

        for (j = 0; j < dictionarySize; ++j) {

            saved = weights[j];
            weights[j] -= epsilon;
            lossMinus = calcLossSingle(hotVectors[randIndex], y[randIndex], weights, dictionarySize);
            weights[j] = saved + epsilon;
            diffVals[j] = (calcLossSingle(hotVectors[randIndex], y[randIndex], weights, dictionarySize) - lossMinus) / (2 * epsilon);
            weights[j] = saved;

            m[j] = beta1 * m[j] + (1.0 - beta1) * diffVals[j];
            v[j] = beta2 * v[j] + (1.0 - beta2) * diffVals[j] * diffVals[j];

            mHat = m[j] / (1.0 - pow(beta1, i+1));
            vHat = v[j] / (1.0 - pow(beta2, i+1));

            diffVals[j] = mHat / (sqrt(vHat) + epsilon);
        }
        learn(weights,diffVals,dictionarySize);

    }
}

// parametreler öğrenme oranı ile çarpılan gradyan yönünde güncellenir.
void learn(double* weights,double* diffVals,int dictionarySize)
{
    int i;
    for (i = 0; i < dictionarySize; ++i) {
            weights[i] -= LEARNING_RATE * diffVals[i];
    }
}

void createDataset(TextExample dataset[]) {
    FILE *fileA = fopen("A.txt", "r");
    FILE *fileB = fopen("B.txt", "r");

    int i = 0;

    if (fileA == NULL || fileB == NULL) {
        perror("Dosya açma hatası");
        exit(EXIT_FAILURE);
    }


    // A dosyasındaki cümleleri oku ve etiketi 1 olarak ata
    while (i < NUM_SAMPLES / 2 && fgets(dataset[i].text, MAX_TEXT_LENGTH, fileA) != NULL) {
        dataset[i].text[strcspn(dataset[i].text, "\n")] = '\0'; // Satır sonu karakterini kaldır
        dataset[i].label = 1;
        i++;
    }

    // B dosyasındaki cümleleri oku ve etiketi -1 olarak ata
    while (i < NUM_SAMPLES && fgets(dataset[i].text, MAX_TEXT_LENGTH, fileB) != NULL) {
        dataset[i].text[strcspn(dataset[i].text, "\n")] = '\0'; // Satır sonu karakterini kaldır
        dataset[i].label = -1;
        i++;
    }


    fclose(fileA);
    fclose(fileB);
}

// Veri setindeki her metin için tahmini değer hesaplanır.
// Tahmini değer ile gerçek değer karşılaştırılır.
// Doğru tahmin edilen metinlerin oranı hesaplanır.
// isTrain 1 ise training accuracy, 0 ise test accuracy hesaplanır.
double evaluateModel(int** hotVectors, int* y,double weights[],int dictionarySize,int isTrain) {
    int correctPredictions = 0;
    int i,predictedLabel;
    double output,accuracy;
    int size = isTrain ? NUM_SAMPLES * TRAIN_RATIO : NUM_SAMPLES * (1-TRAIN_RATIO);
    int threshold = isTrain ? 0: NUM_SAMPLES*TRAIN_RATIO;
    for (i = 0; i < size; i++) {
        output = forward(hotVectors[threshold+i],weights,dictionarySize);


        predictedLabel = (output >= 0) ? 1 : -1;
        if (predictedLabel == y[threshold+i]) {
            correctPredictions++;

        }
    }
    accuracy = (double)correctPredictions / size;
    return accuracy;
}

// sözlük oluşturma esnasında hotVektörler de oluşturulur. eğer tri değeri bir ise her kelimenin ilk 3 harfini token olarak kullanır.
// sözlük içerisindeki en uzun kelimenin uzunluğunu döndürür.
int createDictionary(TextExample dataset[], int tri, char** dictionary,int** hotVectors,int* y,int *dictionarySize) {
    int i,j;
    int wordExists;
    char text[MAX_TEXT_LENGTH];
    char *token;
    int len;
    int longest = 0;

    for (i = 0; i < NUM_SAMPLES; i++) {

      for (j = 0; j < DICTIONARY_SIZE; j++) {

                  hotVectors[i][j] = 0;
              }

      y[i] = dataset[i].label;
      strcpy(text, dataset[i].text);
      token = strtok(text, " ");
      while (token != NULL) {
          len = strlen(token);

          if(len>longest)
            longest=len;

          if((tri && len >= 3)||tri ==0){

          if(tri){
            token[3] = '\0';
          }
          wordExists = 0;
          for (j = 0; j < *dictionarySize; j++) {
              if (strcmp(dictionary[j], token) == 0) {
                  wordExists = 1;
                  hotVectors[i][j] = 1;
                  j = *dictionarySize;
              }
          }
          if (!wordExists) {
              strcpy(dictionary[*dictionarySize], token);
              hotVectors[i][j] = 1;

              (*dictionarySize)++;
          }
        }
          token = strtok(NULL, " ");
      }
      // printf("%d asdsad\n",i);

    }
    return tri ? 3 : longest;
}

//  dataset, hotVektörler ve labellar A ve B sınıfı ayrı ayrı olmak üzere karıştırılır.
//  ardından belirenen training sayısı kadar eleman iki sınıftanda eşit sayıda seçilerek bias oluşturması engellenmeye çalışılır.

void splitDataset(TextExample dataset[],int** hotVectors,int* y) {
    int i,j,randomIndex;
    int halfOfSamples = NUM_SAMPLES/2;
    int numTrain = (int)(halfOfSamples * TRAIN_RATIO);
    int numTest = halfOfSamples - numTrain;
    TextExample temp;
    int* tempVector;
    int tempY;
    // Veri setini karıştır
    for(j=0;j<2;j++){
    for (i = 0; i < halfOfSamples; i++) {
        randomIndex = rand() % halfOfSamples;
        temp = dataset[halfOfSamples*j+i];
        dataset[halfOfSamples*j+i] = dataset[randomIndex];
        dataset[randomIndex] = temp;
        tempVector = hotVectors[halfOfSamples*j+i];
        hotVectors[halfOfSamples*j+i] = hotVectors[randomIndex];
        hotVectors[randomIndex] = tempVector;
        tempY = y[halfOfSamples*j+i];
        y[halfOfSamples*j+i] = y[randomIndex];
        y[randomIndex] = tempY;
    }
}
    halfOfSamples *= TRAIN_RATIO;
    for (i = 0; i < 20; ++i) {
   tempVector = hotVectors[halfOfSamples+i];
   hotVectors[halfOfSamples+i] = hotVectors[halfOfSamples*2+i];
   hotVectors[halfOfSamples*2+i] = tempVector;
   tempY = y[halfOfSamples+i];
   y[halfOfSamples+i] = y[halfOfSamples*2+i];
   y[halfOfSamples*2+i] = tempY;
}

}
//değerleri -1,1 aralığında tutarak aşırı dalgalanmayı önler
double tanhActivation(double x) {
    return tanh(x);
}
