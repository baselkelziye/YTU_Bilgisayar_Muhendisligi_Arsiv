#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

//  #define _CRTDBG_MAP_ALLOC //Memoryleak test etmek icindir. Memory Leak bulunmamaktadır.
//  #include <crtdbg.h>

#define PI 3.14159265358979323846
#define EPS 0.000000001
#define ETA 0.01
#define GRAD_CLIP 100
#define WEIGHT_CLIP 100 
#define STOP_ERROR 0.01


typedef struct {
    double** inputVals;
    double** targetVals;
    int rowCount;
    int colCount;
    int numOfClasses;
}Data;

typedef struct
{
    double* weights; // Neurons Connections
    double* delta_weights; // difference in weights
    double* firstMoment; // v for ADAM
    double* secondMoment; // m for ADAM
    double output_val; // Calculated Value that will be multiplied with weights
    double gradient;

    int weightCount;
    int m_myIndex;
} Neuron;

typedef struct
{
    int neuronNum;
    Neuron** neurons; // Pointer to array of neuron pointers

} Layer;

typedef struct
{
    int* topology;
    int layerNum;
    Layer** layers;
}Net;

//------------------- Neuron Codes -------------------

Neuron* newNuron(int weightCount, int myIndex);

void freeNuron(Neuron* neuron);

void feedForwardNeuron(Neuron* neuron, Layer* prevLayer);

void updateWeightsNeuron(Neuron* neuron, Layer* nextLayer, double learningRate, int batchSize);

void updateWeightsNeuronADAM(Neuron* neuron, Layer* nextLayer, double learningRate, int batchSize, double beta1, double beta2);

// ------------------- Layer Codes -------------------

Layer* newLayer(int neuronNum, int nextNeuronNum);

void freeLayer(Layer* layer);

void feedForwardLayer(Layer* prevLayer, Layer* currLayer);

// ------------------- Net Codes -------------------

Net* newNet(int* topology, int layerNum);

void freeNet(Net* net);

void feedForwardNet(Net* net, double* inputVals, int inputSize);

void updateWeightsNet(Net* net, double learningRate, int batchSize);

void updateWeightsNetADAM(Net* net, double learningRate, int batchSize, double beta1, double beta2);

// ------------------- Calculatinons -------------------
double getRandom();

double activation(double x);

double derivActivation(double x);

double calculateErr(Net* net, double* targetVals);

void   softmaxNet(Net* net);

void   resetDeltaWeights(Net* net);

void   printNumber(double* values, int lenght);
  
void   testSample(Net* net, Data* data, int testIdx);

void   testResults(Net* net, Data* data, int splitIdx, int* correct, int* wrong);

void shuffleArray(int* array, int size);

int *generateRandomElements(int start, int end);

// ------------------- Net Calculatinons -------------------
double sumDOW(Neuron* neuron, Layer* nextLayer);

void   calculateHiddenGrad(Layer* currentLayer, Layer* nextLayer);

void   calculateOutputGrad(double* targetVals, Layer* outputLayer);

void   backPropagation(Net* net, double* targetVals, int targetSize);


// ------------------- Save-Read Neural Net -------------------

void getNetProperties(Net** net, Data* data);

void saveNet(Net* net, FILE* fp);

Net* readNet(FILE* fp);

void printNet(Net* net);

// ------------------- Save-Read Data -------------------

void readData(FILE* fp, Data* data);

void printData(Data* data);

void freeData(Data* data);

// ------------------- Optimizers -------------------

void trainGD(Net* net, Data* data, int epoch, double learningRate);

void trainSGD(Net* net, Data* data, int epoch, int batchSize, double learningRate);

void trainADAM(Net* net, Data* data, int epoch, int batchSize, double learningRate);

