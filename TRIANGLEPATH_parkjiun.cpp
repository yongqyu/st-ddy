#include<iostream>
using namespace std;

int main() {
	int T, triSize;
	int test_case;


	scanf("%d", &T);
	for (test_case = 1; test_case <= T; ++test_case) {
		scanf("%d", &triSize);

		int **A = new int*[triSize];
		int **B = new int*[triSize];

		for (int i = 0; i < triSize; i++) {
			A[i] = new int[triSize];
			B[i] = new int[triSize];
		}

		for (int i = 0; i < triSize; i++) {
			for (int j = 0; j < i + 1; j++)
				scanf("%d", &A[i][j]);
		}

		B[0][0] = A[0][0];


		for (int i = 1; i < triSize; i++) {
			for (int j = 0; j < i + 1; j++) {
				if (i == j) B[i][j] = B[i - 1][j - 1] + A[i][j];
				else if (i > j && j == 0) B[i][0] = B[i - 1][0] + A[i][0];
				else if (i > j && j != 0)
					B[i][j] = (B[i - 1][j - 1] >= B[i - 1][j]) ? B[i - 1][j - 1] + A[i][j] : B[i - 1][j] + A[i][j];
			}
		}

		int maxsum = B[0][0];

		for (int i = 0; i < triSize; i++)
			if (maxsum < B[triSize - 1][i]) maxsum = B[triSize - 1][i];

		cout << maxsum << endl;

		for (int i = 0; i < triSize; i++) delete[] B[i];
		delete[] B;

		for (int i = 0; i < triSize; i++) delete[] A[i];
		delete[] A;

	}
}