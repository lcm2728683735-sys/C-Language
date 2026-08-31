#include <iostream>
class HalfSearch
{
public:
    int Search(const int *arr, int size, int target)
    {
        int left = 0;
        int right = size - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target)
            {
                return mid;
            }
            arr[mid] > target ? right = mid - 1 : left = mid + 1;
        }
        return -1;
    }
};

int main()
{
    HalfSearch test;
    int arr[] = {0, 3, 5, 9, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 3;
    std::cout << "结果为：" << test.Search(arr, size, target) << std::endl;
    return 0;
}