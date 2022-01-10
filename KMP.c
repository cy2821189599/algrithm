#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 计算next数组
void getNext(int *next, const char *substr)
{
    int len = strlen(substr);
    next[0] = 0;
    int j = 0, i = 1; //j 前缀末尾下标，i后缀末尾下标
    for(; i < len; i++)
    {
        while (j > 0 && substr[j] != substr[i])
        {
            j = next[j-1];
        }
        if (substr[i] == substr[j])
        {
            ++j;
        }
        next[i] = j;
    }
}

int substr(const char *basestr, const char *findstr)
{
    int ret = -1;
    int len = strlen(findstr);
    int *next = (int *) malloc(sizeof(int)*len);
    getNext(next, findstr);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", next[i]);
    }
    printf("\n");
    //使用next数组
    int base_len = strlen(basestr);
    for (int i = 0, j = 0; i < base_len; i++)
    {
        while (j > 0 && basestr[i] != findstr[j])
        {
            j = next[j - 1];
        }
        
        if (basestr[i] == findstr[j])
        {
            j++;
        }
        if (j == len)
        {
            ret =  i - len + 1;
        }
    }
    free(next);
    return ret;
}

int main()
{
    const char *str = "aabaaffaa";
    const char *basestr = "aabbcccaabaaffaah";
    int index = substr(basestr, str);
    printf("index %d\n", index);
    if (index != -1)
    {
        printf("%s\n", basestr+index);
    }
    
    return 0;
}