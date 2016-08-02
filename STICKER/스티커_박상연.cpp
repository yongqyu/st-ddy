#include <iostream>
#include <cstdio>

using namespace std;
int input[2][100001];
int dp[2][100001];

int main(){
	int T, N, temp;


	scanf("%d", &T);
	for (int testcase = 0; testcase < T; testcase++){
		scanf("%d", &N);
		for (int j = 0; j < 2; j++){
			for (int i = 1; i <= N; i++){
				scanf("%d", &temp);
				input[j][i] = temp;
			}
		}
		dp[0][1] = input[0][1];
		dp[1][1] = input[1][1];

		for (int i = 2; i <= N; i++)
		{
			dp[0][i] = (dp[1][i - 1] > dp[1][i - 2] ? dp[1][i - 1] : dp[1][i - 2]) + input[0][i];
			dp[1][i] = (dp[0][i - 1] > dp[0][i - 2] ? dp[0][i - 1] : dp[0][i - 2]) + input[1][i];
		}
		int result = dp[0][N] > dp[1][N] ? dp[0][N] : dp[1][N];
		cout << result << endl;
	}
}