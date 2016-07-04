#include<iostream>
#include<stdlib.h>
#include<cstring>
#pragma warning(disable:4996)
using namespace std;

int msize;
int map[100][100];
int dp[100][100];

int findPath(int row, int col) {
	if (row == msize - 1 && col == msize - 1) return 1; // arrival
	if (row >= msize || col >= msize) return 0;			// exceed size
	if (dp[row][col] != -1) return dp[row][col];		// existing value
	
	int jump = map[row][col];
	return dp[row][col] = findPath(row+jump, col) || findPath(row, col+jump);
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		memset(dp, -1, sizeof(dp));
		cin >> msize;

		// √ ±‚»≠
		for(int j=0; j<msize; j++)
			for (int k = 0; k < msize; k++) {
				cin >> map[j][k];
			}

		if (findPath(0, 0)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}