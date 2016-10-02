#include<iostream>
#include<stdlib.h>
#include<memory.h>
#pragma warning(disable:4996)
using namespace std;

int village, road, destination;
int way[1001][1001]; // [a][b]= a->b 가는 가중치
bool visited[1001];
int weight[1001];
int result[1001];

void dijkstra(int start, int end) {

	int count = 1;
	weight[start] = 0;
	visited[start] = true;
	int temp = start;

	while (count != village) {

		// way 순회하면서 
		for (int i = 1; i <= village; i++) {

			//길이 있다면
			if (way[temp][i] != -1) {
				// false 이고 (음수이거나 더 작으면) weight 초기화
				if (visited[i] == false && (weight[i] < 0 || weight[temp] + way[temp][i] < weight[i])) {
					weight[i] = weight[temp] + way[temp][i];
				}
			}
		}

		int min_village = 2, min_value = 99999999;
		for (int i = 1; i <= village; i++) {
			if (visited[i])continue;
			if (min_value >= weight[i] && weight[i]>0) {
				min_value = weight[i];
				min_village = i;
			}
		}

		// result 순회하면서 false인애중에 가장 작은애 선택 = true
		visited[min_village] = true, count++;
		temp = min_village;
		if (min_village == end)return;
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);

	memset(way, -1, sizeof(way));
	memset(result, 0, sizeof(result));

	cin >> village >> road >> destination;

	for (int i = 0; i < road; i++) {
		int v1, v2, w;
		cin >> v1 >> v2 >> w;
		way[v1][v2] = w;
	}

	for (int i = 1; i <= village; i++) {

		memset(weight, -1, sizeof(weight));
		memset(visited, 0, sizeof(visited));


		dijkstra(i, destination);

		if (i == destination)
			for (int j = 1; j <= village; j++) {
				result[j] += weight[j];
			}
		else {
			result[i] += weight[destination];
		}

	}

	int longest = 0;
	for (int i = 1; i <= village; i++)
		longest = (longest < result[i]) ? result[i] : longest;

	printf("%d", longest);

	return 0;
}