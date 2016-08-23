#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 999

int connection[101][101];
int group[101];
int max_connection[101];

int main(){
	int N, M;
	int man1, man2;

	scanf("%d %d", &N, &M);

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (i != j)
				connection[i][j] = INF;
			else
				connection[i][j] = 0;
		}
	}

	for (int i = 0; i < M; i++){
		scanf("%d %d", &man1, &man2);
		connection[man1][man2] = connection[man2][man1] = 1;
	}


	////////////////////sum connection//////////////////
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++){
			if (i == j || connection[i][j]==INF)
				continue;

			int weight = connection[i][j];

			for (int k = 1; k <= N; k++){
				if (connection[i][k] + weight < connection[j][k])
					connection[j][k] = connection[k][j] = connection[i][k] + weight;
			}
		}
	}
	////////////////////sum connection end//////////////////

	//////////////////give people group number/////////////
	int group_num = 1;
	for (int i = 1; i <= N; i++)
	{
		if (group[i] == 0){
			for (int j = 1; j <= N; j++)
			{
				if (connection[i][j] != INF)
					group[j] = group_num;
			}
			group_num++;
		}

		int max = 0;
		for (int j = 1; j <= N; j++){
			if (connection[i][j]>max && connection[i][j]!=INF)
				max = connection[i][j];
		}
		max_connection[i] = max;
	}
	group_num--;
	//////////////////give people group number end/////////////

	//////////////////select representative in group//////////////
	vector<int> representative_list;
	for (int i = 1; i <= group_num; i++){
		int min = INF;
		int representative_num;

		for (int j = 1; j <= N; j++)
		{
			if (group[j] != i)
				continue;

			if (max_connection[j] < min){
				min = max_connection[j];
				representative_num = j;
			}
		}
		representative_list.push_back(representative_num);
	}
	sort(representative_list.begin(), representative_list.end());
	//////////////////select representative in group end//////////////

	cout << group_num << endl;
	for (int i = 0; i < representative_list.size(); i++)
		cout << representative_list[i] << endl;
}