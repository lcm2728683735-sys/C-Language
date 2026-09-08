#include <iostream>
#include <string>

class str
{
public:
    std::string IsPalind(const std::string a)
    {
        int maxlen = 0;
        int start = 0;
        for (int i = 0; i < a.size(); i++)
        {
            int temp1 = 0;
            // 奇数
            int n = 1;
            while (i - n >= 0 && n + i < a.size()&&a[i - n] == a[i + n])
            {
                temp1++;
                n++;
            }
                int len1 = 2 * temp1 + 1;
                if (len1 > maxlen)
                {
                    maxlen = len1;
                    start = i - temp1;
                }

            // 偶数
            int temp2 = 0;
            int j = 0;
            while (i-j >= 0 && j + i + 1 < a.size()&&a[i + 1- j] == a[i + j])
            {
                temp2++;
                j++;
            }

                int len2 =  2 * temp2;

                if (len2 > maxlen)
                {
                    maxlen = len2;
                    start = i - temp2 + 1;
                }
        }
        return a.substr(start,maxlen);
    }

private:
    std::string a;
};

int main()
{
    str str;

    std::string s = "ababa";
    std::cout << str.IsPalind(s)<<"\n";
    return 0;
}
