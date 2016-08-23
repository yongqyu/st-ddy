/**************************************************************
	Problem: 1440
	Author: ParkJiun
	Language: C++
	Result: Success
	Time:33 ms
	Memory:1896 kb
****************************************************************/
#include<iostream>
#include<map>
#include<vector>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int nofNode, node1, node2;
	cin >> nofNode;
	vector<int > node(nofNode+1, -1);

	for (int i = 0; i < nofNode-1; i++) {
		int temp1, temp2;
		cin >> temp1 >> temp2;
		node[temp2] = temp1;
	}
	cin >> node1 >> node2;

	vector<int> path1(1), path2(1);
	path1[0] = node1; path2[0] = node2;

	for (int i = 1; node[path1[i - 1]] != -1; i++) path1.push_back(node[path1[i - 1]]);

	for (int i = 1; node[path2[i - 1]] != -1; i++) path2.push_back(node[path2[i - 1]]);
	
	int result, flag = 1;

	for (int i = 0; i < path1.size() && flag; i++)
		for (int j = 0; j < path2.size() && flag; j++)
			if (path1[i] == path2[j]) {
				result = path1[i];
				flag = 0;
				break;
			}
		
	printf("%d\n", result);
	return 0;
}