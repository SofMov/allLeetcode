//space complexity O(1): constant space used (9.17 MB)
//time complexity: O(n): go through all digits to find 2 biggest (0 ms)

int maxProduct(int n) {
    int max_number[2] = {0,0};

    while(n > 0){
        if(n%10 > max_number[0]){
            max_number[1] = max_number[0]; //move number down
            max_number[0] = n%10;
        } else if(n%10 > max_number[1]){
            max_number[1] = n%10;
        }
        n /= 10;
    }
    return max_number[0]*max_number[1];
}