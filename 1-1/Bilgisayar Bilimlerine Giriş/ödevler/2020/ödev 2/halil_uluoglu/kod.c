#include <stdio.h>

#define MAX 50

int main()
{
    char string[MAX],encrypted_text[MAX];
    char shift,temp;
    int x,i;

    puts("Please enter your sentence.");
    gets(string);
    puts(">>>>Your input sentence is: ");
    puts(string);

    do
    {
        puts("\nPlease enter shift value. 'l' for left 'r' for right ");
        shift=getc(stdin);
    }while((shift!='l')&&(shift!='r'));

    do
    {
        puts("\nPlease enter encryption value.It has to be above 0.");
        scanf("%d",&x);
    }while(x<=0);
    if(shift=='r')
    {
        x*=1;
    }
    else if(shift=='l')
    {
        x*=-1;
    }
    else
    {
        printf("The shift value is wrong.Exiting...");
        exit(-1);
    }
    puts("[INFO]Encryption is starting...Loading...");
    i=0;
    while(string[i]!='\0')
    {
        if(((string[i]>='a')&&(string[i]<='z'))) //if1
        {
            string[i]+=x;
            if((string[i]<'a'))     //2
            {
                string[i]=string[i]+('z'-'a')+1;
            }
            else if((string[i]>'z')) //3
            {
                string[i]=string[i]-('z'-'a')-1;
            }
        }
        else if(((string[i]>='A')&&(string[i]<='Z'))) //4
        {
            string[i]+=x;
            if((string[i]<'A')) //5
            {
                string[i]=string[i]+('Z'-'A')+1;
            }
            else if((string[i]>'Z'))  //6
            {
                string[i]=string[i]-('Z'-'A')-1;
            }
        }
        i++;
    }
    puts(">>>>Encrypted string is: ");
    puts(string);

    puts("[INFO]Decryption is starting...Loading...");
    i=0;
    x*=-1;
    while(string[i]!='\0')
    {
        if(((string[i]>='a')&&(string[i]<='z'))) //7
        {
            string[i]+=x;
            if((string[i]<'a')) //8
            {
                string[i]=string[i]+('z'-'a')+1;
            }
            else if((string[i]>'z')) //9
            {
                string[i]=string[i]-('z'-'a')-1;
            }
        }
        else if(((string[i]>='A')&&(string[i]<='Z'))) //10
        {
            string[i]+=x;
            if((string[i]<'A'))  //11
            {
                string[i]=string[i]+('Z'-'A')+1;
            }
            else if((string[i]>'Z')) //12
            {
                string[i]=string[i]-('Z'-'A')-1;
            }
        }
        i++;
    }
    puts(">>>>Dencrypted string is: ");
    puts(string);
    return 0;
}