#include <stdio.h>
#include <stdlib.h>
#define min(x,y) (x < y ? x : y);
int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    int arr[n];
    int sum = 0;
    for(int i = 0; i < n; i++){ 
        scanf("%d", &arr[i]); 
        sum += arr[i];
    }
    int maxTeamsPossible = sum/m;
    int team[maxTeamsPossible][m];
    
    int teamFilledUpto[maxTeamsPossible];
    for(int i = 0; i < maxTeamsPossible; i++){ teamFilledUpto[i] = 0; }
    int currentTeamFillingUp = 0;

    for(int i = 0; i < n; i++){
        int t = min(maxTeamsPossible,arr[i]);
        while(t>0){
            if(teamFilledUpto[currentTeamFillingUp] == m){ 
                currentTeamFillingUp = (currentTeamFillingUp+1)%maxTeamsPossible;
                int c = 0;
                for(int j = 0; j < maxTeamsPossible; j++){
                    if(teamFilledUpto[j] == m) {c++;}
                }
                if(c == maxTeamsPossible){break;}
            }else{
            team[currentTeamFillingUp][teamFilledUpto[currentTeamFillingUp]] = i;
            t--;
            teamFilledUpto[currentTeamFillingUp] += 1;
            currentTeamFillingUp = (currentTeamFillingUp + 1)%maxTeamsPossible;
            }
        }
    }

    int filledTeams = 0;
    for(int i = 0; i < maxTeamsPossible; i++){
        if (teamFilledUpto[i] == m){ filledTeams++; }
    }
    for(int i = 0; i < maxTeamsPossible;i++){
        for(int j = 0; j < m; j++){
            printf("%d ", team[i][j]);
        }
        printf("\n");
    }
    printf("%d\n", filledTeams);
    return 0;
}