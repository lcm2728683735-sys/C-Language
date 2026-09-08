#include <iostream>
#include <string>
int Hash(char i)
{
    return i -'a';
}

bool IsSamStr(std::string a,std::string b)
{
    int hash1[26] = {0};
    int hash2[26] = {0};
    for(int i = 0;i < a.size(); i++)
    {
        hash1[Hash(a[i])]++;
        hash2[Hash(b[i])]++;
    }
    for(int i = 0;i < 26;i++)
    {
        if(hash1[i] != hash2[i])
            return false;
    }
    return true;
}

int main ()
{
    std::string s1 = "eat";
    std::string s2 = "ate";
    std::string s3 = "happy";
    std::string s4 = "apply";
    std::cout<<IsSamStr(s3,s4)<<std::endl;
    return 0;
    
}