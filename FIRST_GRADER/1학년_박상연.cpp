#include <iostream>
#include <cstdio>

using namespace std;

unsigned long long DP[100][21];

int main(){
	int N, input;
	scanf("%d", &N);

	scanf("%d", &input);
	DP[0][input] = 1;
	for (int i = 0; i < N-1; i++){
		scanf("%d", &input);
		for (int num = 0; num <= 20; num++){
			if (DP[i][num] == 0)
				continue;
			if (num + input <= 20)
				DP[i + 1][num + input] += DP[i][num];
			if (num - input >= 0)
				DP[i + 1][num - input] += DP[i][num];
		}
	}
	cout << DP[N - 2][input] << endl;
}