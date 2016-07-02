#pragma warning(disable:4996)

#include <iostream>

using namespace std;

int main() {
	int T, result = 0, remain;

	scanf("%d", &T);
	
	unsigned long long* cows = new unsigned long long[T];

	for (int i = 0; i < T; i++) {
		cin >> cows[i];

		for (int j = 0; j < remain; j++) {
			if (cows[j] == 0) continue;

			if (cows[j] > cows[i]) result++;
			else cows[j] = 0;
		}
	}
	
	cout << result;

	delete cows;

	return 0;
}