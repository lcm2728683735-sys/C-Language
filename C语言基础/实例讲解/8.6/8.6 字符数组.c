#include <stdio.h>
#include <string.h>
int main ()
{
    // char *s ="helloworld";
    // printf("%c\n",*(s+1));
    // char a[10] = "hello";
    // printf("%s\n",a+1);
 
    // char b[] ="helloworld";
    // printf("%ld\n",strlen(b));
    // printf("%ld\n",sizeof(b));
    
    char s1[11] = "helloworld";
    char * s3 = s1;
    char s2[11] = "world";
    // printf("%d\n",strncmp(s1,s2,4));
    // strncpy(s2,s1,sizeof(s2)-1); 
    // printf("%s\n,%s\n",s1,s2);
    // strcat(s1,s2);
    // printf("%s\n",s1);
    // printf("%s\n",strstr(s1,s2));
    char c[] = "tom,mike,jarry";
    char *dest =  strtok(c,",");
    for (int i = 0; i < sizeof(c);i++)
    {
        printf("%c %d\n",c[i],c[i]);
    }
    printf("%s\n",dest); 
    dest = strtok(NULL,",");
    printf("%s\n",dest);
    return 0;
}