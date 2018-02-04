/* Brute for solution : 
    Possible height ranges between tmin to tmax
    Loop through them. Find minumum. 
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main(){
    int numTestCases;
    scanf("%d", &numTestCases);
    for(int t = 0; t < numTestCases; t++){
        int numTowers;
        scanf("%d", &numTowers);

        int height[numTowers];
        int cost[numTowers];
        int minHeight = INT_MAX;
        int maxHeight = INT_MIN;

        for(int i = 0; i < numTowers; i++){ 
            scanf("%d", &height[i]);
            if(height[i] < minHeight){ minHeight = height[i]; }
            if(height[i] > maxHeight){ maxHeight = height[i]; }
        }
        for(int i = 0; i < numTowers; i++){ scanf("%d", &cost[i]);}

        int minCost = INT_MAX;
        for(int i = minHeight; i <= maxHeight; i++ ){
            int costI = 0;
            for(int j = 0; j < numTowers; j++){
                int costTower = cost[j]*abs(i-height[j]);
                costI += costTower;
            }
            if(costI < minCost){ minCost = costI; }
        }
        printf("Minimum cost is : %d\n", minCost);
    }
}