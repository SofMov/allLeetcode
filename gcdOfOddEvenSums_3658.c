//time complexity O(1) -> constant time return operation
//space complexity O(1) -> no extra space is necesary
int gcdOfOddEvenSums(int n) {
    return n;
}
/**
 * When looking at possible values for n a pattern emerges:
 *  n  sumOdd  sumEven GCD
 *  1  1       2       1
 *  2  4       6       2
 *  3  9       12      3
 *  4  16      20      4
 *  5  25      30      5
 *  6  36      42      6
 */