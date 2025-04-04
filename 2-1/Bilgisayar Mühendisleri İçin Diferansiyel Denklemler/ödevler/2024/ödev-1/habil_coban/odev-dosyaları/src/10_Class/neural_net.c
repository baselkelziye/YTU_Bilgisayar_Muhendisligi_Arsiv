#include "neural_net.h"

//------------------- Neuron Codes -------------------

Neuron* newNuron(int weightCount, int myIndex) {
    int i;
    Neuron* neuron = (Neuron*)malloc(sizeof(Neuron));

    neuron->output_val = 0.0f; // default value
    neuron->gradient = 0.0f; // default value
    neuron->m_myIndex = myIndex;
    neuron->weightCount = weightCount;
    neuron->weights = NULL; // null for output layer

    if (weightCount != 0) {
        neuron->weights = (double*)malloc(sizeof(double) * weightCount);
        neuron->delta_weights = (double*)malloc(sizeof(double) * weightCount);
        neuron->firstMoment = (double*)malloc(sizeof(double) * weightCount);
        neuron->secondMoment = (double*)malloc(sizeof(double) * weightCount);
        for (i = 0; i < weightCount; i++)
        {
            neuron->weights[i] = getRandom();
            neuron->firstMoment[i] = 0;
            neuron->secondMoment[i] = 0;
            neuron->delta_weights[i] = 0;
        }
    }
    return neuron;
}

void freeNuron(Neuron* neuron) {
    if (neuron) {
        if (neuron->weightCount != 0) {
            free(neuron->weights);
            free(neuron->delta_weights);
            free(neuron->firstMoment);
            free(neuron->secondMoment);
        }
        neuron->weights = NULL;
        neuron->delta_weights = NULL;
        neuron->firstMoment = NULL;
        neuron->secondMoment = NULL;
        free(neuron);
        neuron = NULL;
    }
}

void feedForwardNeuron(Neuron* neuron, Layer* prevLayer) {
    int i;
    double sum = 0;
    for (i = 0; i < prevLayer->neuronNum; i++)
    {
        sum += prevLayer->neurons[i]->weights[neuron->m_myIndex] *
            prevLayer->neurons[i]->output_val;
    }
    neuron->output_val = activation(sum);
}

void updateWeightsNeuron(Neuron* neuron, Layer* nextLayer, double learningRate, int batchSize) {
    int i;
    for (i = 0; i < nextLayer->neuronNum-1; i++)
    {
        Neuron* nextNeuron = nextLayer->neurons[i];
        double avgDelta = neuron->delta_weights[nextNeuron->m_myIndex] / batchSize;
        //Gradient clipping
        if (avgDelta > GRAD_CLIP) avgDelta = GRAD_CLIP;
        if (avgDelta < -GRAD_CLIP) avgDelta = -GRAD_CLIP;
        //Update weight
        neuron->weights[nextNeuron->m_myIndex] -= learningRate * avgDelta;
    }
}

void updateWeightsNeuronADAM(Neuron* neuron, Layer* nextLayer, double learningRate, int batchSize, double beta1, double beta2) {
    int i;
    double firstM, secondM;
    for (i = 0; i < nextLayer->neuronNum-1; i++)
    {
        Neuron* nextNeuron = nextLayer->neurons[i];
        double avgDelta = neuron->delta_weights[nextNeuron->m_myIndex] / batchSize;
        //Gradient clipping
        if (avgDelta > GRAD_CLIP) avgDelta = GRAD_CLIP;
        if (avgDelta < -GRAD_CLIP) avgDelta = -GRAD_CLIP;
        //Update weight
        firstM = neuron->firstMoment[nextNeuron->m_myIndex] * beta1 + (1 - beta1) * avgDelta;
        secondM = neuron->secondMoment[nextNeuron->m_myIndex] * beta2 + (1 - beta2) * (avgDelta * avgDelta);
        neuron->weights[nextNeuron->m_myIndex] -= learningRate * (firstM / (sqrt(secondM) + EPS));
    }
}

// ------------------- Layer Codes -------------------

Layer* newLayer(int neuronNum, int nextNeuronNum) {

    neuronNum = neuronNum + 1; // neuronNum+1 because we add bias as a neuron

    Layer* layer = (Layer*)malloc(sizeof(Layer));
    layer->neurons = (Neuron**)malloc(sizeof(Neuron*) * neuronNum);
    layer->neuronNum = neuronNum;

    int i;
    if (neuronNum > 0) {
        for (i = 0; i < neuronNum; i++)
        {
            layer->neurons[i] = newNuron(nextNeuronNum, i);
            if (!layer->neurons[i]) {
                printf("Memory allocation failed for Neuron %d\n", i);
                // Free previously allocated neurons and the layer
                for (int j = 0; j < i; j++) {
                    freeNuron(layer->neurons[j]);
                }
                free(layer->neurons);
                free(layer);
                return NULL;
            }
        }
    }

    //Set 1 to bias value. It will be ajdusted via weight
    layer->neurons[neuronNum - 1]->output_val = 1.0f;

    return layer;
}

void freeLayer(Layer* layer) {

    if (layer) {
        for (int i = 0; i < layer->neuronNum; i++)
        {
            freeNuron(layer->neurons[i]);
        }
        free(layer->neurons);
        free(layer);
    }
}

void feedForwardLayer(Layer* prevLayer, Layer* currLayer) {
    int i;
    for (i = 0; i < currLayer->neuronNum - 1; i++)
    {
        feedForwardNeuron(currLayer->neurons[i], prevLayer);
    }
}

// ------------------- Net Codes -------------------

Net* newNet(int* topology, int layerNum) {

    int i;
    Net* net = (Net*)malloc(sizeof(Net));
    net->topology = topology;
    net->layerNum = layerNum;
    net->layers = (Layer**)malloc(sizeof(Layer*) * layerNum);

    //First input layer
    net->layers[0] = newLayer(net->topology[0], net->topology[1]);
    //Hidden layers
    for (i = 1; i < layerNum - 1; i++)
    {
        net->layers[i] = newLayer(net->topology[i], net->topology[i + 1]);
    }
    //Output layer
    net->layers[layerNum - 1] = newLayer(net->topology[layerNum - 1], 0);

    return net;
}

void freeNet(Net* net) {
    int i;
    if (net) {
        for (i = 0; i < net->layerNum; i++)
        {
            freeLayer(net->layers[i]);
        }
        free(net->layers);
        free(net->topology);
        free(net);
    }
}

void feedForwardNet(Net* net, double* inputVals, int inputSize) {

    int i;

    if (net->topology[0] != inputSize) {
        printf("Couldnt Feed Forward !! \n Input Size DON'T match.\n");
        return;
    }
    //Set first layers value with input
    for (i = 0; i < net->layers[0]->neuronNum - 1; i++) {
        net->layers[0]->neurons[i]->output_val = inputVals[i];
    }
    //Feed layers
    for (i = 1; i < net->layerNum; i++) {
        feedForwardLayer(net->layers[i - 1], net->layers[i]);
    }
}

void updateWeightsNet(Net* net, double learningRate, int batchSize) {

    int layerNum;
    int n;
    // Go backwards while updating
    for (layerNum = 0; layerNum < net->layerNum - 1; ++layerNum)
    {
        for (n = 0; n < net->layers[layerNum]->neuronNum ; n++)
        {
            updateWeightsNeuron(net->layers[layerNum]->neurons[n], net->layers[layerNum + 1], learningRate, batchSize);
        }
    }
    resetDeltaWeights(net);
}

void updateWeightsNetADAM(Net* net, double learningRate, int batchSize, double beta1, double beta2) {

    int layerNum;
    int n;
    // Go backwards while updating
    for (layerNum = 0; layerNum < net->layerNum - 1; ++layerNum)
    {
        for (n = 0; n < net->layers[layerNum]->neuronNum; n++)
        {
            updateWeightsNeuronADAM(net->layers[layerNum]->neurons[n], net->layers[layerNum + 1], learningRate, batchSize, beta1, beta2);
        }
    }
    resetDeltaWeights(net);
}

// ------------------- Calculatinons -------------------

void resetDeltaWeights(Net* net) {
    int i, j, k;

    for (i = 0; i < net->layerNum - 1; i++)
    {
        for (j = 0; j < net->layers[i]->neuronNum; j++)
        {
            // Reset delta_weights and clip weights if necessary
            Neuron* neuron = net->layers[i]->neurons[j];
            for (k = 0; k < net->layers[i+1]->neuronNum - 1; k++)
            {
                neuron->delta_weights[k] = 0;

                if (neuron->weights[k] > WEIGHT_CLIP) neuron->weights[k] = WEIGHT_CLIP;
                if (neuron->weights[k] < -WEIGHT_CLIP) neuron->weights[k] = -WEIGHT_CLIP;
            }
        }
    }
}

double sumDOW(Neuron* neuron, Layer* nextLayer) { // sum of Derivative Of Weigths
    int i;
    double sum = 0;
    for (i = 0; i < nextLayer->neuronNum - 1; i++)
    {
        sum += neuron->weights[i] * nextLayer->neurons[i]->gradient;
        neuron->delta_weights[i] += neuron->output_val * nextLayer->neurons[i]->gradient; // Required bc GradientDescent
    }
    return sum;
}

void calculateHiddenGrad(Layer* currentLayer, Layer* nextLayer) {
    int n;
    for (int n = 0; n < currentLayer->neuronNum - 1; ++n) {
        Neuron* currentNeuron = currentLayer->neurons[n];

        // Compute gradient based on next layer's gradients
        double dow = sumDOW(currentNeuron, nextLayer);
        currentNeuron->gradient = dow * derivActivation(currentNeuron->output_val);
    }
}

void calculateOutputGrad(double* targetVals, Layer* outputLayer) {
    for (int i = 0; i < outputLayer->neuronNum - 1; i++) {
        double output = outputLayer->neurons[i]->output_val;
        double target = targetVals[i];
        outputLayer->neurons[i]->gradient = output - target;
        // double gradient = (output - target ) * derivActivation(output); // for tanh
    }
}

void softmaxNet(Net* net) {
    int i;
    Layer* outputLayer = net->layers[net->layerNum - 1];
    double expSum = 0.0;
    double maxVal = -INFINITY;
    // Find max val
    for (i = 0; i < outputLayer->neuronNum - 1; i++) {
        if (outputLayer->neurons[i]->output_val > maxVal) {
            maxVal = outputLayer->neurons[i]->output_val;
        }
    }
    // Normalized softmax
    for (i = 0; i < outputLayer->neuronNum - 1; i++) {
        expSum += exp(outputLayer->neurons[i]->output_val - maxVal);
    }
    for (i = 0; i < outputLayer->neuronNum - 1; i++) {
        double softmaxVal = exp(outputLayer->neurons[i]->output_val - maxVal) / expSum;
        outputLayer->neurons[i]->output_val = softmaxVal;
    }
}
double calculateErr(Net* net, double* targetVals) {
    int i;
    Layer* outputLayer = net->layers[net->layerNum - 1];
    double crossEntropyLoss = 0.0;
    for (i = 0; i < outputLayer->neuronNum - 1; i++) {
        double softmaxVal = outputLayer->neurons[i]->output_val ;
        // Cross-Entropy Loss
        if (targetVals[i] > 0) {
            crossEntropyLoss -= targetVals[i] * log(fmax(softmaxVal, 1e-15));
        }
    }
    return crossEntropyLoss;
}

void backPropagation(Net* net, double* targetVals, int targetSize) {
    Layer* outputLayer = net->layers[net->layerNum - 1];

    // Validate output size
    if (outputLayer->neuronNum - 1 != targetSize) {
        printf("\nOutput Size Didn't Match Target Size!!!\n");
        return;
    }

    // softmaxNet(net, targetVals);
    calculateOutputGrad(targetVals, outputLayer);

    // Backpropagate gradients through hidden layers
    for (int layerNum = net->layerNum - 2; layerNum >= 0; --layerNum) {
        Layer* currentLayer = net->layers[layerNum];
        Layer* nextLayer = net->layers[layerNum + 1];

        calculateHiddenGrad(currentLayer, nextLayer);
    }
}



void testResults(Net* net, Data* data, int splitIdx, int* correct, int* wrong) {
    int i, j, target, ansIdx;
    Layer* outputLayer = net->layers[net->layerNum - 1];
    *wrong = 0;
    *correct = 0;

    for (i = 0; i < splitIdx; i++)
    {
        feedForwardNet(net, data->inputVals[i], data->colCount);
        target = 0;
        ansIdx = 0;
        //Find target val
        for (j = 0; j < data->numOfClasses; j++) {
            if (data->targetVals[i][j] == 1) { target = j; }
        }
        //Find which answer is most likely
        for (j = 1; j < data->numOfClasses; j++) {
            if (outputLayer->neurons[j]->output_val > outputLayer->neurons[ansIdx]->output_val) {
                ansIdx = j;
            }
        }
        if (target == ansIdx) {
            *correct = *correct + 1;
        }
        else {
            *wrong = *wrong + 1;
        }
    }
}
void testSample(Net* net, Data* data, int testIdx) {
    int i, target, ans;
    Layer* outputLayer = net->layers[net->layerNum - 1];

    feedForwardNet(net, data->inputVals[testIdx], data->colCount);
    softmaxNet(net);

    target = 0;
    ans = 0;

    //Find target val
    for (i = 0; i < data->numOfClasses; i++) {
        if (data->targetVals[testIdx][i] == 1) { target = i; }
    }
    printf("---------------\n");
    printf("Target was :%d\n", target);

    //Find which answer is most likely
    for (i = 0; i < data->numOfClasses; i++) {
        printf("Probablity of %d : %.3lf\n", i, outputLayer->neurons[i]->output_val);
    }
    printf("---------------\n");
    
}


void printNumber(double* values, int lenght) {
    int i, j, K;
    char tmp;
    int n = sqrt(lenght);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            K = values[i * 28 + j] * 11;
            tmp = ".,-~:;=!*#$@"[K > 0 ? K : 0];
            printf("%c ", tmp);
        }
        printf("\n");
    }
    printf("\n");
}

void shuffleArray(int* array, int size) {
    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}
int* generateRandomElements(int start, int end) {
    int rangeSize = end - start + 1;
    int* result = (int*)malloc(rangeSize * sizeof(int));
    
    // Fill array with sequential numbers
    for (int i = 0; i < rangeSize; i++) {
        result[i] = start + i;
    }

    // Shuffle the array
    shuffleArray(result, rangeSize);
    return result;
}
double getRandom() {
    double result;
    double u = ((double)rand() / RAND_MAX);
    double v = ((double)rand() / RAND_MAX);
    result = sqrt(-2.0f * log(u)) * cos(2.0f * PI * v);

    return fmax(-0.10f, fmin(0.10f, result));
}

// ------------------- Save-Read Neural Net -------------------

void getNetProperties(Net** net, Data* data) {
    int layerNum = 0;
    printf("Enter the number of hidden layers: ");
    scanf_s("%d", &layerNum);
    layerNum += 2; // Add input and output layers

    int* topology = (int*)malloc(sizeof(int) * layerNum);
    if (topology == NULL) {
        printf("Memory allocation failed for topology\n");
        return;
    }

    if(layerNum>2){
        printf("Enter the number of neurons for the hidden layers:\n");
        for (int i = 1; i < layerNum - 1; i++) {
            scanf_s("%d", &topology[i]);
        }
    }

    // Set input and output layer sizes
    topology[0] = data->colCount;
    topology[layerNum - 1] = data->numOfClasses;

    *net = newNet(topology, layerNum);
}

void saveNet(Net* net, FILE* fp) {

    int i, j, k;
    //Write layer num
    fprintf(fp, "%d\n", net->layerNum);
    //Write topology
    for (i = 0; i < net->layerNum; i++)
    {
        fprintf(fp, "%d ", net->topology[i]);
    }
    fprintf(fp, "\n");
    //Write weigths
    for (i = 0; i < net->layerNum - 1; i++)
    {
        for (j = 0; j < net->layers[i]->neuronNum; j++)
        {
            for (k = 0; k < net->layers[i]->neurons[j]->weightCount; k++)
            {
                fprintf(fp, "%f ", net->layers[i]->neurons[j]->weights[k]);
            }
            fprintf(fp, "\n");
        }
        fprintf(fp, "\n");
    }
}

Net* readNet(FILE* fp) {

    int i, j, k;

    //Read Layer num
    int layerNum;
    fscanf_s(fp, "%d\n", &layerNum);

    //Read topology
    int* topology;
    topology = (int*)malloc(sizeof(int) * layerNum);
    for (i = 0; i < layerNum; i++)
    {
        fscanf_s(fp, "%d ", &topology[i]);
    }
    fscanf_s(fp, "\n");

    //Create net
    Net* net = newNet(topology, layerNum);

    //Read weights from file
    for (i = 0; i < net->layerNum - 1; i++)
    {
        for (j = 0; j < net->layers[i]->neuronNum; j++)
        {
            for (k = 0; k < net->layers[i]->neurons[j]->weightCount; k++)
            {
                fscanf_s(fp, "%lf ", &net->layers[i]->neurons[j]->weights[k]);
            }
            fscanf_s(fp, "\n");
        }
        fscanf_s(fp, "\n");
    }

    return net;
}

void printNet(Net* net) { // To be able see weights

    int i, j, k;
    for (i = 0; i < net->layerNum - 1; i++)
    {
        for (j = 0; j < net->layers[i]->neuronNum; j++)
        {
            for (k = 0; k < net->layers[i]->neurons[j]->weightCount; k++)
            {
                printf("%lf ", net->layers[i]->neurons[j]->weights[k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

// ------------------- Save-Read Data -------------------

void readData(FILE* fp, Data* data) {
    int i, j, targetIndex;

    // Read rowCount, colCount, and numOfClasses from the file
    fscanf(fp, "%d ", &data->rowCount);
    fscanf(fp, "%d ", &data->colCount);
    fscanf(fp, "%d \n", &data->numOfClasses);

    printf("Rows: %d, Columns: %d, Classes: %d\n", data->rowCount, data->colCount, data->numOfClasses);
    printf("Reading Data ...\n");

    // Allocate memory for inputVals and tagertVals
    data->inputVals = (double**)malloc(sizeof(double*) * (data->rowCount));
    data->targetVals = (double**)malloc(sizeof(double*) * (data->rowCount));
    for (i = 0; i < (data->rowCount); i++) {
        data->inputVals[i] = (double*)malloc(sizeof(double) * (data->colCount));
        data->targetVals[i] = (double*)malloc(sizeof(double) * (data->numOfClasses));
        for (j = 0; j < (data->numOfClasses); j++) {
            data->targetVals[i][j] = 0;  // Initialize target values to -1
        }
    }

    // Read data and target values from the file
    for (i = 0; i < (data->rowCount); i++) {

        fscanf(fp, "%d ", &targetIndex); // Read target index
        if (targetIndex >= 0 && targetIndex < data->numOfClasses) {
            data->targetVals[i][targetIndex] = 1; // Set target value to 1 for the correct class
        }

        // Read the input values
        for (j = 0; j < (data->colCount); j++) {
            fscanf(fp, "%lf ", &data->inputVals[i][j]);
        }
        fscanf(fp, "\n");
    }
}

void printData(Data* data) { // To be able to see data

    int i, j, k;
    //Read Layer num

    printf("%d ", data->rowCount);
    printf("%d ", data->colCount);
    printf("%d ", data->numOfClasses);

    printf("\n");


    for (i = 0; i < data->rowCount; i++)
    {
        for (j = 0; j < data->numOfClasses; j++){
            if (data->targetVals[i][j] != 0) {
                printf("%d ", j);
            }
        }

        for (j = 0; j < data->colCount; j++){
            printf("%.0f ", data->inputVals[i][j]);
        }
        printf("\n");
    }

}

void freeData(Data* data) {
    int i;

    // Free inputVals
    for (i = 0; i < data->rowCount; i++) {
        free(data->inputVals[i]);
    }
    free(data->inputVals);

    // Free targetVals
    for (i = 0; i < data->rowCount; i++) {
        free(data->targetVals[i]);
    }
    free(data->targetVals);
}

// ------------------- Optimizers -------------------

void trainGD(Net* net, Data* data, int epoch, double learningRate) {

    int epochIdx, dataIdx, batchSize, i;
    int dataCount = data->rowCount;
    int splitIdx = (2 * dataCount) / 10; // 80-20 ratio. First 20 percent is for testing the model 
    batchSize = dataCount - splitIdx;
    double loss = 0;
    double valError = 1; // Must be greater than stop_error 


    //Train
    epochIdx = 0;
    while (epochIdx < epoch && valError > STOP_ERROR)
    {
        epochIdx++;
        valError = 0;
        loss = 0;

        for (dataIdx = splitIdx; dataIdx < dataCount; dataIdx++)
        {
            feedForwardNet(net, data->inputVals[dataIdx], data->colCount);
            softmaxNet(net);
            backPropagation(net, data->targetVals[dataIdx], data->numOfClasses);
            loss += calculateErr(net, data->targetVals[dataIdx]);
        }

        updateWeightsNet(net, learningRate, batchSize);

        //Validation Error calculation
        for (dataIdx = 0; dataIdx < splitIdx; dataIdx++)
        {
            feedForwardNet(net, data->inputVals[dataIdx], data->colCount);
            softmaxNet(net);
            valError += calculateErr(net, data->targetVals[dataIdx]);
        }
        loss = loss / batchSize;
        valError = valError / splitIdx;
        printf("Loss :%lf ,", loss);
        printf(" Validation Error:%lf\n", valError);

    }

    //Test how many correct answers (test data is from 0 - splitIdx )
    int correct, wrong;
    testResults(net, data, splitIdx, &correct, &wrong);

    double accuracy = 100.0 * (correct) / (correct + wrong);
    printf("---- Test Results ---- \nWrong    :%d\nCorrect  :%d\nAccuracy :%.3lf\n", wrong, correct, accuracy);

}

void trainSGD(Net* net, Data* data, int epoch, int batchSize, double learningRate) {

    int epochIdx, dataIdx, shuffledIdx, trainSize;
    int dataCount = data->rowCount;
    int splitIdx = (2 * dataCount) / 10; // 80-20 ratio. First 20 percent is for testing
    trainSize = dataCount - splitIdx;
    double loss = 0;
    double valError = 1;

    if (batchSize >= trainSize || batchSize == 0) {
        printf("Batch size is cant be equal to or greater than train size");
        return;
    }


    // Train
    for (epochIdx = 0; epochIdx < epoch; epochIdx++) {
        // Generate shuffled indices for this epoch
        int* indices = generateRandomElements(splitIdx, dataCount - 1);
        
        // Calculate number of complete batches
        int numBatches = trainSize / batchSize;
        
        // Process each batch
        for (int batchIdx = 0; batchIdx < numBatches; batchIdx++) {
            loss = 0;
            valError = 0;
            
            // Process each sample in the batch
            for (dataIdx = 0; dataIdx < batchSize; dataIdx++) {
                // Calculate the index into our shuffled indices array
                int sampleIdx = batchIdx * batchSize + dataIdx;
                if (sampleIdx < trainSize) {  // Safety check
                    shuffledIdx = indices[sampleIdx];
                    
                    // Train on this sample
                    feedForwardNet(net, data->inputVals[shuffledIdx], data->colCount);
                    softmaxNet(net);
                    backPropagation(net, data->targetVals[shuffledIdx], data->numOfClasses);
                }
            }
            
            // Update weights after processing the batch
            updateWeightsNet(net, learningRate, batchSize);
        }
        
        // Calculate and print accuracy for this epoch
        int correct, wrong;
        testResults(net, data, splitIdx, &correct, &wrong);
        double accuracy = 100.0 * correct / (correct + wrong);
        printf("Epoch %d, accuracy: %.3lf%%\n", epochIdx + 1, accuracy);
        
        // Clean up the indices array for this epoch
        free(indices);
    }

    //Test how many correct answers (test data is from 0 - splitIdx )
    int correct, wrong;
    testResults(net, data, splitIdx, &correct, &wrong);

    double accuracy = 100.0 * (correct) / (correct + wrong);
    printf("---- Test Results ---- \nWrong    :%d\nCorrect  :%d\nAccuracy :%.3lf\n", wrong, correct, accuracy);

}
void trainADAM(Net* net, Data* data, int epoch, int batchSize, double learningRate) {
    int epochIdx, dataIdx, shuffledIdx, trainSize;
    int dataCount = data->rowCount;
    int splitIdx = (2 * dataCount) / 10; // 80-20 ratio. First 20 percent is for testing
    trainSize = dataCount - splitIdx;
    double loss = 0;
    double valError = 1;

    if (batchSize >= trainSize || batchSize == 0) {
        printf("Batch size can't be equal to or greater than train size\n");
        return;
    }

    clock_t start = clock();
    
    // Train
    for (epochIdx = 0; epochIdx < epoch; epochIdx++) {
        // Generate shuffled indices for this epoch
        int* indices = generateRandomElements(splitIdx, dataCount - 1);
        
        // Calculate number of complete batches
        int numBatches = trainSize / batchSize;
        
        // Process each batch
        for (int batchIdx = 0; batchIdx < numBatches; batchIdx++) {
            loss = 0;
            valError = 0;
            
            // Process each sample in the batch
            for (dataIdx = 0; dataIdx < batchSize; dataIdx++) {
                // Calculate the index into our shuffled indices array
                int sampleIdx = batchIdx * batchSize + dataIdx;
                if (sampleIdx < trainSize) {  // Safety check
                    shuffledIdx = indices[sampleIdx];
                    
                    // Train on this sample
                    feedForwardNet(net, data->inputVals[shuffledIdx], data->colCount);
                    softmaxNet(net);
                    backPropagation(net, data->targetVals[shuffledIdx], data->numOfClasses);
                }
            }
            
            // Update weights after processing the batch
            updateWeightsNetADAM(net, learningRate, batchSize, 0.9, 0.99);
        }
        
        // Calculate and print accuracy for this epoch
        int correct, wrong;
        testResults(net, data, splitIdx, &correct, &wrong);
        double accuracy = 100.0 * correct / (correct + wrong);
        printf("Epoch %d, accuracy: %.3lf%%\n", epochIdx + 1, accuracy);
        
        // Clean up the indices array for this epoch
        free(indices);
    }

    // Final test results
    int correct, wrong;
    testResults(net, data, splitIdx, &correct, &wrong);
    double accuracy = 100.0 * correct / (correct + wrong);
    printf("---- Final Test Results ----\nWrong    : %d\nCorrect  : %d\nAccuracy : %.3lf%%\n", 
           wrong, correct, accuracy);
}

double activation(double x) { return x > 0 ? x : 0.01 * x; } // ReLu
double derivActivation(double x) { return x > 0 ? 1 : 0.01; }
