#include <iostream>
#include <algorithm>
#include <list>
#include <vector> 
#include <time.h>
using namespace std;

template<typename Container,typename T>
void Remove(Container& v,const T&value)
{
    for(auto ite = v.begin(); ite != v.end();)
    {
        if(*ite == value)
            ite = v.erase(ite);
        else
            ite++;
    }
}

template<typename Iterator>
void RandomShuffle(Iterator start,Iterator end)
{
    for(auto i = start + 1; i != end;i++)
    {
        auto j = start +  std::rand() % (i - start +1);
        if(i != j)
            swap(*i,*j);
    }
}

int main()
{
    // vector<int> v = {1,2,3,3,3,4,5};
    // vector <int> v2 ={5,3,2};
    //迭代器遍历整个容器
    // for_each(v.begin(),v.end(),[](int a)
    //         {cout << a << " ";});
    // cout << endl;

    //计算元素个数
    // cout << count(v.begin(),v.end(),5) << endl;
    //条件统计
    // cout << count_if(v.begin(),v.end(),[](int a)
    //             { return a % 2 != 0;})
    //     <<endl;
    //找出最小元素
    // cout << *min_element(v.begin(),v.end()) << endl;
    // cout << *max_element(v.begin(),v.end()) << endl;

    //find 找不到返回 end()
    // auto ite = find(v.begin(), v.end(), 3);
    // if(ite != v.end())
    // {
    //     cout << *ite << endl;
    // }
     

    // auto ite = search_n(v.begin(), v.end(), 1,2);
    // cout <<*ite <<endl; 
    //在前一个区间找后一个区间  ,返回找到位置的迭代器
    
    //滑动窗口，搜索子区间第一次出现的位置
    // auto ite = search(v.begin(),v.end(),v2.begin(),v2.end());
    //反向search   
    // auto ite = find_end(v.begin(),v.end(),v2.begin(),v2.end());
    // cout << *ite <<endl;
    //在第一个区间中找到第二个区间中第一次出现的元素
    // auto ite = find_first_of(v.begin(),v.end(),v2.begin(),v2.end());
    // cout << *ite << endl;
    //找连续两个相等的元素
    // auto ite = adjacent_find(v.begin(),v.end());
    // cout << *ite << endl;
    //判断元素是否都相等
    // cout <<equal(v.begin(),v.end(),v2.begin(),v2.end())<<endl;

    // string s1 = "hello";
    // string s2 = "hollo";
    // 找到不同的元素 
    // auto pair = mismatch(s1.begin(),s1.end(),s2.begin(),s2.end());
    // cout << *pair.first << " " << *pair.second << endl;   


    // vector<int> v = {1,2,3,4,5};
    // list<int> l;
    // l.resize(v.size());

    // transform(v.begin(),v.end(),l.begin(),[](int a)
    //             { return a * 2;});

    //从前往后拷贝某区间
    // copy(v.begin(),v.end(),l.begin());
    //从后往前拷贝某区间
    // copy_backward(v.begin(),v.end(),l.end());
    //变动并且复制元素，将区间元素合并
    // vector <int> v2;
    // v2.resize(v.size() + l.size());    
    // merge(v.begin(),v.end(),l.begin(),l.end(),v2.begin());
    //替换所有元素
    // fill(v.begin(),v.end(),0)
    //替换n个元素
    // fill_n(l.begin(),3,0);
    //以某个操作结果替换每一个值
    // int a;
    // generate(v.begin(),v.end(),[&a](){return ++a;});
    //以某个操作结果替换n个值
    // vector<int> v = {1,1,2,3,4,5};
    // vector<int> v2;
    // v2.resize(v.size());
    //替换某个值
    // replace(v.begin(),v.end(),1,99);
    // 原修改后塞入新的容器
    // replace_copy(v.begin(),v.end(),v2.begin(),1,99);
    // replace_if(v.begin(),v.end(),[](int a){return a < 4},99)
    // replace_copy_if(v.begin(),v.end(),v2.begin(),[](int a){return a < 4},99)
    // for_each(v.begin(),v.end(),[](int &a)
    //              {cout << a << " ";});
    // cout <<endl;
    // for_each(v2.begin(),v2.end(),[](int &a)
    //              {cout << a << " ";});
    // cout <<endl;

    // vector<int> v = {1,2,3,4,5};
    //移除
    // Remove(v,1);
    //逆序
    // reverse(v.begin(),v.end());
    //旋转元素次序
    // rotate(v.begin(),v.begin()+2,v.end()); 
    //全排列 数列从大到小，小到大所有情况
    // prev_permutation(v.begin(),v.end());
    // srand(time(nullptr));
    // random_shuffle(v.begin(),v.end());
    //改变元素次序，符合条件向前移动，不稳定(元素相对位置变化)
    //稳定版本
    // stable_partition(v.begin(),v.end(),[](int a)
    //         {return a & 2 == 0;});
    //size < 15 插入
    //     > 15 分组插入   归并
    //从大到小，小到大排序(堆排序)
    //稳定版（归并排序）
    // vector<int> v= {2,1,5,3,4};
    // sort(v.begin(),v.end(),std::less<int>());
    //排序，直到前n个元素就位
    // partial_sort(v.begin(),v.begin()+2,v.end());
    //只排第n个元素
    // nth_element(v.begin(),v.begin()+2,v.end());
    //构建堆   less 最大堆，greater最小堆
    // make_heap(v.begin(),v.end(),std::greater<int>());
    //将一个元素加入一个堆
    // v.push_back(12);
    // push_heap(v.begin(),v.end());
    //根塞到最后
    // pop_heap(v.begin(),v.end());
    //堆排序
    // sort_heap(v.begin(),v.end());
    // for_each(v.begin(),v.end(),[](int &a)
    //             {cout << a << " ";});
    // cout <<endl;

    // vector<int> v = {1,2,2,2,3,4,5};
    // vector<int> v2 = {1,2};
    //二分查找
    // cout<< binary_search(v.begin(),v.end(),2) << endl;
    //判断子区间
    // cout<< includes(v.begin(),v.end(),v2.begin(),v2.end())<<endl;
    //找大于等于给定值
    // cout << *lower_bound(v.begin(),v.end(),2)<<endl; 
    //找大于给定值
    // cout << *upper_bound(v.begin(),v.end(),2)<<endl;
    //返回等于给定值的所有元素构成的区间
    // auto pair = equal_range(v.begin(),v.end(),2);
    // cout << distance(v.begin(),pair.first)<<endl;
    // cout << distance(v.begin(),pair.second)<<endl;

    vector<int> v1 = {1,2,3,1,2,4};
    vector<int> v2 = {2,3,4};
    vector<int> result;
    result.resize(v1.size() + v2.size());
    //并集
    // set_union(v1.begin(),v1.end(),v2.begin(),v2.end(),result.begin());
    //交集
    // set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),result.begin());
    //补集
    // set_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),result.begin());
    //对称差集(并集减去交集)
    // set_symmetric_difference(v1.begin(),v1.end(),v2.begin(),v2.end(),result.begin());
    inplace_merge(v1.begin(),v1.begin()+ 3,v1.end());
    for_each(v1.begin(),v1.end(),[](int &a)
                {cout << a << " ";});
    return 0;
}

