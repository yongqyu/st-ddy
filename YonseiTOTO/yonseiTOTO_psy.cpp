#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#pragma warning(disable:4996)
using namespace std;

int main(){
	std::ios::sync_with_stdio(false);	//cin속도 절약
	freopen("input.txt", "r", stdin);
	vector<int> course[100];
	int result[100];
	int count = 0;
	int index = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		int p, l;
		cin >> p >> l;
		for (int j = 0; j < p; j++){
			int temp;
			cin >> temp;
			course[i].push_back(temp);
		}
		sort(course[i].begin(), course[i].end(),greater<int>());
		course[i].push_back(l);
	}

	for (int i = 0; i < n; i++){
		int sizeofCourse = course[i].size() - 1;
		int possibleStudent = course[i][course[i].size() - 1];	//vector 마지막에 l값 저장해둠
		if (sizeofCourse < possibleStudent){
			result[index] = 1;
			index++;
		}
		else{
			result[index] = course[i][possibleStudent - 1];
			index++;
		}
	}
	
	sort(result, result + index);

	for (int i = 0; i < index; i++){
		if (m >= result[i]){
			m -= result[i];
			count++;
		}
	}
	cout << count << endl;
}