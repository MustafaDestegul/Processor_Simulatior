#ifndef PROCESS_H_INCLUDED
#define PROCESS_H_INCLUDED


// there will be 6 running process objects for the proper operation
class Process    // a pointer can be used to access to this class LUCTURE NOTES 5  look at it .
{
    private:
    int pID;
    int Priority;
    int Runtime;
    int Arrivaltime;
    int Counter;

    public:
// Constructor
    Process(int pIDx, int Priorityx, int Arrivaltimex, int Runtimex,int Counterx);
// int  IDLE_No_Process(); will be ýn the controller...
// setter of the current process
    void Set_Counter(int i);
    void Set_pID(int x);
    void Set_Priority(int x);
    void Set_Runtime(int x);
    void Set_ArrivalTime(int x);
// getter of the current process results
    int Get_Counter();
    int Get_pID();
    int Get_Priority();
    int Get_Runtime();
    int Get_ArrivalTime();
    void DecreaseTheRunningProcessRunTimeby1();



};

#endif // PROCESS_H_INCLUDED
