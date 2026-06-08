#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pivotArray(int* nums, int numsSize, int pivot, int* returnSize) {
    int* retArr = (int*)malloc(sizeof(int)* *returnSize);
    int numpart = 0;
    //linear search
    int i, j=0;
    for(i = 0; i < numsSize; i++){
        if(nums[i] < pivot){
            printf("%d ", nums[i]);
            retArr[j++] = nums[i];
        }
        else if(nums[i] == pivot){
            numpart++;
        }
    }
    printf("\n");
    printf("adding %d %ds\n", numpart, pivot);
    while(numpart > 0){
        //printf("adding %d %ds\n", numpart, pivot);
        retArr[j++] = pivot;
        numpart--;
    }
    for(i = 0; i < numsSize; i++){
        if(nums[i] > pivot){
            printf("%d ", nums[i]);
            retArr[j++] = nums[i];
        }
    }
    printf("\n");
            
    return retArr;
    
}

int main(){
    int ret = 7;
    pivotArray((int[]){9,12,5,10,14,3,10}, ret, 10, &ret);
    ret = 4;
    pivotArray((int[]){-3,4,3,2}, ret, 2, &ret);
    return 0;
}