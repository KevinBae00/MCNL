#include <iostream>
using namespace std;

# define Max 10000
class stack
{
private:
    /* data */
    int top;
    int max_size;

public:
    stack(/* args */);
    ~stack();
    void push(int x);
    int pop();
    int size();
    bool empty();
    int return_top();

};

stack::stack(/* args */)
{
    top=-1;
}

stack::~stack()
{
}
