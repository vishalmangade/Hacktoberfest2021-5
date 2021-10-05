#include <iostream>
using namespace std;
class Stack
{
    int
        *ptr;
    int
        size;
    int top;

public:
    Stack();
    Stack(int);
    ~Stack();
    void
    push(int);
    int
    pop();
    bool isempty() const;
    bool isfull() const;
};

Stack::Stack() : Stack(25)
{
}
Stack::Stack(int n)
{
    size =
        n;
    top =
        -1;
    ptr = new int[size];
}
Stack::~Stack()
{
    delete[] ptr;
    ptr =
        nullptr;
}
void Stack::push(int element)
{
    if (isfull())
    {
        cout << "STACK OVERFLOW" << endl;
        return;
    }
    ptr[++top] = element;
}
int Stack::pop()
{
    if (isempty())
    {
        cout << "STACK UNDERFLOW" << endl;
        return '$';
    }
    return ptr[top--];
}
bool Stack::isempty() const
{
    return top == -1;
}
bool Stack::isfull() const
{
    return top == size - 1;
}
