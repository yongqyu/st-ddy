#include<iostream>
#include<stdlib.h>
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;


int main(int argc, char** argv) {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int TC;
	int test_case;

	scanf("%d", &TC);	// cin ��� ����
	for (test_case = 1; test_case <= TC; test_case++) {
		int n;
		scanf("%d", &n);

		int min = 99999;
		int *NUM = new int[n];
		int *DIFF = new int[n-1];
		int ZERO = 1, once=0;
		for (int i = 0; i < n; i++) {
			cin >> NUM[i];
			if (i != 0) {
				DIFF[i - 1] = NUM[i] - NUM[i - 1];
				min = (min <= DIFF[i-1]) ? min : DIFF[i-1];
				if (DIFF[i - 1] == 0) once = 1;
				else ZERO = 0;
			}
		}

		int count = 0;
		if (once == 1) { // 0 �ѹ��̶� ��������
			if (ZERO == 0) // �ѹ��̶� 0 �ƴѰ� ��������
				count = 0;
			else count = 1; // ��� 0�϶�
		}
		else {
			count = 1;
			for (int i = 2; i <= min; i++) {
				int success = 1;

				if (min % i != 0) continue;
				for (int j = 0; j < n - 1; j++) {
					// 0���� �ٿ�
					if (DIFF[j] % i != 0) success = 0;
				}
				if (success == 1) count++;
			}
		}

		printf("Case #%d\n", test_case);
		printf("%d\n", count);

		delete NUM;
		delete DIFF;
	}

	return 0;	// �������� �� �ݵ�� 0�� �����ؾ� �մϴ�.
}