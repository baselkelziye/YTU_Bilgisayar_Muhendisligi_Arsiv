# %% 
from matplotlib import pyplot as plt
import re
import random

# %% 
def getPixels(fileDir): # Reads pixel values by using given file directory
    myFile = open(fileDir, "r")
    line = myFile.readline()
    myFile.close()
    return re.findall(',?\s?(-?\d),?', line) # Uses RegEx to obtain pixel values

  # %%    
def threshold(sum, thresholdValue):
    if sum > thresholdValue:
        return 1.0
    elif sum < (-1*thresholdValue):
        return -1.0
    else:
        return 0.0

  # %%
def predict(data, weights, thresholdValue): # Predicts whetwer the given piece of data will be resolved as the output owns the given weight
    sum = 0
    for x in range(0, len(weights)):
        sum += data[x]*weights[x]
    return threshold(sum, thresholdValue)

  # %%
def accuracy(data, weights, thresholdValue): # Accuracy measurement
    token = 0.0
    for i in range (0,len(data)):
        for x in range (len(weights)):
            prediction = predict(data[i][:-1], weights[x], thresholdValue)
            if data[i][-1] == float(x) and prediction == 1.0: # Letter matches and the output = 1
                token = token + 1.0
            elif data[i][-1] != float(x) and prediction == -1.0: #Vice versa
                token = token + 1.0
    return ((token/49.0)*100.0) # Maximum 7 data x 7 output node = 49 token can be collected

  # %%
def normalize(array, lower, upper): # Optional, usable if weights should be normalized
    width = upper - lower
    for w in array:
        w = (w - min(array))/(max(array) - min(array)) * width + lower
    return array

  # %%
def dataModification(data, volume, prefix): # Modifies the given data by the given volume
    for _ in range (0,volume):
        idx = random.randint(1,61)
        if prefix == "Binary":
            data[idx] = 1 - data[idx]
        else:
            while(True):
                val = random.randint(-1,1)
                if (val != data[idx]):
                    data[idx] = val
                    break
    return data

  # %%
def trainWeights(data,weights,nrOfEpoch,learningRate,thresholdValue,rule,prefix,mod,volume): #Training
    print("Accuracy with deafult weights:", accuracy(data, weights, thresholdValue), "%")
    
    accuracyPerEpoch = []
    for epoch in range (0,nrOfEpoch):
        for line in data[:14]: # ONLY 2 FONTS USED AS TRAINING DATA
            _line = line.copy() # for if user requested random modification
            
            if (mod == 1): # Modifying data every epoch if requested
                _line = dataModification(_line, volume, prefix)
                    
            for j in range (0, 7): # For every output
                
                target = -1.0
                if line[-1] == j: #Does the letter idx value match with the index of the output
                    target += 2.0
                    
                prediction = predict(_line[:-1],weights[j],thresholdValue)
                error = target - prediction
                
                factor = target # Depends on the training rule
                if (rule == "d"):
                    factor = error
                
                if (error != 0):
                    weights[j][0] = weights[j][0] + (learningRate * factor) #For bias
                    for k in range (1,len(weights[j])):
                        weights[j][k] = weights[j][k] + (learningRate * factor * _line[k])
                weights[j] = normalize(weights[j], -1, 1)
            
            

        acc = accuracy(data[14:21], weights, thresholdValue) # THIRD FONT USED FOR VALIDATION
        print("Validation accuracy after epoch #", epoch+1, " = ", acc, "%")
        accuracyPerEpoch.append(acc)
        
        if acc==100.0: # Training stpos if the accuracy reaches to 100%
            print("Stopping before epoch #", epoch+2)
            break
        
    plt.plot(accuracyPerEpoch, 'r-') 
    plt.show()
    return weights

# %% 
def main():
    
    #bias
    bias = 1.0
    volume = 0 # Will be set by the user later
    
    # Needed to create file names
    base = "Font"
    fonts = ["_1", "_2", "_3"]
    letters = ["_A", "_B", "_C", "_D", "_E", "_J", "_K"]

  # %%    
    #for multiple training if will be requested
    repeat = 1
    
    while(repeat==1):
        
        #This is where we will store our pixel values
        # Allignemnt will be "bias : pixels : the idx of drawn letter figure"
        data = []
        weights= []

  # %%    
        # Getting params from user
        while (True):
            prefix = input("Select training data type (0 for BINARY or 1 for BIPOLAR)...")
            if (prefix == "0"):
                prefix = "Binary"
                break
            elif (prefix == "1"):
                prefix = "Bipolar"
                break
            else:
                print("INVALID")
            
        while (True):
            rule = (input("Select learning rule (P for PERCEPTRON or D for DELTA)...")).lower()
            if (rule == "p" or rule == "d"):
                break
            
        while (True):
            mod = int(input("Select if apply random data modification (0 for NO or 1 for YES)..."))
            if (mod == 0):
                break
            if (mod == 1):
                while (True):
                    volume = int(input("Select number of pixels to be modified for each drawing, every epoch (>0)..."))
                    if (volume > 0):
                        break
                    else:
                        print("INVALID")
                break
            else:
                print("INVALID")
        
        while (True):
            nrOfEpoch = int(input("Select the number of epoch (>0)..."))
            if (nrOfEpoch > 0):
                break
            else:
                print("INVALID")
            
        while (True):
            learningRate = float(input("Select learning rate (Between 0.0 and 1.0)..."))
            if (learningRate > 0.0 and learningRate < 1.0):
                break
            else:
                print("INVALID")
            
        while (True):
            thresholdValue = float(input("Select threshold value for activation function (Between 0.0 and 1.0)..."))
            if (thresholdValue > 0.0 and thresholdValue < 1.0):
                break
            else:
                print("INVALID")

  # %%        
        # Setting default weights
        for i in range (0,7):
            wghts = []
            wghts.append(1.0) # bias weight
            for x in range (0,63):
                wghts.append(0.0)
            weights.append(wghts)
 
  # %%
        # Fetching pixels and creating our data
        for font in fonts:
            letterIndex = 0.0
            for letter in letters:
                pixels = getPixels(prefix + "/" + base + font + letter +".txt")
                dataLine = []
                dataLine.append(bias)
                
                for x in pixels:
                    if x == "1":
                        dataLine.append(1.0)
                    elif x == "-1":
                        dataLine.append(-1.0)
                    else:
                        dataLine.append(0.0)
                dataLine.append(letterIndex) # Desired output
                
                data.append(dataLine)
                letterIndex += 1.0   
                
        # Training and getting our trained weight values    
        weights = trainWeights(data=data,weights=weights,nrOfEpoch=nrOfEpoch,learningRate=learningRate,thresholdValue=thresholdValue, 
                               rule=rule, prefix = prefix, mod = mod, volume = volume)
        
    # %%
        print("Final Accuracy = ", accuracy(data[14:21],weights,thresholdValue), "%")
        
        print()
        print("Train all over again -> 1")
        print("Manually test the trained model -> 2")
        print("Automatically test the trained model -> 3")
        print("Exit -> any other")
        repeat = int(input("Please enter..."))
        
  # %% Manual testing
        while (repeat==2): # Manuel test mode
            print("Manual testing mode...\n")
            font = "_" + input("Font code...")
            char = "_" + (input("Letter in given font...")).upper()
            print(prefix + "/" + base + font + char +".txt")
            pixels = getPixels(prefix + "/" + base + font + char +".txt")
            
            testdata = []
            testdata.append(bias)
            for x in pixels:
                if x == "1":
                    testdata.append(1.0)
                elif x == "-1":
                    testdata.append(-1.0)
                else:
                    testdata.append(0.0)
                    
            for x in range(0,7):
                print("Output for letter" + letters[x])
                print(predict(testdata, weights[x], thresholdValue))
                
            print()
            print("Train all over again -> 1")
            print("Keep manually testing the trained model -> 2")
            print("Automatically test the trained model -> 3")
            print("Exit -> any other")
            repeat = int(input("Please enter..."))
            
  # %%     Automaic testing  
        if ( repeat == 3 ):
            print("Auto testing mode...\n")
            for font in fonts:
                for letter in letters:
                    pixels = getPixels(prefix + "/" + base + font + letter +".txt")
                    testData = []
                    testData.append(bias)
                    
                    for x in pixels:
                        if x == "1":
                            testData.append(1.0)
                        elif x == "-1":
                            testData.append(-1.0)
                        else:
                            testData.append(0.0)
                            
                    print()
                    print("Predictions for " + prefix + "/" + base + font + letter +".txt")
                    for x in range(0,7):
                        print("Output for letter" + letters[x])
                        print(predict(testData, weights[x], thresholdValue))
            print()
            print("Train all over again -> 1")
            print("Exit -> any other")
            repeat = int(input("Please enter..."))    
    
 # %%   
if __name__ == "__main__":
    main()