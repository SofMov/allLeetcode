//return lexigraphically smallest string which is also a palindrome
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* smallestPalindrome(char* s) {
    int len = strlen(s);
    char *answer = (char*)malloc(len);
    int freq[27] = {0};

    for(int i = 0; s[i] != '\0'; i++){ //record all frequencies of letters
        freq[s[i]-'a']++;
    }

    int pos = 0;

    if(len%2 == 0){ //even
        printf("even\n");
    } else { //odd
        
        //find letter which has odd freq;
        int odd_lett_pos;
        for(int i = 0; i < 27; i++){
            if(freq[i]%2 == 1){
                odd_lett_pos = i;
                break;
            }
        }
        printf("%c has odd freq of %d\n", odd_lett_pos+'a', freq[odd_lett_pos]);
        //place odd letter in correct place
        answer[len/2] = odd_lett_pos + 'a'; //place letter in middle
        printf("placing %c into middle(%d)\n", odd_lett_pos+'a', len/2);

        for(int i = 1; i < freq[odd_lett_pos]/2+1; i++){ //place letter on either side of middle
            printf("adding %c to %d and %d\n", odd_lett_pos+'a', len/2 + i, len/2 - i);
            answer[len/2 + i] = odd_lett_pos + 'a'; 
            answer[len/2 - i] = odd_lett_pos + 'a';
        }
    }

    for(int i = 0; i < 27; i++){ //construct the rest of the palindrome
        if(freq[i] != 0 && freq[i]%2 != 1){ //if letter contained in original string and not odd (already added) 
            for(int j = 0; j < freq[i]/2; j++){ //add back letter
                printf("adding %c, freq = %d\n", i +'a', freq[i]);
                answer[pos] = i + 'a'; //add first half letters
                answer[len - pos - 1] = i + 'a'; //add second half letters
                pos++;
            }
        }
    }
    return answer;
}

int main(){
    char* stroka = "z";
    printf("\t\tz: %s (z)\n", smallestPalindrome(stroka));
    char* ok = "babab";
    printf("\t\tbabab: %s (abbba)\n", smallestPalindrome(ok));
    char* ok2 = "aabbcc";
    printf("\t\taabbcc: %s (abccba)\n", smallestPalindrome(ok2));
    char* s = "daccad";
    printf("\t\tdaccad: %s (acddca)\n", smallestPalindrome(s));
}