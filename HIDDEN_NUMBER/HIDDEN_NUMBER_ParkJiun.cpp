#include<iostream>
using namespace std;

int N; char str[5000001];

int main() {
	scanf("%d %s", &N, str);
	unsigned long long result = 0;
	int power = 1;
	int val = 0;

	for (int i = N - 1; i >= 0; i--) {
		if ('0' <= str[i] && str[i] <= '9') {
			val += power * (str[i] - '0');
			power *= 10;
		}
		if (i == 0 || str[i] < '0' || '9' < str[i]) { //¹®ÀÚ
			if (val <= 999999) {
				result += val;
			}
			val = 0;
			power = 1;
		}
	}
	printf("%llu\n", result);
	return 0;
}