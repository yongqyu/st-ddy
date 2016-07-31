#include <iostream>
#include <cstdio>

using namespace std;

#define INF ((1<<30)-1) 
#define CANT_REACH 0
#define NOT_VISIT 1
#define VISIT 2

int N, M, X;
int match[1001][1001];
int reverse_match[1001][1001];
int shortest_weight[1001];
int reverse_shortest_weight[1001];

void dijkstra(int weight[][1001], int * shortest_path, int start){
	int footPrint[1001];
	int count = 0;

	for (int i = 1; i <= N; i++)
		footPrint[i] = CANT_REACH;

	//--------- start node initialize---------//
	footPrint[start] = VISIT;
	shortest_path[start] = 0;
	count++;
	for (int i = 1; i <= N; i++){
		if (weight[start][i] != INF){
			shortest_path[i] = weight[start][i];
			footPrint[i] = NOT_VISIT;
		}
	}
	//--------- start node initialize end---------//

	while (count < N){
		//-------search not visit  shortest path----------//
		int min = INF;
		int min_index = 0;
		for (int i = 1; i <= N; i++){
			if (footPrint[i] == NOT_VISIT){
				if (shortest_path[i] < min)
				{
					min = shortest_path[i];
					min_index = i;
				}
			}
		}
		//-------search not visit  shortest path----------//

		footPrint[min_index] = VISIT;
		count++;
		for (int i = 1; i <= N; i++)
		{
			if (footPrint[i] != VISIT && weight[min_index][i]!=INF){
				if (shortest_path[min_index] + weight[min_index][i] < shortest_path[i]){
					shortest_path[i] = shortest_path[min_index] + weight[min_index][i];
					footPrint[i] = NOT_VISIT;
				}
			}
		}
	}
}

int main(){
	int start_P, end_P, weight;
	scanf("%d %d %d", &N, &M, &X);

	for (int i = 1; i <= N; i++)
		shortest_weight[i] = reverse_shortest_weight[i] = INF;
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= N; j++)
			match[i][j] = reverse_match[i][j] = INF;

	for (int i = 0; i < M; i++){
		scanf("%d %d %d", &start_P, &end_P, &weight);
		match[start_P][end_P] = weight;
		reverse_match[end_P][start_P] = weight;
	}
	dijkstra(match, shortest_weight, X);
	dijkstra(reverse_match, reverse_shortest_weight, X);

	int max = -1;
	for (int i = 1; i <= N; i++){
		if (shortest_weight[i] + reverse_shortest_weight[i] > max)
			max = shortest_weight[i] + reverse_shortest_weight[i];
	}
	cout << max << endl;
}