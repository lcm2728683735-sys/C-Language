#include <iostream>
#include <stack>

int partition(int *array,int  start ,int end)
{
    int left = start;
    int right = end;
    int temp = array[start];
    while(left < right)
    {
        while(array[right] > temp && left < right)
        {
            right--;
        }
        if(left < right)
            array[left++] = array[right];
        
        while(array[left] < temp && left < right)
        {
            left++;
        }
        if(left < right)
            array[right--] = array[left];
        
    }
    array[left] = temp;
    return left;
}


void FastSort(int * array,int n)
{
    if(n<=1)
        return;
    std::stack<std::pair<int,int>> s;
    s.push({0, n- 1});

    while(!s.empty())
    {
        auto [start,end] = s.top();
        s.pop();

        if(start >= end) continue;

        int pivot = partition(array,start,end);

        s.push({start,pivot - 1});
        s.push({pivot + 1,end});
    }

}
int main ()
{
    int arr[] = {7,3,5,9,2,4,1,8,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    FastSort(arr,n);
    for(int i = 0;i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
    return 0;
}