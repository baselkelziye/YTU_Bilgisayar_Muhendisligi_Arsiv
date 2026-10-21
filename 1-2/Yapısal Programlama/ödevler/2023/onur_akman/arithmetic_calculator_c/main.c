#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct STACK
{
    int top;
    int st[SIZE];
}
STACK;

void initialize (STACK *stack)
{
    stack->top=0;
}

int isEmpty (STACK stack)
{
    if (stack.top==0)
        return 1;
    else
        return 0;
}

int isFULL (STACK stack)
{
    if (stack.top==SIZE)
        return 1;
    else
        return 0;
}

void pushSign (STACK *stack, char sign) //Ýþaretler Stack'i için Push fonksiyonu
{
    if (isFULL(*stack))
        printf("Stack is full. \n");
    else
    {
        stack ->st[stack->top]=sign;
        stack->top++;
    }

    int j;
    printf("\n Signs Stack:");
    for (j=0;j<stack->top;j++){ printf(" %c ", stack->st[j]); }
    printf("\n");
}

void pushNumber (STACK *stack, int value) //Sayýlar Stack'i için Push fonksiyonu
{
    if (isFULL(*stack))
        printf("Stack is full. \n");
    else
    {
        stack ->st[stack->top]=value;
        stack->top++;
    }

    int j;
    printf("\n Numbers Stack:");
    for (j=0;j<stack->top;j++){ printf(" %d ", stack->st[j]); }
    printf("\n");
}

char popSign (STACK *stack) //Ýþaretler Stack'i için Pop fonksiyonu
{
    if(isEmpty(*stack))
        printf("Signs stack is empty. \n");
    else{
        stack->top--;
        return stack->st[stack->top];
    }

    int j;
    printf("\n Signs Stack:");
    for (j=0;j<stack->top;j++){ printf(" %c ", stack->st[j]); }
    printf("\n");
}

int popNumber (STACK *stack) //Sayýlar Stack'i için Push fonksiyonu
{
    if(isEmpty(*stack))
        printf("Numbers stack is empty. \n");
    else
    {
        stack->top--;
        return stack->st[stack->top];
    }

    int j;
    printf("\n Numbers Stack:");
    for (j=0;j<stack->top;j++){ printf(" %d ", stack->st[j]); }
    printf("\n");
}

int decimal (int i, char input[]) //Inputtaki sayýlarýn decimal karþýlýðýný çýkaran fonksiyon
{
    int ascii=input[i], result=0;
    while ((ascii>47) && (ascii<58))
    {
        result=(10*result)+(ascii-48);
        i++;
        ascii=input[i];
    }
    return result;
}

int process (int value1, int value2, char sign)  //Matematiksel iþlemleri yapan fonksiyon
    {
    int result;
    if (sign=='+')
        result=value1+value2;
    else if (sign=='-')
        result=value1-value2;
    else if (sign=='*')
        result=value1*value2;
    else if (sign=='/')
        result=value1/value2;
    else
        printf("The sign is not valid. /n");

    return result;
}

char priority(char a,char b)  //Ýþaretler arasý önceliði kontrol eden fonksiyon
{
    if (b=='(')
        return 'x';
    else if ((a=='*') || (a=='/'))
    {
        if ((b=='*') || (b=='/'))
            return 'e';
        else
            return 'h';
    }
    else
    {
        if ((b=='+') || (b=='-'))
            return 'e';
        else
            return 'l';
    }

}


int main()
{
    int ascii, i=0;
    char input[100],j=NULL;

    STACK numbers;
    STACK signs;
    initialize(&numbers);
    initialize(&signs);

    printf("Please enter the input. \n");
    scanf("%s", input);

    printf("\n");

    ascii=input[0];

    while ( ( (ascii>47) && (ascii<58) ) || (ascii==40) || (ascii==41) || ( (ascii>41) && (ascii<48) ) ) //Karakterleri sýnýflandýrma
    {
        if ((ascii>47) && (ascii<58)) //Gelen karakter bir sayý mý
        {
            pushNumber(&numbers,decimal(i,input));
            while (ascii>47)
            {
                i++;
                ascii=input[i];
            }
        }
        else{ //Deðilse bir iþarettir
            if(ascii==40) //Sol parantez mi?
            {
                pushSign(&signs,input[i]);
                i++;
            }
            else if(ascii==41) //Sað parantez mi?
            {
                j=popSign(&signs);
                while (j!='(')
                {
                    pushNumber(&numbers,process(popNumber(&numbers),popNumber(&numbers),j));
                    j=popSign(&signs);
                }
                i++;
            }
            else if((ascii>41) && (ascii<48)) //Sýradan 4 iþlem iþareti mi?
            {
                if (signs.top==0) //Stack þu an boþ mu?
                {
                    pushSign(&signs,input[i]);
                    i++;
                }
                else if (priority(input[i],signs.st[signs.top-1])=='h') //Önceki iþarete göre öncelikli mi?
                {
                    pushSign(&signs,input[i]);
                    i++;
                }
                else
                {
                    while ((priority(input[i],signs.st[signs.top-1])!='h') && (priority(input[i],signs.st[signs.top-1])!='x') && (signs.top!=0))
                    {
                        pushNumber(&numbers,process(popNumber(&numbers),popNumber(&numbers),popSign(&signs)));
                    }
                pushSign(&signs,input[i]);
                i++;
                }

            }
    ascii=input[i];
        }
    }

    while (numbers.top>1) //Kalan sayýlarla iþlemler tamamlanýr
    {
        pushNumber(&numbers,process(popNumber(&numbers),popNumber(&numbers),popSign(&signs)));
    }

    int result = popNumber(&numbers);
    printf("\n RESULT: %d \n", result);
}


