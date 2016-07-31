//2016.07.31 12:00
//Park Jiun
//Baekjoon 1238 파티
#include<iostream>
#include<string.h>
#include<vector>
#define MIN(a,b) ((a)<(b))?(a):(b)
#define MAX(a,b) ((a)>(b))?(a):(b)
using namespace std;

int Edge1[1001][1001];
int Edge2[1001][1001];
int A[1001], B[1001];

int main() {
	int n, m, x;
	cin >> n >> m >> x;

	int s, d, t;
	for (int i = 0; i < m; i++) {
		cin >> s >> d >> t;
		Edge1[s][d] = t; Edge2[d][s] = t;
	}

	int *S = new int[n+1];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!Edge1[i][j]) Edge1[i][j] = 999999;
			if (!Edge2[i][j]) Edge2[i][j] = 999999;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		if (Edge1[x][i]) A[i] = Edge1[x][i];
		if (Edge2[x][i]) B[i] = Edge2[x][i];
		S[i] = 0;
	}

	A[x] = B[x] = 0;
	S[x] = 1;

	int cnt = n - 1;
	while (cnt) {
		int min = 999999, min_i;
		for (int i = 1; i <= n; i++) {
			if (S[i] == 0 && min > A[i]) {
				min = A[i];
				min_i = i;
			}
		}
		S[min_i] = 1; cnt--;
		for (int i = 1; i <= n; i++)
			if (S[i] == 0) 
				A[i] = MIN(A[i], (min + Edge1[min_i][i]));
	}

	memset(S, 0, 4 * (n + 1));
	S[x] = 1;
	
	cnt = n - 1;
	while (cnt) {
		int min = 999999, min_i;
		for (int i = 1; i <= n; i++) {
			if (S[i] == 0 && min > B[i]) {
				min = B[i];
				min_i = i;
			}
		}
		S[min_i] = 1; cnt--;
		for (int i = 1; i <= n; i++)
			if (S[i] == 0) 
				B[i] = MIN(B[i], (min + Edge2[min_i][i]));
	}

	int max = A[1] + B[1];
	for (int i = 2; i <= n; i++) {
		max = MAX(max, A[i] + B[i]);
	}
	cout << max << endl;
}