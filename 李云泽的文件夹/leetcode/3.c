#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <malloc.h>

/*滑动窗口，还是能优化一些的*/


int check(char * s , int begin , int end , int current)
{
    int i;
    for(i=begin;i<=end;i++){
        if(s[current] == s[i]) return 0;
    }
    return 1;
}

int lengthOfLongestSubstring(char * s)
{
    int length=strlen(s);
    if(length < 2) return length;
    int i=0;
    int now_len;
    int right=0;
    for(i=1;i<length;i++){
        if(check(s,0,i-1,i) == 0) break;
    }
    right=i-1;
    now_len=i;
    for(i=1;i<length;i++){
        if(right <= i) right=i;
        while(check(s,i,right,right+1)){
            if((right+1)>=length) break;
            right++;
        }
        if((right-i+1)>now_len) now_len=right-i+1;
    }
    return now_len;
}

int main()
{
    char s[100]="aaaca";
    printf("%d\n",lengthOfLongestSubstring(s));
    return 0;
}

