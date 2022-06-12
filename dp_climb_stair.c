#include <stdio.h>

#ifndef max
#define max(a,b)  (a)<(b) ? (a) :(b)
#endif

int n;
//계단의 점수: score
int score[305];
int dp[305][3];

//계단의 개수(=마지막 계단): st, 마지막 점프를 뛸 때 올라갈 계단 개수: lastjump
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
    dp[1][1] = dp[1][2] = score[1]; //base case

    for(int i=2;i<=n;i++){
        dp[i][1] = dp[i-1][2] + score[i]; // 1)값을 저장한다.
        dp[i][2] = max(dp[i-2][1], dp[i-2][2]) + score[i]; 
        //2) 이후, 함수를 호출할 필요 없이 저장한 값을 가져와 계속해서 대입한다.
    }
    printf("%d 점", max(dp[n][1],dp[n][2]));
}