#include <iostream>
#include "Quene.h"
#include<bits/stdc++.h>

using namespace std;


template<class T>   // INITIALIZE QUENE1 FRONT, REAR AND COUNT
Quene<T>::Quene(void): front(0),rear(0),count(0) {}

template<class T>
void Quene<T>::QInsert(const T& item) // INSERTS NEW ITEMS INTO THE QUENE
{
 if(count==MaxQsize)
{
   cerr<<"QUENE OVERFLOW!"<<endl;
   exit(1);
}

// increment counter , assign item to the qlist and update the rear
count++;
qlist[rear]=item;
rear= (rear+1)% MaxQsize;
}

template<class T>  // delete elemet from the front of the quene and return its value
T Quene<T>::QDelete(void)
{
    T temp;
    // if q1 is empty terminate the program
    if(count==0)
   {
       cerr<<"DELETING FROM AN EMPTY QUENE!"<<endl;

    }
     // record the value at the front of the quene
     temp=qlist[front];

     // decrement the count , advance front and return former front
      count --;
      front= (front+1) % MaxQsize;

      return temp;
}

template<class T>  // check the queues value for the checking purposes in the main....
T Quene<T>::PeekQueue(void)
{

     T temp;
 if(count==0)
    temp =-1;
 else
     temp=qlist[front];
return temp;
}
