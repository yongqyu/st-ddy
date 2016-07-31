#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct node{
	int desti;	//도착점
	int time;	//가중치
};

//N의 최대값이 1000이므로 1001로 생성
int d[1001];	//파티 장소에서 최소거리 저장, 그 반대 저장
int visited[1001] = { 0, };	//방문안했으면 0, 방문 가능한 점인데 아직 안했으면 1, 방문했으면 2
int result[1001] = { 0, };	//d의 배열에서 2가지 경우를 더해서 저장
int N, M, X;
vector<node> Graph[1001];	//정방향 그래프
vector<node> reverseGraph[1001];	//역방향 그래프
vector<node>::iterator iter;
void dijkstra(int v, vector<node> *graph);

int main(){
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++){	//입력받기
		int start, desti, time;
		cin >> start >> desti >> time;
		node temp;
		temp.desti = desti;
		temp.time = time;
		Graph[start].push_back(temp);
		temp.desti = start;
		reverseGraph[desti].push_back(temp);
	}
	
	dijkstra(X, Graph);	//정방향
	memset(visited, 0, sizeof(int)*(N + 1));
	for (int i = 1; i <= N; i++){	
		result[i] = d[i];
	}
	dijkstra(X, reverseGraph);	//역방향
	for (int i = 1; i <= N; i++){
		result[i] += d[i];
	}
	
	int max = result[1];
	for (int i = 2; i <= N; i++){
		if (max < result[i])max = result[i];
	}
	cout << max << endl;
	
}

void dijkstra(int v,vector<node> *graph){
	int count = 1;
	for (int i = 1; i <= N; i++){
		d[i] = 10000000;//무한대표현
	}
	d[v] = 0;
	visited[v] = 2;
	int next=0;
	while (count != N){
		int min = 10000000;
		for (iter = graph[v].begin(); iter != graph[v].end(); iter++){ //시작점에서 연결된 점들
			if (visited[iter->desti] == 2)continue;
			else{
				visited[iter->desti] = 1;	
				if (d[iter->desti]>d[v] + iter->time || d[iter->desti] == 10000000) //최소값으로 바꾸기
					d[iter->desti] = d[v] + iter->time;
			}
		}
		for (int i = 1; i <= N; i++){	//visited가 1인 것들에 대해 d값이 작은거 next로 지정
			if (visited[i] == 1){
				if (min > d[i]){
					next = i;
					min = d[i];
				}
			}
		}
		visited[next] = 2;
		v = next;
		count++;
	}
}


