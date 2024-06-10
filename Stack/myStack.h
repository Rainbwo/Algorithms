#ifndef _MY_STACK_H_
#define _MY_STACK_H_
#include <stack>


class myStack
{
private:

    std::stack<int> *StackData;
    std::stack<int> *StackMin;


public:
    myStack(/* args */);
    ~myStack();

    int getMin(void);
    void push(int data);
    int pop(void);
};


myStack::myStack(/* args */)
{
    StackData = new std::stack<int>;
    StackMin  = new std::stack<int>;
}

myStack::~myStack()
{
    delete StackData;
    delete StackMin;
}





#endif