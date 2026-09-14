#include <stdio.h>
#include <string.h>
void SimStrPre(char *a[])
{
    int len =sizeof(a);
    char Sim = '\0';
    char temp = a[0][0];
    for(int i =1;i<len;i++)
    {
        if(temp =='\0')
            return """";
        if(temp == a[i][0])
        {
            temp = a[i][0];
        }
        // else
        
    }
}
int main()
{
    return 0;
}