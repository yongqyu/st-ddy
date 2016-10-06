#include<iostream>
#include<vector>
using namespace std;

vector<vector<bool> > adj;
vector<bool> discarded;
int main() {
	ios::sync_with_stdio(false);
	int t, K, L, V, E;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		cin >> K >> L >> V >> E;
		adj.assign(V + 1, vector<bool>(V + 1, false));
		discarded.assign(V + 1, false);

		for (int i = 0; i < E; i++) {
			int a, b; cin >> a >> b;
			adj[a][b] = adj[b][a] = true;
		}

		int nofrobot = V;
		while (1) {
			int i = 1;
			for (; i <= V; i++) {
				if (discarded[i]) continue;

				int degree = 0;
				for (int j = 1; j <= V; j++) {
					if (adj[i][j]) degree++;
				}

				if (degree == nofrobot - 1 || degree < K || degree > nofrobot - L - 1) {
					discarded[i] = true;
					for (int j = 1; j <= V; j++) adj[i][j] = adj[j][i] = false;
					nofrobot--;
					break;
				}
			}
			if (i == V + 1) break;
		}

		int result = 0;
		for (int i = 1; i <= V; i++)
			if (discarded[i]) result += i;

		cout << "Case #" << test << "\n" << result << "\n";
	}
}
