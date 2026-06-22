
/**
 * LeetCode 1189 solved:
 * Count amount of letters and find amount of "balloon"s
 * Time complexity: O(n) (finding all letters)
 * Space Complexity: O(1) (constant space used)
 */
#include <stdio.h>

int maxNumberOfBalloons(char* text) {
    int let[5] = {0};

    while(*text != '\0'){
        printf("read %c\n", *text);
        switch (*text) { //count number of instances of each needed letter
        case 'b':
            let[0]++; break;
        case 'a':
            let[1]++; break;
        case 'l':
            let[2]++; break;
        case 'o':
            let[3]++; break;
        case 'n':
            let[4]++; break;
        default:
            break;
        }
        text += 1;
    }

    int count = 0;
    while(let[0] > 0 && let[1] > 0 && let[2] > 1 && let[3] > 1 && let[4] > 0){ //count how many "balloon"s found
        let[0] -= 1;
        let[1] -= 1;
        let[2] -= 2;
        let[3] -= 2;
        let[4] -= 1;
        count++;
    }
    return count;
}

int main(){
    char* str = "balloon";
    maxNumberOfBalloons(str);
    char* str2 = "nlaebolko";
    maxNumberOfBalloons(str2);
}