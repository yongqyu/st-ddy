#include<iostream>
using namespace std;

int original[1001];
int change[1001];

int main() {
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> original[i];
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp;
		change[i] = temp - original[i];
	}
	
	int nofchange = 0;
	
	for (int i = 0; i < N; ) {
		if (change[i] == 0) i++;
		if (change[i] < 0) {
			for (int j = i; j < N && change[j] < 0; j++)
				change[j]++;

			nofchange++;
		}
		else if (change[i] > 0) {
			for (int j = i; j < N && change[j] > 0; j++)
				change[j]--;

			nofchange++;
		}
	}
	cout << nofchange << "\n";
}