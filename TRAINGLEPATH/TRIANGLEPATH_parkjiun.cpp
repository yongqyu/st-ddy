//2016/06/28 박지언 삼각형 위의 최대 경로
//https://algospot.com/judge/problem/read/TRIANGLEPATH
#include<iostream>
using namespace std;

int main() {
	int T, triSize;//test number, size of triangle
	int test_case;

	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case) {
		scanf("%d", &triSize);
		
		//2d array dynamic allocation
		int **A = new int*[triSize];
		int **B = new int*[triSize];

		for (int i = 0; i < triSize; i++) {
			A[i] = new int[i+1];
			B[i] = new int[i+1];
		} //right-angled triangle

		for (int i = 0; i < triSize; i++) {
			for (int j = 0; j < i + 1; j++)	//right-angled triangle
				scanf("%d", &A[i][j]);
		}

		B[0][0] = A[0][0];
		
		//dynamic programming
		//3rd condition i > j && j != 0 : choose a large number between ↑ and ↖
		//possible directions are ↘ and ↓
		for (int i = 1; i < triSize; i++) {
			for (int j = 0; j < i + 1; j++) {
				if (i == j) B[i][j] = B[i - 1][j - 1] + A[i][j];
				else if (i > j && j == 0) B[i][0] = B[i - 1][0] + A[i][0];
				else if (i > j && j != 0)
					B[i][j] = (B[i - 1][j - 1] >= B[i - 1][j]) ? B[i - 1][j - 1] + A[i][j] : B[i - 1][j] + A[i][j];
			}
		}
		
		//find max value in array B's last row
		int maxsum = B[triSize-1][0];

		for (int i = 1; i < triSize; i++)
			if (maxsum < B[triSize - 1][i]) maxsum = B[triSize - 1][i];

		cout << maxsum << endl;
		
		//deallocation in reverse order
		for (int i = 0; i < triSize; i++) delete[] B[i];
		delete[] B;

		for (int i = 0; i < triSize; i++) delete[] A[i];
		delete[] A;
	}
}
