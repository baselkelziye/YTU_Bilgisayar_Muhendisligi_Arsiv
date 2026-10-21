# Neural-Network-Application
YTU MSc Course HW

Problems solved with the help of Keras library of Tensorflow

## PROBLEM 1

### CASE 1
A study is initiated by the government to ensure safe living conditions in a country. Accordingly, all foreign aircraft seen in the country's airspace should be classified as fighter aircraft or bomber aircraft. The speed and weight of each aircraft can be measured. Since the researchers are new to classification problems, they decide to use a single-layer feedforward network to represent the incoming data. Their first task is to build a classifier based on previously seen and classified aircraft. Their data is given in the table below.

|Aircraft type | Weight (lbs) | Speed (mph) |
| :---        |    :----:   |          ---: |
|Mirage IIIB (S) | 26455 | 1460 |
|Mirage F.1E (S) | 33510 | 1450 |
|Mirage 2000 (S) | 36375 | 1550 |
|F16 (S) | 37500 | 1350 | 
|F14 (S) | 72000 | 1564 |
|B52H (B) | 505000 | 595 |
|B1b (B) | 477000 | 825 |
|KC10 (B) | 590000 | 600 |

In this table, warplanes (S) are denoted by bombers (B).

### QUESTION 1
By creating a pattern file containing the above data, design and train a network to classify the planes correctly. After training, obtain a graph showing the patterns the network has learned and the decision boundary (hyperplane). Explain the classification made by the network.

### CASE 2
The country suddenly goes into an emergency: Unknown planes have been spotted. The classifier should be tested immediately. Are these planes fighter jets or bomb planes?
           The information received is as follows:
           
|Weight (lbs)| Speed (mph)|
| :---        |    :----:   |
|565035| 559|
|68000| 1653|
|50064| 1190|
|406966| 516|

### QUESTION 2
Create a new pattern file containing the incoming data. The file format should be such that it can classify (+1 or –1) for each aircraft. Test whether all aircraft are fighter or bomber aircraft.

### CASE 3
Meanwhile, some newly classified aircraft have been found:
|Aircraft type| Weight (lbs) |Speed (mph)|
| :---        |    :----:   |          ---: |
|Harrier GR-3| 26,000 |737
|DC9(B) 149,471 |518|

### QUESTION 3
Add these planes to the file you used for training and re-adjust the mesh weights to learn all 10 planes.

### CASE 4
Under the influence of destructive forces, the old government is overthrown and a new government is established. Coincidentally, all new members of the government are spying on the other side, but this is unknown to researchers. The new government begins to give researchers erroneous data to disrupt the aircraft classification project.

|Aircraft type| Weight (lbs)| Speed (mph)|
| :---        |    :----:   |          ---: |
|bomber| 150,000| 900|
|fighter jet| 250,000| 800|
### QUESTION 4
Add these new entries to the learning pattern and try to teach all the data to the network. Give a full description of the behavior of the network. Without using a computer, estimate how many hidden units will be needed to solve the problem and mark them on a graph showing the learning patterns.

## Problem 2
Two famous British detectives, Dr. Watson and Sherlock Holmes, drew a statistical conclusion from the crimes they solved and found a method to decide whether the murder was committed intentionally or as a result of self-defense by multiplying the information about the crime with certain coefficients. Again in such an event, Dr. Watson goes to the crime scene, collects the evidence and conveys the mathematical results to S.Holmes. S.Holmes answers the given numbers verbally as follows.
                                                            

|1st class evidence (Dr.Watson)| 2nd class evidence (Dr.Watson)| Conclusion (S.Holmes)|
| :---        |    :----:   |          ---: |
|1000| 975| Self-defense|
|100 |990| Intentional|
|980 |110| Intentional|
|95 |170 |self-defense|

Here, S.Holmes decides according to the 1st and 2nd grade evidence scores and there is a one-to-one logical relationship between the scores sent and the decision mechanism.

**A )** Based on the data above, design a multi-layered network with two hidden units in one layer to form the decision-making structure of S.Holmes. The weights will be randomly initialized. 

a) Calculate the initial output of the network for each of the input patterns.

b) Train your network for 100 steps, taking the learning rate=0.5 and momentum=0.9. What can you say about the function performed by the hidden units at this stage?

c) Train your network so that the mean square error is less than 0.005. Give the final weights of the network and explain the network output. Show the data and the decision curve on the same graph.

d) If this problem is to be solved with a network consisting of more hidden units and/or more hidden layers, how would the results change? For example, does it learn faster or give more precise results (smaller error)? What are the results when the learning rate, momentum, and initial weights change? Train your network using different values for these parameters and evaluate the results.

**B )** Design and train the same structure with RBF and draw the decision curve.
