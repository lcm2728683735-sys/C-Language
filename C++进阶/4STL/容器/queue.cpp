#include <iostream>
#include <queue>


class MyStack
{
public:
    template<typename T>
    void Print(const T &v)
    {
        for(auto ite = v.begin(); ite != v.end(); ite++)
        {
            std::cout << *ite <<" "; 
        }
        std::cout << std::endl;
    }
    MyStack(){}
    void Push(int value)
    {
        if(q1.empty() == false)
            q1.push(value);
        else    
            q2.push(value);
    }
    void Pop()
    {
        if(q1.empty() == false)
        {
            while(q1.size() != 1)
            {
                q2.push(q1.front());
                q2.pop();
            }
            q2.pop();
        }
    }
    int GetTop()   
    {
        int result = 0; 
        if(q1.empty() == false)
        {
            while(q1.size() != 1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            result = q1.front();
            q2.push(result);
            q1.pop();
            return result;
        }
        else
        {
            while(q2.size() != 1)
            {
                q1.push(q1.front());
                q2.pop();
            }
            result = q2.front();
            q1.push(result);
            q2.pop();
            return result;
        }
    }
private:
    std::queue<int> q1;
    std::queue<int> q2;
};

int main()
{
    MyStack s;   // 实例化一个 MyStack 对象

    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);

    std::cout << s.GetTop() << std::endl;  
    s.Pop();
    std::cout << s.GetTop() << std::endl;  
    s.Pop();
    std::cout << s.GetTop() << std::endl;  
    return 0;
}