#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(void)
{
	int T, N;
	int input;
	int * temp_M;
	int * temp_E;
	pair<int, int> apair;
	vector<pair<int,int>> list;
	unsigned int sum;
	int criteria;
	int delay_criteria;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++)
	{
		scanf("%d", &N);
		
		temp_M = (int *)malloc(sizeof(int)*N);
		temp_E = (int *)malloc(sizeof(int)*N);
		list.clear();

		for (int lunchbox = 0; lunchbox < N; lunchbox++){
			if (lunchbox != N - 1)
				scanf("%d ", &input);
			else
				scanf("%d", &input);
			temp_M[lunchbox] = input;
		}
		for (int lunchbox = 0; lunchbox < N; lunchbox++){
			if (lunchbox != N - 1)
				scanf("%d ", &input);
			else
				scanf("%d", &input);
			temp_E[lunchbox] = input;
		}
		
		for (int lunchbox = 0; lunchbox < N; lunchbox++){
			apair.first = temp_E[lunchbox];
			apair.second = temp_M[lunchbox];
			list.push_back(apair);
		}

		sort(list.begin(), list.end(), greater<pair<int,int>>());

		sum = 0;

		for (int lunchbox = 0; lunchbox < N; lunchbox++)
			sum += list.at(lunchbox).second;
		
		criteria = list.at(N - 1).first;
		delay_criteria = 0;

		for (int i = N - 2; i >= 0; i--){
			delay_criteria += list.at(i + 1).second;
			if (list.at(i).first - delay_criteria > criteria)
				criteria = list.at(i).first - delay_criteria;
		}

		printf("%d\n", sum + criteria);

		free(temp_E);
		free(temp_M);
		//결과 출력
	}
}