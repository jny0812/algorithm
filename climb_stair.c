#include <stdio.h>

#ifndef max
#define max(a,b)  (a)<(b) ? (a) :(b)
#endif

int n;
//계단의 점수: score
int score[305];
int dp[305][3];

//올라가야 하는 계단의 개수: stairs, 마지막 점프를 뛸 때 올라갈 계단 개수: lastjump
int get_score(int stairs, int lastjump){
    if(stairs==0 || dp[stairs][lastjump]!=0){
        return dp[stairs][lastjump];
    }
    if(lastjump==1){
        return dp[stairs][lastjump] = get_score(stairs-1,2) + score[stairs];
    }
    return dp[stairs][lastjump] = max(get_score(stairs-2,1), get_score(stairs-2,2) + score[stairs]);
}

int main(){
    
    printf("계단의 개수를 입력하세요:");
    scanf("%d", &n);
    if(n == 0 ){
        printf("계단의 개수는 1개 이상입니다. 다시 입력하세요:");
        scanf("%d", &n);
    }
    for (int i=1;i<=n;i++){
        printf("각 계단 별 점수를 입력하세요(%d 번째 계단):", i);
        scanf("%d", &score[i]);
    }
    dp[1][1] = dp[1][2] = score[1];
    printf("%d 점", max(get_score(n,1),get_score(n,2)));
}