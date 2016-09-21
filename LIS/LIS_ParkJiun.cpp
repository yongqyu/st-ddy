#include<iostream>
using namespace std;

int DP[500], S[500];

int main() {
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> S[i];
			DP[i] = 1;
		}
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i + 1; j < n; j++) {
				if (S[i] < S[j] && DP[i] < DP[j] + 1) {
					DP[i] = DP[j] + 1;
				}
			}
		}
		int max = 0;
		for (int i = 0; i < n; i++)
			if (max < DP[i]) max = DP[i];

		cout << max << endl;
	}
}