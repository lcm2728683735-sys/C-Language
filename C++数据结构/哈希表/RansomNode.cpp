#include <iostream>
#include <string>

int Hash(char i)
{
    return i - 'a';
}

bool canConstruct(std::string& ransomNote,std::string& magazine)
{
    int hash[52] = {0};
    for(int i = 0;i < ransomNote.size();i++)
    {
        hash[Hash(magazine[i])]++;
    }
    for(int i = 0;i < magazine.size();i++)
    {
        hash[Hash(magazine[i])]--;
    }
    for(int i = 0;i < 26;i++)
    {
        if(hash[i] > 0)
            return false;
    }
    return true;
}

int main ()
{
    std::string s1 = "aab";
    std::string s2 = "aabb";  
    std::cout<<canConstruct(s1,s2)<<"\n"<<std::endl;
    return 0;
}