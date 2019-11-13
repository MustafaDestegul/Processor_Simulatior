#include <iostream>
#include <fstream> // file streams
#include "Stack.h"
#include "Stack.cpp"
#include "Quene.h"   // typo mistake sorry!..it was time consuming to change back it to queue...
#include "Quene.cpp"
#include "Process.h"
#include "Process.cpp"
#include<bits/stdc++.h>  //for exit function




using namespace std;

// function to determine if any process arrives or not...
int CheckForNewArrivalTime(int i,Process& Running_Process, Process& Previous_Process,std::ifstream& infile,std::ofstream& outfile, int &arrTime,int &pID,int &priority,int &runTime){

int InterruptCameOrNot=0;  // output of this function which shows if a new interrupt came or not

       if(!infile.eof()) {

           if (i==arrTime){  // arrival time is equal to the current cycle time.. load the informations to the running process.

outfile<<"t="<<i<<" P"<<pID<<"  Arrives"<<endl;

cout<<"ARRTIME:"<<arrTime<<endl;  // for debug purposes..

                Previous_Process.Set_pID(Running_Process.Get_pID());  // To keep the previous process to compare the priority and stack, Q operations
                Previous_Process.Set_Priority(Running_Process.Get_Priority());  // if a new arrival time is detected then load the current to the previous
                Previous_Process.Set_ArrivalTime(Running_Process.Get_ArrivalTime()); // process, and load the new comer to the running process.
                Previous_Process.Set_Runtime(Running_Process.Get_Runtime());

                Running_Process.Set_pID(pID);               // set new values to the running process while keeping the previous infos in Previous_Process object...
                Running_Process.Set_Priority(priority);
                Running_Process.Set_ArrivalTime(arrTime);
                Running_Process.Set_Runtime(runTime);


               infile >> pID >> priority >> arrTime >> runTime;

            InterruptCameOrNot= 1; // a new arrival time is detected

            }

          else {

            InterruptCameOrNot= 0;  // new arrival time is not detected

          }


       }

   return InterruptCameOrNot;   //  1 if interrupt came else 0.
}

// When running time==0 of a running process this function is called to determine the next operation...
template<class T>
int ComparePrioritiesBetweenStackandQueusChoseTheHigher(std::ofstream& outfile,Stack<T>&S ,Quene<T>&Q1, Quene<T>&Q2, Quene<T>&Q3,T cycle,int priorities[2000][2]){
int a;
int S_peek=S.PeekStack();
int Q1_peek=Q1.PeekQueue();
int Q2_peek=Q2.PeekQueue();
int Q3_peek=Q3.PeekQueue();
int result=0;
int DummyArrayPriority[4];
int N=4;


       // IF THE STACK OR QUEUES ARE EMPTY , THEN NO OPERATİON ON THEM
        if(S_peek==-1){
            DummyArrayPriority[0]=4; }  // since the lowest priority is 3 , writing 4 has no effect (actually there is but ignored for now)
        else{
            DummyArrayPriority[0]=priorities[S_peek][1];}  // PriorityAndRuntime=Results[2000][2]read the stack pID without changing the top variable and find the corresponding priority of the pID then save to the array


        if(Q1_peek==-1){
            DummyArrayPriority[1]=4;}
        else{
            DummyArrayPriority[1]=priorities[Q1_peek][1];}   // read the queue1 pID without changing the front variable  and find the corresponding priority of the pID

        if(Q2_peek==-1){
            DummyArrayPriority[2]=4;}
        else{
            DummyArrayPriority[2]=priorities[Q2_peek][1]; }  // read the queue2 pID without changing the front variable  and find the corresponding priority of the pID

        if (Q3_peek==-1){
            DummyArrayPriority[3]=4;}
        else{
            DummyArrayPriority[3]=priorities[Q3_peek][1];}   // read the queue3 pID without changing the front variable  and find the corresponding priority of the pID



cout<<" DummyArrayPriority[0]:"<< DummyArrayPriority[0]<<endl;  // for debug purposes..

cout<<" DummyArrayPriority[1]:"<< DummyArrayPriority[1]<<endl;  // for debug purposes..

cout<<" DummyArrayPriority[2]:"<< DummyArrayPriority[2]<<endl;  // for debug purposes..

cout<<" DummyArrayPriority[3]:"<< DummyArrayPriority[3]<<endl;  // for debug purposes..
int temp = DummyArrayPriority[0];

            for(int i=0; i<N; i++) {                    // find the smallest value since the smallest one has the higher priority value
                if(temp>=DummyArrayPriority[i]) {
                    temp=DummyArrayPriority[i];         // temp keeps the smallest priority but we need the ID to load the values from the array back to the running process
                }
            }

cout<<"temp"<<temp<<endl;
// find the corresponding pID to call the values BACK stored in the Results[][] array.

   //This is a protection from being cut the program. if this statements read then the programs stops since queues and stacks error functions..

if (S_peek==-1 && Q1_peek==-1 && Q2_peek==-1 && Q3_peek ==-1) {  // if all storage elements are empty then return -1
        result=-1;

}
else if(S_peek==-1){                                         //.   if stack is empty then look at the others no to have error...

                if(temp==priorities[Q1_peek][1]){            // delete the value from the Queue 1 and return in if it has the highest priority
                outfile<<"P"<<Q1_peek<<"  popped from  Q1"<<endl; // write the process to the output file
                result=Q1.QDelete();

                }
                else if(temp==priorities[Q2_peek][1]){             // delete the value from the Queue 2 and return in  if it has the highest priority
                outfile<<"P"<<Q2_peek<<"  popped from  Q2"<<endl; // write the process to the output file
                 result=Q2.QDelete();

                }
                else if(temp==priorities[Q3_peek][1]) {
                outfile<<"P"<<Q3_peek<<"  popped from  Q3"<<endl; // write the process to the output file
                 result=Q3.QDelete();                     // delete the value from the Queue 3 and return in   if it has the highest priority
                }
       }
else if (Q1_peek==-1){                                      //    if q1 is empty then look at the others

                if(temp==priorities[S_peek][1]){                  // Pop values from the stack if the priority is the highest one and return it
                outfile<<"P"<<S_peek<<"  popped from S"<<endl; // write the process to the output file
                result=S.Pop();

                }

                else if(temp==priorities[Q2_peek][1]){             // delete the value from the Queue 2 and return in  if it has the highest priority
                outfile<<"P"<<Q2_peek<<"  popped from  Q2"<<endl; // write the process to the output file
                result=Q2.QDelete();

                }
                else if(temp==priorities[Q3_peek][1]) {
                outfile<<"P"<<Q3_peek<<"  popped from  Q3"<<endl; // write the process to the output file
                result=Q3.QDelete();                     // delete the value from the Queue 3 and return in   if it has the highest priority

            }

        }
else if (Q2_peek==-1){                                    // if q2 is empty then look at the others


                if(temp==priorities[S_peek][1]){                  // Pop values from the stack if the priority is the highest one and return it
                outfile<<"P"<<S_peek<<"  popped from S"<<endl; // write the process to the output file
                result=S.Pop();

                }
                else if(temp==priorities[Q1_peek][1]){            // delete the value from the Queue 1 and return in if it has the highest priority
                outfile<<"P"<<Q1_peek<<"  popped from  Q1"<<endl; // write the process to the output file
                 result=Q1.QDelete();

                }

                else if(temp==priorities[Q3_peek][1]) {
                outfile<<"P"<<Q3_peek<<"  popped from  Q3"<<endl; // write the process to the output file
                 result=Q3.QDelete();                     // delete the value from the Queue 3 and return in   if it has the highest priority

        }



     }
else if(Q3_peek==-1){                                           // if q3 is empty then look at the others

        if(temp==priorities[S_peek][1]){                  // Pop values from the stack if the priority is the highest one and return it
            outfile<<"P"<<S_peek<<"  popped from S"<<endl; // write the process to the output file
                result=S.Pop();

        }
        else if(temp==priorities[Q1_peek][1]){            // delete the value from the Queue 1 and return in if it has the highest priority
            outfile<<"P"<<Q1_peek<<"  popped from  Q1"<<endl; // write the process to the output file
                 result=Q1.QDelete();

        }
        else if(temp==priorities[Q2_peek][1]){             // delete the value from the Queue 2 and return in  if it has the highest priority
            outfile<<"P"<<Q2_peek<<"  popped from  Q2"<<endl; // write the process to the output file
                 result=Q2.QDelete();

        }



     }

else if ((S_peek!=-1) && (Q1_peek!=-1) && (Q2_peek!=-1) && (Q3_peek !=-1)){           // if none of the is empty then look at this part
       if(temp==priorities[S_peek][1]){                  // Pop values from the stack if the priority is the highest one and return it
            outfile<<"P"<<S_peek<<"  popped from S"<<endl; // write the process to the output file
                result=S.Pop();

        }
        else if(temp==priorities[Q1_peek][1]){            // delete the value from the Queue 1 and return in if it has the highest priority
            outfile<<"P"<<Q1_peek<<"  popped from  Q1"<<endl; // write the process to the output file
                 result=Q1.QDelete();

        }
        else if(temp==priorities[Q2_peek][1]){             // delete the value from the Queue 2 and return in  if it has the highest priority
            outfile<<"P"<<Q2_peek<<"  popped from  Q2"<<endl; // write the process to the output file
                 result=Q2.QDelete();

        }
        else if(temp==priorities[Q3_peek][1]) {
            outfile<<"P"<<Q3_peek<<"  popped from  Q3"<<endl; // write the process to the output file
                 result=Q3.QDelete();                     // delete the value from the Queue 3 and return in   if it has the highest priority

        }
}
  // result KEEPS THE pID VALUE OF THE HIGHER PRIORITY PROCESS TO BE LOADED TO THE RUNNING PROCESS. AND THE LATANCY IN THIS FUNCTION WTIH result[2].
                      // result[1]  is for the latency calculation, keeps the passed time in the function
   a=result;
 cout<<"result:"<<a<<endl;

return a;  // result is the pID of the process which has the higher priority,
}




//**********************************MAIN FUNCTION***********************************************//
int main()
{
    Stack <int>S;               // stack object
    Quene <int>Q1;               // queue objects. typo mistake is realized late to be changed.
    Quene <int>Q2;
    Quene <int>Q3;

    Process Running_Process(0,0,0,0,0); // running process object
    Process Previous_Process(0,0,0,0,0); // This process is to keep the values of the current process to load the next process to the running_process object
   // Calculations Results;
    int Results[2000][2]; // will be used as storage element since, when we save pID to a stack or queues, we cannot keep the remaining runtime, and priority.
    int InterruptedRunTimesAndPriority[2000][2]; // when an arrival time is matched with the counter ,Cycle, then we need to save the value to a storage element to compare with the final value to calculate the latency later
//******************************FILE SYSTEM*****************************************
    int pID, priority, arrTime, runTime;

    ifstream infile; // input file stream
    ofstream outfile; // output file stream
    ofstream Latency_output;// ouput latency file

    infile.open("C:/Users/KLAS/Desktop/EE441_C++/EE441_HW1/HW1/input.txt"); // input file is input.txt
    outfile.open("C:/Users/KLAS/Desktop/EE441_C++/EE441_HW1/HW1/output1.txt"); // output file is output.txt
    Latency_output.open("C:/Users/KLAS/Desktop/EE441_C++/EE441_HW1/HW1/Latency1.txt");

    infile >> pID >> priority >> arrTime >> runTime; // read input file for the first input to the system. After taking fist arrival time, I will compare it with the Counter

               Running_Process.Set_pID(pID);               // set new values to the running process while keeping the previous infos in Previous_Process object...
                Running_Process.Set_Priority(priority);
                Running_Process.Set_ArrivalTime(arrTime);
                Running_Process.Set_Runtime(runTime);

//NOTE: SINCE I READ THE FIRST ELEMENT ON THE BEGINNING, THE LAST ELEMENT OF THE INPUT FILE CANNOT BE READ FOR NOW. IT CAN BE SOLVABLE PROBLEM BUT LACK OF TIME...
int NextpID;
int Latency;
int dummycounter=0;
int InterruptArrivedOrNot=0;

for(int Cycle=0;;Cycle+=1){  // if a new arrival time doesn't match with the counter then go if statement and decrease the runtime, else go checking part(else part).

     InterruptArrivedOrNot = CheckForNewArrivalTime(Cycle,Running_Process,Previous_Process,infile,outfile,arrTime,pID,priority,runTime); // any time check any arrival time is reached or not...

  if( InterruptArrivedOrNot == 0) {  // if a new arrival time is not detected

                 dummycounter=dummycounter+1;   // THE COUNTER TO CALCULATE THE RUNNING TIME FOR LATENCY
            cout<<"dummycounter "<<dummycounter<<endl;

                 Running_Process.DecreaseTheRunningProcessRunTimeby1();  // decrease the RUNTIME in each cycle to update the remaining runtime

                cout<<"PROCESS P"<<Running_Process.Get_pID()<<" is running and RUN TIME IS="<<Running_Process.Get_Runtime()<<endl;


                    if(Running_Process.Get_Runtime()==0){   // if a process comes this state, then the arrival time becomes trivial to consider.


                    outfile<<"t="<<Cycle<<"  P"<< Running_Process.Get_pID()<<" is finished"<<endl;



                    NextpID=  ComparePrioritiesBetweenStackandQueusChoseTheHigher<int>(outfile,S,Q1,Q2,Q3,Cycle,InterruptedRunTimesAndPriority);  // compare the priorities and   load the ID of the process which has the highest priority


                    Latency =Cycle-  InterruptedRunTimesAndPriority[Running_Process.Get_pID()][0]; // lATENCY keeps the final value of the process and ınterrupted runtimes keeps the value when is is interrupted

                     Latency_output<<"The latency for P="<<Running_Process.Get_pID()<<"   is"<<Latency<<endl;
        cout<<"Latency is"<<Latency<<endl;
                        if (NextpID==-1){              // when pID becomes -1 then the system stops...
                            cout<<"SYSTEM IS AT IDLE STATE "<<endl;
                            exit(1);
                            }
                        else{

                         //   ACCORDING TO THE NextpID RESULT, LOAD THE  NEW RUNNING PROCESS...
                    Running_Process.Set_pID(NextpID);                   // by the ComparePrioritiesBetweenStackandQueusChoseTheHigher function, I found the highest priority between the Queues and Stack
                    Running_Process.Set_Priority(Results[NextpID][0]);  // then load the proper values to the Running process and continue.
                    Running_Process.Set_Runtime(Results[NextpID][1]);   //result[1] keeps the pID of the running process which will work next
        cout<<"running process is loaded with pID:"<<Running_Process.Get_pID()<<endl; // for debugging
                        }

                }
         }


  else if( InterruptArrivedOrNot== 1){    // If a new arrival time is detected.
                              cout<<"Interrupted came "<<endl;  // for debug

                                InterruptedRunTimesAndPriority[Running_Process.Get_pID()][1]=Running_Process.Get_Priority();
                                InterruptedRunTimesAndPriority[Running_Process.Get_pID()][0]=Running_Process.Get_Runtime();  // saving the values of the interrupted runtime to this array to calculate the latency later above.

                      if((Running_Process.Get_Priority()) < (Previous_Process.Get_Priority())){  // if the priority of the new process is higher(lower number has higher priority) than the previous one, save the
                                        cout<<"priority is higher "<<endl;  // for debug

                                    S.Push(Previous_Process.Get_pID());  // push the previous process to stack

                                    outfile<<"P"<<Previous_Process.Get_pID()<<"  pushed on S with runTime"<<Previous_Process.Get_Runtime()<<endl;

                                    outfile<<"P"<<Running_Process.Get_pID()<<"  preempted the CPU"<<endl;

        cout<<"Process is interrrupted and pID::" <<Previous_Process.Get_pID()<<" is sent to the stack"<<endl;  // for debug



                                    Results[Previous_Process.Get_pID()][0]=Previous_Process.Get_Priority();              // push the preempted process to the stack and load the new process to the running process
                                    Results[Previous_Process.Get_pID()][1]=Previous_Process.Get_Runtime();


                                    Running_Process.Set_pID(Running_Process.Get_pID());          // since the priority levels are the same, store the older ones values to the running process
                                    Running_Process.Set_Priority(Running_Process.Get_Priority());
                                    Running_Process.Set_ArrivalTime(Running_Process.Get_ArrivalTime());
                                    Running_Process.Set_Runtime(Running_Process.Get_Runtime());

        cout<<"Running_Process is set to " <<Running_Process.Get_pID()<<endl;  // for debugging

                           // also save the remaining time and the pID to the 2D array or an object.
                      }
                      else if((Running_Process.Get_Priority()) > (Previous_Process.Get_Priority())){  // if the priority of the new process is lower than the  the previous one, save it to the queues.
                                     cout<<"priority is lower "<<endl;  // for debug
                                    if(Running_Process.Get_Priority()==1){                  // Since the priority level is lower, save the new coming interrupt to the queues
                                        Q1.QInsert(Running_Process.Get_pID());
                                        Results[Running_Process.Get_pID()][0]=Previous_Process.Get_Priority();              // push the preempted process to the Q1 and load the new process to the running process
                                        Results[Running_Process.Get_pID()][1]=Previous_Process.Get_Runtime();
                                cout<<"The Process pID:" <<Running_Process.Get_pID()<<"is sent to Q1"<<endl;     // FOR DEBUGGİNG PURPOSES
                                    outfile<< "P"<<Running_Process.Get_pID()<<"  Pushed on Q1"<<endl;

                                        }
                                    else if (Running_Process.Get_Priority()==2){
                                        Q2.QInsert(Running_Process.Get_pID());
                                        Results[Running_Process.Get_pID()][0]=Previous_Process.Get_Priority();              // push the preempted process to the Q2 and load the new process to the running process
                                        Results[Running_Process.Get_pID()][1]=Previous_Process.Get_Runtime();
                                   cout<<"The Process pID:" <<Running_Process.Get_pID()<<"is sent to Q2"<<endl;
                                     outfile<< "P"<<Running_Process.Get_pID()<<"  Pushed on Q2"<<endl;
                                        }
                                    else if (Running_Process.Get_Priority()==3){
                                        Q3.QInsert(Running_Process.Get_pID());
                                        Results[Running_Process.Get_pID()][0]=Previous_Process.Get_Priority();              // push the preempted process to the Q3 and load the new process to the running process
                                        Results[Running_Process.Get_pID()][1]=Previous_Process.Get_Runtime();
                                   cout<<"The Process pID:" <<Running_Process.Get_pID()<<"is sent to Q3"<<endl;
                                    outfile<< "P"<<Running_Process.Get_pID()<<"  Pushed on Q3"<<endl;
                                        }



                                            Running_Process.Set_pID(Previous_Process.Get_pID());          // since the process will not change at this step, load the previous datas to the running process.
                                            Running_Process.Set_Priority(Previous_Process.Get_Priority());
                                            Running_Process.Set_ArrivalTime(Previous_Process.Get_ArrivalTime());
                                            Running_Process.Set_Runtime(Previous_Process.Get_Runtime());

                        }

                      else                                  // the priorities are the same so we choose the older one to be processed..
                        {
                                cout<<"same priority "<<endl;  // for debug


                                if(Running_Process.Get_pID()>Previous_Process.Get_pID()) {   // bigger pID will be sent to the stacks.
                                     if(Running_Process.Get_Priority()==1){
                                        Q1.QInsert(Running_Process.Get_pID());

                                            outfile<<"P"<<Running_Process.Get_pID()<<"  pushed on Q1 "<<endl;
                                    InterruptedRunTimesAndPriority[Running_Process.Get_pID()][1]=Running_Process.Get_Priority();  // set the priorities of each ID to be fetch in comparison part...

                                   //    Results[Running_Process.Get_pID()][0]=Previous_Process.Get_Priority();              // push the preempted process to the Q3 and load the new process to the running process
                                        Results[Running_Process.Get_pID()][1]=Previous_Process.Get_Runtime();
                                        Running_Process.Set_pID(Previous_Process.Get_pID());
                                        Running_Process.Set_Priority(Previous_Process.Get_Priority());
                                        Running_Process.Set_Runtime(Previous_Process.Get_Runtime());

                                    }

                                    else if(Running_Process.Get_Priority()==2) {

                                        Q2.QInsert(Running_Process.Get_pID());
                                            outfile<<"P"<<Running_Process.Get_pID()<<"  pushed on Q2 "<<endl;
                                        cout<< "Q2 PEEK VALUE SHOULD BE 5*********************"<<Q2.PeekQueue()<<endl;

                                       InterruptedRunTimesAndPriority[Running_Process.Get_pID()][1]=Running_Process.Get_Priority();
                                   //     Results[Running_Process.Get_pID()][0]=Previous_Process.Get_Priority();              // push the preempted process to the Q3 and load the new process to the running process
                                        Results[Running_Process.Get_pID()][1]=Previous_Process.Get_Runtime();
                                        Running_Process.Set_pID(Previous_Process.Get_pID());
                                        Running_Process.Set_Priority(Previous_Process.Get_Priority());
                                        Running_Process.Set_Runtime(Previous_Process.Get_Runtime());

                                    }
                                     else if(Running_Process.Get_Priority()==3) {

                                        Q3.QInsert(Running_Process.Get_pID());
                                            outfile<<"P"<<Running_Process.Get_pID()<<"  pushed on Q3 "<<endl;
                                       InterruptedRunTimesAndPriority[Running_Process.Get_pID()][1]=Running_Process.Get_Priority();
                                     Results[Running_Process.Get_pID()][0]=Previous_Process.Get_Priority();              // push the preempted process to the Q3 and load the new process to the running process
                                //       Results[Running_Process.Get_pID()][1]=Previous_Process.Get_Runtime();
                                        Running_Process.Set_pID(Previous_Process.Get_pID());
                                        Running_Process.Set_Priority(Previous_Process.Get_Priority());
                                        Running_Process.Set_Runtime(Previous_Process.Get_Runtime());

                                    }


                                }







                        }

                }

          }




    infile.close(); // close the files
    outfile.close(); // AT THE END SAVE THE LOG TO THE OUTPUT FILE AND ACTIVATE THÝS LINE AT THE END
    Latency_output.close();




    return 0;
}

