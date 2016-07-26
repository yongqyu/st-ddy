#include<iostream>
#include<string.h>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n, k;
	cin >> n >> k;
	char num[500000];
	cin >> num;

	int length = strlen(num);
	vector<char> BIG;
	BIG.push_back(num[0]);

	for (int i = 1; i < length; i++) {
		while ( k && !BIG.empty() && BIG.back() < num[i] ) {
			k--;
			BIG.pop_back();
		}
		BIG.push_back(num[i]);
	}

	while (k) {
		k--;
		BIG.pop_back();
	}

	for (int i = 0; i < n-k-1; i++)
		cout << BIG[i];
	cout << endl;


	return 0;
}