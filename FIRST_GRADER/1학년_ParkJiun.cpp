#include<iostream>
#include<vector>
using namespace std;
typedef unsigned long long ull;
ull DP[101][21];
int num[101];
int N;

ull solve(int cur, int sum){
	if (sum < 0 || sum > 20) return 0;
	if (cur == N) {
		if (sum == num[cur]) return 1;
		else return 0;
	}

	ull& ret = DP[cur][sum];
	if (ret) return ret;

	ret += solve(cur + 1, sum + num[cur]);
	ret += solve(cur + 1, sum - num[cur]);
	return ret;
}

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; ++i) scanf("%d", &num[i]);
	printf("%llu\n", solve(2, num[1]));
}