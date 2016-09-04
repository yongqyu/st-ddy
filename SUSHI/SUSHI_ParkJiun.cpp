#include<iostream>
using namespace std;

int DP_prefer[21474836];
int minPrice = 1000000;
int price[20], prefer[20];
int nofsushi, budget;
int result;

int main() {
	std::ios::sync_with_stdio(false);
	int test;
	cin >> test;

	while (test--) {
		result = 0;
		cin >> nofsushi >> budget;
		budget /= 100;
		
		for (int i = 0; i < nofsushi; i++) {
			cin >> price[i] >> prefer[i];
			price[i] /= 100;
			if (minPrice > price[i]) {
				minPrice = price[i];
			}
		}
		
		for (int bud = minPrice; bud <= budget; bud++) {
			for (int i = 0; i <nofsushi; i++) {
				int cur_prefer = 0;
				if (bud >= price[i] && prefer[i] + DP_prefer[bud - price[i]] > DP_prefer[bud]) {
					DP_prefer[bud] = prefer[i] + DP_prefer[bud - price[i]];
				}
			}
		}

		cout << DP_prefer[budget] << endl;
	}
}