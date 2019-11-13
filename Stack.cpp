
#include <iostream>
#include<bits/stdc++.h>
#include "Stack.h"

using namespace std;

template<class T>   // CONSTRUCTOR
Stack<T>::Stack(void):top (-1) {}


template<class T>   //PUSH
void Stack<T>::Push(const T& item)
 {
     if (top==MaxStackSize-1)  //CHECH IF THE STACK IS EXCEED OR NOT
     {
            cerr<< "STACK OVERFLOW!"<<endl;
            exit(1);
     }

     top++;
     StackList[top]=item;   // PUSH THE ITEM

}

template<class T>
T Stack<T>::Pop(void)
{

    T temp;
    if(top==-1)  // CHECKTHE STACK ÝS EMPTY OR NOT
    {
    cerr<<"STACK EMPTY!"<<endl;
    exit(1);
    }
    temp=StackList[top]; // LOAD THE TOP ITEM TO THE TEMP
    top--;               // DECREASE THE TOP
    return temp;

}



template<class T>
T Stack<T>::PeekStack(void)
{

   int temp;

   if(top==-1)  // CHECKTHE STACK IS EMPTY OR NOT
    temp=-1;
   else
   temp=StackList[top];

    return temp;

}
