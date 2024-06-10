#ifndef _TWO_STACK_QUEUE_H_
#define _TWO_STACK_QUEUE_H_
#include <stack>


class TwoStackQueue
{
private:
    /* data */
    std::stack<int>* StackPush;
    std::stack<int>* StackPoll;

public:
    TwoStackQueue(/* args */);
    ~TwoStackQueue();

    void add(int data);
    void poll(void);
    int peek(void);
};

TwoStackQueue::TwoStackQueue(/* args */)
{
    StackPush = new std::stack<int>;
    StackPoll = new std::stack<int>;
}

TwoStackQueue::~TwoStackQueue()
{
}

inline void TwoStackQueue::add(int data)
{
    StackPush->push(data);
}

inline void TwoStackQueue::poll(void)
{
    if(StackPoll->empty())
    {
        if(StackPush->empty())
        {
            return;
        }
        while(!StackPush->empty())
        {
            StackPoll->push(StackPush->top());
            StackPush->pop();
        }
        StackPoll->pop();
        while(!StackPoll->empty())
        {
            StackPush->push(StackPoll->top());
            StackPoll->pop();
        }
    }
    return;
}

inline int TwoStackQueue::peek(void)
{
    int data = 0;
    if(StackPoll->empty())
    {
        if(StackPush->empty())
        {
            return;
        }
        while(!StackPush->empty())
        {
            StackPoll->push(StackPush->top());
            StackPush->pop();
        }
        data = StackPoll->top();
        while(!StackPoll->empty())
        {
            StackPush->push(StackPoll->top());
            StackPoll->pop();
        }
    }
    return data;
}

#endif