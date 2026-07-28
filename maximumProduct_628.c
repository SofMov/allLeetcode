//doesnt account for 2 negative times 1 positive

int maximumProduct(int* nums, int numsSize) {
    int max_number[3] ;//= {nums[0], nums[1], nums[2]};
    int smallest[2] = {0};

    if(nums[0] > nums[1]){
        if(nums[2] > nums[0]){
            max_number[0] = nums[2];
            max_number[1] = nums[0];
            max_number[2] = nums[1];
        } else {
            max_number[0] = nums[0];
            max_number[1] = nums[2];
            max_number[2] = nums[1];
        }
    } else {
        if(nums[2] > nums[1]){
            max_number[0] = nums[2];
            max_number[1] = nums[1];
            max_number[2] = nums[0];
        } else {
            max_number[0] = nums[1];
            max_number[1] = nums[2];
            max_number[2] = nums[0];
        }
    }
    
    for(int i = 3; i < numsSize; i++){
        if(nums[i] < smallest[0]){
            smallest[1] = smallest[0]; //move number down
            smallest[0] = nums[i];
        } else if(nums[i] < smallest[1]){
            smallest[1] = nums[i];
        }
        if(nums[i] > max_number[0]){ //trickle down economy ts
            max_number[2] = max_number[1]; //move number down
            max_number[1] = max_number[0]; //move number down
            max_number[0] = nums[i];
        } else if(nums[i] > max_number[1]){
            max_number[2] = max_number[1]; //move number down
            max_number[1] = nums[i];
        } else if(nums[i] > max_number[2]){
            max_number[2] = nums[i];
        }
    }
    if(smallest[0]*smallest[1] == 0){ //two smallest not found
        return max_number[0]*max_number[1]*max_number[2];
    }
    if(max_number[0]*max_number[1]*max_number[2] > max_number[0]*smallest[1]*smallest[0]){
        return max_number[0]*max_number[1]*max_number[2];
    }
    return max_number[0]*smallest[1]*smallest[0];
}