//yarým yamalak biþe

#include <iostream>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

bool isOperator(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
    {
        return true;
    }
    else return false;
}


bool isOperand(char x)
{
    if( (x >= '0' && x<='9') || (x >= 'a' && x<='z') || (x >='A' && x<='Z') )
    {
        return true;
    }
    else return false;
}

bool isLowOperator(char x, char y)
{
    int valX = 0, valY = 0;

    if(x=='*' || x=='/')
    {
        valX = valX + 1;
    }
    if(x=='^')
    {
        valX = valX + 2;
    }


    if(y=='*' || y=='/')
    {
        valY = valY + 1;
    }
    if(y=='^')
    {
        valY = valY + 2;
    }

    if(valX < valY)
    {
        //   cout<<x<<"is lower than"<<y<<endl;
        return true;
    }
    else return false;

}


int evaluateOperator(int x, int y, char o)
{
    if(o == '+')
    {
        return (x+y);
    }
    else if(o == '-')
    {
        return (x-y);
    }
    else if(o == '/')
    {
        return (x/y);
    }
    else if(o == '*')
    {
        return (x*y);
    }
    else if(o == '^')
    {
        return pow(x,y);
    }

    return -1;
}

int main()
{

    /*
    Infix to postfix
    */


    stack<char> myStack;

    string infix = "1*(2/(3-4)+5)*6";

    infix = infix + ')';

    myStack.push('(');

    string p = "";

    int len = infix.length();

    for(int i =0; i<len &&  myStack.empty() != true; i++)
    {
        if(isOperand(infix[i]))
        {
            p = p + infix[i];
        }
        else if(infix[i] == '(')
        {
            myStack.push(infix[i]);
        }
        else if( isOperator(infix[i]) )
        {
            while( isOperator(myStack.top()) && (isLowOperator(infix[i],myStack.top()) != true))
            {
                p = p + myStack.top();
                myStack.pop();
            }

            myStack.push(infix[i]);

        }

        else if( infix[i] == ')' )
        {
            while(myStack.top() != '(')
            {
                p = p + myStack.top();
                myStack.pop();
            }

            myStack.pop();
        }

        /*
        cout<<"STEP "<<i<<" : "<<p;
                if(!myStack.empty()){
            cout<<myStack.top();}
        cout<<endl;
        */
    }


    cout<<"POSTFIX: "<<p<<endl;


    //Postfix to INFIX

    stack<string> anotherStack;

    for(int i =0; i<p.length(); i++)
    {
        if(isOperand(p[i]))
        {
            anotherStack.push(string(1,p[i]));
        }
        else if(isOperator(p[i]))
        {
            string tmp = p[i] + anotherStack.top();
            anotherStack.pop();
            tmp = tmp + anotherStack.top();
            anotherStack.pop();
            anotherStack.push(tmp);
        }

    }



    cout<<"PREFIX : "<<anotherStack.top()<<endl;


    //Evaluate prefix

    {
        stack<int> myStack;

        string x = anotherStack.top();
        x = '(' + x;

        int len = x.length() -1;
        // cout<<len;
        bool flag = true;

        for(int i = len; x[i] != '('; i--)
        {
            if(x[i] >= '0' && x[i]<= '9')
            {
                myStack.push(x[i] - 48);
            }
            else if(myStack.empty())
            {
                flag = false;
            }
            else if(isOperator(x[i]))
            {
                int a = myStack.top();
                myStack.pop();
                int b = myStack.top();
                myStack.pop();

                int res = evaluateOperator(a,b,x[i]);

                myStack.push(res);

            }


        }


        if(flag)
        {
            cout<<"Evaluated = "<<myStack.top()<<endl;
        }
        else cout<<"Invalid"<<endl;
    }





    return 0;
}
