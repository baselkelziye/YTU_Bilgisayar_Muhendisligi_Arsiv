#include<stdio.h>
#include<string.h>
 
int isDot(char a);
char upperCase(char a);
void makeCapital(char string[]);
 
int main()
{
   char sampleString[]={"in 1983.the ANSI formed a committee! to establish a standard. But ?when.specification"};
   printf("%s\n",sampleString);
   makeCapital(sampleString);
   printf("%s\n",sampleString);
   return 0;
}
 
void makeCapital(char string[])
{
   int i=0;
   string[0]=upperCase(string[0]);
   while (string[i+2]!='\0')
   {
       if(isDot(string[i]))
       {
           if(string[i+1]==' ')   
               string[i+2]=upperCase(string[i+2]);
           else
               string[i+1]=upperCase(string[i+1]);
       }
       i++;
   }
}
 
char upperCase(char a)
{
   if(a>='a' && a<='z')
       return (a-32);
   else return a;
}
 
int isDot(char a)
{
   if(a=='.' || a=='!' || a=='?')
       return 1;
   return 0;
}

