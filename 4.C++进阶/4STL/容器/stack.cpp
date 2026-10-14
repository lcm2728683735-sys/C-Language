#include <iostream>
#include <stack>

class MyQueue
{
public:
    MyQueue(){}
    void Push(int value)
    {
        while(s2.empty() == false)
        {
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(value);
    }
    void Pop()
    {
        while(s1.empty() == false)
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
    }
    bool Isempty()
    {
        return s1.empty() && s2.empty();
    }
    int Getfront()
    {
        while(s1.empty() == false)
        {
            s2.push(s1.top());
            s1.pop();
        }
        return s2.top();
    }
private:
    std::stack<int> s1;
    std::stack<int> s2;
};

int main()
{
    MyQueue q;
    q.Push(1);
    q.Push(2);
    std::cout << q.Getfront() << std::endl;
    q.Push(3);
    q.Pop();
    std::cout << q.Getfront() << std::endl;
    return 0;
}