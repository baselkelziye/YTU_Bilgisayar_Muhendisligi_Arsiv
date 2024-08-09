/*
 * C Program to Check whether two Strings are Anagrams 
 */
#include <stdio.h>
 
int find_anagram(char [], char []);
 
int main()
{
    char array1[100], array2[100];
    int flag;
    printf("Enter the string\n");
    gets(array1);
    printf("Enter another string\n");
    gets(array2);
    flag = find_anagram(array1, array2);
    if (flag == 1)
        printf("%s and %s are anagrams.\n", array1, array2);
    else
        printf("%s and %s are not anagrams.\n", array1, array2);
    return 0;
}
 
int find_anagram(char array1[], char array2[])
{
    int num1[26] = {0}, num2[26] = {0}, i = 0;
 
    while (array1[i] != '\0')
    {
        num1[array1[i] - 'a']++;
        i++;
    }
    i = 0;
    while (array2[i] != '\0')
    {
        num2[array2[i] -'a']++;
        i++;
    }
    for (i = 0; i < 26; i++)
    {
        if (num1[i] != num2[i])
            return 0;
    }
    return 1;
}
