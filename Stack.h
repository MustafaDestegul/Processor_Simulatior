#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

const int MaxStackSize=2;
template<class T>
class Stack
{
    private:
        T StackList[MaxStackSize];
        int top;
    public:
        Stack(void);               // constructor to initialize the top
        void Push(const T& item); // Push item to the stack
        T Pop(void);             // Pop item to the stack
        void ClearStack(void);  // Just copy the item without modifying stack contents
        T PeekStack(void);    // Check stack state returns top element value without removal.
        int StackEmpty(void) const; // returns true if the stack is empty
        int StackFull(void) const;  // returns true if the stack is full

};


#endif // STACK_H_INCLUDED
