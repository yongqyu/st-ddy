#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct node{
	int desti;	//������
	int time;	//����ġ
};

//N�� �ִ밪�� 1000�̹Ƿ� 1001�� ����
int d[1001];	//��Ƽ ��ҿ��� �ּҰŸ� ����, �� �ݴ� ����
int visited[1001] = { 0, };	//�湮�������� 0, �湮 ������ ���ε� ���� �������� 1, �湮������ 2
int result[1001] = { 0, };	//d�� �迭���� 2���� ��츦 ���ؼ� ����
int N, M, X;
vector<node> Graph[1001];	//������ �׷���
vector<node> reverseGraph[1001];	//������ �׷���
vector<node>::iterator iter;
void dijkstra(int v, vector<node> *graph);

int main(){
	cin >> N >> M >> X;
	for (int i = 0; i < M; i++){	//�Է¹ޱ�
		int start, desti, time;
		cin >> start >> desti >> time;
		node temp;
		temp.desti = desti;
		temp.time = time;
		Graph[start].push_back(temp);
		temp.desti = start;
		reverseGraph[desti].push_back(temp);
	}
	
	dijkstra(X, Graph);	//������
	memset(visited, 0, sizeof(int)*(N + 1));
	for (int i = 1; i <= N; i++){	
		result[i] = d[i];
	}
	dijkstra(X, reverseGraph);	//������
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
		d[i] = 10000000;//���Ѵ�ǥ��
	}
	d[v] = 0;
	visited[v] = 2;
	int next=0;
	while (count != N){
		int min = 10000000;
		for (iter = graph[v].begin(); iter != graph[v].end(); iter++){ //���������� ����� ����
			if (visited[iter->desti] == 2)continue;
			else{
				visited[iter->desti] = 1;	
				if (d[iter->desti]>d[v] + iter->time || d[iter->desti] == 10000000) //�ּҰ����� �ٲٱ�
					d[iter->desti] = d[v] + iter->time;
			}
		}
		for (int i = 1; i <= N; i++){	//visited�� 1�� �͵鿡 ���� d���� ������ next�� ����
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


