//m is the size of nums1, n is the size of nums2

#include <stdio.h>
#include <stdlib.h>

void merge(int* l, int lSize, int* r, int rSize, int* ans);

//using modified version of merge (from mergesort)
//Space complexity: O(1): only indexes necessary (11.94 MB)
//time complexity: O(log (m+n)): used in modified merge function (0 ms)
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    //return (double)(ans[(nums1Size+nums2Size)/2-1] + ans[(nums1Size+nums2Size)/2])/2; //even
    //return ans[(nums1Size+nums2Size)/2]; //odd
    if(nums1Size + nums2Size == 1) return nums1Size == 1? nums1[0] : nums2[0];
    int last_added; //track last number added
    int i = 0; //nums1
    int j = 0; //nums2
    if((nums1Size+nums2Size)%2==0){
        double total = 0;
        while(i < nums1Size && j < nums2Size){
            printf("i is %d, j is %d\n", i, j);
            if(i+j == (nums1Size+nums2Size)/2){
                printf("first 1 is %d\n", last_added);
                total += last_added;
            }
            else if (i+j == (nums1Size+nums2Size)/2+1){
                printf("second 1 is %d\n", last_added);
                total += last_added;
            }
            if(nums1[i] < nums2[j]){
                last_added = nums1[i++];
            } else {
                last_added = nums2[j++];
            }
        }
        if(i+j == (nums1Size+nums2Size)/2){
                printf("first 1 is %d\n", last_added);
                total += last_added;
            }
            else if (i+j == (nums1Size+nums2Size)/2+1){
                printf("second 1 is %d\n", last_added);
                total += last_added;
            }

        while(i < nums1Size){
            if(i+j == (nums1Size+nums2Size)/2-1){
                printf("first 1 is %d\n", nums1[i]);
                total += nums1[i];
            }
            else if (i+j == (nums1Size+nums2Size)/2){
                printf("second 1 is %d\n", nums1[i]);
                total += nums1[i];
            }
            i++;
        }
        while(j < nums2Size){
            if(i+j == (nums1Size+nums2Size)/2-1){
                printf("first 1 is %d\n", nums2[j]);
                total += nums2[j];
            }
            else if (i+j == (nums1Size+nums2Size)/2){
                printf("second 1 is %d\n", nums2[j]);
                total += nums2[j];
            }
            j++;
        }
        printf("total is %d", total);
        return  total/2;
    } else {    //odd
        while(i < nums1Size && j < nums2Size){
            if (i+j == (nums1Size+nums2Size)/2+1){
                return last_added;
            }
            if(nums1[i] < nums2[j]){
                last_added = nums1[i++];
            } else {
                last_added = nums2[j++];
            }
        }
        if (i+j == (nums1Size+nums2Size)/2+1){
                return last_added;
            }
        while(i < nums1Size){
            if (i+j == (nums1Size+nums2Size)/2){
                return nums1[i];
            }
            i++;
        }
        while(j < nums2Size){
            if (i+j == (nums1Size+nums2Size)/2){
                return nums2[j];
            }
            j++;
        }
    }
    return 0; //for leetcode
}

//Space complexity: O(m+n): need to create ans (12.3 MB)
//time complexity: O(log (m+n)): used in merge function (0 ms)
double findMedianSortedArraysWorse(int* nums1, int nums1Size, int* nums2, int nums2Size) {
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