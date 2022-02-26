#include <stack>

class MyQueue 
{
private:
    std::stack<int> stack1, stack2;
public:
    MyQueue() {}
    
    void push(int x) 
    {
        stack2.push(x);
    }
    
    int pop() 
    {
        if (!stack1.size())
        {
            while (stack2.size())
            {
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
        int temp = stack1.top();
        stack1.pop();
        return temp;
    }
    
    int peek() 
    {
        if (!stack1.size())
        {
            while (stack2.size())
            {
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
        int temp = stack1.top();
        return temp;
    }
    
    bool empty() 
    {
        return (stack1.size() + stack2.size() == 0);
    }
};