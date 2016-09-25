#include<iostream>
#include<vector>
using namespace std;
#define MOD 1000000009

int K, N, L;
int DP[50001][101];
int S[50001];

int main() {
	ios::sync_with_stdio(false);
	int T;
	int test_case;

	cin >> T;
	for (test_case = 1; test_case <= T; test_case++) {
		cin >> N >> K >> L;

		vector<bool> mine(N + 1, false);
		for (int i = 1; i <= L; i++) {
			int tmp; cin >> tmp;
			mine[tmp] = true;
		}

		for (int i = 1; i <= N; i++) {
			S[i] = 0;
			for (int j = 1; j <= K; j++) {
				DP[i][j] = 0;
			}
		}

		S[0] = 1;

		for (int stone = 1; stone <= N; stone++) {
			if (mine[stone]) continue;
			for (int jump = 1; jump <= K && (stone - jump >= 0); jump++) {
				DP[stone][jump] = (S[stone - jump] + MOD - DP[stone - jump][jump]) % MOD;
				S[stone] = (S[stone] + DP[stone][jump]) % MOD;
			}
		}

		cout << "Case #" << test_case << "\n" << S[N] << endl;
	}
}