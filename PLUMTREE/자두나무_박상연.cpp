#include <iostream>
#include <cstdio>
using namespace std;
#define max(a,b) (a>b? a: b)

int time_dp[1001][31];
int main(){
	int T, W;
	int input;

	scanf("%d %d", &T, &W);


	scanf("%d", &input);
	if (input == 1)
		time_dp[1][0] = 1;
	else{
		time_dp[1][1] = 1;
	}

	for (int i = 2; i <= T; i++){
		scanf("%d", &input);
		for (int j = 0; j <= W && j<=i; j++){
			int cur_pos = (j % 2 == 0) ? 1 : 2;
			if (cur_pos == input)	// 떨어지는 위치에 있을때
			{
				if (j == 0){
					time_dp[i][j] = time_dp[i - 1][j] + 1;
					continue;
				}
				time_dp[i][j] = (max(time_dp[i - 1][j], time_dp[i - 1][j - 1])) + 1;
			}
			else{		// 떨어지는 위치에 있지 않을때
				if (j == 0){
					time_dp[i][j] = time_dp[i][j] = time_dp[i - 1][j];
					continue;
				}
					time_dp[i][j] = max(time_dp[i - 1][j], time_dp[i - 1][j - 1]);
			}
		}
	}
	int max = time_dp[T][0];
	for (int j = 1; j <= W; j++){
		max = max(time_dp[T][j], max);
	}

	cout << max;
}