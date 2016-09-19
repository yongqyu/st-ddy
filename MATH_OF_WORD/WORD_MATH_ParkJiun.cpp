#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

int N;
char str[10][9];
int len[10];
int arr[92][8];
bool used[92];
vector<unsigned int> m;

int main() {
	int max_len = 0;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", str[i]);
		len[i] = strlen(str[i]);
		if (max_len < len[i]) max_len = len[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < len[i]; j++) {
			arr[str[i][j]][max_len - len[i] + j] += 1;
			used[str[i][j]] = true;
		}
	}
	for (int i = 65; i < 91; i++) {
		if (used[i] == false) continue;
		int val = 0;
		for (int j = 0; j < max_len; j++) {
			val += arr[i][j] * pow(10, max_len -1 - j);
		}
		m.push_back(val);
	}
	sort(m.begin(), m.end(), [](auto a, auto b) {return a > b; });
	
	unsigned int result = 0;
	int num = 9;
	for (int i = 0; i < m.size(); i++) {
		result += (num--)*m[i];
	}
	cout << result << endl;
}