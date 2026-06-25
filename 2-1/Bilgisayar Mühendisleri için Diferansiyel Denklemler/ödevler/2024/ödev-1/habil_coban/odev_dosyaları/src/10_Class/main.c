#include "neural_net.h"

int main() {


    int option ;
    int isTest = 0;
    int testIdx = 0;
    int correct, wrong, i;
    FILE *fp_weights;
    Data trainData;
    Net* myNet;

    srand(time(NULL)); 

    
    FILE *fp = fopen("data/mnist-digits.txt", "r"); // Open file containing the data

    if (fp == NULL) {
        printf("Error opening file!\n");
        return -1;
    }
    readData(fp, &trainData);
    fclose(fp);
    
    //-----------------

    printf("New Net : 1 ,Load Net : 2\nOption :");
    scanf_s("%d",&option);

    printf("Input(%d) and output(%d) layer set automatically.\n", trainData.colCount, trainData.numOfClasses);
    if (option == 1) {
        getNetProperties(&myNet, &trainData);
    }
    else {
        fp_weights = fopen("data/weights.txt", "r"); // Open file containing the weights
        myNet = readNet(fp_weights);
        fclose(fp_weights);
    }

    printf("\nTest - 1 \nTrain - 2\nOption:");
    scanf("%d", &isTest);


    if(isTest == 1){

        testResults(myNet,&trainData,trainData.rowCount,&correct, &wrong);
        printf("\nCorrect: %d, Wrong: %d, Accuracy: %lf\n",correct, wrong, (double)correct/(correct+wrong));
        printf("-----------------\n");

        while (isTest == 1)
        {
            testIdx = rand()%trainData.rowCount;
            feedForwardNet(myNet, trainData.inputVals[testIdx], trainData.colCount);
            printNumber(trainData.inputVals[testIdx], trainData.colCount);

            testSample(myNet, &trainData, testIdx);

            printf("Next sample - 1\nExit test - 2\nOption:");
            scanf("%d",&isTest);
            printf("-----------------\n");
        }

    }else{

        int yontem;
        printf("\n1-Gradient Descent\n2-Stochastic Gradient Descent\n3-Adam\n");
        printf("Choose Method :");
        scanf("%d", &yontem);

        int epoch, batchSize;
        double eta;
        
        switch (yontem){
        case 1:
            printf("Enter epoch :");
            scanf("%d", &epoch);
            printf("Enter learning rate :");
            scanf("%lf", &eta);
            trainGD(myNet, &trainData, epoch, eta);
            break;
        
        case 2:
            printf("Enter epoch :");
            scanf("%d", &epoch);
            printf("Enter learning rate :");
            scanf("%lf", &eta);
            printf("Enter batch size :");
            scanf("%d", &batchSize);
            trainSGD(myNet, &trainData, epoch, batchSize, eta);
            break;
        
        case 3:
            printf("Enter epoch :");
            scanf("%d", &epoch);
            printf("Enter learning rate :");
            scanf("%lf", &eta);
            printf("Enter batch size :");
            scanf("%d", &batchSize);
            trainADAM(myNet, &trainData, epoch, batchSize, eta);
            break;

        default:
            printf("Not a valid option !\n");
            break;
        }

        
        printf("Do you want to save Neural Net weights ?\n1-Yes\n2-No\nChoose :");
        scanf("%d",&option);
        if(option == 1){
            fp_weights = fopen("data/weights.txt", "w"); // Open file containing the data
            saveNet(myNet, fp_weights);
            fclose(fp);
            printf("Neural Net is saved !\n");
        }
    
    }


    printf("Exitting program !");
    freeNet(myNet);
    freeData(&trainData);
    
    //  _CrtDumpMemoryLeaks();
    return 0;
}