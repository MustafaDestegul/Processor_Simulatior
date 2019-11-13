#include <iostream>
//#include<bits/stdc++.h>
#include "Process.h"


using namespace std;


Process::Process(int pIDx, int Priorityx, int Runtimex, int Arrivaltimex, int Counterx){

    pID=pIDx;
    Priority=Priorityx;
    Arrivaltime=Arrivaltimex;
    Runtime=Runtimex;
    Counter=Counterx;
}


void Process::Set_Counter(int i)
{
    Counter=i;

}

void Process::Set_pID(int x)
{
    pID=x;
}

void Process::Set_Priority(int x)
{
    Priority=x;
}

void Process::Set_ArrivalTime(int x)
{
    Arrivaltime=x;
}


void Process::Set_Runtime(int x) // check it later in terms of pass by reference
{
   Runtime=x;
}


// GETTER FUNCTIONS

int Process::Get_pID()
{
    return pID;
}

int Process::Get_Priority()
{
    return Priority;
}

int Process::Get_ArrivalTime()
{
   return  Arrivaltime;
}


int Process::Get_Runtime()
{

   return Runtime;
}

int Process::Get_Counter()  // Change the current counter according to the process
{
  return Counter;
}


void Process::DecreaseTheRunningProcessRunTimeby1(){

  Runtime=Runtime -1;

}


