//  Infix to postfix, single character, +-*/ C++

#include<stdio.h>
#include<conio.h>
#define max 50
char s[max];
int top;
void ev();//evaluate the expressions
int lfas(char);//left associated
int hp(char,char);//high precdent
int we(char);//find the weight of the opreators
int em();//isempty
int fu();//isfull
void push(char a);//elememnt push to stack
char pop();//element pop from stack
int od(char);//is opreand
int op(char);//is oprator
int pa(char);//is open parenthesis
char in[50],po[50];
int main()
{
top=-1;
printf("enter the infix expression \n");
scanf("%s",in);
ev();
printf("the infix expression\n%s\n",in);
printf("the postfix expression\n%s\n",po);
return 0;
}
void ev()
{
int i,j;
i=j=0;
char temp;
for(i=0;in[i]!='\0';i++)
{
temp=in[i];
if(od(temp))
{
po[j]=temp;
j++;
}
else if(op(in[i]))
{
while((!em())&&(!pa(temp))&&(hp(s[top],temp)))
{
temp=pop();
po[j]=temp;
j++;
}
push(in[i]);

                }
                else if(pa(temp))
                push(in[i]);
                else if(temp==')')
                {
                temp=pop();	
               	while(!pa(temp))
               	{
 po[j]=temp;
 j++; 
 temp=pop();                 	
                   	
                 }
                pop();
                	
                }
	
}
while(!em())
{
temp=pop();
po[j]=temp;
j++;	
	
}
}
int lfas(char a)
{
if(a == '$'|| a== '^')
return 0;
else
return 1;
}
int hp(char a,char b)
{
int w1,w2;
w1=we(a);
w2=we(b);
if(w1==w2)
{
if(lfas(a))
return 1;
else
return 0;
}
return ( w1>w2? 1:0);

}
int we(char a)
{
int p;
switch(a)
{
case'-':
case'+':p=1;
break;
case'*':
case'/':
case'%':p=2;
break;
case'^':
case'$':p=3;
break;
}
return p;
}
int em()
{
if(top==-1)
return 1;
else
return 0;
}
int fu()
{
if(top==max-1)
return 1;
else
return 0;
}
void push(char a)
{
if(!fu())
{
top++;
s[top]=a;
}
else
printf("an error \n");
}
char pop()
{
char t;
if(!em())
{
t=s[top];
top--;
return(t);
}
else
return '@';

}
int od(char a)
{
if(a>='a'&& a<='z'||a>='A'&& a<='Z'||a>='0'&&a<='9')
return 1;
else
return 0;
}
int op(char a)
{
if(a=='+'||a=='-'||a=='*'||a=='/'||a=='%'||a=='^'||a=='$')
return 1;
else
return 0;
}
int pa(char a)
{
if(a=='(')
return 1;
else
return 0;
}
