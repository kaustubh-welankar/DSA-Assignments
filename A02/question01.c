#include <stdio.h>
#include <string.h>

#define COMBINATIONS 6561
#define OPS 8
void generateCombination(int permutationIdentifier, char* arr){
    int arrPtr = 0;
    for(int i = 1; i < OPS ; i++, permutationIdentifier /= 3){
        arr[arrPtr] = i + '0';
        arrPtr++;
        int op = permutationIdentifier % 3;
        if(op == 0){
            arr[arrPtr] = '+';
            arrPtr++;
        }
        else if(op == 1){
            arr[arrPtr] = '-';
            arrPtr++;
        }
    }
    arr[arrPtr] = '9';
    arr[arrPtr + 1] = '\0';
}

int eval(char* exp){
    int lastInt = 0, val = 0;
    char lastOp = '+';
    int len = strlen(exp);
    for(int i = 0; i < len; i++){
        char c = exp[i];
        if(c >= '1' && c <= '9'){
            lastInt *= 10;
            lastInt += (c - '0');
        }
        else if(c == '+' || c == '-'){
            if(lastOp == '+'){ val += lastInt; }
            else {val -= lastInt;}
            lastInt = 0;
            lastOp = c;
        }
    }
    if(lastOp == '+'){ val+= lastInt; }
    else{ val -= lastInt ;}
    return val;
}

int main(){
    for(int i = 0; i < COMBINATIONS; i++){
        char expression[20];
        generateCombination(i,expression);
        int valExpression = eval(expression);
        if(valExpression == 100){
            printf("%s = %d\n", expression, valExpression);
        }        
    }

    return 0;
}