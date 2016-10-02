// https://www.acmicpc.net/problem/1238
// 참고 해설 : http://hanstemcell.tistory.com/entry/2-%EB%B0%B1%EC%A4%80%ED%8C%8C%ED%8B%B0%EC%9A%B0%EC%84%A0%EC%88%9C%EC%9C%84-%ED%81%90%EB%A5%BC-%EC%9D%B4%EC%9A%A9%ED%95%9C-%EB%8B%A4%EC%9D%B5%EC%8A%A4%ED%8A%B8%EB%9D%BC-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98
// 다음노드 선정시 최소값 선정 - priority_queue 사용(maxheap)
// adjacency node 정보 저장위해 - Vector 사용

#include<iostream>
#include<queue>
#include<vector>

#define MAX_NODE 1000
#define MAX_COST 1000000

using namespace std;

int vill, way, party;
vector<pair<int, int>> adj[MAX_NODE + 1];
int total[MAX_NODE + 1], dist[MAX_NODE + 1];

void input() {
	cin >> vill >> way >> party;
	for (int i = 0; i < way; i++) {
		int from, to, time;
		cin >> from >> to >> time;
		adj[from].push_back(make_pair(to, time));
	}
}

int dijkstra(int from, int to) {
	priority_queue<pair<int, int> > pq;

	for (int i = 1; i <= vill; i++)
		dist[i] = MAX_COST;

	dist[from] = 0;
	pq.push(make_pair(0, from));

	while (!pq.empty()) 
	{
		int position = pq.top().second;
		int cost = -pq.top().first;

		if(position == to) return dist[to];

		for (int i = 0; i < adj[position].size(); i++) {
			int next_position = adj[position][i].first;
			int next_cost = cost + adj[position][i].second;

			if ( next_cost < dist[next_position] ) {
				dist[next_position] = next_cost;
				pq.push(make_pair(-next_cost, next_position));
			}
		}
		pq.pop();
	}
}

int main() {
	
	input();

	for (int i = 1; i <= vill; i++) {
		total[i] = dijkstra(i, party);
	}

	dijkstra(party, 0);

	int longest = 0;
	for (int i = 1; i <= vill; i++) {
		total[i] += dist[i];
		if (longest < total[i])
			longest = total[i];
	}

	cout << longest;

	return 0;
}
