#include "myStack.h"


void myStack::push(int Data)
{
    if(StackMin->empty())
    {
        StackData->push(Data);
        StackMin->push(Data);
    }
    else
    {
        int data = StackMin->top();
        if(Data <= data)
        {
            StackData->push(Data);
            StackMin->push(Data);
        }
        else
        {
            StackData->push(Data);
        }

    }
    
}


int myStack::pop(void)
{
    int data = StackData->top();
    if(data == StackMin->top())
    {
        StackData->pop();
        StackMin->pop();
    }
    else if(data > StackData->top())
    {
        StackData->pop();
    }
    return data;
}


int myStack::getMin(void)
{
    if(!StackMin->empty())
    {
        return StackMin->top();
    }
}