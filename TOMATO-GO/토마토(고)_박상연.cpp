#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int tomato[1000][1000];
int tomato_count;
queue< pair<int, int> > next_ripe;
int M, N;

void make_ready(int X, int Y){
	int directionX[4] = { 0, 1, 0, -1 };
	int directionY[4] = { -1, 0, 1, 0 };

	for (int k = 0; k < 4; k++){
		int nextX = directionX[k] + X;
		int nextY = directionY[k] + Y;
		if (nextX >= 0 && nextX < N && nextY >=0 && nextY < M)
		{
			if (tomato[nextY][nextX] == 0){
				next_ripe.push(make_pair(nextX, nextY));
				tomato[nextY][nextX] = 2;
			}
		}
	}
}

int main(){
	pair<int, int> temp;
	int directionX[4] = { 0, 1, 0, -1 };
	int directionY[4] = { -1, 0, 1, 0 };

	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			scanf("%d", &tomato[i][j]);
			if (tomato[i][j] == 0)
				tomato_count++;
		}
	}

	for (int i = 0; i < M; i++){
		for (int j = 0; j < N; j++){
			if (tomato[i][j] == 1)
				make_ready(j, i);
		}
	}

	int size;
	int day=0;
	while ((size = next_ripe.size())){
		day++;
		for (int i = 0; i < size; i++){
			temp = next_ripe.front();
			next_ripe.pop();

			tomato_count--;
			tomato[temp.second][temp.first] = 1;
			make_ready(temp.first, temp.second);
		}
	}
	if (tomato_count != 0)
		cout << -1 << endl;
	else
		cout << day << endl;
	
}