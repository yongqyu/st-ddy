#include<iostream>
#include<stdlib.h>
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;

int frog(int* S, int stone, int k) {
	int count=0, position = 0, position_i=0;

	while ( S[position_i+1] <= position+k ) {
		if (position+k >= S[stone]) return count+1;

		int i;
		for (i = position_i+1; i <= stone; i++) {
			if (S[i] > position + k) break;
		}

		count++;
		position_i = i-1;
		position = S[i-1];
	}

	return -1;
}

int main(int argc, char** argv) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int TC;
	int test_case;

	scanf("%d", &TC);	// cin 사용 가능
	for (test_case = 1; test_case <= TC; test_case++) {
		
		int stone;
		scanf("%d", &stone);
		int *S = new int[stone+1];

		for (int i = 1; i <= stone; i++)
			scanf("%d", &S[i]);

		int k;
		scanf("%d", &k);

		int result = frog(S, stone, k);

		printf("Case #%d\n", test_case);
		printf("%d\n", result);
	}

	return 0;	// 정상종료 시 반드시 0을 리턴해야 합니다.
}