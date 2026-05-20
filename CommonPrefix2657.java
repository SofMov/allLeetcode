import java.util.Arrays;

class Solution {
    public int[] findThePrefixCommonArray(int[] A, int[] B) {
        int[] CAP = new int[A.length];
        int[] collisions = new int[Arrays.stream(A).max().getAsInt()+1]; //store all numbers at their indexes
        
        if(A[0] == B[0]){ //collision found
            CAP[0] = 1;
        } else{ //collision not found so add both
            collisions[A[0]] = 1;
            collisions[B[0]] = 1;
        }

        for(int i = 1; i < A.length; i++){
            if(collisions[A[i]] + collisions[B[i]] == 2){ //both collide
                CAP[i] = CAP[i-1] + 2;
            } else if (collisions[A[i]] == 1){ //only A collides
                CAP[i] = CAP[i-1] + 1;
                collisions[B[i]] = 1;
            } else if (collisions[B[i]] == 1){ //only B collides
                CAP[i] = CAP[i-1] + 1;
                collisions[A[i]] = 1;
            } else if(A[i] == B[i]){ //collide with each other
                CAP[i] = CAP[i-1] + 1;
            } else { //no collisions
                CAP[i] = CAP[i-1];
                collisions[B[i]] = 1;
                collisions[A[i]] = 1;
            }
        }
        return CAP;
    }
    public static void main(String[] args) {
        Solution ok = new Solution();
        int[] arr1 = new int[]{1,3,2,4};
        int[] arr2 = new int[]{3,1,2,4};
        
        ok.findThePrefixCommonArray(arr1, arr2);
    }
}