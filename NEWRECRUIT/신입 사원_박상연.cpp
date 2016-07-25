#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
	int T, N;
	int first, second;
	vector< pair<int, int> > score;

	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &N);
		score.clear();

		for (int i = 0; i < N; i++){
			scanf("%d %d", &first, &second);
			score.push_back(pair<int, int>(first, second));
		}

		sort(score.begin(), score.end());

		int min = score.at(0).second;
		int count = 1;
		for (int i = 1; i < N; i++){
			if (score.at(i).second < min){
				min = score.at(i).second;
				count++;
			}
		}
		cout << count << endl;
	}
}