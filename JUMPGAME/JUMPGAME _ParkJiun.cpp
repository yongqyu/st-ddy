#include<iostream>
using namespace std;

int board[100][100];
int DP[100][100];
int dir[2][2] = { {0,1}, {1, 0} }; //right down
int n;
void solve(int, int);

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> board[i][j];
				DP[i][j] = -1;
			}

		solve(0, 0);

		if (DP[n - 1][n - 1] == 1) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

void solve(int x, int y) {
	if (x < 0 || n <= x || y < 0 || n <= y) return;
	int nx, ny;
	for (int i = 0; i < 2; i++) {
		nx = x + dir[i][0] * board[x][y];
		ny = y + dir[i][1] * board[x][y];
		if (0 <= nx && nx < n && 0 <= ny && ny < n && DP[nx][ny] == -1) {
			DP[nx][ny] = 1;
			solve(nx, ny);
		}
	}
}