#include <iostream>
#include <cstring>

int Sum(int *nums,int length,int k)
{
    if(nums == NULL)
        return 0;
    if(length < 0)
        return 0;
    int left = 0;
    int right = 0;
    int sum = nums[0];
    int count = 0;
    while(left<= right&& right<length)
    {
        if(sum <= k)
        {
            if(sum == k)
                count++;
            right++;
            if (right<length)
            sum += nums[right]; 
        }
        else if(sum > k)
        {
            sum -= nums[left];
            left++;
        }
    }
    return count;
}

int main()
{
    int a[] = {1,2,3};
    std::cout << Sum(a, sizeof(a) / sizeof(int), 3) << std::endl;
    return 0;
}