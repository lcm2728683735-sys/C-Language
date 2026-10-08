#include <iostream>
#include <vector>
#include <algorithm>

class Sort
{
public:
    virtual void sort(std::vector<int> &v) = 0;
};

class BubbleSort:public Sort
{
public:
    virtual void sort(std::vector<int> &v)
    {
        std::cout << "冒泡排序\n";
        for(int i = 0; i< v.size()-1;i++)
        {
            for(int j = 0; j < v.size() - i-1; j++)
            {
                if(v[j] > v[j+1])
                    std::swap(v[j],v[j+1]);
            }
        }
    }
};

class FastSort : public Sort
{
public:
    virtual void sort(std::vector<int> &v)
    {
        std::cout<<"快速排序\n";
        std::sort(v.begin(), v.end());
    }
};

void MySort(std::vector<int> &v, Sort *s)
{
    s->sort(v);
}

int main ()
{
    Sort *s = new FastSort;
    std::vector<int> v = {5,3,1,4,2};
    MySort(v,s);
    std::for_each(v.begin(),v.end(),[](int a){std::cout<<a <<" ";});
    std::cout<<std::endl;
    return 0;
}