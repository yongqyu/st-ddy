#include <iostream>

using namespace std;

int main() {
	int n, k, count = 0;
	cin >> n >> k;

	int* bulb = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> bulb[i];
	}

	for (int i = 0; i < n; i++) {
		if (bulb[i] == 1) {
			if (i> n - k) {
				cout << "Insomnia";
				return 0;
			}
			else {
				count++;
				for (int j = 0; j < k; j++) {
					bulb[i + j] = !bulb[i + j];
				}
			}
		}
	}

	cout << count;

	return 0;
}
