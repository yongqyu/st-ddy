/*
std::ios::sync_with_stdio(false); cin>>test; 
위 문장 두개 지우고 그냥 scanf 쓰니까 정답처리됨
*/
#include<iostream>
#include<cstring>
using namespace std;

int DP[210][210];
char first[201], second[201], third[401];

int main() {
	int test;
	scanf("%d", &test);
	for (int T = 1; T <= test; T++) {
		scanf("%s %s %s", first, second, third);
		int first_len = strlen(first);
		int second_len = strlen(second);
		int third_len = strlen(third);

		for (int i = 0; i <= first_len; i++)
			for (int j = 0; j <= second_len; j++) 
				DP[i][j] = 0;

		DP[0][0] = 1;

		for (int i = 0; i <= first_len; i++) {
			for (int j = 0; j <= second_len; j++) {
				if (!DP[i][j]) continue;
				if (second[j] == third[i + j])
					DP[i][j + 1] = 1;
				
				if (first[i] == third[i + j]) 
					DP[i + 1][j] = 1;
			}
		}

		cout << "Data set " << T;
		if (DP[first_len][second_len]) cout << ": yes\n";
		else cout << ": no\n";
	}
}