#include<iostream>
#include<string.h>
using namespace std;

char word[50][51];
char result[51];

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%s", word[i]);
	
	int len = strlen(word[0]);

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < N; j++) {
			if (j == N - 1) {
				result[i] = word[j][i];
				break;
			}
			if (word[j][i] != word[j + 1][i]) {
				result[i] = '?';
				break;
			}
		}
	}
	result[len] = '\0';
	printf("%s\n", result);

}