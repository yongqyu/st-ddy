#include <iostream>
#include <cstdio>

using namespace std;

int map[12][12];
int N;
int max_count;

void Go(int X, int Y, int cur_count){
	int next_init_X = (X+Y > N ? X+1 : 1);
	int next_init_Y = (X+Y > N ? N : Y+1);

	if (X == N+1)
	{
		max_count = max_count < cur_count ? cur_count : max_count;
		return;
	}

	int remain;
	if (next_init_X == 1)
		remain = (N-1) + (N - next_init_Y) +2;
	else
		remain = N - X + 2;

	if (cur_count + remain <= max_count)
		return;

	int call_count = 0;
	int curX = X;
	int curY = Y;
	while (curX <= N && curY > 0){
		if (map[curY][curX])
		{
			int i = 1;
			while (curX - i > 0 && curY - i > 0){
				if (map[curY - i][curX - i] == 2)
				{
					i = 0;
					break;
				}
				i++;
			}

			map[curY][curX] = 2;
			if (i != 0){
				Go(next_init_X, next_init_Y, cur_count + 1);
				call_count++;
			}
			map[curY][curX] = 1;
		}
		curX++;
		curY--;
	}
	if (call_count == 0)
		Go(next_init_X, next_init_Y, cur_count);
}

int main(){
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			scanf("%d", &map[i][j]);
	Go(1, 1, 0);
	cout << max_count << endl;
}