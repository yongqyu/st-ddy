#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//���� ���� ������ sorting �� ���� ������ ���ذ��鼭 cnt++�ϰ� �񱳴�� �ٲ��ֱ�
int main() {
	int T, N;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> N;
		vector<pair<int, int>> docu(N);
		int i, cnt = 1;

		for (i = 0; i < N; i++)	cin >> docu[i].first >> docu[i].second;
		sort(docu.begin(), docu.end());

		int compare = docu.begin()->second;
		for (i = 1; i < N; i++)
			if (compare > docu[i].second) {
				cnt++;
				compare = docu[i].second;
			}

		cout << cnt << endl;
	}
	return 0;
}