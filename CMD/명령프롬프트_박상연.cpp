#include<iostream>
#include <cstdio>
#include <cstring>
char input[50][51];

using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	char standard_char;

	for (int i = 0; i < N; i++)
		scanf("%s", input[i]);
	int string_len = strlen(input[0]);

	for (int i = 0; i < string_len; i++){
		int j;
		standard_char = input[0][i];

		for (j = 1; j < N; j++){
			if (input[j][i] != standard_char){
				cout << "?";
				break;
			}
		}
		if (j == N)
			cout << standard_char;
	}
	cout << endl;
}