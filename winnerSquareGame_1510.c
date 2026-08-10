#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

//158 ms, 13.5 MB
//bad because by default false so has to go until it finds a true

bool* prevNum = NULL;

bool winnerSquareGame(int n) {
    bool first = false;
    if(prevNum == NULL){ //initial setup
        prevNum = (bool *)calloc(sizeof(bool), n+1); //assign space initially
        first = true;
    }
    if(n == 0) return false;
    if(prevNum[n]){ //base case
        printf("\tprevNum[%d] is true\n", n);
        return true;
    }
    for(int i = 1; i*i <= n; i++){
        if(!winnerSquareGame(n-i*i)){ // if even one is a losing move then this turn is winnable
            printf("when %d - %d then win possible\n", n, i*i);
            prevNum[n] = true;
            if(first) {free(prevNum); prevNum = NULL;}
            return true;
        }
    }
    if(first) {free(prevNum); prevNum = NULL;}
    return false;
}

int main(){
    printf("\t\t%s\n", winnerSquareGame(1)? "Pass": "Fail"); //True
    printf("\t\t%s\n", winnerSquareGame(2)? "Fail": "Pass"); //False
    printf("\t\t%s\n", winnerSquareGame(3)? "Pass": "Fail");
    printf("\t\t%s\n", winnerSquareGame(4)? "Pass": "Fail");
    printf("\t\t%s\n", winnerSquareGame(5)? "Fail": "Pass");
    printf("\t\t%s\n", winnerSquareGame(6)? "Pass": "Fail");
    printf("\t\t%s\n", winnerSquareGame(7)? "Fail": "Pass");
    printf("\t\t%s\n", winnerSquareGame(8)? "Pass": "Fail");
    printf("\t\t%s\n", winnerSquareGame(9)? "Pass": "Fail");
}