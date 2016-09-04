#include <iostream>
#include <cstdio>

using namespace std;

int sushi_price[20];
int sushi_preference[20];
int DP[10000001];
int DP_limit;
int C, N, M;

int search_best_choice(int remain_money){
	int max_preference;
	for (int i = 1; i <= remain_money; i++){
		max_preference = 0;
		for (int j = 0; j < N; j++){
			if (i >= sushi_price[j] && DP[i - sushi_price[j]] + sushi_preference[j] > max_preference)
				max_preference = DP[i - sushi_price[j]] + sushi_preference[j];
		}
		DP[i] = max_preference;
	}

	return DP[remain_money];
}

int main(){
	scanf("%d", &C);
	for (int i = 0; i < C; i++){
		scanf("%d %d", &N, &M);

		for (int j = 0; j < N; j++){
			scanf("%d %d", &sushi_price[j], &sushi_preference[j]);
			sushi_price[j] /= 100;
		}
		DP_limit = M / 100;
		for (int j = 1; j <= DP_limit; j++)
			DP[j] = -1;
		
		cout << search_best_choice(DP_limit) << endl;
	}
}