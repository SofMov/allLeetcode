#include <stdbool.h>
#include <stdio.h>

bool check(int* nums, int numsSize) {
    int min=nums[0], minIndex=0;
    for(int i = 1; i < numsSize-1; i++){
        printf("checking %d\n", nums[i]);
        if(min > nums[i]){
            min = nums[i];
            minIndex = i;
        }
    }
    if(min == nums[numsSize-1]) minIndex = numsSize-1; //in case the last element is also the smallest
    printf("%d %d\n", min, minIndex);
    for(int i = minIndex; i - minIndex < numsSize-1; i++){
        if(nums[i % numsSize] > nums[(i+1) % numsSize]){
            printf("%d greater than %d", nums[i % numsSize],nums[(i+1) % numsSize] );
            return false;
        }
    }
    return true;
}


//count number of decreases (should be 1 or 0)
bool check(int* nums, int numsSize) {
    int numD = 0; //number of decreases
    for(int i = 0; i < numsSize-1; i++){
        if(nums[i] > nums[i+1]){
            if(numD) return false; //numD != 0
            numD++;
        }
    }
    if(nums[0] < nums[numsSize-1]) numD++;
    if(numD >= 2) return false;
    return true;
}