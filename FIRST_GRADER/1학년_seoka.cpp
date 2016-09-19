#include<iostream>
#include<memory.h>
#pragma warning(disable:4996)
using namespace std;

int n, result=0;
int num[101];
unsigned long long dp[101][21];

unsigned long long equation(int p, int value) {
	
	if (dp[p][value] != -1)
		return dp[p][value];

	
	if (p == n - 1) {
		if( value == num[n] )
			return dp[p][value]=1;
		else return dp[p][value]=0;
	}

	unsigned long long tmp=0;
	if (value + num[p + 1] <= 20) 
		tmp += equation(p + 1, value + num[p + 1]);
	

	if (value - num[p + 1] >= 0) 
		tmp += equation(p + 1, value - num[p + 1]);
	

	return dp[p][value] = tmp;	
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	memset(dp, -1, sizeof(dp));

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &num[i]);

	cout << equation(1, num[1]);
	
	return 0;
}