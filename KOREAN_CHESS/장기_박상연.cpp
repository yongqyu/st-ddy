#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int map[101][101];

int main(){
	int N, M, R, C, S, K;
	queue< pair<int, int> > Q;
	pair<int, int> temp, cur_node;
	int dir_row[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	int dir_colunm[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };

	scanf("%d %d", &N, &M);
	scanf("%d %d %d %d", &R, &C, &S, &K);

	for (int i = 1; i <= N; i++)
		for (int j = 0; j <= M; j++)
			map[i][j] = -1;

	temp.first = R;
	temp.second = C;
	Q.push(temp);
	map[R][C] = 0;

	while (!Q.empty()){
		cur_node = Q.front();
		Q.pop();

		for (int i = 0; i < 8; i++){
			temp.first = cur_node.first + dir_row[i];
			temp.second = cur_node.second + dir_colunm[i];
			if (map[temp.first][temp.second]==-1 && temp.first >= 1 && temp.first <= N && temp.second >= 1 && temp.second <= M)
			{
				Q.push(temp);
				map[temp.first][temp.second] = map[cur_node.first][cur_node.second] + 1;
			}
		}
	}

	cout << map[S][K] << endl;

	
}