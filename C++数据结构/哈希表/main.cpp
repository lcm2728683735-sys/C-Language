#include <iostream>
#include <string>
#include "HashMap.h"

void MaxHeap(std::string& s,int n,int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int max = i;
    if(left < n && s[left] > s[i])
    {
        max = left;
    } 
    if(right < n && s[right] > s[max])
    {
        max = right;
    }
    if(max != i)
    {
        std::swap(s[i],s[max]);
        MaxHeap(s,n,max);
    }
}

void Sort(std::string & s)
{
    int n = s.size();
    for(int i = n /2 - 1;i >= 0;i--)
    {
        MaxHeap(s,n,i);
    }
    for(int i = n - 1; i >= 0;i--)
    {
        std::swap(s[0],s[i]);
        MaxHeap(s,i,0);
    }
}
int main()
{
    //字母异位词
    HashMap m(100);
    // m["zhangsan"]=100;
    // m["lisi"]=90;
    // m["wangwu"]=80;
    // m["zhaoliu"] = 95;
    // m.Remove("lisi");
    // m.Remove("zhangsan");
    // m.show(); 
    // std::cout << *m.Get("wangwu") << std::endl;

    std::string s[] = {"eat","ate","tan","tea","nat","bat"}; 
    for(int i = 0;i < 6;i++)
    {
        std::string temp = s[i];
        Sort(temp);
        m.Insert(temp,s[i]);
    }

    m.showByGroup();
     
    return 0;
}