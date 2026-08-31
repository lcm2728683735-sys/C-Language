#include <iostream>
#include <cstring>

int Sum(int *arr, int len, int k)
{
    if (arr == NULL)
        return 0;
    if (len < 0)
        return 0;
    int left = 0;
    int right = 0;
    int sum = arr[0];
    int count = 0;
    //std::cout << "left:" << left << " right:" << right << " sum:" << sum  << std::endl;
    while (left <= right && right < len)
    {
        if(sum <= k)
        {
            if(sum == k)
                count++;
            right++;
            if(right < len)
                sum += arr[right];
        }
        else if(sum > k)
        {
            sum -= arr[left];
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