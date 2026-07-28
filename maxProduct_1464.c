//find 2 biggest numbers and multiply them together
//return (nums[i]-1)*(nums[j]-1)
#include <stdio.h>

int maxProduct(int* nums, int numsSize) {
    int max_number[2] = {0,0};

    //max[0] is the biggest number
    //max[1] is the second biggest number

    for(int i = 0; i < numsSize; i++){
        if(nums[i] > max_number[0]){
            max_number[1] = max_number[0]; //move number down
            max_number[0] = nums[i];
        } else if(nums[i] > max_number[1]){
            max_number[1] = nums[i];
        }
    }
    printf("two max are %d and %d\n", max_number[0], max_number[1]);
    return (max_number[0]-1)*(max_number[1]-1);
}

int main(){
    printf("3,4,5,2: %d (12)\n",maxProduct((int[]){3,4,5,2}, 4));
}
