# Fast Linked List

## Kaynaklar

1. [Homework Assignment 3 - Fast Linked Lists ](https://viterbi-web.usc.edu/~adamchik/15-121/labs/HW-3%20Fast%20Lists/lab.html)  
2. [Veri Yapıları ve Algoritmalar - Ödev 1](https://online.yildiz.edu.tr/upload/ytu/Evaluation/62e9f608-00e5-471a-950f-de90bc31ce9e.pdf)

```sh

ondergormez@ondergormez-IdeaPad:~/Private/Doktora/Repos/BLM2512_Data_Structures_and_Algorithms/build-dir$ ./Homework1/FastLinkedListSingleFile
Fast Linked List Implementation
Node Address: 0x875406d0, Node Value: 0
Node Address: 0x875406f0, Node Value: 1
Node Address: 0x87540710, Node Value: 2
Node Address: 0x87540730, Node Value: 3
Node Address: 0x87540750, Node Value: 4
Node Address: 0x87540770, Node Value: 5
Node Address: 0x87540790, Node Value: 6
Node Address: 0x875407b0, Node Value: 7
Node Address: 0x875407d0, Node Value: 8
Node Address: 0x875407f0, Node Value: 9
Length of the linked list: 10
Node Address: 0x875407b0, Node Value: 7
In function getLinkedListNode(): Index not found in the linked list!
********************* 1. Level *********************
Head Address: 0x875406b0
Node Address: 0x875406d0, Node Value: 0
Node Address: 0x875406f0, Node Value: 1
Node Address: 0x87540710, Node Value: 2
Node Address: 0x87540730, Node Value: 3
Node Address: 0x87540750, Node Value: 4
Node Address: 0x87540770, Node Value: 5
Node Address: 0x87540790, Node Value: 6
Node Address: 0x875407b0, Node Value: 7
Node Address: 0x875407d0, Node Value: 8
Node Address: 0x875407f0, Node Value: 9
********************* 2. Level *********************
Head Address: 0x0x556d87540830
Node Address: 0x87540850, Node Value: 0
Node Address: 0x87540870, Node Value: 2
Node Address: 0x87540890, Node Value: 4
Node Address: 0x875408b0, Node Value: 7
Node Address: 0x875408d0, Node Value: 8
********************* 3. Level *********************
Head Address: 0x0x556d87540930
Node Address: 0x87540950, Node Value: 0
Node Address: 0x87540970, Node Value: 7
Node Address: 0x87540990, Node Value: 8
********************* 4. Level *********************
Head Address: 0x0x556d875409d0
Node Address: 0x875409f0, Node Value: 7
Node Address: 0x87540a10, Node Value: 8
********************* 5. Level *********************
Head Address: 0x0x556d87540a50
Node Address: 0x87540a70, Node Value: 7
********************* Heads *********************
Node Address: 0x0x556d87540a90, Head Address Value: 0x0x556d87540a50
Node Address: 0x0x556d87540a30, Head Address Value: 0x0x556d875409d0
Node Address: 0x0x556d875409b0, Head Address Value: 0x0x556d87540930
Node Address: 0x0x556d87540910, Head Address Value: 0x0x556d87540830
Node Address: 0x0x556d875408f0, Head Address Value: 0x0x556d875406b0
Searching in the level 5...
Searching in the level 4...
Value found  in the 1. index of linked list
Find in the 4. Level
Size of inputArray is 4 
Node Address: 0x87540ad0, Node Value: 3
Node Address: 0x87540af0, Node Value: 5
Node Address: 0x87540b10, Node Value: 9
Node Address: 0x87540b30, Node Value: 15
********************* 6 Ekliyoruz *********************
Node Address: 0x87540ad0, Node Value: 3
Node Address: 0x87540af0, Node Value: 5
Node Address: 0x87540b50, Node Value: 6
Node Address: 0x87540b10, Node Value: 9
Node Address: 0x87540b30, Node Value: 15
********************* 1 Ekliyoruz *********************
Node Address: 0x87540b70, Node Value: 1
Node Address: 0x87540ad0, Node Value: 3
Node Address: 0x87540af0, Node Value: 5
Node Address: 0x87540b50, Node Value: 6
Node Address: 0x87540b10, Node Value: 9
Node Address: 0x87540b30, Node Value: 15
********************* 20 Ekliyoruz *********************
Node Address: 0x87540b70, Node Value: 1
Node Address: 0x87540ad0, Node Value: 3
Node Address: 0x87540af0, Node Value: 5
Node Address: 0x87540b50, Node Value: 6
Node Address: 0x87540b10, Node Value: 9
Node Address: 0x87540b30, Node Value: 15
Node Address: 0x87540b90, Node Value: 20
********************* 9 Ekliyoruz *********************
Node Address: 0x87540b70, Node Value: 1
Node Address: 0x87540ad0, Node Value: 3
Node Address: 0x87540af0, Node Value: 5
Node Address: 0x87540b50, Node Value: 6
Node Address: 0x87540bb0, Node Value: 9
Node Address: 0x87540b10, Node Value: 9
Node Address: 0x87540b30, Node Value: 15
Node Address: 0x87540b90, Node Value: 20
Adding to the 1. Level...
Node Address: 0x875406d0, Node Value: 0
Node Address: 0x875406f0, Node Value: 1
Node Address: 0x87540710, Node Value: 2
Node Address: 0x87540730, Node Value: 3
Node Address: 0x87540750, Node Value: 4
Node Address: 0x87540770, Node Value: 5
Node Address: 0x87540790, Node Value: 6
Node Address: 0x875407b0, Node Value: 7
Node Address: 0x875407d0, Node Value: 8
Node Address: 0x875407f0, Node Value: 9
Node Address: 0x87540bd0, Node Value: 30
Adding to the 2. Level...
Node Address: 0x87540850, Node Value: 0
Node Address: 0x87540870, Node Value: 2
Node Address: 0x87540890, Node Value: 4
Node Address: 0x875408b0, Node Value: 7
Node Address: 0x875408d0, Node Value: 8
Node Address: 0x87540bf0, Node Value: 30
Value found  in the 10. index of linked list
Deleting value from the 1. Level...
Value found  in the 5. index of linked list
Deleting value from the 2. Level...
Value not found in 3. Level. Skipping...
Value not found in 4. Level. Skipping...
Value not found in 5. Level. Skipping...

```