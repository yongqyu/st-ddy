#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int INF = 0x79999999;

int main() {
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		int V, E, K;
		ll sumofdistance = 0, sumofshelter = 0;
		cin >> V >> E >> K;
		
		vector<vector<pair<int, int> > > edge(V + 1);
		priority_queue<pair<int, int> > pq;
		vector<int> shelter(V + 1);
		vector<ll> dist(V + 1, INF);

		for (int i = 0; i < E; i++) {
			int from, to, cost; cin >> from >> to >> cost;
			edge[from].push_back(make_pair(to, cost));
			edge[to].push_back(make_pair(from, cost));
		}

		for (int i = 0; i < K; i++) {
			int a; cin >> a;
			shelter[a] = a;
			dist[a] = 0;
			pq.push(make_pair(a, 0));
		}

		while (!pq.empty()) {
			int cur = pq.top().first;
			int curCost = pq.top().second;
			pq.pop();
			
			int nofEdge = edge[cur].size();
			for (int i = 0; i < nofEdge; ++i) {
				int next = edge[cur][i].first;
				int nextCost = edge[cur][i].second;

				if (dist[next] > curCost + nextCost) {
					dist[next] = curCost + nextCost;
					shelter[next] = shelter[cur];
					pq.push(make_pair(next, dist[next]));
				}
				else if (dist[next] == curCost + nextCost && shelter[next] > shelter[cur]) {
					shelter[next] = shelter[cur];
					pq.push(make_pair(next, dist[next]));
				}
			}
		}

		
		for (int i = 1; i <= V; i++) {
			sumofdistance += dist[i];
			sumofshelter += shelter[i];
		}

		printf("Case #%d\n%lld\n%lld\n", test, sumofdistance, sumofshelter);
	}
}