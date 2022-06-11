#include <stdio.h>


//옮기는 원반의 개수 : n
//시작 기둥: from, 도착 기둥: to, 거쳐갈 기둥: temp
void hanoi(int n, char from, char temp, char to) {
    if (n<1){ //만약 n이 1보다 작다면 다시 입력 받음.
        printf("error: n must be natural number. \n");
        printf("원판의 개수를 입력하시오: ");
	    scanf("%d", &n);
    }

	if (n == 1) {  //만약 n이 1이라면 한 번에 이동 가능
		printf(" 1번 원판을 %c 기둥에서 %c 기둥으로 옮긴다. \n", from, to);
	}
	else { //n이 2 이상일 때,

        //1번 재귀
		hanoi(n - 1, from, to, temp);
		printf(" %d번 원판을 %c 기둥에서 %c 기둥으로 옮긴다. \n", n, from, to);

        //2번 재귀
		hanoi(n - 1, temp, from, to);
	}
}

int main(void) {
	int n = 0;
	printf("원판의 개수를 입력하시오: ");
	scanf("%d", &n);
	
	hanoi(n, 'A', 'B', 'C');
	return 0;
}