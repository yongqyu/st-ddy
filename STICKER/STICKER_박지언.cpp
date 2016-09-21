#include<iostream>
#define MAX(a,b) (a)>(b) ? (a):(b)
using namespace std;

int main() {
	int T, n;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int max = 0;
		cin >> n;
		int *sticker[2], *dp[2];
		for (int i = 0; i < 2; i++) {
			sticker[i] = new int[n];
			dp[i] = new int[n];
		}
		
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++)
				cin >> sticker[i][j];
		}
		
		dp[0][0] = sticker[0][0];
		dp[1][0] = sticker[1][0];

		for (int i = 1; i < n; i++) {
			dp[0][i] = MAX(dp[1][i - 1] + sticker[0][i], max + sticker[0][i]);
			dp[1][i] = MAX(dp[0][i - 1] + sticker[1][i], max + sticker[1][i]);
			max = MAX(dp[0][i - 1], dp[1][i - 1]);
		}
		
		max = MAX(dp[0][n - 1], dp[1][n - 1]);
		cout << max << endl;
	}
}