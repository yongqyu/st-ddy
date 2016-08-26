/*
Date: 2016.08.26
Author: Park Jiun
Probloem: 2015 SCPC 1차 예선 - 방속의 거울
*/

#include<cstdio>
#include<iostream>
using namespace std;

int d[4][2] = { {1,0}, {0,1}, {-1,0},{0,-1} }; //up, right, down, left
int room[1000][1000];
bool visited[1000][1000];

int main(int argc, char** argv) {
	setbuf(stdout, NULL);
	int TC, N, i, j;
	int test_case;

	scanf("%d", &TC);
	for (test_case = 1; test_case <= TC; test_case++) {
		scanf("%d", &N);
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				scanf("%1d", &room[i][j]);
				visited[i][j] = false;
			}
		}

		int row = 0, col = 0, dir = 1;
		while (row >= 0 && row < N && col >= 0 && col < N) {
			if (room[row][col]) {
				visited[row][col] = true;
				if (room[row][col] == 1)
					dir = (dir - 3) < 0 ? -(dir - 3) : dir - 3;
				else {
					if (dir % 2 == 0) dir++;
					else dir--;
				}
			}
			row += d[dir][0];
			col += d[dir][1];
		}

		int result = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++)
				if (visited[i][j]) result++;
		}
		printf("Case #%d\n%d\n", test_case, result);
	}
	return 0;
}