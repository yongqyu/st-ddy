// Created: 2016/7/26 5:00 pm
// Author: Park Jiun
// Baekjoon 2812 크게 만들기
#include<iostream>
#include<vector>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	char num[500000];
	cin >> num;
	vector<char> number(1);

	number[0] = num[0];
	int K = k;

	for (int i = 1; i < n; i++){
		while(K && !number.empty() && number.back() < num[i]) {
			number.pop_back();
			K--;
		}
		number.push_back(num[i]);
	}

	for (int i = 0; i < n - k; i++) printf("%c", number[i]);
	printf("\n");
}