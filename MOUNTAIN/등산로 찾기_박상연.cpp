#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>

using namespace std;

int Mount[101][101];
int Weight[101][101];
int N;
pair<int, int> top;

int dir_row[4] = { -1, 0, 1, 0 };
int dir_col[4] = { 0, 1, 0, -1 };

typedef struct{
	int weight;
	pair<int, int> pos;
}upMount;

bool operator<(upMount A, upMount B)
{
	return A.weight < B.weight;
}

bool operator>(upMount A, upMount B)
{
	return A.weight > B.weight;
}

void dijkstra(){
	upMount temp_upMount;
	priority_queue<upMount, vector<upMount>, greater<upMount> > Q;

	temp_upMount.weight = 0;
	temp_upMount.pos = top;
	Weight[top.first][top.second] = 0;
	Q.push(temp_upMount);

	while (!Q.empty()){
		temp_upMount = Q.top();
		Q.pop();

		for (int i = 0; i < 4; i++){
			int next_row = temp_upMount.pos.first + dir_row[i];
			int next_col = temp_upMount.pos.second + dir_col[i];

			if (next_row > N || next_row <1 || next_col > N || next_col < 1){
				continue;
			}
			
			int add_weight = Mount[next_row][next_col] - Mount[temp_upMount.pos.first][temp_upMount.pos.second];
			if (add_weight < 0)
				add_weight = add_weight*add_weight;

			if (Weight[next_row][next_col] > temp_upMount.weight+ add_weight)
			{
				Weight[next_row][next_col] = temp_upMount.weight + add_weight;
				upMount T;
				T.weight = Weight[next_row][next_col];
				T.pos.first = next_row;
				T.pos.second = next_col;
				Q.push(T);
			}
		}
	}
}

int get_min_val(){
	int min_val = 99999999;
	for (int i = 1; i <= N; i++){
		int index_row[4] = { i, 1, i, N };
		int index_col[4] = { 1, i, N, i };
		for (int j = 0; j < 4; j++){
			if (min_val > Weight[index_row[j]][index_col[j]] + Mount[index_row[j]][index_col[j]] * Mount[index_row[j]][index_col[j]])
				min_val = Weight[index_row[j]][index_col[j]] + Mount[index_row[j]][index_col[j]] * Mount[index_row[j]][index_col[j]];
		}

	}
	return min_val;
}

int main(){
	scanf("%d", &N);
	scanf("%d %d", &top.first, &top.second);

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			scanf("%d", &Mount[i][j]);
			Weight[i][j] = 999999999;
		}
	}

	dijkstra();
	cout << get_min_val() << endl;
}