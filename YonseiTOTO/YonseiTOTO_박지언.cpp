#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int nofclass, m;
	cin >> nofclass >> m;
	int mileage[101][101];
	int value[101];

	int a, b;
	for (int i = 0; i < nofclass; i++) {
		cin >> a >> b;
		if (a >= b) {
			for (int j = 1; j <= a; j++)
				cin >> mileage[i][j];
			sort(mileage[i] + 1, mileage[i] + a + 1, [](auto &a, auto &b) {return a > b; });
			value[i] = mileage[i][b];
		}
		else {
			value[i] = 1;
			for (int j = 0; j < a; j++) cin >> mileage[i][j];
		}
	}
	sort(value, value + nofclass);

	int result = 0;
	int i = 0;
	for (; i < nofclass; i++) {
		result += value[i];
		if (result > m) break;
		else if (result == m) {
			i++;
			break;
		}
	}
	cout << i << "\n";
}