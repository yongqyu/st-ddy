#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int input[500];
int DP[500];

int main(){
	int T, N;
	scanf("%d", &T);
	int max_len;
	for (int test_case = 0; test_case < T; test_case++){
		scanf("%d", &N);
		for (int i = 0; i < N; i++){
			scanf("%d", &input[i]);
			DP[i] = 0;
		}

		for (int i = N - 1; i >= 0; i--){
			int count=0;
			for (int j = i+1; j < N; j++){
				if (input[j] > input[i] && DP[j] > count){
					count = DP[j];
				}
			}
			DP[i] = count + 1;
		}
		int max = 0;
		for (int i = 0; i < N; i++)
		{
			if (DP[i] > max)
				max = DP[i];
		}
		cout << max << endl;
	}
}