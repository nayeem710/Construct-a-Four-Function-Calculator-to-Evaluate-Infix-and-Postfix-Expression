#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include <cmath>
#include <stdio.h>
#include <string>
#include <stack>


using namespace std;
typedef long double ld;
typedef long long int ll;

stack<ll>Stack;
string str;

void init()
{
    while (!Stack.empty())
        Stack.pop();
}

void Addition()
{
    ll op1,op2,S;
    op2=Stack.top();
    Stack.pop();
    op1=Stack.top();
    Stack.pop();
    S=op1+op2;
    Stack.push(S);
}

void Substraction()
{
    ll op1,op2,S;
    op2=Stack.top();
    Stack.pop();
    op1=Stack.top();
    Stack.pop();
    S=op1-op2;
    Stack.push(S);
}

void Multiplication()
{
    ll op1,op2,S;
    op2=Stack.top();
    Stack.pop();
    op1=Stack.top();
    Stack.pop();
    S=op1*op2;
    Stack.push(S);
}
void root()
{
    ll op1,S;

    op1=Stack.top();
    Stack.pop();
    S=sqrt(op1);
    Stack.push(S);
}
void square()
{
    ll op1,S;

    op1=Stack.top();
    Stack.pop();
    S=op1*op1;
    Stack.push(S);
}

void Division()
{
    ll op1,op2,S;
    op2=Stack.top();
    Stack.pop();
    if (op2)
    {
        op1=Stack.top();
        Stack.pop();
        S=op1/op2;
        Stack.push(S);
    }


    else
        cout << "\n\tWrong equation!!!\n\n\tInput Correctly Again...\n\n";
}
void Calculator(char C)
{
    if (C=='+')
        Addition();
    else if (C=='-')
        Substraction();
    else if (C=='*')
        Multiplication();
    else if (C=='/')
        Division();
    else if (C=='$')
        root();
    else if (C=='#')
        square();
}

bool Digit(char C)
{
    if(C>='0' && C<='9')
        return true;
    return false;
}

bool Operator(char C)
{
    if(C=='+' || C=='-' || C=='*' || C=='/'|| C=='$'|| C=='#')
        return true;
    return false;
}

int prec(char C)
{
    if(C=='*' || C=='/')
        return 2;
    else if(C=='+' || C=='-')
        return 1;
    else
        return -1;
}

void postFixOpp(string str1)
{
    int l=str1.length();
    for(int i=0; i<l; i++)
    {
        if(str1[i]==' ')
            continue;

        if(Operator(str1[i]))
            Calculator(str1[i]);

        else if(Digit(str1[i]))
        {
            ll opp=0;
            while(i<l && Digit(str1[i]))
            {
                opp=(opp*10)+(str1[i]-'0');
                i++;
            }
            i--;
            Stack.push(opp);
        }
    }
    cout << "\n\tResult: " << Stack.top() << endl << endl;
}

void postFix()
{
    printf("\nEnter The PostFix Equation: ");
    cin.ignore();
    getline(cin,str);
    postFixOpp(str);
}

void inFix()
{
    stack<char> st;
    string ns;

    printf("\nEnter The InFix Equation: ");
    cin.ignore();
    getline(cin,str);
    st.push('N');
    int l=str.length();
    for(int i=0; i<l; i++)
    {
        if(Digit(str[i])){
            ns+=str[i];

          }

        else if (str[i]==' '){
            ns+=' ';

        }
        else if(str[i]=='(')
            st.push('(');

        else if(str[i]==')')
        {
            while(st.top()!='N' && st.top()!='(')
            {
                ns+=st.top();

                st.pop();
            }
            if(st.top()=='(')
                st.pop();
        }
        else
        {
            while(st.top()!='N' && prec(str[i])<=prec(st.top()))
            {
                ns+=st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }
    while(st.top()!='N')
    {
        ns+=st.top();
        st.pop();
    }

    postFixOpp(ns);
}

 int TwoDigitMethod()
{
    int choice;
   long num1, num2, x;
   double PI, r, y;

   cout << "Please Choose Your Option:"
           "\n\t1. Addition"
           "\n\t2. Subtraction"
           "\n\t3. Multiplication"
           "\n\t4. Division"
           "\n\t5. Squares"
           "\n\t6. Root"
           "\n\t7. Sin(X)"
           "\n\t8. Cos(X)"
           "\n\t9. Tan(X)"

           "\n\t10. exit"
           "\n\nChoice: ";
   cin >> choice;

   while(choice < 1 || choice > 10)
   {
      cout << "\nPlease Choose the above Mentioned Option."
              "\nChoice: ";
      cin >> choice;
   }

   switch (choice)
   {
      case 1:
         cout << "Enter Two Numbers: \n";
         cin >> num1 >> num2;
         x = num1 + num2;
         cout << "Sum = " << x;
         break;

      case 2:
         cout << "Enter Two Numbers: \n";
         cin >> num1 >> num2;
         x = num1 - num2;
         cout << "Subtraction = " << x;
         break;

      case 3:
         cout << "Enter Two Numbers: \n";
         cin >> num1 >> num2;
         x = num1 * num2;
         cout << "Product = " << x;
         break;

      case 4:
         cout << "Enter Dividend: ";
         cin >> num1;
         cout << "Enter Divisor: ";
         cin >> num2;

         while(num2 == 0)
         {
            cout << "\nDivisor cannot be zero."
                    "\nEnter divisor once again: ";
            cin >> num2;
         }
         x = num1 / num2;
         cout << "\nQuotient = " << x;
         break;

      case 5:
         cout << "Enter any Number: \n";
         cin >> num1;
         x = num1 * num1;
         cout << "Square = " << x;
         break;
      case 6:
         cout << "Enter any Number: \n";
         cin >> num1;
         x = sqrt(num1);
         cout << "Root = " << x;
         break;
      case 7:

         PI = 3.1415926;

         cout << "Enter any Angle: ";
         cin >> num1;
         r= num1 * PI /180;
         y = sin(r);
         cout << "Sin("<< num1 <<")= " << y;
         break;
      case 8:

        PI = 3.1415926;

         cout << "Enter any Angle: ";
         cin >> num1;
         r= num1 * PI / 180;
         y = cos(r);
         cout << "Cos("<< num1 <<")= " << y;
         break;
      case 9:

        PI = 3.1415926;

         cout << "Enter any Angle: ";
         cin >> num1;
         r= num1 * PI /180;
         y = tan(r);
         cout << "Tan("<< num1 <<")= " << y;
         break;


      case 10:
         return 0;

      default: cout << "\nError";
   }

}




int main()
{

   cout << "\n\n****************************************************\n";
   cout << "                     CALCULATOR\n              \n";
       cout << "****************************************************\n";

    int choice,j=1;
    for (int i=1; i<=j; i++)
    {
        init();
        cout << "\n\nEnter The Method Which You Want to do:\n"
             << "\t1. Equation Method"
             << "\t2. Two Digit Method\n"
             << "\tEnter Your Option: ";
        cin >> choice;
        if(choice==1)
            inFix();
        else if(choice==2)
            TwoDigitMethod();
        else
            cout << "\n\n****Wrong Choice**** \n\n";

        cout << "\nDo you want to continue??? y/n: ";
        char C;
        cin >> C;
        if(C=='y' || C=='Y')
            j++;
    }
}

