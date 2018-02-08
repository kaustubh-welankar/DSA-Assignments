#include<stdio.h>
#include<stdlib.h>
#include<limits.h>



int check(int val, int* numFiles, int numFriends, int numCabinets){
    int completed = 1;
    int currentSum = 0;
    int i = 0;
    while(i < numCabinets){
        if(numFiles[i] > val){
            return INT_MAX;
        }
        if( currentSum + numFiles[i] <= val){
            currentSum += numFiles[i];
        }
        else{
            completed++;
            currentSum = numFiles[i];
        }
        i++;
    } 
    return (completed);      
}


int main(){
    int numCabinets, numFriends;
    scanf("%d %d", &numCabinets, &numFriends);
    int numFiles[numCabinets];
    int minFiles = INT_MAX, maxFiles = INT_MIN;

    for(int i = 0; i < numCabinets; i++){
        scanf("%d", &numFiles[i]);
        if(minFiles > numFiles[i]){minFiles = numFiles[i];}
        if(maxFiles < numFiles[i]){maxFiles = numFiles[i];}
    }
    //printf("%d\n", check(1785, numFiles, numFriends, numCabinets));
    
    for(int i = 1700; i < 1800; i++){
        printf("%d is max height : %d min people\n", i, check(i,numFiles,numFriends,numCabinets));
    }
    
    

    
    int low = 1, high = 1e5;
    while(low < high){
        int mid = (low+high)/2;
        if(check(mid, numFiles, numFriends, numCabinets) > numFriends){
            low = mid + 1;
        }
        else{
            if(check(mid, numFiles, numFriends, numCabinets) < numFriends){
                high = mid;
            }
            else{
                if(check(mid - 1, numFiles, numFriends, numCabinets) == numFriends){
                    high = mid;
                }
                else{
                    printf("%d\n", mid);
                    break;
                }
            }
        }
    }
    


    return 0;
}
//568 712 412 231 241 393 865 287 128 457 238 98 980 23 782
//    XXXX            1730            1228                