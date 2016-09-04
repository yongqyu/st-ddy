#include <iostream>

using namespace std;

int c, n, m;
int price[20];
int pref[20];
int arr[10000000] = { 0, };

int main() {
	cin >> c;

	for (int count = 0; count < c; count++) {
		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			cin >> price[i] >> pref[i];
			arr[price[i] / 100] = pref[i];
		}

		for (int i = 1; i <= m/100; i++) {
			for (int j = 0; j < n; j++) {
				if (i - (price[j] / 100) > 0) {
					if (arr[i] < arr[i - (price[j] / 100)] + pref[j])
						arr[i] = arr[i - (price[j] / 100)] + pref[j];
				}
			}
		}

		cout << arr[m/100] << endl;
	}

	return 0;
}