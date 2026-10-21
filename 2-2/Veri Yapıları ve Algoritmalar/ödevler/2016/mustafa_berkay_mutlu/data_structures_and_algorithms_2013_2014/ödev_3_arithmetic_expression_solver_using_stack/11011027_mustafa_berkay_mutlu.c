/****************************************************************************
 * main.c                                                                   *
 * Modified in 04 May 2014                                                  *
 * Written by Mustafa Berkay Mutlu                                          *
 * http://www.berkaymutlu.com/                                              *
 *                                                                          *
 * Please feel free to copy this source code.                               *
 *                                                                          *
 * DESCRIPTION:                                                             *
 *  This program converts infix notation equations to postfix notations and *
 * solves using Stack data structure.                                       *
 *                                                                          *
 ***************************************************************************/


#include <stdio.h>
#include <stdlib.h>

// Genel tanimlamalar:
#define BOOL_TRUE 1 // Boolean true'yu ifade eder.
#define BOOL_FALSE 0 // Boolean false'u ifade eder.
#define ERROR -1 // Hata olması durumunda kullanilan donus degeridir.

// Programa özel degistirilebilir tanimlamalar:
#define SHOW_DEBUG BOOL_TRUE // Bu etiket acik olursa her adimda stack durumunu ve Pop/Push edilmeleri gorebilirsiniz.
#define STACK_SIZE 50   // Stack'in karakter cinsinden boyutu
#define EXPRESSION_SIZE 50  // Girilecek olan ifadenin karakter cinsinden boyutu

// Operator tanimlamalari:
#define OPERATOR_ADD 1 // "+" toplama operatoru
#define OPERATOR_SUB 2 // "-" cikarma operatoru
#define OPERATOR_MUL 3 // "*" carpma operatoru
#define OPETATOR_DIV 4 // "/" bolme operatoru
#define OPENING_PARAN 5 // "(" acik parantez ifadesi
#define CLOSING_PARAN 6 // ")" kapalı parantez ifadesi


typedef struct STACK{
    int top; // Stack'in elemanlarindan sonraki bos gozunu isaret eder. Pop/Push islemlerine gore degisir.
    char data[STACK_SIZE]; // Stack'tir.
}STACK;


int isStackEmpty(STACK *); // Stack tamemen bos ise BOOL_TRUE, degilse BOOL_FALSE dondurur.
int isStackFull(STACK *); // Stack tamamen doluysa BOOL_TRUE, degilse BOOL_FALSE dondurur.
int Push(char, STACK *); // Stack'e char karakter Push eder.
char Pop(STACK *); // Stack'ten char karakter Pop eder.
int isNumber(char); // Verilen karakter sayi ise BOOL_TRUE, degilse BOOL_FALSE dondurur.
int whichOperatorIsThis(char); // Verilen karakterin islem operatorlerinden karsiligini bulur ve
int getPriority(char); // Islem operatorlerinin onceligini dondurur.
char getTopFromStack(STACK *); // Stack'in en ustundeki elemani dondurur. Ancak Pop etmez.
void printStack(STACK *); // Stack'i ekrana yazdirir. SHOW_DEBUG opsiyonu aktif ise calisir, degil ise calismaz.
int ConvertInfixToPostfix(STACK *, char [], char []); // Infix ifadeyi Stack'i kullanarak Postfix ifadeye cevirir.
int SolvePostfixViaStack(STACK *, char []); // Postfix islemi Stack yardimi ile cozer.
int parseCharToNumber(char); // Verilen karakterin islem yapilabilen sayi karsiligini dondurur.
char parseNumberToChar(int); // Verilen sayinin karakter karsiligini dondurur.


int main()
{
    STACK stack = {.top = 0, .data = {}}; // Stack olusturuluyor ve ilk değer atamalari yapiliyor.
    char expression_infix[EXPRESSION_SIZE] = {}; // Infix ifadenin tutuldugu char dizisi.
    char expression_postfix[EXPRESSION_SIZE] = {}; // Postfix ifadenin tutuldugu char dizisi.
    int result; // Islem sonucunun tutulacagi degisken.

    printf("Enter the infix expression> ");
    gets(expression_infix);

    ConvertInfixToPostfix(&stack, expression_infix, expression_postfix);
    printf("Postfix expression: ");
    puts(expression_postfix);

    result = SolvePostfixViaStack(&stack, expression_postfix);
    printf("Result: %d \n",result);

    getch();
    return 0;
}

int ConvertInfixToPostfix(STACK *stack, char expression_infix[], char expression_postfix[]){
    int index = 0; // Indicates expression_postfix array's element index.
    int i;
    int temp;

    if(SHOW_DEBUG) printf("[DEBUG] ConvertInfixToPostfix::\n");

    for(i=0;i<EXPRESSION_SIZE;i++){
        if(SHOW_DEBUG){
            printf("[DEBUG] ");
            printStack(stack);
            printf("[DEBUG] Postfix: ");
            puts(expression_postfix);
        }
        if(expression_infix[i] != ' ' && expression_infix[i] != '\0'){
            if(isNumber(expression_infix[i])){ // Sayı ise
                // postfix ifadeye eklenir.
                expression_postfix[index++] = expression_infix[i];
            }
            else{ // Sayı değil ise
                if(whichOperatorIsThis(expression_infix[i]) == OPENING_PARAN){ // "(" ifadesi ise.
                    // Yığına Push edilir.
                    if(isStackFull(stack)){
                        printf("Error. Stack overflow.\n");
                        return ERROR;
                    }
                    else{
                        Push(expression_infix[i], stack);
                        if(SHOW_DEBUG) printf("[DEBUG] %c Push edildi. Top: %d \n", expression_infix[i], stack->top);
                    }
                }
                else if(whichOperatorIsThis(expression_infix[i]) == CLOSING_PARAN){ // ")" ifadesi ise
                        // Sol parantez çıkana kadar yığından Pop işlemi yapılır.
                    do{
                        temp = Pop(stack);
                        expression_postfix[index++] = temp;
                        if(SHOW_DEBUG) printf("[DEBUG] %c Pop edildi. Top: %d \n", expression_postfix[index-1], stack->top);
                    }while(whichOperatorIsThis(temp) != OPENING_PARAN);
                }
                else{ // İşlem işaretleri ise
                    while(getPriority(expression_infix[i]) <= getPriority(getTopFromStack(stack)) && !isStackEmpty(stack) ){
                        expression_postfix[index++] = Pop(stack);
                        if(SHOW_DEBUG) printf("[DEBUG] %c Pop edildi. Top: %d \n", expression_postfix[index-1], stack->top);
                    }
                    if(isStackFull(stack)){
                        printf("Error. Stack overflow.\n");
                        return ERROR;
                    }
                    else{
                        Push(expression_infix[i], stack);
                        if(SHOW_DEBUG) printf("[DEBUG] %c Push edildi. Top: %d \n", expression_infix[i], stack->top);
                    }
                }
            }
        }
    }

    // Kalan isaretler Stack'ten Pop edilir
    while(!isStackEmpty(stack)){
        expression_postfix[index++] = Pop(stack);
        if(SHOW_DEBUG) printf("[DEBUG] %c Pop edildi. Top: %d \n",expression_postfix[index-1], stack->top);
    }

    return BOOL_TRUE;
}


int SolvePostfixViaStack(STACK *stack, char expression_postfix[]){
    int i;
    int operand1, operand2;
    int result;

    if(SHOW_DEBUG) printf("[DEBUG] SolvePostfixViaStack::\n");

    for(i=0;i<EXPRESSION_SIZE;i++){
        if(expression_postfix[i] != ' ' && expression_postfix[i] != '\0'){
            if(isNumber(expression_postfix[i])){  // Sayı ise
                Push(expression_postfix[i], stack);
            }
            // Acik-parantez veya kapali-parazntez degil ise islem isaretidir.
            else if( whichOperatorIsThis(expression_postfix[i]) != OPENING_PARAN && whichOperatorIsThis(expression_postfix[i]) != CLOSING_PARAN ){
                // Islem isareti ise:
                operand2 = parseCharToNumber(Pop(stack));
                operand1 = parseCharToNumber(Pop(stack));

                switch (whichOperatorIsThis(expression_postfix[i])){
                    case OPERATOR_MUL:
                        result = operand1 * operand2;
                        Push(parseNumberToChar(result), stack);
                        if(SHOW_DEBUG) printf("[DEBUG] Yapilan islem: %d * %d Sonuc: %d \n",operand1,operand2,result);
                        break;
                    case OPERATOR_SUB:
                        result = operand1 - operand2;
                        Push(parseNumberToChar(result), stack);
                        if(SHOW_DEBUG) printf("[DEBUG] Yapilan islem: %d - %d Sonuc: %d \n",operand1,operand2,result);
                        break;
                    case OPERATOR_ADD:
                        result = operand1 + operand2;
                        Push(parseNumberToChar(result), stack);
                        if(SHOW_DEBUG) printf("[DEBUG] Yapilan islem: %d + %d Sonuc: %d \n",operand1,operand2,result);
                        break;
                    case OPETATOR_DIV:
                        result = operand1 / operand2;
                        Push(parseNumberToChar(result), stack);
                        if(SHOW_DEBUG) printf("[DEBUG] Yapilan islem: %d / %d Sonuc: %d \n",operand1,operand2,result);
                        break;
                    default:
                        return ERROR;
                }
            }
        }
    }

    // Islem sonucu Stack'ten Pop edilerek sayiya donusturulur ve dondurulur.
    return parseCharToNumber(Pop(stack));
}


int isStackEmpty(STACK *stack){
    if(stack->top == 0) return BOOL_TRUE;
    else return BOOL_FALSE;
}

int isStackFull(STACK *stack){
    if(stack->top == STACK_SIZE) return BOOL_TRUE;
    else return BOOL_FALSE;
}

int Push(char item, STACK *stack){
    if(isStackFull(stack)){
        puts("Stack is full.\n");
        return BOOL_FALSE;
    }
    else{
        stack->data[stack->top] = item;
        stack->top++;
        return BOOL_TRUE;
    }
}

char Pop(STACK *stack){
    if(isStackEmpty(stack)){
        puts("Stack is empty.\n");
        return BOOL_FALSE; // ERROR (-1) if statement için true olduğundan ötürü BOOL_FALSE (0) kullanıldı
    }
    else{
        stack->top--;
        return stack->data[stack->top];
    }
}

int isNumber(char letter){

    if( ((int) letter <= (int)'9') && ((int) letter > (int)'0') ){
        return BOOL_TRUE;
    }
    else
        return BOOL_FALSE;
}

int whichOperatorIsThis(char letter){
    switch(letter){
    case '+':
        return OPERATOR_ADD;
    case '-':
        return OPERATOR_SUB;
    case '*':
        return OPERATOR_MUL;
    case '/':
        return OPETATOR_DIV;
    case '(':
        return OPENING_PARAN;
    case ')':
        return CLOSING_PARAN;
    default:
        return ERROR;
    }
}

int getPriority(char letter){
    switch(letter){
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    }
    return 4;
}

char getTopFromStack(STACK *stack){
    return stack->data[stack->top - 1];
}

void printStack(STACK *stack){
    int i;
    printf("STACK:\t");
    for(i=0;i<STACK_SIZE;i++)
        printf("%c ",stack->data[i]);
    printf("\n");
}

int parseCharToNumber(char letter){
    if( ((int) letter <= (int)'9') && ((int) letter >= (int)'0') ){
        return (int) letter - (int)'0';
    }
    else
        return ERROR;
}


char parseNumberToChar(int number){
    return (char) (number + (int)'0');
}


