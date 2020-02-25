#include <cstring>

const char LEN = 26;

static inline char add(char x,char dist)
{
    if(x<='Z')  return (x-'A'+dist)%LEN+'A';
    if(x>='a')  return (x-'a'+dist)%LEN+'a';
}
static inline bool same(char x, char y)
{
    char max = x>y?x:y;
    char min = x<y?x:y;
    return (max-min)<='Z'-'A';
}

static inline char dis(char start, char end)
{
    return (end+LEN-start)%LEN;
}


int judgeStringType(char *s1,char *s2){

    if(strlen(s1)!=strlen(s2))
    {
        return 1;
    }
    if(strlen(s1)==strlen(s2))
    {   
        bool right = 1;
        for(int i=0;i<strlen(s1);i++)
        {
            if(s1[i]!=s2[i])
            {
                right = 0;
                break;
            }
        }
        if(right) return 2;
    }
    if(strlen(s1)==strlen(s2))
    {
        bool right = 1;
        int convert = 'a'-'A';
        for(int i=0;i<strlen(s1);i++)
        {
            if(s1[i]!=s2[i]&& s1[i]+convert!=s2[i] && s1[i]!=s2[i]+convert)
            {
                right = 0;
                break;
            }
        }
        if(right) return 3;        
    }
    if(strlen(s1)==strlen(s2))
    {
        int start;
        int end;
        int len;
        for(int i=0;i<strlen(s1);i++)
        {
            if(!same(s1[i],s2[i]))  return 5;
            if(i == 0)
            {
                len = dis(s1[i],s2[i]);
            }
            if(add(s1[i],len)!=s2[i])   return 5;
        }
        return 4;
    }
    return 5;
}