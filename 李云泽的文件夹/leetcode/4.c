#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <malloc.h>


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int allnum=nums1Size+nums2Size;
    double current;
    int s1=0,s2=0;
    double cu1,cu2;
    if(allnum == 0) current=0.0;
    else if(nums1Size == 0){
        if((allnum)%2 == 1) current=(double) nums2[allnum/2];
        else current=((double)  (nums2[allnum/2]+nums2[allnum/2-1]) )/2;
    }else if(nums2Size == 0){
        if((allnum)%2 == 1) current=(double) nums1[allnum/2];
        else current=((double)  (nums1[allnum/2]+nums1[allnum/2-1]) )/2;
    }else {
    if((allnum)%2 == 1){
        for(int i=0;i<allnum/2+1;i++){
            if(s1 == nums1Size) {
                s2++;
                current=(double) nums2[s2-1];
                continue;
            }
            if(s2 == nums2Size) {
                s1++;
                current=(double) nums1[s1-1];
                continue;
            }
            if(nums1[s1]<nums2[s2]) {s1++;current=(double) nums1[s1-1]; }
            else {s2++;current=(double) nums2[s2-1]; }
        }
    }else{
        for(int i=0;i<allnum/2+1;i++){
            cu2=cu1;
            if(s1>=nums1Size) {s2++;cu1=(double) nums2[s2-1]; continue;}
            if(s2>=nums2Size) {s1++;cu1=(double) nums1[s1-1]; continue;}
            if(nums1[s1]<nums2[s2]) {s1++;cu1=(double) nums1[s1-1]; }
            else {s2++;cu1=(double) nums2[s2-1]; }
        }
        current=(cu1+cu2)/2;
    }
    }
    return current;
}

int main()
{
    int s1[2]={1,2};
    int s2[2]={3,4};
    printf("%f\n",findMedianSortedArrays(s1,2,s2,2));
    return 0;
}
