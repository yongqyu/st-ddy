#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector<int> path;
queue<int> possible_node;
char input[1001][31];
int foot_print[1001];
int N, K, start_node, end_node;

inline int compare_bit(int index1, int index2){
	int different = 0;
	for (int i = 0; i < K; i++)
		if (input[index1][i] != input[index2][i])
			different++;
	return different;
}

void search_path(){
	int parent_node, cur_node;
	possible_node.push(start_node);
	foot_print[start_node] = -1;

	while (!possible_node.empty()){
		parent_node = possible_node.front();
		possible_node.pop();

		for (int i = 1; i <= N; i++){
			if (foot_print[i]==0 && compare_bit(parent_node, i) == 1){
				foot_print[i] = parent_node;
				if (i == end_node)
				{
					while (!possible_node.empty())
						possible_node.pop();
					break;
				}
				possible_node.push(i);
			}
		}
	}
}

int main(){
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++)
		scanf("%s", input[i]);
	scanf("%d %d", &start_node, &end_node);
	search_path();

	vector<int> output_path;

	int temp = end_node;
	output_path.push_back(end_node);
	do{
		temp = foot_print[temp];
		if (temp == 0)
			break;
		output_path.push_back(temp);
	} while (temp != start_node);

	if (output_path.size() == 1)
		cout << -1 << endl;
	else{
		for (int i = output_path.size() - 1; i >= 0; i--){
			cout << output_path[i];
			if (i != 0)
				cout << " ";
			else
				cout << endl;
		}
	}

}