#include <stdio.h>
#include <stdlib.h>

int cmpInt(const void* a, const void* b){
    int* aPtr = (int*) a;
    int* bPtr = (int*) b;
    return a - b;
}


int main(){
    int numStudents;
    scanf("%d", &numStudents);
    
    int inTimes[numStudents];
    int outTimes[numStudents];
    for(int i = 0; i < numStudents; i++){
        scanf("%d", &inTimes[i]);
    }
    for(int i = 0; i < numStudents; i++){
        scanf("%d", &outTimes[i]);
    }

    qsort(inTimes,  numStudents, sizeof(int), cmpInt);
    qsort(outTimes, numStudents, sizeof(int), cmpInt);
    int inPtr = 0; 
    int outPtr = 0; 
    int time = -1; 
    int numStudentsPresent = 0;
    int maxStudents = -1;
    int maxTime = -1;
    while(inPtr < numStudents){
        if(inTimes[inPtr] <= outTimes[outPtr]){
            numStudentsPresent++;
            if(maxStudents < numStudentsPresent){
                maxStudents = numStudentsPresent;
                maxTime = inTimes[inPtr];
            }
            inPtr++;
        }
        else{
            outPtr++;
            numStudentsPresent--;
        }
    }
    printf("Max %d students present at time %d\n", maxStudents, maxTime);
    return 0;
}