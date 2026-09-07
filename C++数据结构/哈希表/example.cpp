#include <iostream>
int Hash(char i)
{
    return i - 'a';
}

int main ()
{
    std::string s1 = "hash";
    std::string s2 = "haha";
    int hash1[26] = {0};
    int hash2[26] = {0};

    for(int i = 0;i < s1.size(); i++)
    {
        hash1[Hash(s1[i])]++;
        hash2[Hash(s2[i])]++;
    }
    int count = 0;
    for(int i = 0;i < 26; i++)
    {
        if(hash2[i] > hash1[i])
            count += hash2[i]-hash1[i];
    }
    std::cout<< count <<std::endl;
    return 0;
}