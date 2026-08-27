#include <iostream>
#include <cstring>

void Sum(const char arr[],int k)
{
    int size  = strlen(arr);
    int count = 0;
    for(int i=0;i<size-1;i++)
    {
        if(arr[i] + arr[i+1] == k)
            count++;
    }
    std::cout<<count<<'\n'<<std::endl;
}


int main ()
{
    char a[3] = {1,2,3};
    char b[3] = {1,1,1};
    Sum(a,3);
    return 0;
}