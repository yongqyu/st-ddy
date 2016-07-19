#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

char cards[1000];
char connect[501][501];
int score_DP[1000][501];
int main(void)
{
	/*
	N - 카드 갯수
	M - 마을 수
	K - 길의 수
	*/
	int N, M, K;

	scanf("%d\n", &N);
	for (int i = 0; i < N; i++){
		scanf("%c", &cards[i]);
		if (i < N-1)
			scanf(" ");
	}
	
	scanf("%d %d", &M, &K);
	for (int i = 0; i < K; i++)
	{
		int start, end;
		char color;
		scanf("%d %d %c", &start, &end, &color);
		connect[start][end] = color;
		connect[end][start] = color;
	}

	for (int i = 0; i < 1000; i++)
		for (int j = 0; j < 501; j++)
			score_DP[i][j] = -1;

	for (int i = 1; i <= M; i++)		// 출발점에서 첫번째 카드를 내려 놓을때 DP[0]값 입력
	{
		if (!connect[1][i])
			continue;
		if (cards[0] == connect[1][i]){
			score_DP[0][i] = 10;
		}
		else
			score_DP[0][i] = 0;
	}
	
	for (int i = 1; i < N; i++){		// 2번째 카드부터 DP 시작
		for (int town = 1; town <= M; town ++){
			int cur_score;
			int max_score=-1;
			for (int j = 1; j <= M; j++){
				if (score_DP[i-1][j] < 0 || connect[j][town]==0)
					continue;
				else{
					cur_score = score_DP[i - 1][j] + (connect[j][town] == cards[i] ? 10 : 0);
					max_score = (max_score >= cur_score ? max_score : cur_score);
				}
			}
			score_DP[i][town] = max_score;
		}
	}

	int max = 0;
	for (int i = 1; i <= M; i++)
		max = (max >= score_DP[N-1][i] ? max : score_DP[N - 1][i]);
	cout << max << endl;
}