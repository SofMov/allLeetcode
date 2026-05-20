/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
    int* CAP = (int*)malloc(sizeof(int)* *returnSize);
    CAP[0] = A[0] == B[0]? 1:0;

    for(int i = 1; i < BSize; i++){
        for(int j = 0; j < ASize; j++){
            if(B[i] == A[j]){ //number found
                CAP[i] = CAP[i-1] + 1;
                break;
            }
        }
    }

    return CAP;
}