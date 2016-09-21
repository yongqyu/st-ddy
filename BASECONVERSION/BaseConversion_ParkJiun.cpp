#include<iostream>
#include<math.h>
using namespace std;

int main() {
	int A, B, m, flag;
	unsigned int Am[25], sum = 0;
	unsigned int result[100];

	cin >> A >> B >> m;
	for (int i = 0; i < m; i++) cin >> Am[i];
	int j = 0;
	for (int i = m - 1; i >= 0; i--) {
		sum += Am[i] * pow(A, j); j++;
	}
	int index, i = 0;
	for (; ; i++) {
		int mok = sum / B;
		result[i] = sum%B;

		if (mok >= B) sum = mok;
		else {
			result[i + 1] = mok;
			index = i + 1;
			break;
		}
	}
	for (i = index; i >= 0; i--)	cout << result[i] << " ";
	cout << endl;
}