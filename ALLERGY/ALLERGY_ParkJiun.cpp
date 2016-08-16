/*
Author: Park Jiun
Created: 2016.08.16 PM 2:33
Problem: 알러지가 심한 친구들
*/
#include<iostream>
#include<string.h>
using namespace std;

char names[51][11];
int nofFriends, nofFoods;
int min_n;

void solve(int*, int, int, int);

int main() {
	std::ios::sync_with_stdio(false);	
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int allergy[51] = { 0, };
		cin >> nofFriends >> nofFoods;
		min_n = nofFoods;

		for (int i = 0; i < nofFriends; i++)
			cin >> names[i];

		for (int i = 0; i < nofFoods; i++) {
			int num;
			cin >> num;
			int k = 0;
			for (int j = 0; j < num; j++) {
				char temp[11];
				cin >> temp;
				for (; k < nofFriends; k++) {
					if (strcmp(temp, names[k]) != 0) {
						allergy[i]++;
						allergy[i] = allergy[i] << 1;
					}
					else {
						allergy[i] = allergy[i] << 1;
						k++;
						break;
					}
				}
			}
			if (k < nofFriends) {
				for (; k < nofFriends; k++) {
					allergy[i]++;
					allergy[i] = allergy[i] << 1;
				}
			}
		}

		for (int i = 0; i < nofFoods; i++)
			solve(allergy, allergy[i], i, 1);

		cout << min_n << "\n";
	}
}

void solve(int *allergy, int start, int start_i, int n) {
	if (n + 1 > min_n) return;
	for (int i = start_i+1; i < nofFoods; i++) {
		int num = n;
		int value = start & allergy[i];
		num++;
		if (!value)
			min_n = num < min_n ? num : min_n;
		else
			solve(allergy, value, i, num);
	}
}