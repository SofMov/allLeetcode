//could merge merge() to take up less space, only make half the array
//m is the size of nums1, n is the size of nums2
//Space complexity: O(m+n): need to create ans (12.3 MB)
//time complexity: O(log (m+n)): used in merge function (0 ms)
#include <stdio.h>
#include <stdlib.h>

void merge(int* l, int lSize, int* r, int rSize, int* ans);

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    //double median;
    int* ans = (int*)malloc(sizeof(int)*(nums1Size+nums2Size));
    //mergesort merge
    merge(nums1, nums1Size, nums2, nums2Size, ans);
    //for(int i = 0; i < nums1Size+nums2Size; i++){
    //    printf("%d ", ans[i]);
    //}
    //printf("\n");
    //find median
    if((nums1Size+nums2Size)%2==0){
        //printf("even\n");
        //printf("%d and %d\n", ans[(nums1Size+nums2Size)/2-1], ans[(nums1Size+nums2Size)/2]);
        return (double)(ans[(nums1Size+nums2Size)/2-1] + ans[(nums1Size+nums2Size)/2])/2;
    } 
    return ans[(nums1Size+nums2Size)/2];

}

void merge(int* l, int lSize, int* r, int rSize, int* ans){
    int i = 0; //left
    int j = 0; //right
    int k = 0; //our array
    while(i < lSize && j < rSize){
        if(l[i] < r[j]){
            ans[k++] = l[i++];
        } else {
            ans[k++] = r[j++];
        }
    }
    while(i < lSize){
        ans[k++] = l[i++];
    }
    while(j < rSize){
        ans[k++] = r[j++];
    }

}