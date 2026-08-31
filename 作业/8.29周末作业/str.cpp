#include <iostream>

class Str
{
public:
    int SearchSonStr(const int *str, int size, int k)
    {
        int sum = 0;
        int minlength = size + 1;
        int left = 0;
        for (int right = 0; right < size; right++)
        {
            sum += str[right];
            while (sum >= k)
            {
                int length = right - left + 1;
                if (length < minlength)
                {
                    minlength = length;
                }
                sum -= str[left];
                left++;
            }
        }
        if (minlength == size + 1)
        {
            return 0;
        }
        return minlength;
    }
};

int main()
{
    Str str;
    int a[] = {2, 3, 1, 2, 4, 3};
    int b[] = {1, 4, 4};
    int c[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};

    int result = str.SearchSonStr(b,3,4);
    std::cout<<"结果为: "<<result<<"\n";
    return 0;
}