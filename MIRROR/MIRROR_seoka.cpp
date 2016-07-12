#include<iostream>
#include<stdlib.h>
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;


int main(int argc, char** argv) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int TC;
	int test_case;

	scanf("%d", &TC);	// cin 사용 가능
	for (test_case = 1; test_case <= TC; test_case++) {
		int n;
		scanf("%d", &n);

		int **mirror = new int*[n];
		int **reflex = new int*[n];
		for (int i = 0; i < n; i++) {
			mirror[i] = new int[n];
			reflex[i] = new int[n];
		}

		for (int i = 0; i < n; i++) {
			int input, remain;
			scanf("%d", &input);
			
			for (int j = n-1; j >= 0; j--) {
				remain = input % 10;
				if (remain == 1) mirror[i][j] = 1;
				else if (remain == 2) mirror[i][j] = 2;
				else mirror[i][j] = 0;
				input /= 10;
			}
		}
		
		int row = 0, col = 0, value;
		int direction = 0; // 0 가로이동 1 세로이동
		int v = 0; // 0 오른쪽 아래, 1 왼쪽 위
		while (row >= 0 && col >= 0 && row < n && col < n ) {
			value = mirror[row][col];
			if (value == 0) {
				if (direction == 0) {
					if (v == 0) col++;
					else col--;
				}
				else {
					if (v == 0) row++;
					else row--;
				}
			}
			// 1
			else {
				reflex[row][col] = 1;
				if (value == 1) {
					if (direction == 0)
						if (v == 0) {
							row--; direction = 1; v = 1;
						}
						else {
							row++; direction = 1; v = 0;
						}
					else {
						if (v == 0) {
							col--; direction = 0; v = 1;
						}
						else {
							col++; direction = 0; v = 0;
						}
					}
				}

				// 2
				else if (value == 2) {
					if (direction == 0)
						if (v == 0) {
							row++; direction = 1; v = 0;
						}
						else {
							row--; direction = 1; v = 1;
						}
					else {
						if (v == 0) {
							col++; direction = 0; v = 0;
						}
						else {
							col--; direction = 0; v = 1;
						}
					}
				}
			}
		}
		
		int count = 0;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (reflex[i][j] == 1) count++;

		printf("Case #%d\n", test_case);
		printf("%d\n", count);

		delete mirror;
		delete reflex;
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}