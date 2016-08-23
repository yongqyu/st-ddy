/**************************************************************
    Problem: 1123
    Author: ParkJiun
    Language: C++
    Result: Success
    Time:0 ms
    Memory:1732 kb
****************************************************************/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int nofdomino;
	cin >> nofdomino;
	vector<int> sum(nofdomino);

	int top, bottom;
	for (int i = 0; i < nofdomino; i++) {
		cin >> top >> bottom;
		int temp = top + bottom;
		sum[i] = temp;
	}

	sort(sum.begin(), sum.end());

	if (sum[nofdomino - 1] == 0) {
		cout << "0";
		return 0;
	}

	for (int i = nofdomino - 1; i >= 0; i--) {
		if (i == 0) {
			cout << sum[0];
			break;
		}
		if (sum[i - 1] >= 10) {
			cout << sum[i] + 1;
			sum[i - 1] -= 10;
		}
		else
			cout << sum[i];
	}

	return 0;
}