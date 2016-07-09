#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {
	int a, b, m, num = 0;
	cin >> a >> b;
	cin >> m;

	int anum[25];
	for (int i = 1; i <= m; i++) {
		cin >> anum[i-1];
		num += pow(a, m - i) * anum[i - 1];
	}

	vector<int> bnum;
	while (num >= b) {
		bnum.push_back(num%b);
		num /= b;
	}
	bnum.push_back(num);

	for (int i = bnum.size()-1; i > 0; i--) {
		cout << bnum[i] << " ";
	}
	cout << bnum[0] << endl;

	return 0;
}