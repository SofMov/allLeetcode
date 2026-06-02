#include <stdio.h>
#include <string.h>

int myAtoi(char* s) {
    int neg = 0, number = 0;
    int len = strlen(s);
    int total = 0;
    for(int i = 0; i < len; i++){
        printf("read %c, number %sfound, %snegative\n", s[i], number==1?"":"not ", neg==1?"":"not ");
        if(s[i] == ' ') continue; //skip empty space
        if(s[i] >= '0' && s[i] <= '9'){ //number found
            printf("adding numbers \n");
            number = 1;
            if(total > 21478364 && neg == 0){ //integer overflow
                return 2147483647;
            } else if (total > 21478364 && neg == 1){
                return -2147483648;
            } else {
                total *= 10;
            }
            total += s[i] - '0';
        } else if(number == 1){ //non number encountered after number
            return neg == 1? -total: total;
        } else if(s[i] >= 'A' && s[i] <= 'z'){ //letter encountered
            printf("returning\n");
            return neg == 1? -total: total;
        } else if (s[i] == '-'){ //negative encountered
            neg = 1;
            number = 1;
        }
    }
    return neg == 1? -total: total;
}

int main(){
    myAtoi("1337c0d3");
    puts("\n");
    myAtoi("1337C0D3");
}