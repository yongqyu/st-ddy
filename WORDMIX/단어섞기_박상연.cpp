#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int DP[202][202];

char word1[201];
char word2[201];
char word3[401];

int main()
{
	int N;
	int len1, len2, len3;
	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		scanf("%s %s %s", word1, word2, word3);
		len1 = strlen(word1);
		len2 = strlen(word2);
		len3 = strlen(word3);

		for (int o = 0; o <= len1; o++)
			for (int p = 0; p <= len2; p++)
				DP[o][p] = 0;
		DP[0][0] = 1;

		for (int j = 0; j <= len1; j++){
			for (int k = 0; k <= len2; k++){
				if (!DP[j][k])
					continue;
				if (word2[k] == word3[j + k])
					DP[j][k + 1] = 1;
				if (word1[j] == word3[j + k])
					DP[j+1][k] = 1;
			}
		}

		cout << "Data set " << i << ": ";
		if (DP[len1][len2])
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}