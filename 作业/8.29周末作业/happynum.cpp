#include <iostream>
#include <cstring>
class HappyNum
{
public:
    int *arr = new int[20];
    int n;
    int count = 0;
    ~HappyNum() { delete[] arr; }
    bool JudgeHappyNum(int n)
    {
        while (n != 1 && count < 20)
        {
            int len = 0;
            int temp1 = n;
            while (temp1 > 0)
            {
                arr[len] = temp1 % 10;
                len++;
                temp1 /= 10;
            }
            int temp2 = 0;
            for (int j = 0; j < len; j++)
            {
                temp2 += (arr[j] * arr[j]);
            }
            std::cout << "第 " << count << " 轮计算结果，计算结果为：" << temp2 << '\n';
            n = temp2;
            count++;
        }
        return n == 1;
    }
};

int main()
{
    HappyNum a;
    int test = 19;
    if (a.JudgeHappyNum(test))
    {
        std::cout << test << "是快乐数" << std::endl;
    }
    else
    {
        std::cout << test << "不是快乐数" << std::endl;
    }
    return 0;
}

//  bool JudgeHappyNum(int n)
//     {
//         {
//             {
// 把整数的数字拆成一维数组
// for (int i = 0; temp1 == 0; i++)
// {
//     temp1 = n % 10;
//     arr[i] = temp1;
//     n /= 10;
// 一维数组每一位平方后相加
//     int len = strlen(arr);
//     for (int j = 0;j < len; j++)
//     {
//         temp2 = (arr[j] * arr[j]) + temp2;
//         std::cout<<"第 "<<count<<" 轮计算结果，计算结果为："<<temp2<<'\n';
//         count++;
//     }
//     if (temp2 == 1)
//         return 1;
//     else
//         n = temp2;
//             }
//         }
//     }
//     if (count == 20)
//         return 0;
// }