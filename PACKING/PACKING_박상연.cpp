#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define GET_MAX(X,Y) (X>Y ? X : Y)

int DP[1001][100];
int need[100];
int volume[100];
char name[100][21];
vector<int> output_vector;

int T,N, bag_size;

int search_max_need(int remain_vol, int item){
	if (item == N)
		return 0;
	int & ret_val = DP[remain_vol][item];
	if (ret_val != -1)
		return ret_val;

	ret_val = search_max_need(remain_vol, item + 1);
	if (remain_vol >= volume[item]){
		ret_val = GET_MAX(ret_val, search_max_need(remain_vol - volume[item], item + 1) + need[item]);
	}
	return ret_val;
}

void get_carry_item_list(){
	int vol = bag_size;

	for (int index = 0; index < N - 1; index++){
		if (DP[vol][index] == DP[vol][index + 1])
			continue;
		output_vector.push_back(index);
		vol -= volume[index];
	}
	if (vol >= volume[N - 1])
		output_vector.push_back(N - 1);
}


int main(){
	scanf("%d", &T);
	for (int test_case = 0; test_case < T; test_case++){
		scanf("%d %d", &N, &bag_size);

		for (int i = 0; i <= bag_size; i++){
			for (int j = 0; j < N; j++)
				DP[i][j] = -1;
		}

		for (int i = 0; i < N; i++){
			scanf("%s %d %d", name[i], &volume[i], &need[i]);
		}
		search_max_need(bag_size, 0);
		output_vector.clear();
		get_carry_item_list();

		int vec_size = output_vector.size();
		cout << DP[bag_size][0] << " " << vec_size << endl;
		for (int i = 0; i < vec_size; i++)
			cout << name[output_vector[i]] << endl;
	}
}