#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <malloc.h>

/*写的很复杂，但是分治之后的递归写的很烂，递归重复问题很大，反而使时间复杂度特别大*/

int check(char * s , int begin , int end , int current)
{
    int i;
    for(i=begin;i<=end-1;i++){
        if(s[current] == s[i]) return 0;
    }
    return 1;
}

int middle_max(char * s , int begin , int end )
{
    //if((s[current] == s[current+1]) && (s[current] == s[current-1]) ) return end-begin;
    //else if((s[current] != s[current+1]) && (s[current] == s[current-1]) ){//���������ƶ�
    //    current++;
    //    end++;
    //}
    //if(begin<=0) {/*printf("ddd\n");*/return end-begin;}
    //if(end>=strlen(s)) {/*printf("eee\n");*/return end-begin;}
    if( (begin<=0) && (end>=strlen(s)) ) {
        //return end-begin;}
        if(s[begin] == s[end-1])return end-begin;
        else return end-begin+1;}
    else if((begin<=0) && (end<strlen(s))) {if(check(s,begin,end,end) != 0) return middle_max(s,begin,end+1)-1;else return end-begin;}
    else if((begin>0) && (end>=strlen(s))) {if(check(s,begin,end,begin-1) != 0) return middle_max(s,begin-1,end)-1;else return end-begin;}
    if((check(s,begin,end,begin-1) == 0) && (check(s,begin,end,end) == 0)) {/*printf("fff   end:%d   begin:%d\n",end,begin);*/return end-begin;}
    else if( ( (check(s,begin,end,begin-1) != 0) && (check(s,begin,end,end) == 0) )   ){//���������ƶ�
        //printf("ccc\n");
        begin--;
        return middle_max(s,begin,end);
    }
    else if((check(s,begin,end,begin-1) == 0) && (check(s,begin,end,end) != 0)){//���������ƶ�
        //printf("bbb\n");
        end++;
        return middle_max(s,begin,end);
    }
    else{
        //printf("aaa\n");
        int num1=middle_max(s,begin-1,end);//printf("num1:%d\n",num1);
        int num2=middle_max(s,begin,end+1);//printf("num2:%d\n",num2);
        if(num1>num2) return num1;
        else return num2;
    }
}

int lengthOfLongestSubstring(char * s)
{
    int length = strlen(s);
    if(length == 0) return 0;
    if(length == 1) return 1;
    if((length == 2) && (s[0] == s[1])) return 1;
    else if((length == 2) && (s[0] != s[1])) return 2;
    char *s1=(char *)malloc((length)*sizeof(char));
    char *s2=(char *)malloc((length)*sizeof(char));
    //for(int i=0;i<length/2;i++){
    //    s1[i]=s[i];
    //}
    strcpy(s1,s);
    s1[length/2]='\0';
    //printf("%s\n",s1);
    strcpy(s2,& s[length/2]);
    //for(int i=0;i<length/2+1;i++){
    //    s2[i]=s[i+length/2];
    //}
    //if(length%2 == 1) s2[length/2+1] = '\0';
    //printf("%s\n",s2);
    int max3=middle_max(s,length/2,length/2+1);
    int max1=lengthOfLongestSubstring(s1);
    int max2=lengthOfLongestSubstring(s2);
    //printf("%d %d %d\n",max1,max2,max3);
    if(max1>max2 ){
        if(max3>max1) return max3;
        else return max1;
    }else{
        if(max3>max2) return max3;
        else return max2;
    }

    //return 1;

}

int main()
{
    char s[100]="hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789hijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"
    ;
    printf("%d\n",lengthOfLongestSubstring(s));
    return 0;
}
