#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int N, M, C;
int weight[13];
char dp[10][1 << 13];

int main(){
	int input;

	scanf("%d %d %d", &N, &M, &C);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &input);
		weight[i] = input;
	}

	for (int i = 0; i < (1 << N); i++){
		int sum = 0;
		for (int j = 0; j < N; j++){
			if ((i&(1 << j))){
				sum += weight[j];
				if (sum > C)
					break;
			}
		}
		if (sum > C)
			continue;
		dp[0][i] = 1;
	}

	for (int x = 0; x < M-1; x++){
		for (int i = 0; i < (1 << N); i++)
		{
			for (int j = 0; j < (1 << N); j++)
			{
				if (dp[x][i] == 1 && dp[0][j] == 1)
					dp[x + 1][i | j] = 1;
			}
		}
	}

	int count, max_count;
	max_count = 0;
	for (int i = (1<<N) -1; i >= 0; i--){
		if (dp[M - 1][i]){
			count = 0;
			for (int j = 0; j < N; j++){
				if (i & (1 << j))
					count++;
			}

			if (count > max_count)
				max_count = count;
		}
	}

	cout << max_count << endl;
}